#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void display();
void search();
struct node
{
int data;
struct node *link;
};
struct node *top;
void main ()
{
int ch,n;
clrscr();
printf(" **********STACK USING SINGLY LINKLIST********** ");
while(ch != 5)
{
printf("\n\nChose one from the below options...\n");
printf("\n1.Push\n2.Pop\n3.Display\n4.Search\n5.Exit");
printf("\n Enter your choice \n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
push();
break;
}
case 2:
{
pop();
break;
}
case 3:
{
display();
break;
}
case 4:
{
search();
break;
}
case 5:
{
exit(0);
}
default:
{
printf("Please Enter valid choice ");
}
};
}
}
void push ()
{
int ele;
struct node *newNode;
newNode = (struct node*)malloc(sizeof(struct node));
if(newNode == NULL)
{
printf("not able to push the element");
}
else
{
printf("\nEnter the element: ");
scanf("%d",&ele);
newNode -> data = ele;
if(top==NULL)
{
newNode -> link =NULL;
}
else
{
newNode -> link = top;
}
top = newNode;
printf("\nItem pushed");
}
}
void pop()
{
int item;
struct node *temp;
if (top == NULL)
{
printf("\nUnderflow");
}
else
{
item = top->data;
temp = top;
top = top -> link;
free(temp);
printf("\nItem popped -> %d",item);
}
}

void display()
{
int i;
struct node *ptr;
if(top == NULL)
{
printf("\nStack is empty\n");
}
else
{
ptr=top;
printf("\nPrinting Stack elements \n");
while(ptr!=NULL)
{
printf("\n%d\n",ptr->data);
ptr = ptr->link;
}
}
}
void search()
{
int i=1, flag=0, item;
if(top == NULL)
{
printf("\n List is empty");
return;
}
while(top != NULL)
{
if(top->data==item)
   {
      flag=1;
      break;
   }
else
{
   top=top->link;
   i++;
}
if(flag==1)
{
   printf("%d found", item);
}
else
{
printf("\n %d Element not found", item);
}
}
}
