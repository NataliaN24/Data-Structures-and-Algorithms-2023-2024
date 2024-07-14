#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<unordered_map>
using namespace std;

//-----------------------------------First Solution---------------------------------------------------------------------------------------------------
int main(){
    string s;
    cin>>s;
    unordered_map<char,int>count;
    for(char c:s){
        count[c]++;
    }
    for(int i=0;i<s.length();++i){
        if(count[s[i]]==1){
            cout<<i<<" ";
        }
    } 
}
//-----------------------------------Second Solution---------------------------------------------------------------------------------------------------
int main(){
string s;
cin>>s;
vector<int>count(26,0);
for(int i=0;i<s.length();i++){
count[s[i]-'a']++;
}
for(int i=0;i<s.length();++i){
if(count[s[i]-'a']==1){
cout<<i<<" " ;
}
}
}
