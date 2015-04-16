/*
 * UserInterface.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: YBAR
 */
#include "Header.h"
#include "UserInterface.h"
#include "UserProfile.h"
#include "SearchFood.h"
#include "loadFood.h"
#include "loadFoodDb.h"
#include "simpleFood.h"
#include "compositeFood.h"
#include "save.h"
#include "loadFoodRemote.h"
#include "CalorieCalculation.h"
#include "foodStore.h"

LoadFoodDb data;

using namespace std;

void UserInterface::calcationInterface(UserProfile *user)
{
	int choice;
	IDietCalculator *dc;
	do
	{
		cout<<"--------- Calorie Intake Menu --------- "<<endl;
		cout << "1. BMR based Intake"<<endl;
		cout << "2. RMR based Intake" << endl;
		cout << "3. Return" << endl;
		cout <<"Enter your choice:"<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1:
				dc= new BMRBasedDietCalculator();
				cout<<"Intake For day :" <<dc->getTargetCalorieIntake(user)<<endl;
				break;
			case 2:
				dc= new RMRBasedDietCalculator();
				cout<<"Intake For day :" <<dc->getTargetCalorieIntake(user)<<endl;
				break;
			case 3:
			  return;

		}

	}while(1);
}

void UserInterface::FoodInterface()
{
	int choice;
	data.loadFood();
	typedef map<string,list<string> > myMap;
	myMap simpleDatabase = data.returnSimpleFoodData();
	myMap compositeDatabase = data.returnCompositeFoodData();

	SimpleFood simpleFood(simpleDatabase);
	CompositeFood compositeFood(compositeDatabase,simpleDatabase);

	do
	{

		cout<<"--------- Food Menu --------- "<<endl;
		cout << "1. Display available Simple Food"<<endl;
		cout << "2. Display all composite Food" << endl;
		cout << "3. Add a simple food" << endl;
		cout << "4. Add a composite food" << endl;
		cout << "5. Save changes to food database" << endl;
		cout << "6. Remote add" << endl;
		cout << "7. Search For Food"<<endl;
		cout << "8.back" << endl;

		cout <<"Enter Your Choice:"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout << "List of Simple Food-" << endl;
			simpleFood.print();
			break;
		case 2:
			cout << "List of Composite Food-" << endl;
			compositeFood.print();
			break;
		case 3:
			cout << "Add a Simple Food-" << endl;
			simpleFood.addDetails();
			simpleFood.storeFood();
			break;
		case 4:
			cout << "Add a Composite Food-" << endl;
			compositeFood.addDetails();
			compositeFood.storeFood();
			break;
		case 5:
			cout << "Save changes to Food Database-" << endl;
			{
				//Save save(simpleDatabase,compositeDatabase,simpleFood,compositeFood);

			}
			break;
		case 6:
		{
			cout<<"Add Food From Remote location-"<<endl;
			LoadFoodRemote lremote;
			lremote.setInitialSimpleFood(simpleDatabase);
			lremote.loadFood();
			cout<<"Food Loaded Successfully..."<<endl;
		}

			break;
		case 7:
		{
			std::string keywords;
			cout<<"Enter Keywords:";
			cin>>keywords;
			Search::search(keywords);
		}
			break;
		case 8:
			return;
		}

	}while(1);
}

void UserInterface::changeUserDetails(UserProfile* loggeduser)
{
	string line;
	int intval;

	cout<<"Current Name:"<<loggeduser->getUserName()<<endl
			<<"Enter New Name:";
	cin>>line;
	loggeduser->setUserName(line);

	cout<<"Current Age:"<<loggeduser->getAge()<<endl
			<<"Enter New Age:";
	cin>>intval;
	loggeduser->setAge(intval);

	cout<<"Current Weight:"<<loggeduser->getWeight()<<endl
			<<"Enter New Weight:";
	cin>>intval;

	cout<<"Current ActivityLevel:"<<loggeduser->getActivityLevel()<<endl
			<<"Enter New Activity Level:";
	cin>>intval;
	loggeduser->setActivityLevel(intval);

}

void UserInterface::AddFoodInterface()
{
	int foodid;
	cout<<"Enter Food Id";
	cin>>foodid;
	FoodStore::addFood(foodid);
}
void UserInterface::LoggedInterface(UserProfile* loggedUser)
{
	int choice;
	do
	{
		cout<<"--------------------------------------------------"<<endl;
		cout<<"      User: "<<loggedUser->getUserName()<<endl;
		cout<<"--------------------------------------------------"<<endl;

		cout<<"Menu   "<<endl<<"1.Food"<<endl
			<<"2.Daily Calorie Information"<<endl
			<<"3.Display My Food"<<endl
			<<"4.Add To My Food"<<endl
			<<"5.Undo Last"<<endl;

		cout<<"6.Change User Details"<<endl;
		cout<<"7.Change Logs"<<endl;
		cout<<"Enter Your Choice:";

		cin>>choice;

		switch(choice)
		{
		case 1:
			FoodInterface();
			break;
		case 2:
			calcationInterface(loggedUser);
			break;
		case 3:
			FoodStore::displayFood();
			break;
		case 4:
			AddFoodInterface();
			break;
		case 5:
			break;
		case 6:
			changeUserDetails(loggedUser);
			break;
		}

	}while(1);

}




