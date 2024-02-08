#include "InvertedSearch.h"
int display_DB(main_node_t *arr[])
{
    printf("[Index]\t\tword\tFilecount\t\tFilename\tWordcount\n");
    for(int i=0;i<27;i++)
    {
        if(arr[i] == NULL)
        continue;
       
        main_node_t *mtemp = arr[i];
    
        while(mtemp)
        {
            printf("%d\t\t",i);
            printf("%s\t\t",mtemp->word);
            printf("%d\t\t",mtemp->f_count);
            sub_node_t *stemp =  mtemp -> sub_link;
            
            while(stemp)
            {
                printf("%s\t\t",stemp -> f_name);
                printf("%d\t\t",stemp -> w_count);
                stemp = stemp -> slink;
                
            }
            printf("\n");
            mtemp = mtemp -> mlink;
            
        }
       

    }
    return SUCCESS;
}