#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node(int value):data(value) ,next(nullptr){}
};

struct LinkedList
{
private:
	Node* head;
	Node* tail;
public:
	LinkedList():head(nullptr),tail(nullptr){}

	void pushFront(int value)
	{
		Node* newHead = new Node(value);
		if (head == nullptr) 
		{
			head = newHead;
			tail = newHead;
		}
		else 
		{
			newHead->next = head;
			head = newHead;

		}

	}
	void pushBack(int value)
	{
		Node* newNode = new Node(value);
		if (tail == nullptr)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}
	
	void pushAtPosition(int value, int position)
	{
		if (position < 0)
		{
			return;
		}
		if (position == 0)
		{
			pushFront(value);
			return;
		}
		if (head == nullptr)
		{
			return;
		}
		Node* newNode = new Node(value);
		Node* current = head;
		Node* previous = nullptr;

		for (int i = 0; current != nullptr && i < position; ++i)
		{
			previous = current;
			current = current->next;
		}
		if (current == nullptr)
		{
			pushBack(value);
			return;
		}
		newNode->next = current;
		if (previous != nullptr)
		{
			previous->next = newNode;
		}
		if (newNode->next == nullptr)
		{
			tail = newNode;
		}

	}
	void popFront()
	{
		if (head == nullptr)
		{
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head == nullptr)
		{
			tail = nullptr;
		}
		delete temp;
	}
	void popBack()
	{
		if (head == nullptr)
		{
			return;
		}
		if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}
		Node* current = head;
		Node* previous = nullptr;
		while (current->next != nullptr)
		{
			previous = current;
			current = current->next;
		}
		delete current;
		tail = previous;

		if (tail != nullptr)
		{
			tail->next = nullptr;
		}
	}
	void removeAtPosition(int position)
	{
		if (position < 0 || head == nullptr)
		{
			return;
		}
		if (position == 0)
		{
			popFront();
			return;
		}
		Node* current = head;
		Node* previous = nullptr;

		for (int i = 0; current != nullptr && i < position; ++i)
		{
			previous = current;
			current = current->next;
		}
		if (current == nullptr)
		{
			return;
		}
		previous->next = current->next;
		if (current->next == nullptr)
		{
			tail = previous;
		}
		delete current;
	}
	void deleteNode(int value)
	{
		if (head == nullptr)
		{
			return;
		}
		if (head->data == value)
		{
			popFront();
			return;
		}
		Node* current = head;
		Node* previous = nullptr;
		while (current != nullptr && current->data != value)
		{
			previous = current;
			current = current->next;
		}
		if (current == nullptr)
		{
			return;
		}
		previous->next = current->next;
		if (current == tail)
		{
			tail = previous;
		}
		delete current;

	}
	bool search(int value)const
	{
		Node* current = head;
		while (current != nullptr)
		{
			if (current->data == value)
			{
				return true;
			}
			current = current->next;
		}
		return false;
	}
	void printList()const
	{
		Node* current = head;
		while (current != nullptr)
		{
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
	~LinkedList()
	{
		Node* temp;
		while (head != nullptr)
		{
			temp = head;
			head = head->next;
			delete temp;
		}
	}
};

int main() {
	LinkedList list;

	list.pushFront(10);
	list.pushFront(20);

	list.pushBack(30);
	list.pushBack(40);

	std::cout << "Linked List: ";
	list.printList();

	std::cout << "Search 20: " << (list.search(20) ? "Found" : "Not Found") << std::endl;
	std::cout << "Search 25: " << (list.search(25) ? "Found" : "Not Found") << std::endl;

	list.pushAtPosition(25, 2);
	std::cout << "After inserting 25 at position 2: ";
	list.printList();

	list.popFront();
	std::cout << "After deleting from front: ";
	list.printList();

	list.popBack();
	std::cout << "After deleting from end: ";
	list.printList();

	list.removeAtPosition(1);
	std::cout << "After deleting at position 1: ";
	list.printList();

	list.deleteNode(30);
	std::cout << "After deleting node with value 30: ";
	list.printList();

	return 0;
}