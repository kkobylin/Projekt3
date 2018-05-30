#include <iostream>
#include <fstream>
#include "Patient.h"

Patient::Patient(int i)
{
    name="Jan Kowalski";
    id=i;
    busy=false;
}

bool Patient::visitdoc(Doctor *wsk)
{
    busy=true;
    if(!wsk)
    {
        int a;
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

bool Patient::docapp(Doctor *wsk)
{
    busy=true;
    if(!wsk)
    {
        int a;
        throw a;
    }
    else
    {
    wsk->toque(this);
    }

}
/*
void Patient::notbusy()
{
    busy=false;
}
*/
bool Patient::ifbusy()
{
    return busy;
}

void Patient::dataact(std::string newname)
{
    name=newname;
}

void Patient::datacopy()
{
    std::ofstream writ;
    writ.open("results.txt", std::ios::app);
    writ<<"Patient's data: "<<std::endl;
    writ<<name<<std::endl;
    writ<<"ID: "<<id<<std::endl;
    writ.close();
}

