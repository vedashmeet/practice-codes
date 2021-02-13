def push():
    stack.append(input("Enter data to push into stack: "))
def pop():
    stack.pop() if len(stack) else "Stack is empty"
def printStack():
    print("The stack is " + str(stack)) if len(stack) else "Stack is empty"
def invalid():
    print "\nInvalid choice!\n"
def operation(choice):
    switch = {
            1: push,
            2: pop,
            3: printStack
            }
    switch.get(choice, invalid)()
stack = []
while True:
    print("\nPress 1 to push")
    print("Press 2 to pop")
    print("Press 3 to print stack")
    print("Press 4 to exit\n")
    choice = input("Enter your choice: ")
    if choice == 4:
        break
    operation(choice)
