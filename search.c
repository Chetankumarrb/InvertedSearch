#include "InvertedSearch.h"

/* Search Database */
int search_DB(main_node_t **hash, char *word)
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
    main_node_t *mtemp = hash[index];
    sub_node_t *stemp = NULL; 
    while(mtemp)
    {
        stemp = mtemp -> sub_link;
        if(!strcmp(mtemp->word,word))
        {
            
            printf("Word '%s' is present in %d files\n",mtemp->word,mtemp->f_count);
            while(stemp)
            {
                printf("In %s '%s' is present %d times\n",stemp->f_name,mtemp->word,stemp->w_count);
                stemp = stemp->slink;
            }
            break;
        }
        mtemp = mtemp -> mlink;
    }
    if(mtemp == NULL)
    {
      printf("Word not Found!!!\n");
    }


return SUCCESS;

 
 }