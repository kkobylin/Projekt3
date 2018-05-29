#ifndef Patient_definition
#define Patient_definition

#include <iostream>
#include "Doctor.h"
#include "IPatient.h"
using namespace std;

//class Doctor;

class Patient : public IPatient
{
    
    string name; //Imie i nazwisko
    int id; //Identyfikator pacjenta
    bool busy; //czy pacjent w trakcie badania lub w kolejce

    public:
    Patient(int i); //konstruktor klasy
    ~Patient(){}; //destruktor klasy
    bool visitdoc(Doctor *wsk); //wizyta lekarza
    void dataact(string newname); //aktualizacja swoich danych
    void datacopy(); //kopia karty
    void notbusy(); //zmiana stanu pacjenta
    bool ifbusy(); //czy pacjent zajety

};


#endif //Patient_definition
