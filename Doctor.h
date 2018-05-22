#ifndef Doctor_definition
#define Doctor_definition

#include <iostream>
using namespace std;


class Doctor
{

    public:
    virtual bool is_ava()=0; //Czy lekarz dostepny
    virtual void iter()=0; //funkcja wykonujaca sie po kazdej iteracji
    virtual void patcame()=0; //funkcja wykonujaca sie gdy przyjdzie pacjent
    virtual ~Doctor(){}; //destruktor wirtualny

};


#endif //Doctor_definition
