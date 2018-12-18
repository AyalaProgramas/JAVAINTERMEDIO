#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "fParcialEmpleado.h"


//void inicializarEmpleado(eEmpleado arrayEmpleado[],int cantidad)
//{
//    int i;
//    for(i=0;i<cantidad;i++)
//    {
//        arrayEmpleado[i].isEmpty=1;
//    }
//}
//
//int buscarLibre(eEmpleado arrayEmpleado[],int cantidad)
//{
//    int i;
//    int indicelibre=-1;
//    for(i=0;i<cantidad;i++)
//    {
//        if(arrayEmpleado[i].isEmpty==1)
//        {
//            indicelibre=i;
//            break;
//        }
//    }
//
//    return indicelibre;
//}
//
//int buscarEmpleado(eEmpleado arrayempleado[],int cantidad,int legajo)
//{
//    int i;
//    int retorno=-1;
//
//    for(i=0;i<cantidad;i++)
//    {
//        if(arrayempleado[i].legajo==legajo)
//        {
//            retorno=i;
//        }
//    }
//
//    return retorno;
//}
//
//
//void altaEmpleado(eEmpleado arrayEmpleado[],int cantidad,eSector arraySector[],int cantidadSector)
//{
//    eEmpleado auxEmpleado;
//    int indice;
//    int esta;
//    int legajo;
//
//    system("cls");
//    printf("---Alta empleado---\n\n");
//
//    indice=buscarLibre(arrayEmpleado,cantidad);
//    if(indice==-1)
//    {
//        printf("\nEl sistema esta completo. No se puede dar de alta a empleados nuevos.\n\n");
//    }
//    else
//    {
//
//        legajo=getValidInt("ingrese legajo:","ingrese un legajo numero",1,1000);
//
//        esta=buscarEmpleado(arrayEmpleado,cantidad,legajo);
//
//        if(esta!=-1)
//        {
//            printf("\nEl legajo %d ya esta dado de alta en el sistema\n", legajo);
//
//        }
//        else
//        {
//            auxEmpleado.isEmpty=0;
//            auxEmpleado.legajo=legajo;
//
//            getValidString("ingrese nombre:","ingrese letra",auxEmpleado.nombre);
//            getValidAlfaNumerico("ingrese sexo:","ingrese letra",auxEmpleado.sexo);
//            getValidFloat("ingrese sueldo:","error ingrese numero",1,500000);
//            auxEmpleado.fechanacimiento.dia=getValidInt("ingrese dia fecha de ingresado:","ingrese un numero",1,31);
//            auxEmpleado.fechanacimiento.mes=getValidInt("ingrese mes fecha de ingresado:","ingrese un numero",1,12);
//            auxEmpleado.fechanacimiento.anio=getValidInt("ingrese anio fecha de ingresado:","ingrese un numero",2000,2100);
//
//
//
//        }
//    }
//
//}
