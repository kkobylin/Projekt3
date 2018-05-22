#include <iostream>
#include "Dentist.h"
using namespace std;

bool Dentist::is_ava()
{
    if(is_available) return true;
    else return false;
}


Dentist::Dentist()
{
    is_available=true;
    freetime=avat;
    examcon=0;
}

void Dentist::patcame()
{
    if(freetime>=examt && is_available==true)
    {
    is_available=false;
    examcon=examt;
    }
    /*
    else
    {

    }*/
}

void Dentist::iter()
{
    //Jesli examcon =1 to w danej iteracji badanie juz sie skonczylo
    if(examcon==1)
    {
        examcon=0;
        is_available=true;
    }

    if(examcon>1)
        examcon--;

    if(freetime>1)
        freetime--;
    else if (freetime<1)
        freetime++;
    else
    {
        if(is_available)
        {
            is_available=false;
            freetime=-breakt+2;
        }
        else
        {
            is_available=true;
            freetime=avat;
        }
    }
}
