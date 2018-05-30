#ifndef IDoctor_definition
#define IDoctor_definition

#include <iostream>
//#include "Patient.h"
class Patient;


class IDoctor
{

    public:
    virtual bool is_ava()=0; //Czy lekarz dostepny
    virtual void iter()=0; //funkcja wykonujaca sie po kazdej iteracji
    virtual bool patcame(Patient *p)=0; //funkcja wykonujaca sie gdy przyjdzie
    virtual void toque(Patient *p)=0;

    virtual int examt()=0; //czas pojedynczych badan
    virtual int breakt()=0; //co ile lekarz jest dostepny
    virtual int avat()=0; //czas na jaki lekarz jest dostepny
    virtual ~IDoctor(){};

};


#endif //IDoctor_definition
