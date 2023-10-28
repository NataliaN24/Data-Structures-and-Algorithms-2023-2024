#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<unordered_map>
using namespace std;

class Cache {
public:
    struct  Node {
        int key;
        int value;
        Node* prev ;
        Node* next ;

        Node(int key, int value) {
            this->key = key;
            this->value=value;
        }

    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int capacity = 0;
    unordered_map<int, Node*>arr;

    Cache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;

    }


    void addNode(Node* otherNode) {
        Node* temp = head->next;
        otherNode->next = temp;
        otherNode->prev = head;

        head->next = otherNode;
        temp->prev = otherNode;


    }
    void removeNode(Node* toBedeleted) {
        Node* previous = toBedeleted->prev;
        Node* _next = toBedeleted->next;
        previous->next = _next;
        _next->prev = previous;
    }


    int  get(int key) {
        if (arr.find(key) != arr.end()) {
            Node* result = arr[key];
            int answer = result->value;

            arr.erase(key);
            removeNode(result);
            addNode(result);
            arr[key] = head->next;
            return answer;
        }
        return -1;

    }
    void put(int key, int value) {
        if (arr.find(key) != arr.end()) {
            Node* current = arr[key];
            arr.erase(key);
            removeNode(current);
        }
        if (static_cast<int>(arr.size()) >= capacity) {
            arr.erase(tail->prev->key);
            removeNode(tail->prev);
        }
        addNode(new Node(key, value));
        arr[key] = head->next;

    }

    void removeLastElement() {
        if (tail->prev != head) {
            int keyToRemove = tail->prev->key;
            arr.erase(keyToRemove);
            removeNode(tail->prev);
        }
    }




};

int main() {
    int capacity, requests, overheat ;
    cin >> capacity >> requests >> overheat;
    int counterForOverheat = 0;
    Cache newcache(capacity);
    do {
        string input;
        cin >> input;
        if (input == "put") {
            int key, value;
            cin >> key >> value;
            newcache.put(key, value);


        }
        else if (input == "get") {
            int key;
            cin >> key;
            int result = newcache.get(key);
            cout << result << std::endl;

        }
        counterForOverheat++;
        if (counterForOverheat == overheat) {
            newcache.removeLastElement();
            counterForOverheat = 0;
        }

        requests--;


    } while (requests != 0);

}
