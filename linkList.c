//
// Created by cyq7on on 18-3-3.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <memory.h>

#define N 5
#define esp 1e-6

typedef struct node {
    float val;
    struct node *next;
} node;

//尾插法
node *creatLinkList(float *val) {
    node *head = (node *) malloc(sizeof(node));
    node *p = head;
    for (int i = 0; i < N; ++i) {
        node *tmp = (node *) malloc(sizeof(node));
        tmp->val = val[i];
        p->next = tmp;
        p = tmp;
    }
    p->next = NULL;
    return head;
}

//头插法
node *creatReverseLinkList(float *val) {
    node *head = (node *) malloc(sizeof(node));
    head->next == NULL;
    node *p;
    for (int i = 0; i < N; ++i) {
        p = (node *) malloc(sizeof(node));
        p->val = val[i];
        p->next = head->next;
        head->next = p;
    }
    return head;
}

//头插法
node *reverseLinkList(node *head) {
    node *p = head->next;
    node *q;
    head->next = NULL;
    while (p) {
        q = p->next;
        p->next = head->next;
        head->next = p;
        p = q;
    }
    return head;
}

//查找元素
int find(node *head, float num) {
    node *p = head->next;
    while (p) {
        if (fabs(p->val - num) < esp) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}

//添加元素
void add(node *head, float num) {
    if (find(head, num)) {
        return;
    }
    node *p = head->next, *pre;
    while (p) {
        pre = p;
        p = p->next;
    }
    p = (node *) malloc(sizeof(node));
    p->val = num;
    p->next = NULL;
    pre->next = p;
}

//删除元素
void delete(node *head, float num) {
    node *p = head->next, *pre = head;

    while (p) {
        if (fabs(p->val - num) < esp) {
            pre->next = p->next;
            free(p);
        }
        pre = p;
        p = p->next;
    }
}

//求交集并由head1返回
void intersection(node *head1, node *head2) {
    node *p = head1->next, *pre = head1;

    while (p) {
        if (find(head2, p->val)) {
            //head2里存在相同元素，直接迭代
            pre = p;
            p = p->next;
        } else {
            //去掉当前结点并且释放内存
            pre->next = p->next;
            free(p);
            p = pre->next;
        }
    }
}

//求并集并由head1返回
void unionLinkList(node *head1, node *head2) {
    node *foot = head1->next, *p, *q;

    while (foot->next) {
        foot = foot->next;
    }

    q = head2->next;
    //新建结点方式
    /*while (q) {
        if (!find(head1, q->val)) {
            p = (node *)malloc(sizeof(node));
            p->val = q->val;
            foot->next = p;
            foot = p;
        }
        q = q->next;
    }*/

    //删除结点方式
    p = head2;
    while (q) {
        if (find(head1, q->val)) {
            p->next = q->next;
            free(q);
            q = p->next;
        } else {
            p = q;
            q = q->next;
        }
    }
    foot->next = head2->next;
}

void print(node *head) {
    printf("\n");
    node *p = head->next;
    while (p) {
        printf("%.2f->", p->val);
        p = p->next;
    }
    printf("\n");
}

void test() {
    char s1[100], s2[100];
    int i, j = 0, k = 0, len;
    scanf("%s", s1);
    scanf("%s", s2);
    len = strlen(s2);
    for (i = 0; s1[i]; ++i) {
        while (s1[i] != s2[j]) {
            j++;
        }
        if (j >= len) {
            s1[k++] = s1[i];
        }
        j = 0;
    }
    s1[k] = '\0';
    printf("%s",s1);
}

void main() {
    test();

    float val[N], data[N];
    float deleteNum, addNum, findNum;

    printf("\n请输入第一组数据\n");
    for (int i = 0; i < N; ++i) {
        scanf("%f", &val[i]);
    }
    node *p = creatLinkList(val);
    print(p);
    print(reverseLinkList(p));
    print(creatReverseLinkList(val));

    printf("\n请输入第二组数据\n");
    for (int i = 0; i < N; ++i) {
        scanf("%f", &data[i]);
    }
    node *q = creatLinkList(data);

    printf("\n请输入查找元素\n");
    scanf("%f", &findNum);

    printf("\n查找结果：%d\t%d\n", find(p, findNum), find(q, findNum));

    unionLinkList(p, q);
    printf("\n并集：");
    print(p);

//    printf("\n交集：");
//    intersection(p, q);
//    print(p);

    printf("\n请输入删除元素\n");
    scanf("%f", &deleteNum);
    delete(p, deleteNum);
    delete(q, deleteNum);
    print(p);
    print(q);


    printf("\n请输入添加元素\n");
    scanf("%f", &addNum);
    add(p, addNum);
    add(q, addNum);
    print(p);
    print(q);
}