#ifndef USER
#define USER

#include "Header.h"

class UserProfile
{
private:
	std::string userName;
	bool gender;	// 0 - male 1 -female
	int age;
	int height;
	int weight;
	int activityLevel;	// in percentage

public:
	UserProfile(){}

	UserProfile(std::string name, bool genderval, int ageval, int weightval, int heightval, int activitylevelval)
	{
		setUserName(name);
		setGender(genderval);
		setAge(ageval);
		setWeight(weightval);
		setHeight(heightval);
		setActivityLevel(activitylevelval);
	}

	void setUserName(std::string name);
	void setGender(bool genderval);
	void setAge(int ageval);
	void setWeight(int weightval);
	void setHeight(int heightval);
	void setActivityLevel(int level);

	std::string getUserName();
	bool getGender();
	int getAge();
	int getHeight();
	int getWeight();
	int getActivityLevel();
};

#endif
