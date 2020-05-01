//
//  main.cpp
//  leetcode_链表_1
//
//  Created by 何忆源 on 2020/4/30.
//  Copyright © 2020 何忆源. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node                          //定义一个链表结构
{
    int data;                        //链表节点的数据
    struct Node * pNext;             //链表节点指向下一个节点的指针
};
int i;
struct Node * create_list(void);     //创建链表的函数声明
void traverse_list(struct Node *);   //打印链表的函数声明
int main()
{
    struct Node * pHead = NULL;     //先给头指针赋值为NULL
    pHead = create_list();
    //调用链表创建函数，并将头指针的值赋给pHead
    traverse_list(pHead);           //打印链表
    return 0;
}
struct Node * create_list(void)     //创建链表的函数
{
    int len;                        //链表的节点数
    int val;                        //链表节点中数据域的值
 //   int deldata;
    struct Node * pHead=(struct Node *)malloc(sizeof(struct Node));  //动态分配头结点的内存
    if(pHead == NULL)
    {
        printf("内存分配失败，程序终止！\n");
        exit(-1);
    }
    struct Node * pTail = pHead;                        //定义一个尾节点指针，将pHead的值赋给它
    pTail->pNext = NULL;                                //尾节点的指针域一定为空
    printf("请输入您需要生成的链表节点的个数：len =");
    scanf("%d",&len);
    
    for (i=0;i<len;i++)
    {
        printf("请输入第%d个节点的值:",i+1);
        scanf("%d",&val);
        struct Node * pNew=(struct Node *)malloc(sizeof(struct Node));  //动态分配新节点的内存
        if(pNew== NULL)
    {
        printf("内存分配失败，程序终止！\n");
        exit(-1);
    }
//        printf("请输入要删除的节点");
//        scanf("%d",&deldata);
        pNew->data = val;       //把输入的值传给*pNew数据域
        pNew->pNext = NULL;     // *pNew是新的尾节点，所以 pNew->pNext应该为空
        pTail->pNext = pNew;    //把*pNew的地址传给pTail->pNext指针域，等效于*pTail.pNext=pNew
                                //第一次的pTail->pNext = pNew相当于把首节点的地址给了头结点
                                
        pTail = pNew;                                          //执行此操作，*pNew就变成了新的*pTail
                                //之后的pTail = pNew则是让最后一个与上一个节点连接上
     }
    return pHead;               //返回 pHead的值
    
}
void traverse_list(struct Node * pHead)  //遍历链表
{
    struct Node * p = pHead->pNext;      //定义一个指向下一个节点的指针
    while(p!=NULL)                       //尾节点的指针域一定是NULL，如果非NULL，则继续打印
    {
        printf("%d\t",p->data);
        p = p->pNext;                    //下一个节点的地址赋值给p
    }
    return;                              //循环结束
}
