/* Italian National Insurance Number Generator by DanielIppo & Pall1n contribute: Filippo127*/
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <vector>
using namespace std;

#pragma warning(disable : 4996)

//Line 12 to 41 are the code for embellish the program

string Red = "\x1b[31m";
string Yellow = "\x1b[33m";
string Green = "\x1b[32m";
string Blue = "\x1b[94m";
string Magenta = "\x1b[95m";
string ColorDefault = "\x1b[0m";
string Bold = "\x1b[1m";
string AttributeStringOff = "\x1b[0m";

void sleep3() {
#ifdef _WIN32
	Sleep(3000);
#else
	sleep(3);
#endif
}

void clear() {
#if _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void header() {
	cout << Red << Bold << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	cout << "@@@@ Italian National Insurance Number Generator @@@@" << endl;
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << AttributeStringOff << endl << endl;
}

int checkInput(int check, string variable) {
	while (cin.fail()) {
		cin.clear();
		cout << Red << "The number you insert is wrong, Please re-insert it." << AttributeStringOff;
		cin.ignore(1000, '\n');
		sleep3();
		cout << "\33[2K\033[A\33[2K\r" << variable << Green << Bold;
		cin >> check;
		cout << AttributeStringOff;
	}
	return check;
}

string get_right_of_delim(string const& str, string const& delim) {
	return str.substr(str.find(delim) + delim.size());
}

string get_left_of_delim(string const& str, string const& delim) {
	return str.substr(0, str.find(delim));
}

vector <string> city;
vector <string> codeOfCity;

//The class to transfer the data to the program to a txt file
class TransferData {	
public:

	void openFile() {
		string line;
		ifstream myfile("Towns.txt");

		int i = 0;

		if (myfile.is_open()) {
			while (getline(myfile, line)) {
				string cityName = get_left_of_delim(line, ";");
				string code = get_left_of_delim(get_right_of_delim(line, ";"), ";");

				city.push_back(cityName);
				codeOfCity.push_back(code);
				i++;
			}
		}
		else {
			cout << Red << "Error to open the file " << Bold << "Towns.txt" << AttributeStringOff << endl;
		}

	}
};
TransferData transferData;

//The class to insert the data of the user
class InsertDate {
public:
	char nameDate[90];
	char surnameDate[90];
	char genderDate[2];
	char birthYearDate[90];
	string birthPlaceDate;
	int birthDayDate = 0;
	int birthMonthDate = 0;
	int birthPlaceIndex = 0;

	//Create a function to verify the name
	char verifyName(char nameDate[]) {
		for (int i = 0; i < strlen(nameDate); i++) {
			if (nameDate[i] >= 'A' && nameDate[i] <= 'Z') {
				continue;
			}
			else if (nameDate[i] >= 'a' && nameDate[i] <= 'z') {
				continue;
			}
			else if (nameDate[i] == ' ') {
				continue;
			}
			else {
				cout << Red << "Invalid name! Please re-insert it." << AttributeStringOff << endl;
				sleep3();
				cout << "\033[A\33[2K\033[A\33[2K\rName: " << Green << Bold;
				// \033[A is the command to move the cursor up, \33[2K is the command to clear the line, \r is the command to return to the beginning of the line
				cout.flush();
				cin >> nameDate;
				cout << AttributeStringOff;
				verifyName(nameDate);
			}
		}
		return nameDate[strlen(nameDate)];
	}
	//Create a function to verify the surname
	char verifySurname(char surnameDate[]) {
		for (int i = 0; i < strlen(surnameDate); i++) {
			if (surnameDate[i] >= 'A' && surnameDate[i] <= 'Z') {
				continue;
			}
			else if (surnameDate[i] >= 'a' && surnameDate[i] <= 'z') {
				continue;
			}
			else if (surnameDate[i] == ' ') {
				continue;
			}
			else {
				cout << Red << "Invalid surname! Please re-insert it." << AttributeStringOff << endl;
				sleep3();
				cout << "\033[A\33[2K\033[A\33[2K\rSurname: " << Green << Bold;;
				cout.flush();
				cin >> surnameDate;
				cout << AttributeStringOff;
				verifySurname(surnameDate);
			}
		}
		return surnameDate[strlen(surnameDate)];
	}

	//Create a function to verify the gender
	char verifyGender(char gendeDate[]) {
		if (genderDate[0] == 'm' or genderDate[0] == 'M' or genderDate[0] == 'f' or genderDate[0] == 'F') {
		}
		else {
			cout << Red << "Invalid gender! Please re-insert it." << AttributeStringOff << endl;
			sleep3();
			cout << "\033[A\33[2K\033[A\33[2K\rGender [m/f]: " << Green << Bold;;
			cout.flush();
			cin >> genderDate;
			cout << AttributeStringOff;
			verifyGender(genderDate);
		}
		return genderDate[strlen(genderDate)];
	}

	//Create a function to verify the BirthDay
	int verifyBirthDay(int birthDayDate) {
		if (birthDayDate > 31 || birthDayDate < 1) {
			cout << Red << "Error: Invalid day of birth! Please re-insert it." << AttributeStringOff << endl;
			sleep3();
			cout << "\033[A\33[2K\033[A\33[2K\rBirth Day: " << Green << Bold;
			cout.flush();
			cin >> birthDayDate;
			cout << AttributeStringOff;
			verifyBirthDay(birthDayDate);
		}
		else {
			return birthDayDate;
		}
	}

