#include <iostream>
#include <fstream>
#include <random>
#include "Doctor.h"
#include "Pedia.h"
#include "Dentist.h"
#include "Oculist.h"
#include "Patient.h"
#include "Simulation.h"
#include <queue>
#include <ctime>
#include <windows.h>
using namespace std;



void Simulation(string file_name)
{
    ofstream write;
    write.open("results.txt", ios::app);
    ofstream cleanthefile("results.txt", ios::trunc);
    ifstream read(file_name);

    int loops,patients; //liczba iteracji oraz liczba pacjentow
    try
    {
        read>>loops>>patients;
    }
    catch(...)
    {
        cout<<"Blad przy wczytywaniu parametrow z pliku"<<endl;
        return;
    }

    //vector <Patient> patvec{patients, Patient()};
    //wektor pacjentow
    vector <Patient> patvec;
    for(int i=0;i<patients;i++)
        patvec.push_back(Patient(i));


    Dentist den1;
    Oculist ocu1;
    Pedia ped1;
    Doctor *wsk;

    int choice,number;


    for(int i=0;i<loops;i++)
    {

        cout<<"Iteracja: "<<i<<endl;
        write<<"Iteracja: "<<i<<endl;

        //akcja 1

        number=random(0,patients-1);

        if(patvec[number].ifbusy())
        {
            cout<<"Pacjent numer "<<number<<" aktualnie zajety"<<endl;
            write<<"Pacjent numer "<<number<<" aktualnie zajety"<<endl;
        }
        else
        {
            choice=random(1,4);
            //choice=1;

        switch(choice)
        {
        case 1:
            //Pacjent idzie do specjalisty
            int doc;
            doc=random(1,3);
            switch(doc)
            {
            case 1:
                wsk=&den1;
                cout<<"Pacjent nr "<<number<<" kieruje sie do dentysty"<<endl;
                write<<"Pacjent nr "<<number<<" kieruje sie do dentysty"<<endl;
                break;
            case 2:
                wsk=&ocu1;
                cout<<"Pacjent nr "<<number<<" kieruje sie do okulisty"<<endl;
                write<<"Pacjent nr "<<number<<" kieruje sie do okulisty"<<endl;
                break;
            case 3:
                wsk=&ped1;
                cout<<"Pacjent nr "<<number<<" kieruje sie do pediatry"<<endl;
                write<<"Pacjent nr "<<number<<" kieruje sie do pediatry"<<endl;
                break;
            }
            if(patvec[number].visitdoc(wsk))
            {
                cout<<"Pacjent zostal przyjety"<<endl;
                write<<"Pacjent zostal przyjety"<<endl;
            }
            else
            {
                cout<<"Lekarz zajety. Pacjent zostal skierowany do kolejki."<<endl;
                write<<"Lekarz zajety. Pacjent zostal skierowany do kolejki."<<endl;
            }

            break;

        case 2:
            cout<<"Pacjent nr "<<number<<" aktualizuje swoje dane"<<endl;
            write<<"Pacjent nr "<<number<<" aktualizuje swoje dane"<<endl;
            patvec[number].dataact("Kazimierz Kowalski");
            break;

        case 3:
            cout<<"Pacjent nr "<<number<<" zamawia kopie swojej karty"<<endl;
            write<<"Pacjent nr "<<number<<" zamawia kopie swojej karty"<<endl;
            patvec[number].datacopy();
            break;

        case 4:
            cout<<"Pacjent nr "<<number<<" nic nie robi"<<endl;
            write<<"Pacjent nr "<<number<<" nic nie robi"<<endl;
            break;
        }
        Sleep(1000);
        }

        cout<<endl;
        write<<endl;
        den1.iter();
        ocu1.iter();
        ped1.iter();
    }


    read.close();
    write.close();
}

random_device rd;
mt19937 gen(time(0));

inline int random(int a, int b)
{

    uniform_int_distribution<> dist(a,b);
    int number =  dist( gen );
    for(int i=0;i<a*b;i++)
    number =  dist( gen );
    return number;
}
