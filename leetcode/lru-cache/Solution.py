class Node:

    def __init__ (self, key: int, val: int):
        self.key = key
        self.val = val
        self.next = self.prev = None

class LRUCache:

    def __init__(self, capacity: int):

        self.cap = capacity
        self.cache = {}

        self.left = Node(0, 0)
        self.right = Node(0, 0)
        self.left.next, self.right.prev = self.right, self.left

    def remove(self, node: Node):
        prev, next = node.prev, node.next
        prev.next, next.prev = next, prev

    def insert(self, node: Node):

        prev, next = self.right.prev, self.right
        node.prev, node.next = prev, next

    def get(self, key: int) -> int:

        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val

        return -1
        
    def put(self, key: int, val: int) -> None:

        if key in self.cache:
            self.remove(self.cache[key])

        node = Node(key, val)
        self.cache[key] = node
        self.insert(node)

        if len(self.cache > self.cap):

            lru = self.left.next
            self.remove(lru)
            del self.cache[lru]
            
# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)