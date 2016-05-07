#ifndef __EARRAY
#define __EARRAY
typedef struct
{
    int isEmpty;
    int old;
    int id;
    char name[12];


}EArray;
#endif // __EARRAY
#ifndef CLARETARRAY_H_INCLUDED
#define CLARETARRAY_H_INCLUDED
int initArray(EArray* struc,int cant,int value);
int findEmpty(EArray* struc,int cant, int value,int printFull);
int findById(EArray* struc,int cant, char* message,char* eMesaage,int printeMessage);


#endif // CLARETARRAY_H_INCLUDED
