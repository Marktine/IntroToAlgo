# LINKED-LIST IMPLEMENTATION IN C

## METHODS
### **push**
--------------------
#### Add a node to the end of the linked-list
- params:
    - `this: struct LinkedList*`
    - `data: integer`
- returns: `linked-list`'s new length
### **pop**
--------------
#### Remove a node at the end of the linked-list
- params:
    - `this: struct LinkedList*`
- returns: popped out node
### **insertBefore**
---------------
#### Insert a node before a node in linked-list
- params:
    - `this: struct LinkedList*`
    - `node: struct ListNode*`
    - `data: int`
- returns: linked-list's new length
### **insertAfter**
---------------
#### Insert a node after a node in linked-list
- params:
    - `this: struct LinkedList*`
    - `node: struct ListNode*`
    - `data: int`
- returns: linked-list's new length