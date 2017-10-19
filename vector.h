//
//  vector.h
//

#ifndef vector_h
#define vector_h

typedef struct vector vector_t;

vector_t    *vector_create      (unsigned int capacity);
void         vector_append      (vector_t *vector, void *data);
void        *vector_get_item_at (vector_t *vector, unsigned int index);
unsigned int vector_size        (vector_t *vector);

#endif /* vector_h */
