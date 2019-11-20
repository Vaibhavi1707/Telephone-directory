#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int file_lines(FILE *);
void Starring_Contacts();
int file_lines(FILE *f)
{
char c;
int count=0;
while((c=getc(f))!=EOF)
{
	if(c=='\n')
	count++;
}
return count;
}
struct starred
{
	char *name;
	char *ph_no;
};
struct starred star[1000];		
struct spam_contacts
{
        char *name;
        char *ph_no;
};
struct spam_contacts spam[1000];		
struct Contacts
{
	char *name;
	char *ph_no;
};
int Search_Contacts(char *,FILE *,struct Contacts[]);
void Starring_Contacts()
{
	FILE *fContacts=fopen("Contacts.txt","r");
	FILE *fstar=fopen("StarContacts.txt","w");
	FILE *fspam=fopen("SpamContacts.txt","w");
	struct Contacts contact[file_lines(fContacts)];
	for(int i=0;i<file_lines(fstar);i++)
	{
		fscanf(fstar,"%s",star[i].name);
		fscanf(fstar,"\t%s\n",star[i].ph_no);
	}
	int starlength=file_lines(fstar);
	for(int i=0;i<file_lines(fspam);i++)
	{
		fscanf(fstar,"%s",spam[i].name);
		fscanf(fstar,"\t%s\n",spam[i].ph_no);
	}
	int spamlength=file_lines(fspam);
	int status=0;
	while(status==0)
	{
		int ch;
		printf("Enter 1 for starring a contact\n");
		printf("Enter 2 for marking a contact as spam\n");
		printf("Enter 3 for unstarring a contact\n");
		printf("Enter 4 for removing a contact from the spam contacts list");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:printf("Enter the name of the contact to be starred\n");
			char name[1000],number[10];
			scanf("%s",name);
			printf("Enter the contact number of the contact to be starred\n");
			scanf("%s",number);
			if(Search_Contacts(number,fContacts,contact)==1)
			{	
				printf("Sorry the contact cannot be found");
			}
			else
			{
				int last_index=starlength,c=0;
				star[last_index].name=name;
				star[last_index].ph_no=number;
				printf("The contact is starred.\nEnter 1 for viewing the changes\n");
				for(int i=0;i<starlength+1;i++)
				{
					fprintf(fspam,"%s\t%s\n",star[i].name,star[i].ph_no);
				}				
				if(c==1)
				{
					while((c=getc(fstar))!=EOF)
					{
						putc(c,stdout);
					}
				}
			}
			break;
		case 2:printf("Enter the name of the contact to be marked as spam\n");
		       char spam_name[1000],spam_number[10];
		       scanf("%s",spam_name);
		       printf("Enter the number of the contact to be marked as spam\n");
                       scanf("%s",spam_number);
			if(Search_Contacts(spam_number,fContacts,contact)==1)
			{
				printf("Sorry the contact cannot be found");
			}
			else
			{
				int spam_index=spamlength;
				spam[spam_index].name=spam_name;
                                spam[spam_index].ph_no=spam_number;
                                printf("The contact is marked as spam.\nEnter 1 for viewing the changes\n");
				for(int i=0;i<spamlength+1;i++)
				{
					fprintf(fspam,"%s\t%s\n",spam[i].name,spam[i].ph_no);
				}
				int c;
				scanf("%d",&c);
                                if(c==1)
				{
                                while((c=getc(fspam))!=EOF)
					{
						putc(c,stdout);
					}
                                }      
                        }
        		break;
		case 3:printf("Enter the name of the contact to be unstarred\n");
                        char unstar_name[1000],unstar_number[10];
                        scanf("%s",unstar_name);
                        printf("Enter the contact number of the contact to be starred\n");
                        scanf("%s",unstar_number);
                        if(Search_Contacts(unstar_number,fContacts,contact)==1)
                        {       
                                printf("Sorry the contact cannot be found");											
                        }												
																																			

			else{	
				int flag=0,loc;												
				for(int k=0;k<starlength;k++)										
				{
					if(strcmp(star[k].ph_no,unstar_number)==0)
					{
						flag=1;
						loc=k;
						break;
					}
				}
				if(flag==0)
				{
					printf("The contact is not starred");
				}
				else
				{
					for(int j=loc;j<starlength-1;j++) 
					{
						star[j].name=star[j+1].name;
						star[j].ph_no=star[j+1].ph_no;
					}
					if(loc==starlength-1)
					{
						star[starlength-1].name="";
						star[starlength-1].ph_no="";
					} 
					for(int i=0;i<file_lines(fstar)-1;i++)
					{
						fprintf(fstar,"%s\t%s\n",star[i].name,star[i].ph_no);
					}
                                 	printf("The contact is unstarred.\nEnter 1 for viewing the changes\n");
	                                int c;
        	                        scanf("%d",&c);
        	                        if(c==1)
                	                {
                        	              while((c=getc(fstar))!=EOF)
						{
							putc(c,stdout);
						}  
                                	}
      				}}
                                break;
		case 4:printf("Enter the name of the contact to be deleted from the spam list\n");
                        char unspam_name[1000],unspam_number[10];
                        scanf("%s",unspam_name);
                        printf("Enter the contact number of the contact to be starred\n");
                        scanf("%s",unspam_number);
                        if(Search_Contacts(unspam_number,fContacts,contact)==1)
                        {
                                printf("Sorry the contact cannot be found");
                        }
                        else
                        {
                                int flag=0,loc;
                                for(int k=0;k<spamlength;k++)
                                {
                                        if(strcmp(spam[k].ph_no,unspam_number)==0)
                                        {
                                                flag=1;
                                                loc=k;
                                                break;
                                        }
                                }
                                if(flag==0)
                                {
                                        printf("The contact is not marked as spam");
                                }
                                else
                                {
                                        for(int j=loc;j<spamlength-1;j++)
                                        {
                                                spam[j].name=spam[j+1].name;
                                                spam[j].ph_no=spam[j+1].ph_no;
                                        }
                                        if(loc==spamlength-1)
                                        {
                                                spam[spamlength-1].name="";
                                                spam[spamlength-1].ph_no="";
                                        }
					for(int i=0;i<spamlength-1;i++)
					{
						fprintf(fspam,"%s\t%s\n",spam[i].name,spam[i].ph_no);
					}
                                        printf("The contact is removed from the spam list.\nEnter 1 for viewing the changes\n");
                                        int c;
                                        scanf("%d",&c);
                                        if(c==1)
                                        {
                                                while((c=getc(fspam))!=EOF)
						{
							putc(c,stdout);
						}  
                                        }
                                }
			}
			break;
		default:printf("Invalid Input");
		}
	printf("Enter 0 to continue.\nEnter 1 to exit");
	scanf("%d",&status);
	}
}
int Search_Contacts(char* no,FILE *f,struct Contacts contact[])
{
	    int flag=1,loc;
                for(int i=0;i<file_lines(f);i++)
                {
                        if(strcmp(contact[i].ph_no,no)==0)
                        {
                                flag=0;
                                loc=i;
                                break;
                        }
                }
		return flag;
}
int main()
{
	Starring_Contacts();
}
