# 数据结构

C 语言实现的经典数据结构与算法合集，包含线性表、栈、队列、堆、二叉树及八大排序算法。每个模块均提供完整的操作接口和独立测试文件。

## 项目结构

```
Data Structure/
├── SeqList/          # 顺序表（动态扩容）
├── SListNode/        # 单向链表
├── DListNode/        # 双向循环链表（哨兵头节点）
├── Stack/            # 栈（顺序实现）
├── Queue/            # 队列（链式实现）
├── Heap/             # 堆（大顶堆 + 堆排序 + Top-K）
├── Tree/             # 二叉树（遍历 / LeetCode 题型 / 前中序重建）
├── sort/             # 八大排序算法
├── 数据结构课设大作业.c   # 课设：算术表达式求值 + 停车场管理
└── 二叉树.c / 复杂度.c    # 练习代码（二叉树、数组轮转）
```

## 模块概览

| 模块 | 实现方式 | 核心功能 |
|------|---------|---------|
| SeqList | 动态数组，2x 扩容 | 增删改查、任意位置插入/删除 |
| SListNode | 单向链表，二级指针操作 | 头尾插删、前插后插、查找删除 |
| DListNode | 双向循环链表，哨兵头节点 | 头尾 O(1) 操作、任意位置插入/删除 |
| Stack | 动态数组 | push/pop/top、判空、获取大小 |
| Queue | 链式结构，头尾指针 | 入队/出队、队首/队尾、判空 |
| Heap | 动态数组，大顶堆 | 入堆上浮、出堆下沉、堆排序、Top-K |
| Tree | 二叉链表 + 队列/栈辅助 | 递归 & 非递归遍历、层序、重建、LeetCode 题型 |
| sort | 原地排序 | 插入、希尔、冒泡、选择、快排(hoare/lomuto)、归并、计数 |

## 快速开始

每个模块目录下均包含独立的 `.h`、`.c` 和 `test.c`，可单独编译运行：

```bash
# 以顺序表为例
cd "Data Structure/SeqList/SeqList"
gcc -o test test.c SeqList.c
./test
```

## API 接口

### 顺序表 (SeqList)

基于动态数组，容量不足时自动扩容为原来的 2 倍。

```c
void InitSL(SL* s);                              // 初始化
void SLPushBack(SL* s, SLDataType x);            // 尾插
void SLPushFront(SL* s, SLDataType x);           // 头插
void SLPopBack(SL* s);                           // 尾删
void SLPopFront(SL* s);                          // 头删
void SLInsert(SL* s, int pos, SLDataType x);     // 指定位置插入
void SLErase(SL* s, int pos, SLDataType x);      // 指定位置删除
int  Find(SL* s, SLDataType x);                  // 查找元素，返回下标
void SLDestroy(SL* s);                           // 销毁
```

### 单链表 (SListNode)

使用二级指针操作链表头，支持头尾和任意位置操作。

```c
SListNode* BuySListNode(STLDataType x);                    // 创建节点
void STLPushBack(SListNode** plist, STLDataType x);        // 尾插
void STLPushFront(SListNode** plist, STLDataType x);       // 头插
void STLPopBack(SListNode** plist);                        // 尾删
void SListPopFront(SListNode** plist);                     // 头删
SListNode* STLFind(SListNode* plist, STLDataType x);       // 查找节点
void SListInsertAfter(SListNode* pos, STLDataType x);      // 指定节点后插入
void SLTInsert(SListNode** pphead, SListNode* pos, STLDataType x); // 指定节点前插入
void SListEraseAfter(SListNode* pos);                      // 删除指定节点之后的节点
void SLTErase(SListNode** pphead, SListNode* pos);         // 删除指定节点
void SLTDestroy(SListNode** pphead);                       // 销毁链表
```

### 双链表 (DListNode)

双向循环链表，哨兵头节点使头尾操作统一且高效（均为 O(1)）。

```c
DListNode* DLInit();                                     // 创建哨兵头节点
void ListPushBack(DListNode* pHead, LTDataType x);       // 尾插
void ListPushFront(DListNode* pHead, LTDataType x);      // 头插
void ListPopBack(DListNode* pHead);                      // 尾删
void ListPopFront(DListNode* pHead, LTDataType x);       // 头删
DListNode* ListFind(DListNode* pHead, LTDataType x);     // 查找节点
void ListInsert(DListNode* pos, LTDataType x);           // 在 pos 前插入
void ListErase(DListNode* pos);                          // 删除 pos 节点
bool IsEmpty(DListNode* pHead);                          // 判空
void ListDestory(DListNode** ppHead);                    // 销毁链表
```

### 栈 (Stack)

