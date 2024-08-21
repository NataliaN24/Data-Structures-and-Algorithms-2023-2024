# Linked List Exercises

This repository contains solutions and explanations for common linked list problems. Each exercise is implemented in C++ and includes a detailed explanation and example.

## Exercises

### **01. Removing Duplicates from Sorted Linked List**
**Problem**: [Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)  
**Description**: Given a sorted linked list, remove all duplicates such that each element appears only once.  
**Example**:
- **Input**: `1 -> 1 -> 2`  
- **Output**: `1 -> 2`  

**Solution**: [Remove Duplicates from Sorted Linked List](./remove-duplicates-sorted-list.cpp)

---

### **02. Removing Duplicates from Unsorted Linked List**
**Description**: Given an unsorted linked list, remove all duplicates such that each element appears only once. This problem requires extra space or modification of the list to identify duplicates.

**Example**:
- **Input**: `4 -> 3 -> 4 -> 2 -> 1 -> 2`  
- **Output**: `4 -> 3 -> 2 -> 1`  

**Solution**: [Remove Duplicates from Unsorted Linked List](./remove-duplicates-unsorted-list.cpp)

---

### **03. Sorting a Linked List**
**Problem**: [Sort List](https://leetcode.com/problems/sort-list/)  
**Description**: Sort a linked list in ascending order using a merge sort algorithm.  
**Example**:
- **Input**: `4 -> 2 -> 1 -> 3`  
- **Output**: `1 -> 2 -> 3 -> 4`  

**Solution**: [Sorting a Linked List](./sort-list.cpp)

---

### **04. Sorting a Linked List in Descending Order**
**Description**: Sort a linked list in descending order. This can be achieved by modifying the sort function to sort in reverse order.

**Example**:
- **Input**: `1 -> 3 -> 2 -> 5 -> 4`  
- **Output**: `5 -> 4 -> 3 -> 2 -> 1`  

**Solution**: [Sorting a Linked List in Descending Order](./sort-list-descending.cpp)

---

### **05. Reversing a Linked List from Start to End**
**Problem**: [Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)  
**Description**: Reverse a singly linked list from start to end.  
**Example**:
- **Input**: `1 -> 2 -> 3 -> 4 -> 5`  
- **Output**: `5 -> 4 -> 3 -> 2 -> 1`  

**Solution**: [Reversing a Linked List from Start to End](./reverse-list.cpp)

---

### **06. Reversing All of the Linked List**
**Description**: Similar to reversing from start to end, this exercise requires you to reverse the entire linked list in-place.

**Example**:
- **Input**: `10 -> 20 -> 30 -> 40 -> 50`  
- **Output**: `50 -> 40 -> 30 -> 20 -> 10`  

**Solution**: [Reversing All of the Linked List](./reverse-entire-list.cpp)

---

### **07. Reorder List**
**Problem**: [Reorder List](https://leetcode.com/problems/reorder-list/)  
**Description**: Reorder the list to be in the following format: L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → ...  
**Example**:
- **Input**: `1 -> 2 -> 3 -> 4 -> 5`  
- **Output**: `1 -> 5 -> 2 -> 4 -> 3`  

**Solution**: [Reorder List](./reorder-list.cpp)

---

### **08. Swapping Elements in Linked List**
**Description**: Swap adjacent nodes in a linked list in pairs. For example, if the list is `1 -> 2 -> 3 -> 4`, it should be transformed into `2 -> 1 -> 4 -> 3`.

**Example**:
- **Input**: `1 -> 2 -> 3 -> 4`  
- **Output**: `2 -> 1 -> 4 -> 3`  

**Solution**: [Swapping Elements in Linked List](./swap-elements-list.cpp)

---

Feel free to clone this repository and explore the solutions provided for each exercise. If you have any questions or suggestions, please open an issue or pull request.

Happy coding!
