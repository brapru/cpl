#include "cpl.h"
#include "vec.h"

#define NOTFOUND -1

static inline int binsearch(int key, cpl_vector *v, int min, int max){
        if (min > max)
                return NOTFOUND;

        int midpoint = (min + max) / 2; 

        if (v->data[midpoint] < key)
                return binsearch(key, v, midpoint + 1, max);
        
        if (v->data[midpoint] > key)
                 return binsearch(key, v, min, midpoint - 1);
        
        return midpoint; 
}
