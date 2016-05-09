#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define TAM 5
void prueba(void)
{
    char palabras[TAM][20];
    int i;
    int a=0;
    int numerito[TAM];

    for(i=0; i<TAM; i++)
    {
        a=getInt(&numerito[i],"Ingrese un numero: ","Solo numeros entre el 0 y el 2300\n",0,2300);

        if (a==-1)
        {
            i--;
        }
    }
    for(i=0; i<TAM; i++)
    {
        printf("La %d Ingresada es: %d\n",i+1,numerito[i]);
    }


}

/**
*\brief Pide y valida un string
*\param char* Input Puntero char donde se va a guardar la cadena
*\param char* message Mensage con el cual se va a solicitar el ingreso de la cadena
*\param int intMin minimo de letras para validar el largo del string
*\param int intMax maximo de letras para validar el largo del string
*\return si todo salio OK retorna 0 y si no -1
*/

int getString(char *input,char* message,int intMin,int intMax )
{
    char auxChar[4096];
    int retorno=-1;

    if(input!=NULL&& intMin>=0)
    {
        printf("%s",message);
        setbuf(stdin,NULL);
        gets(auxChar);
        if(strlen(auxChar)<intMax &&strlen(auxChar)>intMin )
        {
            strcpy(input,auxChar);
            retorno=0;
        }
        else
        {
            if(strlen(auxChar)<intMin)
            {
                printf("muy cort@\n");
            }
            if(strlen(auxChar)>intMax)
            {
                printf("muy larg@\n");
            }

            //printf( "%s",errorMessage);
        }
    }
    return retorno;

}


/**
*\brief Solicita un string y valida que sean todas letras
*\param char* input Puntero char donde se guardara la cadena
*\param char* messageInput mensaje de solicitud de cadena
*\param char* eMessage mensaje de error por si se ingresan datos que no son letras
*\param int lengthMin minimo de letras que debe tener la cadena
*\param int lengthMax Maximo de letras que debe tener la cadena
*\return Retorna 0 si todo salio bien o -1 si no finalizo ok
*/

int getLetters(char* input,char* messageInput,char* eMessage,int lengthMin,int lengthMax)
{
    int retorno=-1;
    int i;
    int getstFlag=0;
    int strleng;
    char auxChar[4096];


    if(input!=NULL && lengthMin>0)
    {
        setbuf(stdin,NULL);
        getstFlag=getString(auxChar,messageInput,lengthMin,lengthMax);
        strleng=strlen(auxChar);

        for(i=0; i<strleng; i++)
        {
            if(getstFlag==-1)
                break;
            if(/*(strleng>lengthMin)&&*/(auxChar[i]>='a'&& auxChar[i]<='z')||(auxChar[i]>='A'&&auxChar[i]<='Z'))
            {

                strcpy(input,auxChar);
                retorno=0;

            }
            else
            {
                printf("%s",eMessage);
                break;

            }

        }
    }
    return retorno;
}

/**
*\brief Solicita una cadena que sean solo numeros y lo valida
*\param  char* input Puntero char donde se guardara la cadena
*\param char* messageInput mensaje de solicitud de cadena
*\param char* eMessage mensaje de error por si se ingresan datos que no son numeros
*\param int lengthMin minimo de letras que debe tener la cadena
*\param int lengthMax Maximo de letras que debe tener la cadena
*\return Retorna 0 si todo salio bien o -1 si no finalizo ok
*/

int getNumbers(char* input,char* messageInput,char* eMessage,int lengthMin,int lengthMax)
{
    int retorno=-1;
    int i;
    int getstFlag=0;
    int strleng;
    char auxChar[4096];


    if(input!=NULL && lengthMin>0)
    {
        setbuf(stdin,NULL);
        getstFlag=getString(auxChar,messageInput,lengthMin,lengthMax);
        strleng=strlen(auxChar);

        for(i=0; i<strleng; i++)
        {
            if(getstFlag==-1)
                break;
            if(/*(strleng>lengthMin)&&*/(auxChar[i]>='0'&& auxChar[i]<='9'))
            {

                strcpy(input,auxChar);
                retorno=0;

            }
            else
            {
                printf("%s",eMessage);
                break;

            }

        }
    }
    return retorno;
}

