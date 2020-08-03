// for files read and wirte ...
#include <iostream>
#include <fstream>
// for string usage
#include <string>
#include <vector>
// for win API
#include <Windows.h>
// for log.json
#include <windows.data.json.h>
//for json usage
#include "json.hpp"

using namespace std;

namespace DATE_TIME {
	time_t tm = time(0);
	struct tm* timeObject = localtime(&tm);

	short day = timeObject->tm_mday, mouth = (timeObject->tm_mon + 1);
	int year = (timeObject->tm_year + 1900);

	void PrintDate(string newL = "") {
		cout << day << '/' << mouth << '/' << year << newL;
	}

	string Date = "[" __TIME__  "]";
}

namespace Filesfuncs {

	string readAll(string fileName , bool OpenAsBinary = false) {

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

namespace logFunctions {
	string output = "[webBlocker] : ";

	using namespace Filesfuncs;

	// for json usage "recommended in library"
	using json = nlohmann::json;

	// opening log.json and getting all data on it as string
	string jsonAsString = readAll("log.json" );


	// parsing log data from ' jsonAsString '
	auto log = json::parse(jsonAsString);

	// class for getting all blocked sites in json varible after parse :)
	class BlockedSite {
		private : 
			string website, fullTime , domin , date , time;

		public :
			BlockedSite(string website , string time = __TIME__ , string date = __DATE__) {
				this->website = website;
				this->fullTime = (time + " " + date);
				this->date = date;
				this->time = time;
			}
			string getSite() {
				return this->website;
			}
			string getFullTime() {
				return fullTime;
			}
	};

	void printAllBlockedSitesInLog() {
		// vector of BlockedSite of Get on it all sites as objects from ' log '
		vector<BlockedSite> allSites;

		try {
			// get all from 'log' to 'vector allSites'
			for (unsigned int c = 0; c < log["blockedSites"].size(); c += 1) {
				// pushing new objects to vector 
				allSites.push_back(BlockedSite(log["blockedSites"][c]["website"] , log["blockedSites"][c]["time"] , log["blockedSites"][c]["date"]));
			} 

			// switching color console to red for defining starting table
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , 12);
			cout << output << ("webSite \t \t Time of blocking") << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

			for (unsigned int c = 0; c < allSites.size(); c += 1) {
				Sleep(250);
				// starting printing blocked sites as in table
				cout << output << ( allSites[c].getSite() + " \t " + allSites[c].getFullTime() )<< endl;
			}
		}
		catch (exception error) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout <<"ERROR : " << error.what() <<endl;
			// backing to default color
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
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