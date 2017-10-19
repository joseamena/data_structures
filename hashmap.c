//
//  hashmap.c
//  DataStructures
//
//  Created by Viviana Uscocovich-Mena on 10/18/17.
//  Copyright © 2017 Viviana Uscocovich-Mena. All rights reserved.
//

#include "hashmap.h"
#include "vector.h"
#include <stdint.h>
#include <stdlib.h>

#define HASH_MAP_TABLE_SIZE (97)

struct hashmap_item {
    void *key;
    void *object;
    struct list_head list;
};

typedef struct hashmap {
    struct list_head lists[HASH_MAP_TABLE_SIZE];
    uint32_t (*hash_function)(void *);
} hashmap_t;

hashmap_t *hashmap_create(void) {
    return malloc(sizeof(hashmap_t));
}

void hashmap_init(hashmap_t *map, uint32_t (*hash_function)(void *)) {
    int i;
    for (i = 0; i < HASH_MAP_TABLE_SIZE; i++) {
        list_init_head(&map->lists[i]);
    }
    map->hash_function = hash_function;
    
}

void hashmap_set_object(hashmap_t *map, void *key, void *object) {
    uint32_t hash = map->hash_function(key);
    uint32_t index = hash % HASH_MAP_TABLE_SIZE;
    struct list_head *pos;
    struct hashmap_item *item = 0;
    struct hashmap_item *temp;
    
    list_for_each(pos, &map->lists[index]) {
        temp = list_entry(pos, struct hashmap_item, list);
        if (temp->key == key) {
            item = temp;
            break;
        }
    }
    
    //update object for key
    if (item) {
        item->object = object;
        return;
    }
    
    //insert new object
    item = malloc(sizeof(struct hashmap_item));
    
    if (!item) {
        return;
    }
    
    item->key = key;
    item->object = object;
    
    struct list_head *head = &map->lists[index];
    list_add_tail(&item->list, head);
}

void *hashmap_get_object(hashmap_t *map, void *key) {
    uint32_t hash = map->hash_function(key);
    uint32_t index = hash % HASH_MAP_TABLE_SIZE;
    
    struct list_head *head = &map->lists[index];
    struct list_head *pos;
    
    list_for_each(pos, head) {
        struct hashmap_item *item = list_entry(pos, struct hashmap_item, list);
        if (item->key == key) {
            return item->object;
        }
    }

    return 0;
}
