#!/usr/bin/env python
# coding: utf-8
# 
# This script serves to create test cases
#  with complete graphs.
#

import sys
from random import randint


def genComplete(n):
  m = n*(n-1)/2
  print str(n) + ' ' + str(m)
  for i in range(0, n):
    for j in range(i+1, n):
      print str(i) + ' ' + str(j) + ' ' + str(randint(1, 100))
  


def main():
  if len(sys.argv) != 2:
    print 'Error: Invalid arguments'
    print 'Usage: ./' + str(sys.argv[0]) + ' [Number of nodes the complete graph will have]'
    return

  n = int(sys.argv[1])
  genComplete(n)


if __name__ == '__main__':
  main()
