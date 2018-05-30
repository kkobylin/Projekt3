#include <iostream>
#include "Doctor.h"
using namespace std;


bool Doctor::is_ava()
{
    return is_available;
}


bool Doctor::patcame(Patient *p)
{
    //Funkcja zwraca falsz jesli lekarz byl zajety i pacjent zostal ustawiony do kolejki
    if(freetime>=examt() && is_available==true && que.empty())
    {
    is_available=false;
    examcon=examt();
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

void Doctor::iter()
{
    //Jesli examcon =1 to w danej iteracji badanie juz sie skonczylo
    if(examcon==1)
    {
        examcon=0;
        is_available=true;
        que.front()->busy=false;
        que.pop();
    }

    if(examcon>1)
        examcon--;

    if(freetime>1)
    {
        freetime--;
    }
    else if (freetime<1)
        freetime++;
    else
    {
        if(is_available)
        {
            is_available=false;
            freetime=-breakt()+2;
        }
        else
        {
            is_available=true;
            freetime=avat();
        }
    }

    if(!que.empty())
    {
        if(freetime>=examt() && is_available==true)
        {
            is_available=false;
            examcon=examt();
        }
    }
}

void Doctor::toque(Patient *p)
{
    que.push(p);
}

int Doctor::examt()
{
    if(dt==doctype::den)
        return 2;
    else if(dt==doctype::ocu)
        return 1;
    else if(dt==doctype::ped)
        return 2;

}

int Doctor::breakt()
{

    if(dt==doctype::den)
        return 3;
    else if(dt==doctype::ocu)
        return 2;
    else if(dt==doctype::ped)
        return 4;
}

int Doctor::avat()
{
    if(dt==doctype::den)
        return 5;
    else if(dt==doctype::ocu)
        return 7;
    else if(dt==doctype::ped)
        return 4;
}
