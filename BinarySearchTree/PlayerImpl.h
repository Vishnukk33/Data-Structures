struct playerInfo accept(struct playerInfo t)
{
	printf("\nEnter name of player: ");
	scanf(" %[^\n]",t.Name);
	printf("\nEnter average run rate: ");
	scanf("%d",&t.avg);
	printf("\nEnter batsman or bowler: ");
	scanf(" %[^\n]",t.Role);
	return t;
}



struct playerProfile *insert(struct playerProfile *P, struct playerInfo x) 
{
	if(P==NULL)
	{
		P = (struct playerProfile*)malloc(sizeof(struct playerProfile));
		P->player  = x;
		P->right = NULL;
		P->left = NULL;
	}
	if(strcmp(x.Name,P->player.Name)<0)
		P->left = insert(P->left,x);
	else if(strcmp(x.Name,P->player.Name)>0)
		P->right= insert(P->right,x);
	return P;
}

void inorder(struct playerProfile *P)
{

	if(P->left!=NULL)
		inorder(P->left);
	printf("\n%s\n\n",P->player.Name);
	if(P->right!=NULL)	
		inorder(P->right);
	
}

void preorder(struct playerProfile *P)
{
	printf("\n%s\n\n",P->player.Name);
	if(P->left!=NULL)
		inorder(P->left);
	if(P->right!=NULL)	
		inorder(P->right);
}

void postorder(struct playerProfile *P)
{

	if(P->left!=NULL)
		inorder(P->left);
	if(P->right!=NULL)	
		inorder(P->right);
	printf("\n%s\n\n",P->player.Name);

}


struct playerProfile *findmin(struct playerProfile *P)
{
	if(P==NULL)printf("Empty");
	
	while(P->left!=NULL)
		return findmin(P->left);
}

struct playerInfo search(struct playerProfile *P, char name[])
{
	if(P==NULL)
	{
		strcpy(P->player.Name,"NOTFOUND");
		return P->player;
	}
	if(strcmp(P->player.Name,name)==0)
		return P->player;
	if(strcmp(P->player.Name,name)>0)
		return search(P->left,name);
	if(strcmp(P->player.Name,name)<0)
		return search(P->right,name);
}


struct playerProfile* deleteNode(struct playerProfile* root, char name[]) 
{ 
    if (root == NULL) return root; 
  
    if (strcmp(root->player.Name,name)>0) 
        root->left = deleteNode(root->left,name); 
  
    else if(strcmp(root->player.Name,name)<0) 
        root->right = deleteNode(root->right, name); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct playerProfile *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct playerProfile *temp = root->left; 
            free(root); 
            return temp; 
        } 

        struct playerProfile* temp = findmin(root->right); 

        root->player = temp->player; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->player.Name); 
    } 
    return root; 
} 



void disp(struct playerProfile *P,int space)
{
	
	printf("\n");
	int i;
	for(i=0;i<space;i++)
		printf(" ");
	printf("%s",P->player.Name);
	if(P->left!=NULL)
		disp(P->left,space+10);	
	if(P->right!=NULL)
		disp(P->right,space+10);
	/*	int setline =5,i;
		if(P==NULL)
			return;
		space+=setline;
		disp(P->right,space);
		printf("\n");
		for(i=setline;i<space;i++)
			printf(" ");
		printf("%s\n",P->player.Name);
		disp(P->left,space);
	*/
}		
		
