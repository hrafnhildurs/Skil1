#include "person.h"

person::person()
{
   name = "";
   sex = "";
   birth_year = 0;
   death_year = 0;


}
person::person(string n, string s, int b, int d){
    name = n;
    sex = s;
    birth_year = b;
    death_year = d;
}
ifstream& operator >> (ifstream& ins, person a) {

    return ins;
}
