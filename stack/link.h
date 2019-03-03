
#ifndef ALGORITHM_LINK_H
#define ALGORITHM_LINK_H

#endif //ALGORITHM_LINK_H

typedef struct Node
{
    //数据
    int data;
    //前一个节点
    struct Node *pre;
}Node, *PNode;

typedef struct
{
    //栈顶指针
    PNode top;
    //栈底指针
    PNode bottom;
}LinkStack, *PLinkStack;

static void init(PLinkStack p);

static void push(PLinkStack p, int v);

static int pop(PLinkStack p);

void linkStack();