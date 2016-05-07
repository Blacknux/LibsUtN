#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "claretlib.h"
#include "claretarray.h"

int initArray(EArray* struc,int cant,int value)
{
    int i;
    int retorno=-1;
    if(struc!=NULL && cant > 0)
    {
        for (i=0; i<cant; i++)
        {
            struc[i].isEmpty=value;
        }
        retorno=0;
    }
    return retorno;
}


int findEmpty(EArray* struc,int cant, int value,int printFull)
{
    int i;
    int retorno=-1;
    if(struc!=NULL && cant>0)
    {
        for (i=0; i<cant; i++)
        {
            if(struc[i].isEmpty==value)
            {
                retorno=i;
                break;
            }
        }
        if (retorno==-1 && printFull==1)
            printf("No hay lugar");
    }
    return retorno;

}




int findById(EArray* struc,int cant, char* message,char* eMesaage,int printeMessage)
{
    int i;
    int retorno=-1;
    int id;
    if(struc!=NULL && cant>0)
    {
        getInt(&id,message,"Id fuera de rango",1,500);
        for (i=0; i<cant; i++)
        {
            if(struc[i].id==id)
            {
                retorno=i;
                break;
            }
        }
        if (retorno==-1 && printeMessage==1)
            printf("%s\n",eMesaage);
    }
    return retorno;
}

