#include <iostream>
#include <fstream>
#include "Patient.h"
#include "Dentist.h"
#include "Oculist.h"
#include "Pedia.h"
#include "Doctor.h"
using namespace std;

Patient::Patient(int i)
{
    name="Jan Kowalski";
    id=i;
    busy=false;
}

void Patient::visitdoc(Doctor *wsk)
{

    wsk->patcame();
    busy=true;

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
    ofstream write("Results.txt");
    write<<"Patient's data: "<<endl;
    write<<name<<endl;
}
