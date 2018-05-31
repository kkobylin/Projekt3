#include <iostream>
#include "Dentist.h"

Dentist::Dentist()
{
    is_available=true;
    freetime=static_cast<int>(avat());
    examcon=0;
}

int Dentist::examt()
{
    return 2;

}

int Dentist::breakt()
{
    return 3;
}

int Dentist::avat()
{
    return 5;
}
