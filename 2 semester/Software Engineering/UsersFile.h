#include "Header.h"
#include "UserProfile.h"

using namespace std;

class UsersFile{

public:
	vector<UserProfile> users;

	void add(UserProfile up);
	void save();
	vector<UserProfile> getUserList();

	void show();
	void driver();

};
