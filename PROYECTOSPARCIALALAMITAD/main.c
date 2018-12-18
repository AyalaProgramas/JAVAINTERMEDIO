#include <stdio.h>
#include <stdlib.h>
#define QTY 10

typedef struct
{
    int id;
    char nombre[20];
} eSector;

typedef struct
{
    int dia;
    int mes;
    int anio;

} eFecha;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    eFecha fechaIngreso;
    int idSector;
    int isEmpty;

} eEmpleado;

int menu();
void inicializarEmpleados(eEmpleado[], int);
void mostrarEmpleados(eEmpleado vec[], int tamEmp, eSector[],int);
void mostrarEmpleado(eEmpleado, eSector[], int);
int buscarLibre(eEmpleado[], int);
int buscarEmpleado(eEmpleado[], int, int);
void bajaEmpleado(eEmpleado[], int, eSector[], int);
void altaEmpleado(eEmpleado[], int, eSector[], int);
void modificacionEmpleado(eEmpleado[], int, eSector[], int);
void ordenarEmpleados(eEmpleado[], int);
float sueldoMaximo(eEmpleado[], int);
int pedirSector(eSector[], int);
void empleadosXSector(eEmpleado[], int, eSector[], int);
void CantidadEmpleadosXSector(eEmpleado[], int, eSector[], int);
void totalSueldosXSector(eEmpleado[], int, eSector[], int);
void totalSueldos(eEmpleado[], int);
void empleadosMejorPagos(eEmpleado[], int, eSector[], int);

int main()
{
    int salir = 0;
    eEmpleado gente[QTY]= {{1000, "Juan", 'm', 20000, {12, 5, 2015}, 5, 0},{2212, "Juana", 'f', 15000, {12, 5, 2010}, 3, 0},{5656, "Manuel", 'm', 18500, {12, 5, 2014}, 1, 0}, {3344, "Lucia", 'f', 23200, {2, 10, 2002}, 1, 0},{8658, "Alberto", 'm', 29500, {29, 3, 2008}, 1, 0},{5656, "Andrea", 'f', 34600, {12, 5, 2014}, 2, 0},{2121, "Gabriel", 'm', 34600, {12, 5, 2014}, 6, 0}};
    eSector sectores[]= {{1, "Ventas"}, {2,"Compras"}, {3, "Comercial"}, {4, "RRHH"}, {5, "Sistemas"}, {6, "Legales"}};
    inicializarEmpleados(gente, QTY);
    //harcodeo
    for(int i=0; i< QTY; i++)
    {
        gente[i].isEmpty = 0;
    }



    do
    {
        switch(menu())
        {

        case 1:
            altaEmpleado(gente, QTY, sectores, 6);
            system("pause");
            break;
        case 2:
            bajaEmpleado(gente, QTY, sectores, 6);
            system("pause");
            break;
        case 3:
            modificacionEmpleado(gente, QTY, sectores, 6);
            system("pause");
            break;
        case 4:
            mostrarEmpleados(gente, QTY, sectores, 6);
            system("pause");
            break;
        case 5:
            ordenarEmpleados(gente, QTY);
            system("pause");
            break;
        case 6:
            totalSueldos(gente, QTY);
            break;
        case 7:
            empleadosMejorPagos(gente, QTY, sectores, 6);
            break;
        case 8:
            empleadosXSector(gente, QTY, sectores, 6);
            break;
        case 9:
            CantidadEmpleadosXSector(gente, QTY, sectores, 6);
            break;
        case 10:
            totalSueldosXSector(gente, QTY, sectores, 6);
            break;
        case 11:
            printf("\nSalir\n\n");
            salir = 1;
            break;
        default:
            printf("\nOpcion Incorrecta\n\n");
            system("pause");
        }
    }
    while(salir != 1);

    return 0;
}

