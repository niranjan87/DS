#include "stdio.h"
#include "stdlib.h"

#define NULLSTACK (-1)
#define MAXREACHED (-2)
#define UNDERFLOW (-3)
#define MEMFULL (-4)
#define SUCCESS (0)

#define MAX_SIZE 100
#define EMPTY -1
typedef struct
{
    int *area;
    int top;
}stack; 


int initStack(stack **s)
{
    stack *ls;

    ls = (stack *) malloc(sizeof(stack));
    if(!ls)
        return MEMFULL;

    ls->area = (int *) malloc(MAX_SIZE * sizeof(int));
    
    if(!ls->area)
        return MEMFULL;

    ls->top = -1;
    *s = ls;
    return SUCCESS;
}

void deinitStack(stack *s)
{
    if(!s || !s->area)
        return;

    free(s->area);
    free(s);
    s = NULL;
}

int push(stack *s, int val)
{
    if(!s)
        return NULLSTACK;
    
    if(s->top == MAX_SIZE)
        return MAXREACHED;
    
    s->top++;
    s->area[s->top] = val;
    return SUCCESS;
}

int pop(stack *s, int *val)
{
    if(!s)
        return NULLSTACK;

    if(s->top == EMPTY)
        return UNDERFLOW;
    
    *val = s->area[s->top];
    s->top--;
    return SUCCESS;
}

int main()
{
    stack *s;
    int err = initStack(&s);
    int val = 0;

    if(err != SUCCESS)
    {
        printf("\r\nStack Init Error (%d)", err);
        return -1;
    }
    else
        printf("\r\nStack Init Complete");
    
    err = push(s,val);
    while(err == SUCCESS)
    {
        printf("\r\nPushed (%d)", val);
        val++;
        err = push(s,val);
    }
    printf("\r\nPush Error (%d)",err);

    while((err = pop(s, &val)) == SUCCESS)
    {
        printf("\r\nPopped Value (%d)", val);
    }
    printf("\r\nPop Error (%d)", err);

    deinitStack(s);
    printf("\r\nStack Deinit Complete...\r\n");
    return 0;
}