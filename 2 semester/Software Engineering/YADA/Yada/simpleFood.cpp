#include "headers.h"
#include "simpleFood.h"

SimpleFood::SimpleFood(SimpleFood::myMap &simple)
{
	simpleDatabase = simple;
}

void SimpleFood::renewSimpleDatabase(SimpleFood::myMap &simple)
{
	simpleDatabase = simple;
}

void SimpleFood::addDetails()
{
	string name;
	string calories;
	string keywords;

	id = "s" + static_cast<ostringstream*>( &(ostringstream() << simpleDatabase.size() + 1) )->str();

	cout << "Enter simple food name: ";
	cin >> name;
	cout << "Enter total calories: ";
	cin >> calories;
	cout << "Enter search keywords separated by comma: ";
	cin >> keywords;

	data.push_back(name);
	data.push_back(calories);
	data.push_back(keywords);
}


void SimpleFood::storeFood()
{
	simpleDatabase[id] = data;
}

SimpleFood::myMap SimpleFood::returnLatestSimpleDatabase()
{
	return simpleDatabase;
}


void SimpleFood::print()
{
	map<string, list<string> >::iterator iter;
	for (iter = simpleDatabase.begin(); iter!=simpleDatabase.end();++iter)
	{
		cout << "Food id: " << iter->first <<" Food Details:";
		list<string> details = iter->second;
		list<string>::iterator iter2;
		for (iter2 = details.begin(); iter2!=details.end();++iter2)
		{
			cout <<" "<< *iter2;
		}
		cout<<endl;
	}
}
