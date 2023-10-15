В турнир по икономика в Китай се приложили иновативни правила, които обаче доста затруднили сидиите в изграждане на класацията на отборите.
//
//Правилата били следните - позволило се на всички участници да си направят отбори с различни на брой участници, като всеки
//човек от отбора носи толкова точки за отбора, колкото участници има в него, а за смятане на краен резултат тези точките се разделяли на броя на участниците в
//противниковият отбор.
//
//Поради сложната ситуация с точкуването, не всички отбори се съгласили да участват в крайното класиране, но дори след отказването
//на част от отборите да се определи кой отбор на кое място е в класирането се оказало достатъчно трудна задача за контролна работа по сда.
//
//Помогнете за подредба на отборите в класиране, като за идентификация на отборите използваме на кой ред в списъка за сортиране подаван като вход са включени.
//
//
//
//Output Format
//
//изведете индексите на печелившите отбори в намаляващ ред по точки.Ако два отбора имат еднакви точки, 
//то изведете индекса на отбора с повече състезатели.Индексите трябва да са разделени с точно един интервал и индекса на първата двойка е 1, а на последната - N.
//
//Sample Input 0
//
//3
//100 1
//20 2
//130 2
//Sample Output 0
//
//1 3 2

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Contestant {
    int nr;
    int points;
    int index;
    double efficasity;
};

bool compareContestants(const Contestant& a, const Contestant& b) {
    if (a.efficasity > b.efficasity) {
        return true;
    } else if (a.efficasity == b.efficasity) {
        return a.nr > b.nr;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<Contestant> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].nr >> arr[i].points;
        arr[i].index = i + 1;
        arr[i].efficasity = static_cast<double>(arr[i].nr*arr[i].nr) / arr[i].points;
    }

    sort(arr.begin(), arr.end(), compareContestants);

    for (int i = 0; i < n; i++) {
        cout << arr[i].index << " ";
    }

    return 0;
}
