#ifndef Patient_definition
#define Patient_definition

#include <iostream>
#include "Doctor.h"
#include "IPatient.h"

class Patient : public IPatient
{
    friend class Doctor;

    std::string name; //Imie i nazwisko
    int id; //Identyfikator pacjenta
    bool busy; //czy pacjent w trakcie badania lub w kolejce

    public:
    Patient(int i);
    ~Patient(){};
    bool visitdoc(Doctor *wsk); //wizyta lekarza
    bool docapp(Doctor *wsk); //zapis do lekarza
    void dataact(std::string newname); //aktualizacja swoich danych
    void datacopy(); //kopia karty
  //  void notbusy(); //zmiana stanu pacjenta
    bool ifbusy(); //czy pacjent zajety

};


#endif //Patient_definition
