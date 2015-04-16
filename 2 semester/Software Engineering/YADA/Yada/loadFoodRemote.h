#ifndef LOADFOODREMOTE_H
#define LOADFOODREMOTE_H

#include "headers.h"
#include "loadFood.h"

class LoadFoodRemote : public LoadFood
{
	public:
		LoadFoodRemote(){}
		typedef map<string,list<string> > myMap;
		void loadFood();
		void setInitialSimpleFood(myMap &);
		myMap & returnTotalSimpleFood();

	private:
		myMap totalSimpleFood;



};

#endif
