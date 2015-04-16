#!usr/bin/env python
from MySQLdb import connect
from re import *
class file_to_db(object):
	def __init__(self,HostName,UserName,Password,DataBase):
		try:
			self.db = connect(HostName,UserName,Password,DataBase)
	    		self.cursor = self.db.cursor()
			print "Success"
		except:
			print "Failed"
			print "No values are saved for objects"
		else:
			self.HostName = HostName
			self.UserName = UserName
			self.Password = Password
			self.DataBase = DataBase
			print "Object has been created"
	def file_to_table(self,FileName,TableName,RegEx):
		self.db = connect(self.HostName,self.UserName,self.Password,self.DataBase )
		self.cursor = self.db.cursor()

		self.cursor.execute("USE %s" %(self.DataBase))

		self.cursor.execute("DROP TABLE IF EXISTS %s" %(TableName))

		# Create table as per requirement
		sql = """CREATE TABLE """+TableName+""" (File_Lines  VARCHAR(2000) NOT NULL)"""
		self.cursor.execute(sql)
		
		f=open(FileName,"r")
		g=f.readlines()
		for i in g:
			if search(RegEx,i)>0:
				sql1 = """INSERT INTO %s VALUES ('%s')""" %(TableName,i)
				try:
				   # Execute the SQL command
			   		self.cursor.execute(sql1)
				   # Commit your changes in the DataBase
			   		self.db.commit()
				except:
				   # Rollback in case there is any error
			  		print "Error !" 
			  		self.db.rollback()
	
	def table_to_file(self,FileName,TableName,RegEx):
		self.flag=0
               
		try:
			self.db=connect(self.HostName,self.UserName,self.Password,self.DataBase)
			self.cursor=self.db.cursor()
		except:
			print "!!!No objects were created due to connection failure!!!"
		else:
			try:
				self.sql="""USE %s""" %(self.DataBase)
				self.cursor.execute(self.sql)
			except:
				print "!!!No such DataBase exist or DataBase name not specified into object!!!"
			else:
				self.sql="SELECT * FROM information_schema.tables WHERE table_schema='%s' AND table_name='%s' LIMIT 1" %(self.DataBase,TableName)
				self.tracker=self.cursor.execute(self.sql)

				if self.tracker!=0:
	  
					try:
						f=open(FileName,"w")
					except:
						print "!!!File name specified cannot be created!!!"
					else:
						self.flag=1
						self.sql="""SELECT * FROM %s LIMIT 1""" %(TableName)
						self.cursor.execute(self.sql)
						self.cursor.fetchone()
						self.tracker=self.cursor.description
						self.columns=self.tracker[0][0]

						self.sql="""SELECT * FROM %s WHERE %s REGEXP '%s'""" %(TableName,self.columns,RegEx)
						try:
							self.cursor.execute(self.sql)
							self.fields=self.cursor.fetchall()
							self.db.commit()
						except:
							print "!!!Values cannot be extracted from the table!!!"
							self.db.rollback()
						try:
							if len(self.fields)>0:
								print "Match found in the database. Matches stored in the specified file."
								for values in self.fields:
									f.write(''.join(values)+"\n")
									f.close()
							elif len(self.fields)==0:
								print "!!!No match found in the database for the specified regex!!!"
						except:
							pass

	def close_db(self):
		self.db.close()
p=file_to_db('localhost','root','password','test')
p.file_to_table('lines.txt','test_table','^.*$')
p.table_to_file('lines2.txt','test_table','Hello')
p.close_db()
'''Please test run this programm with the given values in aboe 4 lines :)'''
