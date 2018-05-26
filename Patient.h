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
    void visitdoc(Doctor *wsk); //wizyta lekarza
    //void changedoc(); //zmiana lekarza
    void dataact(string newname); //aktualizacja swoich danych
    void datacopy(); //kopia karty
    void notbusy(); //zmiana stanu pacjenta
    bool ifbusy(); //czy pacjent zajety

};


#endif //Patient_definition
