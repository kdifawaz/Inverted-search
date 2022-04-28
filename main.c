#include "main.h"

int main(int argc,char *argv[])
{

/*declaring the variables*/
    int option;
    char choice;

    /*declaring file posinter*/
    FILE *fptr = NULL;
    char fname[20];

    /*declaring the heads*/
    main_node *head[26] = {NULL};
/*defining a head pointer for a list to store file names which are updated to data base*/
    file_list *fhead = NULL;

    do
    {
	printf("Options:\n1. Create Database\n2. Update\n3. Display\n4. Save\n5.Search\n6. Exit\nEnter the Option:");
	scanf("%d",&option);

	switch(option)
	{
	    case 1:
		{
		    /*creating database*/

		    for(int i = 1;i < argc;i++)
		    {
			strcpy(fname,argv[i]);

			if(open_file(&fptr,fname) == SUCCESS)
			{

			    printf("%s is opened succefully\n",fname);

			    if((check_file_list(&fhead,fname)) == SUCCESS)
			    {
				printf("Data base creation strated\n");

				if(create_DB(&fptr,fname,head) == SUCCESS)
				{
				    printf("Data base creation done Succesfully\n");

				}
			    }

			}
		    }
		    break;
		}
	    case 2:
		{
		    /*updating the database*/
		    printf("Enter the file name\n");
		    scanf("%s",fname);
		    if((open_file(&fptr,fname)) == SUCCESS)
		    {
			printf("%s is opened succefully\n",fname);

			if((check_file_list(&fhead,fname)) == SUCCESS)
			{
			    printf("Data base creation strated\n");
			    if(create_DB(&fptr,fname,head) == SUCCESS)
			    {
				printf("Data base creation done Succesfully\n");

			    }
			}
		    }
		    else
			printf("File:%s is not opened\n",fname);
		    break;

		}
	    case 3:
		{

		    /*printing database*/

		    printf("%-10s%-15s%10s\n","INDEX","WORD","FILE COUNT");

		    /*printing for each charecter*/
		    for(int i = 0;i < 26;i++)
		    {
			print(head[i],i,stdout);
		    }
		    break;

		}
	    case 4:
		{
		    /*backuping the output in a file*/
		    FILE *file = fopen("Output.txt","w");
		    for(int i = 0;i < 26;i++)
		    {
			print(head[i],i,file);
		    }
		    fclose(file);

		    break;

		}
	    case 5:
		{
		    /*searching word*/
		    char key_word[20];
		    printf("Enter the key word to search\n");
		    scanf("%s",key_word);
		    search(head,key_word);

		    break;

		}
	    case 6:
		{
		    printf("Program teminated\n");
		    return 0;
		    break;

		}
	    default:
		{
		    printf("Enter a valid input\n");
		}



	}
	printf("Do you want to continue(y/n):");
	scanf("\n%c",&choice);

    }while(choice != 'n' && choice != 'N');
    return 0;
}
int check_file_list(file_list **fhead,char fname[])
{
    if(*fhead == NULL)
    {
	file_list *new = malloc(sizeof(file_list));
	strcpy(new -> file_name,fname);
	new -> link = NULL;
	*fhead = new;
	return SUCCESS;
    }
    file_list *temp = *fhead;
    file_list *prev = NULL;
    while(temp)
    {   
	if((strcmp(fname,temp -> file_name)) == 0)
	{
	    printf("File is updated already\n");
	    return FAILURE;
	}   
	prev = temp;
	temp = temp -> link;

    }
    prev -> link = malloc(sizeof(file_list));
    temp = prev -> link; 
    strcpy(temp -> file_name,fname);
    temp -> link = NULL;
    return SUCCESS;
}


int open_file(FILE* *fptr,char *name)
{

    /*opening the file in read mode*/

    *fptr = fopen(name,"r");
    if(*fptr == NULL)
    {
	printf("%s file is note available\n",name);
	return FAILURE;
    }


    return SUCCESS;


}










