#include <bits/stdc++.h>

using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

struct DoublyListNode
{
	int val;
	DoublyListNode *prev;
	DoublyListNode *next;
	DoublyListNode(int n) : val(n), prev(NULL), next(NULL) {}
};

class LRUCache
{
private:
	unordered_map<int, int> record;
	unordered_map<int, DoublyListNode *> positions;
	DoublyListNode *anchor;
	int size;
public:
	LRUCache(int capacity)
	{
		size = capacity;
		anchor = new DoublyListNode(-1);
		anchor->next = anchor;
		anchor->prev = anchor;
	}

	int get(int key)
	{
		if (!record.count(key))
			return -1;
		DoublyListNode *ptr = positions[key];
		// remove
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		// insert
		ptr->next = anchor->next;
		ptr->next->prev = ptr;
		anchor->next = ptr;
		ptr->prev = anchor;
		return record[key];
	}

	void put(int key, int value)
	{
		if (record.count(key))
		{
			record[key] = value;
			get(key);
			return;
		}
		if (record.size() == size)
		{
			int drop_key = anchor->prev->val;
			record.erase(drop_key);
			positions.erase(drop_key);
			anchor->prev = anchor->prev->prev;
			anchor->prev->next = anchor;
		}
		DoublyListNode *new_elem = new DoublyListNode(key);
		record[key] = value;
		positions[key] = new_elem;
		// insert
		anchor->next->prev = new_elem;
		new_elem->next = anchor->next;
		anchor->next = new_elem;
		new_elem->prev = anchor;
		return;
	}
};
