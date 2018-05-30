#include <iostream>
#include "Oculist.h"

Oculist::Oculist()
{
    Doctor::dt=doctype::ocu;
    is_available=true;
    freetime=static_cast<int>(avat());
    examcon=0;
}
