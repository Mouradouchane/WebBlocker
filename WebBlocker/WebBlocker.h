﻿// for files read and wirte ...
// for what in main cpp file :)
/*
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <Windows.h>
*/

using namespace std;

namespace CONSTANTS {

	const string output = "[webBlocker] : ", hint = "[+]", warn = "[!]";

	// this string for targting where is windows in harddisk +   // this static path for hosts file 
	const string standarFilePath = getenv("SystemDrive") + string("/Windows/System32/Drivers/etc/hosts");

	const string getUserName() {
		char* userName = getenv("USER");

		if (!userName) {
			userName = getenv("USERNAME");
		}

		return userName;
	}
}

namespace TIME {
	string getFormatedDate() {

		time_t TE = time(0);
		struct tm* timeObject = localtime(&TE);

		// problem who do wired date formate here in this function

		int dt[] = { timeObject->tm_mday , timeObject->tm_mon + 1 , timeObject->tm_year + 1900 };
		string stv;

		int size = (sizeof(dt) / sizeof(int));

		for (int i = 0 ; i < size ; i += 1) {
			stv += std::to_string(dt[i]);
			if ( size - 1 != i) {
				stv += "/";
			}
		}

		return stv;
	}

	string Date = "[" __TIME__  "]";
}

	using namespace TIME;

namespace COLORS {

	HANDLE standarHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	void setDefultColor() {
		SetConsoleTextAttribute(standarHandle, 15);
	}

	void setConsoleColor(unsigned int color = 15) {
		if (color > 25) color = 15;
		SetConsoleTextAttribute(standarHandle, color);
	}

	void setWarningColor() {
		SetConsoleTextAttribute(standarHandle, 14);
	}

	void setErrorColor() {
		SetConsoleTextAttribute(standarHandle, 12);
	}

	void setHintColor() {
		SetConsoleTextAttribute(standarHandle, 10);
	}
}

namespace FILESFUNCTIONS {

	using namespace COLORS;

	string readAll(string fileName , bool OpenAsBinary = false) {
		try {
			// define var for opening file
			ifstream fName;
			// open file as binary or not
			if (!OpenAsBinary) fName = ifstream(fileName);
			else fName = ifstream(fileName, std::ifstream::binary);

			string content, line;

			// if file is open correctlly
			if (fName.is_open()) {

				// start reading line by line
				while (getline(fName, line))
				{
					// adding line + new line 
					content += line + "\n";
				}

			}
			else {
				// when file not open or not exit returning -1
				content = -1;
			}

			// closing file in end
			fName.close();
			// return all content in file or -1
			return content;
		}
		catch (exception error) {
			cout << "ERROR : " << error.what() << endl;
			return "";
		}
	}

	bool fileIsExist(string fileName) {
		bool r;
		try {
			ifstream f(fileName);

			r = f.good();
		}
		catch (exception error) {
			cout << "ERROR : " << error.what() << endl;
			r = false;
		}

		return r;
	}

	bool filePutContent(string fileName, string content) {
			// trying open file and putting some content
			ofstream fName(fileName, ios_base::app);

			// if open putting content
			if (fName.is_open()) {
				fName << "\n" <<content << endl;
				fName.close();
				return true;
			}

			return false;
	}

	// this function for checking if host file is exit in windows or not
	void checkingDesintation() {
		while (true) {
			if (fileIsExist(CONSTANTS::standarFilePath)) {
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
				filePutContent(CONSTANTS::standarFilePath, "# added in " + TIME::Date);
			}
		}
	}

}

namespace ASCIIART {
	
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	void printAsciiArt() {

			SetConsoleTextAttribute(consoleHandle, 10);
			cout << ("\t\t   _ _ _     _      _____ _         _   ") << endl;
			cout << ("\t\t  | | | |___| |_   | __  | |___ ___| |_ ___ ___ ") << endl;
			cout << ("\t\t  | | | | -_| . |  | __ -| | . |  _| '_| -_|  _|") << endl;
			cout << ("\t\t  |_____|___|___|  |_____|_|___|___|_,_|___|_| v1.0") << endl;
			SetConsoleTextAttribute(consoleHandle, 13);
			cout << ("================================================================================") << endl;
			COLORS::setDefultColor();
	}

}

namespace STRING {

	bool starts_with(const std::string& str, const std::string& prefix)
	{
		return str.find(prefix) == 0;
	}


	bool ends_with(const std::string& str, const std::string& suffix)
	{
		const auto pos = str.rfind(suffix);

		return (pos != std::string::npos) && (pos == (str.length() - suffix.length()));
	}

	std::vector<std::string> split(const std::string& str, const std::string& delim){
		size_t pos_start = 0, pos_end, delim_len = delim.length();
		std::string token;
		std::vector<std::string> tokens;

		while ((pos_end = str.find(delim, pos_start)) != std::string::npos)
		{
			token = str.substr(pos_start, pos_end - pos_start);
			pos_start = pos_end + delim_len;
			tokens.push_back(token);
		}

		tokens.push_back(str.substr(pos_start));
		return tokens;
	}

	void trim_left(std::string& str)
	{
		str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) { return !std::isspace(ch); }));
	}

	void trim_right(std::string& str)
	{
		str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) { return !std::isspace(ch); }).base(), str.end());
	}

	void trim(std::string& str)
	{
		trim_left(str);
		trim_right(str);
	}

	bool include(std::string strv = "_", char key = '@') {
		for (unsigned short c = 0; c < strv.length(); c += 1) {
			if (strv[c] == key) return true;
		}

		return false;
	}
}