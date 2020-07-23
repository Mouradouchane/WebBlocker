#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
// for user
#include <lmcons.h>
#include "WebBlocker.h"

// checking system if windows as first step
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

	void PrintDate(string newL = "") {
		cout << day << '/' << mouth << '/' << year << newL;
	}

	string Date = "[ " __TIME__  "]";
}

using namespace std;
using namespace Filesfuncs;
using namespace constants;
using namespace asciiArt;
using namespace ConsoleColors;
using namespace ConsoleOutputs;
using namespace DATE_TIME;

// this function for checking if host file is exit in windows or not
void checkingDesintation() {
	while (true) {
		if (fileIsExist(standarFilePath)) {
			// if exist print hint & going for next step
			setHintColor();
			Sleep(500);
			cout << "[+] Founding Destination to System32" << endl;
			setDefultColor();
			break;
		}
		else {
			// else print warninng + trying making new HOST File !
			Sleep(500);
			setWarningColor();
			cout << "[!] Missing Destionation to System32 'Destination Not Found'" << endl;

			Sleep(250);
			setHintColor();
			cout << "[+] Adding Destination to System32 :) " << endl;
			// trying making new HOST File 
			filePutContent(standarFilePath, "# added in " + Date);
		}
	}
}

int main(){
	/*
		ofstream 	Creates and writes to files
		ifstream 	Reads from files
		fstream 	A combination of ofstream and ifstream: creates, reads, and writes to files
	*/

	/*	
		Program start 
		set console title as first step
	*/
	SetConsoleTitle(TEXT("WebBlocker v1.0"));


	printAsciiArt();
	setDefultColor();

	Sleep(500); // just sleeping for nice transition :)
	PRINT("def" , "Welcome to WebBlocker v1.0 Beta ..." + Date); // printing Date in starting



	Sleep(500); // just sleeping for nice transition :)

	setWarningColor();
	cout <<"[!] Checking Requirements Before Staring ..." << endl;
	setDefultColor();

	Sleep(500); // just sleeping for nice transition :)

	if (isWIN) {
		// if programme start in windows print hint to user
		setHintColor(); 
		cout << "[+] Environment Working Windows Found" << endl;
		setConsoleColor(13);
		cout << "[$] Programme Requirements Found" << endl;
		setDefultColor();
	}
	else {
		// else Error Environment + Exit Programme 
		setErrorColor();
		cout << "[x] Environment Not Working 'WebBlocker' Only Work In Windows" << endl;
		cout << "[x] Missing Host File " << endl;

		Sleep(500); 
		exit(1);
	}

	Sleep(500);
	
	// checking host file 
	checkingDesintation();
	
	setWarningColor();
	cout << "[!] Note : All websites that you place as a user It will be blocked \n \t   until the next formatting" << endl;
	
	setDefultColor();

	cout << "webblocker : -h or --help" << endl;

	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;
	GetUserName(username, &username_len);


	setDefultColor();

	getchar();
	return 0;
}



