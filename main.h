#ifndef MAIN_H
#define MAIN_L

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1
#define  WORD_SIZE  20
#define  NAME_SIZE  20
typedef struct _sub_node
{
	int word_count;
	char f_name[NAME_SIZE];
        struct _sub_node *table;
}sub_node;
typedef struct _main_node
{
	int file_count;
	char word[WORD_SIZE];
	struct _sub_node *table;
	struct _main_node *link;
}main_node;


int open_file(FILE* *fptr,char *name);
int create_DB(FILE* *fptr,char *fname,main_node **head);
int create_node(char *word,char *fname,main_node **head);
void print(main_node *head,int index);



#endif
