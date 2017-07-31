// Lights header file

#ifndef _LIGHTS_
#define _LIGHTS_

class Lights {
	
	bool active, malfunction;
	
public:
	
	Lights();
	Lights(bool);
	~Lights();
	
	void toggleLights();
	
	//setters
	void setActive(bool);
	void setMalfunction(bool);
	//getters
	bool getActive() const {return active;}
	bool getMalfunction() const {return malfunction;}
};

#endif
