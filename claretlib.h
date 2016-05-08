#ifndef CLARETLIB_INCLUDED
#define CLARETLIB_INCLUDED
int getString(char *input,char* message,int intMin,int intMax );
int getLetters(char* input,char* message,char* eMessage,int lengthMin,int lengthMax);
int getNumbers(char* input,char* message,char* eMessage,int lengthMin,int lengthMax);
int getMail(char* input,char* messageInput,char* eMessage,int lengthMin,int lengthMax);
int getInt(int* input,char message[], char errorMessage[],int lowLimitRange,int hiLimitRange);
void prueba(void);



#endif // CLARETLIB_INCLUDED
