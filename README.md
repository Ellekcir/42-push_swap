
Mandatory part

V.1 The rules

• You have 2 stacks named a and b.

• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.
◦ The stack b is empty.

• The goal is to sort in ascending order numbers into stack a. To do so you have the
following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.
-------------------------------------------------------------------------------------------
NOTES TAKEN -

# Understanding Nodes

A **node** is a basic building block used in various data structures like linked lists, trees, and graphs. Think of it as a single container that holds information and connects to other containers.

## Key Parts of a Node:

1. **Data**: 
   - This is the value that the node holds. It can be anything, like numbers or text.

2. **Links/Pointers**: 
   - Nodes usually have pointers (or links) to other nodes. This connection allows you to build complex structures.
   - For example:
     - In a **linked list**, each node points to the next one.
     - In a **tree**, a node can point to its child nodes.
     - In a **graph**, a node can connect to multiple other nodes.

### Example of a Node in a Linked List:

```c
typedef struct s_node {
    int value;               // The value the node holds
    struct s_node *next;    // Points to the next node
} t_node;
```

# Data Structure Examples

## 1. Linked List

A linked list is a collection of nodes where each node points to the next one. It allows for efficient insertion and deletion of elements.

### Example of a Singly Linked List Node:

```c
typedef struct s_node {
    int value;               // Value held by the node
    struct s_node *next;    // Pointer to the next node
} t_node;
```

### Example of a Linked List:

```c
t_node *head = malloc(sizeof(t_node));
head->value = 10;
head->next = malloc(sizeof(t_node));
head->next->value = 20;
head->next->next = NULL; // Last node points to NULL
```

**Visual Representation:**

```
head -> [10|next] -> [20|next] -> NULL
```

---

## 2. Tree

A tree is a hierarchical structure consisting of nodes, where each node has a value and can point to multiple child nodes.

### Example of a Tree Node:

```c
typedef struct s_tree_node {
    int value;                         // Value held by the node
    struct s_tree_node *left;         // Pointer to the left child
    struct s_tree_node *right;        // Pointer to the right child
} t_tree_node;
```

### Example of a Binary Tree:

```c
t_tree_node *root = malloc(sizeof(t_tree_node));
root->value = 10;
root->left = malloc(sizeof(t_tree_node));
root->left->value = 5;
root->right = malloc(sizeof(t_tree_node));
root->right->value = 15;
root->left->left = NULL;
root->left->right = NULL;
root->right->left = NULL;
root->right->right = NULL;
```

**Visual Representation:**

```
        10
       /  \
      5   15
```

---

## 3. Graph

A graph is a collection of nodes (vertices) and edges that connect them. It can be used to represent relationships between items.

### Example of a Graph Node:

```c
typedef struct s_graph_node {
    int value;                             // Value held by the node
    struct s_graph_node **neighbors;       // Array of pointers to neighboring nodes
    int neighbor_count;                    // Number of neighbors
} t_graph_node;
```

### Example of a Graph Node:

```c
t_graph_node *nodeA = malloc(sizeof(t_graph_node));
nodeA->value = 1;
nodeA->neighbor_count = 2;
nodeA->neighbors = malloc(nodeA->neighbor_count * sizeof(t_graph_node*));

t_graph_node *nodeB = malloc(sizeof(t_graph_node));
nodeB->value = 2;

t_graph_node *nodeC = malloc(sizeof(t_graph_node));
nodeC->value = 3;

nodeA->neighbors[0] = nodeB; // Node A connects to Node B
nodeA->neighbors[1] = nodeC; // Node A connects to Node C
```

**Visual Representation:**

```
    1
   / \
  2   3
```
// Stack a -
// begins containing a random amount of negative and/or positive numbers
// which cannot be duplicated.

// Stack b
// begins empty.

// The goal is to sort in ascending order numbers into stack a.

// sa (swap a): Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements.

// sb (swap b): Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.

// ss : sa and sb at the same time.

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.

// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.

// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.

// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.

// rr : ra and rb at the same time.

// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.

// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.

// rrr : rra and rrb at the same time.
