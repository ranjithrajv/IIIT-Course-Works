#!usr/bin/env python
from numpy import *
x = array([[1,2,3],[4,5,6]])
y = x[0:,1:]
z = random.randn(4,4)
w = y.shape+z.shape
print y
print z
print w
