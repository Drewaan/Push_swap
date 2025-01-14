#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int data;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
} t_stack;

t_stack *create_stack()
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    stack->top = NULL;
    return stack;
}

void push(t_stack *stack, int data)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
}

int pop(t_stack *stack)
{
    if (stack->top == NULL)
    {
        printf("Stack underflow\n");
        return -1;
    }
    t_node *temp = stack->top;
    int popped_data = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return popped_data;
}

int main()
{
    t_stack *stack = create_stack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    return 0;
}

