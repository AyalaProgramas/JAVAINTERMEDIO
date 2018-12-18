
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

void initStruct (e_avion* arrayP,e_vuelo* arrayD,e_aeropuerto* arrayN,e_modelo* arrayR,int cant)
{
    int i;

    for (i=0;i<cant;i++)
    {
        arrayD[i].id_estado='E';
        arrayP[i].id_estado='E';
        arrayN[i].id_estado='E';
        arrayR[i].id_estado='E';

    }
}



///falta cambiar
/** \brief se ingresa los datos del avion
 *
 * \param vec_avion
 * \param vec_vuelo
 * \param vec_modelo
 * \param indice
 * \param cant
 * \return retorna -1 si no se enigreso el dato si no retorna 0
 *
 */

int upAVION (e_avion* vec_avion,e_vuelo* vec_vuelo,e_modelo* vec_modelo, int indice,int cant)
{
    system("cls");
    char auxfabricante[255];///auxtitulo
    char auxautonomia[255];///anio
    char auxcapasidad[255];
    char auxmatricula[255];
    int flagDate=0;

    int empty;
    int flagfabricante=0;
    int flagautonomia=0;
    int flagcapasidad=0;
    int flagmodelo=0;
    int flagmatricula=0;
    int flagavion=0;
    int retorno=-1;
    int id_avion;///id_pelicula
    char opcion_pais;
    int id_modelo;
    int id_director;
    char seguir='n';
    int indice_relacion;

    printf("Ingrese la matricula del el avion:");
    fflush(stdin);
    gets(auxfabricante);
    if(verifyArrayAlphaNum(auxmatricula,1,49)==0)
    {
        flagmatricula=1;
    }
    else
        printf("ERROR");
    if(flagmatricula)
    {
        printf("Ingrese fabricante del el avion:");///titulo
        fflush(stdin);
        gets(auxfabricante);
        if(verifyArrayAlphaNum(auxfabricante,1,49)==0)
        {
            flagfabricante=1;
        }
        else
            printf("ERROR");
    }




    if(flagfabricante)
    {
        while(flagDate==0)
        {
            printf("Ingrese autnomia: ");
            fflush(stdin);
            gets(auxautonomia);
            if(verifyArrayNum(auxautonomia,2,2)==0)
            {
                if(verifyDate(atoi(auxautonomia),0,24)==0)
                {
                    flagautonomia=1;
                    flagDate=1;
                }
            }
        }

    }
    else
        printf("ERROR");

    if(flagautonomia)
    {
        while(flagDate==0)
        {
            printf("Ingrese capasidad de pasajeros: ");
            fflush(stdin);
            gets(auxcapasidad);
            if(verifyArrayNum(auxcapasidad,4,4)==0)
            {
                if(verifyDate(atoi(auxcapasidad),2,1000)==0)
                {
                    flagcapasidad=1;
                    flagDate=1;
                }
            }
        }

    }
    else
        printf("ERROR");







    if(flagcapasidad)
    {
       id_modelo=up_MODELO_HC(vec_modelo,cant);
       flagmodelo=1;

    }
    else
        printf("ERROR");


    if(flagmodelo)
    {
        id_avion=recorre_estado_avion_crea_id(vec_avion,cant);
        flagavion=1;
    }
    else
        printf("ERROR");






//    if(flagavion)
//    {
//        do
//        {
//
//            imprimir_lista_director(vec_director,cant);
//            printf("\nse encuentra el director en la lista <s>/<n>\n");
//            fflush(stdin);
//            opcion_pais=getchar();
//
//            if(opcion_pais!='s')
//            {
//
//                empty=searchEmptyD(vec_director,cant);
//                if(empty!=-1)
//                {
//                    printf("Ingrese nombre del director: ");
//                    fflush(stdin);
//                    gets(auxDirec);
//                    id_director=upDirectorHC(vec_director,vec_nacion,auxDirec,cant);
//                    if(id_director!=0)
//                    {
//                        printf("Se ha registrado al director, gracias.\n");
//                        flagDirec=1;
//                    }
//                    else
//                        printf("Error al cargar\n");
//                }
//                else
//                    printf("No hay mas lugar\n");
//
//            }
//            else
//            {
//                if(get_string_numero("ingrese la opcion de directores",auxDirec))
//                {
//                    id_director=atoi(auxDirec);
//                    flagDirec=1;
//                }
//
//
//            }
//            indice_relacion=searchEmptyR(vec_relacion,cant);
//            vec_relacion[indice_relacion].id_director=id_director;
//            vec_relacion[indice_relacion].id_pelicula=id_pelicula;
//
//            printf("desea seguir ingresando directores en la pelicula presione <s> si no <n>\n");
//            fflush(stdin);
//            seguir=getchar();
//        }while(seguir=='s');
//    }
//    else
//        printf("ERROR");

    if(flagavion)
    {
        strcpy(vec_avion[indice].fabricante,auxfabricante);
        strcpy(vec_avion[indice].matricula,auxmatricula);
        vec_avion[indice].id_avion=id_avion;
        vec_avion[indice].autonomia=atoi(auxautonomia);
        vec_avion[indice].capasidad_de_pasaje=atoi(auxcapasidad);
        vec_avion[indice].id_estado='F';
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



int modifyData (e_avion* vec_avion,e_modelo* vec_modelo,int cant)
{
    int flag_id_modificar;
    int id_modelo;
    int id_director;
    int busqueda_de_id;
    char orige_director[200];
    //int atoi_direc_cambiar;
    int i;
    int retorno=-1;
    int opcion;
    char orige_id_avion[10];
    char auxiliar[255];
    int flag;

    int continuar=1;


    imprimir_lista_matricula(vec_avion,cant);
    if(get_string_numero("ingrese numero la id del avion para modificar",orige_id_avion))
    {
        flag_id_modificar=1;
    }
    busqueda_de_id=search_Id_avion(vec_avion,cant,atoi(orige_id_avion));
    if(flag_id_modificar&&busqueda_de_id!=-1)
    {
        printf("MODIFICAR\n");

        while(continuar)
        {
            opcion=menu_generico("1.fabricante\n2.capasidad\n3.modelo\n4.autonomia\n",1,5);

                switch(opcion)
                {
                case 1:
                    system("cls");
                    flag=0;
                    while(flag==0)
                    {
                        printf("Ingrese nuevo fabricante: ");
                        gets(auxiliar);
                        if(verifyArrayAlpha(auxiliar,1,20)==0)
                        {
                            flag=1;
                            strcpy(vec_avion[busqueda_de_id].fabricante,auxiliar);
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
                        printf("Ingrese el nueva capasidad: ");
                        gets(auxiliar);
                        if(verifyArrayNum(auxiliar,1,6)==0)
                        {
                            flag=1;
                            vec_avion[busqueda_de_id].capasidad_de_pasaje=atoi(auxiliar);
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
                       id_modelo=up_MODELO_HC(vec_modelo,cant);

                       vec_avion[busqueda_de_id].id_modelo=id_modelo;
                       flag=1;

                    }
                    retorno=0;
                    break;
                case 4:
                    system("cls");
                    flag=0;
                    while(flag==0)
                    {
                        printf("Ingrese autnomia: ");
                        fflush(stdin);
                        gets(auxiliar);
                        if(verifyArrayNum(auxiliar,2,2)==0)
                        {
                            if(verifyDate(atoi(auxiliar),0,24)==0)
                            {
                                vec_avion[busqueda_de_id].autonomia=atoi(auxiliar);
                                flag=1;
                            }
                        }
                    }
//                    while(flag==0)
//                    {
//                        imprimir_lista_director(vec_director,cant);
//                        if(get_string_letras("Ingrese la opcion del nuevo director: ",orige_director))
//                        {
//                            flag=1;
//                        }
//                        id_director=upDirectorHC(vec_director,vec_naciones,orige_director,cant);
//
//                        ///mostra directores qu e hicieron la pelicula
//                        imprimir_lista_director(vec_director,cant);
//
//                        if(get_string_letras("Ingrese el director que quiere cambiar",orige_director))
//                        {
//                            flag=1;
//                        }
//                        atoi_direc_cambiar=atoi(orige_director);
//
//                        for(i=0;i<cant;i++)
//                        {
//                            if(vec_relacion[i].id_pelicula==orige_id_pelicula&&vec_relacion[i].id_director==atoi_direc_cambiar)
//                            {
//                                vec_relacion[i].id_director=id_director;
//
//                                flag=1;
//                                break;
//                            }
//                        }
//
//
//                    }
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

int downUser(e_avion* arrayavion,int cant)
{
    int retorno=-1;
    char id_para_dar_baja[10];
    int i;

    imprimir_lista_matricula(arrayavion,cant);
    if(get_string_numero("ingrese el id del avion para dar de baja",id_para_dar_baja))
    {
        i=search_Id_avion(arrayavion,cant,atoi(id_para_dar_baja));
        if(i!=-1)
        {
            printf("Acaba de dar de baja el avion DE matricula:\n%s\nID: %d\n",arrayavion[i].matricula,arrayavion[i].id_avion);
            arrayavion[i].id_estado='D';
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
 * \param
 * \param
 * \param
 * \param
 * \return
 *
 */


int upVUELO(e_vuelo* arrayvuelo,e_avion* arrayavion,e_aeropuerto* arrayaeropuer,e_relacion* arrayrelacaion,int cant,int i)
{
    int id_vuelo;
    int id_aeropuerto_orige;
    int id_aeropuerto_desti;
    int retorno=-1;
    int flagmatricula=0;
    int flagaeropuertoorige=0;
    int flagaeropuertodesti=0;
    int flaghorario=0;
    char auxmatricula[255];
//    char auxNacio[255];
//    char auxFecha[255];
    int auxseg;
    int auxmin;
    int auxhora;
    char opcion_matricula;
    int opcion_id_matri;
    int id_matricula;

    printf("lista de matricula de avion:\n");
    imprimir_lista_Dmatriculaavion(arrayavion,cant);
    printf("se encuentra la matriclua del avion?s:<SI>/n:<N>\n");
    fflush(stdin);
    opcion_matricula=getchar();
    if(opcion_matricula=='s')
    {
        printf("inngrese la opcion:\n");
        scanf("%d",&opcion_id_matri);
        id_matricula=opcion_id_matri;
        flagmatricula=1;
    }
    else
    {
        if(get_string_letras("ingrese la nueva matricula del avion",auxmatricula))
        {
        if(search_matricula_avion(arrayavion,auxmatricula,cant)==-1)
            {
            flagmatricula=1;
            id_vuelo=recorre_estado_vuelo_crea_id(arrayvuelo,cant);

            }
            else
                printf("El avion ya se encuentra registado");
        }
        else
            printf("ERROR");
    }



    if(flagmatricula)
    {
        printf("ORIGEN DEL VUELO\n");
        id_aeropuerto_orige=up_aeropuerto_HC(arrayaeropuer,cant);
        flagaeropuertoorige=1;

    }
    if(flagaeropuertoorige)
    {
        printf("DESTINO DEL  VUELO\n");
        id_aeropuerto_desti=up_aeropuerto_HC(arrayaeropuer,cant);
        flagaeropuertodesti=1;

    }
    if(flagaeropuertodesti)
    {
        if(getDatehora(&auxseg,&auxmin,&auxhora)==0)
            flaghorario=1;

    }
    if(flaghorario)
    {
        //strcpy(arrayvuelo[i].,auxmatricula);
        arrayvuelo[i].id_aeropuerto_des=id_aeropuerto_desti;
        arrayvuelo[i].id_aeropuerto_orige=id_aeropuerto_orige;
        arrayvuelo[i].hora.segundo=auxseg;
        arrayvuelo[i].hora.minuto=auxmin;
        arrayvuelo[i].hora.hora=auxhora;
        arrayvuelo[i].id_vuelo=id_vuelo;
        arrayvuelo[i].id_estado='F';
        retorno=0;
    }
    return retorno;
}










//int upDirectorHC(e_director* array,e_nacion* arrayN,char* director,int cant)
//{
//
//    int flagDirec=1;
//    int flagNacio=0;
//    int flagFecha=0;
//    int auxseg=0;
//    int auxmin=0;
//    int auxhora=0;
//    int empty;
//    int id_nacion;
//    int id_director=0;
//
//    id_director=recorre_estado_director(array,cant);
//    printf("nombre del director: %s\n",director);
//    if(flagDirec)
//    {
//          id_nacion=up_naciones_HC(arrayN,cant);
//          flagNacio=1;
//    }
//    if(flagNacio)
//    {
//        if(getDate(&auxseg,&auxhora,&auxhora)==0)
//            flagFecha=1;
//
//    }
//    empty=searchEmptyD(array,cant);
//    if(flagFecha)
//    {
//        strcpy(array[empty].dest_nombre,director);
//        array[empty].id_nacionalidad=id_nacion;
//        array[empty].fechanacimiento.dia=auxDia;
//        array[empty].fechanacimiento.mes=auxMes;
//        array[empty].fechanacimiento.ano=auxAno;
//        array[empty].id_director=id_director;
//        array[empty].id_estado='F';
//    }
//    return id_director;
//}








///crea una lista para ingresar un modelo como opcion retor la opcion elegida
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int up_MODELO_HC(e_modelo* arraymodelo,int cant)
{

            int opcion_modelo;
            char auxmodelo[50];
            int atoi_id_modelo;

            int empty;
            int id_modelo;



            printf("\nOPCIONES DE MODELOS:\n");
            imprimir_lista_modelo(arraymodelo,cant);
            printf("se encuentra el MODELO en la lista ingrese s:<SI>  n:<NO>\n");
            fflush(stdin);
            opcion_modelo=getchar();
            if(opcion_modelo=='s')
            {
                if(get_string_numero("ingrese la opcion del modelo:",auxmodelo))
                {
                    id_modelo=atoi(auxmodelo);
                }
            }
            else
            {
                id_modelo=recorre_estado_modelo_crea_id(arraymodelo,cant);


                empty=search_Empty_modelo(arraymodelo,cant);

                if(get_string_letras("ingrese el nuevo modelo a la lista:",auxmodelo))
                {
                    strcpy(arraymodelo[empty].dest_modelo,auxmodelo);
                    arraymodelo[empty].id_estado='F';
                    arraymodelo[empty].id_modelo=id_modelo;
                }

            }

        return id_modelo;

}









/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int downvuelo(e_vuelo* arrayvuelo,e_avion* arrayavion,int cant)
{
    int retorno=-1;
    char auxiliar_id_vuelo[255];
    char auxiliar_matricula[255];
    int i_id;
    int i_matricula;
    int continuar=1;
    printf("DAR DE BAJA\nlista de vuelos:\n");
    //imprimir_lista_director(array,cant);
    printf("Ingres el id del vuelo: ");
    fflush(stdin);
    gets(auxiliar_id_vuelo);
    printf("Ingres matricula del avion: ");
    fflush(stdin);
    gets(auxiliar_matricula);
    i_id=search_vuelo_id(arrayvuelo,atoi(auxiliar_id_vuelo),cant);
    i_matricula=search_matricula_avion(arrayavion,auxiliar_matricula,cant);
    if(i_id!=-1&&i_matricula!=-1)
    {
        printf("vuelo: %s\n",arrayvuelo[i_id].id_vuelo);
        //printf("Nacionalidad: %d\n",array[i].id_nacionalidad);
        continuar=verifyYorN();
        if(continuar==0)
        {
            arrayvuelo[i_id].id_estado='D';
            arrayavion[i_matricula].id_estado='D';
            retorno=0;
        }
        else
            printf("Hasta luego.");
    }
    else
        printf("\nEl vuelo y la matricula no se encuentra registado.\n");
    return retorno;
}










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











//
//
//
//
//
//
//
//
//
//
//
//
//int searchEmptyR (e_relacion* array, int cant)
//{
//    int retorno=-1;
//    int i;
//
//        for ( i=0;i<cant;i++)
//        {
//            if(array[i].id_director=='E')
//            {
//                retorno=i;
//                break;
//            }
//        }
//    return retorno;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//int searchEmptyP (e_video* array, int cant)
//{
//    int retorno=-1;
//    int i;
//
//        for ( i=0;i<cant;i++)
//        {
//            if(array[i].id_estado=='E')
//            {
//                retorno=i;
//                break;
//            }
//        }
//    return retorno;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//int searchDirector (e_director* array,char director[], int cant)
//{
//    int retorno=-1;
//    int i;
//
//    for ( i=0;i<cant;i++)
//    {
//        if(array[i].id_estado=='F')
//        {
//            if(stricmp(array[i].dest_nombre,director)==0)
//            {
//                retorno=i;
//                break;
//            }
//        }
//    }
//    return retorno;
//}
//
//
//
//
//
//
//
//
//
//int searchEmptyD (e_director* array, int cant)
//{
//    int retorno=-1;
//    int i;
//
//        for ( i=0;i<cant;i++)
//        {
//            if(array[i].id_estado=='E')
//            {
//                retorno=i;
//                break;
//            }
//        }
//    return retorno;
////}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//int buscar_n_dire_max_peli(e_cant_pelicula* vector_cant_peli,int max_cant,int cant)
//{
//    int i;
//    int retorno=-1;
//    for(i=0;i<cant;i++)
//    {
//        if(vector_cant_peli[i].cant_pelicula==max_cant)
//        {
//            retorno=vector_cant_peli[i].id_director;
//            break;
//        }
//    }
//    return retorno;
//}
//
//
//
//
//
//
//
//
//
//
//int searchDirector_por_id(e_director* arrayD,int id_director,int cant)
//{
//    int retorno=-1;
//    int i;
//    for(i=0;i<cant;i++)
//    {
//        if(arrayD[i].id_director==id_director)
//        {
//            retorno=i;
//        }
//    }
//    return retorno;
//}
//
//
//
//
//
//
//
//
//int buscar_n_dire_max_dire(e_cant_director* vector_cant_director,int max_cant,int cant)
//{
//    int i;
//    int retorno=-1;
//    for(i=0;i<cant;i++)
//    {
//        if(vector_cant_director[i].cant_directores==max_cant)
//        {
//            retorno=vector_cant_director[i].id_pelicula;
//            break;
//        }
//    }
//    return retorno;
//}








/*************************************************************/






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















//void imprimir_lista_director(e_director* vectordirector,int tam)
//{
//    int i;
//    for(i=0;i<tam;i++)
//    {
//        if(vectordirector[i].id_estado=='F')
//        {
//            printf("%d-%s\n",vectordirector[i].id_director,vectordirector[i].dest_nombre);
//
//        }
//
//    }
//
//}













///upavion///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

///2///
///recorre array estado de modelo  y encuentra el primer empty para crear un nuevo id retorna un nuevo id

/** \brief recorre el array id_estado para encontrar el primer espacio vacio 'E' y crear un nuevo id
 *
 * \param vector_estado es el array en donde buscar
 * \param cant_peli es cantidad de veces que va recorrer el id:estado
 * \return retorna un nuevo id
 *
 */

int recorre_estado_avion_crea_id(e_avion vector_estado[],int cant_peli)///
{
    int i;
    int mayor=0;

    for(i=0;i<cant_peli;i++)
    {
        if(vector_estado[i].id_estado=='E')
        {
            mayor=max_id_avion(vector_estado,cant_peli)+1;
            break;
        }

    }

    return mayor;

}


///2///
///recorre el array modelo  buscado en el array id_modelo para encontrar el mayor

/** \brief  recorre el array id_avion para encontar el mayor id_avion
 *
 * \param vector_id es el array en donde buscar
 * \param  cant_id es la cantidad de veces que va iterar el for
 * \return retorna el mayor id_avion del array
 *
 */

int max_id_avion(e_avion* vector_id,int cant_id)///
{
    int i;
    int mayor=0;
    for(i=0;i<cant_id;i++)
    {
        if(vector_id[i].id_estado=='F')
        {
            if(vector_id[i].id_avion>mayor)
            {
                mayor=vector_id[i].id_avion;

            }

        }
    }

    return mayor;
}




///up_MODELO_HC///1///
///1///imprime array modelo avion
/** \brief imprime una lista de la cantidad de modelos de aviones
 *
 * \param vectormodelo es el array en donde buscar
 * \param tam es el tamanio del array a recorrer
 *
 */

void imprimir_lista_modelo(e_modelo* vectormodelo,int tam)///
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(vectormodelo[i].id_estado=='F')
        {
            printf("%d-%s\n",vectormodelo[i].id_modelo,vectormodelo[i].dest_modelo);

        }

    }

}


///1///
///recorre array estado de modelo  y encuentra el primer empty para crear un nuevo id
/** \brief recorre el array id_estado para encontrar el primer espacio vacio 'E' y crear un nuevo id
 *
 * \param vector_estado es el array en donde buscar
 * \param cant_model es tamanio del array a recorrer
 * \return retorna un nuevo id
 *
 */

int recorre_estado_modelo_crea_id(e_modelo* vector_estado,int cant_model)///
{
    int i;
    int mayor=0;

    for(i=0;i<cant_model;i++)
    {
        if(vector_estado[i].id_estado=='E')
        {
            mayor=max_id_modelo(vector_estado,cant_model)+1;
            break;
        }

    }

    return mayor;

}


///1///
///recorre el array modelo  buscado en el array id_modelo para encontrar el mayor
/** \brief  recorre el array id_modelo para encontar el mayor id_modelo
 *
 * \param vector_id es el array en donde buscar
 * \param  cant_id es el tamanio del array a recorrer
 * \return retorna el mayor id_modelo del array
 *
 */
int max_id_modelo(e_modelo* vector_id,int cant_id)///
{
    int i;
    int mayor=0;
    for(i=0;i<cant_id;i++)
    {
        if(vector_id[i].id_estado=='F')
        {
            if(vector_id[i].id_modelo>mayor)
            {
                mayor=vector_id[i].id_modelo;

            }

        }
    }

    return mayor;
}

///1///
///recorre el id_estado para saber cual esta vacio com empty 'E' retorna indice
/** \brief busca el primer lugar no utilisado en el array
 *
 * \param arraymodelo es el array en donde buscar
 * \param cant es el tamanio del array a recorrer
 * \return  retorna -1 si no hay ocurrencia y si la hay retorna la posicion i
 *
 */

int search_Empty_modelo(e_modelo* arraymodelo, int cant)///
{
    int retorno=-1;
    int i;

        for ( i=0;i<cant;i++)
        {
            if(arraymodelo[i].id_estado=='E')
            {
                retorno=i;
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

int search_Empty_avion(e_avion* arrayavion, int cant)
{
    int retorno=-1;
    int i;

        for ( i=0;i<cant;i++)
        {
            if(arrayavion[i].id_estado=='E')
            {
                retorno=i;
                break;
            }
        }
    return retorno;
}


///modificdata///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
///  downUser
///1//
///busca id del avion para modificar//
/** \brief busca el id en el array
 *
 * \param arrayavion es el array en donde buscar
 * \param id es el id ingresado para buscar en el arrayavion
 * \param cant es el tamanio del array a recorrer
 * \return retorna -1 si no hay ocurrencia y si la hay retorna i
 *
 */

int search_Id_avion(e_avion* arrayavion, int id,int cant)///
{
    int retorno=-1;
    int i;
    for ( i=0;i<cant;i++)
    {
        if(arrayavion[i].id_avion==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

///imprime matricula delos aviones
/** \brief imprime una lista de la cantidad de matriculas de aviones
 *
 * \param vector_matricula es el array en donde buscar
 * \param tam es el tamanio del array a recorrer
 *
 */

void imprimir_lista_matricula(e_avion* vector_matricula,int tam)///
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(vector_matricula[i].id_estado=='F')
        {
            printf("%d-%s\n",vector_matricula[i].id_avion,vector_matricula[i].matricula);

        }

    }

}


///upVUELO///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

int search_Empty_vuelo (e_vuelo* arrayvuelo, int cant)
{
    int retorno=-1;
    int i;

        for ( i=0;i<cant;i++)
        {
            if(arrayvuelo[i].id_estado=='E')
            {
                retorno=i;
                break;
            }
        }
    return retorno;

}





/** \brief busca la matricula en el array
 *
 * \param arraymatricula es el array en donde buscar
 * \param matricula es la matricula ingresado para buscar en el arraymatricula
 * \param cant es el tamanio del array a recorrer
 * \return retorna -1 si no hay ocurrencia y si la hay retorna i
 *
 */
int search_matricula_avion (e_avion* arraymatricula,char* matricula, int cant)///
{
    int retorno=-1;
    int i;

    for ( i=0;i<cant;i++)
    {
        if(arraymatricula[i].id_estado=='F')
        {
            if(stricmp(arraymatricula[i].matricula,matricula)==0)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief recorre el array id_estado para encontrar el primer espacio vacio 'E' y crear un nuevo id
 *
 * \param vector_estado es el array en donde buscar
 * \param cant_vuelo es tamanio del array a recorrer
 * \return retorna un nuevo id
 *
 */

int recorre_estado_vuelo_crea_id(e_vuelo* vector_vuelo,int cant_vuelo)///
{
    int i;
    int mayor=0;

    for(i=0;i<cant_vuelo;i++)
    {
        if(vector_vuelo[i].id_estado=='E')
        {
            mayor=max_id_vuelo(vector_vuelo,cant_vuelo)+1;
            break;
        }

    }

    return mayor;

}
/** \brief  recorre el array id_vuelo para encontar el mayor id_vuelo
 *
 * \param vector_id es el array en donde buscar
 * \param  cant_id es el tamanio del array a recorrer
 * \return retorna el mayor id_vuelo del array
 *
 */
int max_id_vuelo(e_vuelo* vector_id,int cant_id)///
{
    int i;
    int mayor=0;
    for(i=0;i<cant_id;i++)
    {
        if(vector_id[i].id_estado=='F')
        {
            if(vector_id[i].id_vuelo>mayor)
            {
                mayor=vector_id[i].id_vuelo;

            }

        }
    }

    return mayor;
}
/** \brief imprime una lista de la cantidad de matriculas de aviones
 *
 * \param vector_matricula es el array en donde buscar
 * \param tam es el tamanio del array a recorrer
 *
 */
void imprimir_lista_Dmatriculaavion(e_avion* vectoravionmatri,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(vectoravionmatri[i].id_estado=='F')
        {
            printf("%d-%s\n",vectoravionmatri[i].id_avion,vectoravionmatri[i].matricula);

        }

    }

}




/** \brief imprime una lista de la cantidad de aeropuertos
 *
 * \param vectoraeropuerto es el array en donde buscar
 * \param tam es el tamanio del array a recorrer
 *
 */

void imprimir_lista_aeropuerto(e_aeropuerto* vectoraeropuerto,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(vectoraeropuerto[i].id_estado=='F')
        {
            printf("%d-%s\n",vectoraeropuerto[i].id_aeropuerto,vectoraeropuerto[i].dest_aeropuerto);

        }

    }

}
/** \brief recorre el array id_estado para encontrar el primer espacio vacio 'E' y crear un nuevo id
 *
 * \param vector_estado es el array en donde buscar
 * \param cant_aeropuerto es tamanio del array a recorrer
 * \return retorna un nuevo id
 *
 */
int recorre_estado_aeropuerto_crea_id(e_aeropuerto* vector_estado,int cant_aeropuerto)
{
    int i;
    int mayor=0;

    for(i=0;i<cant_aeropuerto;i++)
    {
        if(vector_estado[i].id_estado=='E')
        {
            mayor=max_id_aeropuerto(vector_estado,cant_aeropuerto)+1;
            break;
        }

    }

    return mayor;

}

/** \brief  recorre el array vector_id para encontar el mayor id_aeropuerto
 *
 * \param vector_id es el array en donde buscar
 * \param  cant_id es el tamanio del array a recorrer
 * \return retorna el mayor id_vuelo del array
 *
 */
int max_id_aeropuerto(e_aeropuerto* vector_id,int cant_id)
{
    int i;
    int mayor=0;
    for(i=0;i<cant_id;i++)
    {
        if(vector_id[i].id_estado=='F')
        {
            if(vector_id[i].id_aeropuerto>mayor)
            {
                mayor=vector_id[i].id_aeropuerto;

            }

        }
    }

    return mayor;
}
/** \brief busca el primer lugar no utilisado en el array
 *
 * \param arrayaeropuerto es el array en donde buscar
 * \param cant es el tamanio del array a recorrer
 * \return  retorna -1 si no hay ocurrencia y si la hay retorna la posicion i
 *
 */

int search_Empty_aeropuerto(e_aeropuerto* arrayaeropuerto, int cant)
{
    int retorno=-1;
    int i;

        for ( i=0;i<cant;i++)
        {
            if(arrayaeropuerto[i].id_estado=='E')
            {
                retorno=i;
                break;
            }
        }
    return retorno;
}




















/** \brief ingresa un nuevo aeropuerto al array estructura o selecciona un aeropuerto de la lista del array estructura
 *
 * \param arrayaeropuerto es
 * \param cant es el tamanio del array a recorrer
 * \return retorna el id_aeropuerto
 *
 */



int up_aeropuerto_HC(e_aeropuerto* arrayaeropuerto,int cant)
{

            int opcion_aeropuerto;
            char auxaeropuerto[50];
            int atoi_id_aeropuerto;

            int empty;
            int id_aeropuerto;



            printf("\nOPCIONES DE aeropuerto:\n");
            imprimir_lista_aeropuerto(arrayaeropuerto,cant);
            printf("se encuentra el aeropuerto en la lista ingrese s:<SI>  n:<NO>\n");
            fflush(stdin);
            opcion_aeropuerto=getchar();
            if(opcion_aeropuerto=='s')
            {
                if(get_string_numero("ingrese la opcion del aeropuerto:",auxaeropuerto))
                {
                    id_aeropuerto=atoi(auxaeropuerto);
                }
            }
            else
            {
                id_aeropuerto=recorre_estado_aeropuerto_crea_id(arrayaeropuerto,cant);


                empty=search_Empty_aeropuerto(arrayaeropuerto,cant);

                if(get_string_letras("ingrese el nuevo aeropuerto a la lista:",auxaeropuerto))
                {
                    strcpy(arrayaeropuerto[empty].dest_aeropuerto,auxaeropuerto);
                    arrayaeropuerto[empty].id_estado='F';
                    arrayaeropuerto[empty].id_aeropuerto=id_aeropuerto;
                }

            }

        return id_aeropuerto;

}







///downvuelo///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/** \brief busca el id_vuelo en el array
 *
 * \param arrayvuelo es el array en donde buscar
 * \param id_vuelo es la id_vuelo ingresado para buscar en el arrayvuelo
 * \param cant es el tamanio del array a recorrer
 * \return retorna -1 si no hay ocurrencia y si la hay retorna i
 *
 */

int search_vuelo_id(e_vuelo* arrayvuelo,int* id_vuelo, int cant)
{
    int retorno=-1;
    int i;

    for ( i=0;i<cant;i++)
    {
        if(arrayvuelo[i].id_estado=='F')
        {
            if(arrayvuelo[i].id_vuelo==id_vuelo)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

///------------------///
///search_matricula_avion()
///------------------///






///downvuelo///++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++







//int recorre_estado_director(e_director vector_estado[],int cant_director)
//{
//    int i;
//    int mayor=0;
//
//    for(i=0;i<cant_director;i++)
//    {
//        if(vector_estado[i].id_estado=='E')
//        {
//            mayor=max_id_director(vector_estado,cant_director)+1;
//            break;
//        }
//
//    }
//
//    return mayor;
//
//}










//int max_id_director(e_director* vector_id,int cant_id)
//{
//    int i;
//    int mayor=0;
//    for(i=0;i<cant_id;i++)
//    {
//        if(vector_id[i].id_estado=='F')
//        {
//            if(vector_id[i].id_director>mayor)
//            {
//                mayor=vector_id[i].id_director;
//
//            }
//
//        }
//    }
//
//    return mayor;
//}


