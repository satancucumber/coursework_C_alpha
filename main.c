#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxlen 1000
#define max_w 1000
int number_lines(const char* fname)
{
    int lines_count;
    char file_name[255];
    FILE *file;
    *strchr(fname, '\n') = 0;
    file = fopen(file_name, "r");
    lines_count = 0;
    while (! feof(file))
    {
        if (fgetc(file) == '\n')
            lines_count++;
    }
    lines_count++;
    fclose(file);
    return lines_count;
}
void alph(char* String)
{
    int i, j, Temp, slen;
    int Flag;
    int Number;
    char result[maxlen];
    int Words[max_w];

    Number = 0;
    Flag = 1;
    slen = strlen(String);
    for (i = 0; i < slen; i ++)
    {
        /* Все пробелы заменяем на символ конца строки */
        if ((String[i] == ' ') || (String[i] == '!') || (String[i] == ',') || (String[i] == '.') || (String[i] == '?') || (String[i] == ':'))
        {
            String[i] = '\0';
            Flag = 1;
        }
            /* Позиции первых после пробелов символов записываем в массив */
        else if (Flag)
        {
            Words[Number ++] = i;
            Flag = 0;
        }
    }

    /* Сортировка */
    for (j = Number; j > 0; j --)
        for (i = 0; i < j; i ++)
            if (strcmp(&String[Words[i]], &String[Words[i + 1]]) > 0)
            {
                Temp = Words[i];
                Words[i] = Words[i + 1];
                Words[i + 1] = Temp;
            }
}

int n_readline(const char* fname, int n, char* buf, int len){
    char  c;
    FILE* fp = fopen(fname, "r");
    if(fp == NULL)
        return 0;

    while(! feof(fp) && (n > 0)){
       fscanf(fp, "%*[^\n\r]%c", &c);
       --n;
    }

    if(! feof(fp))
        fgets(buf, len-1, fp);
    else
       *buf = '\0';

    fclose(fp);
    return (int)(*buf != '\0');
  }



 int main(){
   char buf[maxlen];
   int i;
   FILE *df;
   FILE *fp;
   df = fopen("data2.txt", "r");
   fp = fopen("data1.txt", "r");
   if ((df != NULL) && (fp != NULL))
   {
       printf("Open OK");
       for (i = 0; i < number_lines("data1.txt"); i++)
       {
           if(n_readline("data1.txt", i, buf, sizeof(buf))){
           alph(buf);
           printf("ok");
           }
            else
       {
           printf("error");
       }
       }
   }
   else{
    printf("Open error");
   }
   if (fclose(df))
   {
       printf("Closing OK");
   }
   else printf("Closing error");
   return 0;
}
