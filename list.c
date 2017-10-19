//
//  list.c
//

#include "list.h"

void list_init_head(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static void __list_add(struct list_head *new,
                       struct list_head *prev,
                       struct list_head *next)
{
    prev->next = new;
    new->prev = prev;
    next->prev = new;
    new->next = next;
}

void list_add_tail(struct list_head *new, struct list_head *head)
{
    struct list_head *prev = head->prev;
    struct list_head *next = head;
    __list_add(new, prev, next);
}

void list_add(struct list_head *new, struct list_head *head)
{
    struct list_head *prev = head;
    struct list_head *next = head->next;
    __list_add(new, prev, next);
}

void list_del(struct list_head *entry)
{
    entry->prev->next = entry->next;
    entry->next->prev = entry->prev;
}

int list_empty(struct list_head *head)
{
    return head->next == head;
}
