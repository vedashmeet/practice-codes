num1 = input("Enter the first number: ")
num2 = input("Enter the second number: ")
num3 = input("Enter the third number: ")
if num1 > num2:
    if num1 > num3:
        print(str(num1) + " is greater")
    else:
        print(str(num3) + " is greater")
else:
    print(str(num2) + " is greater")
