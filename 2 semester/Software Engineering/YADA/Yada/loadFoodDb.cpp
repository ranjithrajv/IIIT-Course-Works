#include "loadFoodDb.h"
#include "headers.h"


void LoadFoodDb::loadFood()
{
	load(1,"simpleFoodDb"); //1 = simpleFood
	load(2,"compositeFoodDb"); //2 = compositeFood
}

void LoadFoodDb::load(int source, string sourceName)
{
	const char *src = sourceName.c_str();
	ifstream foodDb(src);
	string value;
	string key;

	while(foodDb >> value)
	{
		key = value.substr(0,2);
		value = value.substr(3);
		// cout << "id: " << key << "\n";

		stringstream stream(value);
		stringstream stream1(value);
		stringstream stream2(value);
		string word;
		string keyword;
		list<string> valueList;
		while (getline(stream, word, '|'))
			// cout << word << endl;
			valueList.push_back(word);

		if (source == 1)
		{
			simpleFood[key] = valueList;

			int count=0;
			list<string> keyList;
			while (getline(stream1, keyword, '|') && count<3){
				//cout << word << endl;
				count++;
			}
			stringstream keyStream(keyword);
			string keys;
			while (getline(keyStream, keys, ','))
				keyList.push_back(keys);

			simpleFoodKeyword[key]= keyList;
			totalSimpleFood++;
		}
		else if (source == 2)
		{
			compositeFood[key] = valueList;
			
			int count=0;
			list<string> keyList;
			while (getline(stream2, keyword, '|') && count<1){
				//cout << word << endl;
				count++;
			}
			stringstream keyStream(keyword);
			string keys;
			while (getline(keyStream, keys, ','))
				keyList.push_back(keys);
			
			compositeFoodKeyword[key]= keyList;
			
			totalCompositeFood++;
		}
	}

	
	// map<string, string>::iterator iter;
	// for (iter = simpleFood.begin(); iter!=simpleFood.end();++iter)
	// {
	// 	cout << iter->first << endl;
	// 	cout << iter->second << endl;
	// }
	
	foodDb.close();
}

LoadFoodDb::myMap &LoadFoodDb::returnSimpleFoodData()
{
	return simpleFood;
}

LoadFoodDb::myMap &LoadFoodDb::returnCompositeFoodData()
{
	return compositeFood;
}

LoadFoodDb::myMap &LoadFoodDb::returnSimpleFoodKeyword()
{
	        return simpleFoodKeyword;
}

LoadFoodDb::myMap &LoadFoodDb::returnCompositeFoodKeyword()
{
	                return compositeFoodKeyword;
}

int LoadFoodDb::returnTotalSimpleFood()
{
	return totalSimpleFood;
}

int LoadFoodDb::returnTotalCompositeFood()
{
	return totalCompositeFood;
}
