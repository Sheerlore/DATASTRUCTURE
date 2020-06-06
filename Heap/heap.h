#ifndef HEAP_TREE_H_INCLUDED
#define HEAP_TREE_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>

//ヒープ型
typedef struct Heap_tag* Heap;

/*
    ヒープを作成する
    引数:
        capacity: ヒープの最大容量
    戻り値:
        作成されたヒープ
        使い終わったら、heap_delete関数に渡して削除する
*/
Heap heap_create(size_t capacity);

/*
    ヒープを削除する
    引数:
        heap: ヒープへのポインタ
*/
void heap_delete(Heap heap);

/*
    ヒープに要素を挿入する
    引数:
        heap:   ヒープへのポインタ
        value:  挿入する要素の値
    戻り値:
        true:   成功
        false:  失敗
*/
bool heap_insert(Heap heap, int value);

/*
    ヒープから根を取り除く
    引数:
        heap:   ヒープへのポインタ
        value:  取り除かれた要素を受け取るメモリアドレス
    戻り値:
        true:   成功
        false:  失敗
*/
bool heap_remove_root(Heap heap, int* value);

/*
    ヒープから要素を探す
    引数:
        heap:   ヒープへのポインタ
        value:  探し出す要素の値
    戻り値:
        true:   成功
        false:  失敗
*/
bool heap_search(const Heap heap, int value);

/*
    ヒープに格納されている要素数を返す
    引数:
        heap:   ヒープへのポインタ
    戻り値:
        格納されている要素の個数
*/
size_t heap_getsize(const Heap heap);

/*
    ヒープの内容を出力する
    引数:
        heap:   ヒープへのポインタ
*/
void heap_print(const Heap heap);



#endif