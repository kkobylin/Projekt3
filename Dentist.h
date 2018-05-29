#ifndef Dentist_definition
#define Dentist_definition

#include <iostream>
#include "Doctor.h"
using namespace std;


class Dentist : public Doctor
{
    queue <Patient*> que; //kolejka oczekujacych na doktora
    bool is_available; //czy dostepny
    int freetime; //zmienna deklarujaca ile jeszcze jednostek czasu lekarz bedzie zajety lub wolny
    int examcon; //zmienna deklarujaca ile jeszcze czasu beda wykonywane badania

    //protected:
    //enum class doctype{den,ocu,ped};
    //doctype dt=den;
    public:
    Dentist();
    ~Dentist(){};

};

#endif //Dentist_definition
