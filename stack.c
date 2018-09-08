#include "stdio.h"
#include "stdlib.h"

#define NULLSTACK (-1)
#define MAXREACHED (-2)
#define UNDERFLOW (-3)
#define MEMFULL (-4)
#define SUCCESS (0)

#define MAX_SIZE 10
#define EMPTY -1
typedef struct
{
    void *area;
    int top;
}stack; 


int initStack(stack *s)
{
    s = (stack *) malloc(sizeof(stack));
    if(!s)
        return MEMFULL;

    s->area = malloc(MAX_SIZE * sizeof(int));
    
    if(!s->area)
        return MEMFULL;

    s->top = -1;
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
    ((int *)s->area)[s->top] = val;
    return SUCCESS;
}

int pop(stack *s, int *val)
{
    if(!s)
        return NULLSTACK;

    if(s->top == EMPTY)
        return UNDERFLOW;
    
    *val = ((int *)s->area)[s->top--];
    return SUCCESS;
}

int main()
{
    stack *s;
    int err = initStack(s);
    int val = 0;

    if(err != SUCCESS)
        printf("\r\nStack Init Error (%d)", err);
    else
        printf("\r\nStack Init Complete");

    while((err = push(s,val)) == SUCCESS)
    {
        printf("\r\nPushed (%d)", val);
        val++;
    }
    printf("\r\nPush Error (%d)",err);

    while((err = pop(s, &val)) == SUCCESS)
    {
        printf("\r\nPopped Value (%d)", val);
    }
    printf("\r\nPop Error (%d)", err);

    deinitStack(s);

    return 0;
}