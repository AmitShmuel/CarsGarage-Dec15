#include <iostream>
#include <cstdlib>
#include <cstring>
#include "LinkList.h"
using namespace std;



// -------------- customer_nodes' METHODES -------------- //


customer_node* customer_node::Add_head(customer_node* head , Customer* data) {
	
	customer_node* newCustomer = new customer_node;
	newCustomer->data = data;
	newCustomer->next = head;
	return newCustomer;
}



customer_node* customer_node::Find(customer_node* head , char* _id) {
	
	customer_node* curr = head;
	while ( (curr != 0) && (strcmp(curr->data->getId() , _id) != 0) )
		curr = curr->next;
		
	return curr;
}



customer_node* customer_node::findByPosition(customer_node* head , int num) {
	
	if(num <= 0)
		return 0; 
		
	customer_node* curr = head;
	while((num-1 != 0) && (curr != 0)) {
	
		curr = curr->next;
		num--;
	}
	return curr;
}



customer_node* customer_node::delete_node(customer_node* head , char* _id) {
	
	if(head == 0) {
		cerr << "list is empty..\n"; return head;}
	
	customer_node* curr = head;
	if(!strcmp(head->data->getId() , _id)) {
		
		curr = curr->next;
		return curr;
	}
	
	customer_node* prev = curr;
	while(curr->next != 0) {
		
		prev = curr;
		curr = curr->next;
		if(!strcmp(curr->data->getId() , _id)) {
			
			prev->next = curr->next;
			return head;
		}
	}
	return head;
}



bool customer_node::Print_list(customer_node* head) {
	
	if(head == 0)
		return false;
	
	cout << endl;
	cout.width(20); cout << "| NAME |";
	cout.width(22); cout << "| ID |";
	cout.width(25); cout << "| FUNDS |\n\n";
	int i=1;
	while(head != 0)
	{
		cout << "[" << i << "]";
		cout.width(20); cout << head->data->getName();
		cout.width(20); cout << head->data->getId();
		cout.width(20); cout << head->data->getFunds() << "\n\n";
		head = head->next;
		i++;
	}
	return true;
}



void customer_node::FreeList(customer_node* head) {
	
	customer_node* toDelete;
	while (head != 0)
	{
		toDelete = head;
		head = head->next;
		delete toDelete;
	}
}



// -------------- carr_nodes' METHODES -------------- //


car_node* car_node::Add_head(car_node* head , Car* data) {
	
	car_node* newCar = new car_node;
	newCar->data = data;
	newCar->next = head;
	return newCar;
}



car_node* car_node::Find(car_node* head , char* _owner) {
	
	car_node* curr = head;
	while ( (curr != 0) && (strcmp(curr->data->getOwner() , _owner) != 0) )
		curr = curr->next;
		
	return curr;
}



car_node* car_node::findByPosition(car_node* head , int num) {
	
	if(num <= 0)
		return 0; 
		
	car_node* curr = head;
	while((num-1 != 0) && (curr != 0)) {
	
		curr = curr->next;
		num--;
	}
	return curr;
}



car_node* car_node::delete_node(car_node* head , char* _owner) {
	
	if(head == 0) {
		cerr << "list is empty..\n"; return head;}
	
	car_node* curr = head;
	if(!strcmp(head->data->getOwner() , _owner)) {
		
		curr = curr->next;
		return curr;
	}
	
	car_node* prev = curr;
	while(curr->next != 0) {
		
		prev = curr;
		curr = curr->next;
		if(!strcmp(curr->data->getOwner() , _owner)) {
			
			prev->next = curr->next;
			return head;
		}
	}
	return head;
}



bool car_node::Print_list(car_node* head) {
	
	if(head == 0)
		return false;
	cout << endl;
	cout.width(24); cout << "| MODEL |";
	cout.width(20); cout << "| BRAND |";
	cout.width(21); cout << "| OWNER |\n\n";
	int i = 1;
	while(head != 0)
	{
		cout << "[" << i << "]";
		cout.width(20); cout << head->data->getModel();
		cout.width(20); cout << head->data->getBrand();
		cout.width(20); cout << head->data->getOwner() << "\n\n";
		head = head->next;
		i++;
	}
	return true;
}



void car_node::FreeList(car_node* head) {
	
	car_node* toDelete;
	while (head != 0)
	{
		toDelete = head;
		head = head->next;
		delete toDelete;
	}
}
