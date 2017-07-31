#include <iostream>
#include "Engine.h"
using namespace std;



Engine::Engine() {
	
	//cout << "\n** Engine default C'tor has been called **\n";
	setMaxFuel(70);
	setFuel(70);
	setVolume(1600);
	setActivated(false);
	setMalfunction(false);
	//cout <<"volume: 1600cc, current fuel: 70 litres, max fuel: 70 litres, Engine is OFF.\n\n";
}



Engine::Engine(float _volume, float _currentFuel, float _maxFuel, bool _malfunc) {
	
	//cout << "\n** Engine C'tor has been called **\n";
	setMaxFuel(_maxFuel);
	setFuel(_currentFuel);
	setVolume(_volume);
	if ( (getVolume() < 1000) || (getVolume() > 10000) || (getFuel() < 0) || (getFuel() > 1000) || (getMaxFuel() < 20) || (getMaxFuel() > 1000) )
		cerr << "Engine values were not given correctly !\n\n";
	else
	//	cout <<"volume: " << _volume << "cc, current fuel: " << _currentFuel << " litres, max fuel: " << _maxFuel << " litres.\n\n";
	setMalfunction(_malfunc);
}



Engine::~Engine() {
	
	//cout << "** Engine's D'tor has been called **\n";
}



void Engine:: setMalfunction(bool _malfunc) {
	
	malfunction = _malfunc;
	//cout << "Engine's malfunction was successfully changed !\n";
}




void Engine::activate(bool _activated) {
	
	if (malfunction == true) {
		
		//cout << "Engine malfunction !\n";
		return;
	}
	
	activated = _activated;
	//activated == true ? cout << "\n\nEngine is now ON !\n" : cout << "\nEngine is now OFF !\n";
}



void Engine::setActivated(bool _activated) {
	
	activated = _activated;
	//cout << "Engine's 'state was successfully changed !\n";
}



void Engine::setVolume(float _volume) {
	
	if ((_volume < 1000) || (_volume > 10000)) {
		
		cerr << "VOLUME IS NOT IN RANGE.. please choose values between 1000 - 5000 !\n\n";
		return;
	}
	
	volume = _volume;
	//cout << "volume was successfully changed !\n";
}



void Engine::setMaxFuel(float _maxFuel) {
	
	if ((_maxFuel < 20) || (_maxFuel > 1000)) {
		
		cerr << "MAX FUEL IS NOT IN RANGE.. please choose values between 20 - 1000 !\n\n";
		return;
	}
	
	maxFuel = _maxFuel;
	//cout << "max fuel was successfully changed !\n";
}



void Engine::setFuel(float _currentFuel) {
	
	if ((_currentFuel < 0) || (_currentFuel > 1000)) {
		
		cerr << "REQUESTED FUEL IS NOT IN RANGE.. please choose values between 0 - 1000 !\n\n";
		return;
	}
	
	currentFuel = _currentFuel;
	//cout << "fuel was successfully changed !\n";
}
