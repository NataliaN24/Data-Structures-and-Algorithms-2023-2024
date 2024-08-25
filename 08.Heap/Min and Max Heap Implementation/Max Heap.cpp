#include <iostream>
#include <vector>

class MaxHeap {
    std::vector<int> heap;

public:
    void push(int val) {
        
        heap.push_back(val);

        int index = heap.size() - 1;
        int parentIndex = (index - 1) / 2;

        while (index > 0 && heap[index] > heap[parentIndex]) {
            std::swap(heap[index], heap[parentIndex]);
            index = parentIndex;
            parentIndex = (index - 1) / 2;
        }
    }

    int pop() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        int maxVal = heap.front();
        heap[0] = heap.back();
        heap.pop_back();

        int index = 0;
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }
            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            }
            else {
                break;
            }
        }

        return maxVal;
    }

    int peek() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap.front();
    }

    int size() const {
        return heap.size();
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void printHeap() const {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MaxHeap maxHeap;

    maxHeap.push(10);
    maxHeap.push(5);
    maxHeap.push(20);
    maxHeap.push(3);
    maxHeap.push(8);

    maxHeap.printHeap();

    std::cout << "Max element (peek): " << maxHeap.peek() << std::endl;

    std::cout << "Popping elements: ";
    while (!maxHeap.isEmpty()) {
        std::cout << maxHeap.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}