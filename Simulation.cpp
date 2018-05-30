#include <iostream>
#include <fstream>
#include <random>
#include "Pedia.h"
#include "Dentist.h"
#include "Oculist.h"
#include "Patient.h"
#include "Simulation.h"
#include <ctime>
#include <windows.h>
using namespace std;



void Simulation(string file_name)
{
    ofstream write;
    write.open("results.txt", ios::app);
    ofstream cleanfile("results.txt", ios::trunc);
    ifstream read(file_name);

    int loops,patients; //liczba iteracji oraz liczba pacjentow
    unsigned int dentn, ocun, pedn; //liczba lekarzy poszczegolnych specjalizacji
    try
    {
        read>>loops>>patients>>dentn>>ocun>>pedn;
        if(read.fail())
        {
            struct readfail{};
            readfail a;
            throw a;
        }
        if(loops<0 || patients<=0 || dentn<0 || ocun<0 || pedn<0)
        {
            int a;
            throw a;
        }
    }
    catch(...)
    {
        cout<<"Blad przy wczytywaniu parametrow z pliku"<<endl;
        return;
    }


    //wektor pacjentow
    vector <Patient> patvec;
    for(int i=0;i<patients;i++)
        patvec.push_back(Patient(i));

    //wektor dentystow
    vector <Dentist> denvec{dentn, Dentist()};

    //wektor okulistow
    vector <Oculist> ocuvec{ocun, Oculist()};

    //wektor pediatrow
    vector <Pedia> pedvec{pedn, Pedia()};

    Doctor *wsk=nullptr;
    //zmienne sluzace do losowania
    int choice,number,docnumber,doc;

    //zmienna pomocnicza
    bool docfree;

    //struktura sluzaca do rzucania okreslonego typu wyjatku
    struct thereisnodoc{};

    for(int i=0;i<loops;i++)
    {

        cout<<"Iteracja: "<<i<<endl;
        write<<"Iteracja: "<<i<<endl;

        for(int akcja=1;akcja<=3;akcja++)
        {
        //Pojedyncza akcja

        number=random(0,patients-1);

        if(patvec[number].ifbusy())
        {
            cout<<"Pacjent numer "<<number<<" aktualnie zajety"<<endl;
            write<<"Pacjent numer "<<number<<" aktualnie zajety"<<endl;
        }
        else
        {
            choice=random(1,5);

        switch(choice)
        {
        case 1:
            //Pacjent idzie do specjalisty
            doc=random(1,3);
            doc=1;
            switch(doc)
            {
            case 1:
                try
                {
                    if(dentn==0)
                    {
                         thereisnodoc a;
                        throw a;
                    }
                    docnumber=random(0,dentn-1);
                }
                catch(thereisnodoc)
                {
                   cout<<"Pacjent nr "<<number<<" kieruje sie do dentysty ale nie ma zadnego w tej przychodni"<<endl;
                    continue;
                }
                wsk=&denvec[docnumber];
                cout<<"Pacjent nr "<<number<<" kieruje sie do dentysty numer "<<docnumber<<endl;
                write<<"Pacjent nr "<<number<<" kieruje sie do dentysty numer "<<docnumber<<endl;
                break;
            case 2:
                try
                {
                    if(ocun==0)
                    {
                         thereisnodoc a;
                        throw a;
                    }
                    docnumber=random(0,ocun-1);
                }
                catch(thereisnodoc)
                {
                   cout<<"Pacjent nr "<<number<<" kieruje sie do okulisty ale nie ma zadnego w tej przychodni"<<endl;
                    continue;
                }
                wsk=&ocuvec[docnumber];
                cout<<"Pacjent nr "<<number<<" kieruje sie do okulisty numer "<<docnumber<<endl;
                write<<"Pacjent nr "<<number<<" kieruje sie do okulisty numer "<<docnumber<<endl;
                break;
            case 3:
                try
                {
                    if(pedn==0)
                    {
                         thereisnodoc a;
                        throw a;
                    }
                    docnumber=random(0,pedn-1);
                }
                catch(thereisnodoc)
                {
                   cout<<"Pacjent nr "<<number<<" kieruje sie do pediatry ale nie ma zadnego w tej przychodni"<<endl;
                    continue;
                }
                 wsk=&pedvec[docnumber];
                cout<<"Pacjent nr "<<number<<" kieruje sie do pediatry numer "<<docnumber<<endl;
                write<<"Pacjent nr "<<number<<" kieruje sie do pediatry numer "<<docnumber<<endl;
                break;
            }
            try
            {
                docfree=patvec[number].visitdoc(wsk);
            }
            catch(int)
            {
                cout<<"Wskaznik nie ustawiony na zadnego specjaliste"<<endl;exit(0);
            }
            if(docfree)
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

        case 5:
            //Pacjent idzie do specjalisty
            doc=random(1,3);
            switch(doc)
            {
            case 1:
                try
                {
                    if(dentn==0)
                    {
                         thereisnodoc a;
                        throw a;
                    }
                    docnumber=random(0,dentn-1);
                }
                catch(thereisnodoc)
                {
                   cout<<"Pacjent nr "<<number<<" kieruje sie do dentysty ale nie ma zadnego w tej przychodni"<<endl;
                    continue;
                }
                wsk=&denvec[docnumber];
                cout<<"Pacjent nr "<<number<<" kieruje sie do dentysty numer "<<docnumber<<endl;
                write<<"Pacjent nr "<<number<<" kieruje sie do dentysty numer "<<docnumber<<endl;
                break;
            case 2:
                try
                {
                    if(ocun==0)
                    {
                         thereisnodoc a;
                        throw a;
                    }
                    docnumber=random(0,ocun-1);
                }
                catch(thereisnodoc)
                {
                   cout<<"Pacjent nr "<<number<<" kieruje sie do okulisty ale nie ma zadnego w tej przychodni"<<endl;
                    continue;
                }
                wsk=&ocuvec[docnumber];
                cout<<"Pacjent nr "<<number<<" kieruje sie do okulisty numer "<<docnumber<<endl;
                write<<"Pacjent nr "<<number<<" kieruje sie do okulisty numer "<<docnumber<<endl;
                break;
            case 3:
                try
                {
                    if(dentn==0)
                    {
                         thereisnodoc a;
                        throw a;
                    }
                    docnumber=random(0,pedn-1);
                }
                catch(thereisnodoc)
                {
                   cout<<"Pacjent nr "<<number<<" kieruje sie do pediatry ale nie ma zadnego w tej przychodni"<<endl;
                    continue;
                }
                 wsk=&pedvec[docnumber];
                cout<<"Pacjent nr "<<number<<" kieruje sie do pediatry numer "<<docnumber<<endl;
                write<<"Pacjent nr "<<number<<" kieruje sie do pediatry numer "<<docnumber<<endl;
                break;
            }
            try
            {
                docfree=patvec[number].visitdoc(wsk);
            }
            catch(int)
            {
                cout<<"Wskaznik nie ustawiony na zadnego specjaliste"<<endl;exit(0);
            }
            if(docfree)
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
        }
        Sleep(1500);
        }

        cout<<endl;
        write<<endl;
        }


        for(int i=0;i<dentn;i++)
            denvec[i].iter();

        for(int i=0;i<ocun;i++)
            ocuvec[i].iter();

        for(int i=0;i<pedn;i++)
            pedvec[i].iter();

        cout<<"-----------------------------------------------------"<<endl;
        write<<"-----------------------------------------------------"<<endl;
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
