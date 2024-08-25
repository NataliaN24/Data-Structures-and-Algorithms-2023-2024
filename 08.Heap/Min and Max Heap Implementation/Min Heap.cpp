#include <iostream>
#include <vector>

using namespace std;

class MinHeap 
{
	vector<int>heap;

public:
	void push(int val)
	{
		heap.push_back(val);
		int index = heap.size() - 1;
		int parentIndex = (index - 1) / 2;

		while (index > 0 && heap[index] < heap[parentIndex])
		{
			std::swap(heap[index], heap[parentIndex]);
			index = parentIndex;
			parentIndex = (index - 1) / 2;
		}
	}

	int pop()
	{
		if (heap.empty())
		{
			throw std::out_of_range("Heap is empty");
		}
		int minVal = heap.front();
		heap[0] = heap.back();
		heap.pop_back();

		int index = 0;
		while (true)
		{
			int leftChild = 2 * index + 1;
			int rightChild = 2 * index + 2;
			int smallest = index;

			if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
			{
				smallest = leftChild;
			}
			if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
			{
				smallest = rightChild;
			}
			if (smallest != index)
			{
				swap(heap[index], heap[smallest]);
				index = smallest;
			}
			else
			{
				break;
			}
		}
		return minVal;
	}

	int peek()const
	{
		if (heap.empty())
		{
			throw std::out_of_range("Heap is empty");
		}
		return heap.front();
	}

	int size()const
	{
		return heap.size();
	}

	bool isEmpty() const 
	{
		return heap.empty();
	}

	void print()const
	{
		for (int val : heap)
		{
			cout << val << " ";
		}
		cout << endl;
	}

};

int main() {
	MinHeap minHeap;

	minHeap.push(10);
	minHeap.push(5);
	minHeap.push(20);
	minHeap.push(3);
	minHeap.push(8);

	minHeap.print();

	std::cout << "Min element (peek): " << minHeap.peek() << std::endl;

	std::cout << "Popping elements: ";
	while (!minHeap.isEmpty()) {
		std::cout << minHeap.pop() << " ";
	}
	std::cout << std::endl;

	return 0;
}