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
    char ans;
    int number;
    do
    {
        cout << "\n";
        cout << "   =========================" << endl;
        cout << "   1.  Input new person" << endl;
        cout << "   2.  View list of persons" << endl;
        cout << "   3.  Eitthvad1" << endl;
        cout << "   4.  Eitthvad2" << endl;
        cout << "   5.  Exit " << endl;
        cout << "   =========================" << endl;
        cout << "\n";
        cout << "   Enter your selection: ";
        cin >> number;
        switch(number)
        {
            case 1:
                cin >> human;
                cout << human << endl;
            break;
            case 2:
                DocString("out.txt", a);
            break;
            case 5:
                return 0;
            break;
        }
        cout << "Do you want to continue (y/n)?";
        cin >> ans;
    }while(ans == 'y');

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
