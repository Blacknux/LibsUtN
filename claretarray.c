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


    int checkByString(EArray* struc,int cant,char* strToCheck )
{
    {
        int i;
        int retorno=-1;
        if(struc!=NULL && cant>0)
        {
            for (i=0; i<cant; i++)
            {
                if(strcmp(struc[i].name,strToCheck)==0 )
                {
                    retorno=i;
                    break;
                }
            }
        }
        return retorno;
    }


}


int checkById(EArray* struc, int cant,int idToCheck)
{
    int i;
    int retorno=-1;
    if(struc!=NULL && cant>0)
    {
        for (i=0; i<cant; i++)
        {
            if (struc[i].id==idToCheck )
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}









int addItemStrings(EArray* struc,int cant,char* message,int IsEmptyValue)
{
    int retorno=-1;
    int indice,exist;
    char auxChar[4096];

    if(struc!=NULL&& cant >0)
    {
        indice=findEmpty(struc,cant,IsEmptyValue,1);
        if(indice!=-1)
        {
            getString(auxChar,"\nIngrese el nombre: ",2,120);
            firstUpperString(auxChar,11);
            printf("\n\n%s\n\n", auxChar);
            exist=checkByString(struc,cant,auxChar);
            /** Si el indice existe y el valor del isEmpty es distinto del que se pasa por parametro
                entonces el usuario existe*/
            if(exist!=-1 && struc[exist].isEmpty!=IsEmptyValue)
            {
                printf("Usuario registrado\n");
            }
            else
            {
                strcpy(struc[indice].name,auxChar);
                if((getInt(&struc[indice].id,"\nIngrese el ID: ","Error ID no valido 1-100",1,100)!=-1)&& //Podemos agregar tantas condiciones como datos necesitamos cargar y si todas
                        (getInt(&struc[indice].old,"\nIngrese la edad: ","Error Edad no valida 1-100",1,100)!=-1))//Dan ok recien ahi cambiamos el valor de is Empty
                {
                    struc[indice].isEmpty=0;
                }
            }
        }
    }
    return retorno;


}


int addItemInt(EArray* struc,int cant,char* message,int IsEmptyValue)
{
    int retorno=-1;
    int indice,exist;
    char auxint;

    if(struc!=NULL&& cant >0)
    {
        indice=findEmpty(struc,cant,IsEmptyValue,1);
        if(indice!=-1)
        {
            getInt(&auxint,"Ingrese el ID: ","Error ID Fuera de Rango\n",0,101);

            exist=checkById(struc,cant,auxint);


            /** Si el indice existe y el valor del isEmpty es distinto del que se pasa por parametro
                entonces el usuario existe*/
            if(exist!=-1 && struc[exist].isEmpty!=IsEmptyValue)
            {
                printf("Usuario registrado\n");
            }
            else
            {
                struc[indice].id=auxint;

                if((getLetters(struc[indice].name,"Ingrese el Nombre: ","Error nombre muy largo o vacio",1,12)!=-1)&& //Podemos agregar tantas condiciones como datos necesitamos cargar y si todas
                        (getInt(&struc[indice].old,"Ingrese la edad: ","Error Edad no valida 1-100",0,101)!=-1))//Dan ok recien ahi cambiamos el valor de is Empty
                {
                    struc[indice].isEmpty=0;
                }
            }
        }
    }
    return retorno;
}




int firstUpperString(char* struc, int cant)
{
    int i;
    int j;
    int retorno = -1;

    if(struc != NULL && cant > 0 )
    {
        for (i=0; i<cant; i++)
        {
            if(0 == i /*|| struc[i][j]==' '*/)
            {
                struc[i]=toupper(struc[i]);
            }
            else if(struc[i]==' ')
            {
                struc[i+1]=toupper(struc[i+1]);
            }
        }
        retorno=0;
    }
    return retorno;
}


int deletItemInt(EArray* struc,int cant,int idToDel)
{
    int retorno=-1;
    int indexToDelete;

    if(struc!=NULL&& cant >0)
    {
        indexToDelete=checkById(struc,cant,idToDel);
        if(indexToDelete!=-1&&struc[indexToDelete].isEmpty==0)
        {
            struc[indexToDelete].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

