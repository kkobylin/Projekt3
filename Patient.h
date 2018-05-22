#ifndef Patient_definition
#define Patient_definition

#include <iostream>
using namespace std;


class Patient
{
    string name; //Imie i nazwisko
    int id; //Identyfikator pacjenta
    bool examdur; //czy pacjent w trakcie badania

    public:
    Patient(); //konstruktor klasy
    ~Patient(){}; //destruktor klasy
    visitdoc(); //wizyta lekarza
    changedoc(); //zmiana lekarza
    dataact(); //aktualizacja swoich danych
    datacopy(); //kopia karty

};


#endif //Patient_definition
