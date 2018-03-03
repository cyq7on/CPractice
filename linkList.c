//
// Created by cyq7on on 18-3-3.
//
#include <stdlib.h>
#include <stdio.h>

#define N 5

typedef struct node {
    float val;
    struct node *next;
} node;

//尾插法
node *linkList(float val[N]) {
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
node *reverseLinList(float val[N]) {
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

void main() {
    float val[N];
    for (int i = 0; i < N; ++i) {
        scanf("%f",&val[i]);
    }
    node *p = linkList(val)->next;
    node *q = reverseLinList(val)->next;
    while (p) {
        printf("%4.2f->",p->val);
        p = p->next;
    }
    printf("\n");
    while (q) {
        printf("%4.2f->",q->val);
        q = q->next;
    }
}