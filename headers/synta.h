#include "Functions.h"
void PROGRAM();
void DECLLIST();
void DECLLIST1();
void DECL();
void FTYPE();
//void VARDECL();
void VARDECLLIST();
void VARDECLLIST1();
void VARVAL();
void VARVALLIST();
void VARID();
void VARIDEXTRA();
void TYPE();
//void FUNDECL();
void PARAMS();
void PARAMSLIST();
void PARAMSLIST1();
void PARAMTYPE();
void PARAMID();
void EXTRA();
void STMT();
void EXPSTMT();
void SCOPESTMT();
void SCOPEDVARDECL();
void LOCALDECLS();
void LOCALDECLS1();
void STMTLIST();
void STMTLIST1();
void CONDSTMT();
void FIF();
void FSIMPLEEXP1();
void ITERSTMT();
void ITERRANGE();
void FSIMPLEEXP();
void FTO();
void FSIMPLEEXP1();
void RETURNSTMT();
void BREAKSTMT();
void READSTMT();
void WRITESTMT();
void LISTID();
void LISTID1();
void EXP();
void SIMPLEEXP();
void SIMPLEEXP1();
void ANDEXP();
void ANDEXP1();
void NOTEXP();
void COMPAREXP();
void COMPAREXTRA();
void COMPAROP();
void SUMEXP();
void SUMEXP1();
void SUMOP();
void MULEXP();
void MULEXP1();
void MULOP();
void FACTOR();
void MUTABLE();
void MUTABLEEXTRA();
void IMMUTABLE();
void CALL();
void ARGS();
void ARGLIST();
void ARGLIST1();
void CONSTANT();

bool c = 0;
struct node *ptr = NULL;

void Symbole_Suiv()
{
    if (ptr == NULL)
        printf("A");
    else
        // printf("%s ", Cour_Token.value);
        ptr = ptr->next;
    prev_token = Cour_Token;
    Cour_Token = ptr->info;
}

void Test_Symbole(Codes_LEX token)
{

    if (Cour_Token.token == token)
    {

        Symbole_Suiv();
    }
    else if (c == 0)
    {

        // printf("%s\n dans la ligne : %d colonne :%d \n", maperror[token].message_erreur, Cour_Token.ligne, Cour_Token.colonne);
    }
}

void PROGRAM()
{
    DECLLIST();
}

void DECLLIST()
{
    DECL();
    DECLLIST1();
}
void DECLLIST1()
{
    DECL();
    DECLLIST1();
}
void DECL()
{
    TYPE();
    FTYPE();
}
void FTYPE()
{
    switch (Cour_Token.token)
    {
    case ID_TOKEN:
        VARDECLLIST();
        Symbole_Suiv();
        Test_Symbole(PV_TOKEN);
        break;
    case IDFCT_TOKEN:
        Symbole_Suiv();
        Test_Symbole(PO_TOKEN);
        PARAMS();
        Test_Symbole(PF_TOKEN);
        STMT();
        break;
    }
}
void VARDECLLIST()
{
    VARVAL();
    VARDECLLIST1();
}

void VARDECLLIST1()
{
    switch (Cour_Token.token)
    {
    case VIR_TOKEN:
        VARVAL();
        Symbole_Suiv();
        VARDECLLIST1();
        break;
    case PV_TOKEN:
        Symbole_Suiv();
        break;
    default:
        //erreur
    }
}

void VARVAL()
{
    VARID();
    VARVALLIST();
}

void VARVALLIST()
{
    switch (Cour_Token.token)
    {
    case AFF_TOKEN:
        Symbole_Suiv();
        SIMPLEEXP();
        break;
    case VIR_TOKEN:
        Symbole_Suiv();
        VARVAL();
        VARDECLLIST1();
        break;
    case PV_TOKEN:
        Symbole_Suiv();
    default:
        //erreur
    }
}
void VARID()
{
    Test_Symbole(ID_TOKEN);
    VARIDEXTRA();
}

void VARIDEXTRA()
{
    switch (Cour_Token.token)
    {
    case CRO_TOKEN: //[
        //Symbole_Suiv();
        Test_Symbole(NUMCONST_TOKEN);
        //Symbole_Suiv();
        Test_Symbole(CRF_TOKEN); //]
        break;
    case PV_TOKEN:
        Symbole_Suiv();
        break;
    case AFF_TOKEN:
        Symbole_Suiv();
        SIMPLEEXP();
        break;
    case VIR_TOKEN:
        Symbole_Suiv();
        VARVAL();
        VARDECLLIST1();
        break;
    default:
        //erreur
    }
}

