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
    int option;//,free1;
    EArray listado[5];
    char seguir='s';
    char itemdel[233];
    int checkdelete;

    initArray(listado,5,1);




    do
    {
        printf("\n1-ADD\n2-DEL\n3-SHOW\n4-EXIT\n");
        getInt(&option,"","Solo entre 1 y 4",0,5);
        firstUpper(listado,5);
        switch(option)
        {

        case 1:
            addItemInt(listado,5,"\n",1);
            break;
        case 2:
            getString(&itemdel,"Ingrese el nombre a eliminar: ",1,20);
            firstUpperString(&itemdel,20);
           checkdelete= deletItemString(listado,5,itemdel);
           if (checkdelete==-1)
           printf("Error en borrado reintente");
            break ;
        case 3:
            system("clear");
            for(i=0; i<5; i++)
            {
                if(listado[i].isEmpty==0)
                {
                    printf("\n\nPersona Nro-%d\n",i+1);
                    printf("Nombre: %s\nEdad: %d\nID: %d\n",listado[i].name, listado[i].old,listado[i].id);
                }
            }
            printf("Presione una tecla pra continuar....");
            getchar();
            system("clear");
            break;
        case 4:
            seguir='n';
            break;
        }

    }
    while(seguir!='n');




    //i=findByString(listado,5,"Ingrese el ID","No se encontro",1);
//    if(i!=-1)
//    {
//        printf("El Id solicitado se encuentra en el indice %d",i);
//    }



    return 0;
}
int deletItemString(EArray* struc,int cant,char* strToDel)
{
    int retorno=-1;
    int indexToDelete;

    if(struc!=NULL&& cant >0)
    {
        indexToDelete=checkByString(struc,cant,strToDel);
        printf("el indice es %d \n",indexToDelete);
        if(indexToDelete!=-1&&struc[indexToDelete].isEmpty==0)
        {
            struc[indexToDelete].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

