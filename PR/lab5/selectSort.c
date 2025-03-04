#include <stdio.h>
#include <stdlib.h>

int selectionComparatorUp(int first, int second) {
    return first < second;
}
int selectionComparatorDown(int first, int second) {
    return first > second;
}
int operation(int (*op)(int, int), int a, int b) {
    return op(a,b);
}
void selectionSort(int array[], int size, FILE *outputFile) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (operation(selectionComparatorUp, array[j], array[minIndex]) == 1) {
                minIndex = j;
            }
        }
        printf("Sorted %d/%d\n", i, size);
        if (minIndex != i) {
            int temp = array[minIndex];
            array[minIndex] = array[i];
            array[i] = temp;
        }
    }
    printf("Sorted");
    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", array[i]);
    }
} 
int main(void) {
    long long n;
    FILE *outputFile = fopen("output.txt", "w");
    FILE *file = fopen("test.txt", "r");
    fscanf(file, "%lld", &n);
    int* array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &array[i]);
    }
    selectionSort(array, n, outputFile);
    fclose(file);
    fclose(outputFile);
    return 0;
}
