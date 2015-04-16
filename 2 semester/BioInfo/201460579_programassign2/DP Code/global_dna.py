#!/usr/bin/env python

def initialize(dimension):
  dp_table=[]

  for i in range(dimension[0]):
    dp_table.append([])
    for j in range(dimension[1]):
      dp_table[-1].append(0)

  return dp_table



def compare(a,b):
  if a==b:
    return match
  elif a=='-' or b=='-':
    return gap_penalty
  else:
    return mismatch



def parameters(align1,align2):
  align1=align1[::-1]    
  align2=align2[::-1]    
  i,j=0,0
  symbol=''
  found=[]
  temp_score=0
  same=0

  for i in range(0,len(align1)):
    if align1[i]==align2[i]:
      symbol=symbol+align1[i]
      temp_score+=compare(align1[i],align2[i])
      same+=1
    elif align1[i]!=align2[i] and align1[i]!='-' and align2[i]!='-': 
      symbol=symbol+' '
      temp_score+=compare(align1[i],align2[i])
      found.append(0)
    elif align1[i]=='-' or align2[i]=='-':          
      symbol=symbol+' '
      temp_score+=gap_penalty
  
  score.append(temp_score)
  identity.append(same) 
  length.append(len(align1))   
  f=open("log_needle_dna.txt","a")
  f.write(str(line1[0][1])+":\t"+align1+"\n"+"\t\t"+symbol+"\n"+str(line2[0][1])+":\t"+align2+"\n\n")
  f.close()



def traceback(i,j,matrix,s1,s2):
  align1,align2='',''

  while i>0 and j>0:
    current=matrix[i][j]
    diagonal=matrix[i-1][j-1]
    up=matrix[i][j-1]
    left =matrix[i-1][j]

    if current==diagonal+compare(s1[i-1],s2[j-1]):
      align1+=s1[i-1]
      align2+=s2[j-1]
      i=i-1
      j=j-1
    elif current==left+gap_penalty:
      align1+=s1[i-1]
      align2+='-'
      i=i-1
    elif current==up+gap_penalty:
      align1+='-'
      align2+=s2[j-1]
      j=j-1

  while i>0:
    align1+=s1[i-1]
    align2+='-'
    i=i-1

  while j>0:
    align1+='-'
    align2+=s2[j-1]
    j=j-1

  parameters(align1,align2)
  


def global_align(seq1,seq2):
  for string in seq1:
    m=len(string)
    s1=str(string)

  for string in seq2:
    n=len(string)
    s2=str(string) 

  matrix=initialize((m+1,n+1)) 

  for i in range(0,m+1):
    matrix[i][0]=gap_penalty*i
 
  for j in range(0,n+1):
    matrix[0][j]=gap_penalty*j

  for i in range(1,m+1):
    for j in range(1,n+1):
      match=matrix[i-1][j-1]+compare(s1[i-1],s2[j-1])
      delete=matrix[i-1][j]+gap_penalty
      insert=matrix[i][j-1]+gap_penalty
      matrix[i][j]=max(match,delete,insert)

  traceback(m,n,matrix,s1,s2)
  


def read():
  import sys, time, os

  if os.path.isfile(sys.argv[1]) and os.path.isfile(sys.argv[2]):
    with open(sys.argv[1]) as f1:
      for line in f1:
        if line.startswith(">"):
          line1.append(line.split("|"))
        else:
          if line.strip()!='':
            total_seq1.append(line.splitlines()) 

    with open(sys.argv[2]) as f2:
      for line in f2:
        if line.startswith(">"):
          line2.append(line.split("|"))
        else:
          if line.strip()!='':
            total_seq2.append(line.splitlines()) 
    
    f1.close()
    f2.close()

    f=open("log_needle_dna.txt","w")
    f.write("########################################\n# Program: needle\n")
    f.write("# Rundate:"+time.strftime("%c")+"\n")
    f.write("# Align_format: pair\n# Report_file: log_needle.txt\n# Aligned_sequences: 2\n")
    f.write("# Seq1: "+line1[0][1]+"\n# Seq2: "+line2[0][1]+"\n")
    f.write("# Match: "+str(match)+"\n")
    f.write("# Mismatch: "+str(mismatch)+"\n")
    f.write("# Gap_penalty: "+str(gap_penalty)+"(Linear Gap Model)"+"\n")
    f.write("########################################\n\n")
    f.close()
  
    size=len(total_seq1) if len(total_seq1)<len(total_seq2) else len(total_seq2)

    for i in range(0,size):
      global_align(total_seq1[i],total_seq2[i])
    print "Alignment completed successfully. Results are stored in the file log_needle_dna.txt"

  else:
    print "!!!No such files(s) exist in current path!!!"



def main():
  import sys

  if len(sys.argv)==3:
    read()
    
  else:
    print "!!!Invalid number of command line arguments!!!"
    print "Usage: python global_dna.py <sequence file1> <sequence file2>"
    


match=1
mismatch=-2
gap_penalty=-2
total_seq1=[]
total_seq2=[]
score=[]
identity=[]
length=[]
line1=[]
line2=[]
main()
if len(score)>0:
  f=open("log_needle_dna.txt","a")
  f.write("\nIdentity: "+str(float(sum(identity))/sum(length)*100)+"%\n########################################")
  f.close()
