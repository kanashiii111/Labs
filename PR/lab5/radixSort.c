#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void radixComparatorUp(int count[]) {
    for (int i = 1; i < 19; i++) {
        count[i] += count[i - 1];
    }
}
void radixComparatorDown(int count[]) {
    for (int i = 17; i >= 0; i--) {
        count[i] += count[i + 1];
    }
}
void countSort(int* arr, int size, int exp) {
    int* output = malloc(size * sizeof(int));
    int count[19] = {0};
    for (int i = 0; i < size; i++) {
        count[((arr[i] / exp) % 10) + 9]++;
    }
    radixComparatorDown(count);
    for (int i = size - 1; i >= 0; i--) {
        long index = count[((arr[i] / exp) % 10) + 9] - 1;
        output[index] = arr[i];
        count[((arr[i] / exp) % 10) + 9]--;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
    }
    free(output);
}

void radixSort(int* arr, int size, FILE* outputFile) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    for (int exp = 1; max / exp > 0; exp*=10) {
        countSort(arr, size, exp);
    }
    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }
}

int main(void) {
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w+");
    int n;
    fscanf(inputFile, "%d", &n);
    int* array = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &array[i]);
    }
    radixSort(array, n, outputFile);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}
