#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

struct Node
{
	string key;
	string value;
	Node(const string& k, const string& v) : key(k), value(v) {}
};

class HashTable {
	vector<list<Node>>table;
	int table_size;
	int hash(const string& key)
	{
		int hashValue = 0;
		for (char ch : key) {
			hashValue = (hashValue * 31 + ch) % table_size;
		}
		return hashValue;
	}
public:
	HashTable(int size) : table_size(size) {
		table.resize(table_size);
	}
	void insert(const string& key, const string& value) {
		int index = hash(key);
		for (auto& node : table[index])
		{
			if (node.key == key) {
				node.value = value;
				return;
			}
		}
		table[index].emplace_back(key, value);
	}
	bool get(const string& key,  string& value)
	{
		int index = hash(key);
		for (auto& node : table[index]) {
			if (node.key == key) {
				value = node.value;
				return true;
			}
		}
		return false;
	}
	bool contains(const string& key) {
		int index = hash(key);
		for (auto& node : table[index]) {
			if (node.key == key) {
				
				return true;
			}
		}
		return false;
	}
	void remove(const string& key)
	{
		int index = hash(key);
		auto& nodeList = table[index];
		for (auto it = nodeList.begin(); it != nodeList.end(); ++it)
		{
			if (it->key == key)
			{
				nodeList.erase(it);
				return;
			}
		}

	}
};

int main() {
	HashTable ht(10);

	ht.insert("name", "Alice");
	ht.insert("age", "25");
	ht.insert("city", "New York");

	string value;
	if (ht.get("name", value)) {
		cout << "Name: " << value << endl;
	}
	else {
		cout << "Name not found" << endl;
	}

	if (ht.contains("age")) {
		cout << "Age key found" << endl;
	}
	else {
		cout << "Age key not found" << endl;
	}

	ht.remove("city");
	if (ht.get("city", value)) {
		cout << "City: " << value << endl;
	}
	else {
		cout << "City not found" << endl;
	}

	return 0;
}