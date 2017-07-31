// Engine header file

#ifndef _ENGINE_
#define _ENGINE_

class Engine {
	
	float volume, currentFuel, maxFuel;
	bool activated, malfunction;

public:
	
	Engine();
	Engine(float, float, float, bool);
	~Engine();

	void activate(bool);
	
	//setters
	void setFuel(float); // accepted values: 20 - 70
	void setMaxFuel(float); // accepted values: 20 - 70
	void setVolume(float); // accepted values: 1000 - 5000
	void setActivated(bool);
	void setMalfunction(bool);
	
	//getters
	float getVolume() const {return volume;}
	float getMaxFuel() const {return maxFuel;}
	float getFuel() const {return currentFuel;}	
	bool getActivated() const {return activated;}
	bool getMalfunction() const {return malfunction;}
};

#endif
