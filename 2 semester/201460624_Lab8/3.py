#!usr/bin/env python
from numpy import *
a = array([[1,1,1],[0,2,5],[2,5,-1]])
b = array([6,-4,27])
print a
print b
print "Solved Linear Equation : ", linalg.solve(a,b)
