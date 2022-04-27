#include "main.h"

int main(int argc,char *argv[])
{


    int option;
    char choice;

    /*declaring file posinter*/
    FILE *fptr = NULL;
    char fname[20];

    /*declaring the heads*/
    main_node *head[26] = {NULL};


    do
    {
    printf("Options:\n1. Create Database\n2. Update\n3. Display\n4. Save\n5. Exit\nEnter the Option:");
    scanf("%d",&option);

    switch(option)
    {
	case 1:
	    {

		   for(int i = 1;i < argc;i++)
		{
		    strcpy(fname,argv[i]);

		    if(open_file(&fptr,fname) == SUCCESS)
		    {
			printf("%s is opened succefully\n",fname);


			if(create_DB(&fptr,fname,head) == SUCCESS)
			{
			    printf("Data base creation doone Succesfully\n");

			}
		    }
		}
		break;
	    }
	case 2:
	    {
		//updating
		break;

	    }
	case 3:
	    {

		//printing

		for(int i = 0;i < 26;i++)
		{
		    print(head[i],i);

		}
		break;

	    }
	case 4:
	    {
		//save to file
		break;

	    }
	case 5:
	    {
		//exit
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

int open_file(FILE* *fptr,char *name)
{


    *fptr = fopen(name,"r");
    if(*fptr == NULL)
    {
	printf("%s file is note available\n",name);
	return FAILURE;
    }
    return SUCCESS;


}
