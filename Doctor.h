#ifndef Doctor_definition
#define Doctor_definition

#include <iostream>
#include "IDoctor.h"
#include "Patient.h"
#include <queue>


class Doctor : public IDoctor
{
    protected:
    std::queue <Patient*> que; //kolejka oczekujacych na doktora
    bool is_available; //czy dostepny
    int freetime; //zmienna deklarujaca ile jeszcze jednostek czasu lekarz bedzie zajety lub wolny
    int examcon; //zmienna deklarujaca ile jeszcze czasu beda wykonywane badania

    public:
    virtual int examt()=0; //czas pojedynczych badan
    virtual int breakt()=0; //co ile lekarz jest dostepny
    virtual int avat()=0; //czas na jaki lekarz jest dostepny
    bool is_ava(); //Czy lekarz dostepny
    void iter(); //funkcja wykonujaca sie po kazdej iteracji
    bool patcame(Patient *p); //funkcja wykonujaca sie gdy przyjdzie pacjent
    void toque(Patient *p); //pacjent zapisuje sie do lekarza
    virtual ~Doctor(){};

};


#endif //Doctor_definition
