#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(int *arr, int n){
    int count=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
    }
    cout << "Optimal train swapping takes " << count << " swaps.\n";
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, size;
    cin >> n;
    while(n--){
        cin >> size;
        vector<int> arr(size);
        for(int i=0; i<size; i++)    cin >> arr[i];
        
        bubble_sort(arr.data(), size);
    }
    return 0;
}