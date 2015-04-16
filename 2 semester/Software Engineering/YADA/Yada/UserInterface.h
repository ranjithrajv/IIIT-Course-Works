/*
 * UserInterface.h
 *
 *  Created on: Mar 21, 2014
 *      Author: YBAR
 */
#include "UserProfile.h"
#ifndef USERINTERFACE_H_
#define USERINTERFACE_H_


class UserInterface
{

public :
	void FoodInterface();
	void changeUserDetails(UserProfile* loggeduser);
	void LoggedInterface(UserProfile* loggedUser);
	void calcationInterface(UserProfile *user);
	void AddFoodInterface();


};

#endif /* USERINTERFACE_H_ */
