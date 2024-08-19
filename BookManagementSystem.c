#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BookManagemantSyestem{
	int bId,Price;
	char Name[20], Author[20],Category[20],Language[10],Publisher[10];
	float Rating;
}typedef Book;


void addBook(Book*,int);
void display(Book*,int);
void display1(Book*,int);
void search(Book*,int);
int searchById(Book*,int,int);
int searchByName(Book*,int,char*);
void searchByAName(Book*,int,char*);
void searchByCategory(Book*,int,char*);
void deleteBook(Book*,int,int);
Book* update(Book*,int);
Book* updateBook(Book*,int);
Book* updatePrice(Book*,int);
Book* updateRating(Book*,int);
void sort(Book*,int);
void sortByRating(Book*,int);
void sortByRatingDesc(Book*,int);
void sortByRatingAsec(Book*,int);
void sortByPrice(Book*,int);
void sortByPriceAsec(Book*,int );
void sortByPriceDesc(Book*,int);



void main(){
	int ch,cnt = 0,N = 10;
	Book* B = (Book*)malloc(sizeof(Book)*N);
	
	do{
		printf("\n1. Add Book \n2. Display Books\n3. Search Book\n4. Delete Book\n5. Update Book\n6. Sort\n0. To Exit\n");
		printf("\nEnter Your Choice:- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:{
				if(cnt != N)
				{
					addBook(B,cnt);
					cnt++;
				}
				else{
					printf("\nInsufficent Memory !!");
				}
				break;
			}
			
			case 2:{
				if(cnt == 0)
				{
					printf("\nData Not Present!!");
				}
				else{
					display(B,cnt);
				}
				
				
				break;
			}
			
			case 3:{
				if(cnt == 0)
				{
					printf("\nData Not Present!!");
				}
				else{
					search(B,cnt);
				}
				
				break;
			}
			case 4:{
				if(cnt == 0)
				{
					printf("\nData Not Present!!");
				}
				else{
				
					int id;
					printf("\nEnter Book ID : ");
					scanf("%d",&id);
					int res = searchById(B,cnt,id);
					
					if(res == -1)
					{
						printf("\nBook Not Found!!");
					}
					else{
						deleteBook(B,cnt,res);
						printf("\nBook Deleted Successfully.");
						cnt--;
					}
				}
				break;
			}
			
		case 5:{
			if(cnt == 0)
			{
				printf("\nData Not Present!!");
			}
			else
			{
				int id = -1;
				printf("\nEnter Book ID : ");
				scanf("%d",&id);
				int idx = searchById(B,cnt,id); 
				if(idx == -1)
				{
					printf("\nData Not Found!!");
				}
				else
				{
					B = update(B,idx);
					printf("\nData Updated Successfully!!");
				}
			}
			break;
		}
		case 6:{
			if(cnt == 0)
			{
				printf("\nData Not Present!!");
			}
			else
			{
				sort(B,cnt);
			}
			break;
		}
		}
	}while(ch != 0);
}

void addBook(Book* B,int cnt)
{
	Book bk;
	printf("\nEnter the Book Id: ");
	scanf("%d",&bk.bId);
	printf("\nEnter the Book Name: ");
	fflush(stdin);
	gets(bk.Name);
	printf("\nEnter the Author Name: ");
	fflush(stdin);
	gets(bk.Author);
	printf("\nEnter Price of Book: ");
	scanf("%d",&bk.Price);
	printf("\nEnter the Category: ");
	fflush(stdin);
	gets(bk.Category);
	printf("\nEnter the Language: ");
	fflush(stdin);
	gets(bk.Language);
	printf("\nEnter the Publishor Name: ");
	fflush(stdin);
	gets(bk.Publisher);
	printf("\nGive the Rating to the Book(1 to 5): ");
	scanf("%f",&bk.Rating);
	
	B[cnt] = bk;
}

void display(Book* B,int cnt)
{	
	printf("\n+----------+--------------+-------------+---------+--------------+---------------+----------------+------------+");
	printf("\n|  BookID  |     Name     |    Author   |  Price  |   Category   |    Language   |    Publisher   |   Rating   |");
	printf("\n+----------+--------------+-------------+---------+--------------+---------------+----------------+------------+");
		for(int i = 0;i<cnt;i++)
		{
			printf("\n|%6d    |%7s       |%7s       |%6d    |%8s     |%8s        |%7s        |%6.2f      |",B[i].bId,B[i].Name,B[i].Author,B[i].Price,B[i].Category,B[i].Language,B[i].Publisher,B[i].Rating);
		}
}

