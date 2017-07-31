#include <iostream>
#include <string.h>
#include "Car.h"
using namespace std;



Car::Car() {
	
	//cout << "\n** default C'tor of the car Audi TT has been called **\n";
	
	owner = 0;
	
	brand = strdup("Audi");
	if (brand == 0) 
	{
		cerr << "Allocation error for brand..";
		return;
	}
	
	model = strdup("TT");
	if (model == 0) 
	{
		cerr << "Allocation error for model";
		return;
	}
	
	//cout << "setting values for your wheels..\n\n";
	int i;
	for (i = 0; i < 4; i++) 
	{
		//cout << "\nwheel number " << i+1;
		wheels[i] = new Wheels();
		if (wheels[i] == 0) 
		{
			cerr << "Allocation error for wheel num " << i+1;
			return;
		}
	}
}



Car::Car(const Car& c) {
	
	//cout << "** Copy C'tor has been called !**\n\n";
	
	owner = strdup(c.owner);
	if(owner == 0) {
		cerr << "Allocation error for owner!\n"; return;}
	
	brand = strdup(c.brand);
	if(brand == 0) {
		cerr << "Allocation error for brand!\n"; return;}
	
	model = strdup(c.model);
	if(model == 0) {
		cerr << "Allocation error for model!\n"; return;}	
	
	for(int i=0; i<4; i++) {

		wheels[i] = new Wheels(c.wheels[i]->getPsi() , c.wheels[i]->getRadi() , c.wheels[i]->getFlat());
		if(wheels[i] == 0) {
			cout << "Allocations error for wheels num " << i+1 << endl; return;
		}
	}
	
	lights.setMalfunction(c.lights.getMalfunction());
	motor.setVolume(c.motor.getVolume());
	motor.setMaxFuel(c.motor.getMaxFuel());
	motor.setFuel(motor.getMaxFuel());
	motor.setMalfunction(c.motor.getMalfunction());
}



Car& Car::operator=(const Car& c) {
	
	//cout << "** operator= has been called! **\n\n";
	if(this == &c) 
		return *this;
	
	delete[] brand , model , owner;
	owner = strdup(c.owner);
	if(owner == 0) {
		cerr << "Allocation error for owner!\n";}
	brand = strdup(c.brand);
	if(brand == 0) {
		cerr << "Allocation error for brand!\n";}
	model = strdup(c.model);
	if(model == 0) {
		cerr << "Allocation error for model!\n";}
		
	for(int i=0; i<4; i++) {

		wheels[i] = new Wheels(c.wheels[i]->getPsi() , c.wheels[i]->getRadi() , c.wheels[i]->getFlat());
		if(wheels[i] == 0) {
			cout << "Allocations error for wheels num " << i+1 << endl;
		}
	}
	
	lights.setMalfunction(c.lights.getMalfunction());
	motor.setVolume(c.motor.getVolume());
	motor.setMaxFuel(c.motor.getMaxFuel());
	motor.setFuel(motor.getMaxFuel());
	motor.setMalfunction(c.motor.getMalfunction());
	setInShop(c.getInShop());
	
	return *this;
}




Car::Car(char* _brand , char* _model , bool _lightsMalfunc , int _volume , float _maxFuel ,  float _currFuel , bool _engineMalfunc , int _psi0 , float _radius0 , bool _flat0 , int _psi1 , float _radius1 , bool _flat1 , int _psi2 , float _radius2 , bool _flat2 , int _psi3 , float _radius3 , bool _flat3 , char* _owner) 
: motor(_volume , _currFuel , _maxFuel , _engineMalfunc) , lights(_lightsMalfunc) {
	
	brand = strdup(_brand);
	if (brand == 0) 
	{
		cerr << "Allocation error for brand\n";
		return;
	}
	
	model = strdup(_model);
	if (model == 0) 
	{
		cerr << "Allocation error for model\n";
		return;
	}
	
	owner = strdup(_owner);
	if(owner == 0)
	{
		cerr << "Allocation error for owner\n";
		return;
	}
	
	//cout << "\n** C'tor of the car " << model << " " << brand << " of the owner " << owner << " has been called **\n";
	
	//cout << "setting values to your 4 wheels..\n";

	wheels[0] = new Wheels(_psi0 , _radius0 , _flat0); 
	if (wheels[0] == 0) {
		cerr << "Allocation error for wheel num 0"; return;}
	wheels[1] = new Wheels(_psi1 , _radius1 , _flat1); 
	if (wheels[1] == 0) {
		cerr << "Allocation error for wheel num 1"; return;}
	wheels[2] = new Wheels(_psi2 , _radius2 , _flat2); 
	if (wheels[2] == 0) {
		cerr << "Allocation error for wheel num 2"; return;}
	wheels[3] = new Wheels(_psi3 , _radius3 , _flat3); 
	if (wheels[3] == 0) {
		cerr << "Allocation error for wheel num 3"; return;}
}



Car::~Car() {
	
	//cout << "** Car's D'tor has been called **\n";
	for (int i = 0; i < 4; i++)
		delete wheels[i];
	delete[] brand , model;
	
}



void Car::switchOn() {
	
	motor.activate(true);
	lights.setActive(true);
	
	int i , checker;
	for (i = 0; i < 4; i++)
	{
		checker = wheels[0]->check();
		if (checker == 1)
			cout << "wheel number " << i << "has a flat !\n";
	}
}



void Car::switchOFF() {
	
	motor.activate(false);
	lights.setActive(false);	
}



void Car::drive() {
	
	if (motor.getActivated() == false) {
		
		cout << "turn on the engine !\n\n";
		return;
	}
	
	if (lights.getMalfunction() == true) {
		
		cout << "fix your lights !\n\n";
		return;
	}
	
	if (lights.getActive() == false) 
		lights.toggleLights();
	
	int i , counter = 0;
	for (i = 0; i < 4; i++)
	{
		if (wheels[i]->getFlat() == true) {
			
			cout << "fix wheel number " << i << "\n\n";
			counter++;
		}
		
		if (counter > 0)
			return;
	}
	
	cout << "\nCar is driving.. drive safe !\n\n";
}



void Car::setInShop(bool _inShop) {
	
	inShop = _inShop;
	//inShop == true ? cout << "car is now in the shop..\n" : cout << "car is out of the shop..\n";
} 



bool Car::setOwner(char* _owner) {
	
	owner = strdup(_owner);
	if(owner == 0)
	{
		cerr << "Allocation error for owner\n";
		return 0;
	}
	
	//cout << "owner of the car is now " << owner << endl;
	return true;
}



int Car::malfunctions() const {
	
	int count = 0;
	if(motor.getMalfunction())
		count++;
	if(lights.getMalfunction())
		count++;
	for(int i = 0; i < 4; i++)
		if(wheels[i]->getFlat())
			count++;
			
	return count;
}



void Car::repair(char* password) {
	
	if(!strcmp(password , "SecreT"))
	{
		motor.setMalfunction(false);
		lights.setMalfunction(false);
		for(int i = 0; i < 4; i++)
			wheels[i]->setFlat(false);
	}
}
