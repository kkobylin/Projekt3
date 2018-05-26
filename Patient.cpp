#include <iostream>
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

Patient::visitdoc(Doctor *wsk)
{

    wsk->patcame();
    busy=true;

}

Patient::notbusy()
{
    busy=false;
}

Patient::ifbusy()
{
    return busy;
}