顺序栈，后进先出，动态扩容。

```c
void StackInit(Stack* ps);                    // 初始化
void StackPush(Stack* ps, StackDataType x);   // 入栈
void StackPop(Stack* ps);                     // 出栈
StackDataType StackTop(Stack* ps);            // 获取栈顶
int  StackSize(Stack* ps);                    // 元素个数
bool IsStackEmpty(Stack* ps);                 // 判空
void StackDestroy(Stack* ps);                 // 销毁
```

### 队列 (Queue)

链式队列，头尾双指针，先进先出。

```c
void QueueInit(Queue* q);            // 初始化
void QueuePush(Queue* q, QDataType x); // 入队
void QueuePop(Queue* q);             // 出队
QDataType QueueFront(Queue* q);      // 队首元素
QDataType QueueBack(Queue* q);       // 队尾元素
int  QueueSize(Queue* q);            // 元素个数
bool IsQueueEmpty(Queue* q);         // 判空
void QueueDestroy(Queue* q);         // 销毁
```

### 堆 (Heap)

大顶堆实现，支持 Top-K 问题（十万数据取最小十个）。

```c
void HeapInit(HP* php);                    // 初始化
void HeapPush(HP* php, HeapDataType x);    // 插入（上浮调整）
void HeapPop(HP* php);                     // 删除堆顶（下沉调整）
HeapDataType HeapTop(HP* php);             // 获取堆顶
int  HeapSize(HP* php);                    // 元素个数
bool HeapEmpty(HP* php);                   // 判空
void HeapSort(int* arr, int n);            // 原地堆排序
void HeapDestroy(HP* php);                 // 销毁
void CreatData();                          // 生成 10 万随机测试数据
```

### 二叉树 (Tree)

二叉树最完整的模块，除基础遍历外涵盖了多道 LeetCode 经典题型。

**基础操作：**
```c
BTNode* BinaryTreeCreate(BTDataType* a, int* pi);   // 前序序列建树（# 表示空）
void BinaryTreeDestory(BTNode** root);               // 后序递归销毁
int  BinaryTreeSize(BTNode* root);                   // 节点总数
int  BinaryTreeLeafSize(BTNode* root);               // 叶子节点数
int  BinaryTreeLevelKSize(BTNode* root, int k);      // 第 k 层节点数
int  BinaryTreeDepth(BTNode* root);                  // 树的深度
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);   // 查找值为 x 的节点
```

**遍历：**
```c
void BinaryTreePrevOrder(BTNode* root);       // 前序遍历（递归）
void BinaryTreeInOrder(BTNode* root);         // 中序遍历（递归）
void BinaryTreePostOrder(BTNode* root);       // 后序遍历（递归）
void BinaryTreeLevelOrder(BTNode* root);      // 层序遍历（队列实现）
```

**进阶题型：**
```c
BTNode* build_pre_in(BTDataType pre[], BTDataType in[], ...); // 前序+中序重建二叉树
bool isUnivalTree(BTNode* root);      // 单值二叉树
bool isSameTree(BTNode* p, BTNode* q); // 相同的树
bool isSymmetric(BTNode* root);        // 对称二叉树
bool isSubtree(BTNode* root, BTNode* subRoot); // 子树判断
```

### 排序算法 (sort)

八大排序，涵盖比较型与非比较型。

| 算法 | 函数 | 时间复杂度 | 特点 |
|------|------|-----------|------|
| 直接插入排序 | `InsertSort` | O(n²) | 接近有序时效率高 |
| 希尔排序 | `ShellSort` | O(n^1.3) | gap 递减的分组插入 |
| 冒泡排序 | `Bubble_sort` | O(n²) | flag 优化提前退出 |
| 选择排序 | `select_sort` | O(n²) | 双向选 min/max |
| 快速排序 | `my_qsort` + `hoare_qsort` / `lomuto_qsort` | O(n log n) | hoare & lomuto 双版本 |
| 归并排序 | `Merge_sort` | O(n log n) | 递归分治 + 临时数组 |
| 计数排序 | `count_sort` | O(n + range) | 非比较型，适合范围集中数据 |

### 课设大作业

`数据结构课设大作业.c` 包含两个完整的课程设计题目：

1. **算术表达式求值** — 双栈法（操作数栈 + 运算符栈），支持 `+ - * / ^`、`sqrt`、`ln`、括号，含逐步演算过程输出
2. **停车场管理** — 停车场为顺序栈，便道为链队列。支持车辆到达/离开（让路重入、便道补位）、状态显示

## 环境要求

- C 编译器（GCC / Clang / MSVC）
- 支持 C99 标准及以上

## 许可

仅供学习交流使用。
