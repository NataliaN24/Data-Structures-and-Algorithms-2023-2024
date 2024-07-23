#include <iostream>
using namespace std;

int main() {
    string str1;
    string str2;

    cin >> str1 >> str2;
    size_t longest = 0;

    for (size_t i = 0; i < str1.size(); i++) {
        for (size_t j = 0; j < str2.size(); j++) {
            size_t current = 0;
            size_t row = i;
            while (row < str1.size() && j < str2.size() && str1[row] == str2[j]) {
                current++;
                row++;
                j++;
            }
            longest = max(longest, current);
        }
    }
    cout << longest;
    return 0;
}
