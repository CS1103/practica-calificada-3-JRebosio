
#ifndef PC3_SUBASTA_H
#define PC3_SUBASTA_H


#include <cctype>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
using namespace std;



struct contestant {
    string name;
    int money;
    bool operator <(contestant other)const{
        return money<other.money;
    }
};

map<string, set<contestant>> m;
map<string, int> counts;



void Erase() {
    for (auto &u : m) {
        for (auto i = u.second.begin(); i != u.second.end();) {
            auto x=*i;
            if (counts[x.name] > 1) u.second.erase(i++);
            else ++i;
        }
    }
}

bool isproduct(const string& word)
{
    for(auto& c: word)
        if(!isspace(static_cast<unsigned char>(c)))
            if(!isupper(static_cast<unsigned char>(c)))
                return false;
    return true;
}

class Subasta{
public:
    Subasta(string file) {
        ifstream s(file);
        string producto;
        getline(s, producto);
        int l = 1;
        while (l != 5) {
            if (isproduct(producto)) {
                string of=producto;
                getline(cin, producto);
                stringstream ss(producto);
                string name;
                int money;
                m[of];
                while (!isproduct(producto)) {
                    ss >> name >> money;
                    contestant temp;
                    temp.name=name;
                    temp.money=money;
                    m[of].insert(temp);
                    getline(cin,producto);
                }
                for (auto &it : m[of]) counts[it.name]++;

            }
            l++;

        }
    }

    void Save(std::ofstream& myfile) {
        Erase();

        for (auto &u : m) {
            myfile << u.first;
            for (auto i = u.second.begin(); i != u.second.end();) {
                auto x=*i;
                myfile << x.name<< " "<<x.money<<'\n';
            }
        }
    }




};



#endif //PC3_SUBASTA_H
