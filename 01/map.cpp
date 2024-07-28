#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, string>m;
    m[1] = "i";
    m[2] = "love";
    m[3] = "you";
    
//    for(const auto &pair : m){
//        cout << pair.first << " : " << pair.second << endl;
//    }

    for(const auto &[key, value] : m){
        cout << key << " : " << value << endl;
    }
    return 0;
}
