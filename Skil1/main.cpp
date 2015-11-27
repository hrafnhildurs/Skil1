#include <iostream>
#include <string>
#include <fstream>
#include "person.h"
using namespace std;

const int MAX = 20;

int main()
{
    person human;

    cout << "input the information like this" << endl;
    cout << "name, sex, birth_year, death_year" << endl;
    cin >> human;

    cout << human << endl;

    return 0;
}
