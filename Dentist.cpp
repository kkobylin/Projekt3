#include <iostream>
#include "Dentist.h"
//#include "Doctor.h"
using namespace std;

Dentist::Dentist()
{
    Doctor::dt=doctype::den;
    is_available=true;
    freetime=static_cast<int>(avat());
    examcon=0;
}
