#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int value;
    int sum;
    vector<Node*>children;
};

int countNodes(Node*r)
{
    int sum=0;
    for(Node*child:r->children)
    {
        sum+=1+countNodes(child);
    }
    return r->sum=sum;
}

int main(){
    int n;
    cin>>n;
    vector<Node>nodes(n);
    
    for(int i=0;i<n-1;++i){
        int a;
        int b;
        cin>>a>>b;
        nodes[a].children.push_back(&nodes[b]);

    }
    countNodes(&nodes[0]);
    for(int i=0;i<n;i++){
        cout<<nodes[i].sum<<" ";
    }
    
}

