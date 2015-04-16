#!usr/bin/env python
from math import *
from numpy import array
k=input("Enter value of k : ")
l0=input("Enter value of l0 : ")
x1 = input("Enter value of x1")
y1 = input("Enter value of y1")
z1 = input("Enter value of z1")
x2 = input("Enter value of x2")
y2 = input("Enter value of y2")
z2 = input("Enter value of z2")
l=(pow((x1-x2),2)+pow((y1-y2),2)+pow((z1-z2),2))**(1/2)
def function(a1,a2):
	f= k*(l-l0)*(a1-a2)*(pow((x1-x2),2)+pow((y1-y2),2)+pow((z1-z2),2))**(-1/2)
	return f
f1x = function(x1,x2)
f1y = function(y1,y2)
f1z = function(z1,z2)
f2x = function(x2,x1)
f2y = function(y2,y1)
f2z = function(z2,z1)
a = [[f1x,f1y,f1z],[f2x,f2y,f2z]]
print a
