#include <iostream>
#include <fstream>
#include <string>
#include "WebBlocker.h"
#include <Windows.h>
#include <cstdlib>
#include <ctime>

// checking system if windows
#ifdef __unix__
	#define isUNIX 1
#elif defined(WIN32) || defined(_WIN32)
	#define isWIN 1
#endif

namespace DATE_TIME {
	time_t tm = time(0);
	struct tm* timeObject = localtime(&tm);

	short day = timeObject->tm_mday, mouth = (timeObject->tm_mon+1);
	int year = (timeObject->tm_year + 1900);

	void PrintDate() {
		cout << day << '/' << mouth << '/' << year << endl;
	}

}

using namespace std;
using namespace funcs;
using namespace constants;
using namespace asciiArt;
using namespace ConsoleColors;
using namespace ConsoleOutputs;
using namespace DATE_TIME;

void checkingDesintation() {
	while (true) {
		if (fileIsExist(standarFilePath)) {
			setHintColor();
			Sleep(500);
			cout << "[+] Founding Destination to System32" << endl;
			setDefultColor();
			break;
		}
		else {
			Sleep(500);
			setWarningColor();
			cout << "[!] Missing Destionation to System32 'Destination Not Found'" << endl;

			Sleep(250);
			setHintColor();
			cout << "[+] Adding Destination to System32 :) " << endl;
			filePutContent(standarFilePath, "# added in ");

		}
	}
}

int main(){
	/*
		ofstream 	Creates and writes to files
		ifstream 	Reads from files
		fstream 	A combination of ofstream and ifstream: creates, reads, and writes to files
	*/

	SetConsoleTitle(TEXT("WebBlocker v1.0"));

	PrintDate();

	printAsciiArt();
	setDefultColor();

	Sleep(500);
	PRINT("def" , "Welcome to WebBlocker v1.0 Beta ...");

	Sleep(500);
	setWarningColor();
	cout <<"[!] Checking Requirements Before Staring ..." << endl;
	setDefultColor();

	Sleep(500);

	if (isWIN) {
		setHintColor(); 
		cout << "[+] Environment Working Windows Found" << endl;
	}
	else {
		setErrorColor();
		cout << "[x] Environment Not Working 'WebBlocker' Only In Windows";
		exit(1);
	}

	Sleep(500);
	


	setDefultColor();

	getchar();
	return 0;
}



