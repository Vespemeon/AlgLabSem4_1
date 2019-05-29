#pragma once

#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <class T> class Node {

public:
	template <class T> friend class List;

	Node(T data) {
		this->data = data;
		this->next = nullptr;
	}

	~Node() {

	}

	Node<T> *next;
	T data;
};

template <class T> class List {

private:

	Node<T> *head;
	Node<T> *tail;

public:

	List() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	List(std::initializer_list<T> list) {
		this->head = nullptr;
		this->tail = nullptr;

		for (auto elem : list) {
			this->push_back(elem);
		}
	}

	~List() {
		clear();
	};

	void push_back(T data) {

		Node<T> *node = new Node<T>(data);

		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
	}

	void push_front(T data) {

		if (head == nullptr) {
			push_back(data);
		}
		else {
			Node<T> *node = new Node<T>(data);
			node->next = head;
			head = node;
		}
	}

	T pop_back() {
		if (tail == nullptr) {
			throw(std::out_of_range("Pop back empty list"));
		}

		if (tail == head) {
			T delData = tail->data;
			delete tail;
			tail = nullptr;
			head = nullptr;

			return delData;
		} 
		Node<T> *temp = head;
		while (temp->next != tail) {
			temp = temp->next;
		}
		T delData = tail->data;
		delete tail;

		tail = temp;
		tail->next = nullptr;
		
		return delData;
	}

	T pop_front() {

		if (head == nullptr) {
			throw(std::out_of_range("Pop front empty list"));
		}

		T delData;
		Node<T> *node = head->next;

		if (node == nullptr) {
			tail = nullptr;
		}

		delData = head->data;
		delete head;
		head = node;

		return delData;
	}

	size_t get_size() {

		size_t size = 0;
		Node<T> *node = head;
		while (node != nullptr) {
			node = node->next;
			++size;
		}
		return size;
	}

	void insert(T data, size_t index) {

		size_t listSize = get_size();

		if (head == nullptr) {
			throw(std::out_of_range("Insert empty list"));
		}
		if (int(index) < 0) {
			throw(std::invalid_argument("Insert negative argument"));
		}
		if (index + 1 > listSize) {
			throw(std::out_of_range("Insert nonexistent index"));
		}

		if (index == 0) {
			push_front(data);
		}
		else {

			Node<T> *prev = head;
			Node<T> *node = nullptr;

			for (size_t currInd = 0; currInd < index - 1; ++currInd) {
				//finding a node before addNode
				prev = prev->next;
			}
			node = prev->next;

			Node<T> *addNode = new Node<T>(data);
			prev->next = addNode;
			addNode->next = node;

			if (node == nullptr) {
				tail = addNode;
			}
		}
	}

	T at(size_t index) {

		if (head == nullptr) {
			throw(std::out_of_range("At empty list"));
		}
		if (int(index) < 0) {
			throw(std::invalid_argument("At negative argument"));
		}
		if (index + 1 > get_size()) {
			throw(std::out_of_range("At nonexistent index"));
		}

		Node<T> *node = head;

		for (size_t currInd = 0; currInd < index; ++currInd) {
			node = node->next;
		}

		return node->data;
	}

	T remove(size_t index) {

		size_t listSize = get_size();

		if (head == nullptr) {
			throw(std::out_of_range("Remove empty list"));
		}
		if (int(index) < 0) {
			throw(std::invalid_argument("Remove negative argument"));
		}
		if (index + 1 > listSize) {
			throw(std::out_of_range("Remove nonexistent index"));
		}

		if (index == 0) {
			pop_front();
		}
		else if (index == listSize) {
			pop_back();
		}
		else {
			Node<T> *node = head;

			for (size_t currInd = 0; currInd < index - 1; ++currInd) {
				node = node->next;
			}

			Node<T> *temp = node->next->next;

			delete node->next;
			node->next = temp;
		}
	}

	void clear() {

		if (head != nullptr) {

			Node<T> *node = head;
			Node<T> *toDelete = head;

			while (node != nullptr) {
				node = node->next;
				delete toDelete;
				toDelete = node;
			}
		}
	}

	void set(T data, size_t index) {

		if (head == nullptr) {
			throw(std::out_of_range("Set empty list"));
		}
		if (int(index) < 0) {
			throw(std::invalid_argument("Set negative argument"));
		}
		if (index + 1 > get_size()) {
			throw(std::out_of_range("Set nonexistent index"));
		}

		Node<T> *node = head;

		for (size_t currInd = 0; currInd < index; ++currInd) {
			node = node->next;
		}
		node->data = data;
	}

	bool isEmpty() {
		if (head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	friend std::ostream& operator<< (std::ostream &out, const List<T> &list) {
		Node<T> *node = list.head;

		while (node != nullptr) {
			std::cout << node->data;
			node = node->next;
			if (node != nullptr) {
				std::cout << ", ";
			}
		}

		return out;
	}
};