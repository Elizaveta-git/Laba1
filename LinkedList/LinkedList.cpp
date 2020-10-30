#include "LinkedList.h"
#include <iostream>

using namespace std;

List::List()//list initiallization
{
	Size = 0;//list size
	head = NULL;//zeroing head element
}

List::~List()//clear list
{
	clear();
}

void List::push_back(int data)//insert element in the end of the list
{
	if (isEmpty() != 0)//insert first element if list is empty
	{
		head = new Node(data);//element creation
	}
	else//insert element in the end of the list
	{
		Node* current = head;//creation a new element
		while (current->Next != NULL)//while the next element exists, move throuth the list to the end
		{
			current = current->Next;
		}
		current->Next = new Node(data);//creating the last element
	}
	Size++;//increasing list size
}

void List::push_front(int data)//insert element at the beginning of the list
{
	head = new Node(data, head);
	Size++;//increasing list size
}

void List::insert(int data, size_t index)//insert element into the list by index
{
	if (isEmpty() == 1)
	{
		throw out_of_range("The list is empty"); 
	}
	else if (index >= Size) 
	{ 
		throw out_of_range("Index is greater than list size");
	}
	else if (index == 0)
	{ 
		push_front(data); 
	}
	else
	{
		Node* previous = this->head;//set the previous element
		for (int i = 0; i < index - 1; i++)//find the previous element
		{
			previous = previous->Next;
		}
		Node* current = new Node(data, previous->Next);//element creation by index
		previous->Next = current;
		Size++;//increasing list size
	}
}

int List::at(size_t index)//getting an element by index
{
	if (isEmpty() == 1) 
	{ 
		throw out_of_range("The list is empty"); 
	}
	else if (isEmpty() != 1 && index >= Size) 
	{ 
		throw out_of_range("Index is greater than list size"); 
	}
	else
	{
		Node* current = this->head;//go to the beginning of the list
		for (int i = 0; i < index; i++)//find the element by index
		{
			current = current->Next;
		}
		return current->data;//return the value of the element
	}
}

void List::print_to_console()//output the list to the console
{
	Node* current = this->head;//go to the beginning of the list
	while (current != NULL)//while new element exist
	{
		cout << current->data << endl;//display the value of the element
		current = current->Next;//move on to the next element
	}
}

bool List::isEmpty()//checking the list for emptiness
{
	if (head == NULL) return true;
	else return false;
}

void List::pop_front()//remove an element from the beginning of the list
{
	if (isEmpty() == 1) 
	{
		throw out_of_range("The list is empty");
	}
	else
	{
		Node* current = head;//remember the first element
		head = head->Next;//make the second element first
		delete current;//delete first element
		Size--;//reduce list size
	}
}

void List::remove(size_t index)//remove element by index
{
	if (isEmpty() == 1)
	{ 
		throw out_of_range("The list is empty"); 
	}
	else if (index >= Size) 
	{ 
		throw out_of_range("Index is greater than list size"); 
	}
	else if (index == 0) 
	{ 
		pop_front(); 
	}
	else
	{
		Node* previous = this->head;//set the previous element
		for (int i = 0; i < index - 1; i++)//find the previous element
		{
			previous = previous->Next;
		}
		Node* Del = previous->Next;//remember the element by index
		previous->Next = Del->Next;//redirect the connection
		delete Del;//remove element by index
		Size--;//reduce list size
	}
}

void List::pop_back()//remove an element in the end of the list
{
	if (isEmpty() == 1) 
	{
		throw out_of_range("The list is empty");
	}
	else
	{
		Node* previous = this->head;//set the previous element
		for (int i = 0; i < Size - 2; i++)//find the penultimate element
		{
			previous = previous->Next;
		}
		Node* Del = previous->Next;//remember the element in the end
		previous->Next = NULL;//set the end of the list
		delete Del;////remove element in the end
		Size--;//reduce list size
	}
}

void List::set(int data, size_t index)//set new element value by index
{
	if (isEmpty() == 1) 
	{
		throw out_of_range("The list is empty"); 
	}
	else if (index >= Size)
	{
		throw out_of_range("Index is greater than list size");
	}
	else
	{
		Node* current = this->head;//go to the beginning of the list
		for (int i = 0; i < index; i++)//find the element by index
		{
			current = current->Next;
		}
		current->data = data;//set new value
	}
}

