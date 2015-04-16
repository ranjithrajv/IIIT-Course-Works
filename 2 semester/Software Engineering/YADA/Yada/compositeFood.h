#ifndef COMPOSITEFOOD_H
#define COMPOSITEFOOD_H

#include "food.h"
#include "headers.h"


class CompositeFood : public Food
{
	public:
		typedef map<string,list<string> > myMap;
		CompositeFood(myMap &, myMap &);
		void addDetails();
		void storeFood();
		void print();
		void renewCompositeDatabase(myMap &, myMap &);
		void save();
	private:
		myMap compositeDatabase;
		myMap initialSimpleFoodDatabase;
		myMap initialCompositeFoodDatabase;
		float calculateCalories(string);
};


#endif