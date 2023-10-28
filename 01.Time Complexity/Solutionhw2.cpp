#include<iostream>
#include<string>

using namespace std;

bool isUpper(char ch){
return ch>='A'&&ch<='Z;
  }

void failedStudents(int T)
{
  for(int i=0;i<T;i++){
  int N,K;         //nr of students asked and nr of students failed
  cin>>N>>K;
    string students;      //students'initials
    cin>>students;
int arr[26]={};        //for 26 letters
    for(char letter:students){
      if(isUpper(letter)){
        arr[letter-'A']++;    /// letter-'A' stands for index 65-65=0 so A will be at index 0 ,B at index 1 and so on .This is done to take note how many time is  repeated a letter[2,0,1,0..] for ex 2 times A,0 times B ,1 time C
      }
    }
    for(char l='A';l<='Z';l++)     //we start and analyze for each letter
      {
        if(arr[l-'A']>=K)    //if a letter is repeated more or equal times as K ,it will be couted ,and we do this for the entire string
        {
          cout<<l;
        }
        cout<<endl;
      }   
}

int main(){
  int T;   // nr of exams
cin>>T;
failedStudents(T);
  return 0;
}
