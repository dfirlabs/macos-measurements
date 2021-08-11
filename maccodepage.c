/*
 * CLI tool to export Unicode to codepage mappings using CoreFoundation.
 *
 * Copyright (C) 2021, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include <CoreFoundation/CoreFoundation.h>
#include <CoreFoundation/CFStringEncodingExt.h>

typedef struct maccodepage_encoding maccodepage_encoding_t;

struct maccodepage_encoding
{
	CFStringEncoding codepage;

	const char *name;
};

maccodepage_encoding_t maccodepage_encodings[ 42 ] = {
	{ kCFStringEncodingMacRoman, "MacRoman" },
	{ kCFStringEncodingMacJapanese, "MacJapanese" },
	{ kCFStringEncodingMacChineseTrad, "MacChineseTrad" },
	{ kCFStringEncodingMacKorean, "MacKorean" },
	{ kCFStringEncodingMacArabic, "MacArabic" },
	{ kCFStringEncodingMacHebrew, "MacHebrew" },
	{ kCFStringEncodingMacGreek, "MacGreek" },
	{ kCFStringEncodingMacCyrillic, "MacCyrillic" },
	{ kCFStringEncodingMacDevanagari, "MacDevanagari" },
	{ kCFStringEncodingMacGurmukhi, "MacGurmukhi" },
	{ kCFStringEncodingMacGujarati, "MaccGujarati" },
	{ kCFStringEncodingMacOriya, "MacOriya" },
	{ kCFStringEncodingMacBengali, "MacBengali" },
	{ kCFStringEncodingMacTamil, "MacTamil" },
	{ kCFStringEncodingMacTelugu, "MacTelugu" },
	{ kCFStringEncodingMacKannada, "MacKannada" },
	{ kCFStringEncodingMacMalayalam, "MacMalayalam" },
	{ kCFStringEncodingMacSinhalese, "MacSinhalese" },
	{ kCFStringEncodingMacBurmese, "MacBurmese" },
	{ kCFStringEncodingMacKhmer, "MacKhmer" },
	{ kCFStringEncodingMacThai, "MacThai" },
	{ kCFStringEncodingMacLaotian, "MacLaotian" },
	{ kCFStringEncodingMacGeorgian, "MacGeorgian" },
	{ kCFStringEncodingMacArmenian, "MacArmenian" },
	{ kCFStringEncodingMacChineseSimp, "MacChineseSimp" },
	{ kCFStringEncodingMacTibetan, "MacTibetan" },
	{ kCFStringEncodingMacMongolian, "MacMongolian" },
	{ kCFStringEncodingMacEthiopic, "MacEthiopic" },
	{ kCFStringEncodingMacCentralEurRoman, "MacCentralEurRoman" },
	{ kCFStringEncodingMacVietnamese, "MacVietnamese" },
	{ kCFStringEncodingMacExtArabic, "MacExtArabic" },
	{ kCFStringEncodingMacSymbol, "MacSymbol" },
	{ kCFStringEncodingMacDingbats, "MacDingbats" },
	{ kCFStringEncodingMacTurkish, "MacTurkish" },
	{ kCFStringEncodingMacCroatian, "MacCroatian" },
	{ kCFStringEncodingMacIcelandic, "MacIcelandic" },
	{ kCFStringEncodingMacRomanian, "MacRomanian" },
	{ kCFStringEncodingMacCeltic, "MacCeltic" },
	{ kCFStringEncodingMacGaelic, "MacGaelic" },
	{ kCFStringEncodingMacFarsi, "MacFarsi" },
	{ kCFStringEncodingMacUkrainian, "MacUkrianian" },
	{ kCFStringEncodingMacInuit, "MacInuit" },
};

void cfstring_printf(
      CFStringRef format,
      ... )
{
	va_list argument_list;

	CFDataRef output_string          = NULL;
	CFStringRef formatted_string     = NULL;
	const UInt8 *output_string_data  = NULL;
	CFStringEncoding output_encoding = 0;
	CFIndex output_string_length     = 0;

	va_start(
	 argument_list,
	 format);

	formatted_string = CFStringCreateWithFormatAndArguments(
	                    NULL,
	                    NULL,
	                    format,
	                    argument_list );

	va_end(
	 argument_list);

	output_encoding = CFStringGetSystemEncoding();

	output_string = CFStringCreateExternalRepresentation(
	                 NULL,
	                 formatted_string,
	                 output_encoding,
	                 '?' );

	if( output_string != NULL )
	{
		output_string_length = CFDataGetLength(
		                        output_string );

		output_string_data = CFDataGetBytePtr(
		                      output_string );

		fprintf(
		 stdout,
		 "%.*s",
		 (int) output_string_length,
		 output_string_data );

		CFRelease(
		 output_string );
	}
	CFRelease(
         formatted_string );
}

int main(
     int argc,
     char * const argv[] )
{
	UniChar utf16_string[ 2 ]        = { 0, 0 };
	CFDataRef encoded_string         = NULL;
	CFStringRef unicode_string       = NULL;
	const UniChar *chars             = NULL;
	const UInt8 *encoded_string_data = NULL;
	maccodepage_encoding_t *encoding = NULL;
	CFIndex encoded_string_length    = 0;
	uint32_t unicode_character       = 0;
	int encoding_index               = 0;

	if( argc != 2 )
	{
		fprintf(
		 stderr,
		 "Missing encoding index.\n" );

		return( EXIT_FAILURE );
	}
	encoding_index = atoi( argv[ 1 ] );

	if( ( encoding_index < 0 )
	 || ( encoding_index >= 42 ) )
	{
		fprintf(
		 stderr,
		 "Unsupported encoding index: %d.\n",
		 encoding_index );

		return( EXIT_FAILURE );
	}
	encoding = &( maccodepage_encodings[ encoding_index ] );

	cfstring_printf(
	 CFSTR("Codepage: %s\n"),
	 encoding->name );

	for( unicode_character = 0x00000000UL;
	     unicode_character < 0x0010ffffUL;
	     unicode_character++ )
	{
		utf16_string[ 0 ] = (UniChar) unicode_character;

		unicode_string = CFStringCreateWithCharacters(
				  NULL,
				  utf16_string,
				  1 );

		if( unicode_string != NULL )
		{
			encoded_string = CFStringCreateExternalRepresentation(
					  NULL,
					  unicode_string,
					  encoding->codepage,
					  0 );

			if( encoded_string != NULL )
			{
				encoded_string_length = CFDataGetLength(
							 encoded_string );

				encoded_string_data = CFDataGetBytePtr(
						       encoded_string );

				if( encoded_string_length != 0 )
				{
					cfstring_printf(
					 CFSTR("0x%08" PRIx32 " =>"),
					 unicode_character );

					if( encoded_string_length <= 6 )
					{
						do
						{
							cfstring_printf(
							 CFSTR(" 0x%02" PRIx8 ""),
							 encoded_string_data[ --encoded_string_length ] );
						}
						while( encoded_string_length > 0 );
					}
					else if( encoded_string_length != 0 )
					{
						cfstring_printf(
						 CFSTR("0x%08" PRIx32 " <UNSUPPORTED: %d>\n"),
						 unicode_character,
						 (int) encoded_string_length );
					}
				}
				cfstring_printf(
				 CFSTR("\n") );

				CFRelease(
				 encoded_string );
			}
			CFRelease(
			 unicode_string );
		}
	}
	return( EXIT_SUCCESS );
}

