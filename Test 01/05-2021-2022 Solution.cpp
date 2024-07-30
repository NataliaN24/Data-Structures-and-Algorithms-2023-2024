#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Team
{
    int index;
    int contestants;
    int points;
    double score;
};

bool comparision(const Team&a,const Team&b)
{
    if(a.score==b.score){
        return a.contestants>b.contestants;
    }
    return a.score>b.score;
}

int main()
{
    int n;
    cin>>n;
    vector<Team>teams(n);
    for(int i=0;i<n;i++){
        cin>>teams[i].contestants>>teams[i].points;
        teams[i].index=i+1;
        teams[i].score=(double)(teams[i].contestants)*teams[i].contestants/teams[i].points;
        
    }
    sort(teams.begin(),teams.end(),comparision);
    for(int i=0;i<n;i++){
        cout<<teams[i].index<<" ";
    }
}
