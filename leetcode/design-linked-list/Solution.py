class Node:
   
   def __init__(self, val, nextNode = None, prevNode = None):

    self.val = val
    self.next = nextNode
    self.prev = prevNode

class MyLinkedList:

    def __init__(self):
        self.idx = 0
        self.head = Node(-1)
        self.tail = Node(-2, prevNode=self.head)
        self.head.next = self.tail

    def get(self, index: int) -> int:

        if index >= self.idx:
           return -1

        tmp = self.head.next
        for _ in range(index):
           tmp = tmp.next

        return tmp.val

    def addAtHead(self, val: int) -> None:

        self.idx += 1
        newNode = Node(val, nextNode=self.head.next, prevNode=self.head)
        self.head.next.prev = newNode
        self.head.next = newNode

    def addAtTail(self, val: int) -> None:
       
        self.idx += 1
        newNode = Node(val, nextNode=self.tail, prevNode=self.tail.prev)
        self.tail.prev.next = newNode
        self.tail.prev = newNode

    def addAtIndex(self, index: int, val: int) -> None:

        if index > self.idx:
           return -1

        self.idx += 1
        newNode = Node(val)
        tmp = self.head.next
        for _ in range(index):
           tmp = tmp.next

        newNode.prev = tmp.prev
        newNode.prev.next = newNode
        newNode.next = tmp
        tmp.prev = newNode

    def deleteAtIndex(self, index: int) -> None:

        if index >= self.idx:
           return -1

        self.idx -= 1
        tmp = self.head.next
        for _ in range(index):
           tmp = tmp.next

        tmp.prev.next = tmp.next
        tmp.next.prev = tmp.prev

def main() -> int:

    mll = MyLinkedList()

    mll.addAtHead(7)
    mll.addAtHead(2)
    mll.addAtHead(1)
    mll.addAtIndex(3, 0)
    mll.deleteAtIndex(2)
    mll.addAtHead(6)
    mll.addAtTail(4)
    print(f"val: {mll.get(4)}")
    mll.addAtHead(4)
    mll.addAtIndex(5, 0)
    mll.addAtHead(6)

if __name__ == "__main__":
   main()