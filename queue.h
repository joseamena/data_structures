//
//  queue.h
//  DataStructures
//
//  Created by Viviana Uscocovich-Mena on 10/16/17.
//  Copyright © 2017 Viviana Uscocovich-Mena. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include "list.h"

typedef struct list_head queue_t;

void queue_init(queue_t *q);
void queue_enqueue(queue_t *q, void *item);
void *queue_dequeue(queue_t *q);


#endif /* queue_h */
