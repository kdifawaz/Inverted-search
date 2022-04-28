#include "main.h"


int search(main_node *head[],char key_word[])
{
    int index;
    index = index_finder(key_word);
    find_node(head[index],key_word);


}

void find_node(main_node *head,char key_word[])
{
    while(head)
    {
	if(strcmp(head -> word,key_word) == 0)
	{
	    printf("%s is present in %d files\n",key_word,head -> file_count);
	    sub_node *temp = head -> table;
	    while(temp)
	    {
		printf("%15s%-15s%15s%5d\n","FILE NAME:",temp -> f_name,"Word Count:",temp -> word_count);
		temp = temp -> table;
	    }
    return;

	}
	head = head -> link;


    }
    printf("%s not found\n",key_word);


}


