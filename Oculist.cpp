#include <iostream>
#include "Oculist.h"

Oculist::Oculist()
{
    is_available=true;
    freetime=static_cast<int>(avat());
    examcon=0;
}

int Oculist::examt()
{
    return 1;

}

int Oculist::breakt()
{
    return 2;
}

int Oculist::avat()
{
    return 7;
}
