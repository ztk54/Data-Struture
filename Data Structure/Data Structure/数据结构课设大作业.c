#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXPR 500
#define MAX_STACK 200
#define PARK_MAX 10

/* ============================================================
   设计一：算术表达式求值
   核心思想：使用两个栈，一个存操作数，一个存运算符。
   支持：实数、+、-、*、/、^、括号、sqrt、ln。
   输入结束符：可以使用 @、#，也可以直接回车结束。
   ============================================================ */

typedef struct 
{
    double data[MAX_STACK];
    int top;
} NumStack;

typedef struct 
{
    char data[MAX_STACK];
    int top;
} OpStack;

void InitNumStack(NumStack* s) 
{
    s->top = -1;
}

void InitOpStack(OpStack* s) 
{
    s->top = -1;
}

int NumEmpty(NumStack* s) 
{
    return s->top == -1;
}

int OpEmpty(OpStack* s) 
{
    return s->top == -1;
}

int PushNum(NumStack* s, double x) 
{
    if (s->top >= MAX_STACK - 1) return 0;
    s->data[++s->top] = x;
    return 1;
}

int PushOp(OpStack* s, char op) 
{
    if (s->top >= MAX_STACK - 1) return 0;
    s->data[++s->top] = op;
    return 1;
}

int PopNum(NumStack* s, double* x) 
{
    if (NumEmpty(s)) return 0;
    *x = s->data[s->top--];
    return 1;
}

int PopOp(OpStack* s, char* op)
{
    if (OpEmpty(s)) return 0;
    *op = s->data[s->top--];
    return 1;
}

int GetTopOp(OpStack* s, char* op) 
{
    if (OpEmpty(s)) return 0;
    *op = s->data[s->top];
    return 1;
}

int IsBinaryOp(char op) 
{
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '^';
}

int IsUnaryOp(char op) 
{
    return op == 's' || op == 'l';   /* s 表示 sqrt，l 表示 ln */
}

int Priority(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    if (op == 's' || op == 'l') return 4;
    return 0;
}

void PrintOperator(char op) 
{
    if (op == 's') printf("sqrt");
    else if (op == 'l') printf("ln");
    else printf("%c", op);
}

void PrintNumStack(NumStack* num) 
{
    int i;
    printf("NumStack: [");
    for (i = 0; i <= num->top; i++) 
    {
        printf("%.6g", num->data[i]);
        if (i < num->top) printf(", ");
    }
    printf("]");
}

void PrintOpStack(OpStack* op) 
{
    int i;
    printf("OpStack: [");
    for (i = 0; i <= op->top; i++) 
    {
        PrintOperator(op->data[i]);
        if (i < op->top) printf(", ");
    }
    printf("]");
}

void PrintStep(const char* token, const char* action, NumStack* num, OpStack* op) 
{
    printf("Token: %-10s  Action: %-30s  ", token, action);
    PrintNumStack(num);
    printf("  ");
    PrintOpStack(op);
    printf("\n");
}

int CalculateOnce(NumStack* num, OpStack* op) 
{
    char c;
    double a, b, r;

    if (!PopOp(op, &c)) 
    {
        printf("错误：运算符栈为空，无法计算。\n");
        return 0;
    }

    if (IsUnaryOp(c)) 
    {
        if (!PopNum(num, &a)) 
        {
            printf("错误：操作数不足。\n");
            return 0;
        }
        if (c == 's')
        {
            if (a < 0) 
            {
                printf("错误：sqrt 的参数不能为负数。\n");
                return 0;
            }
            r = sqrt(a);
        }
        else {
            if (a <= 0) 
            {
                printf("错误：ln 的参数必须大于 0。\n");
                return 0;
            }
            r = log(a);
        }
        PushNum(num, r);
        return 1;
    }

    if (!PopNum(num, &b) || !PopNum(num, &a)) 
    {
        printf("错误：二元运算符缺少操作数。\n");
        return 0;
    }

    switch (c) 
    {
    case '+': r = a + b; break;
    case '-': r = a - b; break;
    case '*': r = a * b; break;
    case '/':
        if (fabs(b) < 1e-12) 
        {
            printf("错误：除数不能为 0。\n");
            return 0;
        }
        r = a / b;
        break;
    case '^': r = pow(a, b); break;
    default:
        printf("错误：未知运算符。\n");
        return 0;
    }
    PushNum(num, r);
    return 1;
}

