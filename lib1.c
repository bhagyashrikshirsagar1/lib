#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
//#include"lib1.h"
//#include"mainfile.h"
struct book
{
  int bookid;
  char bname[25] ;
  char author[25];
  int status;
}book;
struct membr
{
  int mis;
  char mname[25] ;
  char department[25];
  int availibcard;
  int phno,year;

}membr;
void screentitle();
void Addbook();
void Search();
void Displaybook();
void Displaymem();
void availablebook();
void Issue();
void Addmembr();
void Exit();
char data[500];
#define INBOOK 1 //it is flag for know book is present in library or not. 
#define OUTBOOK 0
FILE *libfile;
FILE *membrfile;
FILE *fp1;
FILE *fp2;
FILE *temp1;
FILE *temp2;
void screentitle() {
//display coep library title
	printf("\n                       :::::::::::::::::::::::::::::::::::::");
	printf("\n                       ::                                 ::");
	printf("\n                       ::     ~~~~~~~~~~~~~~~~~~~~~~~     ::");
	printf("\n                       ::     ~                     ~     ::");
	printf("\n                       ::     ~      WELCOME TO     ~     ::");
	printf("\n                       ::     ~                     ~     ::");
	printf("\n                       ::     ~     COEP  LIBRARY   ~     ::");
	printf("\n                       ::     ~                     ~     ::");
	printf("\n                       ::     ~~~~~~~~~~~~~~~~~~~~~~~     ::");
	printf("\n                       ::                                 ::");
	printf("\n                       :::::::::::::::::::::::::::::::::::::\n\n");
}
void Addbook() {
//enter the books from user
 int i;book.status=INBOOK;
        //opening the libfile file
	libfile = fopen("libfile.txt","a+");
	printf("Enter The unique id of The Book\n");
	scanf("%d",&book.bookid);
	printf("Enter The Name of The Book :\n");
        scanf("%s",book.bname);
	printf("Enter The Name of Author :\n");
        scanf("%s",book.author);
	fprintf(libfile,"\n%d\t%s\t%s\t%d\t",book.bookid,book.bname,book.author,book.status);    
	fclose(libfile);
	printf("A New Book has been Added Successfully...\n");
}

void Displaybook(){
//display the available books
	libfile = fopen("libfile.txt","a+");
	printf("==============================================================================");
	printf("\nBookid\tName\tAuthor\tStatus No.\n",data);
	printf("==============================================================================");
	do{
        	fgets(data,500,libfile);
       		printf("%s\n",data);
	}while(!feof(libfile));
	
	fclose(libfile);
  
}
void Displaymem(){
//display member record
membrfile = fopen("membrfile.txt","a+");
	printf("==============================================================================");
	printf("\nMid\tName\tDept\tPh.no\tAvailablecards\tyear\n",data);
	printf("==============================================================================");
    do
    {
        fgets(data,500,membrfile);
        printf("%s\n",data);
    }while(!feof(membrfile));
	
	fclose(membrfile);
  
}
void Author(){
//easy to search book by name
}
void availablebook(){
//how many books available
}
void Search(){
//search the books available in files
}
void Issue();
void Addmembr()
{
	membrfile = fopen("membrfile.txt","a+");
	printf("Enter The MIS of the Member:\n");
        scanf("%d",&membr.mis);
	printf("Enter The Name of the Member :\n");
        scanf("%s",membr.mname);
	printf("Enter The Department\n");
        scanf("%s",membr.department);
	printf("Enter The year of the Member:\n");
        scanf("%d",&membr.year);
	printf("Enter The phone number of the member:\n");
        scanf("%d",&membr.phno);
	membr.availibcard=5;
	fprintf(membrfile,"\n%d\t%s\t%s\t%d\t%d\t",membr.mis,membr.mname,membr.department,membr.phno,membr.availibcard,membr.year);
	fclose(membrfile);
	printf("\nAdded  A New member Successfully...\n");
}
void Exit()
{
  exit(0);
}
int main()
{       
	int choice=0,i;
	screentitle();
	do{
		printf("\n\t~~MENU~~\n [1] Add A New Book\n [2] Display Books Information\n [3] Display members Information\n [4] Search a book \n [5] Add A New Member\n [6] Exit the program\n\n\t Enter your choice <1-6>: ");
	scanf("%i",&choice);
	switch (choice)
	{   
        	case 1:Addbook();
			break;
        	case 2:Displaybook();
			break;
		case 3:Displaymem();
			break;
		case 4:Search();
                	break;
        	case 5:Addmembr();
                	break;
        	case 6:Exit();
                	break;
		default:
            		printf(" ! Invalid Input...\n");
	}
	}while(choice!=6);
	 return (0);
}


