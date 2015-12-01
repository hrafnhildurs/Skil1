#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "person.h"

class Manager
{
public:
    Manager();
    void addPerson();
    vector<string> readFromFile();
    void alphabeticSortAsc(vector<string> cnames);
    void alphabeticSortDes(vector<string> cnames);
    void deleteName(const char doc[], vector<string> tempVec);
    string readSearchWord();
    void search(const char doc[], string letters);
    void DocString (const char doc[], vector<string> stringVec);
private:
    person pers;
};

#endif // MANAGER_H
