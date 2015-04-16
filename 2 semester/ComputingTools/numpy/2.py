from numpy import *

a = [[1,2,3],[4,5,6],[7,8,9]]
b = [[9,8,7],[6,5,4],[3,2,1]]
print "Matrix 1:\n",array(a),"\nMatrix 2:\n",array(b),"\nMultiplication by NumPy:\n",array(dot(a,b))


c = zeros((9,),dtype=int).reshape(3,3)
for i in range(len(a)):
	for j in range(len(b[0])):
		for k in range(len(b)):
			c[i][j]+=a[i][k]*b[k][j]
d=[]
for m in c:
	d.append(m)
print "Multiplication py Math algorithm :\n",array(d)


if (dot(a,b)==array(d)).all():
	print "\nSame, when compared"
else:
	print "\nNot Same, when compared"
