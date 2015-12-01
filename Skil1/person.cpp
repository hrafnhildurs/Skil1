#include <iostream>
#include <iomanip>
#include "person.h"
#include <string>
#include <time.h>
#include <ctime>
#include <limits>

using namespace std;

person::person()
{
   name = "";
   sex = "";
   birth_year = 0;
   death_year = 0;
}
person::person(string& n, string& s, int& b, int& d){
    name = n;
    sex = s;
    birth_year = b;
    death_year = d;
}
person::person(string& n, string& s, int& b) {
    name = n;
    sex = s;
    birth_year = b;
}

istream &operator >> (istream& ins, person& a) {

    ofstream outFile;
    char date[9];
    _strdate(date);
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);
    char ans;
    outFile.open("out.txt", ofstream::app);
    if(outFile.fail())
    {
        cout << "   outFile opening failed!!" << endl;
    }
    cout << endl;
    cout << setw(60) << "Is the person alive? (y/n) ";
    cin >> ans;

    if(ans == 'y') {
        cout << "\n";
        cout << setw(39) << "Name: ";
        ins >> ws;
        getline(ins, a.name);
        cout << setw(38) << "Sex: ";
        getline(ins, a.sex);
        cout << setw(45) << "Birth year: ";
        ins >> a.birth_year;
        while ( !( ins >> a.birth_year ) ) {
          cin.clear();
          cin.ignore( 256, '\n' );
          cout << setw(61) << "Please insert a valid year: ";
        }
        outFile << setw(a.name.length()) << a.name << setw(14 + (25 - a.name.length())) << a.sex << setw(9) << a.birth_year << setw(39) << asctime(timeinfo) << endl;
    }
    else if (ans == 'n'){
        cout << endl;
        cout << setw(39) << "Name: ";
        ins >> ws;
        getline(ins, a.name);
        cout << setw(38) << "Sex: ";
        getline(ins, a.sex);
        cout << setw(45) << "Birth year: ";
        ins >> a.birth_year;
        while ( !( ins >> a.birth_year ) ) {
          cin.clear();
          cin.ignore( 256, '\n' );
          cout << setw(61) << "Please insert a valid year: ";
        }
        cout << setw(45) << "Death year: ";
        ins >> a.death_year;
        while ( !( ins >> a.birth_year ) ) {
          cin.clear();
          cin.ignore( 256, '\n' );
          cout << setw(61) << "Please insert a valid year: ";
        }
        outFile << setw(a.name.length()) << a.name << setw(14 + (25 - a.name.length())) << a.sex << setw(9) << a.birth_year << setw(11) << a.death_year << setw(28) << asctime(timeinfo) << endl;
    }

    outFile.close();

    return ins;
}
