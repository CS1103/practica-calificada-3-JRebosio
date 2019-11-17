
#ifndef PC3_SUBASTA_H
#define PC3_SUBASTA_H



#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;


struct contestant {
    string name;
    int money;

    bool operator<(const contestant &other) const {
        //return name!=other.name;
        return name != other.name && money >= other.money;
    }
};

bool isproduct(const string& word);




class Subasta {
public:


    Subasta(const string& file);
    void Erase() ;
    void Save(std::ofstream &myfile);

private:
    map<string, set<contestant>> m;
    map<string, int> counts;
    map<string,double> promedio;
    map<string, int> min;
    map<string, int> max;
};


#endif //PC3_SUBASTA_H
