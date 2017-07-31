#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include "FileParser.h"
using namespace std;



bool my_atob(char* s) {
	
	if(!strcmp(s , "false"))
		return false;
	return true;
}

car_node* FileParser::parseCarFile(char* fileName) {
	
	fp = fopen(fileName , "r");
	if(fp == 0)
	{
		cerr << "Cannot open the file " << fileName << endl;
		return 0;
	}
	
	car_node* carList = 0;
	char buff[256];
	char* s[20];	// will hold 20 strings for each car's C'tor
	int m , n , j , i , count;
	while(fgets(buff , 256 , fp))
	{	
		i = 0;
		m = 0;
		do
		{
			count = 0;
			j = i;
			for(; buff[i] != ',' && buff[i] != '\n'; i++)
				count++;
			i+=2;	// jumping over ',' and 'space' to the next word
			
			s[m] = new char[count+1];
				
			for(n = 0; n < count; n++ , j++)
				s[m][n] = buff[j];
				
			s[m][n] = '\0';
			m++;
		}
		while(buff[i-2] != '\n'); // (i-2) jumping back, oherwise out of bounds at end of buffer/line
		Car* c = new Car( s[0] , s[1] , my_atob(s[2]) , atoi(s[3]) , atof(s[4]) , atof(s[5]) , my_atob(s[6]) , atoi(s[7]) , atof(s[8]) , my_atob(s[9]) , atoi(s[10]) , atof(s[11]) , my_atob(s[12]) , atoi(s[13]) , atof(s[14]) , my_atob(s[15]) , atoi(s[16]) , atof(s[17]) , my_atob(s[18]) , s[19] );
		carList = carList->Add_head(carList , c);
	}
	
	fclose(fp);
	return carList;
}



customer_node* FileParser::parseCustomerFile(char* fileName) {
	
	fp = fopen(fileName , "r");
	if(fp == 0)
	{
		cerr << "Cannot open the file " << fileName << endl;
		return 0;
	}
	
	customer_node* customerList = 0;
	char buff[256];
	char* s[3];
	int m , n , j , i , count;
	while(fgets(buff , 256 , fp))
	{	
		i = 0;
		m = 0;
		do
		{
			count = 0;
			j = i;
			for(; buff[i] != ',' && buff[i] != '\n'; i++)
				count++;
			i+=2;
			
			s[m] = new char[count+1];
				
			for(n = 0; n < count; n++ , j++)
				s[m][n] = buff[j];
				
			s[m][n] = '\0';
			m++;
		}
		while(buff[i-2] != '\n');
		Customer* c = new Customer( s[0] , s[1] , atof(s[2]) , 0);		
		customerList = customerList->Add_head(customerList , c);
	}

	fclose(fp);
	return customerList;
}
