// Purpose: Demonstrate NULL pointer intialization and safe usage

// key points: 
// 1. Intializa pointers to NULL when they don't yet point to valid data
// 2. Check pointers for NULL before using to void crashes
// 3. NULL checks allow graceful handling of unintialized or failed allocations

#include<stdio.h>
#include<stdlib.h>

int main() {
    // Intialize pointer to NULL
    int* ptr = NULL;
    // %p期望的是void*类型的参数，因为void*是一种通用的指针类型，可表示任何其他类型的指针
    printf("1. Intial ptr value: %p\n", (void*)ptr);

    // Check for NULL before using
    if (ptr == NULL){
        printf("2. ptr is NULL, cannot reference\n");
    }

    // Allocate memory
    ptr = malloc(sizeof(int));
    if (ptr == NULL) {
        printf("3. Memory allocation failed\n");
        return 1;
    }

    printf("4. After allocation, ptr value: %p\n", (void*)ptr);

    // 占位符
    // %p:打印指针变量
    // %d:有符号整数
    // %s:字符串
    // %c:单个字符
    // %f:用于输出浮点数
    // %%:输出百分数

    // safe to use ptr after NULL check
    *ptr = 88;
    printf("5. value at ptr: %d\n", *ptr);

    // clean up
    free(ptr); // 释放ptr指向的内存块
    ptr = NULL; // set to NULL after freeing，指针置NULL

    printf("6. After free, ptr value: %p\n", (void*)ptr);

    // Demonstrate safety of NULL check after free
    if (ptr == NULL) {
        printf("7. ptr is NULL, safety avoided use after free\n");
    }

    return 0;
}
