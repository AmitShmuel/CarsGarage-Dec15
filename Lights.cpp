#include <iostream>
#include "Lights.h"
using namespace std;



Lights:: Lights() {
	
	//cout << "\n\n** Lights' default C'tor has been called **\n";
	setMalfunction(false); 
	setActive(false);
	//cout <<"Lights are off, there is no malfunction..\n\n";	
} 



Lights:: Lights(bool _malfunction) {
	
	//cout << "\n\n** Lights' C'tor has been called **\n";
	setMalfunction(_malfunction); 
	setActive(false);
	//cout << "Lights are OFF \n\n";
} 



Lights:: ~Lights() {

	//cout << "** Lights' D'tor has been called **\n";
}



void Lights:: toggleLights() {
	
	if (active == 1) {
		
		active == 0;
		cout << "Light are now OFF !\n";
	}
	
	else {
		
		active == 1;
		cout << "Lights are now ON !\n";
	}
}



void Lights:: setActive(bool _active) {
	
	if (malfunction == true) {
		
		//cerr << "Lights are malfunctioning.. please fix them before using..\n";
		return;
	}

	active = _active;
	//cout << "Lights' state was successfully changed !\n";
}



void Lights:: setMalfunction(bool _malfunction) {
	
	malfunction = _malfunction;
	//cout << "Lights' malfunction was successfully changed !\n";
}