int ShouldCalculate(char topOp, char curOp) 
{
    if (topOp == '(') return 0;
    if (IsUnaryOp(topOp)) return 1;
    if (Priority(topOp) > Priority(curOp)) return 1;
    if (Priority(topOp) == Priority(curOp) && curOp != '^') return 1;
    return 0;
}

int IsUnaryMinusPosition(const char* expr, int pos) 
{
    int j = pos - 1;
    while (j >= 0 && isspace((unsigned char)expr[j])) j--;
    if (j < 0) return 1;
    if (expr[j] == '(' || IsBinaryOp(expr[j]) || expr[j] == '#') return 1;
    return 0;
}

void EvaluateExpression()
{
    char expr[MAX_EXPR];
    NumStack num;
    OpStack op;
    int i = 0;
    int ok = 1;

    InitNumStack(&num);
    InitOpStack(&op);

    printf("\n请输入算术表达式（可用 @ 或 # 结束，也可直接回车结束）：\n");
    printf("示例：(3.5+2)*4@\n");
    getchar(); /* 吃掉上一次菜单输入后的换行 */
    fgets(expr, MAX_EXPR, stdin);

    printf("\n表达式求值过程如下：\n");
    printf("--------------------------------------------------------------------------\n");

    while (expr[i] != '\0' && expr[i] != '\n') 
    {
        if (isspace((unsigned char)expr[i])) 
        {
            i++;
            continue;
        }

        if (expr[i] == '@') break;
        if (expr[i] == '#') 
        {
            i++;
            continue;
        }

        if (isdigit((unsigned char)expr[i]) || expr[i] == '.' ||
            (expr[i] == '-' && IsUnaryMinusPosition(expr, i) &&
                (isdigit((unsigned char)expr[i + 1]) || expr[i + 1] == '.'))) 
        {
            char* endptr;
            char token[50];
            double value = strtod(&expr[i], &endptr);
            int len = (int)(endptr - &expr[i]);
            if (len >= 49) len = 49;
            strncpy(token, &expr[i], len);
            token[len] = '\0';
            PushNum(&num, value);
            PrintStep(token, "数字入操作数栈", &num, &op);
            i = (int)(endptr - expr);
            continue;
        }

        if (strncmp(&expr[i], "sqrt", 4) == 0) 
        {
            PushOp(&op, 's');
            PrintStep("sqrt", "函数入运算符栈", &num, &op);
            i += 4;
            continue;
        }

        if (strncmp(&expr[i], "ln", 2) == 0) 
        {
            PushOp(&op, 'l');
            PrintStep("ln", "函数入运算符栈", &num, &op);
            i += 2;
            continue;
        }

        if (expr[i] == '(') 
        {
            PushOp(&op, '(');
            PrintStep("(", "左括号入运算符栈", &num, &op);
            i++;
            continue;
        }

        if (expr[i] == ')') 
        {
            char top;
            while (GetTopOp(&op, &top) && top != '(') 
            {
                if (!CalculateOnce(&num, &op)) { ok = 0; break; }
                PrintStep(")", "遇右括号，弹栈计算", &num, &op);
            }
            if (!ok) break;
            if (!PopOp(&op, &top) || top != '(') 
            {
                printf("错误：括号不匹配。\n");
                ok = 0;
                break;
            }
            PrintStep(")", "左括号出栈", &num, &op);

            while (GetTopOp(&op, &top) && IsUnaryOp(top)) 
            {
                if (!CalculateOnce(&num, &op)) { ok = 0; break; }
                PrintStep(")", "函数运算", &num, &op);
            }
            if (!ok) break;
            i++;
            continue;
        }

        if (IsBinaryOp(expr[i])) 
        {
            char cur = expr[i];
            char top;
            char token[2] = { cur, '\0' };
            while (GetTopOp(&op, &top) && ShouldCalculate(top, cur)) 
            {
                if (!CalculateOnce(&num, &op)) { ok = 0; break; }
                PrintStep(token, "栈顶优先级较高，先计算", &num, &op);
            }
            if (!ok) break;
            PushOp(&op, cur);
            PrintStep(token, "当前运算符入栈", &num, &op);
            i++;
            continue;
        }

        printf("错误：表达式中存在非法字符：%c\n", expr[i]);
        ok = 0;
        break;
    }

    while (ok && !OpEmpty(&op)) 
    {
        char top;
        GetTopOp(&op, &top);
        if (top == '(') 
        {
            printf("错误：括号不匹配。\n");
            ok = 0;
            break;
        }
        if (!CalculateOnce(&num, &op)) { ok = 0; break; }
        PrintStep("END", "表达式结束，继续计算", &num, &op);
    }

    printf("--------------------------------------------------------------------------\n");
    if (ok && num.top == 0) {
        printf("表达式结果为：%.10g\n", num.data[0]);
    }
    else if (ok) {
        printf("错误：表达式格式不正确，操作数栈剩余元素数量异常。\n");
    }
}

