#include <iostream>
#include <iomanip>
#include "person.h"
#include <string>
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
    char ans;
    outFile.open("out.txt", ofstream::app);
    if(outFile.fail())
    {
        cout << "   outFile opening failed!!" << endl;
    }
    cout << endl;
    cout << setw(52) << "Is the person alive? (y/n) ";
    cin >> ans;

    if(ans == 'y') {
        cout << "\n";
        cout << setw(31) << "Name: ";
        ins >> ws;
        getline(ins, a.name);
        cout << setw(30) << "Sex: ";
        getline(ins, a.sex);
        cout << setw(37) << "Birth year: ";
        ins >> a.birth_year;
        outFile << setw(a.name.length()) << a.name << setw(16 + (25 - a.name.length())) << a.sex << setw(8) << a.birth_year << setw(14) << endl;
    }
    else if (ans == 'n'){
        cout << endl;
        cout << setw(31) << "Name: ";
        ins >> ws;
        getline(ins, a.name);
        cout << setw(30) << "       Sex: ";
        getline(ins, a.sex);
        cout << setw(37) << "       Birth year: ";
        ins >> a.birth_year;
        cout << setw(37) << "       Death year: ";
        ins >> a.death_year;
        outFile << setw(a.name.length()) << a.name << setw(16 + (25 - a.name.length())) << a.sex << setw(8) << a.birth_year << setw(14) << a.death_year << endl;
    }

    outFile.close();

    return ins;
}
