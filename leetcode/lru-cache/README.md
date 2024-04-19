146. LRU Cache
Medium
Topics
Companies

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

 

Constraints:

    1 <= capacity <= 3000
    0 <= key <= 104
    0 <= value <= 105
    At most 2 * 105 calls will be made to get and put.


Analisis:

    Despues de ver el video de Neetcode: https://www.youtube.com/watch?v=7ABFKPK2hD4&t=980s

    Hay que crear una estructura de datos lineal que permite borrar, crear y mover datos sin cambiar la estructura entera con acceso inmediato como un hash map. 
    
    La estructura de datos lineal es una linked list con doble nexo. Es lineal y se pueden borrar, crear y mover elementos de forma sencilla.

    Un diccionario cumple el acceso inmediato por key.

    La estructura de datos es un hash map de nodos. Cada nodo está conectado al adyacente y la key value permite acceder el nodod de forma inmediata.

    La estructura de datos solo puede contener max elementos, donde max es el valor que se asigna a la estructura de datos en el constructor.

    Left (LRU) | Right (MRU)
        Node        Node   

Algoritmo:

    Nodo:

        constructor: key, val, next=None, prev=None:

            .key = key
            .val = val
            .next = next
            .prev = prev

    LRUCache:

        constructor: max:

            .cache = start{}
            .max = max
            .left = Node(0,0)
            .right = Node(0,0)

        .get: key:

            if key in .cache 
                .remove(.cache.key)
                .insert(.cache.key)
                return .cache.key.val
            return -1

        .put: key, val:

            if key in cache:
                .remove(.cache.key)
            .cache.key = .Node(key, val)
            .insert(.cache.key)

            if len(.cache) > .max:

        .insert: Nodo:

            .nodos[Nodo.val] = Nodo