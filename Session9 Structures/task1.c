#include<stdio.h>
#include<assert.h>
#include<string.h>


struct aminoAcid{
	char letterName;
	unsigned int numOfOccurrences;
}Protein[26];

void InsertMax (struct aminoAcid array[], int index)
{
int i = index; int valueIndex = array[index].numOfOccurrences; 
struct aminoAcid valueArray=array[index];
while (i > 0 && valueIndex > array[i-1].numOfOccurrences) {
 array[i] = array[i-1];
 i--;
}
array[i]= valueArray;
}

void SortDesc(struct aminoAcid array[], int size){
	int i;
	for(i=1;i<size;i++)
		InsertMax(array, i);
}

int totalOccurrences(struct aminoAcid array[],int size){
	int i,sum=0;
	for(i=0;i<size;i++)
		sum+=array[i].numOfOccurrences;
	return sum;
}
//-------------------------------------------------
int main(){
	int i,j,ch,seqlen,alpha=65;
	char prot[11];
	for(i=0;i<26;i++){
		Protein[i].letterName=alpha++;
		Protein[i].numOfOccurrences=0;
	}
	alpha=65;
	FILE *fp = fopen("seqs.faa","r");
	assert(fp!=NULL);
	int k,total;
	float percent;
	printf("Enter the number of protein from the top order of occurrences to be displayed: ");
	scanf("%d",&k);
	char seq[1000];
	fgets(seq,1000,fp);
	while(seq[0]=='>'){
		int a=1;
		while(seq[a]!=' '){
			prot[a-1]=seq[a];
			a++;
		}
		prot[a-1]='\0';
		printf("The protein in %s has the following amino acid:\n\n",prot);
		fgets(seq,1000,fp);
		seqlen=strlen(seq);
		for(i=0;i<seqlen-1;i++){
			ch=seq[i];
			Protein[ch-65].numOfOccurrences++;
		}
		SortDesc(Protein,26);
		
		total=totalOccurrences(Protein,26);
		for(i=0;i<k;i++){
			percent = Protein[i].numOfOccurrences*100.0/total;
			printf("%c : ",Protein[i].letterName);
			printf("%.2f%\t",percent);
			for(j=0;j<Protein[i].numOfOccurrences;j++)
				printf("*");
			printf("\n");
		}
		for(i=0;i<26;i++){
			Protein[i].letterName=alpha++;
			Protein[i].numOfOccurrences=0;
		}
		alpha=65;
		printf("\n\n");
		fgets(seq,1000,fp);
		
	}
	return 0;
}
