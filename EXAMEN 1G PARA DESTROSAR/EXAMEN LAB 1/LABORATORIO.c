#define QTY 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FUNCIONES.h"
#include "LABORATORIO.h"
#include <ctype.h>
#define FALLA_3G 1
#define FALLA_LTE 2
#define FALLAE_QUIPO 3
#define EN_CURSO 4
#define SOLUCIONADO 5
#define NO_SOLUCIONADO 6
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int upabonado(e_abonado* vec_abonado, int indice,int cant)
{
    system("cls");
    char auxapellido[255];//
    int flagapellido=0;//

    char auxnombre[255];//
    char auxtelefono[255];//
    char auxDirec[255];
    int flagDate=0;//


    int flagnombre=0;//
    int flagtelefono=0;//

    int flagId=0;//
    int retorno=-1;//
    int id_abonado;//

    int indice_relacion;///nose



    printf("Ingrese nombre:");
    fflush(stdin);
    gets(auxnombre);
    if(verifyArrayAlphaNum(auxnombre,1,49)==0)
    {
        flagnombre=1;
    }
    else
        printf("ERROR");

    if(flagnombre)
    {
        printf("Ingrese apellido:");
        fflush(stdin);
        gets(auxapellido);
        if(verifyArrayAlphaNum(auxapellido,1,49)==0)
        {
            flagapellido=1;
        }
        else
            printf("ERROR\n");
    }
    else
        printf("error\n");


    if(flagapellido)
    {
        while(flagDate==0)
        {
            printf("Ingrese numero de telefono: ");
            fflush(stdin);
            gets(auxtelefono);
            if(verifyArrayNum(auxtelefono,8,8)==0)
            {

                    flagtelefono=1;
                    flagDate=1;

            }
        }

    }
    else
        printf("ERROR");




    if(flagtelefono)
    {
        id_abonado=recorre_estado_abonado(vec_abonado,cant);
        flagId=1;
    }
    else
        printf("ERROR");







    if(flagId)
    {

        strcpy(vec_abonado[indice].dest_nombre,auxnombre);
        strcpy(vec_abonado[indice].dest_apellido,auxapellido);
        vec_abonado[indice].id_abonado=id_abonado;
        vec_abonado[indice].dest_numero_tel=atoi(auxtelefono);


        vec_abonado[indice].id_estado_empt='F';
        retorno=0;
    }
    else
        printf("error\n");
    return retorno;
}







/** \brief
 *
 * \param
 * \param
 * \return
 *
 */



int modifyData (e_abonado* arrayabonado,int cant)
{
    char orige_id_abonado[10];//

    int flag_id_modificar=0;//

    int busqueda_de_id;

    int retorno=-1;
    int opcion;

    char auxiliar[255];

    int flagnombre=0;
    int flagapellido=0;

    int continuar=1;

    ///imprimir listas de los abonados para modificar///<------------------------------------------------------------
    imprimir_lista_abonado(arrayabonado,cant);

    if(get_string_numero("ingrese numero de id del abonado para modificar",orige_id_abonado))
    {
        flag_id_modificar=1;
    }
    //busqueda_de_id=search_Id_abonado(arrayabonado,cant,atoi(orige_id_abonado));
    if(flag_id_modificar&&busqueda_de_id!=-1)
    {
        printf("MODIFICAR\n");

        while(continuar)
        {
            opcion=menu_generico("1.NOMBRE:\n2.APELLIDO\n3.SALIR",1,3);

                switch(opcion)
                {
                case 1:
                    system("cls");

                    while(flagnombre==0)
                    {
                        printf("Ingrese nuevo nombre: ");
                        gets(auxiliar);
                        if(verifyArrayAlpha(auxiliar,1,20)==0)
                        {
                            flagnombre=1;
                            strcpy(arrayabonado[busqueda_de_id].dest_nombre,auxiliar);
                        }

                        else
                            printf("Error, reintente");
                    }
                    retorno=0;
                    break;

                case 2:
                    system("cls");

                    while(flagapellido==0)
                    {
                        printf("Ingrese nuevo apellido: ");
                        gets(auxiliar);
                        if(verifyArrayAlpha(auxiliar,1,20)==0)
                        {
                            flagapellido=1;
                            strcpy(arrayabonado[busqueda_de_id].dest_apellido,auxiliar);
                        }

                        else
                            printf("Error, reintente");
                    }
                    retorno=0;
                    break;

                case 3:
                    continuar=verifyExit();
                    retorno=0;
                    break;
                default:
                    break;
                }
        }
    }
    else
        printf("error no es id\n");
    return retorno;
}





