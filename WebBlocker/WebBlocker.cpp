
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
// for multi usage in programme
#include "WebBlocker.h"

// including icon resource
#include <winres.h>
#include <WinUser.h>
#include "resource.h"

//HINSTANCE hInstance; 
HICON icon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON1));

// checking system if windows as first step
#ifdef __unix__
	#define isUNIX 1
#elif defined(WIN32) || defined(_WIN32)
	#define isWIN 1
#endif

using namespace std;
using namespace Filesfuncs;
using namespace constants;
using namespace asciiArt;
using namespace ConsoleColors;
using namespace DATE_TIME;
using namespace stringNews;
using namespace logFunctions;


int main(){

	/*
		icon part : before start
	*/


	/*	
		Program start 
		set console title as first step
	*/
	SetConsoleTitle(TEXT("WebBlocker v1"));

	printAsciiArt();
	setDefultColor();

	Sleep(500); // just sleeping for nice transition :)
	cout << "Welcome to WebBlocker v1 stable ..." + Date << endl; // printing Date in starting

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
	
	// checking host file if exist or not
	checkingDesintation();
	Sleep(500);

	// checking log file if exist or not 
	checkLogFileIsExist();
	Sleep(500);

	setWarningColor();
	cout << "[!] Note : All websites that you place as a user It will be blocked \n \t   until the next formatting" << endl;
	Sleep(500);
	
	setDefultColor();
	cout << "webBlocker : -h or --help" << endl;

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
		"-c or --clear for clearing console outputs"
	};

	const string AppVersion = "version 1 stable";

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
		else if (command == "webBlocker --log" || command == "webBlocker -l" || command == "log") {

			// calling this funtion in WebBlocker.h for reading and printing all 
			// blocked sites in array from log.json file
			printAllBlockedSitesInLog();

		}
		else if (command == "clear" || command == "webBlocker --clear" || command == "webBlocker -c") {
			// clear cmd or console
			system("cls");
			// print ascii art from scratch :)
			printAsciiArt();
		}
		else if (starts_with(command, "webBlocker --block") || starts_with(command , "webBlocker -b")) {
			
			vector<string> vars = split(command , " ");
			
			for (unsigned short i = 2; i < vars.size(); i += 1) { 

				string targetweb(vars[i].erase(vars[i].find_last_not_of(" \n\r\t") + 1));

				trim(targetweb);

				if (targetweb != " " && targetweb != "" && 
					starts_with(targetweb , "www.") != true &&
					starts_with(targetweb , "https://") != true &&
					starts_with(targetweb,	"https::") != true &&
					starts_with(targetweb,	"http://") != true &&
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
					filePutContent(standarFilePath , "127.0.0.1 www." + targetweb);
					filePutContent(standarFilePath , "127.0.0.1 https://www." + targetweb);
					filePutContent(standarFilePath , "127.0.0.1 http://www." + targetweb);

					// when programme do all steps should append new blocked site to log.json
					// bay using appendNewBlockedSiteToLog();
					appendNewBlockedSiteToLog(targetweb);

					// show to user success message 
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
