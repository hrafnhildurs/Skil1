#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "person.h"
using namespace std;

const int MAX = 20;

void DocString (const char doc[], vector <string> stringVec);

int main()
{
    person human;
    string names[MAX];
    string x;
    vector <string> a;
    int number;

    cout << "1: Input new person" << "\n2: View list of persons" << endl;
    cout << "Use numbers to navigate" << endl;
    cin >> number;
    switch(number)
    {
        case 1:
            cout << "input the information like this" << endl;
            cout << "name, sex, birth_year, death_year" << endl;
            cin >> human;

            cout << human << endl;
        break;
        case 2:
            DocString("out.txt", a);
        break;
    }

    return 0;
}

void DocString (const char doc[], vector <string> stringVec)
{
    ifstream document;
    document.open(doc);
    string temp;

    while(getline(document, temp, ';'))
    {
        cout << temp;
        stringVec.push_back(temp);
    }

    document.close();
}
