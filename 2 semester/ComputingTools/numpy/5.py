from numpy import *
cartesian = random.randn(100,2)
x,y = cartesian[:,0],cartesian[:,1]
print array(x),array(y)
print array([sqrt(x**2 + y**2), arctan2(y,x)])
