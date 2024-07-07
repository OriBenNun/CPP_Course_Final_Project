#pragma once
class linked_list
{
    int data_ = 0;
public:
    linked_list* next;
    void push(linked_list** head_ref, int new_data);
    void insert_after(linked_list* prev_node, int new_data);
    void printList(linked_list* h);
    void append(linked_list** head_ref, int new_data);
    linked_list* find_in_list(linked_list* head, int data);
};

