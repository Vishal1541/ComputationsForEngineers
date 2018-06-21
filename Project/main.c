#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*Declaring a structure for the contents of Dictionary. It contains the
 *Serial No
 *Animal/Bird names
 *Description of that animal/bird
 */
 
typedef struct dict{
	char sr_no[4];
	char category[20];
	char name[30];
	char *des;
}Dictionary;

	Dictionary dictionary[100];

int total_Species;
void ucase(char s[]){
	int i=0;
	while(s[i]!=0){
		if(s[i]>='a' && s[i]<='z'){
			s[i]=s[i]-32;
		}
		i++;
	}
}
int startingInput(){
	printf("Select the serial no of the operation to be performed:\n");
	printf("1.\tSearch by Letter\n");
	printf("2.\tShow all categories\n");
	printf("3.\tShow all species from all categories\n");
	printf("4.\tHelp\n");
	int i;
	char *dump=malloc(1000);
	scanf("%d",&i);
	while(!(i>0&&i<5)){
		printf("ERROR: Invalid input. Please enter integer 1/2/3/4:\t");
		/*to clear the buffer storage in the memory,
		 *as charcter is stored in the buffer,
		 *and only character can clear another character
		 */
		fgets(dump,1000,stdin);
		scanf("%d",&i);
	}
	return i;
}
/*Giving choice of input after selecting the category
 */
int optionInput(){
	printf("\nSerial No.\t|\t\tOperation\n");
	printf("-----------------------------------------------------------------------------------------\n");
	printf("\t1.\t|\tList all the names of birds and animals of the chosen category.\n");
	printf("\t2.\t|\tSearch by letters or words.\n");
	printf("\nEnter the serial no of the operation to be performed:\t");
	int i;
	char *dump=malloc(1000);
	scanf("%d",&i);
	while(i!=1 && i!=2){
		printf("ERROR: Invalid input. Please enter integer 1 or 2:\t");
		/*to clear the buffer storage in the memory,
		 *as charcter is stored in the buffer,
		 *and only character can clear another character
		 */
		fgets(dump,1000,stdin);
		scanf("%d",&i);
	}
	return i;
	
}

void openReadMeTXT(){
	FILE *f=fopen("readme","r");
	char *line;
	/*allocating dynamic memory to the character pointer
	 */
	line=malloc(sizeof(char));
	while(!feof(f)){
		fgets(line,10,f);
		printf("%s",line);
	}
}
/*Listing all the categories at the starting of the program
 */
int showCategory(){
	printf("\t1.\tWild Cats\n");
	printf("\t2.\tDogs\n");
	printf("\t3.\tRodents\n");
	printf("\t4.\tShrews\n");
	printf("\t5.\tCivets\n");
	printf("\t6.\tMongoose\n");
	printf("\t7.\tIndian Wild Boar\n");
	printf("\t8.\tPrimates\n");
	printf("\t9.\tHares\n");
	printf("\t10.\tDeer\n");
	printf("\t11.\tBats\n");
	printf("\t12.\tSnakes\n");
	printf("\t13.\tLizards\n");
	printf("\t14.\tToads\n");
	printf("\t15.\tShow all birds/animals from all categories.\n\n");
	
	printf("Enter the serial no of the category to be chosen:\t");
	int i;
	char *dump=malloc(1000);
	scanf("%d",&i);
	while(!(i>=1 && i<=15)){
		printf("ERROR: Invalid input. Please enter valid serial no:\t");
		/*to clear the buffer storage in the memory,
		 *as charcter is stored in the buffer,
		 *and only character can clear another character
		 */
		fgets(dump,1000,stdin);
		scanf("%d",&i);
	}
	return i;
}
/*Printing all the species of chosen category
 */
void printSelectedCategory(int i,int max_species,char *allCat[]){
	for(int x=0;x<max_species;x++){
		if(strcmp(dictionary[x].category,allCat[i-1])==0){
			printf("\t%s\t->%s",dictionary[x].sr_no,dictionary[x].name);
		}
	}
}
/*Printing the description of the selected species
 *under a specific category
 */
void printSelectedCategorySpecies(int cat_sno, char *allCat[], int max_species){
	char k[5];
	char *dump=malloc(1000);
	int c=0;	
	printf("\n\tEnter the Serial number of the species to show its description:\t");
	fgets(dump,1000,stdin);
	fgets(k,5,stdin);
	while(c!=1){
		for(int i=0;i<max_species;i++){
			if(strcmp(dictionary[i].category,allCat[cat_sno-1])==0){
				if(strcmp(dictionary[i].sr_no,k)==0){
					printf("\n\t%s\n\t%s",dictionary[i].name,dictionary[i].des);
					c++;
				}
			}
		}
		if(c==0){
			printf("ERROR: Invalid input. Please enter any serial no as shown above:\t");
			fgets(dump,1000,stdin);
			fgets(k,5,stdin);
			/*scanf("%s",k);
			temp_len=strlen(k);
			k[temp_len]='\n';
			k[temp_len+1]=0;*/
		}
	}
}
/*Printing the list/desc
 *when the user enters by
 *letter/word
 */
