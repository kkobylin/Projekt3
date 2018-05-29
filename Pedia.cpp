#include <iostream>
#include "Pedia.h"
using namespace std;


Pedia::Pedia()
{
    Doctor::dt=doctype::ped;
    is_available=true;
    freetime=static_cast<int>(avat());
    examcon=0;
}
