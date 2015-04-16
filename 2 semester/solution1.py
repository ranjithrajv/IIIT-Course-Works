#usr/bin/env python
from MySQLdb import connect

hostname   = raw_input("Enter the server address : ")
username = raw_input("Enter the username       : ")
password = raw_input("Enter the password       : ")
database = raw_input("Enter the database name  : ")
try:
	connect(hostname,username,password,database)
except:
	print "Oops!  Couldn't connecct to MySQLdb.  Try again..."
else:
	print "Success"
