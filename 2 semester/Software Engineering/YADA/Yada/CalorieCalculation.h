#include "UserProfile.h"

class IDietCalculator
{
public:
	virtual double getTargetCalorieIntake(UserProfile *user)=0;
};

class BMRBasedDietCalculator :public IDietCalculator
{
	public:
	/*virtual*/

	double getTargetCalorieIntake(UserProfile *user);

};

class RMRBasedDietCalculator :public IDietCalculator
{

	/*virtual*/

	double getTargetCalorieIntake(UserProfile *user);
}
;
