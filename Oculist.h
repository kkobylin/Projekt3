#ifndef Oculist_definition
#define Oculist_definition

#include <iostream>
#include <queue>
#include "Doctor.h"
#include "Patient.h"
using namespace std;


class Oculist : public Doctor
{
    queue <Patient> que; //kolejka oczekujacych na doktora
    const int examt=1; //czas pojedynczych badan
    const int breakt=2; //co ile lekarz jest dostepny
    const int avat=7; //czas na jaki lekarz jest dostepny
    bool is_available; //czy dostepny
    int freetime; //zmienna deklarujaca ile jeszcze jednostek czasu lekarz bedzie zajety lub wolny
    int examcon; //zmienna deklarujaca ile jeszcze czasu beda wykonywane badania

    public:
    bool is_ava(); //Czy lekarz dostepny
    void iter(); //funkcja wykonujaca sie po kazdej iteracji
    bool patcame(Patient p); //funkcja wykonujaca sie gdy przyjdzie pacjent
    Oculist();
    ~Oculist(){};

};


#endif //Oculist_definition
