// Car class header file
// Car is implemented by three main componenets: engine, lights and wheels.

#ifndef _CAR_
#define _CAR_
#include "Lights.h"
#include "Wheels.h"
#include "Engine.h"

class Car {
	
	char* owner;
	char* brand;
	char* model;
	bool inShop;
	Wheels* wheels[4];
	Lights lights;
	Engine motor;
	
public:
	
	Car(); // default constructor, brand and model: Audi TT, engine and lights are off
	Car(const Car&); // copy constructor, recieving reference to an existing car
	Car& operator=(const Car&); // operator '=', use to assaign one object to another from the same class 
	Car(char* _brand , char* _model , bool _lightsMalfunc , int _volume , float _maxFuel ,  float _currFuel , bool _engineMalfunc , int _psi0 , float _radius0 , bool _flat0 , int _psi1 , float _radius1 , bool _flat1 , int _psi2 , float _radius2 , bool _flat2 , int _psi3 , float _radius3 , bool _flat3 , char* _owner); // nondefault constructor, send values as you wish
	~Car();
	
	// Car handling methods
	void switchOn(); 
	void switchOFF(); 
	void drive(); 
	void repair(char*); // with a given "password" from Garage, function can repair the car
	int malfunctions() const; // returns num of malfunctioned components
		
	//setters
	void setInShop(bool);
	bool setOwner(char*);
	
	//getters
	char* getBrand() const {return brand;}
	char* getModel() const {return model;}
	char* getOwner() const {return owner;}
	bool getInShop() const {return inShop;}
};

#endif
