
#include "link.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * 初始化
 * @param p
 */
void init(PLinkStack p)
{
    if (p == NULL) {
        printf("invalid stack\n");
        exit(1);
    }

    PNode node = (PNode)malloc(sizeof(Node));
    node->pre = NULL;

    p->top = node;
    p->bottom = p->top;
}

/**
 * 压栈
 * @param p
 * @param v
 */
static void push(PLinkStack p, int v)
{
    PNode new = (PNode)malloc(sizeof(Node));
    new->data = v;

    new->pre = p->top;
    p->top = new;
}

/**
 * 弹栈
 * @param p
 * @return
 */
static int pop(PLinkStack p)
{
    if (p->top == p->bottom) {
        printf("the stack is empty \n");
        exit(0);
    }

    PNode node = p->top;
    int v = node->data;
    p->top =node->pre;
    free(node);

    return v;
}

/**
 * 测试
 */
void linkStack()
{
    LinkStack stack;

    init(&stack);

    for (int i = 0; i < 10; i++) {
        push(&stack, i);
    }

    for (int i = 0; i < 10; i++) {
        int v =pop(&stack);
        printf("%d\n", v);
    }
}