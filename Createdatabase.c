#include "InvertedSearch.h"


int create_DB(file_node_t *file_head, main_node_t *hash[],file_node_t** nhead)
{
    
    char word[NAMELENGTH];
    file_node_t *temp = file_head;
    while(temp)
    {
        int flag = 0;
        file_node_t *temp1 = *nhead;
         while(temp1)
         {
            if(!strcmp(temp1 -> f_name, temp ->f_name ))
            {
                flag = 1;
                break;
            }
            temp1 = temp1 -> link;
         }

         if(flag == 0)
         {
            insert_at_last(nhead,temp->f_name);
            FILE *fptr = fopen(temp->f_name,"r");


        while(fscanf(fptr,"%s",word) != EOF)
        {
            int index;
            if(word[0] >= 'A' && word[0]<= 'Z' || word[0] >= 'a' && word[0] <='z')
            {
            index = tolower(word[0]) - 97;
            }
            else
            {
              index=26;
            }  

            if(hash[index] == NULL)
            {
                //create main node
                hash[index]=Createmainnode(word,temp->f_name);          
            }
            else 
            {            
              main_node_t *t1 = hash[index];
              main_node_t *p1 = NULL;
              sub_node_t *t2 = NULL;
              sub_node_t *p2 = NULL;
              //check word exist or not
              while(t1)
              {      
                if(!strcmp(t1->word,word))
                {
                
                    t2 = t1 -> sub_link;
                    while(t2)
                    {
                        if(!strcmp(t2->f_name,temp->f_name))
                        {
                            (t2 -> w_count)++;
                            break;
                            
                        }
                        p2=t2;
                        t2 = t2 -> slink;
                      
                    }
                    if(t2 == NULL)
                    {
                        p2->slink = CreateSubnode(temp->f_name);
                        (t1 -> f_count)++;
                
                    }
                       
                    
                     break;
              
                }
                p1=t1;
                t1 = t1-> mlink;
              }

              if(t1 == NULL)
              {
    
                p1->mlink = Createmainnode(word,temp->f_name);
              }
           
            }
        }
    
         }
        temp = temp->link;
        
    }

return SUCCESS;

}

main_node_t* Createmainnode(char *word,char *filename)
{
    main_node_t *m_new = malloc(sizeof(main_node_t));
    if(m_new == NULL)
    {
         return NULL;
    }

    //update the contents of mainnode          
    strcpy(m_new -> word , word);
    m_new -> f_count =  1;
    m_new -> mlink = NULL;
    m_new -> sub_link =  CreateSubnode(filename);

     return m_new;
}


sub_node_t* CreateSubnode(char *fname) 
{

    sub_node_t *s_new = malloc(sizeof(sub_node_t));
    if(s_new == NULL)
    {
         return NULL;
    }

     //update the contents of mainnode and subnode         
    s_new -> w_count = 1;
    strcpy(s_new -> f_name,fname);
    s_new -> slink = NULL;

    return s_new;
}