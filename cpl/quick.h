#include "cpl.h"
#include "vec.h"

static inline void swap(cpl_vector *v, int i, int j){
        int temp = v->data[i];
        v->data[i] = v->data[j];
        v->data[j] = temp; 
} 


static inline int partition(cpl_vector *v, int start, int end){
        int pivot = v->data[end];
        int index = start - 1;

        for (int i = start; i <= end - 1; i++){
                if (v->data[i] < pivot){
                        index++;
                        swap(v, i, index);
                }
                
        }

        swap(v, index + 1, end); 

        return index + 1;
}

static inline void quick(cpl_vector *v, int start, int end){
        if (start >= end)
                return;
  
        int index = partition(v, start, end);

        quick(v, start, index - 1); 
        quick(v, index + 1, end);
}
