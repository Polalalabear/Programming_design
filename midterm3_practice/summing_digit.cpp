#include <iostream>
using namespace std;

int summing(int n){
    int total = 0;
    while(n > 0){
        total += n % 10;
        n /= 10;
    }
    return (total>9) ? summing(total) : total;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    while(cin >> n){
        cout << summing(n) << "\n";
    }
    return 0;
}