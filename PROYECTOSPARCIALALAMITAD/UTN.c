
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



float getFloat(char mensaje[])
{
    float aux;
    printf("%s",mensaje);
    scanf("%f",&aux);
    return aux;
}

int getInt(char mensaje[])
{
    int aux;
    printf("%s",mensaje);
    scanf("%d",&aux);
    return aux;
}

char getChar(char mensaje[])
{
    char aux;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&aux);
    return aux;
}

int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

int esNumerico(char strin[])
{
    int i=0;
    while(strin[i]!='\0')
    {
        if(strin[i]<'0'||strin[i]>'9')
            return 0;
        i++;
    }
    return 1;
}

int esSololetra(char strin[])
{
    int i=0;
    while(strin[i]!='\0')
    {
        if((strin[i]!=' ')&&(strin[i]<'a'||strin[i]>'z')&&(strin[i]<'A'||strin[i]>'Z'))
            return 0;
        i++;

    }

    return 1;
}

int esAlfaNumerico(char strin[])
{
    int i=0;
    while(strin[i]!='\0')
    {
        if((strin[i]!=' ')&&(strin[i]<'a'||strin[i]>'z')&&(strin[i]<'A'||strin[i]>'Z')&&(strin[i]<'0'||strin[i]>'9'))
            return 0;
        i++;
    }
    return 1;
}

int esTelefono(char strin[])
{
    int i=0;
    int contadordeguiones=0;
    while(strin!='\0')
    {
        if((strin[i]!=' ')&&(strin[i]<'0'||strin[i]>'9')&&(strin[i]!='-'))
            return 0;
        if((strin[i]=='-'))
            contadordeguiones++;
        i++;
    }
    if(contadordeguiones==1)
    {
        return 1;
    }
    return 0;
}


void getString(char mensaje[],char input[])
{
    printf(mensaje);
    fflush(stdin);
    scanf("%s",input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSololetra(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }

    return 0;
}

int getAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    getAlfaNumerico(mensaje,aux);
    if(esAlfaNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
//void inicializarArrayInt(int array[],int cantidad_de_elementos,int valor)
//{
//    int i;
//    for(i=0;i<cantidad_de_elementos;i++)
//    {
//        array[i]=valor;
//    }
//}
//
//int buscarPrimeraOcurrencia(int array[],int cantidad_de_elemento,int valor)
//{
//    int i;
//    for(i=0;i<cantidad_de_elemento;i++)
//    {
//        if(array[i]==valor)
//        {
//            return i;
//        }
//    }
//    return -1;
//}





int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];

    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getValidInt(char requestMessage[],char errorMessage[],int lowLimit,int hiLimit)
{
    char auxStr[256];
    int auxInt;
    while(1)
    {
        if(!getStringNumeros(requestMessage,auxStr))
        {
            printf("%s\n",errorMessage);
            continue;
        }
        auxInt=atoi(auxStr);
        if(auxInt<lowLimit||auxInt>hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }

        break;
    }

    return auxInt;

}


float getValidFloat(char requestMessage[],char errorMessage[],int lowLimit,int hiLimit)
{
    char auxStr[256];
    float auxFloat;
    while(1)
    {


        if(!getStringNumerosFlotantes(requestMessage,auxStr))
        {
            printf("%s\n",errorMessage);
            continue;
        }
        auxFloat=atof(auxStr);
        if(auxFloat<lowLimit||auxFloat>hiLimit)
        {
            printf ("El numero del debe ser mayor a %d y menor a %d\n",lowLimit,hiLimit);
            continue;
        }

        break;
    }

    return auxFloat;

}



void cleanStdin(void)
{
    int c;
    do
    {
        c=getchar();
    }while(c!='\n'&&c!=EOF);

}

void getValidString(char requestMessage[],char errorMessage,char input[])
{
    while(1)
    {
        if(!getStringLetras(requestMessage,input))
        {
            printf("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }
}

void getValidAlfaNumerico(char requestMessage[],char errorMessage,char input[] )
{
    while(1)
    {
        if(!getAlfaNumerico(requestMessage,input))
        {
            printf("%s\n",errorMessage);
            continue;
        }
        cleanStdin();
        break;
    }
}

int verifyDosOption(char mensaje[])
{
    int retorno=-1;
    char aux;
    char brick='x';
    while(brick=='x')
    {
        fflush(stdin);
        printf("%s\n",mensaje);
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
