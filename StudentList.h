#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include <iostream>
using namespace std;

class Node
{


private:
	string ID,LastName,FirstName,Major,YearOB,MonthOB,DateOB,Address;
	double GPA;
	string phonenumber;
	Node *next;
	Node *previous;
	int index;
	

public:
	Node();
	int GetData();
	friend class DLinkedList;
};

class DLinkedList
{
private:
	int length;
	Node *head;
	Node *tail;
	
public:
	DLinkedList();
	~DLinkedList();
	int LengthIs();
	void MakeEmpty();
	void AddToTail(string, string, string, string, string, string, string, string, double, string );
	void DeleteFromHead();
	void Delete(string);
	void Swap(string,string);
	int GiveIndex(string);
	void OrderByIDDescending();
	void OrderByIDAscending();
	void OrderByGPAAscending();
	void OrderByGPADescending();
	void OrderByAge();
	bool IsOlder(Node*,Node*);
	void ListMajor(string);
	void PrintAll();
	void ListID(string);
	
};

#endif