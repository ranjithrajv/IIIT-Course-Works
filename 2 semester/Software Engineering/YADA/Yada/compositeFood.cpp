#include "headers.h"
#include "compositeFood.h"
#include "save.h"

CompositeFood::CompositeFood(CompositeFood::myMap &composite, CompositeFood::myMap &simple)
{
	compositeDatabase = composite;
	simpleDatabase = simple;
	initialSimpleFoodDatabase = simple;
	initialCompositeFoodDatabase =composite;
}

void CompositeFood::renewCompositeDatabase(CompositeFood::myMap &composite, CompositeFood::myMap &simple)
{
	compositeDatabase = composite;
	simpleDatabase = simple;
}

void CompositeFood::addDetails()
{
	id = "c" + static_cast<ostringstream*>( &(ostringstream() << compositeDatabase.size() + 1) )->str();

	string name;
	cout << "Enter comopsite food name: ";
	cin >> name;

	string keywords;
	cout << "Enter search keywords separated by comma: ";
	cin >> keywords;

	string component = "~";
	string servingSize;
	int count = 1;
	float calories = 0.0;

	data.push_back(keywords);

	cout << "Enter serial/composite food id to add or 'e' to stop adding: " << endl;	
	while (component!="e")
	{
		cout << "Enter component food " << count << ": ";
		cin >> component;
		if (component != "e")
		{
			cout << "Enter serving size for food " << count << ": ";
			cin >> servingSize;
			data.push_back(component + ":" + servingSize);
			calories = calories + atof(servingSize.c_str()) * calculateCalories(component);
		}
		else
			continue;
		count++;
	}

	data.push_front(static_cast<ostringstream*>( &(ostringstream() << calories) )->str());
	data.push_front(name);

}

float CompositeFood::calculateCalories(string component)
{
	const char *comp = component.c_str();
	if (comp[0] == 's')
	{
		list<string>::iterator iter;
		iter=simpleDatabase[component].begin();
		iter++;
		return atof((*iter).c_str());
	}
	else
	{
		list<string>::iterator iter;
		iter=compositeDatabase[component].begin();
		iter++;
		return atof((*iter).c_str());
	}

}

void CompositeFood::storeFood()
{
	compositeDatabase[id] = data;
}

void CompositeFood::print()
{
	map<string, list<string> >::iterator iter;
	for (iter = compositeDatabase.begin(); iter!=compositeDatabase.end();++iter)
	{
		cout << "id: " << iter->first << endl;
		list<string> details = iter->second;
		list<string>::iterator iter2;
		for (iter2 = details.begin(); iter2!=details.end();++iter2)
		{
			cout << *iter2 << endl;
		}
	}
}

void CompositeFood::save()
{
	Save save(initialSimpleFoodDatabase, initialCompositeFoodDatabase, simpleDatabase, compositeDatabase);
	initialSimpleFoodDatabase = simpleDatabase;
	initialCompositeFoodDatabase =compositeDatabase;
}
