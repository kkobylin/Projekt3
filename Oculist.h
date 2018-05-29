#ifndef Oculist_definition
#define Oculist_definition

#include <iostream>
#include "Doctor.h"
using namespace std;


class Oculist : public Doctor
{
    queue <Patient*> que; //kolejka oczekujacych na doktora
    bool is_available; //czy dostepny
    int freetime; //zmienna deklarujaca ile jeszcze jednostek czasu lekarz bedzie zajety lub wolny
    int examcon; //zmienna deklarujaca ile jeszcze czasu beda wykonywane badania
     public:
    Oculist();
    ~Oculist(){};

};


#endif //Oculist_definition
