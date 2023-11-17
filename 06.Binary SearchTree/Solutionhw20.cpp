
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};
int maxSum=INT_MIN;
int findMax(Node*root){
    if(!root){
        return 0;
    }
    else{
        int lhs=max(findMax(root->left),0);
        int rhs=max(findMax(root->right),0);
        int sum=root->data+lhs+rhs;
        maxSum=max(sum,maxSum);
                return root->data+max(lhs,rhs);      
    } 
    
}
int maxPath(Node*root){
    maxSum=INT_MIN;
    findMax(root);
    return maxSum;
}

int main() {
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;
    cin >> n;
    Node*nodes=new Node[n];
for(int i=0;i<n;i++){
    int val,left,right;
    cin>>val>>left>>right;
    
    nodes[i].data=val;
    
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
    cout<<maxPath(&nodes[0]);
    delete[]nodes;
    
}
