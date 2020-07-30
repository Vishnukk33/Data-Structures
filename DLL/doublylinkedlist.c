#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"dllinter.h"
#include"dllimpl.h"

void main()
{	int opt;
	perADT *l=malloc(sizeof(perADT));
	perADT *l1=malloc(sizeof(perADT));	
	perADT *l2=malloc(sizeof(perADT));	
	initialise(l);
	person x;
	long int arr[10];
	char a[20];
	int ct=0,n,i,flag;
	do	
	{	
		printf("\n\nMENU: \n 1.insert front \n 2.insert end \n 3.insert after a pin \n 4.list senior people \n 5.locate people based on a location \n 6.sort list \n 7.display \n 8.show ratio \n 9.Exit\n");
		scanf("%d",&opt);
		long int o;
		switch(opt)
		{	
			case 1:
					x = accept();
					insertFront(l,x);
					break;
			case 2:
					x = accept();
					insertEnd(l,x);
					break;
			case 3:
					x = accept();
					printf("Enter the pin after which we need to add");
					scanf("%li",&o);
					insertPIN(l,x,o);
					break;
			case 4: 
					l1 = senior(l);
					display(l1);
					break;
			case 5:	printf("Enter City name to be searched");
					scanf(" %[^\n]",a);
					
					l2 = locate(l,a);
					display(l2);
					break;
			case 6:	printf("Details\n");
					sort(l);
					display(l);
					break;
			case 7: display(l);
					break;
			case 8: ratio(l);
					break;
			case 9: exit(0);
					break;
			default:printf("Invalid input\n");
		}
	}while(opt!=9);
}
/*OUTPUT
vishnu@vishnu-G7-7588:~/Desktop$ gcc dll.c -o k
vishnu@vishnu-G7-7588:~/Desktop$ ./k


MENU: 
 1.insert front 
 2.insert end 
 3.insert after a pin 
 4.list senior people 
 5.locate people based on a location 
 6.sort list 
 7.display 
 8.show ratio 
 9.Exit
1
enter name:Vishnu
enter age:66
enter address:ffff
enter city:uu
enter sex:M
enter mobile:444


MENU: 
 1.insert front 
 2.insert end 
 3.insert after a pin 
 4.list senior people 
 5.locate people based on a location 
 6.sort list 
 7.display 
 8.show ratio 
 9.Exit
2
enter name:
KOK
enter age:56
enter address:popo
enter city:uu
enter sex:F
enter mobile:434


MENU: 
 1.insert front 
 2.insert end 
 3.insert after a pin 
 4.list senior people 
 5.locate people based on a location 
 6.sort list 
 7.display 
 8.show ratio 
 9.Exit
7


name:Vishnu 
pin:9651 
sex:M 
address:ffff 
city:uu 
age:66 
Mobile:444 


name:KOK 
pin:5146 
sex:F 
address:popo 
city:uu 
age:56 
Mobile:434 


name:KOK 
pin:5146 
sex:F 
address:popo 
city:uu 
age:56 
Mobile:434 


name:Vishnu 
pin:9651 
sex:M 
address:ffff 
city:uu 
age:66 
Mobile:444 


MENU: 
 1.insert front 
 2.insert end 
 3.insert after a pin 
 4.list senior people 
 5.locate people based on a location 
 6.sort list 
 7.display 
 8.show ratio 
 9.Exit
3
enter name:JJJ
enter age:33
enter address:fdf
enter city:ll
enter sex:M
enter mobile:344
Enter the pin after which we need to add9651


MENU: 
 1.insert front 
 2.insert end 
 3.insert after a pin 
 4.list senior people 
 5.locate people based on a location 
 6.sort list 
 7.display 
 8.show ratio 
 9.Exit
4


name:Vishnu 
pin:9651 
sex:M 
address:ffff 
city:uu 
age:66 
Mobile:444 


name:Vishnu 
pin:9651 
sex:M 
address:ffff 
city:uu 
age:66 
Mobile:444 


MENU: 
 1.insert front 
 2.insert end 
 3.insert after a pin 
 4.list senior people 
 5.locate people based on a location 
 6.sort list 
 7.display 
 8.show ratio 
 9.Exit
5
Enter City name to be searcheduu


name:Vishnu 
pin:9651 
sex:M 
address:ffff 
city:uu 
age:66 
Mobile:444 


name:KOK 
pin:5146 
sex:F 
address:popo 
city:uu 
age:56 
Mobile:434 


name:KOK 
pin:5146 
sex:F 
address:popo 
city:uu 
age:56 
Mobile:434 


name:Vishnu 
pin:9651 
sex:M 
address:ffff 
city:uu 
age:66 
Mobile:444 


MENU: 
 1.insert front 
 2.insert end 
 3.insert after a pin 
 4.list senior people 
 5.locate people based on a location 
 6.sort list 
 7.display 
 8.show ratio 
 9.Exit
6
Details


name:JJJ 
pin:4558 
sex:M 
address:fdf 
city:ll 
age:33 
Mobile:344 


name:KOK 
pin:5146 
sex:F 
address:popo 
city:uu 
age:56 
Mobile:434 


name:Vishnu 
pin:9651 
sex:M 
address:ffff 
city:uu 
age:66 
Mobile:444 


name:Vishnu 
pin:9651 
sex:M 
address:ffff 
city:uu 
age:66 
Mobile:444 


name:KOK 
pin:5146 
sex:F 
address:popo 
city:uu 
age:56 
Mobile:434 


name:JJJ 
pin:4558 
sex:M 
address:fdf 
city:ll 
age:33 
Mobile:344 


MENU: 
 1.insert front 
 2.insert end 
 3.insert after a pin 
 4.list senior people 
 5.locate people based on a location 
 6.sort list 
 7.display 
 8.show ratio 
 9.Exit
8
Ratio of men to women is:  2:1

MENU: 
 1.insert front 
 2.insert end 
 3.insert after a pin 
 4.list senior people 
 5.locate people based on a location 
 6.sort list 
 7.display 
 8.show ratio 
 9.Exit
9
*/
		
		
		
		
		
