class Node:
    def __init__(self, data):
        self.left = None
        self.right = None
        self.data = data
def inOrder(root, arr):
    if not root:
        return
    inOrder(root.left, arr)
    arr.append(root.data)
    inOrder(root.right, arr)
    return arr
def preOrder(root, arr):
    if not root:
        return
    arr.append(root.data)
    preOrder(root.left, arr)
    preOrder(root.right, arr)
    return arr
def postOrder(root, arr):
    if not root:
        return
    postOrder(root.left, arr)
    postOrder(root.right, arr)
    arr.append(root.data)
    return arr
def invalid(root):
    print("\nInvalid choice!\n")
def operation(root, choice):
    switch = {
            1: inOrder,
            2: preOrder,
            3: postOrder
            }
    print(switch.get(choice, invalid)(root, []))
def insertIntoTree(temp, data):
   que = []
   que.append(temp)
   while (len(que)):
      temp = que[0]
      que.pop(0)
      if (not temp.left):
         temp.left = Node(data)
         break
      else:
         que.append(temp.left)
      if (not temp.right):
         temp.right = Node(data)
         break
      else:
         que.append(temp.right)
def createTree(elements):
   root = Node(elements[0])
   for element in elements[1:]:
      insertIntoTree(root, element)
   return root

elements = input("Enter the elements of tree as [12, 99.99, \"Hello\"]: ")
root = createTree(elements)
while True:
    print("Press 1 to in-order traverse")
    print("Press 2 to pre-order traverse")
    print("Press 3 to post-order traverse")
    print("Press 4 to exit\n")
    choice = input("Enter your choice: ")
    if choice == 4:
        break
    operation(root, choice)
