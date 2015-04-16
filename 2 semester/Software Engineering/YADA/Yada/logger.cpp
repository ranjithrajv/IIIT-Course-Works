#include <fstream>
#include <iostream>
#include<string.h>
#include<sstream>
#include<cstring>
#include<algorithm>
#include <limits>
#include <cstdlib>
#include <list>

using namespace std;

int file_lines(string filename )
{
	int numLines = 0;
	ifstream in(filename.c_str());
	std::string unused;
	while ( std::getline(in, unused) )
		++numLines;

	return numLines;
}

void sortfile(string filename)
{
  fstream outstream ;
	string line;int i=0 ;int id_p[1000];
	outstream.open(filename.c_str());
      while(getline(outstream, line))
		{
			string firstCharacter;
			stringstream ssin(line);
			ssin>>firstCharacter;
                         id_p[i]=atoi(firstCharacter.c_str());
                         i++;

             }
sort(  id_p,   id_p+file_lines(filename));


outstream.close();

string line_3;int j=0;
ofstream op_new;
op_new.open("temp.txt", std::ios_base::app | std::ios_base::out);

while(j<=file_lines(filename))
{
ifstream op;
op.open(filename.c_str());
 while(getline(op, line_3))
		{
			string first;
			stringstream ssin(line);
			ssin>>first;
                         if(id_p[j]==atoi(first.c_str()))
                         {op_new <<line_3;
                              
                             op.close();
                            op.clear();
                             break;
                  }
                      

             }
j++;
}
op_new.close();
remove(filename.c_str());
rename("temp.txt", filename.c_str());





         
}

void removelastline(string  filename)
{      fstream outstream ;
	string line_1;
	string line_2;
	outstream.open(filename.c_str());
	int num=file_lines(filename);
	cout <<num<<"lines"<<endl;
	while(! outstream.eof())
	{
		getline( outstream,line_1);
	}
	cout <<"line_1"<<line_1<<endl;
	outstream .close();
	outstream.clear();
	ifstream outstrea ;
	outstrea.open(filename.c_str(), std::ios_base::out );
	ofstream   outfile;  
	outfile.open("temp.txt",ios::app);
	//deletedlogs.open("deletedlogs.txt",ios::app);
	while(getline(outstrea, line_2))
	{       
		cout <<"line_2"<<line_2<<endl;

		if (line_1!= line_2 ||  num>1)
		{
			outfile<< line_2<< endl;
			//   cout <<"line_2"<<line_2<<endl;
		}
		else
		{     

			//deletedlogs<<line;
		}
		num=num-1;
	}

	outstrea.close();

	outfile.close();
	remove(filename.c_str());

	rename("temp.txt", filename.c_str());
}





/*fstream& GotoLine(fstream& file, unsigned int num){
  file.seekg(std::ios::beg);
  for(int i=0; i < num - 1; ++i){
  file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  }
  return file;
  }*/

class Logger
{   
	fstream m_pInputFile;
	ofstream   update;
	public:

	void addLog(string m)
	{    m_pInputFile.open("logfile.txt",std::ios_base::app | std::ios_base::out);

		m_pInputFile<<m;
		m_pInputFile.close();
		m_pInputFile.clear();

		m_pInputFile.open("update.txt", std::ios_base::app );
		m_pInputFile<<"Food added"<<endl;
		m_pInputFile.close();


	}
	void openLogFile(std::string fileName)
	{
		m_pInputFile.open(fileName.c_str(),std::ios_base::app | std::ios_base::out);
	}
	void closeLogFile()
	{
		m_pInputFile.close();
	}

	void deletelog(string id )
	{    string line;
		m_pInputFile.open("logfile.txt");
		ofstream   outfile;    ofstream   deletedlogs;
		outfile.open("temp.txt",ios::app);
		deletedlogs.open("deletedlogs.txt",ios::app);
		while(getline(m_pInputFile, line))
		{
			string firstCharacter;
			stringstream ssin(line);
			ssin>>firstCharacter;


			if (firstCharacter!= id)
			{
				outfile<< line << endl;
			}
			else
			{     

				deletedlogs<<line;

			}

		}

		m_pInputFile .close();

		outfile.close();
		deletedlogs.close();

		remove("logfile.txt");

		rename("temp.txt", "logfile.txt");
		update.open("update.txt", std::ios_base::app );
		update<<"log deleted"<<endl;
		update.close();

		//we have to save the deleted line in another file
	}
	void editlog(string id, string edited_string )
	{
		string line;
		m_pInputFile.open("logfile.txt");
		ofstream   outfile;   
		ofstream   editedlogs;
		outfile.open("temp.txt",ios::app);
		editedlogs.open("editedlogs.txt",ios::app);
		while(getline(m_pInputFile, line))
		{
			string firstCharacter;
			stringstream ssin(line);
			ssin>>firstCharacter;


			if (firstCharacter!= id)
			{
				outfile<< line << endl;
			}
			else
			{     

				editedlogs<<line;
				outfile<<edited_string;

			}

		}

		m_pInputFile .close();

		outfile.close();
		editedlogs.close();

		remove("logfile.txt");

		rename("temp.txt", "logfile.txt");


		update.open("update.txt", std::ios_base::app );
		update<<"log edited"<<endl;
		update.close();




	}  





	void undo()
	{  string line;
		string line_2;
		fstream out;
		out.open("logfile.txt", std::ios_base::app | std::ios_base::out );
		m_pInputFile.open("update.txt" );

		while(!  m_pInputFile.eof())
		{
			getline(m_pInputFile,line);
		}


		m_pInputFile.close();
		if (line=="log edited")
		{   removelastline("logfile.txt");
			ifstream editlogs;
			editlogs.open("editedlogs.txt");
			while(!  editlogs.eof())
			{
				getline(editlogs, line_2);
			}
			removelastline("logfile.txt");
			out<<line_2;
			removelastline("update.txt");
			removelastline("editedlogs.txt");
			editlogs.close();}
		else if (line=="log deleted")
		{ 
			ifstream deletelogs;
			deletelogs.open("deletedlogs.txt");
			while(!  deletelogs.eof())
			{
				getline(   deletelogs,line_2);
			}
			out<<line_2;
			removelastline("update.txt");
			removelastline("deletedlogs.txt");
			//sort_file("logfile.txt");









			deletelogs.close(); }
		else if (line=="Food added")
		{    removelastline("logfile.txt");
			removelastline("update.txt");}


		out.close();
	}

};



int xmain (int argc, char **argv)
{
	// cout <<"here" ;


	// Logger log=*Logger::Instance();
	Logger log;
	log.deletelog("12345");
	log.undo();
	log. openLogFile("logfile.txt");
	//   log.addLog("how are you");
	log. closeLogFile();
	// log.deleteLogger();*/
	return 0;
}

