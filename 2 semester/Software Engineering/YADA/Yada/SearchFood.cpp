/*
 * Search.cpp
 *
 *  Created on: Mar 21, 2014
 *      Author: YBAR
 */

#include "SearchFood.h"

void Search::search(string keywords)
{
	cout<<"Searching In Food"<<endl;
	OrSearch(keywords);
}

void Search::OrSearch(string keywords)
{
	LoadFoodDb data;
	data.loadFood();

	typedef map<string,list<string> > myMap;
	myMap simpleDatabase = data.returnSimpleFoodKeyword();
	myMap compositeDatabase = data.returnCompositeFoodKeyword();

	SimpleFood simpleFood(simpleDatabase);
	CompositeFood compositeFood(compositeDatabase,simpleDatabase);


	/*Seach in SimpleFoodDb*/
	map<string,list<string> >::iterator it;
	list<string> searchlist;
	list<string>::iterator search_it;
	bool flag1=false;
	for(it=simpleDatabase.begin();it!=simpleDatabase.end();++it)
	{
		searchlist = it->second;
		for(search_it=searchlist.begin();search_it!=searchlist.end();++search_it)
		{
			if(search_it->compare(keywords)==0)
			{
				flag1=true;
				cout<<"found in Simple Food at "<<it->first;
				cout<<endl;
			}
		}
	}

	/*Seach in compositeFoodDb*/

	bool flag2=false;
	for(it=compositeDatabase.begin();it!=compositeDatabase.end();++it)
	{   
		searchlist = it->second;
		for(search_it=searchlist.begin();search_it!=searchlist.end();++search_it)
		{   
			if(search_it->compare(keywords)==0)
			{   
				flag2=true;
				cout<<"found in Composite Food at"<<it->first;
				cout<<endl;
			}   
		}   
	} 

	if(!flag1 && !flag2)
	{
		cout<<"Not Found Anywhere!"<<endl;
	}
}

void Search::AndSearch(string keywords)
{
	LoadFoodDb data;
	data.loadFood();
	typedef map<string,list<string> > myMap;
	myMap simpleDatabase = data.returnSimpleFoodData();
	myMap compositeDatabase = data.returnCompositeFoodData();

	SimpleFood simpleFood(simpleDatabase);
	CompositeFood compositeFood(compositeDatabase,simpleDatabase);

	/*Seach in SimpleFoodDb*/
	map<string,list<string> >::iterator it;
	list<string> searchlist;
	list<string>::iterator search_it;
	bool flag=false;
	for(it=simpleDatabase.begin();it!=simpleDatabase.end();++it)
	{
		searchlist = it->second;
		for(search_it=searchlist.begin();search_it!=searchlist.end();++search_it)
		{
			if(search_it->compare(keywords)==0)
			{
				flag=true;
				cout<<"found in "<<it->first;
				cout<<endl;
			}
		}
	}

	if(!flag)
	{
		cout<<"Not Found Anywhere!"<<endl;
	}

}
