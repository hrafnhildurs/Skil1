#include <iostream>
#include <iomanip>
#include <conio.h>
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
person::person(string n, string s, int b, int d){
    name = n;
    sex = s;
    birth_year = b;
    death_year = d;
}
istream &operator >> (istream& ins, person& a) {

    ofstream outFile;
    outFile.open("out.txt", ofstream::app);
    if(outFile.fail())
    {
        cout << "outFile opening failed!!" << endl;
    }

    cout << "\n\n   Name: ";
    ins >> ws;
    getline(ins, a.name);
    cout << "   Sex: ";
    getline(ins, a.sex);
    cout << "   Birth year: ";
    ins >> a.birth_year;
    cout << "   Death year: ";
    ins >> a.death_year;

    outFile << setw(28) << a.name << setw(14) << a.sex << setw(14) << a.birth_year << setw(14) << a.death_year << ";" << endl;

    outFile.close();

    return ins;
}
ostream &operator << (ostream& outs, const person& a)
{
    outs << "\n   Name: " << a.name << endl;
    outs << "   Sex: " << a.sex << endl;
    outs << "   Birth year: " << a.birth_year << endl;
    outs << "   Death year: " << a.death_year << endl;

    return outs;
}
