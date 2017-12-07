#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 1000 

int encrypt (int key, char *name, char *text)
{
	system("clear");
	freopen(name,"w",stdout);
	int i,j=0;
	for(i=0;i!=strlen(text);i++)
	{
		text[i]=text[i]^key;
		j++;
	}
	fputs(text,stdout);
	fclose(stdout);
	return 0;
}

char decrypt (int key, char *name, char *text)
{
	system("clear");
	freopen(name,"r",stdin);
	freopen(text,"w",stdout);
	int i,j=0;
	char mass[100];
	fgets(mass,sizeof(mass),stdin);
        fclose(stdin);
	for(i=0;i!=strlen(mass);i++)
	{
		mass[i]=mass[i]^key;
		j++;
	}
	fputs(mass,stdout);
	fclose(stdout);
	return 0;
}

int main()
{
	system("clear");
	int a,b;
	char name [100];
	int key;
	char text [N];
	printf("What do you want?\n1.Encrypt\n2.Decrypt\n");
	scanf("%d",&a);
	while(1)
	{
	        b=fgetc(stdin);
	        if(b=='\n')
	                break;
	}
	switch (a)
	{
	        case 1:
	        printf("Put a text: ");
	        fgets(text,sizeof(text),stdin);
	        printf("Put a name file: ");
	        fgets(name,sizeof(name),stdin);
		printf("Put a key: ");
		scanf("%d",&key);
		encrypt(key,name,text);
		break;
	
	        case 2:
	        printf("Put a name encrypt file: ");
	        fgets(name,sizeof(name),stdin);
	        printf("Put a name decrypt file: ");
	        fgets(text,sizeof(text),stdin);
	        a=strcmp(text,name);
	        if (sizeof(text)<=strlen(text)||sizeof(name)<strlen(name))
		        {
		        printf("Overfull");
		        return 1;
		        }
	        if (a==0)
	        {
	                printf("Error!\n");
	                break;
		}
		printf("Put a key:");
		scanf("%d",&key);
		decrypt(key,name,text);
	        break;
	
	        default:
		printf("Error\n");
		return 1;
	}
	return 0;
}
