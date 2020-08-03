// for files read and wirte ...
#include <iostream>
#include <fstream>
// 
#include <cstdlib>
// for string usage
#include <string>
#include <vector>
// for time and windows api
#include <Windows.h>
#include <ctime>
#include <lmcons.h>
//for json usage
#include "json.hpp"
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
using namespace stringNews;
using namespace logFunctions;

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
	printjson();

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

	cout << "webBlocker : -h or --help" << endl;

	setDefultColor();

	/*
		- this for getting user input
	*/

	const string userName = getUserName(), userNameCommand = "[" + userName + "] :" , output = "[webBlocker] : ";
	string command;

	vector<string> commandsHELP = {
		"webBlocker 'command' 'args'",
		"webBlocker --exit or Exit or EXIT",
		"-v or --version for programme version",
		"-b or --block for blocking website \nNote! : enter target web site without 'Protocole http|https|...' \nNote! : enter target web without 'www.' \nEx: ex.com",
		"-l or --log for watching list of blocked sites + time",
	};

	const string AppVersion = "version 1 beta none stable";

	while (true) {

		cout << userNameCommand; getline(cin , command);

		if (command == "exit" || command == "EXIT" || command == "Exit" || command == "webBlocker --exit") {
			exit(1);
		}
		else if (command == "webBlocker --version" || command == "webBlocker -v" || command == "version") {
			cout << output << AppVersion << endl;
		}
		else if (command == "webBlocker --help" || command == "webBlocker -h" || command == "help") {
			for (unsigned short c = 0; c < commandsHELP.size(); c += 1) {
				Sleep(250);
				setConsoleColor(13);
				cout << output;
				setDefultColor();
				cout << commandsHELP[c] << endl <<endl;
			}
		}
		else if (starts_with(command, "webBlocker --block") || starts_with(command , "webBlocker -b")) {
			
			vector<string> vars = split(command , " ");
			
			for (unsigned short i = 2; i < vars.size(); i += 1) { 

				string targetweb(vars[i].erase(vars[i].find_last_not_of(" \n\r\t") + 1));

				trim(targetweb);

				if (targetweb != " " && targetweb != "" && 
					starts_with(targetweb , "www.") != true &&
					starts_with(targetweb , "https://") != true &&
					starts_with(targetweb, "https::") != true &&
					starts_with(targetweb, "http://") != true &&
					include(targetweb , '.')
					) {

					Sleep(250);

					if (ends_with(targetweb, ".")) {
						targetweb += "com";
					}

					setHintColor();
					cout << output;
					setDefultColor();
				
					filePutContent(standarFilePath , "127.0.0.1 " + targetweb);
					filePutContent(standarFilePath, "127.0.0.1 www." + targetweb);
					filePutContent(standarFilePath, "127.0.0.1 https://www." + targetweb);
					filePutContent(standarFilePath, "127.0.0.1 http://www." + targetweb);

					cout << " blocking web " << " => " << targetweb << endl;
					
				}
				else {
					Sleep(250);

					setWarningColor();
					cout << output << " Wrong Syntax Because " << targetweb << " Not Valid 'WebSite' " << endl;
					setDefultColor();
				}
			}
		}
		else {
			setWarningColor();
			cout << output << command << " not found ! try 'help' " << endl;
			setDefultColor();
		}

	}

	return 0;
}
