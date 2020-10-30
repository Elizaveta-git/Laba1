#pragma once
#include <iostream>

class List
{
public:
	List();
	~List();

	void push_back(int data);
	void push_front(int data);
	void insert(int data, size_t index);
	int at(size_t index);
	void print_to_console();
	bool isEmpty();
	void clear();
	void pop_front();
	void remove(size_t index);
	void pop_back();
	void set(int data, size_t index);
	void swap(size_t index1, size_t index2);
	size_t get_size();
	void menu();
	int interface(int exit);

private:

	class Node
	{
	public:
		Node* Next;//pointer to the next element in the list
		int data;//element value

		Node(int data = int(), Node* Next = NULL)//creating element
		{
			this->data = data;
			this->Next = Next;
		}
	};
	int Size;//list size
	Node* head;//pointer to the head of the list
};