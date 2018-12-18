#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FUNCION.h"
#include <ctype.h>
#include "LIBRERIA.h"
#define QTY 20



int menu_generico(char *mensaje,int desde,int hasta);

int main()
{
    /**lista*/
    e_nacion vector_naciones[200];
    e_director vector_directores[500];
    /*******/

    e_video vector_pelicula[1000];
    e_relacion vector_relacion[1000];

    e_cant_director vector_cantdirec[1000];
    e_cant_pelicula vector_cantpeli[1000];

    int opcion;
    int continuar=1;
    int empty;
    int i;
    int flag;
    int flagD;







    initStruct(vector_pelicula,vector_directores,vector_naciones,vector_relacion,QTY);



    e_nacion nac1={1,"argentina",'F'};
    e_nacion nac2={2,"brasil",'F'};
    e_nacion nac3={3,"cuba",'F'};
    e_nacion nac4={4,"mexico",'F'};
    e_nacion nac5={5,"irak",'F'};
    e_nacion nac6={6,"israel",'F'};
    e_nacion nac7={7,"rusia",'F'};
    e_nacion nac8={8,"china",'F'};
    e_nacion nac9={9,"uruguay",'F'};
    e_nacion nac10={10,"japon",'F'};
    vector_naciones[0]=nac1;
    vector_naciones[1]=nac2;
    vector_naciones[2]=nac3;
     vector_naciones[3]=nac4;
     vector_naciones[4]=nac5;
     vector_naciones[5]=nac6;
     vector_naciones[6]=nac7;
     vector_naciones[7]=nac8;
     vector_naciones[8]=nac9;
     vector_naciones[9]=nac10;

    do
    {
        flag=0;
        for(i=0;i<QTY;i++)
        {
            if(vector_pelicula[i].id_estado=='F')
            {
                flag=1;
                break;
            }
        }
        flagD=0;
        for(i=0;i<QTY;i++)
        {
            if(vector_directores[i].id_estado=='F')
            {
                flagD=1;
                break;
            }
        }

        opcion=menu_generico("\n1-alta\n2-baja\n3baja pelicula-\n4-nuevo director\n5-eliminar director\n6-informar\n7-mostrar\n",1,7);

        switch(opcion)
        {
        case 1:
            empty=searchEmptyP(vector_pelicula,QTY);
            if(empty!='E')
            {
                if(upMovie(vector_pelicula,vector_directores,vector_naciones,vector_relacion,empty,QTY)==0)
                    printf("\nDatosUp\n");
                else
                    printf("\nERROR\n");
            }
            else
                printf("No hay mas lugar.\n");
            break;
        case 2:
            if(flag)
            {
                if(modifyData(vector_pelicula,vector_naciones,vector_directores,vector_relacion,QTY)==0)
                    printf("OK");
                else
                    printf("ERROR");
            }
            else
                printf("Cargue una pelicula.\n");

            break;
        case 3:
            if(flag)
            {
                if(downUser (vector_pelicula,QTY)==0)
                    printf("\nOk\n");
                else
                    printf("\nError\n");
            }
            else
                printf("Cague una pelicula.\n");
            break;
        case 4:
            empty=searchEmptyD (vector_directores,QTY);
            if(empty!=-1)
            {
                if(upDirector(vector_directores,vector_naciones,QTY,empty)==0)
                    printf("DatosUp\n");
                else
                    printf("Error\n");
            }
            else
                printf("No hay las lugar.\n");
            break;
        case 5:
            if(flagD)
            {
                if(downDirector(vector_directores,QTY)==0)
                    printf("\nSe ha dado de baja correctamente al director. \n");
                else
                    printf("\nNo se pudo dar de baja al director. \n");
            }
            else
                printf("Cargue un director.\n");
            break;
        case 6:
            if(flagD&&flag)
            {
                cant_pelicula_y_cant_director(vector_relacion,vector_directores,vector_cantpeli,vector_pelicula,vector_cantdirec,QTY);
            }
            else
                printf("Cargue un director con alguna pelicula al menos.");
            break;
        case 7:
//            if(flag)
//            {
//                 generateList(vector_pelicula);
//            }
//            else
//                printf("Cargue una pelicula.\n");
//            break;
        case 8:
            continuar=verifyExit();
            break;
        }
        system("pause");
    }
    while(continuar);


    return 0;
}

















