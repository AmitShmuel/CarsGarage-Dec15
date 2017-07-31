// FileParser header file:
// This class suppose to read the data from text files, customers data and cars data.
// It is implemented in a way that the parsing functions creating a linked list of the data of each file, and returning the head of the list to the main.

#ifndef _FILEPARSER_
#define _FILEPARSER_
#include <fstream>
#include "Garage.h"


class FileParser {
	
	FILE* fp;
	
public:
	
	car_node* parseCarFile(char*);
	customer_node* parseCustomerFile(char*);
};

#endif
