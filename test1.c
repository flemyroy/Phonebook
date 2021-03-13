#include<stdio.h>
#include<string.h>
#include <stdlib.h> 

struct contact_managment {
    char fname[50];
    char lname[50];
    char email[50];
    char primary_contact[10];
    char sec_contact[10];
} ;
struct contact_managment c[100];

void getdata(int n)
{
    FILE *f;
    f=fopen("test.bin","wb");
    if (f==NULL)
    {
     printf("File does not exist");
     exit(0);
    }
    for(int i=0; i<n ;i++)
    {
     printf("\nEnter First Name:");
     scanf("%s", &c[i].fname);
     printf("Last Name:");
     scanf("%s", &c[i].lname);
     printf("Email:");
     scanf("%s",&c[i].email);
     printf("Primary Contact Number:");
     scanf("%s",&c[i].primary_contact);
     printf("Secondary Contact Number:");
     scanf("%s",&c[i].sec_contact );
     fwrite (&c[i], sizeof(c[i]), 1, f); 
    }
    if(fwrite != 0)  
        printf("File written successfully !\n"); 
    else 
        printf("Error writing file !\n"); 
  
    fclose (f); 
}

void showdata(int n)
{   
    FILE *fptr;

   if ((fptr = fopen("test.bin","rb")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   for(int i = 0; i<n; i++)
   {
     fread(&c, sizeof(c), 1, fptr); 
     printf("\nFirst Name: %s",&c[i].fname);
     printf("\nLast Name: %s",&c[i].lname);
     printf("\nEmail: %s",&c[i].email);
     printf("\nPrimary Contact Number: %s",&c[i].primary_contact);
     printf("\nSecondary Contact Number: %s:",&c[i].sec_contact);
     printf("\n");
    }
    
    fclose(fptr);
}

int search(char fname[50])
{
 FILE *fptr;
 int i=0;
 if ((fptr = fopen("test.bin","rb")) == NULL)
   {
     printf("Error! opening file");
     // Program exits if the file pointer returns NULL.
     exit(1);
   }

   while(fread(&c, sizeof(c), 1, fptr) )
   {
        if(fname==c[i].fname)
        {
         printf("\nFirst Name: %s",&c[i].fname);
         printf("\nLast Name: %s",&c[i].lname);
         printf("\nEmail: %s",&c[i].email);
         printf("\nPrimary Contact Number: %s",&c[i].primary_contact);
         printf("\nSecondary Contact Number: %s:",&c[i].sec_contact);
         printf("\n");
        }
        fread(&c, sizeof(c), 1, fptr);
        i++;
   }
}
int main()
{
    
   int n,i,number;
   char option, fname[50];
   do
   {
       printf("Enter your choice: \n 1: Add Records \n 2: Display Records \n 3: Search Record\n");
       scanf("%d", &number);
       switch(number) 
       {
          case 1 :
          {
             printf("Enter Number of Records to be added:");
             scanf("%d",&n);
             getdata(n);
             break;
          }
          case 2 :
          {
    	     printf("Enter Number of Records to be diplayed:");
             scanf("%d",&n);
             showdata(n);
             break;
          }
          case 3 :
             printf("Enter First name to be found:")	;
             scanf("%s",fname); 
    	     search(fname);
             break;
          default:
             printf("Error! Incorrect Value");
        }
        printf("\nDo you want to continue(y/n)?\n");
        scanf("%s", &option);
   }while(option=='y' || option =='Y');

   printf("THANK YOU!!!!");
   return 0;
    
    
}
