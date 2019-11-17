#include <iostream>
#include "Subasta.h"
#include <fstream>
#include <sstream>

using namespace std;


int main() {
    Subasta subasta ("bid_example.txt");
    ofstream myfile;
    myfile.open ("resultados.txt");
    subasta.Save(myfile);
    myfile.close();
    return 0;
};