#include "CalorieCalculation.h"
#include "UserProfile.h"

 


	double BMRBasedDietCalculator::getTargetCalorieIntake(UserProfile *user)
	{
		// Harris-Benedict equation for BMR
		if (user->getGender() == true)
		{
			return (13.75 * user->getWeight()) + (5 * user->getHeight()) - (6.76 * user->getActivityLevel()) + 66;
		}
		else
		{
			return (9.57 * user->getWeight()) + (1.85 * user->getHeight()) - (4.68 * user->getActivityLevel()) +655;
		}
	}




	double RMRBasedDietCalculator::getTargetCalorieIntake(UserProfile *user)
	{
		//Mufflin equation for RMR
		if (user->getGender() == true)
		{
			return (10 * user->getWeight()) + (6.25 * user->getHeight()) - (5* user->getActivityLevel()) + 5;
		}
		else
		{
			return (10 * user->getWeight()) + (6.25 * user->getHeight()) - (5 * user->getActivityLevel()) - 161;
		}

	}


