#include "foodStore.h"
#include "foodStructure.h"

// struct food
// {
// 	int id;
// 	string name;
// 	int servSize;
// 	int calories;
// 	vector<string> nutrients;
// };

void FoodStore::addFood(int id)
{
	int servSize, calories, extra;
	string name;

	cout << "Enter food name: ";
	cin >> name;
	cout << "Enter serving size: ";
	cin >> servSize;
	cout << "Enter total calories: ";
	cin >> calories;

	ofstream simpleFoodDb("simpleFoodDb",ios::app);
	simpleFoodDb << id << "|" << name << "|" << servSize << "|" << calories << "\n";

	simpleFoodDb.close();
}

int FoodStore::getCalorieDetail()
{
	string line;
	ifstream simpleFoodDb("simpleFoodDb");
	simpleFoodDb>>line;
	simpleFoodDb>>line;

	int serve;
	simpleFoodDb>>serve;
	int calorie;
	simpleFoodDb>>calorie;

	return serve*calorie;

}
void FoodStore::displayFood()
{
	string line;
	ifstream simpleFoodDb("simpleFoodDb");

	cout<<"Your serve for today:"<<endl;

	while(simpleFoodDb >> line)
	{
		stringstream stream(line);
		string word;
		while (getline(stream, word, '|'))
			cout << word << "     ";
		cout << "\n";
	}
	simpleFoodDb.close();

}
