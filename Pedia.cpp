#include <iostream>
#include "Pedia.h"
using namespace std;

bool Pedia::is_ava()
{
    return is_available;
}


Pedia::Pedia()
{
    is_available=true;
    freetime=avat;
    examcon=0;
}

bool Pedia::patcame(Patient p)
{
    //Funkcja zwraca falsz jesli lekarz byl zajety i pacjent zostal ustawiony do kolejki
    if(freetime>=examt && is_available==true && que.empty())
    {
    is_available=false;
    examcon=examt;
    que.push(p);
    return true;
    }
    //Jesli lekarz nie moze przyjac
    else
    {
        que.push(p);
        return false;
    }
}

void Pedia::iter()
{
    //Jesli examcon =1 to w danej iteracji badanie juz sie skonczylo
    if(examcon==1)
    {
        examcon=0;
        is_available=true;
        que.front().notbusy();
        que.pop();
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
    if(!que.empty())
    {
        if(freetime>=examt && is_available==true)
        {
            is_available=false;
            examcon=examt;
        }
    }
}
