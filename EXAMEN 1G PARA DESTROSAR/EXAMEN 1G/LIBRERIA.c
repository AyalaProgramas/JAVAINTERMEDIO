
#define QTY 10
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FUNCION.h"
#include "LIBRERIA.h"
#include <ctype.h>


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int upMovie (e_video* vec_pelicula,e_director* vec_director,e_nacion* vec_nacion,e_relacion* vec_relacion, int indice,int cant)
{
    system("cls");
    char auxTitulo[255];
    char auxAno[255];
    char auxDirec[255];
    int flagDate=0;

    int empty;
    int flagTitulo=0;
    int flagAno=0;
    int flagNacio=0;
    int flagDirec=0;
    int flagId=0;
    int retorno=-1;
    int id_pelicula;
    char opcion_pais;
    int id_nacion;
    int id_director;
    char seguir='n';
    int indice_relacion;



    printf("Ingrese titulo de la pelicula:");
    fflush(stdin);
    gets(auxTitulo);
    if(verifyArrayAlphaNum(auxTitulo,1,49)==0)
    {
        flagTitulo=1;
    }
    else
        printf("ERROR");



    if(flagTitulo)
    {
        while(flagDate==0)
        {
            printf("Ingrese anio: ");
            fflush(stdin);
            gets(auxAno);
            if(verifyArrayNum(auxAno,4,4)==0)
            {
                if(verifyDate(atoi(auxAno),1000,2020)==0)
                {
                    flagAno=1;
                    flagDate=1;
                }
            }
        }

    }
    else
        printf("ERROR");







    if(flagAno)
    {
       id_nacion=up_naciones_HC(vec_nacion,cant);
       flagNacio=1;

    }
    else
        printf("ERROR");


    if(flagNacio)
    {
        id_pelicula=recorre_estado_pelicula(vec_pelicula,cant);
        flagId=1;
    }
    else
        printf("ERROR");






    if(flagId)
    {
        do
        {

            imprimir_lista_director(vec_director,cant);
            printf("\nse encuentra el director en la lista <s>/<n>\n");
            fflush(stdin);
            opcion_pais=getchar();

            if(opcion_pais!='s')
            {

                empty=searchEmptyD(vec_director,cant);
                if(empty!=-1)
                {
                    printf("Ingrese nombre del director: ");
                    fflush(stdin);
                    gets(auxDirec);
                    id_director=upDirectorHC(vec_director,vec_nacion,auxDirec,cant);
                    if(id_director!=0)
                    {
                        printf("Se ha registrado al director, gracias.\n");
                        flagDirec=1;
                    }
                    else
                        printf("Error al cargar\n");
                }
                else
                    printf("No hay mas lugar\n");

            }
            else
            {
                if(get_string_numero("ingrese la opcion de directores",auxDirec))
                {
                    id_director=atoi(auxDirec);
                    flagDirec=1;
                }


            }
            indice_relacion=searchEmptyR(vec_relacion,cant);
            vec_relacion[indice_relacion].id_director=id_director;
            vec_relacion[indice_relacion].id_pelicula=id_pelicula;

            printf("desea seguir ingresando directores en la pelicula presione <s> si no <n>\n");
            fflush(stdin);
            seguir=getchar();
        }while(seguir=='s');
    }
    else
        printf("ERROR");

    if(flagDirec)
    {
        strcpy(vec_pelicula[indice].dest_titulo,auxTitulo);
        vec_pelicula[indice].id_nacionalidad=id_nacion;
        vec_pelicula[indice].dest_anio=atoi(auxAno);
        vec_pelicula[indice].id_pelicula=id_pelicula;
        vec_pelicula[indice].id_estado='F';
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



int modifyData (e_video* array,e_nacion* vec_naciones,e_director* vec_director,e_relacion* vec_relacion,int cant)
{
    int flag_id_modificar;
    int id_naciones;
    int id_director;
    int busqueda_de_id;
    char orige_director[200];
    int atoi_direc_cambiar;
    int i;
    int retorno=-1;
    int opcion;
    char orige_id_pelicula[10];
    char auxiliar[255];
    int flag;

    int continuar=1;
    if(get_string_numero("ingrese numero de id",orige_id_pelicula))
    {
        flag_id_modificar=1;
    }
    busqueda_de_id=search_Id_pelicula(array,cant,atoi(orige_id_pelicula));
    if(flag_id_modificar&&busqueda_de_id!=-1)
    {
        printf("MODIFICAR\n");

        while(continuar)
        {
            opcion=menu_generico("1.Titulo\n2.Anio\n3.Nacionalidad\n4.Director\n",1,5);

                switch(opcion)
                {
                case 1:
                    system("cls");
                    flag=0;
                    while(flag==0)
                    {
                        printf("Ingrese nuevo titulo: ");
                        gets(auxiliar);
                        if(verifyArrayAlpha(auxiliar,1,20)==0)
                        {
                            flag=1;
                            strcpy(array[busqueda_de_id].dest_titulo,auxiliar);
                        }

                        else
                            printf("Error, reintente");
                    }
                    retorno=0;
                    break;
                case 2:
                    system("cls");
                    flag=0;
                    while(flag==0)
                    {
                        printf("Ingrese el nuevo ano: ");
                        gets(auxiliar);
                        if(verifyArrayNum(auxiliar,1,6)==0)
                        {
                            flag=1;
                            array[busqueda_de_id].dest_anio=atoi(auxiliar);
                        }
                        else
                            printf("Error, reintente");
                    }
                    retorno=0;
                    break;
                case 3:
                    system("cls");
                    flag=0;
                    while(flag==0)
                    {
                       id_naciones=up_naciones_HC(vec_naciones,cant);

                       array[busqueda_de_id].id_nacionalidad=id_naciones;
                       flag=1;

                    }
                    retorno=0;
                    break;
                case 4:
                    flag=0;
                    while(flag==0)
                    {
                        imprimir_lista_director(vec_director,cant);
                        if(get_string_letras("Ingrese la opcion del nuevo director: ",orige_director))
                        {
                            flag=1;
                        }
                        id_director=upDirectorHC(vec_director,vec_naciones,orige_director,cant);

                        ///mostra directores qu e hicieron la pelicula
                        imprimir_lista_director(vec_director,cant);

                        if(get_string_letras("Ingrese el director que quiere cambiar",orige_director))
                        {
                            flag=1;
                        }
                        atoi_direc_cambiar=atoi(orige_director);

                        for(i=0;i<cant;i++)
                        {
                            if(vec_relacion[i].id_pelicula==atoi(orige_id_pelicula)&&vec_relacion[i].id_director==atoi_direc_cambiar)
                            {
                                vec_relacion[i].id_director=id_director;

                                flag=1;
                                break;
                            }
                        } 


                    }
                    retorno=0;
                    break;
                case 5:
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


int downUser (e_video* array,int cant)
{
    int retorno=-1;
    char id_para_dar_baja[10];
    int i;


if(get_string_numero("ingrese el id para dar de baja",id_para_dar_baja))
{
    i=search_Id_pelicula(array,cant,atoi(id_para_dar_baja));
    if(i!=-1)
    {
        printf("Acaba de dar de baja la pelicula:\n%s\nID: %d\n",array[i].dest_titulo,array[i].id_pelicula);
        array[i].id_estado='D';
        retorno=0;
    }
    else
        printf("\nEse ID no esta registado.");
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


int upDirector(e_director* array,e_nacion* arrayN,int cant,int i)
{
    int id_director;
    int id_nacion;
    int retorno=-1;
    int flagDirec=0;
    int flagNacio=0;
    int flagFecha=0;
    //char auxDirec[255];
    //char auxNacio[255];
    //char auxFecha[255];
    int auxDia;
    int auxMes;
    int auxAno;

    if(get_string_letras("ingrese el nombre del director",auxDirec) /*verifyArrayAlpha(auxDirec,1,49)==0*/)
    {
        if(searchDirector(array,auxDirec,cant)==-1)
        {
            flagDirec=1;
            id_director=recorre_estado_director(array,cant);
        }
        else
            printf("El director ya se encuentra registado");
    }
    else
        printf("ERROR");
    if(flagDirec)
    {
        id_nacion=up_naciones_HC(arrayN,cant);
        flagNacio=1;

    }
    if(flagNacio)
    {
        if(getDate(&auxDia,&auxMes,&auxAno)==0)
            flagFecha=1;

    }
    if(flagFecha)
    {
        strcpy(array[i].dest_nombre,auxDirec);
        array[i].id_nacionalidad=id_nacion;
        array[i].fechanacimiento.dia=auxDia;
        array[i].fechanacimiento.mes=auxMes;
        array[i].fechanacimiento.ano=auxAno;
        array[i].id_director=id_director;
        array[i].id_estado='F';
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



int downDirector(e_director* array,int cant)
{
    int retorno=-1;
    char auxiliar[255];
    int i;
    int continuar=1;
    printf("DAR DE BAJA\nlista de directores:\n");
    imprimir_lista_director(array,cant);
    printf("Ingres el nombre del director: ");
    fflush(stdin);
    gets(auxiliar);
    i=searchDirector(array,auxiliar,cant);
    if(i!=-1)
    {
        printf("Nombre: %s\n",array[i].dest_nombre);
        printf("Nacionalidad: %d\n",array[i].id_nacionalidad);
        continuar=verifyYorN();
        if(continuar==0)
        {
            array[i].id_estado='D';
            retorno=0;
        }
        else
            printf("Hasta luego.");
    }
    else
        printf("\nEl director no se encuentra registado.\n");
    return retorno;
}



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


void cant_pelicula_y_cant_director(e_relacion* arrayR,e_director* arrayD,e_cant_pelicula* array_cont_peli,e_video* arrayP,e_cant_director* array_cont_direc,int cant)
{

    int id_director_busque_indice;
    int id_director_busque_cant;

    int id_pelicula_busque_indice;
    int id_pelicula_busque_cant;
    /******/
    int flag_permiso_indice=0;
    int flag_max_peli=0;
    int flag_max_dire=0;
    /*******/
    int max_peli=0;
    int max_dire=0;
    /*******/
    int id_director;
    int id_pelicula;
    /******/
    int indi_can_peli=0;
    int indi_can_direc=0;
    /******/
    int i;
    int j;
    int k;
    int opcion;
    /******/
    int contador_de_pelicula=0;
    int contador_de_directores=0;


    opcion=menu_generico("\n1-desea ver el director con mas peliculas\n2-desea ver la pelicula con mas directores",1,2);
    switch(opcion)
    {
        case 1:
                for(k=0;k<cant;k++)
                {
                    contador_de_pelicula=0;
                    if(arrayD[k].id_estado!='F')
                    {
                        continue;
                    }

                    id_director=arrayD[k].id_director;

                    for(i=0;i<cant;i++)
                    {

                        if(arrayR[i].id_director==id_director)
                        {
                            contador_de_pelicula++;
                            flag_permiso_indice=1;
                        }
                    }
                    if(flag_permiso_indice)
                    {
                        array_cont_peli[indi_can_peli].cant_pelicula=contador_de_pelicula;
                        array_cont_peli[indi_can_peli].id_director=id_director;

                        indi_can_peli++;
                    }


                }

                for(j=0;j<cant;j++)
                {
                    if(array_cont_peli[j].cant_pelicula>max_peli||flag_max_peli==0)
                    {
                        max_peli=array_cont_peli[j].cant_pelicula;
                        flag_max_peli=1;
                    }
                }


                ///buscar director con max_peli igualando FUNCIONES.......

                id_director_busque_cant=buscar_n_dire_max_peli(array_cont_peli,max_peli,cant);
                id_director_busque_indice=searchDirector_por_id(arrayD,id_director_busque_cant,cant);
                printf("El director  %d-%s tiene %d peliculas \n",id_director_busque_cant,arrayD[id_director_busque_indice].dest_nombre,max_peli);
                system("pause");
            break;

        case 2:
                for(k=0;k<cant;k++)
                {
                    contador_de_directores=0;
                    if(arrayP[k].id_estado!='F')
                    {
                        continue;
                    }

                    id_pelicula=arrayP[k].id_pelicula;

                    for(i=0;i<cant;i++)
                    {

                        if(arrayR[i].id_pelicula==id_pelicula)///hacer array mas claros para no confundirme
                        {
                            contador_de_directores++;
                            flag_permiso_indice=1;///hacer otro indice_p xq va entrar siempre
                        }
                    }
                    if(flag_permiso_indice)
                    {
                        array_cont_direc[indi_can_direc].cant_directores=contador_de_directores;
                        array_cont_direc[indi_can_direc].id_pelicula=id_pelicula;

                        indi_can_direc++;
                    }


                }

                for(j=0;j<cant;j++)
                {
                    if(array_cont_direc[j].cant_directores>max_dire||flag_max_dire==0)
                    {
                        max_dire=array_cont_direc[j].cant_directores;
                        flag_max_dire=1;
                    }
                }
                ///buscar director con max_peli igualando
                id_pelicula_busque_cant=buscar_n_dire_max_dire(array_cont_direc,max_dire,cant);
                id_pelicula_busque_indice=search_Id_pelicula(arrayP,id_pelicula_busque_cant,cant);
                printf("la pelicula  %d-%s tiene %d directores \n",id_pelicula_busque_cant,arrayP[id_pelicula_busque_indice].dest_titulo,max_dire);
                system("pause");

            break;
        default:

            break;

    }




}







/********************************************************************//********************************************************************/
/********************************************************************//********************************************************************/
/********************************************************************//********************************************************************/








/** \brief iniciacilisa todos los id_estado de las estructuras
 *
 * \param arrayP es el array en cual se inicilisa id_estado con 'E'
 * \param arrayD es el array en cual se inicilisa id_estado con 'E'
 * \param arrayN es el array en cual se inicilisa id_estado con 'E'
 * \param arrayR es el array en cual se inicilisa id_estado con 'E'
 * \param cant es el tamanio del array a recorrer

 *
 */


void initStruct (e_video* arrayP,e_director* arrayD,e_nacion* arrayN,e_relacion* arrayR,int cant)
{
    int i;

    for (i=0;i<cant;i++)
    {
        arrayD[i].id_estado='E';
        arrayP[i].id_estado='E';
        arrayN[i].id_estado='E';
        arrayR[i].id_director='E';
        arrayR[i].id_pelicula='E';
    }
}



/** \brief busca el primer lugar no utilisado en el array
 *
 * \param array es el array en donde buscar
 * \param cant es el tamanio del array a recorrer
 * \return  retorna -1 si no hay ocurrencia y si la hay retorna la posicion i
 *
 */

int searchEmptyP (e_video* array, int cant)
{
    int retorno=-1;
    int i;

        for ( i=0;i<cant;i++)
        {
            if(array[i].id_estado=='E')
            {
                retorno=i;
                break;
            }
        }
    return retorno;
}

///up_naciones_HC(--------)++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/** \brief busca el primer lugar no utilisado en el array
 *
 * \param array es el array en donde buscar
 * \param cant es el tamanio del array a recorrer
 * \return  retorna -1 si no hay ocurrencia y si la hay retorna la posicion i
 *
 */

int searchEmptyN (e_nacion* array, int cant)
{
    int retorno=-1;
    int i;

        for ( i=0;i<cant;i++)
        {
            if(array[i].id_estado=='E')
            {
                retorno=i;
                break;
            }
        }
    return retorno;
}
/** \brief imprime una lista de la cantidad de pais
 *
 * \param vectorpais es el array en donde buscar
 * \param tam es el tamanio del array a recorrer
 *
 */


void imprimir_lista_pais(e_nacion* vectorpais,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(vectorpais[i].id_estado=='F')
        {
            printf("%d-%s\n",vectorpais[i].id_nacionalidad,vectorpais[i].dest_pais);

        }

    }

}
/** \brief recorre el array id_nacion para encontrar el primer espacio vacio 'E' y crear un nuevo id
 *
 * \param vector_estado es el array en donde buscar
 * \param cant_nacio es tamanio del array a recorrer
 * \return retorna un nuevo id
 *
 */

int recorre_estado_nacion(e_nacion vector_estado[],int cant_nacio)
{
    int i;
    int mayor=0;

    for(i=0;i<cant_nacio;i++)
    {
        if(vector_estado[i].id_estado=='E')
        {
            mayor=max_id_nacion(vector_estado,cant_nacio)+1;
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

int max_id_pelicula(e_video* vector_id,int cant_id)
{
    int i;
    int mayor=0;
    for(i=0;i<cant_id;i++)
    {
        if(vector_id[i].id_estado=='F')
        {
            if(vector_id[i].id_pelicula>mayor)
            {
                mayor=vector_id[i].id_pelicula;

            }

        }
    }

    return mayor;
}


/** \brief  recorre el array vector_id para encontar el mayor id_nacion
 *
 * \param vector_id es el array en donde buscar
 * \param  cant_id es el tamanio del array a recorrer
 * \return retorna el mayor id_nacion del array
 *
 */



int max_id_nacion(e_nacion* vector_id,int cant_id)
{
    int i;
    int mayor=0;
    for(i=0;i<cant_id;i++)
    {
        if(vector_id[i].id_estado=='F')
        {
            if(vector_id[i].id_nacionalidad>mayor)
            {
                mayor=vector_id[i].id_nacionalidad;

            }

        }
    }

    return mayor;
}
/** \brief  recorre el array vector_id para encontar el mayor id_director
 *
 * \param vector_id es el array en donde buscar
 * \param  cant_id es el tamanio del array a recorrer
 * \return retorna el mayor id_director del array
 *
 */

int max_id_director(e_director* vector_id,int cant_id)
{
    int i;
    int mayor=0;
    for(i=0;i<cant_id;i++)
    {
        if(vector_id[i].id_estado=='F')
        {
            if(vector_id[i].id_director>mayor)
            {
                mayor=vector_id[i].id_director;

            }

        }
    }

    return mayor;
}





//void generateList(EPelicula* array)
//{
//    char titulo[]={"TITULO"};
//    char director[]={"DIRECTOR"};
//    char ano[]={"ANO"};
//    char nacionalidad[]={"NACIONALIDAD"};
//    int i,j;
//    EPelicula aux;
//    for(i=0;i<QTY-1;i++)
//    {
//        if(array[i].isEmpty==-1)
//            continue;
//        for(j=i+1;j<QTY;j++)
//        {
//            if(array[j].isEmpty==-1)
//                continue;
//            if(stricmp(array[i].titulo,array[j].titulo)>0)
//            {
//                aux=array[i];
//                array[i]=array[j];
//                array[j]=aux;
//            }
//            else if(stricmp(array[i].titulo,array[j].titulo)==0)
//            {
//                if(array[i].ano>array[j].ano)
//                {
//                    aux=array[i];
//                    array[i]=array[j];
//                    array[j]=aux;
//                }
//            }
//        }
//    }
//    printf("%20s%20s%15s %s\n",titulo,director,nacionalidad,ano);
//    for(i=0;i<QTY;i++)
//    {
//        if(array[i].isEmpty==0)
//        {
//            printf("%20s%20s%15s  %d\n",array[i].titulo,array[i].director,array[i].nacionalidad,array[i].ano);
//        }
//    }
//    system("pause");
//}








///UP-MOVIE++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/** \brief ingresa una nueva nacion al array estructura si el pais no se encuentra en la lista
 *
 * \param arrayN es el array en cual buscar
 * \param cant es el tamanio del array a recorrer
 * \return retorna el id_nacion
 *
 */

int up_naciones_HC(e_nacion arrayN[],int cant)
{

            int opcion_pais;
            char auxNacio[50];
            //int atoi_id_pais;
            int flagnacion=0;
            int empty;
            int id_nacion;



            printf("\nOPCIONES DE PAISES PARA LA PELICULA:\n");
            imprimir_lista_pais(arrayN,cant);
            printf("se encuentra el pais en la lista ingrese s:<SI>  n:<NO>\n");
            fflush(stdin);
            opcion_pais=getchar();
            if(opcion_pais=='s')
            {
                if(get_string_numero("ingrese la opcion del pais:",auxNacio))
                {
                    id_nacion=atoi(auxNacio);
                }
            }
            else
            {
                id_nacion=recorre_estado_nacion(arrayN,cant);
                flagnacion=1;

                empty=searchEmptyN(arrayN,cant);

                if(get_string_letras("ingrese el nuevo pais a la lista:",auxNacio))
                {
                    strcpy(arrayN[empty].dest_pais,auxNacio);
                    arrayN[empty].id_estado='F';
                    arrayN[empty].id_nacionalidad=id_nacion;
                }

            }

        return id_nacion;

}
/** \brief recorre el array id_pelicula para encontrar el primer espacio vacio 'E' y crear un nuevo id
 *
 * \param vector_estado es el array en donde buscar
 * \param cant_peli es tamanio del array a recorrer
 * \return retorna un nuevo id
 *
 */

int recorre_estado_pelicula(e_video vector_estado[],int cant_peli)
{
    int i;
    int mayor=0;

    for(i=0;i<cant_peli;i++)
    {
        if(vector_estado[i].id_estado=='E')
        {
            mayor=max_id_pelicula(vector_estado,cant_peli)+1;
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


void imprimir_lista_director(e_director* vectordirector,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(vectordirector[i].id_estado=='F')
        {
            printf("%d-%s\n",vectordirector[i].id_director,vectordirector[i].dest_nombre);

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


int searchEmptyD (e_director* array, int cant)
{
    int retorno=-1;
    int i;

        for ( i=0;i<cant;i++)
        {
            if(array[i].id_estado=='E')
            {
                retorno=i;
                break;
            }
        }
    return retorno;
}
/** \brief ingresa una nuevo director al array estructura si el director no se encuentra en la lista
 *
 * \param array es el array a recorrer
 * \param arrayN es el array a recorrer
 * \param director es el nombre del director para ingresarlo a la lista
 * \param cant es el tamanio del array a recorrer
 * \return retorna el id_director
 *
 */

int upDirectorHC(e_director* array,e_nacion* arrayN,char* director,int cant)
{

    int flagDirec=1;
    int flagNacio=0;
    int flagFecha=0;
    int auxDia=0;
    int auxMes=0;
    int auxAno=0;
    int empty;
    int id_nacion;
    int id_director=0;

    id_director=recorre_estado_director(array,cant);
    printf("nombre del director: %s\n",director);
    if(flagDirec)
    {
          id_nacion=up_naciones_HC(arrayN,cant);
          flagNacio=1;
    }
    if(flagNacio)
    {
        if(getDate(&auxDia,&auxMes,&auxAno)==0)
            flagFecha=1;

    }
    empty=searchEmptyD(array,cant);
    if(flagFecha)
    {
        strcpy(array[empty].dest_nombre,director);
        array[empty].id_nacionalidad=id_nacion;
        array[empty].fechanacimiento.dia=auxDia;
        array[empty].fechanacimiento.mes=auxMes;
        array[empty].fechanacimiento.ano=auxAno;
        array[empty].id_director=id_director;
        array[empty].id_estado='F';
    }
    return id_director;
}

/** \brief busca el primer lugar no utilisado en el array
 *
 * \param array es el array en donde buscar
 * \param cant es el tamanio del array a recorrer
 * \return  retorna -1 si no hay ocurrencia y si la hay retorna la posicion i
 *
 */

int searchEmptyR (e_relacion* array, int cant)
{
    int retorno=-1;
    int i;

        for ( i=0;i<cant;i++)
        {
            if(array[i].id_director=='E')
            {
                retorno=i;
                break;
            }
        }
    return retorno;
}

///modifyData////++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/** \brief busca el id_pelicula en el array
 *
 * \param arrayP es el array en donde buscar
 * \param id es el id de la pelicula ingresado para buscar en el arrayP
 * \param cant es el tamanio del array a recorrer
 * \return retorna -1 si no hay ocurrencia y si la hay retorna i
 *
 */


int search_Id_pelicula(e_video* arrayP, int id,int cant)
{
    int retorno=-1;
    int i;
    for ( i=0;i<cant;i++)
    {
        if(arrayP[i].id_pelicula==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}


///up_naciones_HC(---------------)////

///imprimir_lista_director(-----------)///




///downUser/////++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



///search_Id_pelicula(---------------)///








///upDirector/////++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/** \brief busca el nombre del director en el array
 *
 * \param director es el nombre del director
 * \param cant indica el tamanio del array a recorrer
 * \return retorna -1 si no hubo ocurrencia y si ocurrio la ocurrencia retorna i
 *
 */

int searchDirector (e_director* array,char director[], int cant)
{
    int retorno=-1;
    int i;

    for ( i=0;i<cant;i++)
    {
        if(array[i].id_estado=='F')
        {
            if(stricmp(array[i].dest_nombre,director)==0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief recorre el array id_director para encontrar el primer espacio vacio 'E' y crear un nuevo id
 *
 * \param vector_estado es el array en donde buscar
 * \param cant_director es tamanio del array a recorrer
 * \return retorna un nuevo id
 *
 */


int recorre_estado_director(e_director vector_estado[],int cant_director)
{
    int i;
    int mayor=0;

    for(i=0;i<cant_director;i++)
    {
        if(vector_estado[i].id_estado=='E')
        {
            mayor=max_id_director(vector_estado,cant_director)+1;
            break;
        }

    }

    return mayor;

}



///up_naciones_HC(--------------)///




///downDirector/////++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


///imprimir_lista_director(-----------------)///

///searchDirector(--------------)///









///cant_pelicula_y_cant_director/////++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int buscar_n_dire_max_peli(e_cant_pelicula* vector_cant_peli,int max_cant,int cant)
{
    int i;
    int retorno=-1;
    for(i=0;i<cant;i++)
    {
        if(vector_cant_peli[i].cant_pelicula==max_cant)
        {
            retorno=vector_cant_peli[i].id_director;
            break;
        }
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

int searchDirector_por_id(e_director* arrayD,int id_director,int cant)
{
    int retorno=-1;
    int i;
    for(i=0;i<cant;i++)
    {
        if(arrayD[i].id_director==id_director)
        {
            retorno=i;
        }
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

int buscar_n_dire_max_dire(e_cant_director* vector_cant_director,int max_cant,int cant)
{
    int i;
    int retorno=-1;
    for(i=0;i<cant;i++)
    {
        if(vector_cant_director[i].cant_directores==max_cant)
        {
            retorno=vector_cant_director[i].id_pelicula;
            break;
        }
    }
    return retorno;
}


///search_Id_pelicula(----------------)///
