#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void readStrings(char **arr, int N) {
    for (int i = 0; i < N; i++) {
        char buffer[100];
        printf("Please enter string %d: ", i + 1);
        scanf("%s", buffer);
        // memory allocation based on string length
        arr[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(arr[i], buffer); // Copies string into the allocated mem
    }
}

// insertion sort for strings
void sortStrings(char **arr, int N) {
    for (int i = 1; i < N; i++) {
        char *temp = arr[i];
        int j = i - 1;
        while (j >= 0 && strcmp(arr[j], temp) > 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void displayStrings(char **arr, int N) {
    printf("Sorted strings: [");
    for (int i = 0; i < N - 1; i++) {
        printf("%s, ", arr[i]);
    }
    printf("%s]\n", arr[N - 1]);
}

int main() {
    int N;
    
 
    printf("Enter the number of strings: ");
    scanf("%d", &N);
    
    // allocates the memory for array of string pointers
    char **arr = (char **)malloc(N * sizeof(char *));
    
    readStrings(arr, N);
    sortStrings(arr, N);
    displayStrings(arr, N);
    for (int i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);
    
    return 0;
}
