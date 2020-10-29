// for standars & files read and wirte ...
#include <iostream>
#include <fstream>
// for winuser.h & resource.h
#include <cstdlib>
// for string usage
#include <string>
#include <vector>
// for time and windows api
#include <Windows.h>
#include <ctime>
#include <lmcons.h>
// for including icon resource
#include <winres.h>
#include <WinUser.h>
#include "resource.h"
// for multi usage in programme "MAIN HEADER FOR US"
#include "WebBlocker.h"


// checking system if windows as first step
#ifdef __unix__
	#define isUNIX 1
#elif defined(WIN32) || defined(_WIN32)
	#define isWIN 1
#endif

using namespace std;
using namespace FILESFUNCTIONS;
using namespace CONSTANTS;
using namespace ASCIIART;
using namespace COLORS;
using namespace TIME;
using namespace STRING;

//HINSTANCE hInstance; 
HICON icon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_ICON1));

int main() {

	/*	
		Program start 
		set console title as first step
	*/
	SetConsoleTitle(TEXT("WebBlocker v2"));

	printAsciiArt();
	setDefultColor();

	Sleep(500); // just sleeping for nice transition :)
	cout << "Welcome to WebBlocker v2 stable ..." + Date << endl; // printing Date in starting

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
		"-c or --clear for clearing console outputs"
	};

	const string AppVersion = "version 3 stable";

	// starting program after checking env & requirements 
	// in this step program entr to infinte loop for getting inputs from user & do task + give output
	while (true) {
		
		// getting user command as first-step
		cout << userNameCommand; getline(cin , command);

		// exit program
		if (command == "exit" || command == "EXIT" || command == "Exit" || command == "webBlocker --exit") {
			exit(1);
		}
		else if (command == "webBlocker --version" || command == "webBlocker -v" || command == "version") {
			cout << output << AppVersion << endl;
		}
		// help commands
		else if (command == "webBlocker --help" || command == "webBlocker -h" || command == "help") {
			for (unsigned short c = 0; c < commandsHELP.size(); c += 1) {
				Sleep(250);
				setConsoleColor(13);
				cout << output;
				setDefultColor();
				cout << commandsHELP[c] << endl <<endl;
			}
		}
		// clear console
		else if (command == "clear" || command == "webBlocker --clear" || command == "webBlocker -c") {
			// clear cmd or console
			system("cls");
			// print ascii art from scratch :)
			printAsciiArt();
		}
		// when user ask for block website or multi
		else if (starts_with(command, "webBlocker --block") || starts_with(command , "webBlocker -b")) {
			// checking here & other staff 
			vector<string> vars = split(command , " ");
					// i = 2 for skiping first tow keyword reserved by program :)
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
					// if address site end with . automaticlly we adding com as def domain
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

					// show to user success message as last step in this task
					cout << " blocking web " << " => " << targetweb << endl;
				}
				else {
					// if user use worng syntax 
					Sleep(250);

					setWarningColor();
					cout << output << " Wrong Syntax Because " << targetweb << " Not Valid 'WebSite' " << endl;
					setDefultColor();
				}
			}
		}
		else {
			// if user use commands not exist 
			setWarningColor();
			cout << output << command << " not found ! try 'help' " << endl;
			setDefultColor();
		}

	}

	return 0;
}