int printByLetter(int cat_sno, char *allCat[], int max_species){
	int x=0,y=0,count=0;
	int only_index=0;
	int sr=0;
	char *serial_no[10];
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
		if(strcmp(dictionary[i].category,allCat[cat_sno-1])==0){
			while(1){
				if(dictionary[i].name[x]==inp[y]){
					x++;
					y++;
					
					while(dictionary[i].name[x]==inp[y]){
						if(inp[y]==0 || dictionary[i].name[x]==0)
							break;
						x++;
						y++;
					}
					if(inp[y]=='\0')
						y--;
					if(y==len){
						count++;
						if(count==1)
							only_index=i;
						printf("\n\t%s\t%s",dictionary[i].sr_no,dictionary[i].name);
						serial_no[sr]=malloc(1000);
						strcpy(serial_no[sr],dictionary[i].sr_no);
						//printf("%s",serial_no[sr]);
						sr++;
						break;
					}
				}
				else{
					x++;
					y=0;
				}
				if(dictionary[i].name[x]=='\0')
					break;
				
			}
			x=0;
			y=0;
		}
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
			for(int i=0;i<sr;i++){
				if(strcmp(srno,serial_no[i])==0){
					for(int j=0;j<37;j++){
						if(strcmp(srno,dictionary[j].sr_no)==0){
							printf("\n\t%s\n\t%s",dictionary[j].name,dictionary[j].des);
							c++;
							break;
						}
					}
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
/*Listing all the names of all categories with their serial no
 */
void showAllList(){
	FILE *fdict=fopen("animal.txt","r");	
	int i=0;
	char *l=malloc(1000);
	while(1){
		fgets(l,1000,fdict);	
		i++;
		if(feof(fdict))
			break;
		if(i%4==1)
			printf("\t%s\t`->\t",l);
		else if (i%4==3)
			printf("%s",l);
	}
}
int main(){
	FILE *fdict=fopen("animal.txt","r");
	int index=0,p=0,a=0;
	int end;
	char *temp=malloc(10000);
	while(!feof(fdict)){	
		fgets(temp,1000,fdict);
		p++;
		if(p%4==1)
			strcpy(dictionary[index].sr_no,temp);
		else if(p%4==2)
			strcpy(dictionary[index].category,temp);
		else if(p%4==3)
			strcpy(dictionary[index].name,temp);
		else {
			dictionary[index].des=malloc(1000);
			strcpy(dictionary[index].des,temp);
			}
		if(p%4==0)
			index++;
	}
	total_Species=index;
	//Now value of index = total no of species
	/*/--------------
	for(int i=0;i<index;i++){
		printf("%s%s%s%s",dictionary[i].sr_no,dictionary[i].category,dictionary[i].name,dictionary[i].des);
	}
	*/
	printf("\n\t\t\tWelcome to the Dictionary of birds and animals of IIT Mandi\n");
	printf("-----------------------------------------------------------------------------------------\n\n");
	printf("This dictionary contains all the information about every birds and animals residing in Kamand.\n\n");
	
	int i=showCategory();
	int j=0;
	char *temp_cat[14];
	for(int i=0;i<14;i++)
		temp_cat[i]=malloc(100);
	temp_cat[0]="WILD CATS\n";
	temp_cat[1]="DOGS\n";
	temp_cat[2]="RODENTS\n";
	temp_cat[3]="SHREWS\n";
	temp_cat[4]="CIVETS\n";
	temp_cat[5]="MONGOOSE\n";
	temp_cat[6]="INDIAN WILD BOAR\n";
	temp_cat[7]="PRIMATES\n";
	temp_cat[8]="HARES\n";
	temp_cat[9]="DEER\n";
	temp_cat[10]="BATS\n";
	temp_cat[11]="SNAKES\n";
	temp_cat[12]="LIZARDS\n";
	temp_cat[13]="TOADS\n";
	while(a==0){
	if(i!=15)
		j=optionInput();
	
	if(j==1){
		/*switch(i){
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:printSelectedCategory(i,index,temp_cat);break;
			}*/
		printSelectedCategory(i,index,temp_cat);
		printSelectedCategorySpecies(i,temp_cat,index);
		a=1;
		
	}
	else if(j==2) {		
		a=printByLetter(i,temp_cat,index);
		if(a==0)
			printf("No such species found from the given letters.\n");
	}
	}
	if(i==15){
		showAllList();
		printf("\n\tEnter the Serial number of the species to show its description:\t");
		int z;
		char *dump=malloc(1000);
		scanf("%d",&z);
		while(!(z>=1 && z<=37)){
		printf("ERROR: Invalid input. Please enter valid serial no (between 1 and 37):\t");
		/*to clear the buffer storage in the memory,
		 *as charcter is stored in the buffer,
		 *and only character can clear another character
		 */
		fgets(dump,1000,stdin);
		scanf("%d",&z);
		}
		printf("\n\n\t%s\n\t%s",dictionary[z-1].name,dictionary[z-1].des);
	}
	
	printf("\nFor finding another species enter 1.\n");
	printf("\nFor exiting enter 2.\n");
	scanf("%d",&end);
	char *dump=malloc(1000);
	while(end!=1 && end!=2){
		printf("ERROR: Invalid input. Please enter valid number:\t");
		/*to clear the buffer storage in the memory,
		 *as charcter is stored in the buffer,
		 *and only character can clear another character
		 */
		fgets(dump,1000,stdin);
		scanf("%d",&end);
	}
	if(end==1)
		main();
	else
		exit(1);
	return 0;
}






