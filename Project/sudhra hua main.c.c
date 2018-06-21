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
    printf("\t");
    for(int a=0;a<50;a++)
    printf("-");
    printf("\n\t| 1.\tWild Cats\t |\t2.\tDogs     |\n");
    printf("\t");
    for(int a=0;a<50;a++)
    printf("-");
	printf("\n\t| 3.\tRodents\t\t | \t4.\tShrews   |\n");
    printf("\t");
    for(int a=0;a<50;a++)
    printf("-");
	printf("\n\t| 5.\tCivets\t\t | \t6.\tMongoose |\n");
    printf("\t");
    for(int a=0;a<50;a++)
    printf("-");
	printf("\n\t| 7.\tIndian Wild Boar | \t8.\tPrimates |\n");
    printf("\t");
    for(int a=0;a<50;a++)
    printf("-");
	printf("\n\t| 9.\tHares\t\t | \t10.\tDeer   \t |\n");
    printf("\t");
    for(int a=0;a<50;a++)
    printf("-");
	printf("\n\t| 11.\tBats\t\t | \t12.\tSnakes \t |\n");
    printf("\t");
    for(int a=0;a<50;a++)
    printf("-");
	printf("\n\t| 13.\tLizards\t\t | \t14.\tToads \t |\n");
	printf("\t");
    for(int a=0;a<50;a++)
    printf("-");
    	printf("\n\t");
    for(int a=0;a<52;a++)
    printf("-");
	printf("\n\t| 15.\tShow all birds/animals from all categories.|\n");
    	printf("\t");
    for(int a=0;a<52;a++)
    printf("-");

	printf("\nEnter the serial no of the category to be chosen:\t");
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
		}
	}
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
	int index=0,p=0;
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
	if(i!=15)
		j=optionInput();

	if(j==1){/*
		switch(i){
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
			case 14:*/printSelectedCategory(i,index,temp_cat);break;
			}
		printSelectedCategorySpecies(i,temp_cat,index);
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

	printf("\n");
	return 0;
}
