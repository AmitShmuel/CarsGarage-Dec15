#include <iostream>
#include <cstring>
#include "Customer.h"
using namespace std;



Customer::Customer() {
	
	//cout << "** Default C'tor of Customer has been called**\n\n";
	setName("Default");
	setFunds(1000);
	setCurrCar(0);		
}



Customer::Customer(char* _name, char* _id, float _funds, Car* _currCar) {
	
	//cout << "** C'tor of Customer has been called! **\n\n";
	setName(_name);
	setId(_id);
	setFunds(_funds);
	setCurrCar(_currCar);
}



Customer::Customer(const Customer& a) {
	
	//cout << "** Copy C'tor of Customer has been called! **\n\n";
	setName(a.name);
	setId(a.id);
	setFunds(a.funds);
	setCurrCar(a.currentCar);
}



Customer& Customer::operator=(const Customer& a) {
	
	//cout << "** operator= of Customer has been called! **\n\n";
	if (this == &a)
		return *this;
		
	delete[] name , id;
	if(currentCar != 0)
		delete currentCar;
	
	setName(a.name);
	setId(a.id);
	setFunds(a.funds);
	setCurrCar(a.currentCar);
	
	return *this;
}



Customer::~Customer() {
	
	//cout << "** D'tor of Customer has been called! **\n\n";
	delete[] name, id;
}


bool Customer::assignCar(Car* c) {
		
	if(currentCar != 0) {
		cerr << "There's already a car to this customer!\n"; return false;}
	
	currentCar = c;
	return true;
}



void Customer::setName(char* _name) {
	
	name = strdup(_name);
	
	if(name == 0) {
		cerr << "Customer setName: error setting name!\n";}
}



void Customer::setId(char* _id) {
	
	if((id = strdup(_id)) == 0) {
		cerr << "Customer setId: error setting id!\n";}
}




void Customer::setFunds(float _funds) {
	
	if(_funds < 0) {
		cerr << "Customer setFunds: funds must be a positive value!\n"; return;}
	funds = _funds;
}


void Customer::setCurrCar(Car* c) {
	
	if(c == 0) {
		
		currentCar = 0;
		return;
	}
	currentCar = c;
}
