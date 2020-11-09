#!/usr/bin/python
#Autor: Andy Schleising
#simple Example, benoetigt "==", da sonst kein gueltiger Value
import sys
import base64
print(base64.b32encode(sys.argv[1]+"==") )
