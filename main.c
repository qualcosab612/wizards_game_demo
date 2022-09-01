#include <stdio.h>
#include <stdlib.h>

int main()
{
    char p1[20], p2[20];
    int vita_p1= 100;
    int vita_p2=100;
    int mana_p1=100;
    int mana_p2=100;
    int scelta; int atk;

    printf("*****************WIZARDS BRAWL*******************\n \n");

    printf("Giocatore 1, inserisci il tuo nome:\n");
    fgets(p1,20,stdin);  //c stops to store characters when it detect a space, solution fgets
    printf("Benvenuto %s",p1);

    printf("\nGiocatore 2, inserisci il tuo nome:\n");
    fgets(p2,20,stdin);  //c stops to store characters when it detect a space, solution fgets
    printf("Benvenuto %s",p2);

    system ("cls");

    //int r = rand() % 1; //picks random number between 0 and 1
    //printf("il giocatore che inizia la partita è pescato in modo casuale.\n -------GAME START-------\n");


    if(vita_p1==0 || mana_p1==0){
        printf("%s died, winner is %s", p1, p2);
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
                printf("error"); //aggiungere un loop per riprovare ad inserire l'attacco
        }
    }
    
    system("cls");

    if(vita_p2==0 || mana_p2==0){
        printf("%s died, winner is %s", p2, p1);
    } else {
        printf("%s turn, what are u using?\n atk:\n 1...\n 2...\n 3...\n", p2);
        scanf("%d", &scelta);

        switch(scelta)
        {
            case 1: //offensive magic
                atk = 20;
                mana_p2-= atk;
                vita_p1-= atk;
                printf("vita: %d\nmana: %d\n", vita_p2, mana_p2);
                break;
            case 2: //defensive magic
                atk = 30;
                mana_p2-= atk;
                vita_p2+= 20; //shield from one offensive magic
                printf("vita: %d\nmana: %d\n", vita_p2, mana_p2);
                break;
            case 3: //cure
                atk = 40;
                mana_p2-= atk;
                vita_p2= 100; //restores health
                printf("vita: %d\nmana: %d\n", vita_p2, mana_p2);
                break;

            default:
                printf("error"); //aggiungere un loop per riprovare ad inserire l'attacco
        }
    }
    
    system("cls");
    //loop per ricominciare il turno
    //chi inizia? dai l'opzione


    return 0;
}