int menu()
{
    int opcion;

    system("cls");
    printf("      ---ABM Empleados---\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Ordenar\n");
    printf("6- Total sueldos\n");
    printf("7- Empleados que mas ganan\n");
    printf("8- Mostrar empleados x sector\n");
    printf("9- Informar cuantos empleados hay en cada sector\n");
    printf("10-Informar total de sueldos x Sector\n");
    printf("11-Salir\n");

    printf("\nIndique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


void inicializarEmpleados(eEmpleado arrayEmpleado[], int cantidad)
{
    int i;
    for(i=0; i< cantidad; i++)
    {
        arrayEmpleado[i].isEmpty =1;
    }
}

void mostrarEmpleados(eEmpleado arrayEmpleado[], int cantidadEmpleado, eSector arraySector[],int cantidadSector)
{
    int i;

    system("cls");
    printf("      ---Lista de Empleados---\n\n");
    printf("  Legajo  Nombre   Sexo   Sueldo   Fecha de Ingreso  Sector \n\n");
    for(i=0; i< cantidadEmpleado; i++)
    {
        if(arrayEmpleado[i].isEmpty == 0)
        {
            mostrarEmpleado(arrayEmpleado[i], arraySector, cantidadSector);
        }
    }
}

void mostrarEmpleado(eEmpleado arrayEmpleado, eSector arraySector[], int cantidad)
{
    int i;
    int indice;
    for(i=0; i< cantidad; i++)
    {
        if(arrayEmpleado.idSector == arraySector[i].id )
        {
            indice = i;
            break;
        }
    }
    printf("  %4d%12s     %c  %10.2f    %02d/%02d/%4d     %s\n", arrayEmpleado.legajo, arrayEmpleado.nombre, arrayEmpleado.sexo, arrayEmpleado.sueldo, arrayEmpleado.fechaIngreso.dia, arrayEmpleado.fechaIngreso.mes, arrayEmpleado.fechaIngreso.anio, arraySector[indice].nombre);
}

int buscarLibre(eEmpleado arrayEmpleado[], int cantidad)
{
    int i;
    int indice = -1;
    for(i=0; i < cantidad; i++)
    {
        if(arrayEmpleado[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


int buscarEmpleado(eEmpleado arrayEmpleado[], int cantidad, int legajo)
{
    int indice = -1;
    for(int i=0; i < cantidad; i++)
    {
        if(arrayEmpleado[i].isEmpty == 0 && arrayEmpleado[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void altaEmpleado(eEmpleado arrayEmpleado[], int cantidaEmpleado, eSector arraySector[], int cantidadSector)
{

    eEmpleado nuevoEmpleado;
    int indice;
    int esta;
    int legajo;

    system("cls");
    printf("---Alta empleado---\n\n");

    indice = buscarLibre(arrayEmpleado, cantidaEmpleado);

    if(indice == -1)
    {
        printf("\nEl sistema esta completo. No se puede dar de alta a empleados nuevos.\n\n");
    }
    else
    {
//        printf("Ingrese legajo: ");
//        scanf("%d", &legajo);
        getValidInt("ingrese legajo:","error,ingrese un legajo correcto",1,200);
        esta = buscarEmpleado(arrayEmpleado, cantidaEmpleado, legajo);

        if(esta != -1)
        {
            printf("\nEl legajo %d ya esta dado de alta en el sistema\n", legajo);
            mostrarEmpleado(arrayEmpleado[esta], arraySector, cantidadSector);
        }
        else
        {
            nuevoEmpleado.isEmpty = 0;
            nuevoEmpleado.legajo = legajo;

//            printf("Ingrese nombre: ");
//            fflush(stdin);
//            gets(nuevoEmpleado.nombre);
            getValidString("ingrese nombre:","error ingrese un nobre valido",nuevoEmpleado.nombre);
            nuevoEmpleado.sexo=getChar("ingrese sexo:");
            //getValidString("ingrese sexo:","error ingrese sexo",nuevoEmpleado.sexo);
//            printf("Ingrese sexo: ");
//            fflush(stdin);
//            scanf("%c", &nuevoEmpleado.sexo);

//            printf("Ingrese sueldo: ");
//            scanf("%f", &nuevoEmpleado.sueldo);
            nuevoEmpleado.sueldo=getValidFloat("ingrese sueldo:","error, ingrese un sexo valido",1,99999);
//            printf("Ingrese fecha de ingreso d m a: ");
//            scanf("%d %d %d", &nuevoEmpleado.fechaIngreso.dia, &nuevoEmpleado.fechaIngreso.mes, &nuevoEmpleado.fechaIngreso.anio);
            nuevoEmpleado.fechaIngreso.dia=getValidInt("ingrese dia:","error ingrese un dia correcto",1,31);
            nuevoEmpleado.fechaIngreso.mes=getValidInt("ingrese mes:","error ingrese un mes correcto",1,12);
            nuevoEmpleado.fechaIngreso.dia=getValidInt("ingrese dia:","error ingrese un anio correcto",2011,2040);

            nuevoEmpleado.idSector = pedirSector(arraySector, cantidadSector);
            arrayEmpleado[indice] = nuevoEmpleado;

            printf("\nAlta exitosa!!!\n\n");

        }
    }

}

void bajaEmpleado(eEmpleado arrayEmpleado[], int cantidadEmpleado, eSector arraySector[], int cantidadSector)
{
    int legajo;
    int esta;
    int confirma;

    system("cls");
    printf("---Baja Empleado---\n\n");

    legajo=getValidInt("ingrese legajo para dar de baja","error ingrese un legajo correcto",1,200);

    esta = buscarEmpleado(arrayEmpleado, cantidadEmpleado, legajo);

    if(esta == -1)
    {
        printf("\nEl legajo %d no se encuentra en el sistema\n\n", legajo);

    }
    else
    {

        mostrarEmpleado(arrayEmpleado[esta], arraySector, cantidadSector);

        confirma=verifyDosOption("\nConfirma baja?:");
//        printf("\nConfirma baja?: ");
//        fflush(stdin);
//        scanf("%c", &confirma);

        if(confirma == 0)
        {
            arrayEmpleado[esta].isEmpty = 1;
            printf("\nSe ha realizado la baja\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la baja\n\n");
        }

    }
}

void modificacionEmpleado(eEmpleado arrayEmpleado[], int cantidadEmpleado, eSector arraySector[], int cantidadSector)
{
    int legajo;
    int esta;
    int confirma;
    float sueldo;

    system("cls");
    printf("---Modificacion Empleado---\n\n");

    legajo=getValidInt("ingrese legajo para modificar:","error ingrese un legajo valido",1,200);
//    printf("Ingrese legajo: ");
//    scanf("%d", &legajo);

    esta = buscarEmpleado(arrayEmpleado, cantidadEmpleado, legajo);

    if(esta == -1)
    {
        printf("\nEl legajo %d no se encuentra en el sistema\n\n", legajo);

    }
    else
    {

        mostrarEmpleado(arrayEmpleado[esta], arraySector, cantidadEmpleado);

        sueldo=getValidInt("ingrese nuevo sueldo","error, ingrese unsueldo valido",1,99999);
        printf("\nIngrese nuevo sueldo: ");
        scanf("%f", &sueldo);

        confirma=verifyDosOption("\nConfirma Modificacion?: ");
//        printf("\nConfirma Modificacion?: ");
//        fflush(stdin);
//        scanf("%c", &confirma);

        if(confirma == 0)
        {
            arrayEmpleado[esta].sueldo = sueldo;
            printf("\nSe ha modificado el sueldo\n\n");
        }
        else
        {
            printf("\nSe ha cancelado la modificacion\n\n");
        }

    }
}

void ordenarEmpleados(eEmpleado arrayEmpleado[], int cantidad)
{

    eEmpleado auxEmpleado;

    for(int i=0; i< cantidad-1; i++)
    {
        for(int j=i +1; j< cantidad; j++)
        {
            if(arrayEmpleado[i].sexo > arrayEmpleado[j].sexo)
            {
                auxEmpleado = arrayEmpleado[i];
                arrayEmpleado[i] = arrayEmpleado[j];
                arrayEmpleado[j] = auxEmpleado;
            }
            else
            {
                if(arrayEmpleado[i].sexo == arrayEmpleado[j].sexo)
                {
                    if(strcmp(arrayEmpleado[i].nombre, arrayEmpleado[j].nombre)>0)
                    {
                        auxEmpleado = arrayEmpleado[i];
                        arrayEmpleado[i] = arrayEmpleado[j];
                        arrayEmpleado[j] = auxEmpleado;
                    }

                }

            }
        }
    }
    printf("\nSistema Ordenado\n\n");
}

float sueldoMaximo(eEmpleado arrayEmpleado[], int cantidad)
{

    float maxSueldo;
    int flag = 0 ;
    int i;

    for(i=0; i< cantidad; i++)
    {

        if( arrayEmpleado[i].sueldo > maxSueldo || flag == 0)
        {
            maxSueldo = arrayEmpleado[i].sueldo;
            flag = 1;
        }
    }
    return maxSueldo;
}




int pedirSector(eSector arraySector[], int cantidad)
{

    int idSector;

    printf("\nSectores\n\n");

    for(int i=0; i< cantidad; i++)
    {
        printf("%d- %s\n", arraySector[i].id, arraySector[i].nombre );
    }
    idSector=getValidInt("Indique sector:","error ingres un valor correcto",1,6);
//    printf("\nIndique Sector: ");
//    fflush(stdin);
//    scanf("%d", &idSector);

    return idSector;
}


void empleadosXSector(eEmpleado arrayEmpleado[], int cantidaEmpleado, eSector arraySector[], int cantidadSector)
{
    int i;
    int j;
    system("cls");
    printf("---Listado Empleados por Sector---\n\n");

    for(i=0; i< cantidaEmpleado; i++)
    {
        printf("-- %s --\n\n", arraySector[i].nombre);

        for(j=0; j < cantidaEmpleado; j++)
        {
            if(arrayEmpleado[j].idSector == arraySector[i].id)
            {
                mostrarEmpleado(arrayEmpleado[j], arraySector, cantidadSector);
            }
        }
        printf("\n-----------------------------------------------------------\n");
    }

    printf("\n\n");
    system("pause");

}

void CantidadEmpleadosXSector(eEmpleado arrayEmpleado[], int cantidadEmpleado, eSector arraySector[], int cantidadSector)
{

    int contador;
    system("cls");
    printf("---Listado Empleados por Sector---\n\n");
    int i;
    int j;
    for(i=0; i< cantidadSector; i++)
    {
        printf("-- %s --\n\n", arraySector[i].nombre);
        contador =0;

        for(j=0; j < cantidadEmpleado; j++)
        {
            if(arrayEmpleado[j].idSector == arraySector[i].id)
            {
                contador++;
            }
        }
        printf("Cantidad empleados: %d\n", contador);
        printf("\n-----------------------------------------------------------\n");
    }

    printf("\n\n");
    system("pause");

}

void totalSueldosXSector(eEmpleado arrayEmpleado[], int cantidadEmpleado, eSector arraySector[], int cantidadSector)
{
    int idSector;
    float acumulador = 0;
    system("cls");
    printf("---Total Sueldos por Sector---\n\n");

    idSector = pedirSector(arraySector, cantidadSector) - 1;


    printf("\n-- %s --\n\n", arraySector[idSector].nombre);

    for(int i=0; i< cantidadEmpleado; i++)
    {

        if(arrayEmpleado[i].idSector == arraySector[idSector].id)
        {
            acumulador += arrayEmpleado[i].sueldo;
        }
    }
    printf("Total sueldos $ %.2f\n\n", acumulador);
    system("pause");
}

void totalSueldos(eEmpleado arrayEmpleado[], int cantidadEmpleado){

float total = 0;
int i;

for(i=0; i< cantidadEmpleado; i++){
    total += arrayEmpleado[i].sueldo;
}

system("cls");
printf("\nEl total de sueldos es $ %.2f\n\n", total);

system("pause");
}

void empleadosMejorPagos(eEmpleado arrayEmpleados[], int cantidadEmpleados, eSector arraySector[], int cantidadSector){

    float sueldoMax;
    int flag=0;
    int i;

    for(i=0; i< cantidadEmpleados; i++){

    if(arrayEmpleados[i].sueldo > sueldoMax || flag == 0){
        sueldoMax = arrayEmpleados[i].sueldo;
        flag = 1;
    }
    }

     for(i=0; i< cantidadEmpleados; i++){

    if(arrayEmpleados[i].sueldo == sueldoMax){
        mostrarEmpleado(arrayEmpleados[i], arraySector, cantidadEmpleados);
    }

    }

    system("pause");

}

