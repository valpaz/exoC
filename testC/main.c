#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//int max(int x,int y)
//{
//    if (x>y){
//        return (x);
//    }
//    else{
//        return (y);
//    }
//}

//int min(int x,int y)
//{
//    if (x<y){
//        return (x);
//    }
//    else{
//        return (y);
//    }
//}
//char* ascii(char charactere)
//{
//    int valeurAscii = charactere;
//    return (valeurAscii);
//}
//char Char(int value)
//{
//    return (char)value;
//}
//char* premmajuscule(char* characteres)
//{
//    characteres[0]=characteres[0] - 32;
//    return characteres;
//}
//char* majuscule(char* characteres)
//{
//    for (int i = 0; characteres[i] != '\0'; i++) {
//        if(characteres[i] >= 'a' && characteres[i] <= 'z'){
//            characteres[i]=characteres[i] - 32;}
//    }
//    return characteres;
//}
//char* minuscule(char* characteres)
//    {
//        for (int i = 0; characteres[i] != '\0'; i++)
//        {
//            if(characteres[i] >= 'A' && characteres[i] <= 'Z'){
//                characteres[i]=characteres[i] + 32;}
//        }
//        return characteres;
//    }
//char* inverseTableau(const char* carchar){



//    int longueurTableau=strlen(carchar);
//    int i=0;
//    char tmp[100];
//    for (i=0;i<longueurTableau;i++){

//        tmp[i]=carchar[longueurTableau-1-i];
//}
//    tmp[i] = '\0';
//    printf ("Resultat fonction inverseTableau :%s\n",tmp);
//}

//char* inversePointers(char* carchar){
//    int longueurChaine=strlen(carchar);
//    char* fin = carchar+longueurChaine-1;
//    char* debut = carchar;
//    int i;
//    char tmp;

//    printf ("Carchar %d\n",carchar[0]);
//    for (i=0;i<longueurChaine/2;i++){
//        tmp=*fin;
//        printf ("%c\n",tmp);
//        *fin=*debut;
//        printf ("Changements : %s\n",carchar);
//        *debut=tmp;
//        debut++;
//        fin--;


//}
//printf("Resultat fonction inversePointers :  %s\n",carchar);
//}

//retourneDate(const char *date, int* jour, int* mois, int* annee){

//    *jour=(*(date)-'0')*10+*(date+1)-'0';
//    printf ("jour %d\n",*jour);
//    *mois=(*(date+3)-'0')*10+*(date+4)-'0';
//    printf ("mois %d\n",*mois);
//    *annee=(*(date+6)-'0')*1000+(*(date+7)-'0')*100+(*(date+8)-'0')*10+*(date+9)-'0';
//    printf ("%d\n",*annee);

//}



//int main(int argc, char *argv[])
//{



//    printf("Nom du programme : %s\n", argv[0]);
//    int i;
//    for (i=1;i<argc;i++){
//        printf("Nom de l'argument %d : %s\n",i,argv[i]);
//    }


typedef struct Livre {
    char *titre;
    char *auteur;
    int an;
    struct Livre* pSuivant;
}livre;




void afficher(livre *list){
    int i = 0;
    if (list == NULL) {
        printf("La liste est vide.\n");
    } else {
        while (list != NULL) {
            i++;
            printf("\nLivre %d\n", i);
            printf("Titre : %s\n", (*list).titre);
            printf("Auteur : %s\n", (*list).auteur);
            printf("An : %d\n", (*list).an);
            printf("\n");
            list = (*list).pSuivant;
        }
    }
}

void clean(livre *list){
    livre*tmp;
    while (list != NULL){
            tmp=list;
            list=(*list).pSuivant;
            free((*tmp).titre);
            free((*tmp).auteur);
            free(tmp);
    }

}

livre* initialisation(char *ttitre, char *aateur, int aan){
    livre *nouveau = malloc(sizeof(*nouveau));
    (*nouveau).titre=(char*)malloc(strlen(ttitre)+1);
    (*nouveau).auteur=(char*)malloc(strlen(aateur)+1);
    strcpy((*nouveau).titre, ttitre);
    strcpy((*nouveau).auteur, aateur);
    (*nouveau).an=aan;
    (*nouveau).pSuivant = NULL;
    return nouveau;
}

