#include<stdio.h>
#include<string.h>
#include <stdlib.h> 

struct contact_managment {
    char fname[10];
    char lname[10];
    char email[10];
    long primary_contact;
    long sec_contact;
} ;
struct contact_managment c[10];

void getdata(int n)
{
    FILE *f;
    f=fopen("test1.dat","w");
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
     scanf("%d",&c[i].primary_contact);
     printf("Secondary Contact Number:");
     scanf("%d",&c[i].sec_contact );
     fwrite (&c[i], sizeof(c[i]), 1, f); 
    }
    if(fwrite != 0)  
        printf("contents to file written successfully !\n"); 
    else 
        printf("error writing file !\n"); 
  
    // close file 
    fclose (f); 
}

void showdata(int n)
{   
    for (int i=0;i<n;i++)
    {
     printf("\nFirst Name: %s",&c[i].fname);
     printf("\nLast Name: %s",&c[i].lname);
     printf("\nEmail: %s",&c[i].email);
     printf("\nPrimary Contact Number: %d",&c[i].primary_contact);
     printf("\nSecondary Contact Number: %d:",&c[i].sec_contact);
     printf("\n");
    }
}
int main()
{
    
    int n,i;
    printf("Enter Number of Records to be added:");
    scanf("%d",&n);
    getdata(n);
    showdata(n);
    return 0;
    
    
}
