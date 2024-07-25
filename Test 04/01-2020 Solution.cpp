#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main() {
   int n;
    cin>>n;
    priority_queue<int>maxHeap;
    vector<int>result;
    
    for(int i=0;i<n;i++){
        int event;
        cin>>event;
        
        if(event==-1){
            if(!maxHeap.empty()){
                result.push_back(maxHeap.top());
                maxHeap.pop();
            }
        }
            else{
                maxHeap.push(event);
            }
        }
    
    for(int price:result){
        cout<<price<<" ";
    }
}
