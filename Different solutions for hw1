#include<iostream>
#include<cstring>
#include<string>
using namespace std;
//first solution of homework task 1
//the problem is in time ,it doesn't give the quick result for some cases 

int symbolToWord(string word, int N, char symbol) {
	int len = word.length();
	string result = "";
	int j;
	for (int i = 0; i < N; i++) {
		result += word[j];
		if (j == len) {
			j = 0;
		}
	}
	int counter = 0;
	for (int i = 0; i < N; i++) {
		if (result[i] == symbol) {
			counter++;
		}
	}
	return counter;

}
//in order to correct the time execution I provided the next code

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
