#!usr/bin/env python

from scipy import *
p1 = array([1,2,-4,6])
p2 = array([2,4,0,7])
print polyadd(p1,p2) #sum of polynomials
print polymul(p1,p2) #product of polynomials
print polyval(p1,4) #evaluate polynomial for x=4
A=p1
print roots(A)      #find the roots of the polynomial
print polyder(A,10) #derivative of polynomial
print polyint(A,2)  #anti-derivative of polynomial
