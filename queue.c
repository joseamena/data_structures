//
//  queue.c
//  DataStructures
//
//  Created by Viviana Uscocovich-Mena on 10/16/17.
//  Copyright © 2017 Viviana Uscocovich-Mena. All rights reserved.
//

#include "queue.h"
#include <stdlib.h>

typedef struct queue_item {
    void *data;
    struct list_head list;
} queue_item_t;

//#define STATIC_MEMORY

//#ifdef STATIC_MEMORY
//#define MAX_QUEUE_ITEM_COUNT (10)
//queue_item_t available_items[MAX_QUEUE_ITEM_COUNT];
//#endif

void queue_init(queue_t *q) {
    list_init_head(q);
}

void queue_enqueue(queue_t *q, void *data) {
    queue_item_t *item = malloc(sizeof(queue_item_t));

    if (!item) {
        return;
    }
    
    item->data = data;
    list_add_tail(&item->list, q);
}

void *queue_dequeue(queue_t *q) {
    if (list_empty(q)) {
        return 0;
    }
    queue_item_t *item = list_entry(q->next, struct queue_item, list);
    list_del(&item->list);
    void *data = item->data;
    free(item);
    return data;
}
