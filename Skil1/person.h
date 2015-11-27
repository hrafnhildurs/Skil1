#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <fstream>
using namespace std;


class person
{
protected:
    string name;
    string sex;
    int birth_year;
    int death_year;
public:
    person();
    person(string n, string s, int b, int d);
    friend ifstream& operator >> (ifstream& ins, person a);

};

#endif // PERSON_H
