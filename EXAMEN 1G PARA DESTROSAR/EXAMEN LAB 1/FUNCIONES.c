


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#ifndef FUNCIONESUTN_H_INCLUDED
#define FUNCIONESUTN_H_INCLUDED
#include "FUNCIONES.h"
#endif // FUNCIONESUTN_H_INCLUDED
/////** \brief Imprime el Menu
// *
// * \param char opcionUno  Accion de la opcionUno.
// * \param char opcionDos  Accion de la opcionDos.
// * \param char opcionTres  Accion de la opcionTres.
// * \param char opcionCuatro  Accion de la opcionCuatro.
// * \param char opcionCinco  Accion de la opcionCinco.
// * \param char opcionSeis  Accion de la opcionSesis.
// * \param char opcionSiete  Accion de la opcionSiete.
// * \param char opcionOcho  Accion de la opcionOcho.
// * \param char opcionNueve  Accion de la opcionNueve.
// * \return
// *
// */
//void menu (char opcionUno[],char opcionDos[], char opcionTres[], char opcionCuatro[],char opcionCinco[], char opcionSeis[], char opcionSiete[], char opcionOcho[])
//{
//    system("cls");
//    printf("MENU DE OPCIONES\n\n");
//    puts(opcionUno);
//    puts(opcionDos);
//    puts(opcionTres);
//    puts(opcionCuatro);
//    puts(opcionCinco);
//    puts(opcionSeis);
//    puts(opcionSiete);
//    puts(opcionOcho);
//    printf("\n");
//}


/** \brief Verifica si se desea salir del programa.
 *
 * \return -1 si la respuesta es No, 0 si la respuesta es Si.
 *
 */
int verifyExit(void)
{
    int retorno=-1;
    char aux;
    char brick='x';
    while(brick=='x')
    {
        fflush(stdin);
        printf("Seguro desea salir? [S/N]\n");
        aux=getch();
        if(tolower(aux)=='s')
        {
            retorno=0;
            brick='y';
        }
        else if(tolower(aux)=='n')
            brick='y';
    }
    return retorno;
}

/** \brief Verifica que un array de char solo contenga letras.
 *
 * \param array Array de char a verificar.
 * \param topLimit Cantidad maxima de Char que puede tener el array.
 * \return 0 si salio todo Ok, -1 si se encontro algun error.
 *
 */
