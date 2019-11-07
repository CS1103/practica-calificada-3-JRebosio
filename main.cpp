#include <iostream>
#include "Subasta.h"
#include <fstream>
#include <sstream>
using namespace std;
int main() {
    Subasta subasta{"bif_example.txt"};
    ofstream myfile;

    //myfile.open("C:\\POO2\\practica-calificada-3-JRebosio\\resultado.txt");
    myfile.open("resultado.text");
    subasta.Save(myfile);
    myfile.close();
    return 0;
}