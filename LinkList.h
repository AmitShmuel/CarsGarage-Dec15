// Linked List header file:
// This file consists two linked list classes, one for cars and the other for customers.
// The functions of each class basicly work the same. 

#ifndef _LINKLIST_
#define _LINKLIST_
#include "Customer.h"



class car_node {

public:
	
	Car* data;
	
	class car_node* next;
	
	// ----------- METHODS ----------- //
	
	car_node* Add_head (car_node* head , Car* data);
	
	car_node* Find(car_node* , char*);
	
	car_node* findByPosition(car_node* , int); // (position in the list)
	
	car_node* delete_node(car_node* , char*);
	
	bool Print_list(car_node* Head);
	
	void FreeList(car_node* head);

};



class customer_node {
	
public:
	
	Customer* data;
	
	class customer_node* next;
	
	// ----------- METHODS ----------- //
	
	customer_node* Add_head(customer_node*, Customer* data);
	
	customer_node* Find(customer_node* , char*);
	
	customer_node* findByPosition(customer_node* , int); // (position in the list)
	
	customer_node* delete_node(customer_node* , char*);
	
	bool Print_list(customer_node* Head);
	
	void FreeList(customer_node* head);

};

#endif
