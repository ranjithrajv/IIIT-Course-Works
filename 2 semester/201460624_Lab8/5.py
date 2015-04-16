#!usr/bin/env python
from numpy import *
a=random.rand(9,3)
a[0:9:1,0:3:2] = [0,0]
#a[1:8:2,1] = [0]
print a
