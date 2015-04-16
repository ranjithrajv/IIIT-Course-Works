#!usr/bin/env python
from MySQLdb import connect
from re import *
class file_to_db(object):
	def __init__(self,hostname,username,password,database):
		try:
			self.db = connect(hostname,username,password,database)
	    		self.cursor = self.db.cursor()
			print "Success"
		except:
			print "Failed"
			print "No values are saved for objects"
		else:
			self.hostname = hostname
			self.username = username
			self.password = password
			self.database = database
			print "Object has been created"
	def file_to_table(self,file_name,table_name,RegEx):
		self.db = connect(self.hostname,self.username,self.password,self.database )
		self.cursor = self.db.cursor()

		self.cursor.execute("USE %s" %(self.database))

		self.cursor.execute("DROP TABLE IF EXISTS %s" %(table_name))

		# Create table as per requirement
		sql = """CREATE TABLE """+table_name+""" (File_Lines  VARCHAR(2000) NOT NULL)"""
		self.cursor.execute(sql)
		
		f=open(file_name,"r")
		g=f.readlines()
		for i in g:
			if search(RegEx,i)>0:
				sql1 = """INSERT INTO %s VALUES ('%s')""" %(table_name,i)
				try:
				   # Execute the SQL command
			   		self.cursor.execute(sql1)
				   # Commit your changes in the database
			   		self.db.commit()
				except:
				   # Rollback in case there is any error
			  		print "Error !" 
			  		self.db.rollback()
	
	def table_to_file(self,file_name,table_name,regexp):
		pass
	def close_db(self):
		self.db.close()
p=file_to_db('localhost','root','password','test')
p.file_to_table('lines.txt','test_table','^.*$')
#p.table_to_file('l.txt','asdf','*.+')
p.close_db()
