class Node:

    def __init__(self, key, val) -> None:
        self.key = key
        self.val = val
        self.next = None

class MyHashMap:

    def __init__(self):
        self.hash_map = [Node(-1, -1) for x in range(1000)]

    def put(self, key: int, value: int) -> None:
        hash_val = key % len(self.hash_map)
        head = self.hash_map[hash_val]

        while head.next:

            if head.next.key == key:
                head.next.val = value
                return
            head = head.next

        head.next = Node(key, value)        

    def get(self, key: int) -> int:
        hash_val = key % len(self.hash_map)
        head = self.hash_map[hash_val]

        while head.next:
            if head.next.key == key:
                return head.next.val
            head = head.next
        return -1
        

    def remove(self, key: int) -> None:
        hash_val = key % len(self.hash_map)
        head = self.hash_map[hash_val]

        while head and head.next:

            if head.next.key == key:
                head.next = head.next.next
            head = head.next

def main():

    hs = MyHashMap()

    hs.put(1,1)
    hs.put(2,2)
    hs.get(1)
    hs.get(3)
    hs.put(2,1)
    hs.get(2)
    hs.remove(2)
    hs.get(2)

if __name__ == "__main__":
    main()
# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)