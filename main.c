#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "claretlib.h"
#include "claretarray.h"



int main()
{
    //prueba();
    int i;
    EArray listado[5];
    initArray(listado,5,1);
    char initnames[][20]= {"jorge","francisco","pedro","nahuel","martin"};
    for(i=0; i<5; i++)
    {
        strcpy(listado[i].name,initnames[i]);
    }
    firstUpper(listado,5);
    for(i=0; i<5; i++)
    {
        //printf("\n el status es: %d\n",listado[i].id);
        printf( "El nombre del registro %d es: %s\n",i+1,listado[i].name);
    }

    //listado[3].isEmpty=0;
    i=findByString(listado,5,"Ingrese el ID","No se encontro",1);
    if(i!=-1)
    {
        printf("El Id solicitado se encuentra en el indice %d",i);
    }



    return 0;
}



int findByString(EArray* struc,int cant, char* message,char* eMesaage,int printeMessage)
{
    int i;
    int retorno=-1;
    char stringToFind[4096];

    firstUpper(struc,cant);

    if(struc!=NULL && cant>0)
    {
        getString(stringToFind,message,1,50);
        stringToFind[0]=toupper(stringToFind[0]);
        printf("%s\n",stringToFind);

        for (i=0; i<cant; i++)
        {

            if(strcmp(struc[i].name,stringToFind)==0)
            {
                retorno=i;
                break;
            }
        }
    }

    if (retorno==-1 && printeMessage==1)
        printf("%s\n",eMesaage);
    return retorno;

}

/**
*\brief Convierte en mayuscula la primera letra de cada nombre incluyendo nombre compuestos.
*\param struc array a utilizar
*\param Largo del array
*\return Devuelve 0 si termino OK o -1 si no pudo realizar la tarea.
*/

int firstUpper(EArray* struc, int cant)
{
    int i;
    int j;
    int retorno = -1;


    if(struc != NULL && cant > 0 )
    {
        for (i=0;i<cant;i++)
        {
            for(j=0;j<strlen(struc[i].name);j++)
            {
                if(0 == j || struc[i].name[j]==' ')
                {
                    struc[i].name[j]=toupper(struc[i].name[j]);

                }
                if(struc[i].name[j]==' ')
                {
                    struc[i].name[j+1]=toupper(struc[i].name[j+1]);

                }


            }
        }
        retorno=0;
    }
    return retorno;
    }


