// #include "synta.h"
#include "headers/Functions.h"
int main(int *argc, char *argv[])
{

    Analex("file.enx");

    for (int i = 0; i < curseur - 1; i++)
        printf("\n %s %d %d ", mes_err[Error_table[i].code_err].message_erreur, Error_table[i].ligneErreur, Error_table[i].colonneErreur);
    return 0;
}