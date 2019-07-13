#include "StudentList.h"
#include <string>
#include <iostream>
using namespace std;

Node::Node()
{
	next = previous = 0;
}



DLinkedList::DLinkedList()
{
	length = 0;
	head = tail = 0;
	
}

int DLinkedList::LengthIs()
{
	return length;
}

void DLinkedList::AddToTail(string ID, string LastName, string FirstName, string Major, string Year, string Month, string Date, string Address, double GPA, string phone)
{
	Node *ptr = new Node();
	ptr->ID = ID;
	ptr->LastName = LastName;
	ptr->FirstName = FirstName;
	ptr->Major= Major;
	ptr->YearOB = Year;
	ptr->MonthOB = Month;
	ptr->DateOB = Date;
	ptr-> Address = Address;
	ptr->GPA = GPA;
	ptr->phonenumber = phone;

	if(tail==0)
	{
		tail = ptr;
		head = ptr;
		length++;
		return;
	}
	tail->next = ptr;
	length++;
	ptr->previous = tail;
	tail = ptr;
}

void DLinkedList::DeleteFromHead()
{
	if(length==0) return;
	Node *ptr = head->next;
	delete head;
	head = ptr;
	length--;
	if(length==0) tail = 0;
	if(head) head->previous = 0;
}
void DLinkedList::Delete(string ID)
{
	Node *current = head;
	Node *pre = head;
	if(head&&(head->ID.compare(ID)==0)) 
	{
		DeleteFromHead();
		return;
	}
	for(int i=0;i<length;i++)
	{
		if(current->ID.compare(ID)==0) 
		{
			if(current->next) (current->next)->previous = current->previous;
			(current->previous)->next = current->next;
			if(current->next == 0) tail = current->previous;
			delete current;
			length--;
			
			break;
		}
		
		current = current->next;
	}
}

void DLinkedList::Swap(string id1,string id2)
{ 
	int index1= GiveIndex(id1);
	int index2=GiveIndex(id2);

	if(index1<length)
	{
		if(index2<length)
		{
		string tempID;
		string tempLastName;
		string tempFirstName;
		string tempMajor;
		string tempYear;
		string tempMonth;
		string tempDate;
		string tempAddress;
		double tempGPA;
		string tempphone;


		Node *current1=head;
		Node *current2=head;

		for(int i=0;i<index1;i++)
		{
		current1=current1->next;
		}
		for(int j=0;j<index2;j++)
		{
		current2=current2->next;
		}
		//temp1=current1->data;

		tempID=current1->ID;
		tempLastName=current1->LastName;
		tempFirstName=current1->FirstName;
		tempMajor=current1->Major;
		tempYear=current1->YearOB;
		tempMonth=current1->MonthOB;
		tempDate=current1->DateOB;
		tempAddress=current1->Address;
		tempGPA=current1->GPA;
		tempphone=current1->phonenumber;

		//current1->data=current2->data;

		current1->ID=current2->ID;
		current1->LastName=current2->LastName;
		current1->FirstName=current2->FirstName;
		current1->Major=current2->Major;
		current1->YearOB=current2->YearOB;
		current1->MonthOB=current2->MonthOB;
		current1->DateOB=current2->DateOB;
		current1->Address=current2->Address;
		current1->GPA=current2->GPA;
		current1->phonenumber=current2->phonenumber;

		//current2->data=temp1;
		current2->ID=tempID;
		current2->LastName=tempLastName;
		current2->FirstName=tempFirstName;
		current2->Major=tempMajor;
		current2->YearOB=tempYear;
		current2->MonthOB=tempMonth;
		current2->DateOB=tempDate;
		current2->Address=tempAddress;
		current2->GPA=tempGPA;
		current2->phonenumber=tempphone;


		}
		else{cout<<"Not possible to swap "<<index1<<" and "<<index2<<". \n";
		return;}

		
	}
}
int DLinkedList::GiveIndex(string value)
{
	int rank = 0;
	Node *current = head;
	for(rank=0;rank<length;rank++)
	{
		if(current->ID.compare(value)==0) return rank;//way to compare if the ID matches the value
		current = current->next;
	}
	return -1;
}
void DLinkedList::PrintAll()
{
	Node *current=head;
	//while(current)
	for(int i=0;i<length;i++)
	{
		cout<<"ID: "<<current->ID<<", First Name: "<<current->FirstName<<", Last Name: "<<current->LastName<<", "<<"Major: "<<current->Major<<endl;
		cout<<"Date of bith: "<<current->MonthOB<<"/"<<current->DateOB<<"/"<<current->YearOB<<", Adress: "<<current->Address<<", GPA: "<<current->GPA<<", Phone #: "<<current->phonenumber<<"."<<endl<<endl;
		current=current->next;
	}
}
void DLinkedList::OrderByIDDescending()
{
	Node * current = head;
		
	for (int j=0; j<length; j++)
	{
		while (current->next)  
		{
			
			if (current->ID.compare(current->next->ID)<0)
			{
				Swap(current->ID,current->next->ID);
			}
			else 
				current = current->next;
		}	
		current = head;
	}

}
void DLinkedList::OrderByIDAscending()
{
	Node * current = head;
		
	for (int j=0; j<length; j++)
	{
		while (current->next)  
		{
			
			if (current->ID.compare(current->next->ID)>0)
			{
				Swap(current->ID,current->next->ID);
			}
			else 
				current = current->next;
		}	
		current = head;
	}

}

