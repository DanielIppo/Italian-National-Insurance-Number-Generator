/* Italian National Insurance Number Generator by DanielIppo contribute: Filippo127*/
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
using namespace std;

void sleep3() {
	#ifdef _WIN32
	Sleep(3000);
	#else
	sleep(3);
	#endif
}



class InsertDate {
public:
    char name[90];
    char surname[30];
    char gender[2];
    int birth_day;
    int birth_month;
    int birth_year;

    void insertDateFunction() {// In this function, the user is asked to insert data
		cout << "Name: ";           cin >> name;		verifyName(name);
        cout << "Surname: ";        cin >> surname;		verifyName(surname);
		cout << "Gender: [m/f]";         cin >> gender;		verifyGender(gender);
        cout << "Birth Day: ";      cin >> birth_day;
        cout << "Birth Month: ";    cin >> birth_month;
        cout << "Birth Year: ";     cin >> birth_year;
    }
	
    //Create a function to verify the name
	char verifyName(char name[]) {
		for (int i = 0; i < strlen(name); i++) {
			if (name[i] >= 'A' && name[i] <= 'Z') {
				continue;
			} else if (name[i] >= 'a' && name[i] <= 'z') {
				continue;
			} else if (name[i] == ' ') {
				continue;
			} else {
				cout << "Invalid name! Please re-insert it." << endl;
				sleep3();
				cout << "\033[A\33[2K\033[A\33[2K\rName: ";
				cin >> name;
				verifyName(name);
			}
		}
		return name[strlen(name)];
	}
    //Create a function to verify the surname
	char verifySurname(char surname[]) {
		for (int i = 0; i < strlen(surname); i++) {
			if (surname[i] >= 'A' && surname[i] <= 'Z') {
				continue;
			} else if (surname[i] >= 'a' && surname[i] <= 'z') {
				continue;
			} else if (surname[i] == ' ') {
				continue;
			} else {
				cout << "Invalid surname! Please re-insert it." << endl;
				sleep3();
				cout << "\033[A\33[2K\033[A\33[2K\rSurname: ";
				cin >> surname;
				verifySurname(surname);
			}
		}
		return surname[strlen(surname)];
	}

	//Create a function to verify the gender
	char verifyGender(char gender[]) {
		if (gender[0] == 'm' or gender[0] == 'M' or gender[0] == 'f' or gender[0] == 'F') {
		} else {
			cout << "Invalid gender! Please re-insert it." << endl;
			cin >> gender;
			verifyGender(gender);
		}
		return gender[strlen(gender)];
	}
	
	//Create a function to 
        
};
int main() {
    InsertDate insertDate;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@ Italian National Insurance Number Generator @@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\nHello I'm your personal Italian National Insurance Number Generator.\nWrite below your data:" << endl;
	insertDate.insertDateFunction();

    return 0;
}
