#ifndef HEAP_SORT_H
#define HEAP_SORT_H

void max_heapify(int nums[], int heap_size, int i);
void build_max_heap(int nums[], int len);
void heap_sort(int nums[], int len);

// TODO: 实现下面的函数可以利用堆实现一个优先队列
void max_heap_insert();
int heap_extract_max(int nums[], int heap_size);
void heap_increase_key();
int heap_maximum(int nums[]);

#endif
