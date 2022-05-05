/* Italian National Insurance Number Generator by DanielIppo & Pll1n contribute: Filippo127*/
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <string.h>
#include <string>
size_t strlen(const char* s);
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
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << AttributeStringOff << endl;
}

int checkInput(int check, string variable) {
	while (cin.fail()) {
		cin.clear();
		cout <<Red<< "The number you insert is wrong, Please re-insert it."<<AttributeStringOff;
		cin.ignore(1000, '\n');
		sleep3();
		cout << "\33[2K\033[A\33[2K\r"<<variable<< Green << Bold;
		cin >> check;
		cout << AttributeStringOff;
	}
	return check;
}

//Global Variable declaration
char name[90];
char surname[30];
char gender[2];
int birthDay;
int birthMonth;
char birthYear[5];


//The class to insert the data of the user
class InsertDate {
public:
	char nameDate[90];
	char surnameDate[90];
	char genderDate[2];
	int birthDayDate;
	int birthMonthDate;
	char birthYearDate[5];

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
				cout << Red<< "Invalid name! Please re-insert it." <<AttributeStringOff<< endl;
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
				cout <<Red<< "Invalid surname! Please re-insert it." << AttributeStringOff << endl;
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
			cout << "\033[A\33[2K\033[A\33[2K\rGender: " << Green << Bold;;
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
			cout <<Red<< "Error: Invalid day of birth! Please re-insert it." << AttributeStringOff << endl;
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
		} else {
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

	
	void insertDateFunction() {// In this function, the user is asked to insert data
		cout << "Name: "<<Green<<Bold;
		cin >> nameDate;
		cout << AttributeStringOff;
		verifyName(nameDate);

		cout << "Surname: " << Green << Bold;
		cin >> surnameDate;
		cout << AttributeStringOff;
		verifySurname(surnameDate);

		cout << "Gender [m/f]:" << Green << Bold;
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
		
		classDate_to_globalDate(nameDate, surnameDate, genderDate, birthDayDate, birthMonthDate, birthYearDate);
	}
	
	//Create a funtion to insert the data of the user to the global variable
	void classDate_to_globalDate(char nameDate[], char surnameDate[], char genderDate[], int birthDayDate, int birthMonthDate, char birthYearDate[]) {
		strcpy(name, nameDate);
		strcpy(surname, surnameDate);
		strcpy(gender, genderDate);
		strcpy(birthYear, birthYearDate),
		birthDay = birthDayDate;
		birthMonth = birthMonthDate;
	}
};

//Class to calculate the Italian National Insurance Number
class GeneratorNIN {
public:
	
	char nameGenerator[90] = { };
	char surnameGenerator[90] = { };
	char genderGenerator[90] = { };
	int birthDayGenerator = 0;
	int birthMonthGenerator = 0;
	char birthYearGenerator[4] = { };
	
	char consonantsName[3] = { };
	char consonantsSurname[3] = { };
	char splittedYear[2] = { };


	//Create a function to insert the global variable to the class
	void globalDate_to_classDate(char name[], char surname[], char gender[], int birthDay, int birthMonth, char birthYear[]) {
		strcpy(nameGenerator, name);
		strcpy(surnameGenerator, surname);
		strcpy(genderGenerator, gender);
		strcpy(birthYearGenerator, birthYear);
		birthDayGenerator = birthDay;
		birthMonthGenerator = birthMonth;
	}
	
	//Create a function to separate the consonants to the vowels
	void separateConsonants(char consonants[], char* consonants1) {
		int counter = 0;
		for(int i = 0; i < strlen(consonants); i++) {
			if (consonants[i] == 'a' || consonants[i] == 'A' || consonants[i] == 'e' || consonants[i] == 'E' || consonants[i] == 'i' || consonants[i] == 'I' || consonants[i] == 'o'|| consonants[i] == 'O' || consonants[i] == 'u' || consonants[i] == 'U') {
				continue;
			} else {
				consonants1[counter] = consonants[i];
				counter++;
				if (counter == 3) {
					break;
				}
			}
		}
	}

	//Create a function to split the year
	void splitYears(char birthyear[], char* birthyearsplitter) {
		for (int i = 0; i < 2; i++) {
			int j = 2;
			birthyearsplitter[i] = birthyear[j];
			j++;
		}
	}

	void generatorInsurance() {
		globalDate_to_classDate(name, surname, gender, birthDay, birthMonth, birthYear);
		separateConsonants(surnameGenerator, consonantsSurname);
		separateConsonants(nameGenerator, consonantsName);
		splitYears(birthYearGenerator, splittedYear);

		cout << consonantsSurname << consonantsName << splittedYear;
		
	}
};


int main() {
	InsertDate insertDate;
	header();
	cout <<Blue<<Bold<< "\nHello I'm your personal Italian National Insurance Number Generator.\nWrite below your data:" << AttributeStringOff << endl<<endl;
	insertDate.insertDateFunction();
	clear();
	GeneratorNIN generator;
	header();
	generator.generatorInsurance();
	
	
	return 0;
}


