#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int main() {

    int N, ch, choose;
    struct vector_t *vector;
    printf("Podaj liczbę elementów: ");
    if (!scanf("%d", &N)) {
        printf("Incorrect input\n");
        return 1;
    }
    if(N < 1){
        printf("Incorrect input data\n");
        return 2;
    }

    //tab = (int *) malloc(N * sizeof(int));
    //if (tab == NULL) {
    //    printf("Failed to allocate memory\n");
    //    return 8;
    //}

    int err = vector_create_struct(&vector, N);
    if(err == 1){
        printf("Incorrect input\n");
        return 2;
    }
    if(err == 2){
        printf("Failed to allocate memory\n");
        return 8;
    }

    int i = 0;
    while(1){
        //clean buffer
        while((getchar())!='\n');
        printf("Co chcesz zrobic: ");
        if (!scanf("%d", &choose)) {
            printf("Incorrect input\n");
            vector_destroy_struct(&vector);
            return 1;
        }
        if(choose == 0){
            break;
        }
        else if(choose == 1){
            //add
            printf("Podaj kolejne liczby, które mają zostać dodane do tablicy: ");
            while(1){
                if (scanf("%d", &ch) != 1) {
                    printf("Incorrect input\n");
                   vector_destroy_struct(&vector);
                    return 1;
                }
               // printf(" ; %d ; ", ch);
                //ch = getchar();

                if(ch == 0){
                    //printf("lotafak\n");
                    break;
                }

                i++;
                //if(i - 1> vector->capacity){ /// todo
                  //  printf("Failed to allocate memory\n");
                 //   break;
                //}
                if(vector_push_back(vector, ch) == 2){
                    printf("Failed to allocate memory\n");
                    break;
                }
            }
            //printf("aaaa");
            if(vector->size != 0)
                vector_display(vector);
            else{
                printf("Buffer is empty\n");
                continue;
            }
        }
        else if(choose == 2){
            //remove
            printf("Podaj kolejne liczby, które mają zostać usuniete z tablicy: ");
            while(1){
                if (scanf("%d", &ch) != 1) {
                    printf("Incorrect input\n");
                    vector_destroy_struct(&vector);
                    return 1;
                }
                if(ch == 0){
                    //printf("lotafak\n");
                    break;
                }
                i++;

                vector_erase(vector, ch);
            }
            if(vector->size != 0)
                vector_display(vector);
            else{
                printf("Buffer is empty\n");
                continue;
            }
        }
        else{
            printf("Incorrect input data\n");
            continue;
        }
    }

    vector_destroy_struct(&vector);
    return 0;
}

