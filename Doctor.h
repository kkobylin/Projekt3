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
    enum class doctype{den,ocu,ped};
    doctype dt; //zmienna deklarujaca ktore specyficzne wartosci ma zwracac funkcja

    public:
    int examt(); //czas pojedynczych badan
    int breakt(); //co ile lekarz jest dostepny
    int avat(); //czas na jaki lekarz jest dostepny
    bool is_ava(); //Czy lekarz dostepny
    void iter(); //funkcja wykonujaca sie po kazdej iteracji
    bool patcame(Patient *p); //funkcja wykonujaca sie gdy przyjdzie pacjent
    virtual ~Doctor(){};

};


#endif //Doctor_definition
