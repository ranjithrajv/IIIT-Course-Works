#include "UserProfile.h"
#include "Header.h"
	
		void UserProfile::setUserName(std::string name)
		{
			userName = name;
		}

		void UserProfile::setGender(bool genderval)
		{
			gender = genderval;
		}

		void UserProfile::setAge(int ageval)
		{
			age = ageval;
		}

		void UserProfile::setWeight(int weightval)
		{
			weight = weightval;
		}

		void UserProfile::setHeight(int heightval)
		{
			height = heightval;
		}

		void UserProfile::setActivityLevel(int level)
		{
			activityLevel = level;
		}


		std::string UserProfile::getUserName()
		{
			return userName;
		}

		bool UserProfile::getGender()
		{
			return gender;
		}

		int UserProfile::getAge()
		{
			return age;
		}

		int UserProfile::getHeight()
		{
			return height;
		}

		int UserProfile::getWeight()
		{
			return weight;
		}

		int UserProfile::getActivityLevel()
		{
			return activityLevel;
		}

