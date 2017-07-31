// Customer header file

#ifndef _CUSTOMER_
#define _CUSTOMER_
#include "Car.h"

class Customer {
	
	char* name;
	char* id;
	float funds;
	Car* currentCar;
	
public:
	
	Customer();
	Customer(char*, char*, float, Car* _currCar = 0);
	Customer(const Customer&);
	Customer& operator=(const Customer&);
	~Customer();
	
	bool assignCar(Car*);
	
	//setters
	void setName(char*);
	void setId(char*);
	void setFunds(float);
	void setCurrCar(Car*);
	
	//getters
	char* getName() const {return name;}
	char* getId() const {return id;}
	float getFunds() const {return funds;}
	Car* getCurrCar() const {return currentCar;}
};


#endif
