#!/usr/bin/python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
k = int(cmdlinearg('k'))
s = int(cmdlinearg('s'))
blim = int(cmdlinearg('b'))
dlim = int(cmdlinearg('d'))

fruits = []

for _ in range(k-s):
	b = rand.randint(0, blim)
	c = rand.randint(0, 1e9)
	d = rand.randint(0, dlim)
	fruits.append[(b,c,d)]

for _ in range(k-s, k):
	i = rand.randint(0, k-s-1)
	b = fruits[i][0]
	c = fruits[i][1]
	d = fruits[i][2]
	fruits.append[(b,c,d)]

for i in range(0,k):
	print(fruits[i][0], fruits[i][1], fruits[i][2])