//
// Created by yehonatan401 on 3/28/26.
//
#include <stdio.h>
#include "dict.h"

int main() {
    dict di;
    dict_set(&di,"hi",9);
    printf("%d",dict_get(&di,"hi"));
    
}
