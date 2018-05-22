#ifndef Dentist_definition
#define Dentist_definition

#include <iostream>
#include "Doctor.h"
using namespace std;


class Dentist : public Doctor
{
    public:
    const int examt=2; //czas pojedynczych badan
    const int breakt=3; //co ile lekarz jest dostepny
    const int avat=5; //czas na jaki lekarz jest dostepny
    bool is_available; //czy dostepny
    int freetime; //zmienna deklarujaca ile jeszcze jednostek czasu lekarz bedzie zajety lub wolny
    int examcon; //zmienna deklarujaca ile jeszcze czasu beda wykonywane badania


    bool is_ava(); //Czy lekarz dostepny
    void iter(); //funkcja wykonujaca sie po kazdej iteracji
    void patcame(); //funkcja wykonujaca sie gdy przyjdzie pacjent
    Dentist(); //konstruktor klasy
    ~Dentist(){}; //destruktor klasy

};


#endif //Dentist_definition
