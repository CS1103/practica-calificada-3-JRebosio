#include <iostream>
#include "Subasta.h"

int main() {
    Subasta subasta{"bif_example.txt"};
    ofstream myfile;
    myfile.open("resul_example.txt");
    subasta.Save()myfile;
    return 0;
}