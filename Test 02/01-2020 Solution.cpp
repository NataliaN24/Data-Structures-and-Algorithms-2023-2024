#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    Node * next;
    int data;
    Node(Node* _next,int _data){
        next = _next;
        data = _data;
    }
};
class LinkedList{
    public:
    LinkedList(){
        head = NULL;
    }
    ~LinkedList(){
        Node* tmp;
        while(head!=NULL){
            tmp = head;
            head = head->next;
            delete tmp;
        }
    }
    void add(int number){
        Node *tmp = new Node(head,number);
        head = tmp;
    }
    void print(){
        Node* curr = head;
        while(curr!=NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
//----------------------------------------------------FIRST SOLUTION--------------------------------------------------------------------------------------------
    void removeComplex(int devidedBy) {
      
        Node* current = head;
        Node* prev = nullptr;
        if (head == nullptr) {
            return;
        }
        
        while (current != nullptr) {
            if (current->data % devidedBy == 0) {
                Node*temp=current;
               if(prev){
                   prev->next=current->next;
               }
                else{
                    head=current->next;
                }
                current=current->next;
                delete temp;
            }else{
                prev=current;
                current=current->next;
            }
        }
    
    }
//----------------------------------------------------SECOND  SOLUTION--------------------------------------------------------------------------------------------
void removeComplex(int dividedBy){
       
   Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr) 
    {
        if (current->data % dividedBy == 0)
        {
            if (prev != nullptr) {
                prev->next = current->next;
                delete current;
                current = prev->next;
            } else
            {
                head = current->next;
                delete current;
                current = head;
            }
        } 
        else
        {
            prev = current;
            current = current->next;
        }
    }
    }
    private:
    Node* head;
};
int main(){
    LinkedList l;

    int n;
    cin >> n;
    int number;
    for(int i = 0 ; i < n ; i++){
        cin >>number;
        l.add(number);
    }
    int devidedBy;
    cin >> devidedBy;
    l.removeComplex(devidedBy);
    l.print();
}
