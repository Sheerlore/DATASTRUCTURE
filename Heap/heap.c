#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"

#define SWAP(type, a, b){type work = a; a = b; b = work;}

struct Heap_tag{
    int* data;          //データ本体
    size_t capacity;    //最大容量
    size_t first_empty; //空になっている最初の位置
};

static void up_heap(Heap heap, size_t index);
static void down_root(Heap heap);
static void heap_print_node(const Heap heap, size_t index, int level);

Heap heap_create(size_t capacity){
    struct Heap_tag* heap = malloc(sizeof(struct Heap_tag));
    heap -> data = malloc(sizeof(int) * (capacity + 1)); //添字を1から始める
    heap -> capacity = capacity;
    heap -> first_empty = 1; //0番目は使わない

    return heap;
}

void heap_delete(Heap heap){
    if(heap != NULL){
        free(heap -> data);
        free(heap);
    }
}

bool heap_insert(Heap heap, int value){
    if(heap -> capacity < heap -> first_empty){
        return false;
    }

    //末尾に追加する
    size_t index = heap -> first_empty;
    heap -> data[index] = value;
    heap -> first_empty += 1;

    //適切な位置まで浮かび上がらせる
    up_heap(heap, index);
    return true;
}

bool heap_remove_root(Heap heap, int* value){
    if(heap_getsize(heap) <= 0){
        return false;
    }

    *value = heap -> data[1];
    //ヒープの最後にある要素を先頭に移動する
    heap -> first_empty -= 1;
    heap -> data[1]  = heap -> data[heap -> first_empty];

    //先頭に移動させた要素を正しい位置に沈める
    down_root(heap);

    return true;
}

bool heap_search(const Heap heap, int value){
    for(int i = 1; i < heap -> first_empty; ++i){
        if(heap -> data[i] == value){
            return true;
        }
    }

    return false;
}

size_t heap_getsize(const Heap heap){
    return heap -> first_empty - 1;
}

void heap_print(const Heap heap){
    if(heap == NULL || heap_getsize(heap) <= 0){
        return;
    }
    heap_print_node(heap, 1, 0);
}

void up_heap(Heap heap, size_t index){
    while(index > 1){
        size_t parent = index / 2;
        if(heap -> data[parent] > heap -> data[index]){
            SWAP(int, heap -> data[parent], heap -> data[index]);
            index = parent;
        }else{
            break;
        }
    }
}

void down_root(Heap heap){
    int index = 1;
    while(index * 2 <= heap -> first_empty){
        int child = index * 2;
        if(child + 1 < heap->first_empty){
            if(heap -> data[child] > heap -> data[child + 1]){
                child = child + 1;
            }
        }

        if(heap -> data[child] < heap -> data[index]){
            SWAP(int, heap -> data[child], heap -> data[index]);
            index = child;
        }else{
            break;
        }
    }
}

void heap_print_node(const Heap heap, size_t index, int level){
    for(int i = 1; i < level; ++i){
        printf("     ");
    }
    if(level > 0) {
        printf("%d\n", heap -> data[index]);
    }
    printf("%d\n", heap -> data[index]);

    //左の子
    index *= 2;
    if(index < heap -> first_empty){
        heap_print_node(heap, index, level + 1);
    }

    //右の子
    index += 1;
    if(index < heap -> first_empty){
        heap_print_node(heap, index, level + 1);
    }
}