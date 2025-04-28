#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, n, p;
    cin >> t;
    while(t--){
        cin >> n >> p;
        bool days[3660] = {false};
        int d, total = 0;
        for(int i=0; i<p; i++){
            cin >> d;
            for(int j=0; j<=n; j+=d)    days[j] = true;
        }
        for(int i=0; i<=n; i++){
            if(days[i] == true && i % 7 != 6 && i % 7 != 0)    total++ ;
        }
        cout << total << "\n";
    }
    return 0;
}
