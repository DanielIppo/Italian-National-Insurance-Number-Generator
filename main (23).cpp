/* Italian National Insurance Number Generator by DanielIppo contribute: Filippo127*/
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
using namespace std;



class Generator{
    public:    
    char name[90];
    char surname[30];
    char gender[2];
    int birth_day;
    int birth_month;
    int birth_year;
    

    void insert_date(){// In this function, the user is asked to insert data
        cout << "Name: ";           cin >> name;
        cout << "Surname: ";        cin >> surname;
        cout << "Gender: ";         cin >> gender;
        cout << "Birth Day: ";      cin >> birth_day;
        cout << "Birth Month: ";    cin >> birth_month;
        cout << "Birth Year: ";     cin >> birth_year;
    }
    void Verify_Name(){
        cout << " prova";
    }
};
int main (){
    Generator generator;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "@@@@ Italian National Insurance Number Generator @@@@" << endl;
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
    cout << "\nHello I'm your personal Italian National Insurance Number Generator.\nWrite below your data:" << endl;
    generator.insert_date();
    generator.Verify_Name();

    return 0;
}