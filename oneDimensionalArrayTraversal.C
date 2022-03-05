#include<stdio.h>
#include<conio.h>
void main()
{
   int a[50], i, size;
   clrscr();
   printf("Enter the size of array: ");
   scanf("%d", &size);
   printf("Enter the Elements: ");
   for(i=0; i<size; i++)
   {
      scanf("%d", &a[i]);
   }
   printf("Elements Traversed are : ");
   for(i=0; i < size; i++)
   {
      printf("\t%d\t", a[i]);
   }
   getch();
}
