#ifndef Oculist_definition
#define Oculist_definition

#include <iostream>
#include "Dentist.h"
using namespace std;


class Oculist : public Doctor
{
    public:
    const int examt=1; //czas pojedynczych badan
    const int breakt=2; ////co ile lekarz jest dostepny
    const int avat=7; //czas na jaki lekarz jest dostepny
    bool is_available; //czy dostepny
    int freetime; //zmienna deklarujaca ile jeszcze jednostek czasu lekarz bedzie zajety lub wolny
    int examcon; //zmienna deklarujaca ile jeszcze czasu beda wykonywane badania

    bool is_ava(); //Czy lekarz dostepny
    void iter(); //funkcja wykonujaca sie po kazdej iteracji
    void patcame(); //funkcja wykonujaca sie gdy przyjdzie pacjent
    Oculist();
    ~Oculist(){};

};


#endif //Oculist_definition
