#ifndef LOADFOOD_H
#define LOADFOOD_H

#include "headers.h"
#include "simpleFood.h"
#include "compositeFood.h"

class LoadFood
{
	public:
		virtual void loadFood()=0;

	protected:
		~LoadFood(){}
};

#endif