void display1(Book* B,int res)
{
	printf("\n+----------+--------------+-------------+---------+--------------+---------------+----------------+------------+");
	printf("\n|  BookID  |     Name     |    Author   |  Price  |   Category   |    Language   |    Publisher   |   Rating   |");
	printf("\n+----------+--------------+-------------+---------+--------------+---------------+----------------+------------+");	
	printf("\n|%6d    |%7s       |%7s       |%6d    |%8s     |%8s        |%7s        |%6.2f      |",B[res].bId,B[res].Name,B[res].Author,B[res].Price,B[res].Category,B[res].Language,B[res].Publisher,B[res].Rating);
}
void search(Book* B,int cnt)
{
	int choice,id;
	char name[20];
	do{
		printf("\n1. Search by Id\n2. Search By Name\n3. Search By Author\n4. Search By Category \n0. To exit\n");
		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:{
				printf("\nEnter the BookId: ");
				scanf("%d",&id);
				int res = searchById(B,cnt,id);
				if(res == -1)
				{
					printf("\nBook Not Found!!");
				}
				else
				{
					display1(B,res);
				}
				break;
			}
			
			case 2:{
				printf("\nEnter the Book Name : ");
				fflush(stdin);
				gets(name);
				int res = searchByName(B,cnt,name);
				if(res == -1)
				{
					printf("\nBook Not Found!!");
				}
				else
				{
					display1(B,res);
				}
				break;
			}
			case 3:{
				printf("\nEnter the Author Name : ");
				fflush(stdin);
				gets(name);
				searchByAName(B,cnt,name);
				break;
			}
			
			case 4:{
				printf("\nEnter the Category : ");
				fflush(stdin);
				gets(name);
				searchByCategory(B,cnt,name);
				break;
			}  
		}
	}while(choice != 0);
	
}
int searchById(Book* B,int cnt,int id)
{
	for(int i = 0;i<cnt;i++)
	{
		if(id == B[i].bId)
		{
			return i;
		}
	}
	return -1;
}

