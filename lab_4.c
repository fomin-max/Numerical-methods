#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 200

typedef struct list{
	char *value;
	struct list *next;
} list;

list *create(list *head, char *data)
{
	list *i = malloc(sizeof(list)); // выделяем память под элемент
	if (head == NULL)       // если создаем самый первый элемент
	{ 
		i->value = strdup(data); // присваиваем значение 
		i->next = NULL; // присваиваем указателю i адрес предыдущего элемента
	}
	else
	{                   // если имеется хотя бы 1 элемент
		i->value = strdup(data); // присваиваем ему значение
		i->next = head;
	}
        return i;
}



list *addLast(char *data) //добавляем в конец элемент
{ 
	list *i = malloc(sizeof(list)); // память для него
	i->value = strdup(data); //значение ему передаваемое
	i->next = NULL; //ссылку на NULL
	return i;
}


/*void delete(list *head){
	list *i = malloc(sizeof(list));
	list *next = malloc(sizeof(list));
	i = head;
	if(i->next == NULL){
		free(i->value);
		free(i);
		i = NULL;
	}
	else{
		next = NULL;
		for ( ; i != NULL; i = next){
			next = i->next;
			if(next->next == NULL){
				i->next = NULL;
				free(next->value);
				free(next);
				break;
				
			}
		}
	}
}
*/
list *getPenult(list *head) // функция возвращающая указатель на предпоследний элемент
{
        if(head->next == NULL) // если в списке 1 элемент
        {
                return NULL;
        }
        while(head->next->next)
        {
                head=head->next;
        }
        return head;
}


void delLast(list *head)
{
        list *i = NULL; // ссылка на NULL
        /*if(!(*head)) // если в списке 1 элемент
        {
                exit(1);
        } */      
        i=getPenult(head); 
        if(i == NULL) // ????????
        {
                free(head);
                head = NULL;
        }
        else            // ?????
        {
                free(i->next);
                i->next = NULL;
        }
}





void display(list *head)
{
        int k=0;
	list *i = head;
	for ( ; i != NULL; i = i->next)
	{
	        k++;
		printf("%d element: %s\n",k, i->value);
	}
}

void delAll(list *head)
{
	list *i = malloc(sizeof(list));
	list *next = malloc(sizeof(list));
	i = head;
	next = NULL;
	for ( ; i != NULL; i = next)
	{
		next = i->next;
		//free(i->value);
		i->value = NULL;
		free(i);
		i = NULL;
		
	}
}

int search(char *str, list *head)
{
	list *i = malloc(sizeof(list));
	int q = 0;
	i = head;
	for ( ; i != NULL; i = i->next)
	{
		if(strcmp(i->value, str) == 0)
		{
			q = 1;		
		}
	}
	return q;
}

void clearstd()
{
        char k;
        while(1)
        {
                k=fgetc(stdin);
                if(k=='\n')
                        break;
        }
}
int main(void)
{
        system("clear");
        char data[N];
        char str[N];
        int b;
        int a=0;
        char j;
        list *head = NULL;
        list *next = NULL;
        list *i= NULL;
        printf("Welcome you in my program!\nWhat you want?\n\n");

def:
        
	printf("1. Create first element\n");
	printf("2. Add element to the end\n");
	printf("3. Delete last element\n");
	printf("4. Show the list\n");
	printf("5. Delete all elements\n");
	printf("6. Find element in the list\n");
	printf("7. Exit\n");
	printf("Your choise: "); 
	scanf("%c", &j);
	if(isdigit(j)==0)
	{
	        system("clear");
	        printf("Wrong input, try again!\n\n");
	        clearstd();
	        goto def;
	}
		switch(j){
			case '1':
			        clearstd();
				printf("Put value of element:\n");
				fgets(data, N, stdin);
				if(strlen(data)>=199)
				{
				        system("clear");
				        clearstd();
				        printf("Overflow of element!\n\n");
				        goto def;
				}
				head = create(head,data);
				system("clear");
				printf("Successfully!\n\n");
				goto def;
			case '2':
			        clearstd();
				if(head == NULL){
					printf("Put value of element:\n");
					fgets(data, N, stdin);
					if(strlen(data)>=199)
				        {
				                system("clear");
				                clearstd();
				                printf("Overflow of element!\n\n");
				                goto def;
				        }
					head = create(head,data);
					next = head;
					system("clear");
				        printf("Successfully!\n\n");
					goto def;
				}
				else{
					i = head;
					for( ; i->next != NULL; i = next)
						next = i->next;
					printf("Put value of element:\n");
					fgets(data, N, stdin);
					if(strlen(data)>=199)
				        {
				                system("clear");
				                clearstd();
				                printf("Overflow of element!\n\n");
				                goto def;
				        }
					next = addLast(data);
					i->next = next;
					system("clear");
				        printf("Successfully!\n\n");
					goto def;

				}
			case '3':
			        clearstd();
				if (head == NULL)
				{
					system("clear");
					printf("The list is empty!\nFor begin, create the elements!\n\n");
					return 1;
				}
				if (head->next == NULL)
				{
				        system("clear");
					delLast(head);
					head = NULL;
					printf("Successfully!\n\n");
				}
				else{
					delLast(head);
					system("clear");
					printf("Successfully!\n\n");
				}
				goto def;
			case '4':
			        if (head == NULL)
				{
				        system("clear");
				        clearstd();
					printf("The list is empty!\nFor begin, create the elements!\n\n");
				}
				else
				{
			                system("clear");
				        display(head);
				        clearstd();
				}
				goto def;
			case '5':
			        clearstd();
				if(head == NULL)
				{
					system("clear");
					printf("The list is empty!\nFor begin, create the elements!\n\n");
				}
				else
				{
					delAll(head);
					head = NULL;
					system("clear");
					printf("Successfully!\n\n");
				}
				goto def;
			case '6':
				if (head == NULL)
				{
				        system("clear");
				        clearstd();
					printf("The list is empty!\nFor begin, create the elements!\n\n");
				}
				else
				{
				        clearstd();
					printf("Put the element:\n");
					fgets(str, N, stdin);
					if(strlen(str)>=199)
				        {
				                system("clear");
				                clearstd();
				                printf("Overflow of element!\n\n");
				                goto def;
				        }
					a=search(str, head);
					system("clear");
					if(a == 1)
	                                {
		                                printf("The element is found!\n\n");
	                                }
	                                else
	                                {
		                                printf("The element is not found!\n\n");
	                                }
				}
				goto def;
			case '7':
				exit(1);
			default:
			        system("clear");
			        clearstd();
				printf("Wrong input, try again!\n\n");
				goto def;
			
		}
return 0;
}
