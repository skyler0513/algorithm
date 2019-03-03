
#include "seq.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * 初始化
 * @param p
 */
static void init(PSeqStack p)
{
    if (p == NULL) {
        printf("invalid stack\n");
        exit(1);
    }

    p->max = MAX;
    p->size = 0;
}

/**
 * 压栈
 * @param p
 * @param v
 */
static void push(PSeqStack p, int v)
{
    if (p->size == p->max) {
        printf("the stack is filled ! the pushed value is %d\n", v);
        exit(0);
    }

    p->data[p->size] = v;
    p->size++;
}

/**
 * 弹栈
 * @param p
 * @return
 */
static int pop(PSeqStack p)
{
    if (p->size == 0) {
        printf("the stack is empty\n");
        exit(0);
    }

    int v = p->data[p->size - 1];
    p->size--;

    return v;
}

/**
 * 测试
 */
void seqStack()
{
    SeqStack stack;

    init(&stack);

    for (int i = 0; i < MAX; i++) {
        push(&stack, i);
    }

    for (int i = 0; i < MAX+1; i++) {
        int v = pop(&stack);
        printf("%d\n", v);
    }
}