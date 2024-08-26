struct Node{
    string url;
    Node*prev;
    Node*next;
    Node(string u,Node*p=nullptr,Node*n=nullptr):url(u),prev(p),next(n){}
};
class BrowserHistory {
    Node*head;
    Node*tail;
    Node*current;
public:
    BrowserHistory(string homepage) {
        head=tail=current=new Node(homepage);
    }
    
    void visit(string url) {
        Node*newNode=new Node(url,current);
        if(current){
            current->next=newNode;
        }
        current=newNode;
        tail=newNode;
    }
    
    string back(int steps) {
        while(steps-- && current->prev){
            current=current->prev;
        }
        return current->url;
    }
    
    string forward(int steps) {
          while(steps-- && current->next){
            current=current->next;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