void ajout(livre *list,char *titreC, char * auteurC, int anI)
{
    livre *nouveau = malloc(sizeof(*nouveau));
    (*nouveau).titre=(char*)malloc(strlen(titreC)+1);
    (*nouveau).auteur=(char*)malloc(strlen(auteurC)+1);

    strcpy((*nouveau).titre, titreC);
    strcpy((*nouveau).auteur, auteurC);
    (*nouveau).an=anI;
    (*nouveau).pSuivant=NULL;
    while ((*list).pSuivant!=NULL){
        list =(*list).pSuivant;
    }

    (*list).pSuivant=nouveau;
}
// && strcmp((*nouveau).titre,(*(*list).pSuivant).titre)>=0
int sauvegarder(livre *list,char *nomFichier){
    FILE *fp = fopen(nomFichier, "w+");
    int i=0;
    while (list != NULL){
        i++;
        char tmp2[30];
        fputs((*list).titre,fp);
        fputs("\n",fp);
        fputs((*list).auteur,fp);
        fputs("\n",fp);
        sprintf(tmp2, "%d\n\n", (*list).an);
        fputs(tmp2,fp);
        list=(*list).pSuivant;
    }
    fclose(fp);
}
livre * recupererFichier(char *nonFichier){
    FILE *fp = fopen(nonFichier, "r");
    char ligne[100];
    livre *list;
    livre *premierElement;
    int i=0;
    while (1) {
        //Arrete quand plus de ligne
        if (fgets(ligne, sizeof(ligne), fp) == NULL){
            break;
            fclose(fp);}
        //saute si ligne "\n"
        fgets(ligne, sizeof(ligne), fp);

        if (ligne[0] == '\n' ){ continue;}

        livre* nouveau = malloc(sizeof(*nouveau));
        (*nouveau).titre=(char*)malloc(strlen(ligne)+1);
        strcpy((*nouveau).titre, strtok(ligne, "\n"));
        fgets(ligne, sizeof(ligne), fp);
        (*nouveau).auteur=(char*)malloc(strlen(ligne)+1);
        strcpy((*nouveau).auteur, strtok(ligne, "\n"));
        fgets(ligne, sizeof(ligne), fp);
        (*nouveau).an=atoi(ligne);
        (*nouveau).pSuivant=NULL;

        if (i<1){ // Seulement le premier tour
            premierElement=nouveau;
            list=nouveau;
            i++;
        }else{
            //indique a nouveau ou pointer
            (*list).pSuivant=nouveau;
            //deplace le pointeur vers le nouveau nouveau
            list=nouveau;

        }




    }
    return premierElement;

    }

int main()
{
FILE *f1 = fopen("вход", "w+");
fputs("вход",f1);
fclose(f1);
FILE *f2 = fopen("вход", "r");
char ligne[30];

fgets(ligne, sizeof(ligne), f2);
printf("Avant %s",ligne);
if (iswlower(ligne[0])) {
    ligne[0] = towupper(ligne[0]);
}
printf("Apres %s",ligne);
return 0;
}
//    livre *premierElement=initialisation("Bonjour","Auteur2",150);
//    ajout(premierElement,"Cela","Auteur4",1815);
//    ajout(premierElement,"Est","Auteur5",1650);
//    ajout(premierElement,"Hello","Auteur1",1815);
//    ajout(premierElement,"Toto","Auteur3",150);

//    afficher(premierElement);
//    char *nomFichier="bibliotheque.txt";
//    sauvegarder(premierElement,nomFichier);
//    clean(premierElement);
//    premierElement=recupererFichier(nomFichier);
//    afficher(premierElement);
//    clean(premierElement);

//struct List *plist=malloc(sizeof(struct List));
//struct Livre *element=malloc(sizeof(struct Livre));
//(*plist).pPremier=element;

//insertion(element, 4);
//insertion(element, 8);
//insertion(element, 15);
//afficherListe(element);



