#include "linkedList.h"
#include <iostream>
using namespace std;

void linked_list::append(linked_list** head_ref, const int new_data)
{
    // 1. allocate node
    linked_list* new_node = new linked_list();

    // Used in step 5
    linked_list* last = *head_ref;

    // 2. Put in the data
    new_node->data_ = new_data;

    // 3. This new node is going to be
    // the last node, so make next of
    // it as NULL
    new_node->next = nullptr;

    // 4. If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }

    // 5. Else traverse till the last node
    while (last->next != nullptr) {
        last = last->next;
    }

    // 6. Change the next of last node
    last->next = new_node;
    return;
}

linked_list* linked_list::find_in_list(linked_list* head, int data)
{
    if (head == nullptr) {
        return nullptr;
    }

    if (head->data_ == data) {
        return head;
    }

    linked_list* head_copy = head;
    
    while (head_copy->next != nullptr) {
        if (head_copy->next->data_ == data) {
            return head_copy->next;
        }
        head_copy = head_copy->next;
    }
    return nullptr;
}

void linked_list::insert_after(linked_list* prev_node, int new_data)
{
    // 1. Check if the given prev_node is NULL
    if (prev_node == nullptr) {
        cout << "The given previous node cannot be NULL";
        return;
    }

    // 2. Allocate new node
    linked_list* new_node = new linked_list();

    // 3. Put in the data
    new_node->data_ = new_data;

    // 4. Make next of new node as
    // next of prev_node
    new_node->next = prev_node->next;

    // 5. move the next of prev_node
    // as new_node
    prev_node->next = new_node;
}

void linked_list::push(linked_list** head_ref, int new_data)
{

    // 1. allocate node
    linked_list* new_node = new linked_list();

    //head.data when head is a value
    //head->data when head is a pointer
    // 2. put in the data
    new_node->data_ = new_data;

    // 3. Make next of new node as head
    new_node->next = (*head_ref);

    // 4. Move the head to point to
    // the new node
    (*head_ref) = new_node;
}

void linked_list::printList(linked_list* h) {
    cout << "list=>" << '\n';
    while (h != nullptr) {
        cout << h->data_ << '\n';
        h = h->next;
    }
}