# Data Structures

A collection of classic data structures and algorithms implemented in C, including linear lists, stacks, queues, heaps, binary trees, and eight sorting algorithms. Each module provides a complete set of operations with independent test files.

## Project Structure

```
Data Structure/
├── SeqList/          # Sequential List (dynamic array)
├── SListNode/        # Singly Linked List
├── DListNode/        # Doubly Circular Linked List (sentinel head)
├── Stack/            # Stack (array-based)
├── Queue/            # Queue (linked-list-based)
├── Heap/             # Max-Heap + Heap Sort + Top-K
├── Tree/             # Binary Tree (traversals / LeetCode problems / reconstruction)
├── sort/             # Eight Sorting Algorithms
├── 数据结构课设大作业.c    # Course Project: Expression Evaluator + Parking Lot Manager
└── 二叉树.c / 复杂度.c    # Practice: Binary Tree Traversal / Array Rotation
```

## Module Overview

| Module | Implementation | Key Features |
|--------|---------------|--------------|
| SeqList | Dynamic array, 2x growth | Full CRUD, insert/delete at arbitrary positions |
| SListNode | Singly linked list, double-pointer ops | Head/tail insert & delete, insert before/after, find & erase |
| DListNode | Doubly circular, sentinel head node | O(1) head/tail ops, arbitrary insert/delete |
| Stack | Dynamic array | Push/pop/top, isEmpty, size |
| Queue | Linked structure, head & tail pointers | Enqueue/dequeue, front/back, isEmpty |
| Heap | Dynamic array, max-heap | Push (sift-up), pop (sift-down), heap sort, Top-K |
| Tree | Binary linked + queue/stack helpers | Recursive & iterative traversal, level-order, tree reconstruction, LeetCode problems |
| sort | In-place comparison & non-comparison sorts | 8 algorithms with multiple partition strategies |

## Quick Start

Each module has its own `.h`, `.c`, and `test.c` files. Compile and run independently:

```bash
# Example: Sequential List
cd "Data Structure/SeqList/SeqList"
gcc -o test test.c SeqList.c
./test
```

## API Reference

### Sequential List (SeqList)

A dynamic array that automatically doubles capacity when full.

```c
void InitSL(SL* s);                              // Initialize
void SLPushBack(SL* s, SLDataType x);            // Insert at tail
void SLPushFront(SL* s, SLDataType x);           // Insert at head
void SLPopBack(SL* s);                           // Delete from tail
void SLPopFront(SL* s);                          // Delete from head
void SLInsert(SL* s, int pos, SLDataType x);     // Insert at position
void SLErase(SL* s, int pos, SLDataType x);      // Erase at position
int  Find(SL* s, SLDataType x);                  // Find element, returns index
void SLDestroy(SL* s);                           // Destroy
```

### Singly Linked List (SListNode)

Uses double pointers for head manipulation. Supports head, tail, and arbitrary position operations.

```c
SListNode* BuySListNode(STLDataType x);                    // Create node
void STLPushBack(SListNode** plist, STLDataType x);        // Insert at tail
void STLPushFront(SListNode** plist, STLDataType x);       // Insert at head
void STLPopBack(SListNode** plist);                        // Delete from tail
void SListPopFront(SListNode** plist);                     // Delete from head
SListNode* STLFind(SListNode* plist, STLDataType x);       // Find node by value
void SListInsertAfter(SListNode* pos, STLDataType x);      // Insert after pos
void SLTInsert(SListNode** pphead, SListNode* pos, STLDataType x); // Insert before pos
void SListEraseAfter(SListNode* pos);                      // Erase node after pos
void SLTErase(SListNode** pphead, SListNode* pos);         // Erase pos node
void SLTDestroy(SListNode** pphead);                       // Destroy entire list
```

### Doubly Circular Linked List (DListNode)

Sentinel head node unifies head and tail operations, both in O(1).

```c
DListNode* DLInit();                                     // Create sentinel head
void ListPushBack(DListNode* pHead, LTDataType x);       // Insert at tail
void ListPushFront(DListNode* pHead, LTDataType x);      // Insert at head
void ListPopBack(DListNode* pHead);                      // Delete from tail
void ListPopFront(DListNode* pHead, LTDataType x);       // Delete from head
DListNode* ListFind(DListNode* pHead, LTDataType x);     // Find node
void ListInsert(DListNode* pos, LTDataType x);           // Insert before pos
void ListErase(DListNode* pos);                          // Erase pos node
bool IsEmpty(DListNode* pHead);                          // Check if empty
void ListDestory(DListNode** ppHead);                    // Destroy list
```

### Stack

