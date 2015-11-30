#include "interface.h"

void Interface::selection() {
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
        switch(number)
        {
            case 1:
                cin >> human;
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

void Interface::sortMenu() {
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
        break;
    }
}

void Interface::DocString (const char doc[], std::vector<string> stringVec)
{
    ifstream document;
    document.open(doc);
    string temp;

    while(getline(document, temp, ';'))
    {
        //cout << "   " << temp;
        stringVec.push_back(temp);
    }

    document.close();
}


void Interface::alphabeticSortAsc() {
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
            cout << "   " << cnames[i] << '\n';
}
void Interface::alphabeticSortDes() {
    string word;
    vector<string> cnames;
    // Empty vector holding all names from file


        // Read names from file LineUp.txt
        ifstream in("out.txt");
        if(!in.is_open())
            cout << "   Unable to open file\n";

        // this is wrong, by the way: while(in.good()){
        Database();
        while(getline(in, word))
                cnames.push_back(word);

        sort(cnames.rbegin(), cnames.rend());

        // Loop to print names
        for (size_t i = 0; i < cnames.size(); i++)
            cout << "   " << cnames[i] << '\n';
}
void Interface::search(const char doc[]) {

    ifstream in(doc);
    string letters;
    string line;

    cout << "   Enter search word: ";
                cin >> letters;
    searchResults();
    if(in.is_open())
    {
        int found = 0;
        cout << "\n";
        while (getline(in, line)) {
        if (line.find(letters) != string::npos) {
            cout << "   " << line << endl;
            found++;
        }
        }
        if (found == 0)
           cout << "   " << letters << " not found" << endl;
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
void Interface::Database()
{
    cout << "   ---------------------------------------------------------------------" << endl;
    cout << setw(40) << "Database" << endl;
    cout << "   ---------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(10) << "Name" << setw(33) << "Sex" << setw(14) << "Birth year" << setw(14) << "Death year" << endl;
    cout << "   =====================================================================" << endl;
}

void Interface::searchResults()
{
    cout << "   ---------------------------------------------------------------------" << endl;
    cout << setw(40) << "Search results" << endl;
    cout << "   ---------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(10) << "Name" << setw(33) << "Sex" << setw(14) << "Birth year" << setw(14) << "Death year" << endl;
    cout << "   =====================================================================" << endl;
}
