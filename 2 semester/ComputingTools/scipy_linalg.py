#!usr/bin/env python
from scipy.linalg import *
from scipy import *
A = array([[1,2],[3,4]])
B = array([[4,2],[16,4]])
print dot(A,B.T) #Matrix multiplication
print inv(A) #Inverse(A.I also works)
print det(A) #Determinant
print norm(A) #Norm
print eig(A) #eigen value and vector
print inv(A).dot(B)
#eval, evact = eig(A)
#print eval, evact
