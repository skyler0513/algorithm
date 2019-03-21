
#include "link.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 初始化
 * @param p
 */
static void init(PLinkList p)
{
    p->head = (PNode)malloc(sizeof(Node));

    if (p->head == NULL) {
        printf("initial the link list failed !\n");
        exit(0);
    }

    p->head->next = NULL;
}

/**
 * 检查位置
 */
static void invalidatePosition()
{
    printf("invalidate position value !\n");
    exit(0);
}

/**
 * 返回position - 1位置的节点的指针
 * @param p
 * @param position
 * @return
 */
static PNode findPrePosition(PLinkList p, int position)
{
    if (position < 1) {
        invalidatePosition();
    }

    if (position == 1) {
        return p->head;
    }

    int counter = 0;
    PNode index = p->head;

    while (counter < position - 1) {
        if (index == NULL) {
             invalidatePosition();
        }
        counter++;
        index = index->next;
    }

    return index;
}

/**
 * 判断是否为空
 * @param p
 */
static void checkEmpty(PLinkList p)
{
    if (p->head == NULL) {
        printf("Empty link list \n");
        exit(0);
    }
}

/**
 * 插入
 * @param p
 * @param position
 * @param data
 */
static void insert(PLinkList p, int position, int data)
{
    if (position < 1) {
        invalidatePosition();
    }

    PNode pre = findPrePosition(p, position);
    PNode new = (PNode)malloc(sizeof(Node));
    new->data = data;
    new->next = pre->next;
    pre->next = new;
}

/**
 * 遍历
 * @param p
 */
static void traversal(PLinkList p)
{
    checkEmpty(p);

    PNode index = p->head->next;

    while (index != NULL) {
        printf("%d\n", index->data);
        index = index->next;
    }
}

/**
 * 删除position处的节点
 * @param p
 * @param position
 * @return
 */
static int delete(PLinkList p, int position)
{
    checkEmpty(p);

    PNode pre = findPrePosition(p, position);
    PNode del = pre->next;
    int res = del->data;
    pre->next = pre->next->next;
    free(del);

    return res;
}

/**
 * 判断一个链表是否为空
 * @param p
 * @param value
 * @return
 */
static int checkExists(PLinkList p, int value)
{
    checkEmpty(p);

    PNode index = p->head->next;
    int res = 0;
    int position = 1;

    while (index != NULL) {
        if (index->data == value) {
            break;
        } else {
            index = index->next;
            position++;
        }
    }

    return position;
}

void linkList()
{
    LinkList list;
    init(&list);

    for (int i = 0; i < 10; i++) {
        insert(&list, i + 1, 10 - i);
    }

    //traversal(&list);

    delete(&list, 8);
    traversal(&list);
}