import os

f = open("files.txt", "r")
i = 0

for x in f:
  print(x)
  str = "{}){}".format(i,x).strip()
  str += ".txt"
  print(str)
  # ff = open(str, "w")
  os.mkdir(str)
  i+=1