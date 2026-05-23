

# 数据结构

本项目收录了C语言实现的各种经典数据结构，包括单链表、双链表、顺序表、栈、队列、堆和二叉树。每个数据结构都提供了完整的增删改查操作接口，便于学习和复用。

## 项目结构

```
Data Structure/
├── DListNode/       # 双向链表
├── Heap/            # 堆
├── Queue/           # 队列
├── SListNode/       # 单链表
├── SeqList/         # 顺序表
├── Stack/           # 栈
└── tree.c           # 二叉树
```

## 数据结构概览

| 模块 | 描述 |
|------|------|
| SListNode | 单向链表，支持头插、尾插、查找、插入、删除等操作 |
| DListNode | 双向链表，带哨兵头节点，支持前后两端的高效操作 |
| SeqList | 动态顺序表，类似于C++的vector，自动扩容 |
| Stack | 栈，后进先出（LIFO） |
| Queue | 队列，先进先出（FIFO） |
| Heap | 堆结构，用于实现优先级队列和堆排序 |
| tree.c | 二叉树，支持递归和非递归遍历 |

## 快速开始

### 编译运行

每个模块目录下都有独立的测试文件，可以单独编译运行：

```bash
# 以顺序表为例
cd Data Structure/SeqList/SeqList
gcc -o test test.c SeqList.c
./test
```

### 示例代码

**顺序表示例**

```c
#include "Seqlist.h"

int main() {
    SL s;
    InitSL(&s);
    
    SLPushBack(&s, 1);
    SLPushBack(&s, 2);
    SLPushBack(&s, 3);
    
    SLPrint(&s);  // 输出: 1 2 3
    
    SLDestroy(&s);
    return 0;
}
```

**单链表示例**

```c
#include "SListNode.h"

int main() {
    SListNode* plist = NULL;
    
    STLPushBack(&plist, 1);
    STLPushBack(&plist, 2);
    STLPushFront(&plist, 0);
    
    STLPrint(plist);  // 输出: 0 1 2
    
    SLTDestroy(&plist);
    return 0;
}
```

**堆排序示例**

```c
#include "Heap.h"

int main() {
    int arr[] = {9, 5, 2, 7, 1, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    HeapSort(arr, n);  // 原地堆排序
    
    // arr 变为有序: 1 2 3 5 6 7 9
    return 0;
}
```

## 各模块详细接口

### 顺序表 (SeqList)

- `InitSL` - 初始化
- `SLPushBack/SLPushFront` - 尾插/头插
- `SLPopBack/SLPopFront` - 尾删/头删
- `SLInsert/SLErase` - 指定位置插入/删除
- `Find` - 查找元素

### 单链表 (SListNode)

- `STLPushBack/STLPushFront` - 尾插/头插
- `STLPopBack/SListPopFront` - 尾删/头删
- `STLFind` - 查找节点
- `SListInsertAfter/SLTInsert` - 后插/前插
- `SListEraseAfter/SLTErase` - 后删/指定删
- `SLTDestroy` - 销毁链表

### 双链表 (DListNode)

- `DLInit` - 初始化创建
- `ListPushBack/ListPushFront` - 尾插/头插
- `ListPopBack/ListPopFront` - 尾删/头删
- `ListFind` - 查找节点
- `ListInsert/ListErase` - 插入/删除
- `ListDestory` - 销毁链表

### 栈 (Stack)

- `StackInit` - 初始化
- `StackPush` - 入栈
- `StackPop` - 出栈
- `StackTop` - 获取栈顶元素
- `StackSize` - 获取元素个数
- `IsStackEmpty` - 判断是否为空

### 队列 (Queue)

- `QueueInit` - 初始化
- `QueuePush` - 入队
- `QueuePop` - 出队
- `QueueFront/QueueBack` - 获取队首/队尾元素
- `QueueSize` - 获取元素个数
- `IsQueueEmpty` - 判断是否为空

### 堆 (Heap)

- `HeapInit` - 初始化
- `HeapPush` - 插入元素（上浮调整）
- `HeapPop` - 删除堆顶（下沉调整）
- `HeapTop` - 获取堆顶元素
- `HeapSize` - 获取元素个数
- `HeapEmpty` - 判断是否为空
- `HeapSort` - 堆排序

### 二叉树 (tree.c)

- `CreateBiTree` - 根据输入创建二叉树
- `PreOrder/InOrder/PostOrder` - 前/中/后序遍历（递归）
- `LevelOrder` - 层序遍历（队列实现）
- `InOrder_NonRec/PostOrder_NonRec` - 非递归遍历（栈实现）
- `CountNodes` - 统计结点总数
- `CountLeaf` - 统计叶子结点个数
- `TreeDepth` - 计算树的深度

## 环境要求

- C编译器（GCC/Clang/MSVC等）
- 支持C99标准及以上

## 许可协议

本项目仅供学习交流使用。