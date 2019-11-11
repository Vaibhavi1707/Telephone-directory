#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data_base
{
	char name[50];	
	char phone1[15];
	char phone2[15];
	char email[50];
	char address[100];
	char occupation[10];
};
int main()
//NA KRNA HAI - KI JAGAH
{
	FILE *fp;
	int prefrence;
	int n;
	printf("HOW MANY NUMBER OF CONTACTS YOU WANT TO ADD ? ");
	scanf("%d",&n);
	printf("NOTE : Enter '-' if you donot have that particular type of info\n");
	struct data_base info;
	fp=fopen("data_base.txt","a");

	//if(fp==NULL)
		//printf("FILE IS MISSING\n");
	while(n > 0)	
	{
		printf("Enter full name(separate by -) : ");
		scanf("%s",info.name);
		fputs(info.name,fp);
		fprintf(fp,"\t");
		printf("Enter phone number1 : ");
		scanf("%s",info.phone1);
		fputs(info.phone1,fp);
		fprintf(fp,"\t");
		printf("Enter phone number2 : ");
		scanf("%s",info.phone2);
		fputs(info.phone2,fp);
		fprintf(fp,"\t");
		printf("Enter email : ");
		scanf("%s",info.email);
		fputs(info.email,fp);
		fprintf(fp,"\t");
		printf("Enter address(separate by -) : ");
		scanf("%s",info.address);
		fputs(info.address,fp);
		fprintf(fp,"\t");
		printf("Enter occupation(separate by -) : ");
		scanf("%s",info.occupation);
		fputs(info.occupation,fp);
		fprintf(fp,"\t");
		//fwrite(&info,sizeof(info),1,fp);
		n--;
		fprintf(fp,"\n");
		if(n>0)
		{
			printf("Do you want to continue(Press 1 for YES and Press 0 for NO) : ");
			scanf("%d",&prefrence);
			if(prefrence == 0)
			{
				break;
			}
			else if(prefrence != 1)
			{
				printf("give a proper response\n");
				scanf("%d",&prefrence);
				if(prefrence == 0)
					break;
				else if(prefrence == 1)
					continue;
				else
					break;
			}
		else if(n == 0)
			break;
		else
			continue;
		}	 
	}
	printf("\nData accepted successfully...");
	fclose(fp);
	return 0;
}
