/****************************
*  Developer : joshi08
*  Date  :  23-06-2020
*  Year  :  2020
****************************/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	char c;
	bool end;
	char meaning[100];
	char word[50];
	struct node *child[26];
};
struct node *start;
int counter=0;



void insert(char word[], char meaning[])
{
	int i;
	counter++;
	if(start == NULL)
	{
		start = (struct  node*) malloc(sizeof(struct node));
		for(i=0;i<26;i++)
		{
			start->child[i] = NULL;
		}
	}

	struct node *temp = start, *ptr;
	for(i=0;i<strlen(word);i++)
	{
		int index = word[i] - 'a';
		if(temp->child[index]==NULL)
		{
			temp->child[index] = (struct  node*) malloc(sizeof(struct node));
			char t[50];
			strcpy(t,temp->word);
			strncat(t,&word[i],1);
			strcpy(temp->child[index]->word,t);
		}
		//printf("\n%c\n",word[i]);
		//temp->child[index]->word = temp->word  + word[i];

		temp = temp->child[index];
		//printf("\n%s\n",temp->word);
	}
	temp->end = true;
	for(i=0;i<26;i++)
	{
		temp->child[i] = NULL;
	}
	strcpy(temp->meaning,meaning);

	printf("\nWord successfully registered!!!");
}


//Just like DFS in trees
void search_similar(struct node* temp)
{
	int i;
	if(temp->end==true)
	{
		printf("%s  ",temp->word);
	}

	for(i=0;i<26;i++)
	{
		if(temp->child[i]!=NULL)
			search_similar(temp->child[i]);
	}
}


void find(char word[])
{
	int i;
	if(start==NULL)
		printf("\nDictionary is Empty!!!");
	else
	{
		struct node *temp = start, *ptr;

		for(i=0;i<strlen(word);i++)
		{
			int index = word[i] - 'a';
			if(temp->child[index]!=NULL)
			{
				temp = temp->child[index];
			}
			else
			{
				break;
			}
		}

		if(i==strlen(word) && temp->end==true)
		{
			printf("\nMeaning of '%s' =  %s\n",word,temp->meaning);
		}
		else
		{
			printf("\nSorry, Word not found in Dictionary.");
			printf("\n\nAre you looking for : ");

			//printf("%s",temp->word);
			search_similar(temp);
		}
	}
}





int main()
{

	printf("\n\nWelcome to the Dictionary!!!\n");

	printf("         ,..........   ..........,");
	printf("\n     ,..,'          '.'          ',..,");
	printf("\n    ,' ,'  A         :    D       ', ',");
	printf("\n   ,' ,'  B          :   E         ', ',");
	printf("\n  ,' ,'  C           :  F           ', ',");
	printf("\n ,' ,'............., : ,.............', ',");
	printf("\n,'  '............   '.'   ............'  ',");
	printf("\n'''''''''''''''''';''';''''''''''''''''''");
	printf("\n                   '''");

	int i,n,m,k;

	while(true)
	{
		printf("\n\n\n        Press: ");
		printf("\n     |*******************************|\n");
		printf("     |  1 to Enter a new word        |\n");
		printf("     |  2 to Find meaning of a word  |\n");
		printf("     |  3 to Check Dictionary status |\n");
		printf("     |  4 to Exit                    |\n");
		printf("     |*******************************|\n");

		printf("\nWaiting for your choice => ");
		scanf("%d",&n);
		char word[50],meaning[200];

		switch (n)
		{
			case 1:	printf("\nEnter the word => ");
					scanf(" %s",word);
					for(i=0;i<=strlen(word);i++)
					{
				    	if(word[i]>=65 && word[i]<=90)
				    		word[i]=word[i]+32;
				   	}

					printf("\nEnter the meaning of %s => ",word);
					scanf(" ");
					gets(meaning);
					insert(word,meaning);

			break;
			case 2:	printf("\nEnter the word => ");
					scanf(" ");
					gets(word);
					for(i=0;i<=strlen(word);i++)
					{
				    	if(word[i]>=65&&word[i]<=90)
				    		word[i]=word[i]+32;
				   	}

					find(word);

			break;
			case 3:	printf("\nCurrently your Dictionary has %d words.\n",counter);

			break;
			case 4: printf("\nMade by HJ");
					printf("\n2019BCS0066\n\n");
					exit(0);

			break;
			default: printf("\nWrong Choice");
		}
	}

	return 0;
}



// Mark of authentication by Hrishabh Joshi
//      ╭━┳━╭━╭━╮╮
//      ┃┈┈┈┣▅╋▅┫┃
//      ┃┈┃┈╰━╰━━━━━━╮
//      ╰┳╯┈┈┈┈┈┈┈┈┈◢▉◣
//      ╲┃┈┈┈┈┈┈┈┈┈┈▉▉▉
//      ╲┃┈┈┈┈┈┈┈┈┈┈◥▉◤
//      ╲┃┈┈┈┈╭━┳━━━━╯
//      ╲┣━━━━━━┫
