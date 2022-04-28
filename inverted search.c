#include "main.h"

int create_DB(FILE* *fptr,char *fname,main_node* *head)
{
    int index = 0;
    char word[20];
    while ( fscanf(*fptr,"%s",word) != EOF)
    {

	index = index_finder(word);	

	create_node(word,fname,&head[index]);

    }
    return SUCCESS;

}

int index_finder(char *word)
{
    int index;

    if (isupper(word[0]) != 0)
    {
	index = word[0] % 65;
    }
    else
    {
	index = word[0] % 97;
    }
    return index;


}

int create_node(char *word,char *fname,main_node **head)
{
    if(*head == NULL)
    {

	/*allocating the memmory for main node and updating the values*/
	main_node *new_main = malloc(sizeof(main_node));
	new_main -> file_count = 1;
	strcpy (new_main -> word,word);
	new_main -> link = NULL;

	/*allocting the memmory for sub node*/
	sub_node *new_sub = malloc(sizeof(sub_node));
	new_sub -> word_count = 1;
	strcpy(new_sub -> f_name,fname);
	new_sub -> table = NULL;
	new_main -> table = new_sub;
	/*updating the head value with new main node*/
	*head = new_main;

	return SUCCESS;
    }
    main_node *temp_main = *head;
    main_node *prev_main = NULL;
    while(temp_main)
    {
	if(strcmp(temp_main -> word,word) == 0)
	{
	    sub_node *sub_temp = temp_main -> table;
	    sub_node *sub_prev = sub_temp;

	    while(sub_temp)
	    {
		if(strcmp(sub_temp -> f_name,fname) == 0)
		{
		    (sub_temp -> word_count)++;
		    return SUCCESS;
		}
		sub_prev = sub_temp;
		sub_temp = sub_temp -> table;
	    }
	    sub_prev -> table = malloc(sizeof(sub_node));
	    sub_prev -> table ->  word_count = 1;
	    strcpy(sub_prev -> table -> f_name,fname);
	    sub_prev -> table -> table = NULL;

	    (temp_main -> file_count)++;
	    return SUCCESS;

	}
	prev_main = temp_main;
	temp_main = temp_main -> link;
    }
    create_node(word,fname,&(prev_main -> link));
    return SUCCESS;

}

