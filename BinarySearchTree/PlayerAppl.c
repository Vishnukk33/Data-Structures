#include"PlayerIf.h"
#include"PlayerImpl.h"

void main()
{

	struct playerProfile *P;
	struct playerInfo t;
	char n[20],s[20];
	int p;
	do
	{
		printf("\n\n\tMENU\n1.ADD\n2.Search\n3.Delete\n4.Display(hierarchial)\n5.Inorder traversal\n6.Preorder Traversal\n7.Postorder Traversal\n8.Exit\nEnter your option: ");
		scanf("%d",&p);
		switch(p)
		{
			case 1:	P = insert(P,accept(t));
				break;
			case 2: printf("Enter name of the player to be searched: ");
				scanf(" %[^\n]",n);
				if(P!=NULL)
				{
					t = search(P,n);
					if(strcmp(t.Name,"NOTFOUND")!=0)
					{
						printf("Player found!\nName: %s\nAverage run rate: %d\nRole: %s",t.Name,t.avg,t.Role); 
					}
					else
						printf("Not found ");
				}
				else 	
					printf("Empty tree");
				break;
			case 3: printf("Enter name of player to be deleted: ");
				scanf(" %[^\n]",s);
				if(P!=NULL)
					P = deleteNode(P,s);
				else
					printf("Empty tree");
				break;
			case 4: disp(P,0);
				break;
			case 5: if(P==NULL)
					printf("Empty Tree");
				else
					inorder(P);
				break;
			case 6: if(P==NULL)
					printf("Empty Tree");
				else
					preorder(P);
				break;
			case 7: if(P==NULL)
					printf("Empty Tree");
				else
					postorder(P);
				break;
			case 8:	exit(0);
			default:printf("Invalid input\n");
		}
	}while(1);
}
/*OUTPUT:
cs1200@jtl-30:~/Desktop/C/player$ gcc PlayerAppl.c -o k
cs1200@jtl-30:~/Desktop/C/player$ ./k


	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 1   

Enter name of player: Vishnu

Enter average run rate: 12

Enter batsman or bowler: Bowler


	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 1

Enter name of player: Srinath

Enter average run rate: 34

Enter batsman or bowler: Batsman


	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 1

Enter name of player: Kola

Enter average run rate: 34

Enter batsman or bowler: Batsman


	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 1

Enter name of player: Poe

Enter average run rate: 45

Enter batsman or bowler: Batsman


	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 2
Enter name of the player to be searched: Poe
Player found!
Name: Poe
Average run rate: 45
Role: Batsman

	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 4

Vishnu
          Srinath
                    Kola
                              Poe

	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 5

Kola


Poe


Srinath


Vishnu



	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 6

Vishnu


Kola


Poe


Srinath



	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 7

Kola


Poe


Srinath


Vishnu



	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 1

Enter name of player: Zues

Enter average run rate: 356

Enter batsman or bowler: Batsman


	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 4

Vishnu
          Srinath
                    Kola
                              Poe
          Zues

	MENU
1.ADD
2.Search
3.Delete
4.Display(hierarchial)
5.Inorder traversal
6.Preorder Traversal
7.Postorder Traversal
8.Exit
Enter your option: 8
*/
