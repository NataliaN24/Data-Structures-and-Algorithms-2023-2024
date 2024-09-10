#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct request{
    int estimate;
    int time;
    request(int e,int t):estimate(e),time(t){}
    bool operator <(const request&other)const{
        return estimate>other.estimate;
    }
};

int main() {
    int k,t,b,n;
    cin>>k>>t>>b>>n;
    
    priority_queue<request>pq;
    vector<int>result;
    for(int i=0;i<n;i++)
    {
        int estimate;
        cin>>estimate;
        pq.emplace(estimate,i+1);
        if((i+1)%t==0)
        {
            for(int j=0;j<k&&!pq.empty();j++){
                result.push_back(pq.top().estimate);
                pq.pop();
            }
            if(result.size()/k>=b){
                break;
            }
            
        }
    }
    while(result.size()/k<b && !pq.empty())
    {
        for(int j=0;j<k &&!pq.empty();++j){
             result.push_back(pq.top().estimate);
                pq.pop();
        }
    }
    for(int estimate:result){
        cout<<estimate<<" ";
    }
}
