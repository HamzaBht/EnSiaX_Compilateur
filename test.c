#include "headers/synta.h"

int main(int *argc, char *argv[])
{

    Analex("file.enx");

    for (int i = 0; i < curseur - 1; i++)
        printf("\n %s %d %d ", mes_err[Error_table[i].code_err].message_erreur, Error_table[i].ligneErreur, Error_table[i].colonneErreur);
    printf("\n \n \n");
    PROGRAM();
    if (Cour_Token.token == FIN_TOKEN)
        printf("YES");
    else
        printf("NO");
}