/* ============================================================
   设计二：停车场管理
   核心思想：停车场用顺序栈，临时让路用顺序栈，便道用链队列。
   ============================================================ */

typedef struct 
{
    int data[PARK_MAX];
    int top;
} SqStackTp;

typedef struct linked_queue 
{
    int data;
    struct linked_queue* next;
} LqueueTp;

typedef struct 
{
    LqueueTp* front;
    LqueueTp* rear;
} QueptrTp;

void InitCarStack(SqStackTp* s) 
{
    s->top = -1;
}

int CarStackEmpty(SqStackTp* s) 
{
    return s->top == -1;
}

int CarStackFull(SqStackTp* s, int capacity) 
{
    return s->top >= capacity - 1;
}

int PushCar(SqStackTp* s, int car, int capacity) 
{
    if (CarStackFull(s, capacity)) return 0;
    s->data[++s->top] = car;
    return 1;
}

int PopCar(SqStackTp* s, int* car) 
{
    if (CarStackEmpty(s)) return 0;
    *car = s->data[s->top--];
    return 1;
}

void InitQueue(QueptrTp* q) 
{
    q->front = q->rear = (LqueueTp*)malloc(sizeof(LqueueTp));
    if (q->front == NULL) 
    {
        printf("内存分配失败。\n");
        exit(1);
    }
    q->front->next = NULL;
}

int QueueEmpty(QueptrTp* q) 
{
    return q->front == q->rear;
}

void EnQueue(QueptrTp* q, int car) 
{
    LqueueTp* p = (LqueueTp*)malloc(sizeof(LqueueTp));
    if (p == NULL) 
    {
        printf("内存分配失败。\n");
        exit(1);
    }
    p->data = car;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}

int DeQueue(QueptrTp* q, int* car) 
{
    LqueueTp* p;
    if (QueueEmpty(q)) return 0;
    p = q->front->next;
    *car = p->data;
    q->front->next = p->next;
    if (q->rear == p) q->rear = q->front;
    free(p);
    return 1;
}

int FindInStack(SqStackTp* s, int car) 
{
    int i;
    for (i = 0; i <= s->top; i++) 
    {
        if (s->data[i] == car) return 1;
    }
    return 0;
}

int FindInQueue(QueptrTp* q, int car) 
{
    LqueueTp* p = q->front->next;
    while (p != NULL) 
    {
        if (p->data == car) return 1;
        p = p->next;
    }
    return 0;
}

void ShowParking(SqStackTp* park, QueptrTp* road) 
{
    int i;
    LqueueTp* p;

    printf("\n当前停车场状态（从北端到大门）：");
    if (park->top == -1) 
    {
        printf("空");
    }
    else {
        for (i = 0; i <= park->top; i++) 
        {
            printf("%d", park->data[i]);
            if (i < park->top) printf(" -> ");
        }
    }

    printf("\n当前便道状态（队头到队尾）：");
    if (QueueEmpty(road)) 
    {
        printf("空");
    }
    else {
        p = road->front->next;
        while (p != NULL) 
        {
            printf("%d", p->data);
            if (p->next != NULL) printf(" -> ");
            p = p->next;
        }
    }
    printf("\n");
}

void ArriveCar(SqStackTp* park, QueptrTp* road, int car, int capacity) 
{
    if (car <= 0) 
    {
        printf("车号必须为正整数。\n");
        return;
    }
    if (FindInStack(park, car) || FindInQueue(road, car))
    {
        printf("车号 %d 已经存在，不能重复进入。\n", car);
        return;
    }

    if (!CarStackFull(park, capacity)) 
    {
        PushCar(park, car, capacity);
        printf("汽车 %d 进入停车场，停车位置为 %d。\n", car, park->top + 1);
    }
    else 
    {
        EnQueue(road, car);
        printf("停车场已满，汽车 %d 进入便道等待。\n", car);
    }
}

