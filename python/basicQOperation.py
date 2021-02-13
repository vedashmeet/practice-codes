def enQueue():
    queue.append(input("Enter data to enter into queue: "))
def deQueue():
    queue.pop(0) if len(queue) else "Queue is empty"
def printQueue():
    print("The queue is " + str(queue)) if len(queue) else "Queue is empty"
def invalid():
    print "\nInvalid choice!\n"
def operation(choice):
    switch = {
            1: enQueue,
            2: deQueue,
            3: printQueue
            }
    switch.get(choice, invalid)()
queue = []
while True:
    print("\nPress 1 to enqueue")
    print("Press 2 to dequeue")
    print("Press 3 to print queue")
    print("Press 4 to exit\n")
    choice = input("Enter your choice: ")
    if choice == 4:
        break
    operation(choice)
