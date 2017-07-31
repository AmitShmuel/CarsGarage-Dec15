#include <iostream>
#include "Wheels.h"
using namespace std;



Wheels:: Wheels() {
	
	//cout << "\n** Wheels' default C'tor has been called **\n";	
	setPsi(30);
	setRadi(15.5);
	setFlat(false);
	//cout << "PSI: 30, radius: 15.5\n\n";
}



Wheels::Wheels(int _psi, float _radius, bool _flat) {
	
	//cout << "\n** Wheels' C'tor has been called **\n";
	setPsi(_psi);
	setRadi(_radius);
	setFlat(_flat);
	if ( (getPsi() < 0) || (getPsi() > 50) || (getRadi() < 1) || (getRadi() > 50) )
		cerr << "wheel values were not given correctly !\n\n";
	//else
		//cout << "PSI: " << _psi << ", radius: " << _radius << endl;
}



Wheels:: ~Wheels() {

	//cout << "** Wheel's D'tor has been called **\n";
}



bool Wheels::check() {
	
	flat == true ? cout << "wheel is damaged !\n" : cout << "wheel is ok..\n";
	return flat;
}



void Wheels::setFlat(bool _flat) {
	
	flat = _flat;
	//flat == true ? cout << "There's a flat !\n" : cout << "there is no flat..\n";		
}



void Wheels::setPsi(int _psi) {
	
	if ((_psi < 0) || (_psi > 50)) {
		
		cerr << "\nPSI IS NOT IN RANGE ! please choose a value between 0-50..\n\n";
		return;
	}
	
	psi = _psi;
	//cout << "psi successfully changed !\n";
}



void Wheels::setRadi(float _radius) {
	
	if ((_radius < 1) || (_radius > 50)) {
		
		cerr << "\nRADIUS IS NOT IN RANGE !, please choose a value between 0-50..\n\n";
		return;
	}
	
	radius = _radius;
	//cout << "radius was successfully changed !\n";
}
