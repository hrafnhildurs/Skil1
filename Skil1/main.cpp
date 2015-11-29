#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "person.h"
using namespace std;

const int MAX = 20;

void DocString (const char doc[], vector <string> stringVec);
void selection();
void alphabeticSortAsc();
void alphabeticSortDes();
void sortMenu();
void search();

int main()
{
    selection();


    return 0;
}
void selection() {
    person human;
    vector <string> a;

    int number;
    do
    {
        cout << "\n";
        cout << "   =========================" << endl;
        cout << "   1.  Input new person" << endl;
        cout << "   2.  View list of persons" << endl;
        cout << "   3.  Search" << endl;
        cout << "   4.  Sort list" << endl;
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
            case 3:
                search();
                break;
            case 4:
                sortMenu();
                break;

            case 5:
                return;
            break;
        }
    }while(true);
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
void sortMenu() {
    int number;
    cout << "\n";
    cout << "   =========================" << endl;
    cout << "   1.  Ascending alphabetic sort" << endl;
    cout << "   2.  Descending alphabetic sort" << endl;
    cout << "   3.  Exit sort menu " << endl;
    cout << "   =========================" << endl;
    cout << "\n";
    cout << "   Enter your selection: ";
    cin >> number;
    switch(number)
    {
    case 1:
        alphabeticSortAsc();
        break;
    case 2:
        alphabeticSortDes();
        break;
    case 3:
        selection();
        break;
    }
}

void alphabeticSortAsc() {
    string word;
    vector<string> cnames;
    // Empty vector holding all names from file


        // Read names from file LineUp.txt
        ifstream in("out.txt");
        if(!in.is_open())
            cout << "Unable to open file\n";

        // this is wrong, by the way: while(in.good()){

        while(getline(in, word))
                cnames.push_back(word);

        sort(cnames.begin(), cnames.end());

        // Loop to print names
        for (size_t i = 0; i < cnames.size(); i++)
            cout << cnames[i] << '\n';
}
void alphabeticSortDes() {
    string word;
    vector<string> cnames;
    // Empty vector holding all names from file


        // Read names from file LineUp.txt
        ifstream in("out.txt");
        if(!in.is_open())
            cout << "Unable to open file\n";

        // this is wrong, by the way: while(in.good()){

        while(getline(in, word))
                cnames.push_back(word);

        sort(cnames.rbegin(), cnames.rend());

        // Loop to print names
        for (size_t i = 0; i < cnames.size(); i++)
            cout << cnames[i] << '\n';
}
void search() {
    ifstream inFile;
    string search, line;

    inFile.open("out.txt");

    if(!inFile){
    cout << "Unable to open file" << endl;
    exit(1);
    }
    cout << "Enter name to search for: ";
    cin >>search;


    size_t pos;
    while(inFile.good())
      {
          getline(inFile,line); // get line from file
          pos=line.find(search); // search
          if(pos!=string::npos) // string::npos is returned if string is not found
            {

                cout << search << " found! " << search << " is in our database" << endl;
                break;
            }
          else
              cout << search << " not found! " << search << " is not in our database" << endl;
                break;

      }
}
