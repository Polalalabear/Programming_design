#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void solve(ll n, ll m){
    vector <int> arr;
    while(n>1){
        if(n % m != 0){
            cout << "Boring!" << "\n";
            return;
        }
        arr.push_back(n);
        n /= m;
    }
    arr.push_back(1);

    for(size_t i=0; i<arr.size(); ++i){
        printf("%d%c", arr[i], (i!=arr.size()-1) ? ' ' : '\n');
    }
}

int main(){
    int n, m;
    while(cin >> n >> m){
        if(n<2 || m<2)  cout << "Boring!" << "\n";
        else solve(n, m);
    }
    return 0;
}