#include <stdio.h>
#include <stdlib.h>

typedef int ElemType; /* 简单数据类型 */

typedef struct tagNode
{
    ElemType data;
    struct tagNode *next;
} LNode, *LinkList;

void input(ElemType *ep)
{
    scanf("%d", ep);
}

void CreatLinkF(LinkList *L, int n, void (*input)(ElemType *))
{
    // 头插法创建单链表
    LinkList s;
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    for (; n > 0; n--)
    {
        s = (LinkList)malloc(sizeof(LNode));
        input(&s->data);
        s->next = (*L)->next;
        (*L)->next = s;
    }
}

void CreatLinkFuncR(LinkList *L, int n, void (*input)(ElemType *))
{
    // 尾插法创建单链表
    *L = (LinkList)malloc(sizeof(LNode));
    LinkList s, r;
    r = L;
    for (; n > 0; n--)
    {
        s = (LinkList)malloc(sizeof(LNode));
        input(&s->data);
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

/* 输出链表 */
void visit(ElemType *ep)
{
    printf("%d", *ep);
}

/* 链表遍历 */
void ListTraverse(LinkList L, void (*vist)(ElemType *))
{
    // 遍历L中的每个元素且调用Visit函数访问它
    LinkList p = L->next;
    while (p != NULL)
    {
        visit(&(p->data));
        p = p->next;
    }
}

/* 尾插法链表遍历 */
void ListTraverseR(LinkList L, void (*vist)(ElemType *))
{
    // 遍历L中的每个元素且调用Visit函数访问它
    LinkList p = L;
    while (p != NULL)
    {
        visit(&(p->data));
        p = p->next;
    }
}

int main()
{

    LinkList L, S;

    S = L;

    CreatLinkFuncR(&L, 5, input);

    printf("print List Begin!\n");

    ListTraverseR(S, visit);

    /* 熟悉一下vscode阅读代码快捷键 */

    ListTraverseR(S, visit);

    return 0;
}