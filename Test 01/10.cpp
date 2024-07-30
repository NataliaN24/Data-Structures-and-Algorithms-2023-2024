Преподавателският състав на курса по СДА има специален админски канал в Slack.Каналът е затворен и за да се присъединиш към него, 
//трябва когато ти бъде подадена парола, да върнеш нейния шифриран вариант.Паролите съдържат само главни букви от английската азбука.
//
//Шифрирането става по следния начин : Всяка последователност от еднакви букви се замества с числото, което указва колко е дълга псоледователността,
//последвана от самата буква.Правилото важи дори и за последователности от 1 символ.Така, например, AAAABBBCCDAA става 4A3B2C1D2A.
//
//Напишете програма, която по подадена парола извежда нейния шифриран вариант.
//
//Input Format
//
//От единствения ред на стандартния вход се въвежда низ str.
//
//Constraints
//
//1 <= length of str < 10 ^ 7
//
//	Output Format
//
//	На единствения ред на стандартния изход се извежда шифриран вариант на низа str.
//
//	Sample Input 0
//
//	AAAABBBCCDAA
//	Sample Output 0
//
//	4A3B2C1D2A

#include<iostream>
#include<string>
using namespace std;

//This is my colution
int main() {

	string word;
	cin >> word;

	int counter = 0;
	for (int i = 0; i < word.length()-1; i++) {
		for (int j = i; j < word.length(); j++)
		{
			if (word[i] == word[j]) {
				counter++;
			}
			else {
				
				cout << counter << word[i] << " ";
				i += counter;
				j -= 1;
				counter = 0;
				
			}
		}	
		cout << counter << word[i] << " ";
  }
}

//This si the solution from our teaching assistant

string s;
int main() {
    cin>>s;
    for(int i=0; i<(int)s.size(); ++i)
    {
        int br = 0, j = i;
        while(s[j] == s[i])
        {
            br++;
            j++;
        }
        cout<<br<<s[i];
        i = j-1;
    }
}
