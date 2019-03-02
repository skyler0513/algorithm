
#include <stdbool.h>

#ifndef ALGORITHM_QUEUE_H
#define ALGORITHM_QUEUE_H

#endif //ALGORITHM_QUEUE_H

#define MAX 10

typedef struct {
    int data[MAX];
    int in;
    int out;
    int len;
}SeqQueue, *PSeqQueue;

static void init(PSeqQueue p);

static bool hasFilled(PSeqQueue p);

static bool isEmpty(PSeqQueue p);

static void enQueue(PSeqQueue p, int v);

static int deQueue(PSeqQueue p);

int seqQueue();