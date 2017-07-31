// Assignment 2: Car class - Upgraded
// made by Amit Shmuel - 305213621

#include <iostream>
#include "FileParser.h"
#include "Menu.h"
using namespace std;


int main(int argc, char** argv) {
	
	
	FileParser parser;
	car_node* carList;
	customer_node* customerList;
	
	carList = parser.parseCarFile(argv[1]);
	customerList = parser.parseCustomerFile(argv[2]);
	
	customer_node* temp = customerList;
	while(temp != 0)
	{
		temp->data->setCurrCar(carList->Find(carList , temp->data->getId())->data); // setting each customer with his car 
		temp = temp->next;
	}
	
	Garage* garage = new Garage(customerList , 0 , 0 , 0); // creating a garage with the given customer list from the file, checked in customers and cars are null..

	int choice;
	do 
	{
		printWelcome(garage);
		cin >> choice;
		switch(choice)
		{
			case 1:	
					Case1(garage); // prints existing customers and offers to check-in their cars
					break;				
			case 2:	
					Case2(garage); // prints checked-in cars and offers to repair them
					break;			
			case 3:			
					Case3(garage); // prints checked-in customers and offers to repair their cars
					break;									
			case 4:	
					printBye();
					break;			
			default:
					printErr();
		}
	}
	while(choice != 4);

	delete garage;
	carList->FreeList(carList);
	
	system ("PAUSE");
	return 0;
}
