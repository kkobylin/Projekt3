#ifndef Pedia_definition
#define Pedia_definition

#include <iostream>
#include "Doctor.h"
using namespace std;


class Pedia : public Doctor
{
    const int examt=2; //czas pojedynczych badan
    const int breakt=4; //co ile lekarz jest dostepny
    const int avat=4; //czas na jaki lekarz jest dostepny
    bool is_available; //czy dostepny
    int freetime; //zmienna deklarujaca ile jeszcze jednostek czasu lekarz bedzie zajety lub wolny
    int examcon; //zmienna deklarujaca ile jeszcze czasu beda wykonywane badania

    public:
    bool is_ava(); //Czy lekarz dostepny
    void iter(); //funkcja wykonujaca sie po kazdej iteracji
    void patcame(); //funkcja wykonujaca sie gdy przyjdzie pacjent
    Pedia(); //konstruktor klasy
    ~Pedia(){}; //destruktor klasy

};


#endif //Pedia_definition
