#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *S;
};
void create(struct Stack *st)
{
    printf("Enter Size");
    scanf("%d", &st->size);
    (*st).top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}
void Display(struct Stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.S[i]);
    printf("\n");
}
void push(struct Stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
int pop(struct Stack *st)
{
    int x = -1;

    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}
int peek(struct Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid Index \n");
    else
        x = st.S[st.top - index + 1];

    return x;
}
int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}
int isBull(struct Stack st)
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}
int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    else
        return 0;
}
int stackTop(struct Stack st)
{
    if (st.top == -1)
        return -1;
    else
        return st.S[st.top];
}
int main()
{
    struct Stack st;
    create(&st);
    int choice,x,pos;
    printf("1. Enter 1 for push()\n");
    printf("2. Enter 2 for pop()\n");
    printf("3.Enter 3 for getting top most element stackTop()\n");
    printf("4. Enter 4 to get any desired psition element\n");
    printf("5. Enter 5 to diplay the whole stack\n");
    printf("6. Enter 6 to exit!!!!\n");
    do{
    printf("Enter your choice ");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("Enter the data to be pushed\n");
        scanf("%d",&x);
        push(&st,x);
        break;
    case 2:
        printf("The popped data is %d\n",pop(&st));
        break;
    case 3:
        printf("The top most data is %d\n",stackTop(st));
        break;
    case 4:
        printf("Enter the position");
        scanf("%d",&pos);
        printf("Your desired element is %d\n",peek(st,pos));
        break;
    case 5:
        printf("The whole stack is :---\n");
        Display(st);
        break;
    default:
        printf("You have entered invalid choice!!!\n");
        break;
    }
    }
    while(choice!=6);
    

    return 0;
}
