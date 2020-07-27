#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// for win API
#include <Windows.h>


using namespace std;

namespace Filesfuncs {

	string readAll(string fileName) {

		// open file
		ifstream fName(fileName);
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

	bool fileIsExist(string fileName) {
		ifstream f(fileName);

		return f.good();
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

	string Boo(bool b) {
		string s;

		if (b) { s = "true"; }
		else s = "false";

		return s;
	}
}

namespace asciiArt {
	
	void printAsciiArt() {

		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

			SetConsoleTextAttribute(consoleHandle, 10);
			cout << ("\t\t   _ _ _     _      _____ _         _   ") << endl;
			cout << ("\t\t  | | | |___| |_   | __  | |___ ___| |_ ___ ___ ") << endl;
			cout << ("\t\t  | | | | -_| . |  | __ -| | . |  _| '_| -_|  _|") << endl;
			cout << ("\t\t  |_____|___|___|  |_____|_|___|___|_,_|___|_| v1.0") << endl;
			SetConsoleTextAttribute(consoleHandle, 13);
			cout << ("================================================================================") << endl;
			//setDefultColor();
	}

	HANDLE standarHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	
}

namespace ConsoleColors {

	void setDefultColor() {
		SetConsoleTextAttribute(asciiArt::standarHandle, 15);
	}

	void setConsoleColor(unsigned int color = 15) {
		if (color > 25) color = 15;
		SetConsoleTextAttribute(asciiArt::standarHandle, color);
	}

	void setWarningColor() {
		SetConsoleTextAttribute(asciiArt::standarHandle , 14);
	}

	void setErrorColor() {
		SetConsoleTextAttribute(asciiArt::standarHandle, 12);
	}

	void setHintColor() {
		SetConsoleTextAttribute(asciiArt::standarHandle, 10);
	}
}

namespace ConsoleOutputs {
	
	void PRINT(string outputType = "def" , string msg = "n/a" , string endLine = "\n") {
			
		if (outputType == "hint") {
			ConsoleColors::setHintColor();
			cout << "[+] hint\t: ";
			ConsoleColors::setDefultColor();
			cout << msg << endLine;
		}
		else if (outputType == "error") {
			ConsoleColors::setErrorColor();
			cout << "[x] error\t: ";
			ConsoleColors::setDefultColor();
			cout << msg << endLine;
		}
		else if (outputType == "warn") {
			ConsoleColors::setWarningColor();
			cout << "[!] warning\t: ";
			ConsoleColors::setDefultColor();
			cout << msg << endLine;
		}
		else {
			ConsoleColors::setDefultColor();
			cout << "[-] " << msg << endLine;
		}
	}

}

namespace constants {
	const string standarFilePath = "C:/Windows/System32/Drivers/etc/hosts";


	string getUserName() {
		char* userName = getenv("USER");

		if(!userName) {
			userName = getenv("USERNAME");
		}

		return userName;
	}

}

namespace stringNews {

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