#include <iostream>
#include "Subasta.h"
#include <fstream>
#include <sstream>
using namespace std;
int main() {
    Subasta subasta{"bif_example.txt"};
    ofstream myfile;
    myfile.open("result_example.txt");
    subasta.Save(myfile);
    return 0;
}