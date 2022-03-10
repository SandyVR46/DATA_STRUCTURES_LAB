#include<stdio.h>
#include<conio.h>
struct dnode
{
  struct dnode *left;
  int data;
  struct dnode *right;
};
typedef struct dnode dnode;
dnode *getnode();
void main()
{
    dnode *first,*temp,*current;
    int i,n,pos,item,ch;
    clrscr();
    first=NULL;
    printf("    **************DOUBLY LNKED LIST*************   ");
    printf("Enter the size of doubly linked list: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
	printf("Enter the data of node %d: ",i);
	scanf("%d",&item);
	temp=getnode();
	temp->data=item;
	temp->right=NULL;
	if(first==NULL)
	{
	    first=temp;
	    temp->left=NULL;
	}
	else
	{
	    current->right=temp;
	    temp->left=current;
	}
	current=temp;
    }
 do
 {
    printf("\n\n ********************************************** \n\n");
    printf("\n1.Insert at First ");
    printf("\n2.Insert at Last ");
    printf("\n3.Insert at Specific Position ");
    printf("\n4.Deletion at First ");
    printf("\n5.Deletion at Specific Position ");
    printf("\n6.Display ");
    printf("\n7.Exit ");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch)
    {
	case 1:
	    printf("Enter the element to be inserted: ");
	    scanf("%d",&item);
	    IDLF(&first,item);
	    break;
	case 2:
	    printf("Enter the element to be inserted: ");
	    scanf("%d",&item);
	    IDLL(&first,item);
	    break;
	case 3:
	    printf("Enter the element to be inserted: ");
	    scanf("%d",&item);
	    printf("Enter the position: ");
	    scanf("%d",&pos);
	    IDLA(&first,pos,item);
	    break;
	case 4:
	    DDLf(&first);
	    break;
	case 5:
	    printf("Enter the position of the node o be Deleted: ");
	    scanf("%d",&pos);
	    DDLA(&first,pos);
	    break;
	case 6:
	    display(first);
	    break;
	case 7:
	    exit(0);
	default:printf("invalid input");
    }
 }while(ch!=8);
 getch();
}
dnode*getnode()
{
    dnode*p;
    p=(dnode*)malloc(sizeof(dnode));
    return p;
}
freenode(dnode*p)
{
    free(p);
}

IDLF(dnode **first,int item)
{
    dnode*temp;
    temp=getnode();
    temp->data=item;
    temp->left=NULL;
    if(*first==NULL)
    temp->right=NULL;
    else
    {
	temp->right=*first;
	(*first)->left=temp;
    }
    *first=temp;
}
IDLL(dnode **first,int item)
{
    dnode *current,*temp;
    temp=getnode();
    temp->data=item;
    temp->right=NULL;
    if(*first==NULL)
    {
	temp->left=NULL;
	*first=temp;
    }
    else
    {
    current=*first;
    while(current->right!=NULL)
	current=current->right;
	temp->left=current;
	current->right=temp;
    }
}

IDLA(dnode **first,int pos,int item)
{
    dnode *temp,*current;
    int i;
    temp=getnode();
    temp->data=item;
    if(pos==1)
    {
	if(*first==NULL)
	    (*first)->left=temp;
	    temp->right=*first;
	    temp->left=NULL;
	    *first=temp;
    }
    else
    {
    i=2;
    current=*first;
    while((i<pos)&&(current->right!=NULL))
    {
	i++;
	current=current->right;
    }
    temp->left=current;
    temp->right=current->right;
    if(current->right!=NULL)
	temp->right->left=temp;
	current->right=temp;
    }
}

DDLf(dnode **first)
{
    dnode *current;
    int item;
    if(*first==NULL)
    {
	printf("list is empty");
    }
    else
    {
	current=(*first);
	(*first)=(*first)->right;
	if(*first!=NULL)
	    (*first)->left=NULL;
	    item=current->data;
	    freenode(current);
	    printf("\n is %d\n",item);
    }
}

DDLA(dnode **first,int pos)
{
    dnode *current,*prev;
    int i=1,item;
    if(*first==NULL)
    {
	printf("list is empty");
    }
    current=(*first);
    while(current!=NULL)
    {
	if(i==pos)
	{
	    item=current->data;
	    if(current->left==NULL)
	    {
		current->right->left=NULL;
		(*first)=current->right;
		freenode(current);
	    }
	    else if(current->right==NULL)
	    {
	    current->left->right=current->right;
	    freenode(current);
	    }
	else
	{
	    current->left->right=current->right;
	    current->right->left=current->left;
	    freenode(current);
	}
	printf("deleted item is %d",item);
	}
    i++;
    current=current->right;
 }
}
display(dnode *first)
{
    if(first==NULL)
    printf("\n list is empty");
    else
    {
	printf("the list is->");
	while(first!=NULL)
	{
	    printf("%d\t",first->data);
	    first=first->right;
	}
    }
}
