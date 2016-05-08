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
int findByString(EArray* struc,int cant, char* message,char* eMesaage,int printeMessage);
int firstUpper(EArray* struc, int cant);
int firstUpperString(char* struc, int cant);
int checkByString(EArray* struc,int cant,char* strToCheck);
int checkById(EArray* struc, int cant,int idToCheck);
int addItemStrings(EArray* struc,int cant,char* message,int IsEmptyValue);
int addItemInt(EArray* struc,int cant,char* message,int IsEmptyValue);
int deletItemInt(EArray* struc,int cant,int idToDel);
#endif // CLARETARRAY_H_INCLUDED
