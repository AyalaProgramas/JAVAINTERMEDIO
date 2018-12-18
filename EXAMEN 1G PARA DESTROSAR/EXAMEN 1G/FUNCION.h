#ifndef FUNCIONESUTN_H_INCLUDED
#define FUNCIONESUTN_H_INCLUDED

int verifyNum (char aNum[]);///NOSE
//void menu (char opcionUno[],char opcionDos[], char opcionTres[], char opcionCuatro[],char opcionCinco[], char opcionSeis[], char opcionSiete[], char opcionOcho[]);
int getOption ( char mensaje[], char errorMensaje[],int botLimit,int topLimit);
int verifyExit(void);///USE-REVISADO
int verifyArrayAlpha (char array[], int botLimit,int topLimit);///SI USE-REVISADO
int verifyAlpha (char aChar[]);///NOSE
int verifyArrayNum (char array[],int botLimit, int topLimit);///SI USE-REVISADO///SI USE-REVISADO
int verifyEmail (char array[],int botLimit, int topLimit);///SI USE-REVISADO
int verifyArrayAlphaNum(char array[],int botLimit, int topLimit);///SI SE USE
int verifyAdress (char array[],int botLimit, int topLimit);
int verifyDate (int dia,int botLimit, int topLimit);///SI USE-REVISADO
int getName (char *array[]);
int getLastName (char *array[]);
int getDNI (char *array[]);
int getId (char *array[]);
int getNick (char *array[]);
int getPass (char *array[]);
int getEmail (char *array[]);
int getId (char *array[]);
int getArrayNum (char *array[]);
int getArrayAlphaNum (char *array[]);
int getAdress (char *array[]);
int getDate(int* dia,int* mes,int* ano);///SI USE-REVISADO
int verifyYorN(void);
int menu_generico(char* mensaje,int desde,int hasta);///SI USE-REVISADO
int es_numerico(char *string);
int es_telefono(char *string);
int es_solo_letra(char *string);
int es_alfa_numerico(char *string);
void get_string(char *mensaje,char *input);
int get_string_letras(char *mensaje,char *input);///SI USE-REVISADO///SI USE-REVISADO///SI USE-REVISADO
int get_string_numero(char *mensaje,char *input);///SI USE-REVISADO///SI USE-REVISADO


#endif
