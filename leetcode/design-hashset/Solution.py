class Node:

    def __init__(self, key: int):
        self.key = key
        self.next = None

class MyHashSet:

    def __init__(self):
        self.hash_set = [Node(-1) for i in range(10**4)]

    def add(self, key: int) -> None:
        hash_val = key % 10_000

        node = Node(key)
        head = self.hash_set[hash_val]

        while head.next:

            if head.key == key:
                return

            head = head.next

        if head.key != key:
            head.next = node

    def remove(self, key: int) -> None:
        hash_val = key % 10_000

        head = self.hash_set[hash_val]
        while head.next:

            if head.next.key == key:
                head.next = head.next.next
                break 

            head = head.next
        
    def contains(self, key: int) -> bool:
        hash_val = key % 10_000
        
        head = self.hash_set[hash_val]
        while head:
            if head.key == key:
                return True
            head = head.next

        return False

def main():

    hs = MyHashSet()
    hs.add(1)
    hs.add(2)
    hs.contains(1)
    hs.contains(3)
    hs.add(2)
    hs.contains(2)
    hs.remove(2)
    hs.contains(2)

if __name__ == "__main__":
    main()

# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)