#include <iostream>
using namespace std;
const int MAX_VALUE = 62;


void CountSort(char *ch,int n,int *arr) {

    int count[MAX_VALUE + 1] = { 0 };

    for (int i = 0; i < n; i++) {
        cin >> ch[i];
        if (ch[i] >= 'a' && ch[i] <= 'z') {
            arr[i] = ch[i] - 'a' + 11;
        }
        else if (ch[i] >= '0' && ch[i] <= '9') {
            arr[i] = ch[i] - '0' + 1;
        }
        else if (ch[i] >= 'A' && ch[i] <= 'Z') {
            arr[i] = ch[i] - 'A' + 37;
        }
        count[arr[i]]++;
    }

    for (int i = 1; i <= MAX_VALUE; i++) {
        count[i] += count[i - 1];
    }


    char* sortedCh = new char[n];
    for (int i = n - 1; i >= 0; i--) {
        sortedCh[count[arr[i]] - 1] = ch[i];
        count[arr[i]]--;
    }
   

    for (int i = 0; i < n; i++) {
        cout << sortedCh[i] ;
    }
    delete[] sortedCh;
}

int main() {
    int n;
    cin >> n;
    char* ch = new char[n];
    int* arr = new int[n];

    CountSort(ch, n, arr);

    delete[] ch;
    delete[] arr;
 

    return 0;
}

