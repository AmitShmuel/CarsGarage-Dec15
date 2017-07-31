// Garage header file

#ifndef _GARAGE_
#define _GARAGE_
#include "Customer.h"
#include "LinkList.h"

class Garage {
	
	customer_node* customers;
	customer_node* checkedInCustomers;
	car_node* carsIn;	
	double funds;
	
public:
	
	Garage();
	Garage(customer_node* , customer_node* , car_node* , double);
	Garage(const Garage&);
	Garage& operator=(const Garage&);
	~Garage();
	
	bool addCustomer(Customer*);
	bool checkInCar(Car&);
	bool checkOut(Customer&);
	double calculatePrice(const Car&);
	
	//setters
	void setCustomers(customer_node* ptr);
	void setCheckedInCustomers(customer_node*);
	void setCarsIn(car_node*);
	void setFunds(double);
	//getters
	double getFunds() const {return funds;}
	car_node* getCarsIn() const {return carsIn;}
	customer_node* getCustomers() const {return customers;}
	customer_node* getCheckedInCustomers() const {return checkedInCustomers;}
};

#endif
