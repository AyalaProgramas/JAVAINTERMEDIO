
float getFloat(char mensaje[]);
int getInt(char mensaje[]);
char getChar(char mensaje[]);
int esNumerico(char strin[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);

int getStringNumerosFlotantes(char mensaje[],char input[]);
int getValidInt(char requestMessage[],char errorMessage[],int lowLimit,int hiLimit);
float getValidFloat(char requestMessage[],char errorMessage[],int lowLimit,int hiLimit);
void cleanStdin(void);
void getValidString(char requestMessage[],char errorMessage,char input[]);
int esNumericoFlotante(char str[]);