void List::swap(size_t index1, size_t index2)//swap two elements in the list
{
	if (isEmpty() == 1) 
	{ 
		throw out_of_range("The list is empty"); 
	}
	else if (index1 >= Size || index2 >= Size) 
	{ 
		throw out_of_range("Index is greater than list size"); 
	}
	else if (index1 == index2)
	{
		throw out_of_range("Iindexes are equal");
	}
	else
	{
		Node* current1 = this->head;//go to the beginning of the list
		for (int i = 0; i < index1; i++)//find the first element by index
		{
			current1 = current1->Next;
		}
		Node* current2 = this->head;//go to the beginning of the list
		for (int i = 0; i < index2; i++)//find the second element by index
		{
			current2 = current2->Next;
		}
		Node* temp = new Node();//creating a new variable
		temp->data = current1->data;//remember the first element
		current1->data = current2->data;//write the value of the second element to the value of the first element
		current2->data = temp->data;//write the value of the first element to the value of the second element
	}

}

size_t List::get_size()//getting list size
{
	if (isEmpty() == 1)
	{
		throw out_of_range("The list is empty");
	}
	else return Size;
}

void List::clear()//clear list
{
	while (Size)
	{
		pop_front();
	}
}

void List::menu()
{
	cout << "Select an action: " << endl;
	cout << "1 - Add an item to the end of the list " << endl;
	cout << "2 - Add item to the beginning of the list " << endl;
	cout << "3 - Add item by index " << endl;
	cout << "4 - Get element by index " << endl;
	cout << "5 - Output of all list items " << endl;
	cout << "6 - Check the list for emptiness " << endl;
	cout << "7 - Remove all list items " << endl;
	cout << "8 - Remove the first element of the list " << endl;
	cout << "9 - Remove element by index " << endl;
	cout << "10 - Remove the last element of the list " << endl;
	cout << "11 - Replace element by index " << endl;
	cout << "12 - Swap two list items by indices " << endl;
	cout << "13 - Get list size " << endl;
	cout << "0 - Exit " << endl;
}

int List::interface(int exit)
{
	int data, index;
	switch (exit)
	{
		case 1:
		{
			cout << "Enter the value: ";
			cin >> data;
			push_back(data);
		} break;
		case 2:
		{
			cout << "Enter the value: ";
			cin >> data;
			push_front(data);
		} break;
		case 3:
		{
			cout << "Enter the value: ";
			cin >> data;
			cout << endl << "Enter the index: ";
			cin >> index;
			if (index-1 >= Size)
			{
				cout << "Index is greater than list size" << endl;
			} 
			else if (isEmpty())
			{
				cout << "List is empty" << endl;
			}
			else 
			{
				insert(data, index-1);
			}
			
		} break;
		case 4:
		{
			cout << endl << "Enter the index: ";
			cin >> index;
			if (index-1 >= Size)
			{
				cout << "Index is greater than list size" << endl;
			}
			else if (isEmpty())
			{
				cout << "List is empty" << endl;
			}
			else
			{
				cout << at(index-1);
			}
		} break;
		case 5:
		{
			print_to_console();
		} break;
		case 6:
		{
			if (isEmpty())
			{
				cout << "List is empty" << endl;
			} 
			else
			{
				cout << "List is not empty" << endl;
			}
		} break;
		case 7:
		{
			clear();
			cout << "List is clear" << endl;
		} break;
		case 8:
		{
			if (isEmpty())
			{
				cout << "List is empty" << endl;
			}
			else
			{
				pop_front();
			}
		} break;
		case 9:
		{
			cout << endl << "Enter the index: ";
			cin >> index;
			if (index-1 >= Size)
			{
				cout << "Index is greater than list size" << endl;
			}
			else if (isEmpty())
			{
				cout << "List is empty" << endl;
			}
			else
			{
				remove(index-1);
			}
		} break;
		case 10:
		{
			if (isEmpty())
			{
				cout << "List is empty" << endl;
			}
			else
			{
				pop_back();
			}
		} break;
		case 11:
		{
			cout << "Enter the value: ";
			cin >> data;
			cout << endl << "Enter the index: ";
			cin >> index;
			if (index-1 >= Size)
			{
				cout << "Index is greater than list size" << endl;
			}
			else if (isEmpty())
			{
				cout << "List is empty" << endl;
			}
			else
			{
				set(data, index-1);
			}
		} break;
		case 12:
		{
			cout << "Enter the index1: ";
			cin >> data;
			cout << endl << "Enter the index2: ";
			cin >> index;
			if (index-1 >= Size || data-1 >= Size)
			{
				cout << "Index is greater than list size" << endl;
			}
			else if (isEmpty())
			{
				cout << "List is empty" << endl;
			}
			else
			{
				swap(data-1, index-1);
			}
		} break;
		case 13:
		{
			cout << get_size();
		} break;
	}
	cout << endl <<  "++++++++List++++++++" << endl;
	print_to_console();
	cout << "++++++++++++++++++++" << endl;
	return exit;
}