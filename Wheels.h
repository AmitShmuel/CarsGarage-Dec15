// Wheels header file

#ifndef _WHEELS_
#define _WHEELS_

class Wheels {
	
	int psi;
	float radius;
	bool flat;
	
public:
	
	Wheels();
	Wheels(int, float, bool);
	~Wheels();
	
	bool check(); // checks if the wheel is damaged or not
	
	//setters
	void setFlat(bool);
	void setPsi(int); // accepted values: 10 - 40
	void setRadi(float); // accepted values: 15 - 40
	//getters
	int getPsi() const {return psi;}
	bool getFlat() const {return flat;}
	float getRadi() const {return radius;}
};

#endif