/*
struct Livre {
    char titre[100];
    char auteur[100];
    int an;
    struct Livre* pSuivant;
};
struct List{
    struct Livre *pPremier;
};

struct List *plist=malloc(sizeof(struct List));
struct Livre *element=malloc(sizeof(struct Livre));
(*plist).pPremier=element;

strcpy((*element).auteur, "Paulo Coelho");
strcpy((*element).titre, "L'alchimiste");
(*element).an=2015;

struct Livre *element2=malloc(sizeof(struct Livre));
(*element).pSuivant=element2;


strcpy((*element2).auteur, "Marc Aurèle");
strcpy((*element2).titre, "Pensées pour moi-même");
(*element2).an=150;
(*element2).pSuivant=NULL;
}
*/

//struct livre{
//char auteur[40];
//char titre[40];
//short an;
//};
//struct livre liv[5]={{"Paulo Coelho","L'alchimiste",2015},
//{"Marc Aurèle","Pensées pour moi-même",150},
//{"Blaise Pascal","Pensées",1650},
//{"Honoré de balzac","Le pere Goriot",1815},
//{"David Gibbins","L'épée d'attila",2015}};
//struct livre *px = liv;
//int i;
//for (i = 0; i < 5; i++) {
//    printf("%s\n",(*px).auteur);
//    printf("%s\n",px->auteur);// ou
//px++;}

//    union MonUnion
//    {
//    double double1;
//    int int1;
//    char char1;

//    };
//    union MonUnion unio;
//    unio.int1 = 66;
//    printf("int1 : %d\n", unio.int1);
//    printf("char1 s'affiche sous la forme 66 de int1 cad 'B' : %c\n", unio.char1);

//    unio.char1 = 'c';
//    printf("char1 : %c\n", unio.char1);
//    printf("int1 s'affiche sous la forme 'c' de char1 cad 99 : %d\n", unio.int1);

//    unio.double1 = 345.123434354;
//    printf("char1 ne s'affiche plus bien : %c\n", unio.char1);
//    printf("int1 non plus : %d\n", unio.int1);

//    printf("double1 fait 8 octets donc l'union fait 8 : %d\n", sizeof(unio));



//    union MonUnion1
//    {
//    struct {
//    unsigned bit1 : 1;
//    unsigned bit4 : 4;
//    unsigned bit3 : 3;
//    }b8;
//    int octet1;
//    };
//    union MonUnion1 unio2;
//    unio2.octet1=0;
//    printf("octet1 s'affiche bien : %d\n", unio2.octet1);
//    printf("b8.bit1 affiche le bit faible de octet1 : %d\n", unio2.b8.bit1);
//    unio2.octet1=1;
//    printf("octet1 s'affiche bien : %d\n", unio2.octet1);
//    printf("b8.bit1 affiche le bit faible de octet1 : %d\n", unio2.b8.bit1);
//    unio2.octet1=2;
//    printf("octet1 s'affiche bien : %d\n", unio2.octet1);
//    printf("b8.bit1 affiche le bit faible de octet1 : %d\n", unio2.b8.bit1);

//    typedef struct _noalign {
//    char c; /* 1 octet */
//    double d; /* 8 octets */
//    int i; /* 4 octets */
//    char c2[3]; /* 3 octets */
//    }__attribute__((packed))noalign; /* 24 octets car padding */
//    typedef struct _align{
//    double d; /* 8 octets */
//    int i; /* 4 octets */
//    char c2[3] ;/* 3 octets */
//    char c; /* 1 octet */
//    }align; /* 16 octets */

//    printf ("taille : %d\n",sizeof(noalign));
//    printf ("taille : %d\n",sizeof(align));
//    char octet16[]="abcdefghijklmno";
//    char octet1 = octet16[0];
//    char octet2A9[8];
//    char octet9A13[4];
//    char octet13A16[3];
//    for (int i = 1; i < 9; i++) {
//            octet2A9[i] = octet16[i];
//        }
//    for (int i = 9; i < 13; i++) {
//            octet9A13[i] = octet16[i];
//        }
//    for (int i = 13; i < 16; i++) {
//            octet13A16[i] = octet16[i];
//        }
//    printf("Taille : %d\n",sizeof(octet16));
//    printf("Taille : %d\n",sizeof(octet1));
//    printf("Taille : %d\n",sizeof(octet2A9));
//    printf("Taille : %d\n",sizeof(octet9A13));
//    printf("Taille : %d\n",sizeof(octet13A16));
//    noalign test;
//    noalign *px=&test;
//    printf("Taille de c : %d\n",px->c);
//    printf("Taille de d : %d\n",px->d);
//    printf("Taille de i : %d\n",px->i);




