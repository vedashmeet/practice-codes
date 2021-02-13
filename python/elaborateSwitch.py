def add():
    num1 = input("Enter the first number: ")
    num2 = input("Enter the second number: ")
    return "Sum of " + str(num1) + " and " + str(num2) + " is " + str(num1 + num2)
def subtract():
    num1 = input("Enter the first number: ")
    num2 = input("Enter the second number: ")
    return "Difference between " + str(num1) + " and " + str(num2) + " is " + str(num1 - num2)
def multiply():
    num1 = input("Enter the first number: ")
    num2 = input("Enter the second number: ")
    return "Multiplication of " + str(num1) + " and " + str(num2) + " is " + str(num1 * num2)
def division():
    num1 = input("Enter the first number: ")
    num2 = input("Enter the second number: ")
    return "Division of " + str(num1) + " by " + str(num2) + " is " + str(num1 / num2)
def checkEvenOdd():
    num = input("Enter any number: ")
    return str(num) + " is odd" if num % 2 else str(num) + " is even"
def checkPrime():
    num = input("Enter any number: ")
    i = 2
    count = 0
    while i <= num:
        if num % i == 0:
            count += 1
        if count > 1:
            break
        i += 1
    if count == 1:
        return str(num) + " is a prime number"
    else:
        return str(num) + " is not a prime number"
def printPrimes():
    prime = []
    rangeOf = input("Enter the range from 0 to : ")
    for num in range(2, rangeOf):
        count = 0
        for i in range(2, num + 1):
            if num % i == 0:
                count += 1
            if count > 1:
                break
        if count == 1:
            prime.append(str(num));
    return prime;
def invalid():
    return "\nInvalid choice!\n"
def calculator(choice):
    switch = {
            1: add,
            2: subtract,
            3: multiply,
            4: division,
            5: checkEvenOdd,
            6: checkPrime,
            7: printPrimes
            }
    print(switch.get(choice, invalid)())
while True:
    print("\nPress 1 for addition")
    print("Press 2 for subtraction")
    print("Press 3 for multiplication")
    print("Press 4 for division")
    print("Press 5 to check whether the number is even or odd")
    print("Press 6 to check whether a number is prime or not")
    print("Press 7 to print prime number in range")
    print("Press 8 to exit\n")
    choice = input("Enter your choice: ")
    if choice == 8:
        break
    calculator(choice)
