#!usr/bin/env python
from scipy import *
import matplotlib as pl
from scipy.special import airy
from scipy import interpolate as Inter
#a = random.ranf((10))
b = range(-100,250,1)
#print a 
#print b
#Airy_solution1 = airy(a)
#print Airy_solution1
Airy_solution2 = airy(b)
#print Airy_solution2
#Interpolate = Inter.interp1d(x1,Airy_solution2)
#x=[1,200,300]
#for i in x:
Interpolate = Inter.interp1d(b,Airy_solution2)
f=open("x.txt","r")
k = f.readlines()
#print k
for i in k:
	i1 = float(i.replace('\n', ''))	
	print Interpolate(i1)
