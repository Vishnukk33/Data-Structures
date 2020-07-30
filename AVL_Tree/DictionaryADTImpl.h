typedef struct
{
	char word[30];
	char meaning[150];
} wordMeaning;

struct dictionaryADT
{
	wordMeaning w;
	struct dictionaryADT *left;
	struct dictionaryADT *right;
	int height;
};

int heightOfNode(struct dictionaryADT *D)
{
	if(D == NULL)
		return(-1);
	else
		return(D->height);
}

void updateHeight(struct dictionaryADT *D)
{
	int hL = heightOfNode(D->left), hR = heightOfNode(D->right);
	D->height = (hL > hR ? hL : hR) + 1;
}

struct dictionaryADT* singleRotateLeft(struct dictionaryADT *D)
{
	struct dictionaryADT *d;

	// Left subtree is set to d
	d = D->left;

	// Left subtree is changed to left subtree's right subtree
	D->left = d->right;

	// Left subtree's right subtree is set to current node
	d->right = D;

	// Heights are updated
	updateHeight(D);
	updateHeight(d);
}

struct dictionaryADT* singleRotateRight(struct dictionaryADT *D)
{
	struct dictionaryADT *d;

	// Right subtree is set to d
	d = D->right;

	// Right subtree is changed to right subtree's left subtree
	D->right = d->left;

	// Right subtree's left subtree is set to current node
	d->left = D;

	// Heights are updated
	updateHeight(D);
	updateHeight(d);
}

struct dictionaryADT* doubleRotateLeft(struct dictionaryADT *D)
{
	// Single rotation between left subtree and its right subtree
	D->left = singleRotateRight(D->left);

	// Single rotation between current node and its (new) left subtree
	return singleRotateLeft(D);
}

struct dictionaryADT* doubleRotateRight(struct dictionaryADT *D)
{
	// Single rotation between right subtree and its left subtree
	D->right = singleRotateRight(D->right);

	// Single rotation between current node and its (new) right subtree
	return singleRotateRight(D);
}

struct dictionaryADT* insert(struct dictionaryADT *D, wordMeaning w)
{
	if(D == NULL)
	{
		D = (struct dictionaryADT *)malloc(sizeof(struct dictionaryADT));
		D->w = w;
		D->height = 0;
		D->left = D->right = NULL;
	}

	else if(strcmp(D->w.word,w.word) > 0)
	{
		D->left = insert(D->left,w);
		int hDiff = heightOfNode(D->left) - heightOfNode(D->right);

		if(hDiff == 2 || hDiff == -2)
		{
			if(strcmp((D->left)->w.word,w.word) > 0)
				D = singleRotateLeft(D);

			else
				D = doubleRotateLeft(D);
		} 
	}

	else if(strcmp(D->w.word,w.word) < 0)
	{
		D->right = insert(D->right,w);
		int hDiff = heightOfNode(D->left) - heightOfNode(D->right);

		if(hDiff == 2 || hDiff == -2)
		{
			if(strcmp((D->right)->w.word,w.word) < 0)
				D = singleRotateRight(D);

			else
				D = doubleRotateRight(D);
		}
	}
	updateHeight(D);
	return(D);
}

void display(struct dictionaryADT *D,int n)
{
	int i;
	
	for(i=0;i<n;i++,printf("\t"));
	printf("----------------------------------\n");

	for(i=0;i<n;i++,printf("\t"));
	printf("Word: %s\n",D->w.word);

	for(i=0;i<n;i++,printf("\t"));
	printf("Meaning: %s\n",D->w.meaning);

	for(i=0;i<n;i++,printf("\t"));
	printf("----------------------------------\n");

	if(D->left != NULL)
	{
		for(i=0;i<n;i++,printf("\t"));
		printf("LEFT: \n");
		display(D->left,n+1);
	}

	if(D->right != NULL)
	{
		for(i=0;i<n;i++,printf("\t"));
		printf("RIGHT: \n");
		display(D->right,n+1);
	}
}

void search(struct dictionaryADT *D, char word[])
{
	if(D == NULL)
		printf("\nWord doesn't exist in the tree!\n");

	else if(strcmp(D->w.word,word) == 0)
		printf("\nMeaning: %s\n",D->w.meaning);

	else if(strcmp(D->w.word,word) > 0)
		search(D->left,word);

	else
		search(D->right,word);
}