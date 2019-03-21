
#include <sys/ucontext.h>

#ifndef ALGORITHM_SEQ_H
#define ALGORITHM_SEQ_H

#endif //ALGORITHM_SEQ_H

typedef struct
{
    //数据
    int *data;
    //当前长度
    int len;
    //容量
    int capcity;
    //每次增长的值
    int increment;
}SeqList, *PSeqList;

static void init(PSeqList p, int capcity, int increment);

static void traversal(PSeqList);

static void insert(PSeqList p, int position, int v);

static void set(PSeqList p, int position, int v);

static void delete(PSeqList p, int position);

static int getPosition(PSeqList p, int v);

static int get(PSeqList p, int position);

static void increment(PSeqList p);

static void validatePosition(PSeqList p, int position);

int seqList();