//    enum jours {lundi=1,mardi,mercredi,jeudi,vendredi,
//    samedi,dimanche};
//    printf ("lundi est le jour %d\n", lundi);
//    printf ("mardi est le jour %d\n", mardi);
//    printf ("mercredi est le jour %d\n", mercredi);
//    printf ("jeudi est le jour %d\n", jeudi);
//    printf ("vendredi est le jour %d\n", vendredi);
//    printf ("samedi est le jour %d\n", samedi);
//    printf ("dimanche est le jour %d\n", dimanche);

//char *date="23/04/2014";
//int jour;
//int mois;
//int annee;
//retourneDate(date, &jour,&mois,&annee);
//printf("Jour : %d\n", jour);
//printf("Mois : %d\n", mois);
//printf("Année : %d\n", annee);


//printf (" variableGlobal : %p\n",&variableGlobal);
//printf (" tableauGlobal : %p\n",&tableauGlobal);
//char *chaine="toto";
//printf("Chaine : %p\n",chaine);
//printf("&Chaine : %p\n",&chaine);
//int variableLocal = 5;
//printf (" variableLocal : %p\n",&variableLocal);
//char tableauLocal[]="au revoir ";
//printf (" tableauLocal : %p\n",&tableauLocal);
//const int constanteLocal = 3;
//printf (" constanteLocal : %p\n",&constanteLocal);
//static int variableStatic = 3;
//printf (" variableStatic : %p\n",&variableStatic);

//    char tableau[]="bonjour";
//    inverseTableau(tableau);
//    char tableau2[]="bonjour";
//    inversePointers( tableau2);

//    int num1=10;
//    int num2=20;
//    int result1 = max(num1,num2);
//    printf("Plus grand des deux nombres est %d\n", result1);
//    int result2 = min(num1,num2);
//    printf("Plus petit des deux nombres est %d\n", result2);
//    char c='d';
//    int result3 = ascii(c);
//    printf("le code ASCII est %d\n", result3);
//    int num3 = 115;
//    char result4 = Char(num3);
//    printf("le caractere associé au numéro %d est %c\n",num3, result4);
//    char toto[]="toto";
//    char* result5 = premmajuscule(toto);
//    printf("Avec la majuscule : %s\n", result5);
//    char papa[]="papa";
//    char* result6 = majuscule(papa);
//    printf("Avec le mot en majuscule : %s\n", result6);
//    char mama[]="MAMA";
//    char* result7 = minuscule(mama);
//    printf("Avec le mot en minuscule : %s\n", result7);

//    int x[5]={1,2,4,8,16};
//    int *p=&x[0];
//    int *q=x;
//    printf("%d %d %d %d %d %d\n",x[0],*p,x[1],*(p+1),x[2],*(p+2));

//    char chain1[]="papa";
//    char chain2[]="maman";
//    printf ("chain1 est %s\n",chain1);
//    printf ("chain2 est %s\n",chain2);
//    int resultat = strcmp (chain1,chain2);
//    printf ("%d\n",resultat);
//    if (resultat>0){
//        char chaintmp1[100];
//        strcpy(chaintmp1, chain1);
//        char chaintmp2[100];
//        strcpy(chaintmp2, chain2);
//        strcpy(chain1, chaintmp2);
//        strcpy(chain2, chaintmp1);
//        printf ("la chaine 1 est a présent inférieur a la chaine 2\n");
//        printf ("chain1 devient %s\n",chain1);
//        printf ("chain2 devient %s",chain2);
//        char lettre = chain2[0];
//        for (lettre; lettre <= 'z'; lettre++) {
//            lettre++;
//            chain2[0] = lettre;
//            printf ("chain1 %s\n",chain2);
//            int resultat = strcmp (chain1,chain2);
//            printf ("resultat %d\n",resultat);
//            if (resultat<0){
//                printf ("la chaine 1 est a présent inférieur a la chaine 2\n");
//                printf ("chain1 %s",chain1);
//                printf ("chain2 %s",chain2);
//                break;
//            }
//        }


//}
