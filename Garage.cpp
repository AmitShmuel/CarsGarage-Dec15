#include <iostream>
#include <cstring>
#include "Garage.h"
using namespace std;



Garage::Garage() {
	
	//cout << "** Default C'tor of Garage has been called **\n\n";
	
	setCustomers(0);
	setCheckedInCustomers(0);
	setCarsIn(0);
	setFunds(0);
}


Garage::Garage(customer_node* customersList , customer_node* checkedInCustomersList , car_node* checkedInCarsList , double _float) {
	
	//cout << "** None - default C'tor of Garage has been called **\n\n";
	
	setCustomers(customersList);
	setCheckedInCustomers(checkedInCustomersList);
	setCarsIn(checkedInCarsList);
	setFunds(_float);
}


Garage::Garage(const Garage& g) {
	
	//cout << "** Copy C'tor of Garage has been called! **\n\n";
	setCustomers(g.customers);
	setCheckedInCustomers(g.checkedInCustomers);
	setCarsIn(g.carsIn);
	setFunds(g.funds);
}

Garage& Garage::operator=(const Garage& g) {
	
	//cout << "** Operator = of Garage has been caleed! **\n\n";
	
	if(this == &g)
		return *this;
	
	if(customers != 0)
		delete customers;
	if(checkedInCustomers != 0)
		delete checkedInCustomers;
	if(carsIn != 0)
		delete carsIn;
	
	setCustomers(g.customers);
	setCheckedInCustomers(g.checkedInCustomers);
	setCarsIn(g.carsIn);
	setFunds(g.funds);
	
	return *this;
}

Garage::~Garage() {
	
	//cout << "** D'tor of Garage has been called! **\n\n";
	if(customers != 0)
		customers->FreeList(customers);
	if(checkedInCustomers != 0)
		checkedInCustomers->FreeList(checkedInCustomers);
	if(carsIn != 0)
		carsIn->FreeList(carsIn);
}


void Garage::setCustomers(customer_node* ptr) {customers = ptr;}

void Garage::setCheckedInCustomers(customer_node* ptr) {checkedInCustomers = ptr;}

void Garage::setCarsIn(car_node* ptr) {carsIn = ptr;}

void Garage::setFunds(double _funds) {funds = _funds;}



double Garage::calculatePrice(const Car& c) {

	int repair = 500;
	return c.malfunctions() * repair;
}



bool Garage::addCustomer(Customer* a) {
	
	customers = customers->Add_head(customers, a);
	if(customers == 0) {
		cerr << "Garage addCustomer : Allocation error for customer!\n"; return false;}
	return true;
}



bool Garage::checkInCar(Car& c) {
	
	if(c.getOwner() == 0)
		return false;
		
	checkedInCustomers = checkedInCustomers->Add_head(checkedInCustomers , (customers->Find(customers , c.getOwner()))->data);
	if(checkedInCustomers == 0) {
		cerr << "Garage checkInCar : Allocation error when checking in customer !\n\n"; return false;}
		
	carsIn = carsIn->Add_head(carsIn , &c);
	if(carsIn == 0) {
		cerr << "Garage checkInCar : Allocation error when checking in car !\n\n"; return false;}	
		
	(customers->Find(customers , c.getOwner()))->data->setCurrCar(0);
	
	c.setInShop(true);
	return true;
}



bool Garage::checkOut(Customer& c) {
	
	car_node* ptr = carsIn->Find(carsIn , c.getId());
	if(ptr == 0) {
		cerr << "Couldn't find customer's car!\n"; return false;}
	int price = calculatePrice(*(ptr->data));
	funds += price;
	c.setFunds(c.getFunds() - price);
	ptr->data->repair("SecreT");
	c.setCurrCar((ptr->data));
	carsIn = carsIn->delete_node(carsIn , c.getId());
	checkedInCustomers = checkedInCustomers->delete_node(checkedInCustomers , c.getId());
	ptr->data->setInShop(false);
	return true;
}
