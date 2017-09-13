// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
   #include <string>

using namespace std;

template<class T>
class Node
{
	public:
	Node();
	Node(const T& item, Node<T>* ptrnext = NULL);
	T value;
	Node<T> * next;
	Node<T> * prev;
};

template<class T>
Node<T>::Node()
{
    value = NULL;
    next = NULL;
	prev = NULL;
}

template<class T>
Node<T>::Node(const T& item, Node<T>* ptrnext = NULL)
{
    this->value = item;
    this->next = ptrnext;
}

template<class T>
class LinkedListClass
{
private:
    Node<T> * Front;
    Node<T> * Rear;
    int Count;
public:
    LinkedListClass();
    ~LinkedListClass();
    void InsertFront(const T Item);
    void InsertRear(const T Item);
    int GetNumber();
	void PrintListFromFront();
	void PrintListFromRear();
};

template<class T>
LinkedListClass<T>::LinkedListClass()
{
    Front = NULL;
    Rear = NULL;
}

template<class T>
void LinkedListClass<T>::InsertFront(const T  Item)
{
	Node<T> * newNode = new Node<T>();
	newNode->value = Item;
  
	if (Front == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
		Front = newNode;
        Rear = newNode;
    }
    else
    {
        newNode->next = Front;
		newNode->prev = NULL;
		Front->prev = newNode;
        Front = newNode;
    }
}

template<class T>
void LinkedListClass<T>::InsertRear(const T  Item)
{
	Node<T> * newNode = new Node<T>();
	newNode->value = Item;

	if (Rear == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
		Front = newNode;
        Rear = newNode;
    }
    else
    {
		newNode->next = NULL;
		newNode->prev = Rear;
        Rear->next = newNode;
        Rear = newNode;
    }
}

template<class T>
void LinkedListClass<T>::PrintListFromFront()
{
    Node<T> *  temp = Front;
    while (temp != NULL)
    {
        cout << " " << temp->value << " ";
        temp = (temp->next);
    }
	cout << endl;
}

template<class T>
void LinkedListClass<T>::PrintListFromRear()
{
    Node<T> *  temp = Rear;
    while (temp != NULL)
    {
        cout << " " << temp->value << " "; 
        temp = (temp->prev);
    }
	cout << endl;
}

template<class T>
int LinkedListClass<T>::GetNumber()
{
	//342
	int result=0;
	int multiplier=1;
    Node<T> *  temp = Front;
    while (temp != NULL)
    {
		//cout << " R: " << result << " M: " << multiplier << " V: " << temp->value; 
        result = result + temp->value*multiplier;
		multiplier=multiplier*10;
		//cout << " R: " << result << " M: " << multiplier << endl; 
        temp = (temp->next);
    }
	return result;
}


int _tmain(int argc, _TCHAR* argv[])
{
//Add two number. https://leetcode.com/problems/add-two-numbers/description/
//Prepared two numbed linked list. Each represent digit. Digit are store in rever order.
//342 stored as 2->4->3. 465 stored as 5->6->4
//Sum both number. and restore sum again in reverse order link list.

        LinkedListClass<int> * no1 = new LinkedListClass<int>();
		no1->InsertRear(2);
        no1->InsertRear(4);
        no1->InsertRear(3);
		//no1->PrintListFromFront();
		//no1->PrintListFromRear();
		int rno1= no1->GetNumber();
		cout << "Value of No1: " << rno1 << endl;

		LinkedListClass<int> * no2 = new LinkedListClass<int>();
		no2->InsertRear(5);
        no2->InsertRear(6);
        no2->InsertRear(4);
		//no2->PrintListFromFront();
		//no2->PrintListFromRear();
		int rno2= no2->GetNumber();
		cout << "Value of No2: " << rno2 << endl;

		int rno= rno1+rno2;
		cout << "Result is : " << rno << endl;

		LinkedListClass<int> * no = new LinkedListClass<int>();
		while(rno>1)
		{
			int reminder=rno%10;
			rno=rno/10;
			//cout << " Rmi: " << reminder << " RNO: " << rno << endl; 
			no->InsertRear(reminder);
		}
		no->PrintListFromFront();
		//no->PrintListFromRear();
		return 0;
}

