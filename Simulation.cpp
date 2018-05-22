#include <iostream>
#include <fstream>
#include <random>
#include "Dentist.h"
#include "Oculist.h"
#include "Patient.h"
#include "Simulation.h"
using namespace std;



void Simulation(string file_name)
{
    ofstream write;
    write.open("results.txt");
    ifstream read(file_name);

    int loops;
    unsigned int patients; //liczba iteracji oraz liczba pacjentow
    try
    {
        read>>loops>>patients;
    }
    catch(...)
    {
        cout<<"Blad przy wczytywaniu parametrow z pliku"<<endl;
        return;
    }

    vector <Patient> patvec{patients, Patient()};
    Dentist den1;
    Oculist ocu1;

    for(int i=0;i<loops;i++)
    {
        /*
        cout<<"Iteracja: "<<i<<endl;
        if(i==2 || i==9 || i==10 || i==12)
        {
            den1.patcame();
           // ocu1.patcame();
        }

        cout<<"Dentysta "<<den1.is_ava()<<endl;
        cout<<"Freetime "<<den1.freetime<<endl;
        cout<<"examcon "<<den1.examcon<<endl;
        cout<<"examt "<<den1.examt<<endl;
        /*
        cout<<"Okulista "<<ocu1.is_ava()<<endl;
        cout<<"Freetime "<<ocu1.freetime<<endl;
        cout<<"examcon "<<ocu1.examcon<<endl;
        cout<<"examt "<<ocu1.examt<<endl;
        */


        den1.iter();
        ocu1.iter();
    }



    read.close();
    write.close();
}

int random(int a, int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(a,b);
    int number =  dist( gen );
    return number;
}
