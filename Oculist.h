#ifndef Oculist_definition
#define Oculist_definition

#include <iostream>
#include "Doctor.h"

class Oculist : public Doctor
{
    public:
    Oculist();
    ~Oculist(){};
    int examt(); //czas pojedynczych badan
    int breakt(); //co ile lekarz jest dostepny
    int avat(); //czas na jaki lekarz jest dostepny
};


#endif //Oculist_definition
