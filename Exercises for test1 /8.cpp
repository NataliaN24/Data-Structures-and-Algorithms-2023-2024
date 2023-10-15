Златар разполагал със антична везна на която от двете страни се поставяли обекти накланяйки се към по тежкият обект.
//Златаря решил, че ще е много автентично да я използва за укражение в магазина, като решил за целта да разположи от 
//едната и страна едно по - голямо парче благороден метал, а от другата страна две други парчета, като единственото му 
//желание било везната да е балансирана.След известен брой опити златаря видял, че задачата да се намерят 3 парчета за
//които едното е равно на сумата на другите не е проста.За това премерил всички парчета, разположил ги в масив и се надява
//с твоя помощ да може да си отговори на въпроса съществуват ли такива парчета или не.
//
//Input Format
//
//Вход : N - броя на продуктите X1 ... XN - теглата на продуктите
//
//Constraints
//
//3 < N < 10000 теглата на продуктите са положителни числа от 0 до 1000000
//
//	Output Format
//
//	true ако съществуват търсените продукти false ако не съществуват
//
//	Пример :
//
//Input: 5 1 2 3 4 5
//
//Output : true
//
//Input : 5 1 10 100 1000 100000
//
//OutputL false
//
//Sample Input 0
//
//5
//2 5 4 3 10
//Sample Output 0
//
//true

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    bool found = false;

    for (int i = n - 1; i >= 0; i--) {
        int left = 0;
        int right = i - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == arr[i]) {
                found = true;
                break;
            } else if (sum < arr[i]) {
                left++;
            } else {
                right--;
            }
        }

        if (found) {
            break;
        }
    }

    if (found) {
        cout << "true";
    } else {
        cout << "false";
    }

    delete[] arr;

    return 0;
}

//Another solution but it is slower than the first one and it gives timeout results
int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = arr[i] + arr[j];

            // Linear search for the sum in the array
            for (int k = 0; k < n; k++) {
                if (k != i && k != j && arr[k] == sum) {
                    found = true;
                    break;
                }
            }

            if (found) {
                break;
            }
        }
        if (found) {
            break;
        }
    }

    if (found) {
        cout << "true";
    } else {
        cout << "false";
    }

    delete[] arr;

    return 0;
}

