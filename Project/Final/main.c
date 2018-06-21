#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"start.c"
#include"end.c"
#include"printpic.c"
int end=1;

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

void helpTXT(){
    FILE *fhelp=fopen("help.txt","r");
	char *l=malloc(1000);
	fgets(l,1000,fhelp);
	while(!feof(fhelp))
    {
        printf("%s",l);
        fgets(l,1000,fhelp);
	}
	free(l);
}
//ucase = Upper Case
void ucase(char s[]){
	int i=0;
	while(s[i]!='\0'){
		if(s[i]>='a' && s[i]<='z'){
			s[i]=s[i]-32;
		}
		i++;
	}
}
/*Giving choice of input after selecting the category
 */
int optionInput()
{
    printf("\n\n");
    printf("\t\t\t-------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t|   Serial No.\t|\t\t                 Operation\t\t\t\t\t|\n");
	printf("\t\t\t-------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t|\t1.\t|\tList all the names of birds and animals of the chosen category. \t|\n");
	printf("\t\t\t-------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t|\t2.\t|\tSearch by letters or words.\t\t\t\t\t\t|\n");
	printf("\t\t\t-------------------------------------------------------------------------------------------------\n");
	printf("\n\n\t\t\tEnter the serial no of the operation to be performed:\t");
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

/*Listing all the categories at the starting of the program
 */
int showCategory()
{
    printf("\t\t\t\t\t\t\t\t\t\t");
    for(int i=0;i<11;i++)
        printf("-");
    printf("\n\t\t\t\t\t\t\t\t\t\t| 0. HELP |");
    printf("\n\t\t\t\t\t\t\t\t\t\t");
    for(int i=0;i<11;i++)
        printf("-");

    printf("\n\n\t\t\t\t\t\t\t\t");

    for(int a=0;a<42;a++)
    printf("~");
    printf("\n\t\t\t\t\t\t\t\t| 1.  \tWild Cats\t | 2.  \tDogs     |\n");
    printf("\t\t\t\t\t\t\t\t");
    for(int a=0;a<42;a++)
    printf("-");
	printf("\n\t\t\t\t\t\t\t\t| 3.  \tRodents\t\t | 4.  \tShrews   | \n");
    printf("\t\t\t\t\t\t\t\t");
    for(int a=0;a<42;a++)
    printf("-");
    /*printf(" \t\t\t ");
    for(a=0;a<13;a++)
    printf("-");*/
	printf("\n\t\t\t\t\t\t\t\t| 5.  \tCivets\t\t | 6.  \tMongoose |  ");
	//printf("\t\t\t | 0.  HELP. |\n");
    printf("\n\t\t");
    /*for(a=0;a<42;a++)
    printf("-");*/
    printf(" \t\t\t\t\t\t");
    for(int a=0;a<42;a++)
    printf("-");
    printf("\n\t   | 15. SHOW ALL ANIMALS/BIRDS IN DICTIONARY |");
	printf("\t\t| 7.  \tIndian Wild Boar | 8.  \tPrimates | ");
	printf("\t | 16 . DIRECT SEARCH BY LETTER IN DICTIONARY |");
	//printf("\t| 15.  SHOW ALL BIRDS/ANIMALS FROM ALL CATEGORIES. |\n");
	printf("\n\t\t\t\t\t\t\t\t");
    for(int a=0;a<42;a++)
    printf("-");
    /*printf(" \t");
    for(a=0;a<52;a++)
    printf("-");*/
	printf("\n\t\t\t\t\t\t\t\t| 9.  \tHares\t\t | 10. \tDeer     |  ");
	//printf("\t\t\t | 16.  Search By Letter/Word. |\n");
    printf("\n\t\t\t\t\t\t\t\t");
    for(int a=0;a<42;a++)
    printf("-");
	printf("\n\t\t\t\t\t\t\t\t| 11. \tBats\t\t | 12. \tSnakes   | \n");
    printf("\t\t\t\t\t\t\t\t");
    for(int a=0;a<42;a++)
    printf("-");
	printf("\n\t\t\t\t\t\t\t\t| 13. \tLizards\t\t | 14. \tToads  \t |\n");
	printf("\t\t\t\t\t\t\t\t");
    for(int a=0;a<42;a++)
    printf("~");
    //delay(1500);
	printf("\n\n\n\nEnter the serial no of the category to be chosen:\t");
	int i;
	char *dump=malloc(1000);
	scanf("%d",&i);
	while(!(i>=0 && i<=16))
    {
		printf("ERROR: Invalid input. Please enter valid serial no:\t");
		/*to clear the buffer storage in the memory,
		 *as charcter is stored in the buffer,
		 *and only character can clear another character
		 */
		fgets(dump,1000,stdin);
		scanf("%d",&i);
	}
	if(!(i==0 || i==15 ||i==16)){
        printpic(i);
	}
	return i;
}


/*Printing all the species of chosen category
 */
void printSelectedCategory(int i,int max_species,char *allCat[])
{
	for(int x=0;x<max_species;x++)
    {
		if(strcmp(dictionary[x].category,allCat[i-1])==0)
		{
			printf("\t%s\t->%s",dictionary[x].sr_no,dictionary[x].name);
		}
	}
}
/*Printing the description of the selected species
 *under a specific category
 */
void printSelectedCategorySpecies(int cat_sno, char *allCat[], int max_species){
	char k[50];
	char *dump=malloc(1000);
	int c=0,len;
	printf("\n\tEnter the Serial number of the species to show its description:\t");
	fgets(dump,1000,stdin);
	//Taking input from user: serial no
	fgets(k,50,stdin);
	//printf("%s",k);
	while(c!=1)
    {
		for(int i=0;i<max_species;i++)
		{
			if(strcmp(dictionary[i].category,allCat[cat_sno-1])==0)
			{
				if(strcmp(dictionary[i].sr_no,k)==0)
				{
				    printf("\n");
					//printf("\n\t%s\n%s",dictionary[i].name,dictionary[i].des);
					len=strlen(dictionary[i].name);
					printf("\n\n\n\t\t\t\t\t\t\t\t\t %s",dictionary[i].name);
					printf("\t\t\t\t\t\t\t\t        ");
					for(int j=0;j<len+1;j++)
					printf("=");
					printf("\n\n");
					for(int j=0;j<143;j++)
                        printf("-");
					printf("\n%s",dictionary[i].des);
					for(int j=0;j<143;j++)
                        printf("-");
					c++;
				}
			}
		}

		if(c==0)
		{
			printf("ERROR: Invalid input. Please enter any serial no as shown above:\t");
			//fgets(dump,1000,stdin);
			fgets(k,50,stdin);
		}
	}
}
/*Printing all species irrespective
 *of any category
 *at starting of the program
 */
int printByLetterAll(int max_species){
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
			while(1){
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
	if(count==1)
    {
		printf("\tCategory : %s\n\t%s",dictionary[only_index].category,dictionary[only_index].des);
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
							printf("\n\t%s\n\tCategory : %s\n\t%s",dictionary[j].name,dictionary[j].category,dictionary[j].des);
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
	char *dump=malloc(1000);
	printf("Search by letters:\t");
	fgets(dump,1000,stdin);
	fgets(inp,40,stdin);
	//scanf("%s",inp);
	int len=strlen(inp);
	len--;
	ucase(inp);
	for(int i=0;i<max_species;i++){
		if(strcmp(dictionary[i].category,allCat[cat_sno-1])==0){
			while(1){
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
void showAllList()
{
	FILE *fdict=fopen("animal.txt","r");
	int i=0;
	char *l=malloc(1000);
	while(1)
    {
		fgets(l,1000,fdict);
		i++;
		//Now i=current line in the animal.txt
		if(feof(fdict))
			break;
		if(i%4==1)
			//Printing serial no
			printf("\t%s\t`->\t",l);
			//Printing name
		else if (i%4==3)
			printf("%s",l);
	}
}
int main()
{
     start();
     here:
         clrscr();
    while(end)
    {
	/*a = return value of printByLetter func, just initialising it here as zero
	 *p = total no of lines in animal.txt
	 *index = indices of dictionary[] variable
	 */
        int index=0,p=0,a=0;
        /*temp for reading each line of
         *animal.txt and copying respective
         *strings in the dictionary[] array
         */
        char *temp=malloc(10000);
        FILE *fdict=fopen("animal.txt","r");
        while(!feof(fdict))
            {
                fgets(temp,1000,fdict);
                p++;
                /*In animal.txt 1st line is for serial no
                 *2nd line for category of the bird/animal
                 *3rd line for the name
                 *4th line for the description of the bird/animal
                 */
                if(p%4==1)
                    strcpy(dictionary[index].sr_no,temp);
                else if(p%4==2)
                    strcpy(dictionary[index].category,temp);
                else if(p%4==3)
                    strcpy(dictionary[index].name,temp);
                else if(p%4==0)
                    {
                     /*malloc : as the dictionary[].des is a char pointer to string
                      */
                      dictionary[index].des=malloc(1000);
                      strcpy(dictionary[index].des,temp);
                      index++;
                    }
            }
        total_Species=index;
        //Now value of index = total no of species
        /*/--------------
        for(int i=0;i<index;i++){
            printf("%s%s%s%s",dictionary[i].sr_no,dictionary[i].category,dictionary[i].name,dictionary[i].des);
        }
        */
        printf("\n");
        for(int x=0;x<168;x++)
        printf("=");
        printf("\t\t\t\t\t\t\tWELCOME TO THE DICTIONARY OF BIRDS AND ANIMALS IN IIT MANDI\n");
        for(int x=0;x<168;x++)
        printf("=");
        //delay(800);
        printf("\n\n");
        printf("\t\t\t\t\tTHIS DICTIONARY CONTAINS ALL THE INFORMATION ABOUT BIRDS AND ANIMALS IN IIT MANDI OR NEAR IIT MANDI\n\n\n");
        //delay(1500);
        /*input (1-15) from user stored in
         *int i
         */
        int i=showCategory();
        int j=0;
        /*temp_cat[] for storing all the categories in serial no
         */
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
	/*i==15 means to show all species from all categories
	 *rather than from any particular category
	 */
	 if(i==0){
        clrscr();
        helpTXT();
        char enter[100];
        printf("\n\n\t\t\tEnter any word to continue...");
        scanf("%s",enter);
        clrscr();
        goto here;
	 }
	if(i==15 || i==16)
		a++;
        while(a==0)
        {
            /*optionInput for selecting by serial no or by letters
             *under the selected category
             */
            if(i!=15)
                j=optionInput();
	    //j==1 for searching by serial no
            if(j==1)
                {
                   /*To list the names of the species under
                    *the selected category
                    */
                    printSelectedCategory(i,index,temp_cat);
                    /*To print the description of the selected
                     *species under the selected category
                     */
                    printSelectedCategorySpecies(i,temp_cat,index);
                    //a=1 for coming out of the while loop
                    a=1;

                }
                //j==2 for searching by letters
            else if(j==2)
                {
                /*value of 'a' is equal to number of species found
                 *on searching by letter
                 */
                    a=printByLetter(i,temp_cat,index);
                    if(a==0)
                    printf("No such species found from the given letters.\n");
                }
        }
        if(i==15)
        {
            showAllList();
            printf("\n\tEnter the Serial number of the species to show its description:\t");
            int z;
            char *dump=malloc(1000);
            scanf("%d",&z);

            while(!(z>=1 && z<=37))
            {
                printf("ERROR: Invalid input. Please enter valid serial no (between 1 and 37):\t");
                /*to clear the buffer storage in the memory,
                 *as charcter is stored in the buffer,
                 *and only character can clear another character
                 */
                fgets(dump,1000,stdin);
                scanf("%d",&z);
            }

            printf("\n\n\t%s\n\tCategory : %s\n\t%s",dictionary[z-1].name,dictionary[z-1].category,dictionary[z-1].des);
        }
        else if(i==16){
            int print_all=printByLetterAll(total_Species);
            if(print_all==0){
                printf("\t\t\t\tError : No results found.\n\n");
                delay(2000);
                goto here;
            }
        }

        end=ending();
        //end=0;
    }

	return 0;
}





