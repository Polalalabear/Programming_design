#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a, b;
    while(cin >> a >> b){
        int f_a[128] = {0}, f_b[128] = {0};
        for(char c:a)   f_a[(unsigned char)c]++;
        for(char c:b)   f_b[(unsigned char)c]++;
        for(int i=95; i<=128; i++){
            int count = min(f_a[i], f_b[i]);
            while(count--)  cout << (char)i;
        }
        cout << "\n";
    }
}