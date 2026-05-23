# Data Structures

This project implements various classic data structures in C, including singly linked lists, doubly linked lists, sequential lists, stacks, queues, heaps, and binary trees. Each data structure provides complete interfaces for insertion, deletion, modification, and lookup operations, facilitating learning and reuse.

## Project Structure

```
Data Structure/
├── DListNode/       # Doubly Linked List
├── Heap/            # Heap
├── Queue/           # Queue
├── SListNode/       # Singly Linked List
├── SeqList/         # Sequential List
├── Stack/           # Stack
└── tree.c           # Binary Tree
```

## Data Structure Overview

| Module | Description |
|--------|-------------|
| SListNode | Singly linked list supporting head insertion, tail insertion, search, insertion, deletion, etc. |
| DListNode | Doubly linked list with a sentinel head node, enabling efficient operations at both ends. |
| SeqList | Dynamic sequential list, similar to C++ vector, with automatic capacity expansion. |
| Stack | Stack implementing LIFO (Last In, First Out) behavior. |
| Queue | Queue implementing FIFO (First In, First Out) behavior. |
| Heap | Heap structure used for implementing priority queues and heap sort. |
| tree.c | Binary tree supporting both recursive and non-recursive traversals. |

## Quick Start

### Compilation and Execution

Each module directory contains an independent test file that can be compiled and run individually:

```bash
# Example for sequential list
cd Data Structure/SeqList/SeqList
gcc -o test test.c SeqList.c
./test
```

### Example Code

**Sequential List Example**

```c
#include "Seqlist.h"

int main() {
    SL s;
    InitSL(&s);
    
    SLPushBack(&s, 1);
    SLPushBack(&s, 2);
    SLPushBack(&s, 3);
    
    SLPrint(&s);  // Output: 1 2 3
    
    SLDestroy(&s);
    return 0;
}
```

**Singly Linked List Example**

```c
#include "SListNode.h"

int main() {
    SListNode* plist = NULL;
    
    STLPushBack(&plist, 1);
    STLPushBack(&plist, 2);
    STLPushFront(&plist, 0);
    
    STLPrint(plist);  // Output: 0 1 2
    
    SLTDestroy(&plist);
    return 0;
}
```

**Heap Sort Example**

```c
#include "Heap.h"

int main() {
    int arr[] = {9, 5, 2, 7, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    HeapSort(arr, n);  // In-place heap sort
    
    // arr becomes sorted: 1 2 3 5 6 7 9
    return 0;
}
```

## Detailed Module Interfaces

### Sequential List (SeqList)

- `InitSL` - Initialize
- `SLPushBack/SLPushFront` - Insert at tail/head
- `SLPopBack/SLPopFront` - Delete from tail/head
- `SLInsert/SLErase` - Insert/delete at specified position
- `Find` - Search for an element

### Singly Linked List (SListNode)

- `STLPushBack/STLPushFront` - Insert at tail/head
- `STLPopBack/SListPopFront` - Delete from tail/head
- `STLFind` - Find a node
- `SListInsertAfter/SLTInsert` - Insert after / insert at head
- `SListEraseAfter/SLTErase` - Delete after / delete at specified position
- `SLTDestroy` - Destroy the list

### Doubly Linked List (DListNode)

- `DLInit` - Initialize and create
- `ListPushBack/ListPushFront` - Insert at tail/head
- `ListPopBack/ListPopFront` - Delete from tail/head
- `ListFind` - Find a node
- `ListInsert/ListErase` - Insert/delete at specified position
- `ListDestory` - Destroy the list

### Stack (Stack)

- `StackInit` - Initialize
- `StackPush` - Push element
- `StackPop` - Pop element
- `StackTop` - Get top element
- `StackSize` - Get number of elements
- `IsStackEmpty` - Check if empty

### Queue (Queue)

- `QueueInit` - Initialize
- `QueuePush` - Enqueue
- `QueuePop` - Dequeue
- `QueueFront/QueueBack` - Get front/back element
- `QueueSize` - Get number of elements
- `IsQueueEmpty` - Check if empty

### Heap (Heap)

- `HeapInit` - Initialize
- `HeapPush` - Insert element (with heapify-up)
- `HeapPop` - Delete root (with heapify-down)
- `HeapTop` - Get root element
- `HeapSize` - Get number of elements
- `HeapEmpty` - Check if empty
- `HeapSort` - Heap sort

### Binary Tree (tree.c)

- `CreateBiTree` - Create binary tree from input
- `PreOrder/InOrder/PostOrder` - Recursive preorder/inorder/postorder traversal
- `LevelOrder` - Level-order traversal (implemented with queue)
- `InOrder_NonRec/PostOrder_NonRec` - Non-recursive traversal (implemented with stack)
- `CountNodes` - Count total nodes
- `CountLeaf` - Count leaf nodes
- `TreeDepth` - Calculate tree depth

## System Requirements

- C compiler (GCC/Clang/MSVC, etc.)
- Supports C99 standard or higher

## License

This project is intended solely for learning and educational purposes.