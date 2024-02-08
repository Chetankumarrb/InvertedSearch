#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1
#define NOELEMENT -2
#define EMPTYLIST -3
#define REPEATED -4
#define FILE_EMPTY -5
#define NOT_PRESENT -6
#define FILE_NOT_AVAILABLE -7 

#define SIZE 27
#define BUFF_SIZE 255
#define NAMELENGTH 20

//inverted table

/* subnode structue */
typedef struct sub_node
{
	char f_name[NAMELENGTH];
	int w_count;
	struct sub_node *slink;
}sub_node_t;

/* main node structure*/
typedef struct node
{
	char word[NAMELENGTH];
	struct node *mlink;
	sub_node_t *sub_link;
	int f_count;
}main_node_t;

/* file node structure (Lineked list used to store the filenames */
typedef struct file_node
{
    char f_name[NAMELENGTH];
    struct file_node *link;
}file_node_t;

/* validating files */
int validate_n_store_filenames(file_node_t **, char *filenames[]);
int IsFileValid(char *);
int store_filenames_to_list(char *f_name, file_node_t **head);

/* Create Database */
int create_DB(file_node_t *file_head, main_node_t *hash[],file_node_t** nhead);

/*create mainnode*/
main_node_t* Createmainnode(char *word,char *filename);

/*create subnode*/
sub_node_t* CreateSubnode(char *fname);

/* Display database */
int display_DB(main_node_t **arr);

/* Search Database */
int search_DB(main_node_t **hash, char *word);

/* Save Database */
int save_DB(main_node_t **head, char *fname);

/* Update database */
int update_DB(main_node_t *hash[],char *bfile,file_node_t **n_head);

int insert_at_last(file_node_t **n_head, char f_name[]);