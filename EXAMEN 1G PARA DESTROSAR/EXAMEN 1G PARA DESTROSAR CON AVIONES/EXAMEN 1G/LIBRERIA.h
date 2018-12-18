typedef struct{
    int hora;
    int minuto;
    int segundo;
}e_horario;


typedef struct
{
    int id_vuelo;/*noid*/
    e_horario hora;/*noid*/
    int id_aeropuerto_des;/***/
    int id_aeropuerto_orige;
    char id_estado;/***<----------------------------------estado*/

}e_vuelo;

typedef struct
{
    char matricula[50];
    int id_avion;/***/
    int id_modelo;
    char fabricante;
    int autonomia;/***/
    int capasidad_de_pasaje;
    char id_estado;/***<----------------------------------estado*/

}e_avion;

typedef struct
{
    int id_modelo;/***/
    char dest_modelo[321];/*noid*/
    char id_estado;/***<----------------------------------estado*/
}e_modelo;

typedef struct
{
    int id_vuelo;/***/
    int id_avion;/***/
    int id_modelo;
}e_relacion;


typedef struct
{
    int id_aeropuerto;/***/
    char dest_aeropuerto[321];/*noid*/
    char id_estado;/***<----------------------------------estado*/
}e_aeropuerto;

typedef struct
{
    int id_modelo;
    int cant_vuelo;

}e_cant_vuelo_mode;

typedef struct
{
    int id_avion;
    int cant_vuelo;

}e_cant_vuelo_avion;


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


int upAVION (e_avion* vec_avion,e_vuelo* vec_vuelo,e_modelo* vec_modelo, int indice,int cant);
int modifyData (e_avion* vec_avion,e_modelo* vec_modelo,int cant);
int downUser(e_avion* arrayavion,int cant);
int upVUELO(e_vuelo* arrayvuelo,e_avion* arrayavion,e_aeropuerto* arrayaeropuer,e_relacion* arrayrelacaion,int cant,int i);
int downvuelo(e_vuelo* arrayvuelo,e_avion* arrayavion,int cant);



int up_MODELO_HC(e_modelo* arraymodelo,int cant);
int recorre_estado_avion_crea_id(e_avion vector_estado[],int cant_peli);
int max_id_avion(e_avion* vector_id,int cant_id);
void imprimir_lista_modelo(e_modelo* vectormodelo,int tam);
int recorre_estado_modelo_crea_id(e_modelo* vector_estado,int cant_model);
int max_id_modelo(e_modelo* vector_id,int cant_id);
int search_Empty_modelo(e_modelo* arraymodelo, int cant);
int search_Id_avion(e_avion* arrayavion, int id,int cant);
void imprimir_lista_matricula(e_avion* vector_matricula,int tam);
int search_matricula_avion (e_avion* arraymatricula,char* matricula, int cant);
int recorre_estado_vuelo_crea_id(e_vuelo* vector_vuelo,int cant_vuelo);
int max_id_vuelo(e_vuelo* vector_id,int cant_id);
void imprimir_lista_Dmatriculaavion(e_avion* vectoravionmatri,int tam);
void imprimir_lista_aeropuerto(e_aeropuerto* vectoraeropuerto,int tam);
int recorre_estado_aeropuerto_crea_id(e_aeropuerto* vector_estado,int cant_aeropuerto);
int max_id_aeropuerto(e_aeropuerto* vector_id,int cant_id);
int search_Empty_aeropuerto(e_aeropuerto* arrayaeropuerto, int cant);
int up_aeropuerto_HC(e_aeropuerto* arrayaeropuerto,int cant);
int search_vuelo_id(e_vuelo* arrayvuelo,int* id_vuelo, int cant);

int search_Empty_vuelo (e_vuelo* arrayvuelo, int cant);
int search_Empty_avion(e_avion* arrayavion, int cant);
