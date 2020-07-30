#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct playerInfo
{
	int avg;
	char Name[20];
	char Role[20];
}playerInfo;

typedef struct playerProfile
{
	struct playerInfo  player;
	struct playerProfile *left,*right;
}playerProfile;

struct playerProfile *insert(struct playerProfile *P, struct playerInfo x);
void disp(struct playerProfile *P,int i);
struct playerInfo search(struct playerProfile *P, char name[]);
void preorder(struct playerProfile *P);
void inorder(struct playerProfile *P);
void postorder(struct playerProfile *P);
struct playerProfile* deleteNode(struct playerProfile* root, char name[]);
