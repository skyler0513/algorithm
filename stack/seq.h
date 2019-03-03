
#ifndef ALGORITHM_SEQ_H
#define ALGORITHM_SEQ_H

#endif //ALGORITHM_SEQ_H

#define MAX 10

typedef struct
{
    //数组
    int data[MAX];
    //栈的最大元素个数
    int max;
    //栈的当前元素个数
    int size;
}SeqStack, *PSeqStack;

static void init(PSeqStack p);

static void push(PSeqStack p, int v);

static int pop(PSeqStack p);

void seqStack();