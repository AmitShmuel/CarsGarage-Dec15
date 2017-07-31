#include <iostream>
#include "Menu.h"
using namespace std;



void printWelcome(Garage* G) {
	
	cout << "===========================================================================\n===========================================================================\n";
	cout << "Welcome to the Garage!			(Garage's funds: " << G->getFunds() << "$)\nWhat would you like to do?\n\n[1] Choose a customer and check if his car has a problam\n\n[2] Printing checked-in cars\n\n[3] Printing checked-in customers\n\n[4] Exit\n\n";
}


void printBye() {
	
	cout << "Good Bye !\n\n";
}

void printErr() {
	
	cout << "There is not such option !\n\n";
}



void Case1(Garage* G1) {
	
		
	if(G1->getCustomers()->Print_list(G1->getCustomers()) == false) 
	{		
		cout << "***\nThere are no customers in this garage..\n***\n"; 
		return;
	}
	
	int chooseCustomer;			
	do {
		
		cout << "\nWhich customer's car would you like to check?\nPress 0 to return to the main menu.\n";
		int exit = 0;
		cin >> chooseCustomer;
		if(chooseCustomer == 0)
			return;
		
		customer_node* nodePtr = G1->getCustomers()->findByPosition(G1->getCustomers() , chooseCustomer);
		
		if(nodePtr == 0) 
		{	
			cout << "***\ncustomer doesnt exist, please choose again\n***\n";
			exit = 1;
		}
			
		else 
		{
			Car* carPtr = nodePtr->data->getCurrCar();
			if(carPtr == 0) 
			{
				cout << "***\nThis customer doesn't have a car, or his car is already in the garage.\nPlease choose another customer.\n***\n";
				exit = 1;
			}
			
			else
			{
				if(carPtr->malfunctions() == 0) 
				{
					cout << "***\nThere is not a problam with this customer's car..\n***\n";
					exit = 1;
				}
				
				else 
				{
					cout << "***\nThere is a problam with this car, Would you like to deposit it for repair?\n***\n[1] Yes\n[2] No\n";
					int yesOrNo;
					do
					{
						cin >> yesOrNo;
						if(yesOrNo == 2)
							break;
								
						else if(yesOrNo == 1)
						{
							Customer& customerRef = *(G1->getCustomers()->findByPosition(G1->getCustomers() , chooseCustomer)->data);
								
							if(customerRef.getFunds() > G1->calculatePrice(*carPtr)) {
								
								if(G1->checkInCar(*carPtr) == false)
									cerr << "***\nThere is a problam checking-in the car\n***\n\n";
								else
									cout << "***\nCar and customer were successfully checked in !\n***\n\n";
								return;
							}
											
							else
							{
								cout << "***\nThis customer's funds are not sufficient for paying for the repair..\n***\n\n";
								return;
							}
						}
					}	
					while(1);				
				}	
			}
		}
	}
	while(exit);
}




void Case2(Garage* G1) {
	
	if(G1->getCarsIn()->Print_list(G1->getCarsIn()) == false) 
	{			
		cout << "***\nThere are no checked in cars in the garage..\n***\n\n";
		return;
	}
	
	int chooseCar;
	do {
		
		int exit = 0;
		cout << "\nWhich car would you like to repair?\nPress 0 to return to the main menu\n";
		cin >> chooseCar;
		
		if(chooseCar == 0)
			return;
			
		customer_node* nodePtr = G1->getCheckedInCustomers()->findByPosition(G1->getCheckedInCustomers() , chooseCar);
	
		if(nodePtr == 0)
		{
			cout << "***\nCar doesn't exist, please choose another car.\n***\n";
			exit = 1;
		}
		
		else
		{
			if(G1->checkOut(*nodePtr->data) == false )
			{
				cerr << "***\nThere is a problam checking-out the car\n***\n\n";
				return;
			}
		
			else
			{
				cout << "***\nCar and customer were successfully checked-out !\n***\n\n";
				return;
			}	
		}
	}
	while(exit);
}




void Case3(Garage* G1) {
	
	if(G1->getCheckedInCustomers()->Print_list(G1->getCheckedInCustomers()) == false)
	{		
		cout << "***\nThere are no checked-in customers in the garage..\n***\n\n";
		return; 
	}
	
	int chooseCar;		
	do {
	
		int exit = 0;	
		cout << "\nWhich customer's car would you like to repair?\nPress 0 to return to the main menu\n";
		cin >> chooseCar;
		if(chooseCar == 0)
			return;
			
		customer_node* nodePtr = G1->getCheckedInCustomers()->findByPosition(G1->getCheckedInCustomers() , chooseCar);
		
		if(nodePtr == 0)
		{
			cout << "***\nCustomer doesn't exist, please choose another customer..\n***\n\n";
			exit = 1;
		}
		
		else
		{
			if(G1->checkOut(*nodePtr->data) == false) 
			{
				cerr << "***\nThere was a problam checking-out the car\n***\n\n";
				return;
			}
		
			else
			{
				cout << "***\nCar and customer were successfully checked-out !\n***\n\n";
				return;
			}
		}
		
	}
	while(exit);
}
