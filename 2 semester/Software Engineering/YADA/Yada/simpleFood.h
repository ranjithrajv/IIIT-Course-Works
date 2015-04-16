#ifndef SIMPLEFOOD_H
#define SIMPLEFOOD_H

#include "food.h"
#include "headers.h"


class SimpleFood : public Food
{
	public:
		typedef map<string,list<string> > myMap;
		SimpleFood(myMap &);
		void addDetails();
		void storeFood();
		void print();
		void renewSimpleDatabase(myMap &);
		myMap returnLatestSimpleDatabase();

};


#endif
