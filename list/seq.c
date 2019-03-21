
#include "seq.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * 初始化
 * @param p
 * @param capcity
 * @param increment
 */
static void init(PSeqList p, int capcity, int increment)
{
    p->capcity = capcity;
    p->increment = increment;
    p->len = 0;
    p->data = (int *)malloc(sizeof(int) * capcity);
}

/**
 * 插入
 * @param p
 * @param position
 * @param v
 */
static void insert(PSeqList p, int position, int v)
{
    int i;

    validatePosition(p, position);

    //需要扩容
    if (p->len == p->capcity) {
        increment(p);
    }

    //插入的位置正好是最后面
    if (position == p->len + 1) {
        p->data[position - 1] = v;
    } else {
        //移动插入位置后面所有的元素
        for (i = p->len; i >= position; i--) {
            p->data[i] = p->data[i - 1];
        }
        //插入
        p->data[i + 1] = v;
    }

    p->len++;
}

/**
 * 扩容
 * @param p
 */
static void increment(PSeqList p)
{
    //新的内存空间
    int *new = (int *)malloc(sizeof(int)*(p->increment + p->capcity));
    //老的内存空间
    int *data = p->data;

    //容量增大
    p->capcity += p->increment;

    //复制以前的数据
    for (int i=0; i < p->len; i++) {
        new[i] = data[i];
    }

    //指向新的内存地址
    p->data = new;

    //释放以前的内存
    free(data);
}

/**
 * 校验位置
 * @param p
 * @param position
 */
static void validatePosition(PSeqList p, int position)
{
    if (position > p->len + 1 || position < 1) {
        printf("illegal position value\n");
        exit(0);
    }
}

/**
 * 更新
 * @param p
 * @param position
 * @param v
 */
static void set(PSeqList p, int position, int v)
{
    validatePosition(p, position);

    p->data[position - 1] = v;
}

/**
 * 获取
 * @param p
 * @param position
 * @return
 */
static int get(PSeqList p, int position)
{
    validatePosition(p, position);

    return p->data[position - 1];
}

/**
 * 删除
 * @param p
 * @param position
 */
static void delete(PSeqList p, int position)
{
    int i;

    validatePosition(p, position);

    for (i = position; i < p->len; i++) {
        p->data[i - 1] = p->data[i];
    }

    p->len--;
}

/**
 * 返回一个value的位置
 * @param p
 * @param v
 * @return
 */
static int getPosition(PSeqList p, int v)
{
    int i;
    bool flag = false;

    for (i = 0; i < p->len; i++) {
        if (p->data[i] == v) {
            flag = true;
            break;
        }
    }

    if (flag) {
        return i + 1;
    } else {
        return -1;
    }
}

/**
 * 遍历
 * @param p
 */
static void traversal(PSeqList p)
{
    int i;

    if (p->len == 0) {
        printf("Empty List!\n");
        exit(0);
    }

    for (i = 0; i < p->len; i++) {
        printf("%d\n", p->data[i]);
    }
}

/*
 * 练习
 */
int seqList()
{
    SeqList list;

    init(&list, 10, 10);

    for (int i = 1; i <= 10; i++) {
        insert(&list, i, 10 - i);
    }

    //traversal(&list);

    for (int i = 11; i <= 20; i++) {
        insert(&list, i, i*10);
    }

    //insert(&list, 21, 119);

    //set(&list, 11, 111);

    //int value = get(&list, 1);
    //printf("%d\n", value);

    //int position = getPosition(&list, 0);
    //printf("%d\n", position);

    delete(&list,1);
    //delete(&list, 10);
    traversal(&list);
    return 0;
}