#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
        int i=0,k=0;
        double t,y;
        char str[100],std[100];
        fgets(str,sizeof(str),stdin);
        i=0;
        k=0;
        while(str[i]){   //проверка на двух стоящих подряд минусов (замена на плюс)
                if (str[i]=='-'&&str[i+1]=='-'){
                        str[i]='+';
                        str[i+1]='0';
                }
                i++;
        }
        i=0;
        if(str[0]=='*'||str[0]=='/'){  //проверка на первый символ строки
                printf("Mistake in input\n");
                return 1;
        }
        t=atof(str);  //взятие первого числа исходной строки
        i=1;
        while (str[i]!='\0'){
                switch (str[i]){
                        case '+':
                                while (k!=i+1){
                                        str[k]='0';
                                        k++;}
                                y=atof(str);
                                t=t+y;  
                                break;

                        case '-':
                                while (k!=i+1){
                                        str[k]='0';
                                        k++;}
                                y=atof(str);
                                t=t-y;
                        break;

                        case '*':
                                while (k!=i+1){
                                        str[k]='0';
                                        k++;}
                                y=atof(str);
                                t=t*y;
                                break;

                        case '/':
                                while (k!=i+1){
                                        str[k]='0';
                                        k++;}
                                y=atof(str);
                                if(y==0){
                                        printf("%s\n","Mistake:Division by zero");
                                        return 0;}
                                t=t/y;
                                break;
                                }
                i++;
                }
        i=0;
        sprintf(std,"%lf",t);
        i=strlen(std)-7;
        if(i>=15){
                printf("Mistake:Overfull\n");
                return 1;
                }
        printf("%.5lf\n",t);
        return 0;
        }

