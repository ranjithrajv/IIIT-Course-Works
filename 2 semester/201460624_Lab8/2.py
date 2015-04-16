#!usr/bin/env python
from numpy import *
a=[[1,2],[3,4]]
b=[[6,7],[8,9]]
print a,b
print "Product  :",dot(a,b)
print "Transpose: ",transpose(a)
print "Inverse: ",linalg.inv(a)
print "Determinant: ",linalg.det(a)
