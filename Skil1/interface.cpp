#include "interface.h"


void Interface::selection() {
    person human;
    vector <string> a;


    int number;
    do
    {
        cout << "\n";
        cout << setw(50) << "-------------------------" << endl;
        cout << setw(51) <<" |    Famous programmers   |" << endl;
        cout << setw(50) << "-------------------------" << endl;
        cout << "\n\n";
        cout << setw(40) << "Menu" << endl;
        cout << "   ======================================================================" << endl;
        cout << setw(45) << "1.  Input new person" << endl;
        cout << setw(49) << "2.  View list of persons" << endl;
        cout << setw(42) << "3.  Edit database" << endl;
        cout << setw(35) << "4.  Search" << endl;
        cout << setw(34) << "5.  Exit " << endl;
        cout << "   ======================================================================" << endl;
        cout << "\n";
        cout << setw(47) << "Enter your selection: ";
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
                editMenu("out.txt");
                break;
            case 4:
                search("out.txt");
                break;
            case 5:
                return;
                break;
        }
    }while(true);
}

void Interface::sortMenu() {
    int number;
    do
    {
        cout << "\n\n";
        cout << setw(44) << "Sorting menu" << endl;
        cout << "   ======================================================================" << endl;
        cout << setw(51) << "1.  Ascending alphabetic sort" << endl;
        cout << setw(52) << "2.  Descending alphabetic sort" << endl;
        cout << setw(41) << "3.  Exit sort menu " << endl;
        cout << "   ======================================================================" << endl;
        cout << "\n";
        cout << setw(47) << "Enter your selection: ";
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
    }while(number < 3);
    cout << "\n\n";
}

void Interface::DocString (const char doc[], std::vector<string> stringVec)
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


void Interface::alphabeticSortAsc() {
    string word;
    vector<string> cnames;

    ifstream in("out.txt");
    if(!in.is_open())
        cout << "Unable to open file\n";


    Database();
    while(getline(in, word))
    cnames.push_back(word);

    sort(cnames.begin(), cnames.end());

    for (size_t i = 0; i < cnames.size(); i++)
        cout << "   " << cnames[i] << '\n';
}

void Interface::alphabeticSortDes() {
    string word;
    vector<string> cnames;

    ifstream in("out.txt");
    if(!in.is_open())
        cout << "   Unable to open file\n";

    Database();
    while(getline(in, word))
        cnames.push_back(word);

    sort(cnames.rbegin(), cnames.rend());

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
}
void Interface::editMenu(const char doc[]){
    int number;
    do
    {
        cout << "\n\n";
        cout << setw(44) << "Edit menu" << endl;
        cout << "   ======================================================================" << endl;
        cout << setw(54) << "1.  Delete name from database" << endl;
        cout << setw(50) << "2.  Edit name in database" << endl;
        cout << setw(44) << "3.  Exit edit menu " << endl;
        cout << "   ======================================================================" << endl;
        cout << "\n";
        cout << setw(47) << "Enter your selection: ";
        cin >> number;
        switch(number)
        {
        case 1:
            deleteName(doc);
            break;
        case 2:
            //changeName(doc);
            break;
        case 3:
            break;
        }
    }while(number < 3);
    cout << "\n\n";
}

void Interface::deleteName(const char doc[]){
    vector<string>tempVec;
    string temp;

    ifstream file(doc);

    while(!file.eof())
    {                               //reading the file into a temp vector
        getline(file, temp);
        tempVec.push_back(temp);
    }
    file.close();

    string name;

    cout << "Enter the name you want to delete: ";
    cin >> name;

    for(unsigned int i = 0; i < tempVec.size(); ++i)
    {
        int found = 0;
        if(tempVec[i].substr(0, name.length()) == name)  //searching for the name in the vector
        {
            tempVec.erase(tempVec.begin() + i);           //deleting the name from the vector
            cout << "Name has been erased!"<< endl;
            found++;
        }
    }
    vector<string>::iterator empty = remove_if(tempVec.begin(), tempVec.end(),mem_fun_ref(&string::empty));
    tempVec.erase(empty, tempVec.end()); // remove empty lines from vector

    ofstream outs(doc);             //printing a new list from the vec to the file
                                                            //were the name has been deleted
    for(vector<string>::const_iterator newlist = tempVec.begin(); newlist != tempVec.end(); newlist++)
    {
        outs << *newlist << endl;
    }
    outs.close();
}


void Interface::Database()
{
    cout << "\n";
    cout << "   ----------------------------------------------------------------------" << endl;
    cout << setw(40) << "Database" << endl;
    cout << "   ----------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(10) << "Name" << setw(33) << "Sex" << setw(12) << "Birth year" << setw(14) << "Death year" << endl;
    cout << "   ======================================================================" << endl;
}

void Interface::searchResults()
{
    cout << "\n";
    cout << "   ----------------------------------------------------------------------" << endl;
    cout << setw(40) << "Search results" << endl;
    cout << "   ----------------------------------------------------------------------" << endl;
    cout << "\n";
    cout << setw(10) << "Name" << setw(33) << "Sex" << setw(12) << "Birth year" << setw(14) << "Death year" << endl;
    cout << "   ======================================================================" << endl;
}
