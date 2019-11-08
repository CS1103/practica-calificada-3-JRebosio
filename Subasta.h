
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
        return money>=other.money;
    }
};








bool isproduct(const string& word)
{
    for(auto& c: word)
        if(!isspace(static_cast<unsigned char>(c))){
            if (isdigit(static_cast<unsigned char>(c) ))
                continue;
            if(!isupper(static_cast<unsigned char>(c)))
                return false;

        }
    return true;
}
class Subasta {
public:
    Subasta(string file) {
        ifstream s(file);
        string producto;
        getline(s, producto);
        int l = 1;
        while (l != 5) {
            if (isproduct(producto)) {
                string of = producto;
                getline(s, producto);
                m[of];
                while (!isproduct(producto)) {
                    contestant temp;
                    stringstream ss(producto);
                    ss >> temp.name >> temp.money;
                    m[of].insert(temp);
                    if (!getline(s, producto)) break;

                }
                double prom = 0;
                for (auto &it : m[of]) {
                    counts[it.name]++;
                    prom += it.money;
                }
                promedio[of] = prom / m[of].size();
            }
            l++;
        }

    }

    void Erase() {
        for (auto &u : m) {
            for (auto i = u.second.begin(); i != u.second.end();) {
                auto x = *i;
                if (counts[x.name] > 1) u.second.erase(i++);
                else ++i;
            }
        }
    }


    void Save(std::ofstream &myfile) {
        Erase();
        for (auto &u : m) {
            auto j = *u.second.begin();
            auto z = *(--u.second.end());
            myfile << u.first << "," << j.money << "," << promedio[u.first] << "," << z.money << '\n';
            for (auto i = u.second.begin(); i != u.second.end(); i++) {
                auto x = *i;
                myfile << x.name << " " << x.money << '\n';
            }
        }
    }

private:
    map<string, set<contestant>> m;
    map<string, int> counts;
    map<string,double> promedio;
};








#endif //PC3_SUBASTA_H
