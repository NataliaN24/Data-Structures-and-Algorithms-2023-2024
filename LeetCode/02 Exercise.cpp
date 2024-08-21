#include <iostream>
#include <unordered_set>
#include <vector>

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

class Solution {
public:
	ListNode* removeDuplicates(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		std::unordered_set<int>seenValues;
		ListNode* current = head;
		ListNode* prev = nullptr;
		while (current != nullptr) {
			if (seenValues.find(current->val) != seenValues.end()) {
				prev->next = current->next;
				delete current;
			}
			else {
				seenValues.insert(current->val);
				prev = current;
			}
			current = prev->next;
		}
		return head;
	}

};

void print(ListNode* head) {
	ListNode* current = head;
	while (current != nullptr) {
		std::cout << current->val << " ";
		current = current->next;
	}
	std::cout << std::endl;
}
ListNode* createList(const std::vector<int>& values) {
	if (values.empty()) return nullptr;
	ListNode* head = new ListNode(values[0]);
	ListNode* current = head;
	for (size_t i = 1; i < values.size(); ++i) {
		current->next = new ListNode(values[i]);
		current = current->next;
	}
	return head;
}
void deleteList(ListNode* head) {
	while (head != nullptr) {
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}
}

int main() {
	Solution solution;

	std::cout << "Test Case 1: Empty List" << std::endl;
	ListNode* head1 = nullptr;
	head1 = solution.removeDuplicates(head1);
	print(head1);

	std::cout << "Test Case 2: List with One Element" << std::endl;
	std::vector<int> vec2 = { 1 };
	ListNode* head2 = createList(vec2);
	head2 = solution.removeDuplicates(head2);
	print(head2);
	deleteList(head2);

	
	std::cout << "Test Case 3: List with All Unique Elements" << std::endl;
	std::vector<int> vec3 = { 1, 2, 3, 4, 5 };
	ListNode* head3 = createList(vec3);
	head3 = solution.removeDuplicates(head3);
	print(head3);
	deleteList(head3);

	std::cout << "Test Case 4: List with All Duplicate Elements" << std::endl;
	std::vector<int> vec4 = { 1, 1, 1, 1, 1 };
	ListNode* head4 = createList(vec4);
	head4 = solution.removeDuplicates(head4);
	print(head4);
	deleteList(head4);


	std::cout << "Test Case 5: List with Some Duplicates" << std::endl;
	std::vector<int> vec5 = { 1, 2, 3, 2, 4, 1, 5, 3 };
	ListNode* head5 = createList(vec5);
	head5 = solution.removeDuplicates(head5);
	print(head5);
	deleteList(head5);


	std::cout << "Test Case 6: Duplicates at the End" << std::endl;
	std::vector<int> vec6 = { 1, 2, 3, 4, 5, 5, 5, 5 };
	ListNode* head6 = createList(vec6);
	head6 = solution.removeDuplicates(head6);
	print(head6);
	deleteList(head6);

	return 0;
}
-------------------------------ANOTHER SOLUTION-------------------------------------------------------------------------------------------------------
	class Solution {
public:
	ListNode* removeDuplicates(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		std::unordered_set<int>seenValues;
		ListNode* current = head;
		ListNode* prev = nullptr;
		while (current != nullptr) {
			if (seenValues.find(current->val) != seenValues.end()) {
				ListNode* temp = current;
				prev->next = current->next;
				current = current->next;
				delete temp;
			}
			else {
				seenValues.insert(current->val);
				prev = current;
				current = current->next;
			}
			
		}
		return head;
	}

};
