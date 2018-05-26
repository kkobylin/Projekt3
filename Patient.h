#ifndef Patient_definition
#define Patient_definition

#include <iostream>
#include "Doctor.h"
#include "Dentist.h"
using namespace std;

class Doctor;

class Patient
{
    string name; //Imie i nazwisko
    int id; //Identyfikator pacjenta
    bool busy; //czy pacjent w trakcie badania lub w kolejce

    public:
    Patient(int i); //konstruktor klasy
    ~Patient(){}; //destruktor klasy
    visitdoc(Doctor *wsk); //wizyta lekarza
    changedoc(); //zmiana lekarza
    dataact(); //aktualizacja swoich danych
    datacopy(); //kopia karty
    notbusy(); //zmiana stanu pacjenta
    ifbusy(); //czy pacjent zajety

};


#endif //Patient_definition
