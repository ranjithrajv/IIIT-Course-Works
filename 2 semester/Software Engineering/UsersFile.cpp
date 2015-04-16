#include "Header.h"
#include "UsersFile.h"
#include <stdlib.h>



void UsersFile::add(UserProfile up)
{
	users.insert(users.end(),up);
	save();
}

void UsersFile::save()
{

	std::string line;
	std::ofstream file("UserProfileDb");
	std::vector<UserProfile>::iterator it;

	if (file.is_open())
	{
		for (it = users.begin(); it != users.end(); ++it)
		{
			file << it->getUserName() << " " << it->getAge() << " " << it->getGender() << " ";
			file << it->getHeight() << " " << it->getWeight() << " " << it->getActivityLevel() << "\n";

		}

		file.close();
	}
	else
	{
		std::cout << "Error In users Database File ";
		exit(0);
	}

}

vector<UserProfile> UsersFile::getUserList()
{
	std::string line;
	std::ifstream file("UserProfileDb");
	int val;
	bool boolval;

	if (file.is_open())
	{
		users.clear();
		UserProfile *p;

		while (file >> line)
		{

			p = new UserProfile();
			p->setUserName(line);
			file >> val;
			p->setAge(val);
			file >> boolval;
			p->setGender(boolval);
			file >> val;
			p->setHeight(val);
			file >> val;
			p->setWeight(val);
			file >> val;
			p->setActivityLevel(val);

			users.insert(users.begin(),*p);

		}

		file.close();
	
	}
	else
	{
		std::cout << "Error In users Database File ";
		exit(0);
	}

	return users;
}
/*TEST Functions*/
void UsersFile::driver()
{

	UserProfile P1("Mahesh", true, 21, 60, 186, 20);
	UserProfile P2("X23", false, 24, 70, 196, 40);
	UserProfile P3("MGR", true, 21, 67, 106, 50);
	add(P1);
	add(P2);
	add(P3);

}

void UsersFile::show()
{
	std::vector<UserProfile>::iterator it;
	for (it = users.begin(); it != users.end(); ++it)
	{
		cout << it->getUserName() << " " << it->getAge() << " " << it->getGender() << " ";
		cout << it->getHeight() << " " << it->getWeight() << " " << it->getActivityLevel() << "\n";

	}
}
