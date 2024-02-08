#include "InvertedSearch.h"

/* Update database */
int update_DB(main_node_t *hash[],char *bfile,file_node_t **n_head)
{
    int index;
    char bfileLine[100];
    char word[NAMELENGTH];
    FILE *fptr = fopen(bfile,"r");
    if(fptr == NULL)
    {
        return FAILURE;
    }

    /*reading backupfile line by line*/
    while(fscanf(fptr,"%s",bfileLine) != EOF)
    {
        if(bfileLine[0] != '#')
        return FAILURE;
        
        //extracting index
        index = atoi(strtok(bfileLine,";#"));
        

       //create main node
       main_node_t *m_new = malloc(sizeof(main_node_t));
       if(m_new == NULL)
       return FAILURE;
       
       strcpy(m_new -> word, strtok(NULL,"#;"));
       m_new -> f_count = atoi(strtok(NULL,"#;"));  
    
    
       m_new -> mlink = NULL;


        //create subnode 
        sub_node_t *s_new = malloc(sizeof(sub_node_t));
        if(s_new == NULL)
        return FAILURE;
        
        strcpy(s_new -> f_name, strtok(NULL,"#;"));
        insert_at_last(n_head,s_new->f_name);
        s_new -> w_count = atoi(strtok(NULL,"#;"));
        s_new -> slink = NULL;
        m_new -> sub_link = s_new;
        sub_node_t *s_temp =s_new;
    
       for(int i=0; i<(m_new->f_count)-1;i++)
       {
        sub_node_t *s_new = malloc(sizeof(sub_node_t));
        if(s_new == NULL)
        return FAILURE;

        strcpy(s_new -> f_name, strtok(NULL,"#;"));
        
        insert_at_last(n_head,s_new->f_name);

        s_new -> w_count = atoi(strtok(NULL,"#;"));
        s_new -> slink = NULL;
        s_temp -> slink = s_new;
        s_temp = s_new;
       }

       //store it in hash table
       main_node_t *temp = hash[index];
       if(temp == NULL)
       {
        hash[index] = m_new;
       }
       else
       {
        while(temp -> mlink)
        {
            temp = temp->mlink;
        }
        temp ->mlink = m_new;

       }
         
    }

fclose(fptr);
return SUCCESS;


}


int insert_at_last(file_node_t **n_head, char f_name[])
{

        if(*n_head == NULL)
        {
            file_node_t *new = malloc(sizeof(file_node_t));
            if(new == NULL)
            return FAILURE;
            strcpy(new -> f_name, f_name);
            new -> link = NULL;
            *n_head = new;
        }
        else
        {
            file_node_t *temp = *n_head;
            file_node_t *prev;
            while(temp != NULL)
            {
            prev =temp;
            temp = temp -> link;
            }
            file_node_t *new = malloc(sizeof(file_node_t));
            if(new == NULL)
            return FAILURE;
            strcpy(new -> f_name,f_name);
            new -> link = NULL;
            prev -> link = new;
        }
        

       return SUCCESS;
}
