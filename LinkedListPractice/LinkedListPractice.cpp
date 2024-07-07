#include "linkedList.h"

void main() {
    linked_list* head= nullptr;
    linked_list* list = nullptr;
    linked_list* item = nullptr;
    list->printList(head);
    list->push(&head, 7);
    list->printList(head);
    list->push(&head, 9);
    list->printList(head);
    list->push(&head, 11);
    int data = 7;
    item = list->find_in_list(head, data);
    list->insert_after(item, 13);
    list->printList(head);
    // list->insert_after(head->next->next, 13);
    // list->printList(head);
    // list->insert_after(head->next->next, 15);
    // list->printList(head);
    // list->append(&head, 12);
    // list->printList(head);
}
