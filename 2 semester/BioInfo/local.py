#!usr/bin/env python
from Bio import pairwise2
seq1=raw_input("Enter the first sequence filename :")
seq2=raw_input("Enter the second sequence filename :")
local_alignments = pairwise2.align.localxx(seq1,seq2)
print local_alignments
