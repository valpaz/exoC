#include <stdio.h>
#include <limits.h>

int main()
{
//int x = 3 ;
//long unsigned m=18 ;
//int d = 5;
//int *v = &x;
//int s1=sizeof(m);
//int s2=sizeof(d);
//int s3=sizeof(v);
//printf ("i : %d\n",s1);
//printf ("d : %d\n",s2);
//printf ("v : %d\n",s3);

//int y;
//for (y = 0; y < 6; y++) {
//    int i;
//    for (i = 0; i < 5; i++) {
//        printf("i = %d\n",i);
//        if (i == 3)
//        break;
//    }
//    printf("y = %d\n",y);

//}
//int i = 4;
//int j = 12;
//int k = 5;
//while(i){
//        i-=1;
//        printf ("i : %d\n",i);
//    while(j){
//            j-=1;
//            printf ("j : %d\n",j);
//        while(k){
//                k-=1;
//                printf ("k : %d\n",k);
//                if (i==0 && j == 0 && k==0){

//                goto end;}
//        }
//    }
//}
//end:
//                printf("fini\n");
//                printf ("i : %d\n",i);
//                printf ("j : %d\n",j);
//                printf ("k : %d\n",k);
//    char lettre='a';
//    while (1){


//        if (lettre <='z'){
//            printf ("lettre : %c\n",lettre);}
//        else{break;}

//        lettre++;

//}
//    char Lettre='A';
//    while (1){


//        if (Lettre <='z'){
//            printf ("Lettre : %c\n",Lettre);}
//        else{break;}

//        Lettre++;

//}
//    int i = 23674; int j = -23674;
//    long int k = (1l << 32);
//    double x = 1e-8 + 1000;
//    char c = 'A';
//    char *chaine = "chaine de caracteres";
//    printf("impression de i: \n");
//    printf("%d \t %u \t %o \t %x",i,i,i,i);
//    printf("\impression de j: \n");
//    printf("%d \t %u \t %o \t %x",j,j,j,j);
//    printf("\n%.2f \t %.2e",x,x);
//    printf("\n%.20f \t %.20e",x,x);
//    printf("\nimpression de c: \n");
//    printf("%c \t %d",c,c);
//    printf("\nimpression de chaine: %s\t %.10s \n",chaine,chaine);
//    int EntreJoueur;
//    int nombreOr = 10;

//    scanf ("%d",&EntreJoueur);
//    printf ("%d",EntreJoueur);

    const int nombreOr = 42; // Le nombre d'or à deviner
    int nombreSaisi, passes = 0;

    printf("Bienvenue dans le jeu du nombre d'or!\n");
    printf("Devinez le nombre d'or, il est compris entre 0 et 100.\n");

    printf("Entrez un nombre : ");
    scanf("%d", &nombreSaisi);

    while (nombreSaisi != nombreOr) {
        passes++; // Incrémentation du nombre de tentatives

        if (nombreSaisi > nombreOr) {
            printf("Le nombre d'or est plus petit.\n");
        } else {
            printf("Le nombre d'or est plus grand.\n");
        }

        printf("Entrez un nombre : ");
        scanf("%d", &nombreSaisi);
    }

    printf("Bravo, vous avez trouvé le nombre d'or en %d passes!\n", passes);

    return 0;
}




