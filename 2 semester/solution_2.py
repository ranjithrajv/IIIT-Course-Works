#!/usr/bin/python
import MySQLdb
import sys
import re
import mysql.connector
class file_to_db:
	def __init__(self,host,user,passwd,db):
		self.host=host
		self.user=user
		self.passwd=passwd
		self.db=db
		try:
			self.tty=MySQLdb.connect(host=self.host,user=self.user,passwd=self.passwd,db=self.db)
		except:
			exit()
		else:
			print 'object created'
	def file_to_table(self,file_name,table_name,regexp):
		self.file_name=file_name
		self.table_name=table_name
		self.regexp=regexp

		cur=self.tty.cursor()
		cur.execute("DROP TABLE IF EXISTS "+ self.table_name)

		sql="CREATE TABLE "+ self.table_name + "(line varchar(2000));"
		cur.execute(sql)

		fobj=open(self.file_name,'a')
		q=raw_input("enter a line :")
		fobj.write('%s'%q)
		fobj.close()
		try:
			fobj=open(self.file_name,'r')
			self.q1=fobj.readlines()
			fobj.close()
		except:
			print "unable to reas file"
		print self.q1
		line_inserted=[]
		try:
			for i in self.q1:
				print i
				print self.regexp
				print re.match(self.regexp,i)
				print "*********"
				if re.search(self.regexp,i)!=None:
					line_inserted.append(i)
					sql1=("insert into %s values(%s)"%(self.table_name,i.rstrip()))
					cur.execute(sql1)
					cur.execute('commit')
					print line_inserted
				else:
					continue
		except:
			print "unable to insert into table"

	def table_to_file(self,file_name,table_name,regexp):
		self.file_name=file_name
		self.table_name=table_name
		self.regexp=regexp
		cur=self.tty.cursor()
		updatefile=open(self.file_name,'w')
		line_inserted=[]
		try:
			for i in self.q1:
				ii=i.split()
				for x in ii:
					if (re.match(self.regexp,i)!=None):
						line_inserted.append(i)
						sql1=("insert into %s values(%s)"%(self.table_name,i.rstrip()))
						cur.execute(sql1)
						cur.execute('commit')
						print line_inserted
					else:
						continue
				for j in line_inserted:
					LINE=j
					updatefile.write('%s\n'%(LINE,))
					updatefile.close()
		except:
			print "unable to insert into file"

	def close_db(self):
		cur=self.tty.cursor()
		cur.close()	


			

p=file_to_db('127.0.0.1','root','password','alumni')
p.file_to_table('l.txt','asdf','*.+')
p.table_to_file('l.txt','asdf','*.+')
p.close_db()



		





















