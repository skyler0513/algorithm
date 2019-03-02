
#ifndef ALGORITHM_LINK_H
#define ALGORITHM_LINK_H

#endif //ALGORITHM_LINK_H

typedef struct Node
{
    int data;
    struct Node *next;
}Node, *PNode;

typedef struct
{
    //进队列的位置
    PNode in;
    //出队列的位置
    PNode out;
}LinkQueen, *PLinkQueen;

static void init(PLinkQueen p);

static void enQueue(PLinkQueen p, int v);

static int deQueue(PLinkQueen p);

int linkQueue();