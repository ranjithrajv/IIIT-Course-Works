#include "headers.h"
#include "loadFoodRemote.h"

void LoadFoodRemote::loadFood()
{

	ifstream remoteFoodDb("calories.csv");
	string value;
	int id = totalSimpleFood.size() + 1;

	while(getline(remoteFoodDb,value))
	{
		stringstream stream(value);
		string word;
		list<string> valueList;
		string searchKeys = "";
		string name = "";
		string calories;
		int count = 0;
		while (getline(stream, word, ',') && count <= 1)
		{
			if (count == 0)
			{
				name = word;
				stringstream stream2(word);
				string key = "";
				int count2 = 0;
				while(getline(stream2,key,' '))
				{
					if (count2 == 0)
						searchKeys = key;
					else
						searchKeys = searchKeys + "," + key;
					count2++;
				}
			}
			valueList.push_back(word);
			count++;
		}
		string dictKey = "s" + static_cast<ostringstream*>( &(ostringstream() << id) )->str();
		valueList.push_back(searchKeys);		
		totalSimpleFood[dictKey] = valueList;
		id++;
	}
}

void LoadFoodRemote::setInitialSimpleFood(myMap & initial)
{
	totalSimpleFood = initial;
}

LoadFoodRemote::myMap & LoadFoodRemote::returnTotalSimpleFood()
{
	return totalSimpleFood;
}	
