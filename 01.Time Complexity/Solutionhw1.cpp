#include<iostream>
#include<cstring>
#include<string>
using namespace std;
//first solution of homework task 1

int symbolInWord(string word, int N, char symbol)
{
	int length = word.length();
	long long counter = 0;     //due to 10^9
	for (int i = 0; i < length; i++){
		if (word[i] == symbol) {
			counter++;
		}
	}
	long long repeatedWord=N/length;   //to find how many times the full word will be repeated
	int remainder=N%length;      // to find which part of the word will be out of the full repeated word
	counter = counter * repeatedWord;

	for (int i = 0; i < remainder; i++) {
		if (word[i] == symbol) {
			counter++;
		}
	}
	return counter;

}

//or ------------------------------------------------------------------------------------------

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


int main() 
{
    string str;
    cin >> str;
    int num;
    cin >> num;
    char ch;
    cin >> ch;
    int counter = 0;

    int length = str.length();
    int howmany = num / length;
    int left = num - (howmany * length);
	
    for (int i = 0; i < length; ++i) {
        if (str[i] == ch) {
            counter++;
        }
    }
	
    int allFound = counter * howmany;
	
    for (int i = 0; i < left; i++) {
        if (str[i] == ch) {
            allFound++;
        }
    }
    cout << allFound;
}