/**
*\brief Solicita una cadena de texto con formato de mail y lo valida
*\param  char* input Puntero char donde se guardara la cadena
*\param char* messageInput mensaje de solicitud de cadena
*\param char* eMessage mensaje de error por si no se ongresa un dato valido
*\param int lengthMin minimo de letras que debe tener la cadena
*\param int lengthMax Maximo de letras que debe tener la cadena
*\return Retorna 0 si todo salio bien o -1 si no finalizo ok
*/
int getMail(char* input,char* messageInput,char* eMessage,int lengthMin,int lengthMax)
{
    int retorno=-1;
    int i;
    int getstFlag=0;
    int strleng;
    int countAt=0;
    int countDot=0;
    char auxChar[4096];


    if(input!=NULL && lengthMin>0)
    {
        setbuf(stdin,NULL);
        getstFlag=getString(auxChar,messageInput,lengthMin,lengthMax);
        strleng=strlen(auxChar);

        for(i=0; i<strleng; i++)
        {
            if(getstFlag==-1)
            {
                break;
            }
            if(/*(strleng>lengthMin)&&*/(auxChar[i]>='0'&& auxChar[i]<='9')||(auxChar[i]>='a'&& auxChar[i]<='z')||(auxChar[i]>='A'&&auxChar[i]<='Z')||(auxChar[i]=='@'|| auxChar[i]=='.'))
            {
                strcpy(input,auxChar);
                if(auxChar[i]=='@')
                {
                    countAt++;
                }
                if(auxChar[i]=='.')
                {
                    countDot++;
                }
            }
            else
            {
                printf("%s",eMessage);
                break;
            }
        }// END FOR
        if(countAt==1&&countDot>=1)
        {
            retorno=0;
        }
        else
        {
            printf("%s",eMessage);
        }
    }
    return retorno;
}

/**
*\brief Solicita una cadena de texto con formato de telefono y lo valida
*\param char* input Puntero char donde se guardara la cadena
*\param char* messageInput mensaje de solicitud de cadena
*\param char* eMessage mensaje de error por si no se ongresa un dato valido
*\param int lengthMin minimo de letras que debe tener la cadena
*\param int lengthMax Maximo de letras que debe tener la cadena
*\return Retorna 0 si todo salio bien o -1 si no finalizo ok
*/

int getPhone(char* input,char* messageInput,char* eMessage,int lengthMin,int lengthMax)
{
    int retorno=-1;
    int i;
    int getstFlag=0;
    int strleng;
    int countSymbol=0;
    char auxChar[4096];


    if(input!=NULL && lengthMin>0)
    {
        setbuf(stdin,NULL);
        getstFlag=getString(auxChar,messageInput,lengthMin,lengthMax);
        strleng=strlen(auxChar);

        for(i=0; i<strleng; i++)
        {
            if(getstFlag==-1)
            {
                break;
            }
            if(/*(strleng>lengthMin)&&*/(auxChar[i]>='0'&& auxChar[i]<='9')||(auxChar[i]=='-'))
            {
                strcpy(input,auxChar);
                if(auxChar[i]=='-')
                {
                    countSymbol++;
                }

            }
            else
            {
                printf("%s",eMessage);
                break;
            }
        }// END FOR
        if(countSymbol==1)
        {
            retorno=0;
        }
        else
        {
            printf("%s",eMessage);
        }
    }
    return retorno;
}
/**
*\brief Solicita un entero en un rango y valida que se haya ingresado un dato valido
*\param int* input Puntero int donde se guardara el dato si es valido
*\param char message[] Mensaje para solicitar el numero
*\param char errorMessage[] Mensaje de error
*\param int lowLimitRange numero minimo del rango a ingresar
*\param int hiLimitRange numero maximo del rango a ingresar
* \return Retorna 0 si todo salio bien o -1 si no finalizo ok
*
*/

int getInt(int* input,char message[], char errorMessage[],int lowLimitRange,int hiLimitRange)
{
    char aux[4096];
    int retorno=-1;
    int intAux;

    printf("%s", message);
    setbuf(stdin,NULL);
    gets(aux);

    if ( strcmp(aux,"0\0")==0)
    {
        intAux = atoi(aux);
        retorno = 0;
        *input = intAux;

    }
    else
    {
        intAux = atoi(aux);
        if(intAux != 0)
        {
            if(intAux > lowLimitRange && intAux < hiLimitRange )
            {
                retorno = 0;
                *input = intAux;
            }
            else
            {
                printf("%s", errorMessage);
            }
        }
        else
        {
            printf("%s", errorMessage);
        }

    }



    return retorno;

}


