#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int count = 0;

    int size1 = s1.length();
    int size2 = s2.length();

    for (int i = 0; i <= size2 - size1; ++i) {
        bool match = true;
        for (int j = 0; j < size1; ++j) {
            if (s1[j] != s2[i + j]) {
                match = false;
                break;
            }
        }
        if (match) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
