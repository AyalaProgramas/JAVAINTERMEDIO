typedef struct{
    int segundos;
    int minutos;
    int hora;
}e_hora;


typedef struct
{
    int id_llamada;
    int id_motivo;
    int id_estado;

    int id_estado_empt;
    int id_abonado;
    e_hora tiempo_conclusion;

}e_llamada;

typedef struct
{
    int id_abonado;
    char dest_nombre[50];
    char dest_apellido[50];
    float dest_numero_tel;
    char id_estado_empt;

}e_abonado;

//typedef struct
//{
//    int id_director;
//    int id_pelicula;
//}e_relacion;




//typedef struct
//{
//    int id_director;
//    int cant_pelicula;
//
//}e_cant_pelicula;
//
//typedef struct
//{
//    int id_pelicula;
//    int cant_directores;
//
//}e_cant_director;


//void initStruct (e_video* arrayP,e_director* arrayD,e_nacion* arrayN,e_relacion* arrayR,int cant);///SI USE
//int upMovie (e_video* vec_pelicula,e_director* vec_director,e_nacion* vec_nacion,e_relacion* vec_relacion, int indice,int cant);///SI USE
//int search_Id_pelicula(e_video* arrayP, int id,int cant);///SI USE
//int modifyData (e_video* array,e_nacion* vec_naciones,e_director* vec_director,e_relacion* vec_relacion,int cant);///SI USE
//int downUser (e_video* array,int cant);///SI USE
//int searchEmptyP (e_video* array, int cant);///SI USE
//int searchEmptyD (e_director* array, int cant);///SI USE
//int upDirector(e_director* array,e_nacion* arrayN,int cant,int i);///SI USE
//int searchDirector (e_director* array,char director[], int cant);///SI USE
//int downDirector(e_director* array,int cant);///SI USE
////void maxMovie (e_director* array);
//void generateList(e_video* array);
//int upDirectorHC(e_director* array,e_nacion* arrayN,char* director,int cant);///SI USE
//int up_naciones_HC(e_nacion arrayN[],int cant);///SI USE
//void cant_pelicula_y_cant_director(e_relacion* arrayR,e_director* arrayD,e_cant_pelicula* array_cont_peli,e_video* arrayP,e_cant_director* array_cont_direc,int cant);///SI USE
//int buscar_n_dire_max_peli(e_cant_pelicula* vector_cant_peli,int max_cant,int cant);///SI USE
//int searchDirector_por_id(e_director* arrayD,int id_director,int cant);///SI USE
//int buscar_n_dire_max_dire(e_cant_director* vector_cant_director,int max_cant,int cant);///SI USE
//
////void recorre_estado_pelicula(e_video vector_estado[],int cant_peli);
////int max_id_pelicula(e_video* vector_id,int cant_id);
//int max_id_pelicula(e_video* vector_id,int cant_id);///SI USE
//int recorre_estado_pelicula(e_video vector_estado[],int cant_peli);///SI USE
//void imprimir_lista_pais(e_nacion* vectorpais,int tam);///SI USE
//void imprimir_lista_director(e_director* vectordirector,int tam);///SI USE
//int recorre_estado_nacion(e_nacion vector_estado[],int cant_nacio);///SI USE
//int max_id_nacion(e_nacion* vector_id,int cant_id);///SI USE
//int recorre_estado_director(e_director vector_estado[],int cant_director);///SI USE
//int max_id_director(e_director* vector_id,int cant_id);///SI USE


//int upMovie (e_video* vec_pelicula,e_director* vec_director,e_nacion* vec_nacion,e_relacion* vec_relacion, int indice,int cant);///SI USE
//int modifyData (e_video* array,e_nacion* vec_naciones,e_director* vec_director,e_relacion* vec_relacion,int cant);///SI USE
//int upDirector(e_director* array,e_nacion* arrayN,int cant,int i);///SI USE
//int downDirector(e_director* array,int cant);///SI USE
//int upDirectorHC(e_director* array,e_nacion* arrayN,char* director,int cant);///SI USE
//int up_naciones_HC(e_nacion arrayN[],int cant);///SI USE
//void cant_pelicula_y_cant_director(e_relacion* arrayR,e_director* arrayD,e_cant_pelicula* array_cont_peli,e_video* arrayP,e_cant_director* array_cont_direc,int cant);///SI USE
//
//
//
//
//void initStruct (e_video* arrayP,e_director* arrayD,e_nacion* arrayN,e_relacion* arrayR,int cant);///SI USE
//int search_Id_pelicula(e_video* arrayP, int id,int cant);///SI USE
//int downUser (e_video* array,int cant);///SI USE
//int searchEmptyP (e_video* array, int cant);///SI USE
//int searchEmptyD (e_director* array, int cant);///SI USE
//int searchDirector (e_director* array,char director[], int cant);///SI USE
//int buscar_n_dire_max_peli(e_cant_pelicula* vector_cant_peli,int max_cant,int cant);///SI USE
//int searchDirector_por_id(e_director* arrayD,int id_director,int cant);///SI USE
//int buscar_n_dire_max_dire(e_cant_director* vector_cant_director,int max_cant,int cant);///SI USE
//int max_id_pelicula(e_video* vector_id,int cant_id);///SI USE
//int recorre_estado_pelicula(e_video vector_estado[],int cant_peli);///SI USE
//void imprimir_lista_pais(e_nacion* vectorpais,int tam);///SI USE
//void imprimir_lista_director(e_director* vectordirector,int tam);///SI USE
//int recorre_estado_nacion(e_nacion vector_estado[],int cant_nacio);///SI USE
//int max_id_nacion(e_nacion* vector_id,int cant_id);///SI USE
//int recorre_estado_director(e_director vector_estado[],int cant_director);///SI USE
//int max_id_director(e_director* vector_id,int cant_id);///SI USE



