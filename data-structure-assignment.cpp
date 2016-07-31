#include <stdio.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *next;
};
typedef struct node *nodeptr;

nodeptr getnode();
void freenode(nodeptr);
void insertatfirst(nodeptr *,int);
int deletefromfront(nodeptr *);
void displaylist(nodeptr);

int main()
{
	nodeptr p;
    p=NULL;
    insertatfirst(&p,4);
    insertatfirst(&p,5);  
    displaylist(p);
	printf("%d\n",deletefromfront(&p));
	printf("%d\n",deletefromfront(&p));
	printf("%d\n",deletefromfront(&p));	  
    displaylist(p); 
}

nodeptr getnode()
{
	return (nodeptr)malloc(sizeof(struct node));
}

void freenode(nodeptr p)
{
	free(p);
}

void insertatfirst(nodeptr*p,int x)
{
	nodeptr q;
	q=getnode();
	q->info=x;
	q->next=*p;
	*p=q;
}

void displaylist(nodeptr p)
{
	nodeptr ptr=p;
	while(ptr!=NULL)
	{
		printf("%d",ptr->info);
		ptr=ptr->next;
	}
	printf("\n");
}

int deletefromfront(nodeptr *p)
{    
	int x;
	if (*p==NULL)
	{
		printf("List underflow\n");
		exit(0);
	}else
	{
		nodeptr q;
	    q=*p;
	    *p=q->next;
	    x=q->info;
	    freenode(q);
		return x;    
	}	
}

