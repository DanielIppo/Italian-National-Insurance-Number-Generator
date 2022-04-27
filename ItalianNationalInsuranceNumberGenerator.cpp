/* Italian National Insurance Number Generator by DanielIppo contribute: Filippo127*/
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <string>
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

int checkInput(int check) {
	while (cin.fail()) {
		cin.clear();
		cout << "\nThe number you insert is wrong, try again...\n";
		cin.ignore(1000, '\n');
		cin >> check;
	}
	return check;
}

//Global Variable declaration
char name[90];
char surname[30];
char gender[2];
int birthDay;
int birthMonth;
int birthYear;


//The class to insert the data of the user
class InsertDate {
public:
	char nameDate[90];
	char surnameDate[30];
	char genderDate[2];
	int birthDayDate;
	int birthMonthDate;
	int birthYearDate;

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
				cout << "\033[A\33[2K\033[A\33[2K\rName: " << Green << Bold;;
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
		
	//Create a function to verify the BirthYear
	int verifyBirthYear(int birthYearDate) {
		if (birthYearDate > 2019 || birthYearDate < 1900) {
			cout << Red << "Error: Invalid year of birth! Please re-insert it." << AttributeStringOff << endl;
			sleep3();
			cout << "\033[A\33[2K\033[A\33[2K\rBirth Year: " << Green << Bold;
			cout.flush();
			cin >> birthYearDate;
			verifyBirthYear(birthYearDate);
		}
		else {
			return birthYearDate;
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
		checkInput(birthDayDate);
		verifyBirthDay(birthDayDate);

		cout << "Birth Month: " << Green << Bold;
		cin >> birthMonthDate;
		cout << AttributeStringOff;
		verifyBirthMonth(birthMonthDate);

		cout << AttributeStringOff << "Birth Year: " << Green << Bold;
		cin >> birthYearDate;
		cout << AttributeStringOff;
		verifyBirthYear(birthYearDate);
		
		classDate_to_globalDate(nameDate, surnameDate, genderDate, birthDayDate, birthMonthDate, birthYearDate);
	}
	
	//Create a funtion to insert the data of the user to the global variable
	void classDate_to_globalDate(char nameDate[], char surnameDate[], char genderDate[], int birthDayDate, int birthMonthDate, int birthYearDate) {
		strcpy(name, nameDate);
		strcpy(surname, surnameDate);
		strcpy(gender, genderDate);
		birthDay = birthDayDate;
		birthMonth = birthMonthDate;
		birthYear = birthYearDate;
	}
};

//Class to calculate the Italian National Insurance Number
class Generator {
	
};


int main() {
	InsertDate insertDate;
	header();
	cout <<Blue<<Bold<< "\nHello I'm your personal Italian National Insurance Number Generator.\nWrite below your data:" << AttributeStringOff << endl<<endl;
	insertDate.insertDateFunction();
	clear();
	Generator generator;
	header();


	return 0;
}
