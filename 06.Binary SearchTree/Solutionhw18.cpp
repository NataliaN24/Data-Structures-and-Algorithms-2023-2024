#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    long long key;
    Node*left;
    Node*right;
};
const int MAX_COL=100000;
long long sum[MAX_COL]={0};

void sumVertical(Node*root,int col)
{
    if(!root){return ;}
    int index=col+MAX_COL/2; //to provide that there are not negative indexes
    if(index>=0 && index<MAX_COL){
        sum[index]+=root->key;
    }
    sumVertical(root->left,col-1);
     sumVertical(root->right,col+1);
}

int main(){
    long long n;
    cin>>n;
    long long root,left,right=0;
    Node*nodes=new Node[n];
    for(int i=0;i<n;i++){
        cin>>root>>left>>right;
        nodes[i].key=root;
        if(left!=-1){
            nodes[i].left=&nodes[left];
        }
        else{
            nodes[i].left=NULL;
        }
        if(right!=-1){
            nodes[i].right=&nodes[right];
        }
        else{
            nodes[i].right=NULL;
        }
    }
    sumVertical(&nodes[0],0);
    for(int i=0;i<MAX_COL ;++i){
        if(sum[i]!=0){
            cout<<sum[i]<<" ";
        }
    }
    delete[]nodes;
    
}
