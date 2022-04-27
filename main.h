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
typedef struct _main_node
{
	int file_count;
	char word[WORD_SIZE];
	struct sub_node *table;
	struct main_node *link;
}main_node;


typedef struct _sub_node
{
	int word_count;
	char f_name[NAME_SIZE];
	struct sub_node *table;
}sub_node;


#endif
