#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Boy {
    int diameter;
    int time;
    int index;
    double efficiency;
};

bool compareEfficiency(const Boy& a, const Boy& b) {
    if (a.efficiency > b.efficiency)
        return true;
    else if (a.efficiency == b.efficiency)
        return a.diameter > b.diameter;
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<Boy> boys(N);

    for (int i = 0; i < N; i++) {
        cin >> boys[i].diameter >> boys[i].time;
        boys[i].index = i + 1;
        boys[i].efficiency = (double(boys[i].diameter * boys[i].diameter) / boys[i].time);//boys[i].diameter * boys[i].diameter: This part calculates the area of the circle that corresponds to the weight that the boy can carry. 
      //The formula for the area of a circle is π * (radius^2). In this case, the radius is half of the diameter, so we calculate it as (diameter/2)^2, which simplifies to (boys[i].diameter * boys[i].diameter)
    }// the double ensures that the result is stores as a double data type

    sort(boys.begin(), boys.end(), compareEfficiency);

    for (int i = 0; i < N; i++) {
        cout << boys[i].index;
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
