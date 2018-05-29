#include <iostream>
#include <fstream>
#include "Patient.h"
using namespace std;

Patient::Patient(int i)
{
    name="Jan Kowalski";
    id=i;
    busy=false;
}

bool Patient::visitdoc(Doctor *wsk)
{
    busy=true;
    int a;
    if(!wsk)
    {
        throw a;
    }
    else
    {
    if(wsk->patcame(this))
        return true;
    else
        return false;
    }

}

void Patient::notbusy()
{
    busy=false;
}

bool Patient::ifbusy()
{
    return busy;
}

void Patient::dataact(string newname)
{
    name=newname;
}

void Patient::datacopy()
{
    ofstream writ;
    writ.open("results.txt", ios::app);
    writ<<"Patient's data: "<<endl;
    writ<<name<<endl;
    writ.close();
}
