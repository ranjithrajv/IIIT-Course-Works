#ifndef FOOD_H
#define FOOD_H

#include "headers.h"

class Food
{
	public:
		typedef map<string,list<string> > myMap;
		virtual void addDetails() = 0;
		virtual void storeFood() = 0;
		virtual void print() = 0;
	protected:
		string id;
		list<string> data;
		map<string,float> nutrientList;
		myMap simpleDatabase;
};


#endif
