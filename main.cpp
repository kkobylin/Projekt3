#include <iostream>
#include "Simulation.h"
#include "Doctor.h"
#include "Dentist.h"
#include "Oculist.h"
using namespace std;

int main()
{
    Simulation("dane.txt");
    /*
    Doctor *wsk;
    Dentist den;
    Oculist ocu;
    den.is_available=false;
    wsk=&den;
    cout<<wsk->is_ava();
    wsk=&ocu;
    cout<<wsk->is_ava();
    */
}
