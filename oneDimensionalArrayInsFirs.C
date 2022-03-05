#include<stdio.h>
#include<conio.h>
void main()
{
int a[50], size, i, num;
clrscr();
printf("************** INSERTION AT FIRST IN 1D ARRAY *************");
printf("\n Enter the size of Array: ");
scanf("%d",&size);
if(size > 50)
{
   printf("\n Overflow");
}
else
{
printf("Enter the Elements: ");
for(i=0; i<size; i++)
{
   scanf("%d", &a[i]);
}
printf(" Enter the Element to insert at first: ");
scanf("%d", &num);

for (i=size-1; i>=0; i--)
{
   a[i+1]=a[i];
}
a[0] = num;
size++;
printf("Array Elements are: ");
for(i=0; i<size; i++)
{
printf("\t%d\t", a[i]);
}
}
getch();
}
