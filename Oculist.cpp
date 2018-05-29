#include <iostream>
#include "Oculist.h"
using namespace std;

Oculist::Oculist()
{
    Doctor::dt=doctype::ocu;
    is_available=true;
    freetime=static_cast<int>(avat());
    examcon=0;
}
