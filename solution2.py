#!/usr/bin/env python

'''Write a python class in file solution2.py titled file_to_db in . The class should have following properties:
1. This class should accept hostname, username, password and database name as constructor arguments. If the database connection fails then the object with given values should not get created.
   
2. The class should have function file_to_table which takes three arguments file-name, table-name and regular expression. The class should create a table with given name to store varchar(2000) type lines. All the lines from given file should be read and only the lines which have strings matching given regular expression should be inserted into table. The match for regular expression can be anywhere in the line and not just in the beginning.
  
3. The class should have function table_to_file which takes three arguments file-name, table-name and regular expression. The class should read from the table assuming there is only one column. All the table rows which satisfy given regular expression should be written to the file on separate lines.
   
4. The class should have function close_db to close connection to db created during object construction.
  
5. In case filename provided for reading does not exists the program should print general error message but it should not crash. Similarly if file cannot be created for writing or if the database connection closes unexpectedly, a proper easy to understand english error message should be shown to the user and the error message thrown by python with line number etc. should not be displayed.'''


import MySQLdb, os, re

class file_to_db(object):
  db=''
  cursor=''
  def __init__(self,hostname,username,password,database):
    try:
      file_to_db.db=MySQLdb.connect(hostname,username,password,database)
    except:
      print "!!!Failed to connect to database!!!"
    else:
      print "Database connection successful."
      self.hostname=hostname
      self.username=username
      self.password=password
      self.database=database


  def file_to_table(self,file_name,table_name,regex):
    self.flag=0
    
    try:
      file_to_db.db=MySQLdb.connect(self.hostname,self.username,self.password,self.database)
      file_to_db.cursor=file_to_db.db.cursor()
    except:
      print "!!!No objects were created due to connection failure!!!"
    else:
      try:
        self.sql="""USE %s""" %(self.database)
        file_to_db.cursor.execute(self.sql)
      except:
        print "!!!No such database exist or database name not specified into object!!!"
      else:
        self.sql="""SELECT * FROM information_schema.tables WHERE table_schema='%s' AND table_name='%s' LIMIT 1""" %(self.database,table_name)
        self.tracker=file_to_db.cursor.execute(self.sql)
  
        if self.tracker==0:
          self.sql="""CREATE TABLE %s(Matches VARCHAR(2000))""" %(table_name)
          file_to_db.cursor.execute(self.sql)

        if os.path.isfile(file_name):
          with open(file_name) as fileobject:
            for line in fileobject:
              if re.search("\n",line):
                string=re.sub("\n","",line)
              string=line.strip()
              self.list_of_matches=re.findall(regex,string)
              if len(self.list_of_matches)>0:
                self.flag=1
                self.sql="INSERT INTO %s(Matches) VALUES('%s')""" %(table_name,re.sub("\n","",string.strip()))
              try:
                file_to_db.cursor.execute(self.sql)
                file_to_db.db.commit()
              except:
                file_to_db.db.rollback()
          fileobject.close()

          if self.flag==1:
            print "Match found. Values stored in the specified table."
          else:
            print "!!!No match found for the specified regex!!!"

        else:
          print "!!!No such file exist in the current path to read from!!!"


  def table_to_file(self,file_name,table_name,regex):
    self.flag=0
   
    try:
      file_to_db.db=MySQLdb.connect(self.hostname,self.username,self.password,self.database)
      file_to_db.cursor=file_to_db.db.cursor()
    except:
      print "!!!No objects were created due to connection failure!!!"
    else:
      try:
        self.sql="""USE %s""" %(self.database)
        file_to_db.cursor.execute(self.sql)
      except:
        print "!!!No such database exist or database name not specified into object!!!"
      else:
        self.sql="SELECT * FROM information_schema.tables WHERE table_schema='%s' AND table_name='%s' LIMIT 1" %(self.database,table_name)
        self.tracker=file_to_db.cursor.execute(self.sql)
  
        if self.tracker==0:
          print "!!!No such table exist in the database!!!"

        else:
          try:
            f=open(file_name,"w")
          except:
            print "!!!File name specified cannot be created!!!"
          else:
            self.flag=1

            self.sql="""SELECT * FROM %s LIMIT 1""" %(table_name)
            file_to_db.cursor.execute(self.sql)
            file_to_db.cursor.fetchone()
            self.tracker=file_to_db.cursor.description
            self.columns=self.tracker[0][0]

            self.sql="""SELECT * FROM %s WHERE %s REGEXP '%s'""" %(table_name,self.columns,regex)
            try:
              file_to_db.cursor.execute(self.sql)
              self.fields=file_to_db.cursor.fetchall()
              file_to_db.db.commit()
            except:
              print "!!!Values cannot be extracted from the table!!!"
              file_to_db.db.rollback()

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
    try:
      file_to_db.db=MySQLdb.connect(self.hostname,self.username,self.password,self.database)
      file_to_db.cursor=file_to_db.db.cursor()
      file_to_db.db.close()
    except:
      print "!!!No objects were created due to connection failure!!!"
    else:
      print "Connection to database was closed successfully."
