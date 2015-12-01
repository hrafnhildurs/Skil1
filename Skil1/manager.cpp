#include "manager.h"

Manager::Manager() {}

// Calls the overloaded cin (>>) operator in Person class to insert into database
void Manager::addPerson() {
    cin >> pers;
}

// Reads from database file (out.txt) into a vector
void Manager::DocString (const char doc[], vector<string> stringVec)
{
    ifstream document;
    document.open(doc);
    string temp;

    while(getline(document, temp, ';'))
    {
        stringVec.push_back(temp);
    }

    document.close();
}

// Helper function that returns a vector from database file
vector<string> Manager::readFromFile() {
    string word;
    vector<string> cnames;

    ifstream in("out.txt");
    if(!in.is_open())
        cout << "   Unable to open file\n";

    while(getline(in, word))
    cnames.push_back(word);
    return cnames;
}

// Prints the list ordered by time inserted
void Manager::asInserted(vector<string> cnames) {

    for (size_t i = 0; i < cnames.size(); i++)
        cout << "   " << cnames[i] << '\n';

}

// Ascending sorting function
void Manager::alphabeticSortAsc(vector<string> cnames) {
    sort(cnames.begin(), cnames.end());

    for (size_t i = 0; i < cnames.size(); i++)
        cout << "   " << cnames[i] << '\n';
}

// Descending sorting function
void Manager::alphabeticSortDes(vector<string> cnames) {
    sort(cnames.rbegin(), cnames.rend());

    for (size_t i = 0; i < cnames.size(); i++)
        cout << "   " << cnames[i] << '\n';
}

// Helper function that reads search input from user
string Manager::readSearchWord() {
    string searchWord;
    cout << setw(52) << "Enter search word: ";
    cin >> searchWord;
    return searchWord;
}

// Search function
void Manager::search(const char doc[], string letters) {
    ifstream in(doc);
    string line;

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
}

// Delete name from database
void Manager::deleteName(const char doc[], vector<string> tempVec){
    string name;
    bool found = false;

    cout << "\n";
    cout << setw(68) << "Enter the name you want to delete: ";
    cin >> name;

    for(unsigned int i = 0; i < tempVec.size(); ++i)
    {
        if(tempVec[i].substr(0, name.length()) == name)  //searching for the name in the vector
        {
            found = true;
            tempVec.erase(tempVec.begin() + i);           //deleting the name from the vector
            cout << setw(54) << "Name has been erased!"<< endl;
            i = 0;                                  //reseting the search
        }
    }

    if(!found)
        cout << setw(60) << "Name not found in database." << endl;


    ofstream outs(doc/*, ios::out | ios::trunc*/);             //printing a new list from the vec to the file
                                                            //were the name has benn deleted
    for(vector<string>::const_iterator newlist = tempVec.begin(); newlist != tempVec.end(); newlist++)
    {
        outs << *newlist << endl;
    }
    outs.close();
}
