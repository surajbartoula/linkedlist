#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack {
    int data;
    struct s_stack *next;
} t_stack;

void ft_lstadd_back(t_stack **lst, t_stack *new_lst) {
    t_stack *node;

    if (*lst) {
        node = *lst;
        while (node->next)
            node = node->next;
        node->next = new_lst;
    } else
        *lst = new_lst;
}

int main() {
    // Create the head pointer and initialize it to NULL
    t_stack *head = NULL;

    // Create some nodes and add them to the list
    for (int i = 1; i <= 5; i++) {
        // Create a new node
        t_stack *newNode = (t_stack *)malloc(sizeof(t_stack));
        newNode->data = i;
        newNode->next = NULL;

        // Add the new node to the end of the list
        ft_lstadd_back(&head, newNode);
    }

    // Print the elements of the list
    printf("Elements of the list: ");
    t_stack *current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    // Free memory allocated for the nodes
    while (head) {
        t_stack *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}