
#include "Subasta.h"

bool isproduct(const string &word){
        for(auto& c: word)
            if(!isspace(static_cast<unsigned char>(c))){
                if (isdigit(static_cast<unsigned char>(c) ))
                    continue;
                if(!isupper(static_cast<unsigned char>(c)))
                    return false;

            }
        return true;
    }


void Subasta::Save(std::ofstream &myfile) {
        Erase();
        for (const auto &u : m) {
            vector<contestant> temp;
            copy(u.second.begin(),u.second.end(),back_inserter(temp));
            sort(temp.begin(),temp.end());
            myfile << u.first << "," << max[u.first] << "," << promedio[u.first] << "," << min[u.first] << '\n';
            for (const auto& i : temp) {
                myfile << i.name << " " << i.money << '\n';
            }
            temp.clear();
        }
    }


void Subasta::Erase() {
        for (auto &u : m) {
            for (auto it = u.second.begin(); it!=u.second.end(); ) {
                if (counts[(*it).name] > 1) u.second.erase(it++);
                else it++;
            }
        }
}

Subasta::Subasta(const string& file) {
        ifstream s(file);
        string producto;
        getline(s, producto);
        int l = 1;
        while (l) {
            int mx=0;
            int mn=1000;
            if (isproduct(producto)) {
                string of = producto;
                getline(s, producto);
                m[of];
                while (!isproduct(producto)) {
                    contestant temp;
                    stringstream ss(producto);
                    ss >> temp.name >> temp.money;
                    m[of].insert(temp);
                    if (!getline(s, producto)){
                        l=0;
                        break;
                    }
                }
                double prom = 0;
                for (auto &it : m[of]) {
                    counts[it.name]++;
                    prom += it.money;
                    mn=std::min(mn,it.money);
                    mx=std::max(mx,it.money);
                }
                min[of]=mn;
                max[of]=mx;
                promedio[of] = prom / m[of].size();
            }
        }
    }


#include "Subasta.h"
