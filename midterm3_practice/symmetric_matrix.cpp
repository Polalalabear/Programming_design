#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

bool isSymmetric(int size, const vector<vector<ll>>& arr) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (arr[i][j] != arr[size - 1 - i][size - 1 - j])
                return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    for (int caseNum = 0; caseNum < t; ++caseNum) {
        int size;
        cin >> size;
        vector<vector<ll>> arr(size, vector<ll>(size));
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                cin >> arr[i][j];

        bool valid = true;
        for (int i = 0; i < size && valid; ++i)
            for (int j = 0; j < size && valid; ++j)
                if (arr[i][j] < 0)
                    valid = false;

        cout << "Test #" << caseNum+1 << ": ";
        if (valid && isSymmetric(size, arr))
            cout << "Symmetric.\n";
        else
            cout << "Non-symmetric.\n";
    }

    return 0;
}
