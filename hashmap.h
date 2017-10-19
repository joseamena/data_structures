//
//  hashmap.h
//  DataStructures
//
//  Created by Viviana Uscocovich-Mena on 10/18/17.
//  Copyright © 2017 Viviana Uscocovich-Mena. All rights reserved.
//

#ifndef hashmap_h
#define hashmap_h

#include "list.h"
#include <stdint.h>

typedef struct hashmap hashmap_t;

hashmap_t *hashmap_create(void);
void  hashmap_init(hashmap_t *map, uint32_t (*hash_function)(void *));
void  hashmap_set_object(hashmap_t *map, void *key, void *object);
void *hashmap_get_object(hashmap_t *map, void *key);

#endif /* hashmap_h */
