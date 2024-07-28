#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int>q;
    int sum = 0; // int sum(0);
    
    for(int i=1;i<=10;i++){
        q.push(i);
    }
    
    while(!q.empty()){
        sum += q.front();
        cout << "front : " << q.front() << endl;
        q.pop();
    }
    
    cout << "sum : " << sum << endl;
    return 0;
}