Array-based stack with LIFO semantics and dynamic capacity.

```c
void StackInit(Stack* ps);                    // Initialize
void StackPush(Stack* ps, StackDataType x);   // Push
void StackPop(Stack* ps);                     // Pop
StackDataType StackTop(Stack* ps);            // Peek top
int  StackSize(Stack* ps);                    // Get size
bool IsStackEmpty(Stack* ps);                 // Check if empty
void StackDestroy(Stack* ps);                 // Destroy
```

### Queue

Linked-list-based queue with head and tail pointers for O(1) enqueue/dequeue.

```c
void QueueInit(Queue* q);            // Initialize
void QueuePush(Queue* q, QDataType x); // Enqueue
void QueuePop(Queue* q);             // Dequeue
QDataType QueueFront(Queue* q);      // Get front
QDataType QueueBack(Queue* q);       // Get back
int  QueueSize(Queue* q);            // Get size
bool IsQueueEmpty(Queue* q);         // Check if empty
void QueueDestroy(Queue* q);         // Destroy
```

### Max-Heap

Max-heap with sift-up on insert and sift-down on delete. Includes a Top-K demo (finding 10 smallest among 100k items).

```c
void HeapInit(HP* php);                    // Initialize
void HeapPush(HP* php, HeapDataType x);    // Insert (sift-up)
void HeapPop(HP* php);                     // Delete root (sift-down)
HeapDataType HeapTop(HP* php);             // Get root
int  HeapSize(HP* php);                    // Get size
bool HeapEmpty(HP* php);                   // Check if empty
void HeapSort(int* arr, int n);            // In-place heap sort
void HeapDestroy(HP* php);                 // Destroy
void CreatData();                          // Generate 100k random test data
```

### Binary Tree

The most comprehensive module, covering traversals and several classic LeetCode problems.

**Core Operations:**
```c
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);   // Build from preorder (use '#' for NULL)
void BinaryTreeDestory(BTNode** root);               // Postorder recursive destroy
int  BinaryTreeSize(BTNode* root);                   // Total node count
int  BinaryTreeLeafSize(BTNode* root);               // Leaf node count
int  BinaryTreeLevelKSize(BTNode* root, int k);      // Node count at level k
int  BinaryTreeDepth(BTNode* root);                  // Tree depth
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);   // Find node by value
```

**Traversals:**
```c
void BinaryTreePrevOrder(BTNode* root);       // Preorder (recursive)
void BinaryTreeInOrder(BTNode* root);         // Inorder (recursive)
void BinaryTreePostOrder(BTNode* root);       // Postorder (recursive)
void BinaryTreeLevelOrder(BTNode* root);      // Level-order (queue-based)
```

**Advanced Problems:**
```c
BTNode* build_pre_in(BTDataType pre[], BTDataType in[], ...); // Reconstruct from pre+in order
bool isUnivalTree(BTNode* root);      // Univalued binary tree
bool isSameTree(BTNode* p, BTNode* q); // Same tree
bool isSymmetric(BTNode* root);        // Symmetric tree
bool isSubtree(BTNode* root, BTNode* subRoot); // Subtree of another tree
```

### Sorting Algorithms

Eight sorting algorithms covering both comparison-based and non-comparison approaches.

| Algorithm | Function | Time Complexity | Notes |
|-----------|----------|----------------|-------|
| Insertion Sort | `InsertSort` | O(n²) | Efficient on nearly-sorted data |
| Shell Sort | `ShellSort` | O(n^1.3) | Gap-based incremental insertion |
| Bubble Sort | `Bubble_sort` | O(n²) | Flag optimization for early exit |
| Selection Sort | `select_sort` | O(n²) | Two-way min/max selection |
| Quick Sort | `my_qsort` + `hoare_qsort` / `lomuto_qsort` | O(n log n) | Both Hoare & Lomuto partition schemes |
| Merge Sort | `Merge_sort` | O(n log n) | Recursive divide-and-conquer with temp array |
| Counting Sort | `count_sort` | O(n + range) | Non-comparison, ideal for small-range data |

### Course Design Project

`数据结构课设大作业.c` contains two complete course design assignments:

1. **Arithmetic Expression Evaluator** — Dual-stack approach (operand stack + operator stack). Supports `+ - * / ^`, `sqrt`, `ln`, and parentheses. Outputs step-by-step evaluation trace.
2. **Parking Lot Manager** — Parking spaces as a sequential stack, waiting lane as a linked queue. Supports vehicle arrival/departure (with yield-and-return logic), queue replenishment, and status display.

## Requirements

- C compiler (GCC / Clang / MSVC)
- C99 or later

## License

For educational and learning purposes only.
