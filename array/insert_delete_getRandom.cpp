#include<bits/stdc++.h>
using namespace std;

class RandomizedCollection {
public:
    vector <int> v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {

        for(int i=0; i<v.size(); i++){
            if(v[i]==val){
                v.push_back(val);
                return false;
            }
        }

        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        for(int i=0; i<v.size(); i++){
            if(v[i]==val){
                v.erase(v.begin()+i);
                return true;
            }
        }

        return false;
    }
    
    int getRandom() {
        int index = rand()%v.size();
        return v[index];
    }
};