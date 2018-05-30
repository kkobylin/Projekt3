#include <iostream>
#include "Dentist.h"

Dentist::Dentist()
{
    Doctor::dt=doctype::den;
    is_available=true;
    freetime=static_cast<int>(avat());
    examcon=0;
}
