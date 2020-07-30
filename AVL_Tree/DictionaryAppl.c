#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DictionaryADTImpl.h"
#include "DictionaryADTIf.h"

void main()
{
	struct dictionaryADT *D = NULL;
	wordMeaning w;
	int op;

	again:
	printf("\nEnter your choice:\n1. Insert word\n2. Display Tree\n3. Search for the meaning of a word\n4. Exit\n>>");
	scanf("%d",&op);

	switch(op)
	{
		case 1: printf("\nEnter the word: ");
				scanf(" %s",&w.word);
				printf("Enter its meaning: ");
				scanf(" %[^\n]",&w.meaning);

				D = insert(D,w);
				break;

		case 2: if(D == NULL)
					printf("\nTree is empty!\n");
				else
					display(D,0);

				break;

		case 3: if(D == NULL)
					printf("\nTree is empty!\n");
				else
				{
					printf("\nEnter the word: ");
					scanf(" %s",&w.word);

					search(D,w.word);
				}

				break;

		case 4: exit(0);
	}

	goto again;
}

/*

OUTPUT:

vishnu@vishnu-G7-7588:~/Desktop$ ./k

Enter your choice:
1. Insert word
2. Display Tree
3. Search for the meaning of a word
4. Exit
>>1

Enter the word: Sad  
Enter its meaning: Feeling down 

Enter your choice:
1. Insert word
2. Display Tree
3. Search for the meaning of a word
4. Exit
>>1

Enter the word: Think
Enter its meaning: Using one's brain

Enter your choice:
1. Insert word
2. Display Tree
3. Search for the meaning of a word
4. Exit
>>1

Enter the word: Write
Enter its meaning: Using a device to mark something on a paper

Enter your choice:
1. Insert word
2. Display Tree
3. Search for the meaning of a word
4. Exit
>>2
----------------------------------
Word: Think
Meaning: Using one's brain
----------------------------------
LEFT: 
	----------------------------------
	Word: Sad
	Meaning: Feeling down
	----------------------------------
RIGHT: 
	----------------------------------
	Word: Write
	Meaning: Using a device to mark something on a paper
	----------------------------------

Enter your choice:
1. Insert word
2. Display Tree
3. Search for the meaning of a word
4. Exit
>>3

Enter the word: Sad

Meaning: Feeling down

Enter your choice:
1. Insert word
2. Display Tree
3. Search for the meaning of a word
4. Exit
>>4


*/
