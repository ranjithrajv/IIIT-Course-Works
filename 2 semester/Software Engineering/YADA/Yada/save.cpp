#include "headers.h"
#include "save.h"


Save::Save(Save::myMap &initialSimple, Save::myMap &initialComposite, Save::myMap &simpleDatabase, Save::myMap &compositeDatabase)
{
	saveData("simpleFoodDb", initialSimple, simpleDatabase);
	saveData("compositeFoodDb", initialComposite, compositeDatabase);
}

void Save::saveData(string sourceName, Save::myMap &initial, Save::myMap &data)
{
	const char *src = sourceName.c_str();
	ofstream myFile(src,ios::app);

	map<string, list<string> >::iterator iter;
	for (iter = data.begin(); iter!=data.end();++iter)
	{
		map<string,list<string> >::const_iterator it = initial.find(iter->first);
		if (it==initial.end())
		{
			myFile << iter->first;
			list<string> details = iter->second;
			list<string>::iterator iter2;
			for (iter2 = details.begin(); iter2!=details.end();++iter2)
			{
				myFile << "|" + *iter2;
			}
			myFile << "\n";
		}
	}

	myFile.close();
}
