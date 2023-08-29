#include <stdio.h>
#include <stdlib.h>
void mem(){
int * memoirePerte;
memoirePerte=malloc(sizeof(int));
*memoirePerte=5;
free(memoirePerte);
}
int main()
{
    // Non init
    int tmp=5;
    printf("non init : %d\n",tmp);
    int div0=3;
    printf("non init : %d\n",div0);
    // Perte memoire
    mem();

    //division par 0
    int num = 10;
    int denom = 0;
    int result;
    result = 1/denom;
    result++;
    printf("Result: %d\n", result);

    //modifie une variable par un pointeur qui déborde de sa valeur pointée
    int a=3;
    int b=5;
    printf("Adresse de a : %p\n", &a);
    printf("Adresse de b : %p\n", &b);
    int *x=&a;
    printf("Adresse de x : %p\n", x-1);
    *(x-1)=9;

    printf("b : %d\n",b);
    int k=0;
    while(1){
        k++;
        printf ("coucou");
    }
    return 0;
}
