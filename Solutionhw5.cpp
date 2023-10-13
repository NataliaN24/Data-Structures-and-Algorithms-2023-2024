#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//1st Solution for all results

int main(){
    int n;
    std::cin >> n;

    std::vector<int> profits(n);
    for (int i = 0; i < n; i++) {
        std::cin >> profits[i];
    }

    std::vector<int> copied = profits;
    std::sort(copied.begin(), copied.end());

    int start = 0, end = n - 1;


    while (start < n && profits[start] == copied[start]) {
        start++;
    }

    while (end >= 0 && profits[end] == copied[end]) {
        end--;
    }

    int length = (end > start) ? (end - start + 1) : 0;

    std::cout << length << std::endl;

    return 0;
}
//2nd Solution

int main() {
    int n;
    std::cin >> n;

    std::vector<int> profits(n);

    for (int i = 0; i < n; i++) {
        std::cin >> profits[i];
    }

    std::vector<int> copied = profits;

    std::sort(profits.begin(), profits.end());

    int count = 0;

    for (int i = 0; i < n; i++) 
    {
        if (profits[i] != copied[i]) 
        {
            count++;
        }
    }
   int l= (count > 0) ? count + 1 : 0;

    std::cout << l << std::endl;

    return 0;
}
