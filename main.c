#include "InvertedSearch.h"
/*
Name : Chetan Kumar
date : 23-12-2023
project : Inverted Search
*/
int main(int argc,char *argv[])
{
    char choose;
    int op;
    char file[NAMELENGTH];
    char word[NAMELENGTH];
    char Ufile[NAMELENGTH];
    //create hash table
    main_node_t *hash[SIZE] = {NULL};
    //validate the arguments
    if(argc <= 1)
    {
        printf("Please enter the valid number of arguments\n");
        printf("./result.exe file1.txt file2.txt ......\n");
        return 0;
    }

     
    //declare head pointer
    file_node_t *f_head = NULL;
    file_node_t *n_head = NULL;
    
    if(validate_n_store_filenames(&f_head,argv)==SUCCESS)
    {
        printf("Read and validate succesfull\n");
    }
    
    do{  
    printf("Select your choice amoung the following option :\n1.Create DATABASE\n2.Display DATABASE\n3.SEARCH DATABASE\n4.Save DATABASE\n5.UPDATE DATABASE\n");
    scanf("%d",&op);
    switch(op)
    {
        case 1: 
            if(create_DB(f_head,hash,&n_head)==SUCCESS)
            printf("database created successfully\n");
            break;
        case 2: 
            display_DB(hash);
            break;
        case 3:
            printf("Enter the word that you want you search\n");
            scanf("%s",word);
            search_DB(hash, word);
            break;
        case 4:
            printf("Enter the filename :\n");
            scanf("%s",file);
            if(save_DB(hash,file) == SUCCESS)
            printf("DATABASE saved successfully\n");
            break;
        case 5:
            printf("Enter the file that you want update\n");
            scanf("%s",Ufile);
            if(update_DB(hash,Ufile,&n_head)==SUCCESS)
            printf("Database updated\n");
            
            break;
        default:
            printf("Invalid : choice!!!\n");
            break;    
    }  
  

     
     printf("Do you want to continue(y/n): \n");
     getchar();
     scanf("%c", &choose);  

    
     }while(choose == 'y' || choose == 'Y');

return 0;


}
