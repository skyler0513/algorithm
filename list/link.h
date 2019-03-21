
#include <stdbool.h>

#ifndef ALGORITHM_LINK_H
#define ALGORITHM_LINK_H

#endif //ALGORITHM_LINK_H

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
}Node, *PNode;

typedef struct
{
    //头结点，指向第一个有数据的节点
    PNode head;

}LinkList, *PLinkList;

static void invalidatePosition();
static void init(PLinkList p);
static PNode findPrePosition(PLinkList p, int position);
static void insert(PLinkList p, int position, int data);
static int get(PLinkList p, int position);
static void traversal(PLinkList p);
static int checkExists(PLinkList p, int value);
static int delete(PLinkList p, int position);
static void checkEmpty(PLinkList p);
void linkList();