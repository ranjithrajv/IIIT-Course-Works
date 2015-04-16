#include <iostream>
#include "UsersFile.h"
#include "header.h"
/*#include "save.h"*/

using namespace std;

/*Driver for class*/

UsersFile users;

UserProfile* check(string username,string password)
{
	vector<UserProfile> userlist = users.getUserList();
	vector<UserProfile>::iterator it;

	for(it=userlist.begin();it!=userlist.end();++it)
	{

		if(it->getUserName().compare(username)==0)
		{
			return  new UserProfile(it->getUserName(),it->getGender(),it->getAge(),it->getWeight(),it->getHeight(),it->getActivityLevel());
		}

	}

	return NULL;
}



int main()
{

	int count =0;
	string username;
	string password;
	do
	{
		cout<<"Yet Another Diet Manager";
		cout<<"login:";
		cin>>username;
		cout<<"password:";
		cin>>password;

		UserProfile* user;
		UserInterface ui;
		user=check(username,password);
		if (user!=NULL)
		{
			cout<<"Logging in : "<<user->getUserName()<<endl;

			ui.LoggedInterface(user);
		}
		else
		{
			cout<<"You have Entered Wrong Username or Password"<<endl;
		}

		count++;
	}while(count<2);

}

