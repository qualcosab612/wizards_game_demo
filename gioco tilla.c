#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char p1[20], p2[20];
    int vita_p1=100;
    int vita_p2=100;
    int mana_p1=100;
    int mana_p2=100;
    char opzioni;
    int scelta; int atk;
    bool condizione_game=true;

    printf("*****************WIZARDS BRAWL*******************\n \n");

    printf("Giocatore 1, inserisci il tuo nome:\n");
    fgets(p1,20,stdin);  //c stops to store characters when it detect a space, solution fgets
    printf("Benvenuto %s\n",p1);

    printf("Giocatore 2, inserisci il tuo nome:\n");
    fgets(p2,20,stdin);  //c stops to store characters when it detect a space, solution fgets
    printf("Benvenuto %s\n",p2);



    printf ("Benvenuti, %s, %s. Desiderate conoscere le regole del gioco prima di proseguire?\n", p1, p2);

    printf ("Inserisci 'A' per leggere le regole\n ");
    printf ("Inserisci  'B' per proseguire\n");
    scanf ("%c", &opzioni);

    system ("cls");

    switch (opzioni)
     {
            case 'A':
                printf("Ecco le informazioni da sapere.\n");
                printf("il giocatore che inizia la partita è pescato in modo casuale.\n *****************GAME START*****************\n");
                printf("Premi C per iniziare la partita ");
                break;
            case 'B':
                printf("Il gioco inizia ora\n.");
                printf("il giocatore che inizia la partita è pescato in modo casuale.\n *****************GAME START*****************\n");
                printf("Inserisci C per iniziare la partita\n");
                break;
}
opzioni= toupper(getch());
if (scelta=='C'){
        goto home;
}


    int r = rand() % 2; //picks random number between 0 and 1

    system ("cls"); //pulisce lo schermo
home:
    switch(r)
    {
            case 0:     //primo caso inzia giocatore 1
        while(condizione_game){

            if(vita_p1==0 || mana_p1==0){
                    printf("%s died, winner is %s", p1, p2);
                    exit(0);
                } else {
                    printf("%s turn, what are u using?\n atk:\n 1:'Palla di Fuoco'\n 2: 'Sciame di api' \n 3: 'Ricarica mana'\n", p1);
                    scanf("%d", &scelta);

                    switch(scelta)
                    {
                        case 1: //offensive magic
                            atk = 20;
                            mana_p1-= atk;
                            vita_p2-= 20;
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;

                        case 2: //defensive magic
                            atk = 30;
                            mana_p1-= atk;
                            vita_p1+= 20; //shield from one offensive magic
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;
                        case 3: //cure
                            atk = 40;
                            mana_p1-= atk;
                            vita_p1= 100; //restores health
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;

                        default:
                            do {
                                goto home;
                            } while (scelta!=3);
                    }
                }

            if(vita_p2==0 || mana_p2==0){
                    printf("%s died, winner is %s", p2, p1);
                    exit(0);
                } else {
                    printf("%s turn, what are u using?\n atk:\n 1: 'Palla di fuoco \n 2: sciame di api\n 3: ricarica mana\n", p2);
                    scanf("%d", &scelta);

                    switch(scelta)
                    {
                        case 1: //offensive magic
                            atk = 20;
                            mana_p2-= atk;
                            vita_p1-= 20;
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;

                        case 2: //defensive magic
                            atk = 30;
                            mana_p2-= atk;
                            vita_p2+= 20; //shield from one offensive magic
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;
                        case 3: //cure
                            atk = 40;
                            mana_p2-= atk;
                            vita_p2= 100; //restores health
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;

                        default:
                            do {
                                goto home;
                            } while (scelta!=3);
                    }
                }
        }

            case 1:   //secondo caso inizia giocatore 2
        while(condizione_game){

            if(vita_p2==0 || mana_p2==0){
                    printf("%s died, winner is %s", p2, p1);
                    exit(0);
                } else {
                    printf("%s turn, what are u using?\n atk:\n 1...\n 2...\n 3...\n", p2);
                    scanf("%d", &scelta);

                    switch(scelta)
                    {
                        case 1: //offensive magic
                            atk = 20;
                            mana_p2-= atk;
                            vita_p1-= 20;
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;

                        case 2: //defensive magic
                            atk = 30;
                            mana_p2-= atk;
                            vita_p2+= 20; //shield from one offensive magic
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;
                        case 3: //cure
                            atk = 40;
                            mana_p2-= atk;
                            vita_p2= 100; //restores health
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;


                        default:
                            do {
                                goto home;
                            } while (scelta!=3);
                    }
                }


            if(vita_p1==0 || mana_p1==0){
                    printf("%s died, winner is %s", p1, p2);
                    exit(0);
                } else {
                    printf("%s turn, what are u using?\n atk:\n 1...\n 2...\n 3...\n", p1);
                    scanf("%d", &scelta);

                    switch(scelta)
                    {
                        case 1: //offensive magic
                            atk = 20;
                            mana_p1-= atk;
                            vita_p2-= 20;
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;

                        case 2: //defensive magic
                            atk = 30;
                            mana_p1-= atk;
                            vita_p1+= 20; //shield from one offensive magic
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;
                        case 3: //cure
                            atk = 40;
                            mana_p1-= atk;
                            vita_p1= 100; //restores health
                            printf("vita: %d\nmana: %d\n", vita_p1, mana_p1);
                            break;

                        default:
                            do {
                                goto home;
                            } while (scelta!=3);
                    }
                }
               }

        }


    return 0;
}
