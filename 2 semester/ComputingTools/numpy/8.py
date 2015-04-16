#!usr/bin/env python
from numpy import *
import csv
objects = open("marks.csv")
data = csv.reader(objects)

print "\n\nBuilding student data"
students=[]
for i in data:
	students.append(i[1:])
students = array(students,dtype=float64)
print students

print "\n\nFinding Mean"
for i in range(len(students)):
	m=mean(students,axis=1)
	print "mean of marks of student %d is %f"%(i+1,m[i])

print "\n\nFinding Rank"
order = sort(m)[::-1]
ranks = argsort(order)[::-1]
for i in range(len(students)):
	for j in range(len(students)):
		if order[i]==m[j]:
			print "rank of %d student is %d"%(i+1,j+1)

print "\n\nFinding highest and lowest"
for i in range(len(students)):
	h = amax(students,axis=0)
	l = amin(students,axis=0)
	print "Highest of %d subjects is %f"%(i+1,h[i])
	print "Lowest  of %d subjects is %f\n"%(i+1,l[i])
