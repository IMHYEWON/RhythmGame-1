#pragma once
#include <algorithm>
#include <string>
#include <hash_map>
#include <tchar.h>

using namespace std;

struct BMSKeyData {
	double beat;
	int key;
	int value;
	int attr;

	bool operator< (const BMSKeyData &o) {
		return (this->beat) < (o.beat);
	}
};

class bmsParser {
public:
	bool ParseBMSFile(TCHAR *filename);
	bool ParseBMSData();
	bool ProcessBMSLine(TCHAR *text);
	bool ParseBMSLine(TCHAR *input, TCHAR *key, TCHAR *value);
	bool ParseBMSLine2(TCHAR *input, TCHAR *key, TCHAR *value);
	double getProgress();

	bool isBMSLoad;

	// BPM, Stop Data is included mixed
	// keynote, Longnote, invisible note is included mixed

	BMSKeyData keyData[65536];	// keydata (PS: if should departed by player)
	int keyDatanum;

	int bpmNum;
	BMSKeyData bpmData[65536];	// BPM Channel: #03 and #08 + STOP Channel: #09

	int BGANum;
	BMSKeyData BGAData[65536];	// BGA Channel: #04, #06(Poor), #07(Overlay)

	int StopNum;
	BMSKeyData StopData[65536];	// STOP Channel: #09

	int BGMNum;
	BMSKeyData BGMData[65536];	// BGM Channel: #01, 



										// for #02 channel (beat size)
										// default value: 1
	float keyBeatLength[256];			// [MAXBEAT]
	int keyBeatCount;					// beat count = end of beat

	int getBPM(int KeyValue);
	int getSTOP(int KeyValue);
private:
	int BMSParseMode;
	TCHAR *noteData;
	int locale;
	bool isUnicode;
	int fSize;
	int fPos;
	bool customwcscmp(TCHAR *t1, TCHAR *t2);

	int b_Player;
	TCHAR b_Title[1024];
	TCHAR b_Artist[1024];
	TCHAR b_Genre[1024];
	int b_BPM;
	int b_Playlevel;
	int b_Rank;
	int b_Total;
	int b_Volwav;
	TCHAR b_Stagefile[1024];
	TCHAR b_Videofile[1024];
	int b_WAVKey[10240];
	int b_BPMKey[10240];
	int b_STOPKey[10240];
	
};