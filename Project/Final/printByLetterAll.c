#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printByLetterAll(Dictionary dictionary[], int max_species){
	int x=0,y=0,count=0;
	int only_index=0;
	//int sr=0;
	//char *serial_no[10];
	char inp[40];
	char *dump=malloc(10);
	printf("Search by letters:\t");
	fgets(dump,2,stdin);
	fgets(inp,40,stdin);
	//scanf("%s",inp);
	int len=strlen(inp);
	len--;
	ucase(inp);
	for(int i=0;i<max_species;i++){
				if(dictionary[i].name[x]==inp[y])
                {
					x++;
					y++;

					while(dictionary[i].name[x]==inp[y])
                    {
						if(inp[y]==0 || dictionary[i].name[x]==0)
							break;
						x++;
						y++;
					}
					if(inp[y]=='\0')
						y--;
					if(y==len)
                    {
						count++;
						if(count==1)
							only_index=i;
						printf("\n\t%s\t%s",dictionary[i].sr_no,dictionary[i].name);
						//serial_no[sr]=malloc(1000);
						//strcpy(serial_no[sr],dictionary[i].sr_no);
						//printf("%s",serial_no[sr]);
						//sr++;
						break;
					}
				}
				else{
					x++;
					y=0;
				}
				if(dictionary[i].name[x]=='\0')
					break;


			x=0;
			y=0;

	}
	if(count==1){
		printf("\t%s",dictionary[only_index].des);
	}
	//serial_no[sr]="000";
	else if (count>1){
		int c=0;
		char srno[5];
		char *dump=malloc(1000);
		printf("Enter the serial no. of the species to be printed:\t");
		//fgets(dump,1000,stdin);
		fgets(srno,10,stdin);
		//printf("%s",srno);
		while(c!=1){
					for(int j=0;j<37;j++){
						if(strcmp(srno,dictionary[j].sr_no)==0){
							printf("\n\t%s\n\t%s",dictionary[j].name,dictionary[j].des);
							c++;
							break;
						}
					}


			if(c==0){
				printf("ERROR: Invalid input. Please enter any serial no as shown above:\t");
				//fgets(dump,1000,stdin);
				fgets(srno,10,stdin);
			}
		}
	}
	//printf("Count = %d\n",count);
	return count;
}
