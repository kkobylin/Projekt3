#ifndef Pedia_definition
#define Pedia_definition

#include <iostream>
#include "Doctor.h"

class Pedia : public Doctor
{
    public:
    Pedia();
    ~Pedia(){};
    int examt(); //czas pojedynczych badan
    int breakt(); //co ile lekarz jest dostepny
    int avat(); //czas na jaki lekarz jest dostepny
};


#endif //Pedia_definition
