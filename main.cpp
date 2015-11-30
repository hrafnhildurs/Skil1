#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include "person.h"
using namespace std;

const int MAX = 20;

void DocString (const char doc[], vector <string> stringVec);
void selection();
void alphabeticSortAsc();
void alphabeticSortDes();
void sortMenu();
void search(const char doc[]);
void Database();

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
        cout << "   4.  Exit " << endl;
        cout << "   =========================" << endl;
        cout << "\n";
        cout << "   Enter your selection: ";
        cin >> number;
        cout << "\n";
        switch(number)
        {
            case 1:
                cin >> human;
                cout << human << endl;
            break;
            case 2:
                DocString("out.txt", a);
                sortMenu();
            break;
            case 3:
                search("out.txt");
                break;
            case 4:
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
    Database();
    while(getline(document, temp, ';'))
    {
        cout << temp;
        stringVec.push_back(temp);
    }

    document.close();
}
void sortMenu() {
    do
    {
        int number;
        cout << "\n";
        cout << "   ==============================" << endl;
        cout << "   1.  Ascending alphabetic sort" << endl;
        cout << "   2.  Descending alphabetic sort" << endl;
        cout << "   3.  Exit sort menu " << endl;
        cout << "   ==============================" << endl;
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
    }while(true);
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
        Database();
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
        Database();
        while(getline(in, word))
                cnames.push_back(word);

        sort(cnames.rbegin(), cnames.rend());

        // Loop to print names
        for (size_t i = 0; i < cnames.size(); i++)
            cout << cnames[i] << '\n';
}
void search(const char doc[]) {

    ifstream in(doc);
    string letters;
    string line;

         cout << "   Enter search word: ";
         cin >> letters;

         if(in.is_open())
         {
            while (getline(in, line)) {
                 if (line.find(letters) != string::npos) {
                     cout << line << endl;
                 }
             }
         }


    /*
     * ifstream inFile;
     string search;
     inFile.open(doc);

    if(!inFile){
    cout << "Unable to open file" << endl;
    exit(1);
    }
    cout << "Enter name to search for: ";
    cin >>search;

    bool nameFound = true;
    while(!inFile.eof())
        {
            string temp = "";
            getline(inFile,temp);
            for(unsigned int i=0; i < search.size();i++)
            {
                if(temp[i] == search[i])
                    nameFound = true;
                else
                {
                    nameFound = false;
                    break;
                }
            }

            if(nameFound)
            {
                cout << "Name found!" << endl;
                cout << search << " ";
                for(unsigned int i = search.size()+1;i < temp.size(); i++)
                    cout << temp[i];
                break;
            }

        }

        if(inFile.eof()&&(!nameFound))
        {
            cout << "Name not found!" << endl;
        }*/

}
void Database()
{
    cout << "   ---------------------------------------------------------------------" << endl;
    cout << setw(40) << "Database" << endl;
    cout << "   ---------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(28) << "Name" << setw(14) << "Sex" << setw(14) << "Birth year" << setw(14) << "Death year" << endl;
    cout << "   =====================================================================" << endl;
}
