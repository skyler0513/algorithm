
#include "seq.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 初始化
 * @param p
 */
static void init(PSeqQueue p)
{
    p->in = 0;
    p->out = 0;
    p->len= 0;
}

/**
 * 是否已满
 * @param p
 */
static bool hasFilled(PSeqQueue p)
{
    if (p->len == MAX) {
        return true;
    } else {
        return false;
    }
}

/**
 * 是否为空
 * @param p
 */
static bool isEmpty(PSeqQueue p)
{
    if (p->len == 0) {
        return true;
    } else {
        return false;
    }
}


/**
 * 进队列
 * @param p
 * @param v
 */
static void enQueue(PSeqQueue p, int v)
{
    if (hasFilled(p)) {
        printf("the queue is filled ! the enqueue value is %d\n", v);
        exit(0);
    }

    p->data[p->in] = v;
    //进队列的位置向前移
    p->in = (p->in + 1) % MAX;
    //队列的长度增加
    p->len++;
}

/**
 * 出队列
 * @param p
 */
static int deQueue(PSeqQueue p)
{
    if (isEmpty(p)) {
        printf("the queue is empty\n");
        exit(0);
    }

    int v = p->data[p->out];
    //向前移出队列的位置
    p->out = (p->out + 1) % MAX;
    //队列长度减少
    p->len--;

    return v;
}

/**
 * 测试
 */
int seqQueue()
{
    SeqQueue queue;

    init(&queue);

    for (int i = 0; i < MAX; i++) {
        enQueue(&queue, i);
    }

    for (int j = 0; j < MAX; j++) {
        int v = deQueue(&queue);
        printf("%d\n",v);
    }

    return 0;
}
