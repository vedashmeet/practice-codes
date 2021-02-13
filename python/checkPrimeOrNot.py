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
    print(str(num) + " is a prime number")
else:
    print(str(num) + " is not a prime number")
