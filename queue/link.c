
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/**
 * 初始化
 * @param p
 */
static void init(PLinkQueen p)
{
    p->in = (PNode)malloc(sizeof(Node));

    if (p->in == NULL) {
        printf("malloc an new mode failed\n");
    }

    p->in->next = NULL;
    p->out = p->in;
}

/**
 * 进队列
 * @param p
 * @param v
 */
static void enQueue(PLinkQueen p, int v)
{
    PNode new = (PNode)malloc(sizeof(Node));

    if (new == NULL) {
        printf("malloc an new node failed\n");
        exit(1);
    }
    new->next = NULL;
    p->in->data = v;
    p->in->next = new;
    p->in = new;
}

/**
 * 出队列
 * @param p
 * @return
 */
static int deQueue(PLinkQueen p)
{
    if (p->in == p->out) {
        printf("the queen is empty\n");
        exit(0);
    }

    int v = p->out->data;

    p->out = p->out->next;

    return v;
}

/**
 * 测试
 * @return
 */
int linkQueue()
{
     LinkQueen queue;

    init(&queue);

    for (int i = 0; i < 10; i++) {
        enQueue(&queue, i);
    }

    for (int j = 0; j < 10; j++) {
        int v = deQueue(&queue);
        printf("%d\n",v);
    }

    return 0;
}