	//Create a function to verify the BirthMonth
	int verifyBirthMonth(int birthMonthDate) {
		if (birthMonthDate > 12 || birthMonthDate < 1) {
			cout << Red << "Error: The month is not valid! Please re-insert it." << AttributeStringOff << endl;
			sleep3();
			cout << "\033[A\33[2K\033[A\33[2K\rBirth Month: " << Green << Bold;
			cout.flush();
			cin >> birthMonthDate;
			verifyBirthDay(birthMonthDate);
		}
		else {
			return birthMonthDate;
		}

	}

	//Create a function to verify the BirthYear with a char array
	char verifyBirthYear(char birthYearDateV[]) {
		int birthYearDateInt = atoi(birthYearDateV);
		if (birthYearDateInt > 2019 || birthYearDateInt < 1900) {
			cout << Red << "Error: Invalid year of birth! Please re-insert it." << AttributeStringOff << endl;
			sleep3();
			cout << "\033[A\33[2K\033[A\33[2K\rBirth Year: " << Green << Bold;
			cout.flush();
			cin >> birthYearDateV;
			cout << AttributeStringOff;
			strcpy(birthYearDate, birthYearDateV);
			verifyBirthYear(birthYearDate);
		}
		else {
			return birthYearDateV[strlen(birthYearDateV)];
		}
	}

	//Create a function to verify the BirthPlace
	string verifyBirthPlace(string birthplacedate, int& birthPlaceIndex) {
		
			if(find(city.begin(), city.end(), birthplacedate) != city.end()) {
				return birthplacedate;
			}
			else {
				cout << Red << "Error: Invalid place of birth! Please re-insert it." << AttributeStringOff << endl;
				sleep3();
				cout << "\033[A\33[2K\033[A\33[2K\rBirth Place: " << Green << Bold;
				cout.flush();
				cin >> birthplacedate;
				cout << AttributeStringOff;
				verifyBirthPlace(birthplacedate, birthPlaceIndex);
			}
			
			/*cout << Red << "Error: Invalid birth place! Please re-insert it." << AttributeStringOff << endl;
			sleep3();
			cout << "\033[A\33[2K\rBirth Place: " << Green << Bold;
			cout.flush();
			cin >> birthplacedate;
			cout << AttributeStringOff;
			verifyBirthPlace(birthplacedate, birthPlaceIndex);*/

	}


	void insertDateFunction() {// In this function, the user is asked to insert data
		cout << "Name: " << Green << Bold;
		cin >> nameDate;
		cout << AttributeStringOff;
		verifyName(nameDate);

		cout << "Surname: " << Green << Bold;
		cin >> surnameDate;
		cout << AttributeStringOff;
		verifySurname(surnameDate);

		cout << "Gender [m/f]: " << Green << Bold;
		cin >> genderDate;
		cout << AttributeStringOff;
		verifyGender(genderDate);

		cout << "Birth Day: " << Green << Bold;
		cin >> birthDayDate;
		cout << AttributeStringOff;
		birthDayDate = checkInput(birthDayDate, "Birth Day: ");
		verifyBirthDay(birthDayDate);

		cout << "Birth Month: " << Green << Bold;
		cin >> birthMonthDate;
		cout << AttributeStringOff;
		birthMonthDate = checkInput(birthMonthDate, "Birth Month: ");
		verifyBirthMonth(birthMonthDate);

		cout << AttributeStringOff << "Birth Year: " << Green << Bold;
		cin >> birthYearDate;
		cout << AttributeStringOff;
		verifyBirthYear(birthYearDate);

		cout << AttributeStringOff << "Birth Place: " << Green << Bold;
		cin.clear();
		getline(cin, birthPlaceDate, '\n');
		cout << AttributeStringOff;
		verifyBirthPlace(birthPlaceDate, birthPlaceIndex);

	}

};

InsertDate insertDate;

//Class to calculate the Italian National Insurance Number
class GeneratorNIN {
public:

	char consonantsSurname[90] = {};
	char consonantsName[90] = {};
	char splittedYears[90] = {};

	//Create a function to separate the consonants to the vowels
	void separateConsonants(char consonants[], char consonants1[]) {
		int counter = 0;
		for (int i = 0; i < strlen(consonants); i++) {
			if (consonants[i] == 'a' || consonants[i] == 'A' || consonants[i] == 'e' || consonants[i] == 'E' || consonants[i] == 'i' || consonants[i] == 'I' || consonants[i] == 'o' || consonants[i] == 'O' || consonants[i] == 'u' || consonants[i] == 'U') {
				continue;
			}
			else {
				consonants1[counter] = consonants[i];
				counter++;
				if (counter == 3) {
					break;
				}
			}
		}
	}

	//Create a function to split the year
	void splitYears(char birthyear[], char birthyearsplitter[]) {
		birthyearsplitter[0] = birthyear[2];
		birthyearsplitter[1] = birthyear[3];
	}

	void generatorInsurance() {

		separateConsonants(insertDate.surnameDate, consonantsSurname);
		separateConsonants(insertDate.nameDate, consonantsName);
		splitYears(insertDate.birthYearDate, splittedYears);

	}



};
GeneratorNIN generator;



int main() {
	transferData.openFile();
	header();
	cout << Blue << Bold << "Hello I'm your personal Italian National Insurance Number Generator.\nWrite below your data:" << AttributeStringOff << endl << endl;
	insertDate.insertDateFunction();
	clear();
	header();
	generator.generatorInsurance();


	return 0;
}
