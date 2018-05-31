#include <iostream>
#include "Pedia.h"

Pedia::Pedia()
{
    is_available=true;
    freetime=static_cast<int>(avat());
    examcon=0;
}

int Pedia::examt()
{
    return 2;

}

int Pedia::breakt()
{
    return 4;
}

int Pedia::avat()
{
    return 4;
}
