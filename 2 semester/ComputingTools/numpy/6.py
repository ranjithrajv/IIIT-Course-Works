from numpy import *
from scipy.stats import *
mu, sigma = 100, 10
d = random.normal(mu,sigma,5000)
print array(d)
print "\nMaximum  of Dist:  ", max(d)
print "Minimum  of Dist:  ", min(d)
print "Mean     of Dist:  ", mean(d)
print "Variance of Dist:  ", var(d)
print "Skew     of Dist:  ", skew(d)
print "Kurtosis of Dist:  ", kurtosis(d)
