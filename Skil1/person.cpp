#include <iostream>
#include "person.h"
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
    outFile.open("persons.txt", ofstream::app);
    if(outFile.fail())
    {
        cout << "outFile opening failed!!" << endl;
    }

    ins >> a.name >> a.sex >> a.birth_year >> a.death_year;
    outFile << a.name << " " << a.sex << " " << a.birth_year << " " << a.death_year << ";" << endl;

    outFile.close();

    return ins;
}
ostream &operator << (ostream& outs, const person& a)
{
    outs << "Name: " << a.name << endl;
    outs << "Sex: " << a.sex << endl;
    outs << "Birth year: " << a.birth_year << endl;
    outs << "Death year: " << a.death_year << endl;

    return outs;
}
