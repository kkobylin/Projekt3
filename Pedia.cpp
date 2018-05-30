#include <iostream>
#include "Pedia.h"

Pedia::Pedia()
{
    Doctor::dt=doctype::ped;
    is_available=true;
    freetime=static_cast<int>(avat());
    examcon=0;
}
