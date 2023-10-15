Напишете програма, която получава като вход два масива с цели числа и връща като изход сумата на уникалните числа, които се срещат и в двата масива.
//
//Пример: Вход: 10
//
//1 5 7 9 4 3 1000 5 9 10
//
//5
//
//66 3 9 44 9
//
//Изход: 12
//
//Обяснение : числата, които се срещат и в двата масива са 3 и 9 тяхната сума е 12.
//Числото 9 се среща повече от един път, но нас ни интересуват само уникалните числа за това го включваме в сумата само един път.




#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    int* arr1 = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    cin >> m;
    int* arr2 = new int[m];
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    int sum = 0;
    int i = 0, j = 0;

    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            sum += arr1[i];
            i++;
            j++;
            // Skip duplicates
            while (i < n && arr1[i] == arr1[i - 1]) {
                i++;
            }
            while (j < m && arr2[j] == arr2[j - 1]) {
                j++;
            }
        } else if (arr1[i] < arr2[j]) {
            i++;
        } else {
            j++;
        }
    }

    cout << sum;

    delete[] arr1;
    delete[] arr2;

    return 0;
}
