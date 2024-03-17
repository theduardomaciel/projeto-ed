#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "utils.h"
#include "stack.h"

/*
    ⮕ Funções públicas
    São funções que podem ser acessadas por qualquer arquivo que inclua este arquivo
*/

// Função para inicializar a pilha
stack *stack_init()
{
    stack *new_stack = malloc(sizeof(stack));
    NULL_POINTER_CHECK(new_stack);

    new_stack->top = NULL;
    new_stack->size = 0;

    return (new_stack);
}

// Função para adicionar um elemento no início da pilha
void stack_push(stack *stack, void *data)
{
    stack_node *new_node = malloc(sizeof(stack_node));
    NULL_POINTER_CHECK(new_node);

    new_node->data = data;
    new_node->next = stack->top;

    stack->top = new_node;
    stack->size++;
}

// Função para remover um elemento do início da pilha
void *stack_pop(stack *stack)
{
    if (stack->top == NULL)
    {
        return NULL;
    }

    stack_node *node = stack->top;
    void *data = node->data;

    stack->top = node->next;
    stack->size--;

    free(node);

    return data;
}

// Função para copiar a pilha
stack *stack_copy(stack *stack)
{
    stack_node *new_stack = stack_init();
    stack_node *current = stack->top;

    while (current != NULL)
    {
        stack_push(new_stack, current->data);
        current = current->next;
    }

    return new_stack;
}

// Função para destruir a pilha
void stack_destroy(stack *stack)
{
    stack_node *current = stack->top;
    stack_node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    free(stack);
}