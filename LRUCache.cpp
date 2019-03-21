#pragma once
#pragma once

#include <iostream>
#include <map>
#include <unordered_map>
#include <new>

using namespace std;

template <typename Key, typename T>
struct Node
{
	Node<Key, T>* prev;
	Node<Key, T>* next;
	T value;
	Key key;
};

template <typename Key, typename T>
class LRUCache
{
public:
	LRUCache();
	LRUCache(int32_t maxcount = 50);
	~LRUCache();

	void setNode(Key Uindex, T value);
	T* getNode(Key Uindex);

protected:
	void detachNode(Node<Key, T>* elem);
	void attachNode(Node<Key, T>*pos, Node<Key, T>*elem);
public:

	typedef T return_type;


	void displayeTable() {
		for (auto it = hash_key_map.begin(); it != hash_key_map.end(); it++) {
			cout << hex << (void*)it->second << endl;
		}
	
	}


private:
	int32_t capacity;
	int32_t size;
	std::unordered_map<Key, Node<Key, T>*> hash_key_map;
	Node<Key, T>* head;
	Node<Key, T>* tail;
	Node<Key, T>* start;
};

template <typename Key, typename T>
LRUCache<Key, T>::LRUCache()
{

}

template <typename Key, typename T>
LRUCache<Key, T>::LRUCache(int32_t maxcount)
{
	capacity = maxcount;
	size = 0;
	head = tail = NULL;
	Node<Key, T> *cur = NULL;

	Node<Key, T> *temp = new Node<Key, T>[capacity];
	start = temp;

	for (int32_t i = 0; i < maxcount; i++) {
		(temp[i]).prev = NULL;
		(temp[i]).next = NULL;

		if (head == NULL) {
			cur = tail = head = &(temp[i]);
		}
		else {
			cur->next = &(temp[i]);
			cur->next->prev = cur;
			cur = cur->next;
			tail = cur;
		}
	}
}

template<typename Key, typename T>
LRUCache<Key, T>::~LRUCache()
{
	capacity = 0;
	size = 0;
	hash_key_map.clear();
	delete[]start;
	head = NULL;
	tail = NULL;
}

template<typename Key, typename T>
T* LRUCache<Key, T>::getNode(Key index)
{
	auto it = hash_key_map.find(index);
	if (it == hash_key_map.end())
		return NULL;

	detachNode(it->second);
	attachNode(head, it->second);

	return &(it->second->value);
}

template<typename Key, typename T>
void LRUCache<Key, T>::setNode(Key index, T value)
{
	auto it = hash_key_map.find(index);
	if (it == hash_key_map.end()) {
		Key oldkey = tail->key;

		tail->key = index;
		tail->value = value;

		Node<Key, T>* elem = tail;

		detachNode(elem);
		attachNode(head, elem);
		hash_key_map[index] = elem;

		if (size >= capacity) {
			hash_key_map.erase(oldkey);
			size = capacity;
		}
		else {
			size++;
		}
	}
	else {
		it->second->value = value;

		detachNode(it->second);
		attachNode(head, it->second);
	}
}

template<typename Key, typename T>
void LRUCache<Key, T>::detachNode(Node<Key, T>* elem)
{
	if (elem == head) {
		head = elem->next;
		head->prev = NULL;
	}
	else if (elem == tail) {
		tail = elem->prev;
		tail->next = NULL;
	}
	else {
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
	}

	elem->prev = NULL;
	elem->next = NULL;
}

template<typename Key, typename T>
void LRUCache<Key, T>::attachNode(Node<Key, T>*pos, Node<Key, T>*elem)
{
	if (pos == head) {
		head->prev = elem;
		elem->next = head;
		head = elem;
	}
	else {
		elem->prev = pos->prev;
		elem->next = pos;
		pos->prev = elem;
	}
}