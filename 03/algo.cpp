#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

int main(){
    vector<int>v(5);
    bool found;
    
    for(int i=0;i<5;i++){
        v[i]=i; // v.push_back(i)
    }
    
    found = binary_search(v.begin(), v.end(), 3);
    cout << found << endl;
    
    found = binary_search(v.begin(), v.end(), 9);
    cout << found << endl;
    
    sort(v.begin(), v.end());
    for(int i : v){
        cout << i << "->";
    }
    return 0;
}

