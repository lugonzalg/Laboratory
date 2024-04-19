Description
Editorial
Editorial
Solutions
Solutions
Submissions
Submissions
Code
Testcase
Test Result
Test Result
705. Design HashSet
Easy
Topics
Companies

Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

    void add(key) Inserts the value key into the HashSet.
    bool contains(key) Returns whether the value key exists in the HashSet or not.
    void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

 

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)

 

Constraints:

    0 <= key <= 106
    At most 104 calls will be made to add, remove, and contains.

Analysis:

    I have to store the values within a array with a hashed value. The array contains nodes. Each node has a key value.

    The array has a linked list in order to avoid colission when hashing the value.

    The received key is an integer, the hashing would be to calculate the 10_000 module of the key:

        1 % 10_000 = 1
        20_001 % 10_000 = 1
        10_123 % 10_000 = 123

Algorithm:

    contructor:

        set array of 10_000

    add:

        hash value
        create node with key

        array[hash value] exists:
            concatenate node
        dont exists
            insert node

    remove:

        hash value
        remove node

    contains:

        hash value
        check node