from numpy import *
print "3(a) \n"
a = random.randn(3,3)
b = random.randn(3,3)
print "Checking whether two randomly generated matrices will be equal OR not"
print a,"\n",b
if (a==b).all():
	print '\nTwo random matrices are equal\n'
else:
	print '\nTwo random matrices are not equal\n'

print "3(b) \n"
data = loadtxt('data.csv',delimiter=',',usecols=(6,),unpack=True)
print "Median is",median(data)
print "\nVariance is",var(data)
print "\nStd Dev is",std(data)
