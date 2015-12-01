#ifndef INTERFACE_H
#define INTERFACE_H
#include "manager.h"
using namespace std;

class Interface
{
public:
    void start();
private:
    Manager manager;
    char indexSwitch();
    void addPerson();
    void sortMenu();
    char sortSwitch();
    void sortAsc();
    void sortDes();
    void asInserted();
    void databaseHeader();
    void searchHeader();
    void search();
    void deletePerson();
};

#endif // INTERFACE_H