/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int downabonado(e_abonado* arrayabonado,int cant)
{
    int retorno=-1;
    char id_para_dar_baja[10];
    int i;

///imprimir abonado para dar de baja///<-----------------------------------------------------------------------------------------
  imprimir_lista_abonado(arrayabonado,cant);
if(get_string_numero("ingrese el id para dar de baja",id_para_dar_baja))
{
//    i=search_Id_abonado(arrayabonado,cant,atoi(id_para_dar_baja));
    if(i!=-1)
    {
        printf("Acaba de dar de baja el abonador:\nnombre:%s\napellido:%s\nID: %d\n",arrayabonado[i].dest_nombre,arrayabonado[i].dest_apellido,arrayabonado[i].id_abonado);
        arrayabonado[i].id_estado_empt='D';
        retorno=0;
    }
    else
        printf("\nEse ID no esta registado.");
}

    return retorno;
}



int upllamada(e_llamada* arrayllamada,e_abonado* arrayabonado,int cant,int i)
{
    int flagabonado=0;
    int id_abonado;
    int flagmotivo=0;
    int opcion_motivo;
    int id_llamada;
    int id_director;
    int id_nacion;
    int retorno=-1;

    int flagNacio=0;

    char auxabonado[50];

    ///imprimir lista de abonado*///
    imprimir_lista_abonado(arrayabonado,cant);
    if(get_string_letras("ingrese el id del abonado",auxabonado))
    {
        id_abonado=atoi(auxabonado);
        flagabonado=1;

    }
    else
        printf("ERROR");
    if(flagabonado)
    {
        opcion_motivo=menu_generico("eliga motivo de llamada:\n1.FALLA 3G:\n2.FALLA LTE\n3.FALLA EQUIPO\n",1,3);

        flagmotivo=1;

    }
    if(flagabonado)
    {
        id_llamada=recorre_estado_llamada(arrayllamada,cant);
        flagNacio=1;

    }

    if(flagmotivo)
    {
        arrayllamada[i].id_llamada=id_llamada;
        arrayllamada[i].id_motivo=opcion_motivo;
        arrayllamada[i].id_abonado=id_abonado;
        arrayllamada[i].id_estado=EN_CURSO;
        arrayllamada[i].id_estado_empt='F';
        retorno=0;
    }
    else
        printf("error\n");
    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int finllamada(e_llamada* arrayfinllamada,int cant,int i)
{
    int auxseg;
    int auxmin;
    int auxhora;
    int id_llamada[50];

    int flagestado=0;
    int flaghorario=0;
    int id_abonado;
    int flagmotivo=0;
    int opcion_estado;
    int retorno=-1;

    int flagNacio=0;

    char auxabonado[50];
    if(get_string_numero("ingrese el id de las llamada para finalizar",id_llamada))
    {
        opcion_estado=menu_generico("eliga unos de los estados:\n1.SOLUCIONADO:\n2.NO SOLUCIONADO\n",1,2);
        flagestado=1;
        if(flagestado)
        {
            if(getDatehora(&auxseg,&auxmin,&auxhora)==0)
            flaghorario=1;

        }
    }
    else
        printf("error\n");




    if(flaghorario)
    {
        arrayfinllamada[i].tiempo_conclusion.segundos=auxseg;
        arrayfinllamada[i].tiempo_conclusion.minutos=auxmin;
        arrayfinllamada[i].tiempo_conclusion.hora=auxhora;
        arrayfinllamada[i].id_abonado=opcion_estado;

        arrayfinllamada[i].id_estado_empt='F';
        retorno=0;
    }
    printf("error\n");
    return retorno;
}









/********************************************************************//********************************************************************/
/********************************************************************//********************************************************************/
/********************************************************************//********************************************************************/

int recorre_estado_llamada(e_llamada vector_estado[],int cant_llamada);
int max_id_llamada(e_llamada* vector_id,int cant_id);
int max_id_abonado(e_abonado* vector_id,int cant_id);
int search_id_abonado(e_abonado* arrayabonado, int id,int cant);





int recorre_estado_llamada(e_llamada vector_estado[],int cant_llamada)///<-------------------------------------------------++++++++++
{
    int i;
    int mayor=0;

    for(i=0;i<cant_llamada;i++)
    {
        if(vector_estado[i].id_estado_empt=='E')
        {
            mayor=max_id_llamada(vector_estado,cant_llamada)+1;
            break;
        }

    }

    return mayor;

}

/** \brief  recorre el array vector_id para encontar el mayor id_pelicula
 *
 * \param vector_id es el array en donde buscar
 * \param  cant_id es el tamanio del array a recorrer
 * \return retorna el mayor id_pelicula del array
 *
 */

int max_id_llamada(e_llamada* vector_id,int cant_id)///<---------------------------------------------------------------------
{
    int i;
    int mayor=0;
    for(i=0;i<cant_id;i++)
    {
        if(vector_id[i].id_estado_empt=='F')
        {
            if(vector_id[i].id_llamada>mayor)
            {
                mayor=vector_id[i].id_llamada;

            }

        }
    }

    return mayor;
}

/** \brief  recorre el array vector_id para encontar el mayor id_pelicula
 *
 * \param vector_id es el array en donde buscar
 * \param  cant_id es el tamanio del array a recorrer
 * \return retorna el mayor id_pelicula del array
 *
 */

int max_id_abonado(e_abonado* vector_id,int cant_id)///<---------------------------------------------------------------------
{
    int i;
    int mayor=0;
    for(i=0;i<cant_id;i++)
    {
        if(vector_id[i].id_estado_empt=='F')
        {
            if(vector_id[i].id_abonado>mayor)
            {
                mayor=vector_id[i].id_abonado;

            }

        }
    }

    return mayor;
}







/** \brief recorre el array id_pelicula para encontrar el primer espacio vacio 'E' y crear un nuevo id
 *
 * \param vector_estado es el array en donde buscar
 * \param cant_peli es tamanio del array a recorrer
 * \return retorna un nuevo id
 *
 */

int recorre_estado_abonado(e_abonado vector_estado[],int cant_abonado)///<-----------------------------------------------------------
{
    int i;
    int mayor=0;

    for(i=0;i<cant_abonado;i++)
    {
        if(vector_estado[i].id_estado_empt=='E')
        {
            //mayor=max_id_pelicula(vector_estado,cant_abonado)+1;
            break;
        }

    }

    return mayor;

}
/** \brief imprime una lista de la cantidad de directores
 *
 * \param vectordirector es el array en donde buscar
 * \param tam es el tamanio del array a recorrer
 *
 */


void imprimir_lista_abonado(e_abonado* vectorabonado,int tam)///<---------------------------------------------------------------
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(vectorabonado[i].id_estado_empt=='F')
        {
            printf("%d-%s\n",vectorabonado[i].id_abonado,vectorabonado[i].dest_nombre);

        }

    }

}
/** \brief busca el primer lugar no utilisado en el array
 *
 * \param array es el array en donde buscar
 * \param cant es el tamanio del array a recorrer
 * \return  retorna -1 si no hay ocurrencia y si la hay retorna la posicion i
 *
 */


int search_empty_llamada(e_llamada* array, int cant)///<--------------------------------------+++++++++++++++++++++++++++++++++++++++++++
{
    int retorno=-1;
    int i;

        for ( i=0;i<cant;i++)
        {
            if(array[i].id_estado_empt=='E')
            {
                retorno=i;
                break;
            }
        }
    return retorno;
}

/** \brief busca el id_pelicula en el array
 *
 * \param arrayP es el array en donde buscar
 * \param id es el id de la pelicula ingresado para buscar en el arrayP
 * \param cant es el tamanio del array a recorrer
 * \return retorna -1 si no hay ocurrencia y si la hay retorna i
 *
 */


int search_id_abonado(e_abonado* arrayabonado, int id,int cant)///<----------------------------------------------------------------------
{
    int retorno=-1;
    int i;
    for ( i=0;i<cant;i++)
    {
        if(arrayabonado[i].id_estado_empt==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void initStruct (e_abonado* arrayP,e_llamada* arrayD,int cant)
{
    int i;

    for (i=0;i<cant;i++)
    {
        arrayD[i].id_estado_empt='E';
        arrayP[i].id_estado_empt='E';


    }
}
