#include "main.h"
void print(main_node *head,int index)
{
    while(head != NULL)
    {
	sub_node *temp = head -> table;
	printf("%d	",index);
	printf("%-15s",(head) -> word);
	printf("%5d file/s",(head) -> file_count);

	while(temp)
	{
	    printf("%7s%10s %-4d","FILE:",temp -> f_name,temp -> word_count);
	    temp = temp -> table;
	}
	    printf("\n");
	head = head -> link;

    }
}


