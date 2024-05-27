#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

typedef struct {
    int *data;
    int size;
    int capacity;
} List;

void initList(List *list) {
    list->data = (int *)malloc(INITIAL_CAPACITY * sizeof(int));
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
}

void resizeListIfNeeded(List *list) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->data = (int *)realloc(list->data, list->capacity * sizeof(int));
    }
}

void insert(List *list, int index, int value) {
    if (index < 0 || index > list->size) return;
    resizeListIfNeeded(list);
    for (int i = list->size; i > index; i--) {
        list->data[i] = list->data[i - 1];
    }
    list->data[index] = value;
    list->size++;
}

void printList(const List *list) {
    printf("[");
    for (int i = 0; i < list->size; i++) {
        printf("%d", list->data[i]);
        if (i < list->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void removeValue(List *list, int value) {
    for (int i = 0; i < list->size; i++) {
        if (list->data[i] == value) {
            for (int j = i; j < list->size - 1; j++) {
                list->data[j] = list->data[j + 1];
            }
            list->size--;
            return;
        }
    }
}

void append(List *list, int value) {
    resizeListIfNeeded(list);
    list->data[list->size++] = value;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void sortList(List *list) {
    qsort(list->data, list->size, sizeof(int), compare);
}

void pop(List *list) {
    if (list->size > 0) {
        list->size--;
    }
}

void reverse(List *list) {
    int temp;
    for (int i = 0; i < list->size / 2; i++) {
        temp = list->data[i];
        list->data[i] = list->data[list->size - i - 1];
        list->data[list->size - i - 1] = temp;
    }
}

void freeList(List *list) {
    free(list->data);
}

int main() {
    int n;
    scanf("%d", &n);

    List list;
    initList(&list);

    for (int i = 0; i < n; i++) {
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "insert") == 0) {
            int index, value;
            scanf("%d %d", &index, &value);
            insert(&list, index, value);
        } else if (strcmp(command, "print") == 0) {
            printList(&list);
        } else if (strcmp(command, "remove") == 0) {
            int value;
            scanf("%d", &value);
            removeValue(&list, value);
        } else if (strcmp(command, "append") == 0) {
            int value;
            scanf("%d", &value);
            append(&list, value);
        } else if (strcmp(command, "sort") == 0) {
            sortList(&list);
        } else if (strcmp(command, "pop") == 0) {
            pop(&list);
        } else if (strcmp(command, "reverse") == 0) {
            reverse(&list);
        }
    }

    freeList(&list);
    return 0;
}
