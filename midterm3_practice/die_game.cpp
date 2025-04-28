#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int move;
    while(cin >> move && move){
        int e = 4, s = 5, n = 2, w = 3, top = 1, buttom = 6;
        string dir;
        while(move--){
            cin >> dir;
            int temp = top;
            if(dir == "north"){
                top = s; 
                s = buttom; 
                buttom = n;
                n = temp;
            }  
            else if(dir == "south"){
                top = n; 
                n = buttom; 
                buttom = s;
                s = top;
            }
            else if(dir == "west"){
                top = e; 
                e = buttom; 
                buttom = w;
                w = top;
            }
            else if(dir == "east"){
                top = w; 
                w = buttom; 
                buttom = e;
                e = top;
            }
        }
        cout << top << "\n";
    }
}