#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ATK_SHIELD_CONST 20
#define CURE_CONST 50

void game_over(int a, int b, char c[],char d[]){

    if(a<=0 ||b<=0){
        system("cls");
        printf("%se' perito!\n**********************************Congratulazioni!**********************************\nSEI UN MAGO POTENTISSIMO %s ",c,d);

        exit(0);

    }


} // checks adversaire's pv&mp before the player's turn



int main()
{
    char p1[20], p2[20];
    int vita_p1=100;
    int vita_p2=100;
    int mana_p1=100;
    int mana_p2=100;
    int scelta; int atk;
    bool condizione_game=true;
    bool stupido=true;


    printf("**********************************WIZARDS BRAWL**********************************\n \n");


    printf("Giocatore 1, inserisci il tuo nome:\n");
    fgets(p1,20,stdin);  //c stops to store characters when it detect a space, solution fgets
    printf("Benvenuto %s\n",p1);

    printf("Giocatore 2, inserisci il tuo nome:\n");
    fgets(p2,20,stdin);  //c stops to store characters when it detect a space, solution fgets
    printf("Benvenuto %s\n",p2);

    srand(time(NULL)); //initialization
    int r = rand() % 2; //picks random number between 0 and 1
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~REGOLE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("Vi sfiderete in uno scontro magico. Entrambi avete 100Pv e 100Mp.\n Il primo che arriva a zero punti vita o finira' il mana avra' perso.\n");
    printf("Gestite bene le vostre risorse e cercate la migliore strategia. Che vinca il migliore\n\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    printf("il giocatore che inizia la partita e' pescato in modo casuale.\n\n\n");
    printf("**********************************GAME START**********************************\n\n");


    switch(r)
    {
            case 0:     //player 1 begins
        while(condizione_game){

            game_over(vita_p2,mana_p2,p2,p1);
            if(vita_p1<=0 || mana_p1<=0){//P1
                    system ("cls");
                    printf("%se' perito!\n**********************************Congratulazioni!**********************************\nSEI UN MAGO POTENTISSIMO %s ", p1, p2);
                    exit(0);
                } else {
                    printf("%sTocca a te!\nFagli vedere di che pasta sei fatto!\n", p1);
                    printf("|Pv: %d\n|Mp: %d\n\n", vita_p1, mana_p1);
                    printf("Quale incantesimo vuoi usare?\n");
                    printf("1. PALLA DI FUOCO\n |attacco magico del fuoco, richiede 20 di mana, fa 20 danni all'avversario|\n");
                    printf("2. SCUDO IMPENETRABILE\n |ti protegge dall'attacco dell'avversario, richiede 30 mana. Attenzione, dura solo un turno|\n");
                    printf("3. FONTE DEL MAGO\n |recupera 50 punti vita del giocatore, richiede 40 mana|\n");

                    stupido=true;

                    while(stupido){
                    scanf("%d", &scelta);

                    switch(scelta)
                    {
                        case 1: //offensive magic
                            atk = 20;
                            mana_p1-= atk;
                            vita_p2-= ATK_SHIELD_CONST;
                            system("cls");
                            stupido=false;
                            break;

                        case 2: //defensive magic
                            atk = 30;
                            mana_p1-= atk;
                            vita_p1+= ATK_SHIELD_CONST; //shield from one offensive magic
                            system("cls");
                            stupido=false;
                            break;

                        case 3: //cure
                            atk = 40;
                            mana_p1-= atk;
                            vita_p1+= CURE_CONST; //restores health
                            system("cls");
                            stupido=false;
                            break;

                        default:
                            printf("Errore, valore non accettabile, riprova\n"); //aggiungere un loop per riprovare ad inserire l'attacco
                    }
                }//while interno
            }//else

            game_over(vita_p1,mana_p1,p1,p2);
            if(vita_p2<=0 || mana_p2<=0){ //P2
                    system ("cls");
                    printf("%se' perito!\n**********************************Congratulazioni!**********************************\nSEI UN MAGO POTENTISSIMO %s ", p2, p1);
                    exit(0);
                } else {
                    printf("%sTocca a te!\nFagli vedere di che pasta sei fatto!\n", p2);
                    printf("|Pv: %d\n|Mp: %d\n\n", vita_p2, mana_p2);
                    printf("Quale incantesimo vuoi usare?\n");
                    printf("1. LAMA DI GHIACCIO\n |attacco magico del ghiaccio, richiede 20 di mana, fa 20 danni all'avversario|\n");
                    printf("2. CLONE FANTOCCIO\n |ti protegge dall'attacco dell'avversario, richiede 30 mana. Attenzione, dura solo un turno|\n");
                    printf("3. RIPRESA INSTANTANEA\n |recupera 50 punti vita del giocatore, richiede 40 mana|\n");

                    stupido=true;

                    while(stupido){
                    scanf("%d", &scelta);

                    switch(scelta)
                    {
                        case 1: //offensive magic
                            atk = 20;
                            mana_p2-= atk;
                            vita_p1-= ATK_SHIELD_CONST;
                            system("cls"); //clears screen
                            stupido=false;
                            break;

                        case 2: //defensive magic
                            atk = 30;
                            mana_p2-= atk;
                            vita_p2+= ATK_SHIELD_CONST; //shield from one offensive magic
                            system("cls");
                            stupido=false;
                            break;
                        case 3: //cure
                            atk = 40;
                            mana_p2-= atk;
                            vita_p2+= CURE_CONST; //restores health
                            system("cls");
                            stupido=false;
                            break;

                        default:
                            printf("Errore, valore non accettabile, riprova\n");
                    }
                } //while interno
            }//else
        }//while ripetizione turni
        break; //CASO 0

            case 1:   //player 2 begins
        while(condizione_game){

            game_over(vita_p1,mana_p1,p1,p2);
            if(vita_p2<=0 || mana_p2<=0){ //P2
                    system ("cls");
                    printf("%se' perito!\n**********************************Congratulazioni!**********************************\nSEI UN MAGO POTENTISSIMO %s ", p2, p1);
                    exit(0);
                } else {
                    printf("%sTocca a te!\nFagli vedere di che pasta sei fatto!\n", p2);
                    printf("|Pv: %d\n|Mp: %d\n\n", vita_p2, mana_p2);
                    printf("Quale incantesimo vuoi usare?\n");
                    printf("1. LAMA DI GHIACCIO\n |attacco magico del ghiaccio, richiede 20 di mana, fa 20 danni all'avversario|\n");
                    printf("2. CLONE FANTOCCIO\n |ti protegge dall'attacco dell'avversario, richiede 30 mana. Attenzione, dura solo un turno|\n");
                    printf("3. RIPRESA INSTANTANEA\n |recupera 50 punti vita del giocatore, richiede 40 mana|\n");

                    stupido=true;

                    while(stupido){
                    scanf("%d", &scelta);

                    switch(scelta)
                    {
                        case 1: //offensive magic
                            atk = 20;
                            mana_p2-= atk;
                            vita_p1-= ATK_SHIELD_CONST;
                            system("cls");
                            stupido=false;
                            break;

                        case 2: //defensive magic
                            atk = 30;
                            mana_p2-= atk;
                            vita_p2+= ATK_SHIELD_CONST; //shield from one offensive magic
                            system("cls");
                            stupido=false;
                            break;

                        case 3: //cure
                            atk = 40;
                            mana_p2-= atk;
                            vita_p2+= CURE_CONST; //restores health
                            system("cls");
                            stupido=false;
                            break;

                        default:
                            printf("Errore, valore non accettabile, riprova\n");
                    }
                }//loop
            }//else

            game_over(vita_p2,mana_p2,p2,p1);
            if(vita_p1<=0 || mana_p1<=0){ //P1
                    system ("cls");
                    printf("%se' perito!\n**********************************Congratulazioni!**********************************\nSEI UN MAGO POTENTISSIMO %s ", p1, p2);
                    exit(0);
                } else {
                    printf("%sTocca a te!\nFagli vedere di che pasta sei fatto!\n", p1);
                    printf("|Pv: %d\n|Mp: %d\n\n", vita_p1, mana_p1);
                    printf("Quale incantesimo vuoi usare?\n");
                    printf("1. PALLA DI FUOCO\n |attacco magico del fuoco, richiede 20 di mana, fa 20 danni all'avversario|\n");
                    printf("2. SCUDO IMPENETRABILE\n |ti protegge dall'attacco dell'avversario, richiede 30 mana. Attenzione, dura solo un turno|\n");
                    printf("3. FONTE DEL MAGO\n |recupera 50 punti vita del giocatore, richiede 40 mana|\n");

                    stupido=true;

                    while(stupido){
                    scanf("%d", &scelta);

                    switch(scelta)
                    {
                        case 1: //offensive magic
                            atk = 20;
                            mana_p1-= atk;
                            vita_p2-= ATK_SHIELD_CONST;
                            system("cls");
                            stupido=false;
                            break;

                        case 2: //defensive magic
                            atk = 30;
                            mana_p1-= atk;
                            vita_p1+= ATK_SHIELD_CONST; //shield from one offensive magic
                            system("cls");
                            stupido=false;
                            break;
                        case 3: //cure
                            atk = 40;
                            mana_p1-= atk;
                            vita_p1+= CURE_CONST; //restores health
                            system("cls");
                            stupido=false;
                            break;

                        default:
                            printf("Errore, valore non accettabile, riprova\n");
                    }
                }//while interno
            }//else
        }//while ripetizione turni
        break; //CASO 1

        }//switch final case 0 case 1


    return 0;
}