int verifyArrayAlpha (char array[], int botLimit,int topLimit)
{
    int retorno=0;
    int i;
    int cantChar=strlen(array);
    if (cantChar<topLimit&&cantChar>botLimit)
    {
        for(i=0;i<cantChar;i++)
        {
            if((array[i] != ' ') && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z'))
            {
                retorno=-1;
                break;
            }
        }
    }
    else
        retorno=-1;
    return retorno;
}

/** \brief Verifica que un array solo contenga un char y del tipo letra.
 *
 * \param aChar Array de char a verificar.
 * \return 0 si salio todo Ok, -1 si se encontro algun error.
 *
 */
int verifyAlpha (char aChar[])
{
    int retorno=0;
    aChar[0]=tolower(aChar[0]);
    if(aChar[0] < 'a' || aChar[0] > 'z'|| strlen(aChar)!= 1)
        retorno=-1;
    return retorno;
}

/** \brief Verifica que un array de char solo contenga numeros.
 *
 * \param array Array de char a verificar.
 * \param topLimit Cantidad maxima de Char que puede tener el array.
 * \return 0 si salio todo Ok, -1 si se encontro algun error.
 *
 */
int verifyArrayNum (char array[],int botLimit, int topLimit)
{
    int retorno=0;
    int cantChar=strlen(array);
    if (cantChar<=topLimit&&cantChar>=botLimit)
    {
        for(int i=0;i<cantChar;i++)
        {
           if(array[i] < '0' || array[i] > '9')
            {
                retorno=-1;
                break;
            }
        }
    }
    else
        retorno=-1;
    return retorno;
}

/** \brief Verifica que un array solo contenga un char y del tipo numerico.
 *
 * \param aChar Array de char a verificar.
 * \return 0 si salio todo Ok, -1 si se encontro algun error.
 *
 */
int verifyNum (char aNum[])
{
    int retorno=0;
    if(aNum[0] < '0' || aNum[0] > '9'|| strlen(aNum)!= 1)
        retorno=-1;
    return retorno;
}

/** \brief Verifica que un array de char solo contenga letras, numeros y ( " @ _ - . " ).
 *
 * \param array Array de char a verificar.
 * \param topLimit Cantidad maxima de Char que puede tener el array.
 * \return 0 si salio todo Ok, -1 si se encontro algun error.
 *
 */
int verifyEmail (char array[],int botLimit, int topLimit)
{
    int retorno=0;
    int cantChar=strlen(array);
    if (cantChar <= topLimit && cantChar>=botLimit )
    {
        for(int i=0;i<cantChar;i++)
        {
            if((array[i] != '.') && (array[i] != '@') && (array[i] != '_')&&(array[i] != '-')&& (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z')&&(array[i] < '0' || array[i] > '9'))
            {
                printf("\nCantidad Char: %d",cantChar);
                retorno=-1;
                break;
            }
        }
    }
    else
    {
        retorno=-1;
        printf("\nCantidad Char: %d",cantChar);
    }

    return retorno;
}

/** \brief Verifica que el array solo contenga letras y/o numeros.
 *
 * \param array Array de char a verificar.
 * \param topLimit Cantidad maxima de Char que puede tener el array.
 * \return 0 si salio todo Ok, -1 si se encontro algun error.
 *
 */
int verifyArrayAlphaNum(char array[],int botLimit, int topLimit)
{
    int retorno=0;
    int cantChar=strlen(array);
    if (cantChar<topLimit&&cantChar>botLimit)
    {
        for(int i=0;i<cantChar;i++)
        {
            if((array[i] != ' ') && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z')&&(array[i] < '0' || array[i] > '9'))
            {
                retorno=-1;
                break;
            }
        }
    }
    else
        retorno=-1;
    return retorno;
}

/** \brief Verifica que el Array solo contenga letras y/o numeros y/o " . ".
 *
 * \param array Array de char a verificar.
 * \param topLimit Cantidad maxima de Char que puede tener el array.
 * \return 0 si salio todo Ok, -1 si se encontro algun error.
 *
 */
int verifyAdress (char array[],int botLimit, int topLimit)
{
    int retorno=0;
    int cantChar=strlen(array);
    if (cantChar<topLimit&&cantChar>botLimit)
    {
        for(int i=0;i<cantChar;i++)
        {
            if((array[i] != '.') && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z')&&(array[i] < '0' || array[i] > '9'))
            {
                retorno=-1;
                break;
            }
        }
    }
    else
        retorno=-1;
    return retorno;
}

/** \brief Solicita el ingreso de una opcion y verifica que cumpla con todos los requisitos.
 *
 * \param char mensaje Mensaje que solicita el ingreso.
 * \param char errorMensaje Mensaje que indica el error.
 * \param botLimit Limite minimo para el valor del ingreso.
 * \param topLimit Limite maximo para el valor del ingreso.
 * \return El valor de la opcion si salio todo Ok, -1 si surgio algun error.
 *
 */
int getOption ( char mensaje[], char errorMensaje[],int botLimit,int topLimit)
{
    int retorno=-1;
    char auxiliar[255];
    puts(mensaje);
    gets(auxiliar);
    if (verifyNum(auxiliar)==0&&atoi(auxiliar)>=botLimit&&atoi(auxiliar)<=topLimit)
        retorno=atoi(auxiliar);
    else
        puts(errorMensaje);
    return retorno;
}
/** \brief Solicita el ingreso de un nombre, lo verifica y lo devuelve.
 *
 * \param char* array Donde se va a guardar la informacion ya verificada.
 * \return 0 si salio todo Ok. -1 Si surgio algun error.
 *
 */
int getName (char *array)
{

    int retorno=-1;
    char auxiliar[255];
    printf("Ingrese su nombre: ");
    gets(auxiliar);
    if(verifyArrayAlpha(auxiliar,1,10)==0)
    {
        strcpy(array,auxiliar);
        retorno=0;
    }
    return retorno;
}

/** \brief Solicita el ingreso de un Apellido, lo verifica y lo devuelve.
 *
 * \param char* array Donde se va a guardar la informacion ya verificada.
 * \return 0 si salio todo Ok. -1 Si surgio algun error.
 *
 */
int getLastName (char *array[])
{
    int retorno=-1;
    char auxiliar[255];
    printf("Ingrese su apellido: ");
    gets(auxiliar);
    if(verifyArrayAlpha(auxiliar,1,10)==0)
    {
        strcpy(array,auxiliar);
        retorno=0;
    }
    return retorno;
}

/** \brief Solicita el ingreso de un Email, lo verifica y lo devuelve.
 *
 * \param char* array Donde se va a guardar la informacion ya verificada.
 * \return 0 si salio todo Ok. -1 Si surgio algun error.
 *
 */
int getEmail (char *array[])
{
    int retorno=-1;
    char auxiliar[255];
    printf("Ingrese su email: ");
    gets(auxiliar);
    if(verifyEmail(auxiliar,1,30)==0)
    {
        strcpy(array,auxiliar);
        retorno=0;
    }
    return retorno;
}

/** \brief Solicita el ingreso de un DNI, lo verifica y lo devuelve.
 *
 * \param char* array Donde se va a guardar la informacion ya verificada.
 * \return 0 si salio todo Ok. -1 Si surgio algun error.
 *
 */
int getDNI (char *array[])
{
    int retorno=-1;
    char auxiliar[255];
    printf("Ingrese su dni: ");
    gets(auxiliar);
    if(verifyArrayNum(auxiliar,1,10)==0)
    {
        strcpy(array,auxiliar);
        retorno=0;
    }
    return retorno;
}


/** \brief Solicita el ingreso de un nick, lo verifica y lo devuelve..
 *
 * \param char* array Donde se va a guardar la informacion ya verificada.
 * \return 0 si salio todo Ok. -1 Si surgio algun error.
 *
 */
int getNick (char *array[])
{
    int retorno=-1;
    char auxiliar[255];
    printf("Ingrese su nick: ");
    gets(auxiliar);
    if(verifyEmail(auxiliar,1,10)==0)
    {
        strcpy(array,auxiliar);
        retorno=0;
    }

    return retorno;
}

/** \brief Solicita el ingreso de un Array Alfacnumerico, lo verifica y lo devuelve.
 *
 * \param char* array Donde se va a guardar la informacion ya verificada.
 * \return 0 si salio todo Ok. -1 Si surgio algun error.
 *
 */
int getArrayAlphaNum (char *array[])
{
    int retorno=-1;
    char auxiliar[255];
    printf("Ingrese su alphanumeric: ");
    gets(auxiliar);
    if(verifyArrayAlphaNum(auxiliar,1,10)==0)
    {
        strcpy(array,auxiliar);
        retorno=0;
    }
    return retorno;
}

/** \brief Solicita el ingreso de una direccion, la verifica y la devuelve.
 *
 * \param char* array Donde se va a guardar la informacion ya verificada.
 * \return 0 si salio todo Ok. -1 Si surgio algun error.
 *
 */
int getAdress (char *array[])
{
    int retorno=-1;
    char auxiliar[255];
    printf("Ingrese su direccion: ");
    gets(auxiliar);
    if(verifyAdress(auxiliar,1,10)==0)
    {
        strcpy(array,auxiliar);
        retorno=0;
    }
    return retorno;
}

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int getArrayNum (char *array[])
{
    int retorno=-1;
    char auxiliar[255];
    printf("Ingrese su numeric: ");
    gets(auxiliar);
    if(verifyArrayNum(auxiliar,1,9999)==0)
    {
        strcpy(array,auxiliar);
        retorno=0;
    }
    return retorno;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int getId (char *array[])
{
    int retorno=-1;
    char auxiliar[255];
    printf("Ingrese su ID: ");
    gets(auxiliar);
    if(verifyArrayNum(auxiliar,1,4)==0)
    {
        strcpy(array,auxiliar);
        retorno=0;
    }
    return retorno;
}
/** \brief
 * \param
 * \param
 * \return
 */

int getPass (char *array[])
{
    int retorno=-1;
    char auxiliar[255];
    printf("Ingrese su password: ");
    gets(auxiliar);
    if(verifyEmail(auxiliar,1,10)==0)
    {
        strcpy(array,auxiliar);
        retorno=0;
    }
    return retorno;
}
/** \brief se ingresa los datos de dia, mes y anio
 * \param dia
 * \param mes
 * \param ano
 * \return
 *
 */

int getDate(int* dia,int* mes,int* ano)
{
    int retorno=-1;
    int flagDia=0;
    int flagMes=0;
    int flagAno=0;
    int flagFull=0;
    char auxDia[255];
    char auxMes[255];
    char auxAno[255];
    while(flagFull==0)
    {
        printf("Ingrese fecha de nacimiento.\n");
        fflush(stdin);
        while(flagDia==0)
        {
            printf("Dia: ");
            gets(auxDia);
            if(verifyArrayNum(auxDia,1,2)==0)
            {
                if(verifyDate(atoi(auxDia),1,31)==0)
                    flagDia=1;
                else
                    printf("Error. reintente\n");
            }
        }
        while(flagMes==0)
        {
            printf("Mes: ");
            gets(auxMes);
            if(verifyArrayNum(auxMes,1,2)==0)
            {
                if(verifyDate(atoi(auxMes),1,12)==0)
                    flagMes=1;
                else
                    printf("Error. reintente\n");
            }
        }
        while(flagAno==0)
        {
            printf("Ano: ");
            gets(auxAno);
            if(verifyArrayNum(auxAno,4,4)==0)
            {
                if(verifyDate(atoi(auxAno),1000,2020)==0)
                {
                    flagAno=1;
                    flagFull=1;
                }

                else
                    printf("Error. reintente\n");
            }
        }
    }
    if(flagFull)
    {
        *dia=atoi(auxDia);
        *mes=atoi(auxMes);
        *ano=atoi(auxAno);
        retorno=0;
    }
    return retorno;
}
/** \brief verifica el si el dato dia se enencuentra entre los limites
 * \param dia es valor para verificarlo
 * \param botLimit es el valor minimo para vericar
 * \param topLimit es el valor maximo para vericar
 * \return retorna -1 si se pasa de los limites o 0 si se encuentra entre los limites
 */

int verifyDate (int dia,int botLimit, int topLimit)
{
    int retorno=-1;
    if(dia>=botLimit&&dia<=topLimit)
        retorno=0;

    return retorno;
}


/** \brief Verifica si se desea salir del programa.
 *
 * \return -1 si la respuesta es No, 0 si la respuesta es Si.
 *
 */
int verifyYorN(void)
{
    int retorno=-1;
    char aux;
    char brick='x';
    while(brick=='x')
    {
        fflush(stdin);
        printf("Esta seguro ? [S/N]\n");
        aux=getch();
        if(tolower(aux)=='s')
        {
            retorno=0;
            brick='y';
        }
        else if(tolower(aux)=='n')
            brick='y';
    }
    return retorno;
}





/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int menu_generico(char* mensaje,int desde,int hasta)
{
    int opcion;
    int flag=0;
    do
    {
        if(flag)
        {
            system("cls");
            printf("ERROR, INGRESE UNA OPCION VALIDA\n");
        }

        puts(mensaje);
        scanf("%d",&opcion);
        flag=1;
    }while(opcion<desde||opcion>hasta);

    return opcion;
}








/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int es_numerico(char *string)
{
    int i=0;
    while(string[i]!='\0')
    {
        if((string[i]!='.')&&(string[i]<'0'||string[i]>'9'))
            return 0;
        i++;
    }
    return 1;
}
/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */

int es_telefono(char *string)
{
    int i=0;
    int cont_guiones=0;
    while(string[i]!='\0')
    {
        if((string[i]!=' ')&&(string[i]!='-')&&(string[i]<'0'||string[i]>'9'))
            return 0;
        if(string[i]=='-')
            cont_guiones++;
        i++;
    }
    if(cont_guiones==1)
    {
        return 1;
    }
    return 0;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */

int es_solo_letra(char *string)
{
        int i=0;
        while(string[i]!='\0')
        {
            if((string[i]!=' ')&&(string[i]<'a'||string[i]>'z')&&(string[i]<'A'|| string[i]>'Z'))
            {
                return 0;
            }

            i++;
        }
        return 1;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */

int es_alfa_numerico(char *string)
{
    int i;

    while(string[i]!='\0')
    {
        if((string[i]!=' ')&&(string[i]<'0'||string[i]>'9')&&(string[i]<'a'||string[i]>'z')&&(string[i]<'A'||string[i]>'Z'))
            return 0;
        i++;
    }
    return 1;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */

void get_string(char *mensaje,char *input)
{
    puts(mensaje);
    fflush(stdin);
    scanf("%s",input);

}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */

int get_string_letras(char *mensaje,char *input)
{
    char aux[50];

    get_string(mensaje,aux);
    if(es_solo_letra(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */

int get_string_numero(char *mensaje,char *input)
{
    char aux[20];
    get_string(mensaje,aux);
    if(es_numerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getDatehora(int* segundo,int* minutos,int* hora)
{
    int retorno=-1;
    int flagseg=0;
    int flagmin=0;
    int flaghora=0;
    int flagFull=0;
    char auxseg[255];
    char auxmin[255];
    char auxhora[255];
    while(flagFull==0)
    {
        printf("Ingrese hora de vuelo.\n");
        fflush(stdin);
        while(flagseg==0)
        {
            printf("segundos: ");
            gets(auxseg);
            if(verifyArrayNum(auxseg,1,2)==0)
            {
                if(verifyDate(atoi(auxseg),0,60)==0)
                    flagseg=1;
                else
                    printf("Error. reintente\n");
            }
        }
        while(flagmin==0)
        {
            printf("minutos: ");
            gets(auxmin);
            if(verifyArrayNum(auxmin,1,2)==0)
            {
                if(verifyDate(atoi(auxmin),0,60)==0)
                    flagmin=1;
                else
                    printf("Error. reintente\n");
            }
        }
        while(flaghora==0)
        {
            printf("hora: ");
            gets(auxhora);
            if(verifyArrayNum(auxhora,1,2)==0)
            {
                if(verifyDate(atoi(auxhora),0,24)==0)
                {
                    flaghora=1;
                    flagFull=1;
                }

                else
                    printf("Error. reintente\n");
            }
        }
    }
    if(flagFull)
    {
        *segundo=atoi(auxseg);
        *minutos=atoi(auxmin);
        *hora=atoi(auxhora);
        retorno=0;
    }
    return retorno;
}
