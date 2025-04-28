#include <iostream>
using namespace std;

int main() {
    string line;
    bool open = true;
    while (getline(cin, line)) {
        for (char c : line) {
            if (c == '"') {
                cout << (open ? "``" : "''");
                open = !open;
            } else {
                cout << c;
            }
        }
        cout << '\n';
    }
    return 0;
}
