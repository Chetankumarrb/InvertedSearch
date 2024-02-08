#include "InvertedSearch.h"

int validate_n_store_filenames(file_node_t **f_head, char *filenames[])
{
    int i=1,empty;
    while(filenames[i] != NULL)
    {
        empty = IsFileValid(filenames[i]);

        if(empty == FILE_NOT_AVAILABLE)
        {
            printf("FILE : %s is not available\n",filenames[i]);
            printf("Hence we are not adding this file into file linked list\n");
            i++;
            continue;
        }
        else if(empty == FILE_EMPTY)
        {
            printf("FILE : %s is empty\n",filenames[i]);
            printf("Hence we are not adding this file into file linked list\n");
            i++;
            continue;
        }
        else
        {
            //create list of files
            int ret = store_filenames_to_list(filenames[i],f_head);
             
            if(ret == SUCCESS)
            {
               printf("Successfull inserting file name : %s into file linked list\n",filenames[i]);
            }
            else if(ret == REPEATED)
            {
                printf("This file name : %s is repeated so not adding to file linked list\n",filenames[i]);
                
            }
      
            i++;
        }
    }
    return SUCCESS;
}




//check file available or not and check if it is having contents or not
int IsFileValid(char *filename)
{
    FILE *fptr = fopen(filename,"r");
    if(fptr == NULL)
    {
        return FILE_NOT_AVAILABLE;
    }
    
    fseek(fptr,0,SEEK_END);
    if(ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }



}

//store filenames to list
int store_filenames_to_list(char *f_name, file_node_t **head)
{
    file_node_t *new = malloc(sizeof(file_node_t));
    if(new == NULL)
      return FAILURE;

    strcpy(new -> f_name , f_name);
    new -> link = NULL;
        
    if(*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }
    file_node_t *temp = *head;
    file_node_t *prev;
    while(temp != NULL)
    {
        if(!strcmp(temp -> f_name, new -> f_name))
        {
            return REPEATED;
        }
        prev =temp;
        temp = temp -> link;
    }
    prev -> link = new;
    return SUCCESS;
    
}