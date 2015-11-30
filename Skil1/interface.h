#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "person.h"


class Interface
{
public:
    void selection();
private:
    void DocString (const char doc[], std::vector<std::string> stringVec);
    void alphabeticSortAsc();
    void alphabeticSortDes();
    void search(const char doc[]);
    void sortMenu();
    void Database();
};

#endif // INTERFACE_H
