#include <iostream>
#include "Subasta.h"
#include <fstream>
#include <sstream>
using namespace std;
int main() {
    Subasta subasta("bid_example.txt");
    cout<<"hola";
    ofstream myfile;
    myfile.open ("example.txt");
    subasta.Save(myfile);
    cout<<"hola";
    myfile.close();
    return 0;
}