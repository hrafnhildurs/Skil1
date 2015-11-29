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
void sort ();

int main()
{
    selection();


    return 0;
}
void selection() {
    person human;
    string names[MAX];
    vector <string> a;
    string search, line, x;
    ifstream inFile;
    char ans;
    int number;
    do
    {
        cout << "\n";
        cout << "   =========================" << endl;
        cout << "   1.  Input new person" << endl;
        cout << "   2.  View list of persons" << endl;
        cout << "   3.  Search" << endl;
        cout << "   4.  Sort alphabetically" << endl;
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
                        }
                      else
                          cout << search << " not found! " << search << " is not in our database" << endl;

                  }
            break;
            case 4:
            {
                    sort();
            break;
            }
            case 5:
                return;
            break;
        }
        cout << "Do you want to continue (y/n)?";
        cin >> ans;
    }while(ans == 'y');
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
void sort () {
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
