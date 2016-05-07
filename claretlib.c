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
*
*
*
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
*
*
*
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
*
*
*
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
*
*
*
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
*
*
*
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
