#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FUNCION.h"
#include <ctype.h>
#include "LIBRERIA.h"
#define QTY 20




int main()
{
    /**lista*/
    e_avion vector_avion[1000];
    e_vuelo vector_vuelo[1000];
    /*******/
    e_relacion vector_relacion[1000];
    e_aeropuerto vector_aeropuerto[1000];
    e_modelo vector_modelo[1000];

    e_cant_vuelo_mode vector_cantvueavion[1000];
    e_cant_vuelo_avion vector_cantvuemodelo[1000];

    int opcion;
    int continuar=1;
    int empty;
    int i;
    int flag;
    int flagD;







    initStruct(vector_avion,vector_vuelo,vector_aeropuerto,vector_modelo,QTY);





    do
    {
        flag=0;
        for(i=0;i<QTY;i++)
        {
            if(vector_avion[i].id_estado=='F')
            {
                flag=1;
                break;
            }
        }
        flagD=0;
        for(i=0;i<QTY;i++)
        {
            if(vector_vuelo[i].id_estado=='F')
            {
                flagD=1;
                break;
            }
        }

        opcion=menu_generico("\n1-alta AVION\n2-modificar avion\n3baja avion-\n4-nuevo vuelo\n5-eliminar vuelo\n6-informar\n7-mostrar\n",1,7);

        switch(opcion)
        {
        case 1:
            empty=search_Empty_avion(vector_avion,QTY);
            if(empty!='E')
            {
                if(upAVION(vector_avion,vector_vuelo,vector_modelo,empty,QTY)==0)
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
                if(modifyData(vector_avion,vector_modelo,QTY)==0)
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
                if(downUser (vector_avion,QTY)==0)
                    printf("\nOk\n");
                else
                    printf("\nError\n");
            }
            else
                printf("Cague una pelicula.\n");
            break;
        case 4:
            empty=search_Empty_vuelo(vector_vuelo,QTY);
            if(empty!=-1)
            {
                if(upVUELO(vector_vuelo,vector_avion,vector_aeropuerto,vector_relacion,QTY,empty)==0)
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
                if(downvuelo(vector_vuelo,vector_avion,QTY)==0)
                    printf("\nSe ha dado de baja correctamente el vuelo. \n");
                else
                    printf("\nNo se pudo dar de baja el vuelo. \n");
            }
            else
                printf("Cargue un director.\n");
            break;
        case 6:
//            if(flagD&&flag)
//            {
//                cant_pelicula_y_cant_director(vector_relacion,vector_directores,vector_cantpeli,vector_pelicula,vector_cantdirec,QTY);
//            }
//            else
//                printf("Cargue un director con alguna pelicula al menos.");
//            break;
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

















