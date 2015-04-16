#!usr/bin/env python
from Bio import pairwise2
seq1=raw_input("Enter the first sequence filename :")
seq2=raw_input("Enter the second sequence filename :")
global_alignments = pairwise2.align.globalxx(seq1,seq2)
print global_alignments
