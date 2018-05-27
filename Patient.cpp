#include <iostream>
#include <fstream>
#include "Patient.h"
//#include "Dentist.h"
//#include "Oculist.h"
//#include "Pedia.h"
//#include "Doctor.h"
using namespace std;

Patient::Patient(int i)
{
    name="Jan Kowalski";
    id=i;
    busy=false;
    //cout<<"Konstruktor pacjenta";
}

bool Patient::visitdoc(Doctor *wsk)
{
    busy=true;
    //cout<<"zmiana busy pacjenta na true"<<endl;

    if(wsk->patcame(*this))
        return true;
    else
        return false;

}

void Patient::notbusy()
{
    busy=false;
    //cout<<"zmiana busy pacjenta na false"<<endl;
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
   // writ.seekp( 0, std::ios_base::end );
    writ<<"Patient's data: "<<endl;
    writ<<name<<endl;
    //writ.close();
}
