#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

struct List {
    Node* head = nullptr;
    Node* tail = nullptr;

    void add(int value) {
        Node* temp = new Node;
        temp->data = value;
        temp->next = nullptr;
        
        if (head == nullptr and tail == nullptr){
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }


    void reverse(int from, int to) {
        if(from>=to||head==nullptr||from<0){
    return;
       }
        Node*prev=nullptr;
        Node*current=head;
        for(int i=1;i<from&&current!=nullptr;i++){
            prev=current;
            current=current->next;
        }
        if(current==nullptr){
            return;
        }
        Node* start=current;
        Node*end=current;
        Node*next=nullptr;
        
        for(int i=from;i<=to&&current!=nullptr;i++){
            next=current->next;
            current->next=start;
            start=current;
            current=next;
        }
        if(prev!=nullptr){
            prev->next=start;
        }
        else{
            head=start;
        }
        end->next=current;
        if(current==nullptr){
            tail=end;
        }
        
    }

    void print() {
        Node* temp = head;
    
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    
        cout << endl;
    }

    ~List() {
        Node* curr = head;
        
        while(curr) {
            Node* prev = new Node;
            prev = curr;
            curr = curr->next;
            delete prev;
        }
        
        delete curr;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    List testList;

    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {
        
        string op;
        cin >> op;
        
        if (op == "add") {
            int num;
            cin >> num;
            testList.add(num);
        }
            
        if (op == "print") {
            testList.print();
        }
            
        if (op == "reverse") {
            int from, to;
            cin >> from >> to;
            testList.reverse(from, to);
        }
    }
    
    return 0;
}
