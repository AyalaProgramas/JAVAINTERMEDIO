#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FUNCIONES.h"
#include <ctype.h>
#include "LABORATORIO.h"
#define QTY 20



int menu_generico(char *mensaje,int desde,int hasta);

int main()
{
    /**lista*/

    e_llamada vector_llamada[500];
    /*******/

    e_abonado vector_abonado[1000];




    int opcion;
    int continuar=1;
    int empty;
    int i;
    int flag;
    int flagD;







    initStruct(vector_abonado,vector_llamada,QTY);





    do
    {
        flag=0;
        for(i=0;i<QTY;i++)
        {
            if(vector_abonado[i].id_estado_empt=='F')
            {
                flag=1;
                break;
            }
        }
        flagD=0;
        for(i=0;i<QTY;i++)
        {
            if(vector_llamada[i].id_estado_empt=='F')
            {
                flagD=1;
                break;
            }
        }

        opcion=menu_generico("\n1-alta del abonado\n2-modificar datos\n3baja abonado-\n4-nueva llamada\n5-fin llamada\n6-informar\n",1,6);

        switch(opcion)
        {
        case 1:
            //empty=search_Empty_abonado(vector_abonado,QTY);
            if(empty!='E')
            {
                if(upabonado(vector_abonado,/*vector_directores,vector_naciones,vector_relacion,*/empty,QTY)==0)
                    printf("\nDatosUp\n");
                else
                    printf("\ndatos no subidos\n");
            }
            else
                printf("No hay mas lugar.\n");
            break;
        case 2:
            if(flag)
            {
                if(modifyData(vector_abonado,/*vector_naciones,vector_directores,vector_relacion,*/QTY)==0)
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
                if(downabonado(vector_abonado,QTY)==0)
                    printf("\nOk\n");
                else
                    printf("\nError\n");
            }
            else
                printf("Cargue un abonado.\n");
            break;
        case 4:
            empty=search_empty_llamada(vector_llamada,QTY);
            if(empty!=-1)
            {
                if(upllamada(vector_llamada,vector_abonado,QTY,empty)==0)
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
                if(finllamada(vector_llamada,QTY)==0)
                    printf("\nSe ha dado de baja correctamente al director. \n");
                else
                    printf("\nNo se pudo dar de baja al director. \n");
            }
            else
                printf("Cargue un director.\n");
            break;
        case 6:

            break;
        case 7:

        case 8:
            continuar=verifyExit();
            break;
        }
        system("pause");
    }
    while(continuar);


    return 0;
}
