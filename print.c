#include "main.h"
void print(main_node *head,int index,FILE *stream)
{

    while(head != NULL)
    {
	/*printing the seperate word*/
	sub_node *temp = head -> table;
	fprintf(stream,"%-10d",index);
	fprintf(stream,"%-15s",(head) -> word);
	fprintf(stream,"%10d file/s",(head) -> file_count);
	/*printing the each file details*/
	while(temp)
	{
	    fprintf(stream,"%7s%-10s%10s%-4d","FILE:",temp -> f_name,"Word Count:",temp -> word_count);
	    temp = temp -> table;
	}
	fprintf(stream,"\n");
	head = head -> link;

    }
}


