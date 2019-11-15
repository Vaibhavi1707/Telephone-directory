#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int string_compare(char array1[100], char array2[100])
{
  int compare=0, count=0, i;
  if(strlen(array1)==strlen(array2))
  {
    for(i=0;i<strlen(array1);i++)
    {
      if(array1[i]==array2[i] || abs((int)array1[i]-(int)array2[i])==32)
      count++;
    }
    if(count!=strlen(array1))
      compare=1;
  }
  else
    compare=1;
  return compare;
}

void garbage_handle(char array[175])
{
  int length=0;
  while(array[length]!='\0')
  {
    printf("%c",array[length]);
    length++;
  }
}

void print2D(char array2d[7][175])
{
  printf("\n");
  printf("Name                : ");
  garbage_handle(array2d[0]);
  printf("\nPhone Number        : ");
  garbage_handle(array2d[1]);
  if(array2d[2][0]!='-')
  { 
    printf("\n                      ");
    garbage_handle(array2d[2]);
  }
  if(array2d[3][0]!='-')
  {
    printf("\nEmail Address       : ");
    garbage_handle(array2d[3]);
  }
  if(array2d[4][0]!='-')
  {
    printf("\nResidential Address : ");
    garbage_handle(array2d[4]);
  }
  if(array2d[5][0]!='-')
  {
    printf("\nOccupation          : ");
    garbage_handle(array2d[5]);
  }
  if(array2d[6][0]!='-')
  {
    printf("\nDate of Birth       : ");
    garbage_handle(array2d[6]);
  }
  printf("\n");
}

void search(void)
{
  FILE* fp=fopen("data_base.txt","a+");
  char single_contact[2000];
  char details[7][175];
  char name_2Darray[6][50];
  char occupation_2Darray[6][50];
  int search_choice, row, column, dashes, i, j, check=0, r, c;
  printf("Please select the appropriate option to search through in the directory\n");
  printf("Enter\n");
  printf("1 for searching through NAME\n");
  printf("2 for searching through PHONE NUMBER\n");
  printf("3 for searching through EMAIL ADDRESS\n");
  printf("4 for searching through OCCUPATION\n");
  printf("5 for searching through DATE OF BIRTH\n");
  scanf("%d",&search_choice);
  char search_name[50];
  char search_phone[50];
  char search_email[50];
  char search_occupation[50];
  char search_dob[50];
  switch(search_choice)
  {
    case 1: system("clear");
            printf("Please enter the name to be searched in the directory\n");
            scanf("%s",search_name);
            search_name[strlen(search_name)]='\0';
            break;
  
    case 2: system("clear");
            printf("Please enter the phone number to be searched in the directory\n");
            scanf("%s",search_phone); 
            search_phone[10]='\0';
            break;

    case 3: system("clear");
            printf("Please enter the email address to be searched in the directory\n");
            scanf("%s",search_email);
            break;
    
    case 4: system("clear");
            printf("Please enter the occupation to be searched in the directory\n");
            scanf("%s",search_occupation);
            break;

    case 5: system("clear");
            printf("Please enter the date of birth in dd/mm/yyyy format to be searched in the directory\n");
            scanf("%s",search_dob);
            break;
    
    default: printf("You are requested to make a valid input choice");
             break;
  }
  while(!feof(fp))
  {
    fgets(single_contact,1999,fp);
    row=0;
    column=0;
    for(i=0;i<strlen(single_contact);i++)
    {
      if(single_contact[i]!='\t')
      {
        details[row][column]=single_contact[i];
        column++;
      }
      else
      {
        row++;
        column=0;
      }
    }
    switch(search_choice)
    {
      case 1: dashes=0;
              details[0][strlen(details[0])]='\0';
              details[1][10]='\0';
              for(i=0;i<strlen(details[0]);i++)
              {
                if(details[0][i]==' ')
                dashes++;
              }
              r=0;
              c=0;
              for(i=0;i<strlen(details[0]);i++)
              {
                if(details[0][i]!=' ')
                {
                  name_2Darray[r][c]=details[0][i];
                  c++;
                }
                else
                { 
                  r++;
                  c=0;
                }
              }
              for(i=0;i<dashes+1;i++)
              { 
                if(string_compare(name_2Darray[i],search_name)==0)
                {
                  print2D(details);
                  check=1;
                  break;
                }
              }
              for(i=0;i<6;i++)
              {
                for(j=0;j<50;j++)
                  name_2Darray[i][j]='\0';
              }
              break;
 
      case 2: details[1][10]='\0';
              if(string_compare(details[1],search_phone)==0 || strcmp(details[2],search_phone)==0)
              {
                print2D(details);
                check=1;
              }
              break;
 
      case 3: if(string_compare(details[3],search_email)==0)
              {
                print2D(details);
                check=1; 
              }
              break;
 
      case 4: dashes=0;
              for(i=0;i<strlen(details[5]);i++)
              {
                if(details[5][i]==' ')
                dashes++;
              }
              r=0;
              c=0;
              for(i=0;i<strlen(details[5]);i++)
              {
                if(details[5][i]!=' ')
                {
                  occupation_2Darray[r][c]=details[5][i];
                  c++;
                }
                else
                { 
                  r++;
                  c=0;
                }
              }
              for(i=0;i<dashes+1;i++)
              {
                if(string_compare(occupation_2Darray[i],search_occupation)==0)
                {
                  print2D(details);
                  check=1;
                  break;
                } 
              }
              for(i=0;i<6;i++)
              {
                for(j=0;j<50;j++)
                  occupation_2Darray[i][j]='\0';
              }
              break;

      case 5: details[6][10]='\0';
              if(string_compare(details[6],search_dob)==0)
              {
                print2D(details);
                check=1;
              }
              break;
    }
    for(i=0;i<7;i++)
    {
      for(j=0;j<175;j++)
        details[i][j]='\0';
    }
  }
  if(check==0 && search_choice==1 && search_choice==2 && search_choice==3 && search_choice==4 && search_choice==5)
    printf("\nNO Match found\n");
}    
