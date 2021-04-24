print("hello world")
print("\nERROR: you are printing 100 squares \n")
print("I want only 99 donot include \"0 x 0 = 0\"\n")
i = 0
while i < 100:
    string = str(i) + " x " + str(i) + " = " + str(i*i)
    print(string)
    i = i+1