void LeaveCar(SqStackTp* park, QueptrTp* road, int car, int capacity) 
{
    SqStackTp temp;
    int x;
    int found = 0;

    InitCarStack(&temp);

    if (car <= 0) 
    {
        printf("车号必须为正整数。\n");
        return;
    }

    if (!FindInStack(park, car)) 
    {
        if (FindInQueue(road, car))
        {
            printf("汽车 %d 在便道上，题目规定便道上的汽车不能直接离开。\n", car);
        }
        else 
        {
            printf("停车场中没有汽车 %d。\n", car);
        }
        return;
    }

    printf("汽车 %d 准备离开，后进入的车辆需要先让路。\n", car);
    while (!CarStackEmpty(park)) 
    {
        PopCar(park, &x);
        if (x == car) 
        {
            found = 1;
            printf("汽车 %d 离开停车场。\n", car);
            break;
        }
        else
        {
            PushCar(&temp, x, capacity);
            printf("汽车 %d 暂时退出停车场让路。\n", x);
        }
    }

    while (!CarStackEmpty(&temp)) 
    {
        PopCar(&temp, &x);
        PushCar(park, x, capacity);
        printf("汽车 %d 重新进入停车场。\n", x);
    }

    if (found && !QueueEmpty(road) && !CarStackFull(park, capacity)) 
    {
        DeQueue(road, &x);
        PushCar(park, x, capacity);
        printf("便道队头汽车 %d 进入停车场。\n", x);
    }
}

void ParkingManage() 
{
    SqStackTp park;
    QueptrTp road;
    int capacity;
    char cmd;
    int car;

    InitCarStack(&park);
    InitQueue(&road);

    printf("\n请输入停车场容量（1-%d）：", PARK_MAX);
    scanf("%d", &capacity);
    if (capacity < 1 || capacity > PARK_MAX) 
    {
        printf("容量输入不合法，默认设置为 3。\n");
        capacity = 3;
    }

    printf("\n命令说明：\n");
    printf("A 车号：汽车到达，例如 A 101\n");
    printf("D 车号：汽车离开，例如 D 101\n");
    printf("S 0 ：显示当前状态\n");
    printf("Q 0 ：退出停车场管理\n");

    while (1) 
    {
        printf("\n请输入命令和车号：");
        scanf(" %c", &cmd);
        cmd = (char)toupper((unsigned char)cmd);

        if (cmd == 'Q') 
        {
            scanf("%d", &car);
            printf("退出停车场管理。\n");
            break;
        }

        if (cmd == 'S') 
        {
            scanf("%d", &car);
            ShowParking(&park, &road);
            continue;
        }

        scanf("%d", &car);
        if (car <= 0) 
        {
            printf("车号为 0 或负数，退出停车场管理。\n");
            break;
        }

        if (cmd == 'A') 
        {
            ArriveCar(&park, &road, car, capacity);
        }
        else if (cmd == 'D') 
        {
            LeaveCar(&park, &road, car, capacity);
        }
        else {
            printf("命令错误，请输入 A、D、S 或 Q。\n");
        }
        ShowParking(&park, &road);
    }
}

/* ============================================================
   主菜单
   ============================================================ */

void MainMenu() 
{
    printf("\n================ 数据结构课程设计 ================\n");
    printf("1. 算术表达式求值\n");
    printf("2. 停车场管理\n");
    printf("0. 退出系统\n");
    printf("==================================================\n");
    printf("请选择：");
}

int main() 
{
    int choice;

    while (1) 
    {
        MainMenu();
        if (scanf("%d", &choice) != 1) 
        {
            printf("输入错误，程序结束。\n");
            break;
        }

        if (choice == 1)
        {
            EvaluateExpression();
        }
        else if (choice == 2) 
        {
            ParkingManage();
        }
        else if (choice == 0) 
        {
            printf("退出系统。\n");
            break;
        }
        else 
        {
            printf("选择错误，请重新输入。\n");
        }
    }

    return 0;
}
