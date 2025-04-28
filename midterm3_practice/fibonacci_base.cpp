#include <iostream>
using namespace std;

void f_b(int n){
    int arr[46];
    arr[0]=0, arr[1]=1;
    for(int i=2; i<46; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << n << " = ";

    bool f = false;
    for(int i=45; i>1; i--){
        if(n >= arr[i]){
            cout << "1";
            n -= arr[i];
            f = true;
        }
        else{
            if(f) cout << "0";
        }
    }
    cout << " (fib)\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;
    while(n--){
        cin >> m;
        f_b(m);
    }
    return 0;
}