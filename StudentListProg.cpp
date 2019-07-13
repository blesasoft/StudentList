#include <iostream>
#include <string>
#include <stdlib.h>
#include "StudentList.h"
using namespace std;

void main()
{
		DLinkedList myList;
		Node result;
		string ID,lastname,firstname, phonenumber,major,yob,mob,dob,address;
		double gpa;
		myList.AddToTail("23","Blesa","Alberto","CS","1995","03","17","Madrid",3.90,"13456789");
		myList.AddToTail("09","Fernandez","Antonio","Biology","1995","03","04","Elm street",3.6,"222222222");
		myList.AddToTail("10","Ramirez","Juan Carlos","CS","1995","03","01","Cedar street",3.5,"444444444");
		myList.AddToTail("11","Gonzalez","Mariano","CS","1995","05","26","1st avenue",3.7,"555555555");
		myList.AddToTail("12","Garcia","Manuel","Art","1996","03","17","3rd avenue",3.8,"666666666");


while (1)
	{
		int select,select2;
		cout<<"SELECT A NUMBER FROM 1 TO 9"<<endl<<endl<<endl;
		cout<<"1) Insert a new record"<<endl;
		cout<<"2) Delete record/records with student ID"<<endl;
		cout<<"3) List all student information"<<endl;
		cout<<"4) Reorder all student information by ID"<<endl;
		cout<<"5) Reorder all student information by GPA"<<endl;
		cout<<"6) Reorder all student information by birthday"<<endl;
		cout<<"7) List all students given a major"<<endl;
		cout<<"8) List student given ID"<<endl;
		cout<<"9 EXIT"<<endl;
		cin>>select;
		system("cls");
		switch (select)
		{
		
		case 1:
			
			cout<<"Insert a new record"<<endl<<endl<<endl;
			cout<<"\nEnter the student ID: ";cin>>ID;
			cout<<"\nEnter the student's last name: ";cin>>lastname;
			cout<<"\nEnter the student's first name: ";cin>>firstname;
			cout<<"\nEnter the student's telephone number: ";cin>>phonenumber;
			cout<<"\nEnter the student's major: ";cin>>major;
			cout<<"\nEnter the student's GPA: ";cin>>gpa;
			cout<<"\nEnter the student's year of birth: ";cin>>yob;
			cout<<"\nEnter the student's month of birth: ";cin>>mob;
			cout<<"\nEnter the student's day of birth: ";cin>>dob;
			cout<<"\nEnter the student's address: ";cin>>address;

			myList.AddToTail(ID,lastname,firstname,major,yob,mob,dob,address,gpa,phonenumber);
			cout<<"Student added correctly"<<endl;
			
			system("pause");
			system("cls");
			break;
		case 2:
			
			cout<<"Delete record/records with student ID"<<endl<<endl;
			cout<<"Enter the student ID that you want to delete: ";
			cin>>ID;
			myList.Delete(ID);
			cout<<"Student with ID "<<ID<<" has been deleted."<<endl;
			system("pause");
			system("cls");
			
				
			break;
		case 3:
			cout<<"List all students information"<<endl<<endl;
		
			myList.PrintAll();
			system("pause");
			system("cls");
			
			break;
		case 4:
			cout<<"Press 1 for ascending order"<<endl;
			cout<<"Press 2 for descending order"<<endl;
			cin>>select2;

			switch (select2)
			{
			case 1:
				myList.OrderByIDAscending();
			cout<<"Students ordered by ascending ID."<<endl;
				break;
			case 2:
				myList.OrderByIDDescending();
			cout<<"Students ordered by descending ID."<<endl;
				break;
			default:
				cout<<"You have entered an invalid input"<<endl;
				break;
			}
			

			system("pause");
			system("cls");
			break;
		case 5:
			cout<<"Press 1 for ascending order"<<endl;
			cout<<"Press 2 for descending order"<<endl;
			cin>>select2;

			switch (select2)
			{
			case 1:
				myList.OrderByGPAAscending();
			cout<<"Students ordered by ascending GPA."<<endl;
				break;
			case 2:
				myList.OrderByGPADescending();
			cout<<"Students ordered by descending GPA."<<endl;
				break;
			default:
				cout<<"You have entered an invalid input"<<endl;
				break;
			}
			system("pause");
			system("cls");
			break;
		case 6:
			myList.OrderByAge();
			cout<<"Students ordered by Age"<<endl;
			
			system("pause");
			system("cls");
			break;
		case 7:
			cout<<"Enter a Major: ";
			cin>>major;
			myList.ListMajor(major);

			system("pause");
			system("cls");
			break;
		case 8:
			cout<<"Enter the ID: ";
			cin>>ID;
			myList.ListID(ID);
			system("pause");
			system("cls");
			break;
		case 9:
			exit(0);
			break;
		default:
			cout<<"You have entered an invalid input"<<endl;
			break;
		}
	}
}