void TYPE()
{
    switch (Cour_Token.token)
    {
    case INT_TOKEN:
        Symbole_Suiv();
        break;
    case BOOL_TOKEN:
        Symbole_Suiv();
        break;
    case CHAR_TOKEN:
        Symbole_Suiv();
        break;
    default:
        //erreur
    }
}

void PARAMS()
{
    switch (Cour_Token.token)
    {
    case (INT_TOKEN):
        PARAMSLIST();
        break;
    case (BOOL_TOKEN):
        PARAMSLIST();
        break;
    case (CHAR_TOKEN):
        PARAMSLIST();
        break;
    case (PF_TOKEN):
        Symbole_Suiv();
        STMT();
        break;
    default:
        //erreur
    }
}

void PARAMSLIST()
{
    PARAMTYPE();
    PARAMSLIST1();
}

void PARAMSLIST1()
{
    switch (Cour_Token.token)
    {
    case (VIR_TOKEN):
        Symbole_Suiv();
        PARAMTYPE();
        PARAMSLIST1();
        break;
    case (PO_TOKEN):
        Symbole_Suiv();
        STMT();
        break;
    default:
        //erreur
    }
}

void PARAMTYPE()
{
    TYPE();
    PARAMID();
}
void PARAMID()
{
    Test_Symbole(ID_TOKEN);
    EXTRA();
}
void EXTRA()
{
    switch (Cour_Token.token)
    {
    case CRO_TOKEN:
        Symbole_Suiv();
        Test_Symbole(CRF_TOKEN);
        break;
    case VIR_TOKEN:
        Symbole_Suiv();
        PARAMTYPE();
        PARAMSLIST1();
        break;
    default:
        // erreur
    }
}

void STMT()
{
    switch (Cour_Token.token)
    {
    case COLON_TOKEN:
        EXPSTMT();
        break;
    case ACO_TOKEN:
        SCOPESTMT();
        break;
    case IF_TOKEN:
        CONDSTMT();
        break;
    case WHILE_TOKEN:
        ITERSTMT();
        break;
    case FOR_TOKEN:
        ITERSTMT();
        break;
    case RETURN_TOKEN:
        RETURNSTMT();
        break;
    case BREAK_TOKEN:
        BREAKSTMT();
        break;
    case CIN_TOKEN:
        READSTMT();
        break;
    case COUT_TOKEN:
        READSTMT();
        break;
    default:
        //erreur
    }
}

void EXPSTMT()
{
    switch (Cour_Token.token)
    {
    case COLON_TOKEN:
        EXP();
        Test_Symbole(PV_TOKEN);
        break;
    case PV_TOKEN:
        Symbole_Suiv();
        break;
    }
}

void SCOPESTMT()
{
    Test_Symbole(ACO_TOKEN);
    LOCALDECLS();
    STMTLIST();
    Test_Symbole(ACF_TOKEN);
}

void LOCALDECLS()
{
    LOCALDECLS1();
}

void LOCALDECLS1()
{
    switch (Cour_Token.token)
    {
    case INT_TOKEN:
        SCOPEDVARDECL();
        LOCALDECLS1();
        break;
    case BOOL_TOKEN:
        SCOPEDVARDECL();
        LOCALDECLS1();
        break;
    case CHAR_TOKEN:
        SCOPEDVARDECL();
        LOCALDECLS1();
        break;
    case PV_TOKEN:
        Symbole_Suiv();
        break;
    case IF_TOKEN:
        CONDSTMT();
        break;
    case WHILE_TOKEN:
        ITERSTMT();
        break;
    case FOR_TOKEN:
        ITERSTMT();
        break;
    case RETURN_TOKEN:
        RETURNSTMT();
        break;
    case BREAK_TOKEN;
        BREAKSTMT();
        break;
        case CIN_TOKEN:
        READSTMT();
        break;
    case COUT_TOKEN:
        WRITESTMT();
        break;
    case COLON_TOKEN:
        EXP();
        break;
    case NOT_TOKEN:
        NOTEXP();
        break;
    case PO_TOKEN:
    // im here :)
    default:
        //erreur
    }
}

void SCOPEDVARDECL()
{
    TYPE();
    VARDECLLIST();
    Test_Symbole(PV_TOKEN);
}
