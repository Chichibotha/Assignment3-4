#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int capacity = 5;
    char** words = (char**)malloc(capacity * sizeof(char*));
    
    const char* initWords[] = {"alpha", "bravo", "charlie", "delta", "echo"};
    for (int i = 0; i < capacity; i++) {
        words[i] = (char*)malloc((strlen(initWords[i]) + 1) * sizeof(char));
        strcpy(words[i], initWords[i]);
    }
    
    printf("[Initial Dictionary]\n");
    for (int i = 0; i < capacity; i++) {
        printf("[%d] %s\n", i, words[i]);
    }
    
    char searchWord[] = "delta";
    int foundIndex = -1;
    for (int i = 0; i < capacity; i++) {
        if (strcmp(words[i], searchWord) == 0) {
            foundIndex = i;
            break;
        }
    }
    printf("\n[Search Result] \n%s found at index %d\n", searchWord, foundIndex);
    free(words[1]);
    words[1] = (char*)malloc(10 * sizeof(char));  
    strcpy(words[1], "blueberry");
    
    printf("\n[After Update]\n");
    for (int i = 0; i < capacity; i++) {
        printf("[%d] %s\n", i, words[i]);
    }
    free(words[2]);  
    for (int i = 2; i < capacity - 1; i++) {
        words[i] = words[i + 1];
    }
    capacity--; 
    
    printf("\n[After Delete]\n");
    for (int i = 0; i < capacity; i++) {
        printf("[%d] %s\n", i, words[i]);
    }
    
    for (int i = 0; i < capacity; i++) {
        free(words[i]);
    }
    free(words);
    
    return 0;
}