int searchByName(Book* B,int cnt,char* Name)
{
	for(int i = 0;i<cnt;i++)
	{
		if(strcasecmp(B[i].Name,Name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void searchByAName(Book* B,int cnt,char* name)
{
	int flag = 0,a = 0;
	for(int i = 0;i<cnt;i++)
	{
		if(strcasecmp(B[i].Author,name) == 0)
		{
			if(a == 0)
			{
				printf("\n+----------+--------------+-------------+---------+--------------+---------------+----------------+------------+");
				printf("\n|  BookID  |     Name     |    Author   |  Price  |   Category   |    Language   |    Publisher   |   Rating   |");
				printf("\n+----------+--------------+-------------+---------+--------------+---------------+----------------+------------+");	
				a++;				
			}
			printf("\n|%6d    |%7s       |%7s       |%6d    |%8s     |%8s        |%7s        |%6.2f      |",B[i].bId,B[i].Name,B[i].Author,B[i].Price,B[i].Category,B[i].Language,B[i].Publisher,B[i].Rating);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("\nBook Not Found!!");
	}
}

void searchByCategory(Book* B,int cnt,char* name)
{
	int flag = 0,a = 0;
	for(int i = 0;i<cnt;i++)
	{
		if(strcasecmp(B[i].Category,name) == 0)
		{
			if(a == 0)
			{
				printf("\n+----------+--------------+-------------+---------+--------------+---------------+----------------+------------+");
				printf("\n|  BookID  |     Name     |    Author   |  Price  |   Category   |    Language   |    Publisher   |   Rating   |");
				printf("\n+----------+--------------+-------------+---------+--------------+---------------+----------------+------------+");	
				a++;				
			}
			printf("\n|%6d    |%7s       |%7s       |%6d    |%8s     |%8s        |%7s        |%6.2f      |",B[i].bId,B[i].Name,B[i].Author,B[i].Price,B[i].Category,B[i].Language,B[i].Publisher,B[i].Rating);
			flag = 1;
		}
	}
	if(flag == 0)
	{
		printf("\nBook Not Found!!");
	}	
}

void deleteBook(Book* B,int cnt,int res)
{
	for(int i = res;i<cnt;i++)
	{
		B[i] = B[i+1];
		
	}
}

Book* update(Book* B,int idx)
{
	
	int ch;
		printf("\n1. Update Book\n2. Update Price\n3. Update Rating\n0. To Exit");
		printf("\nEnter Your Choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:{
				B = updateBook(B,idx);
				return B;
				break;
			}
			case 2:{
				B = updatePrice(B,idx);
				return B;
				break;
			}
			case 3:{
				B = updateRating(B,idx);
				return B;
				break;
			}
		}
}

Book* updateBook(Book* B,int idx)
{
	printf("\nEnter the Book Id: ");
	scanf("%d",&B[idx].bId);
	printf("\nEnter the Book Name: ");
	fflush(stdin);
	gets(B[idx].Name);
	printf("\nEnter the Author Name: ");
	fflush(stdin);
	gets(B[idx].Author);
	printf("\nEnter Price of Book: ");
	scanf("%d",&B[idx].Price);
	printf("\nEnter the Category: ");
	fflush(stdin);
	gets(B[idx].Category);
	printf("\nEnter the Language: ");
	fflush(stdin);
	gets(B[idx].Language);
	printf("\nEnter the Publishor Name: ");
	fflush(stdin);
	gets(B[idx].Publisher);
	printf("\nGive the Rating to the Book(1 to 5): ");
	scanf("%f",&B[idx].Rating);
	return B;
}

Book* updatePrice(Book* B,int idx)
{
	printf("\nEnter Price of Book: ");
	scanf("%d",&B[idx].Price);
	return B;	
}

Book* updateRating(Book* B,int idx)
{
	printf("\nGive the Rating to the Book(1 to 5): ");
	scanf("%f",&B[idx].Rating);
	return B;
}

void sort(Book* B,int cnt)
{
	int ch;
	printf("\n1. Sort By Price\n2. Sort By Rating");
	printf("\nEnter your Choice: ");
	scanf("%d",&ch);
	if(ch == 1)
	{
		sortByPrice(B,cnt);
	}
	if(ch == 2)
	{
		sortByRating(B,cnt);
	}
	
	
}

void sortByPrice(Book* B,int cnt)
{
	int ch;
	printf("\n1. Ascending\n2. Descending");
	printf("\nEnter your Choice: ");
	scanf("%d",&ch);
	
	if(ch == 1)
	{
		sortByPriceAsec(B,cnt);
	}
	if(ch == 2)
	{
		sortByPriceDesc(B,cnt);
	}
	else
	{
		printf("\nInvalid Found!!");
	}

}

void sortByPriceAsec(Book* B,int cnt)
{
	Book* bk;
	bk = B;
	for(int i=0;i<cnt;i++)
	{
		for(int j = i;j<cnt;j++)
		{
			if(bk[i].Price < bk[j].Price)
			{
				Book temp = bk[i];
				bk[i] = bk[j];
				bk[j] = temp;
			}
		}
	}
	display(bk,cnt);
}
void sortByPriceDesc(Book* B,int cnt)
{
	Book* bk = B;
	for(int i=0;i<cnt;i++)
	{
		for(int j = i;j<cnt;j++)
		{
			if(bk[i].Price > bk[j].Price)
			{
				Book temp = bk[i];
				bk[i] = bk[j];
				bk[j] = temp;
			}
		}
	}
	display(bk,cnt);
}
void sortByRating(Book* B,int cnt)
{
	int ch;
	printf("\n1. Ascending\n2. Descending");
	printf("\nEnter your Choice: ");
	scanf("%d",&ch);
	
	if(ch == 1)
	{
		sortByRatingAsec(B,cnt);
	}
	if(ch == 2)
	{
		sortByRatingDesc(B,cnt);
	}
	else
	{
		printf("\nInvalid Found!!");
	}
}

void sortByRatingAsec(Book* B,int cnt)
{
	Book* bk = B;
	for(int i=0;i<cnt;i++)
	{
		for(int j = i;j<cnt;j++)
		{
			if(bk[i].Rating < bk[j].Rating)
			{
				Book temp = bk[i];
				bk[i] = bk[j];
				bk[j] = temp;
			}
		}
	}
	display(bk,cnt);
}

void sortByRatingDesc(Book* B,int cnt)
{
	Book* bk = B;
	for(int i=0;i<cnt;i++)
	{
		for(int j = i;j<cnt;j++)
		{
			if(bk[i].Rating > bk[j].Rating)
			{
				Book temp = bk[i];
				bk[i] = bk[j];
				bk[j] = temp;
			}
		}
	}
	display(bk,cnt);
}