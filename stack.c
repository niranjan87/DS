#include "stdio.h"

#define NULLSTACK (-1)
#define MAXREACHED (-2)
#define UNDERFLOW(-3)
#define SUCCESS (0)

#define MAX_SIZE 10
#define EMPTY -1
typedef struct
{
    void *area;
    int top;
}stack; 

int push(stack *s, int val)
{
    if(!s)
        return NULLSTACK;
    
    if(top == MAX_SIZE)
        return MAXREACHED;
    
    s->top++;
    s->area[s->top] = val;
}

int pop(stack *s)
{
    is(!s)
        return NULLSTACK;

    if(s->top == EMPTY)
        return UNDERFLOW;
    
    return s->area[s->top--];

}