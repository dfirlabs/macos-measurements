#!/bin/bash
#
# Script to export Mac codepages
# Requires MacOS and maccodepage binary

EXIT_SUCCESS=0;
EXIT_FAILURE=1;

MACCODEPAGE="./maccodepage";
EXPORT_PATH="codepages";

if ! test -x ${MACCODEPAGE};
then
	echo "Missing maccodepage binary.";

	exit ${EXIT_FAILURE};
fi

mkdir -p ${EXPORT_PATH};

set -e;

${MACCODEPAGE} 0 > ${EXPORT_PATH}/MacRoman.txt;
${MACCODEPAGE} 1 > ${EXPORT_PATH}/MacJapanese.txt;
${MACCODEPAGE} 2 > ${EXPORT_PATH}/MacChineseTrad.txt;
${MACCODEPAGE} 3 > ${EXPORT_PATH}/MacKorean.txt;
${MACCODEPAGE} 4 > ${EXPORT_PATH}/MacArabic.txt;
${MACCODEPAGE} 5 > ${EXPORT_PATH}/MacHebrew.txt;
${MACCODEPAGE} 6 > ${EXPORT_PATH}/MacGreek.txt;
${MACCODEPAGE} 7 > ${EXPORT_PATH}/MacCyrillic.txt;
${MACCODEPAGE} 8 > ${EXPORT_PATH}/MacDevanagari.txt;
${MACCODEPAGE} 9 > ${EXPORT_PATH}/MacGurmukhi.txt;
${MACCODEPAGE} 10 > ${EXPORT_PATH}/MaccGujarati.txt;
${MACCODEPAGE} 11 > ${EXPORT_PATH}/MacOriya.txt;
${MACCODEPAGE} 12 > ${EXPORT_PATH}/MacBengali.txt;
${MACCODEPAGE} 13 > ${EXPORT_PATH}/MacTamil.txt;
${MACCODEPAGE} 14 > ${EXPORT_PATH}/MacTelugu.txt;
${MACCODEPAGE} 15 > ${EXPORT_PATH}/MacKannada.txt;
${MACCODEPAGE} 16 > ${EXPORT_PATH}/MacMalayalam.txt;
${MACCODEPAGE} 17 > ${EXPORT_PATH}/MacSinhalese.txt;
${MACCODEPAGE} 18 > ${EXPORT_PATH}/MacBurmese.txt;
${MACCODEPAGE} 19 > ${EXPORT_PATH}/MacKhmer.txt;
${MACCODEPAGE} 20 > ${EXPORT_PATH}/MacThai.txt;
${MACCODEPAGE} 21 > ${EXPORT_PATH}/MacLaotian.txt;
${MACCODEPAGE} 22 > ${EXPORT_PATH}/MacGeorgian.txt;
${MACCODEPAGE} 23 > ${EXPORT_PATH}/MacArmenian.txt;
${MACCODEPAGE} 24 > ${EXPORT_PATH}/MacChineseSimp.txt;
${MACCODEPAGE} 25 > ${EXPORT_PATH}/MacTibetan.txt;
${MACCODEPAGE} 26 > ${EXPORT_PATH}/MacMongolian.txt;
${MACCODEPAGE} 27 > ${EXPORT_PATH}/MacEthiopic.txt;
${MACCODEPAGE} 28 > ${EXPORT_PATH}/MacCentralEurRoman.txt;
${MACCODEPAGE} 29 > ${EXPORT_PATH}/MacVietnamese.txt;
${MACCODEPAGE} 30 > ${EXPORT_PATH}/MacExtArabic.txt;
${MACCODEPAGE} 31 > ${EXPORT_PATH}/MacSymbol.txt;
${MACCODEPAGE} 32 > ${EXPORT_PATH}/MacDingbats.txt;
${MACCODEPAGE} 33 > ${EXPORT_PATH}/MacTurkish.txt;
${MACCODEPAGE} 34 > ${EXPORT_PATH}/MacCroatian.txt;
${MACCODEPAGE} 35 > ${EXPORT_PATH}/MacIcelandic.txt;
${MACCODEPAGE} 36 > ${EXPORT_PATH}/MacRomanian.txt;
${MACCODEPAGE} 37 > ${EXPORT_PATH}/MacCeltic.txt;
${MACCODEPAGE} 38 > ${EXPORT_PATH}/MacGaelic.txt;
${MACCODEPAGE} 39 > ${EXPORT_PATH}/MacFarsi.txt;
${MACCODEPAGE} 40 > ${EXPORT_PATH}/MacUkrianian.txt;
${MACCODEPAGE} 41 > ${EXPORT_PATH}/MacInuit.txt;
