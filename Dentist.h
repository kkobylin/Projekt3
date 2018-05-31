#ifndef Dentist_definition
#define Dentist_definition

#include <iostream>
#include "Doctor.h"

class Dentist : public Doctor
{
    public:
    Dentist();
    ~Dentist(){};
    int examt(); //czas pojedynczych badan
    int breakt(); //co ile lekarz jest dostepny
    int avat(); //czas na jaki lekarz jest dostepny
};

#endif //Dentist_definition
