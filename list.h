//
//  list.h
//  Implementation of a linked list
//  mimics the implementation in the linux kernel
//  as i find it better for the list to not know about the data
//

#ifndef list_h
#define list_h

struct list_head {
    struct list_head *prev;
    struct list_head *next;
};

#ifndef offsetof
#define offsetof(type,_member) (&((type *)0)->_member)
#endif

#ifndef container_of
#define container_of(ptr,type,member) (type *)((char *)ptr - (char *)offsetof(type, member))
#endif

#define list_entry(ptr, type, member) container_of(ptr, type, member)

#define list_for_each(pos, head) for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_for_each_prev(pos, head) for (pos = (head)->prev; pos != (head); pos = pos->prev)

#define list_for_each_safe(pos, n, head) \
        for (pos = (head)->next, n = pos->next; pos != (head); \
        pos = n, n = pos->next)

#define list_for_each_prev_safe(pos, n, head) \
        for (pos = (head)->prev, n = pos->prev; \
        pos != (head); \
        pos = n, n = pos->prev)

void list_init_head(struct list_head *list);
void list_add(struct list_head *new, struct list_head *head);
void list_add_tail(struct list_head *new, struct list_head *head);
void list_del(struct list_head *entry);
int list_empty(struct list_head *head);


#endif /* list_h */
