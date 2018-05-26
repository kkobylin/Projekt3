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
using namespace std;



void Simulation(string file_name)
{
    ofstream write;
    write.open("results.txt");
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
    queue <Patient> qued; //kolejka oczekujacych pacjentow do dentysty
    queue <Patient> queo; //kolejka oczekujacych pacjentow do okulisty
    queue <Patient> quep; //kolejka oczekujacych pacjentow do pediatry
    Doctor *wsk;

    int choice,number;

    for(int i=0;i<loops;i++)
    {

        cout<<"Iteracja: "<<i<<endl;

        //akcja 1
        do
        {
            number=random(0,patients-1);
        }while(patvec[number].ifbusy());
        choice=random(1,4);
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
            try
            {
                patvec[number].visitdoc(wsk);
            }
            catch(int)
            {
                cout<<"Specjalista aktualnie zajety wiec pacjent kieruje sie do kolejki"<<endl;
                write<<"Specjalista aktualnie zajety wiec pacjent kieruje sie do kolejki"<<endl;
                if(doc==1)
                    qued.push(patvec[number]);
                else if(doc==2)
                    queo.push(patvec[number]);
                else
                    quep.push(patvec[number]);
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


        den1.iter();
        ocu1.iter();
        ped1.iter();
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
