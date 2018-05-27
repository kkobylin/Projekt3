#include <iostream>
#include <fstream>
#include "Simulation.h"
using namespace std;

int main()
{
    Simulation("dane.txt");
    /*
    ofstream writ;
    ofstream write("results.txt", ios::app);
    writ.open("results.txt", ios::app);
   // writ.seekp( 0, std::ios_base::end );
    writ<<"Patient's data: "<<endl;
    writ<<"Patient's data: "<<endl;
    writ<<"Patient's data: "<<endl;
    write<<"cos"<<endl;
    write<<"dwa"<<endl;
    //writ<<name<<endl;
    writ.close();
    write.close();
    */
}
