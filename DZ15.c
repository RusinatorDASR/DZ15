#include <stdio.h>
#include <stdlib.h>

//=============== Task 1 =================//

int hashFunc(char* arr) {
    int sum = 0;
    while (*arr != '\0') {
        sum += *arr;
        arr++;
    }
    return sum;
}
//=============== Task 2 =================//

int* greedy(int* money, int size, int sum) {
    if (size == 0 || sum == 0) return NULL;

    int* answ = (int*) calloc(100, sizeof(int));
    answ[0] = 0;
    int current, k = 1;
    for (int i = 0; i < size; ++i) {
        current = 0;
        while (sum - current >= money[i]) {
            current += money[i];
            answ[k] = money[i];
            answ[0]++;
            k++;
            if (sum == current) return answ;
        }
        sum -= current;
    }
    printf("%s \n", "Exchange failed");
    return NULL;
}
void printArr(int* array) {
    int i = 1;
    while (i <= array[0]) {
        printf("%d ", array[i]);
        ++i;
    }
    printf("\n");
}
int main()
{
    printf("Somemessage: %d", hashFunc("Somemessage"));
    printf("\n");
    printf("98: \n");
    int money[] = {50, 10, 5, 2, 1};
    printArr(greedy(money, 5, 98));
    return 0;
}
