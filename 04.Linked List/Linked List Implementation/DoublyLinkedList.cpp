#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node* prev;
	Node(int value):data(value) ,next(nullptr),prev(nullptr) {}
};

struct DoublyLinkedList
{
private:
	Node* head;
	Node* tail;
public:
	DoublyLinkedList():head(nullptr),tail(nullptr){}

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
			head->prev = newHead;
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
			newNode->prev = tail;
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
		

		for (int i = 0; current != nullptr && i < position-1; ++i)
		{
			current = current->next;
		}

		if (current == nullptr||current->next==nullptr)
		{
			pushBack(value);
			return;
		}
		newNode->next = current->next;
		newNode->prev = current;
		if (current->next != nullptr)
		{
			current->next->prev = newNode;
		}
		current->next = newNode;
	}
	void popFront()
	{
		if (head == nullptr)
		{
			return;
		}
		Node* temp = head;
		head = head->next;
		if (head != nullptr)
		{
			head->prev = nullptr;
		}
		else
		{
			tail = nullptr;
		}
		delete temp;
	}
	void popBack()
	{
		if (tail == nullptr)
		{
			return;
		}
		Node* temp = tail;
		tail = tail->prev;
		if (tail != nullptr)
		{
			tail->next = nullptr;
		}
		else
		{
			head = nullptr;
		}
		delete temp;
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
		

		for (int i = 0; current != nullptr && i < position; ++i)
		{
			current = current->next;
		}
		if (current == nullptr)
		{
			return;
		}
	
		if (current->prev != nullptr)
		{
			current->prev->next = current->next;
		}
		if (current->next != nullptr)
		{
			current->next->prev = current->prev;
		}
		if (current == tail)
		{
			tail = current->prev;
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

		while (current != nullptr && current->data != value)
		{
			current = current->next;
		}
		if (current == nullptr)
		{
			return;
		}
		if (current->prev != nullptr)
		{
			current->prev->next = current->next;
		}
		else
		{
			head = current->next;
		}
		if (current->next != nullptr)
		{
			current->next->prev = current->prev;
		}
		else
		{
			tail = current->prev;
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
	~DoublyLinkedList()
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
	DoublyLinkedList list;
  
	list.pushFront(10);
	list.pushFront(20);

	list.pushBack(30);
	list.pushBack(40);

	std::cout << "Doubly Linked List: ";
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
