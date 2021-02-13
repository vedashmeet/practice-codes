rangeOf = input("Enter the range from 0 to : ")
for num in range(2, rangeOf):
    count = 0
    for i in range(2, num + 1):
        if num % i == 0:
            count += 1
        if count > 1:
            break
    if count == 1:
        print(str(num) + " is a prime number")       
