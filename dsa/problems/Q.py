import helper.utilf as utilf
import sys
sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

n = int(input())
a = [int(x) for x in input().split()]

A = utilf.ListToTree(a)
print(A)
