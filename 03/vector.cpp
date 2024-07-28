#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;
    
    v.push_back(100);
    v.push_back(1000);    
    v.push_back(10000);
    v.insert(v.begin(), 10);  
    v.insert(v.end(),100000);
    v.erase(v.begin() + 3);  
    
    for(int i : v){
        cout << i << endl;
    }
    
    for(auto i = v.begin(); i != v.end(); ++i) {
        cout << *i << " "; 
    }
    return 0;
}
