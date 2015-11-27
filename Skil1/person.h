#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;


class person
{
protected:
    string name;
    string sex;
    int birth_year;
    int death_year;
    vector<person>persons;

public:
    person();
    person(string n, string s, int b, int d);
    friend ifstream& operator >> (ifstream& ins, person a);


};

#endif // PERSON_H