void DLinkedList::OrderByGPAAscending()
{
	Node * current = head;
		
	for (int j=0; j<length; j++)
	{
		while (current->next)  
		{
			
			if (current->GPA>current->next->GPA)
			{
				Swap(current->ID,current->next->ID);
			}
			else 
				current = current->next;
		}	
		current = head;
	}
}
void DLinkedList::OrderByGPADescending()
{
	Node * current = head;
		
	for (int j=0; j<length; j++)
	{
		while (current->next)  
		{
			
			if (current->GPA<current->next->GPA)
			{
				Swap(current->ID,current->next->ID);
			}
			else 
				current = current->next;
		}	
		current = head;
	}
}
void DLinkedList::OrderByAge()
{
	Node * current = head;
		
	for (int j=0; j<length; j++)
	{
		while (current->next)  
		{
			
			if (IsOlder(current,current->next))
			{
				Swap(current->ID,current->next->ID);
			}
			current = current->next;
		}	
		current = head;
	}
}

bool DLinkedList::IsOlder(Node *a,Node *b)
{
	Node * nodea = a;
	Node * nodeb = b;
	

	if(nodea->YearOB.compare(nodeb->YearOB)<0){return 1;}
	else{if(nodea->YearOB.compare(nodeb->YearOB)>0){return 0;}
		else//at this point the both students were born in the same year
		{
			if(nodea->MonthOB.compare(nodeb->MonthOB)<0){return 1;}
			else{if(nodeb->MonthOB.compare(nodea->MonthOB)<0){return 0;}
			else//at this point the both students were born in the same year and month
			{
				if(nodea->DateOB.compare(nodeb->DateOB)<0){return 1;}
			else{if(nodeb->DateOB.compare(nodea->DateOB)<0){return 0;}
			}}}}}////////////////continue here
	//in this case the students have the same date of birth so we do not care wich one goes first
	return 1;
}
void DLinkedList::ListMajor(string major)
{
	Node *current = head;

	while (current)
	{
		if(current->Major.compare(major)==0)
			{
				cout<<"ID: "<<current->ID<<", First Name: "<<current->FirstName<<", Last Name: "<<current->LastName<<", "<<"Major: "<<current->Major<<", "<<endl;
				cout<<"Date of birth(month/day/year): "<<current->MonthOB<<"/"<<current->DateOB<<"/"<<current->YearOB<<", Adress: "<<current->Address<<", GPA: "<<current->GPA<<", Phone number: "<<current->phonenumber<<"."<<endl<<endl;
			}
		
			current=current->next;
		
	
	}

}
void DLinkedList::ListID(string major)
{
	Node *temp = head;

	while (temp)
	{
		if(temp->ID.compare(major)==0)
			{
				cout<<"ID: "<<temp->ID<<", First Name: "<<temp->FirstName<<", Last Name: "<<temp->LastName<<", "<<"Major: "<<temp->Major<<", "<<endl;
				cout<<"Date of birth(month/day/year): "<<temp->MonthOB<<"/"<<temp->DateOB<<"/"<<temp->YearOB<<", Adress: "<<temp->Address<<", GPA: "<<temp->GPA<<", Phone number: "<<temp->phonenumber<<"."<<endl<<endl;
			}
		temp=temp->next;
	
	}

}



void DLinkedList::MakeEmpty()
{
	while(length>0) DeleteFromHead();
}

DLinkedList::~DLinkedList()
{
	MakeEmpty();
}
/*void DLinkedList::AddToHead(int value)
{
	Node *ptr = new Node();
	ptr->data = value;

	length++;
	ptr->next = head;
	if(head) head->previous = ptr;
	head = ptr;
	if(length==1) tail = ptr;
}




int DLinkedList::RetrieveAt(int index)
{
	if(index>=length){return -999;}
	else
	{
		Node *current=head;
		for(int i=0;i<index;i++)
		{
		current=current->next;
		}
		return current->data;
	}
}
void DLinkedList::DeleteAt(int index)
{
	if(index<length)
	{
		Node *current=head;
		for(int i=0;i<index;i++)
		{
		current=current->next;
		}
		Delete(current->data);	
	}
	else{return;}
}
void DLinkedList::Swap(int index1,int index2)
{
	if(index1<length)
	{
		if(index2<length)
		{
		int temp1;
		Node *current1=head;
		Node *current2=head;

		for(int i=0;i<index1;i++)
		{
		current1=current1->next;
		}
		for(int j=0;j<index2;j++)
		{
		current2=current2->next;
		}
		temp1=current1->data;
		current1->data=current2->data;
		current2->data=temp1;
		}
		else{//cout<<"Not possible to swap "<<index1<<" and "<<index2<<". \n";
		return;}

		
	}
	else{//cout<<"Not possible to swap "<<index1<<" and "<<index2<<". \n";
		return;}
}



void DLinkedList::DeleteFromTail()
{
	if(length==0) return;
	tail = tail->previous;
	if(tail) delete tail->next;
	else delete head;
	if(tail) tail->next = 0;
	length--;	
	if(length==0)
	{
		head=tail=0;
		return;
	}
	
}







void DLinkedList::InsertAtRank(int rank,int value)
{
	if(rank>=length)
	{
		AddToTail(value);
		return;
	}
	else if(rank<=0)
	{
		AddToHead(value);
		return;
	}
	Node *ptr = new Node();
	ptr->data = value;
	Node *current = head;
	for(int i=0;i<rank-1;i++) current=current->next;
	ptr->next =current->next;
	ptr->previous = current;
	current->next->previous = ptr;
	current->next  = ptr;
	length++;
}*/