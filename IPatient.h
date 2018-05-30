#ifndef IPatient_definition
#define IPatient_definition

#include <iostream>
//#include "Doctor.h"

class Doctor;

class IPatient
{
    public:
    virtual ~IPatient(){};
    virtual bool visitdoc(Doctor *wsk)=0; //wizyta lekarza
    virtual bool docapp(Doctor *wsk)=0; //zapis do lekarza
    virtual void dataact(std::string newname)=0; //aktualizacja swoich danych
    virtual void datacopy()=0; //kopia karty
    //virtual void notbusy()=0; //zmiana stanu pacjenta
    virtual bool ifbusy()=0; //czy pacjent zajety
};


#endif //IPatient_definition
