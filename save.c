#include "InvertedSearch.h"

int save_DB(main_node_t **arr, char *fname)
{
    FILE *fptr = fopen(fname,"w");
    if(fptr == NULL)
    return FAILURE;
    for(int i=0;i<27;i++)
    {
        if(arr[i] == NULL)
        continue;    
        
        main_node_t *mtemp = arr[i];
    
        while(mtemp)
        {
            fprintf(fptr,"%s","#");
            fprintf(fptr,"%d;",i);
            fprintf(fptr,"%s;",mtemp->word);
            fprintf(fptr,"%d",mtemp->f_count);
            sub_node_t *stemp =  mtemp -> sub_link;
            
            while(stemp)
            {
                fprintf(fptr,"%s",";");
                fprintf(fptr,"%s;",stemp -> f_name);
                fprintf(fptr,"%d",stemp -> w_count);
                stemp = stemp -> slink;
                
            }

            fprintf(fptr,"%s\n","#");
    
            mtemp = mtemp -> mlink;
            
        }         
        }         

    return SUCCESS;
}