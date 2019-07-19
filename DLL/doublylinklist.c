#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *start = NULL;
struct node *temp= NULL;
struct node *t=NULL;
void insert_at_beginning(int x);
void insert_at_end(int x);
void traverse();
void delete_from_beginning();
void delete_from_end();
int main()
{
    int num,choice=0;
    while(choice >=0 && choice <5)
    {
    printf("\n========================Please Enter Your choice==================");
    printf("\nPress 1 For Inserting element at begining");
    printf("\nPress 2 For Inserting element at end");
    printf("\nPress 3 For Traversing Link List");
    printf("\nPress 4 for Deleting element from starting");
    printf("\nPress 5 for Deleting element from end");
    printf("\n Your Choice Please -->");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("\n Please enter the number :-");
        scanf("%d",&num);
        insert_at_beginning(num);
        break;
    case 2:
        printf("\n Please enter the number :-");
        scanf("%d",&num);
        insert_at_end(num);
        break;
    case 3:
        traverse();
        break;
    case 4:
        delete_from_beginning();
        break;
    case 5:
        delete_from_end();
        break;
    
    default:
        printf("You Entered a wrong choice .... %c",2);
        break;
    }
    }
    return 0;
}
void insert_at_beginning(int x)
{
    t=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
        t->data=x;
        t->next=NULL;
        t->prev=NULL;
        start=t;
    }
    else
    {
        t->data=x;
        t->prev=NULL;
        t->next=start;
        start->prev=t;
        start=t;
    }
    
}
void insert_at_end(int x)
{
    t=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
        t->data=x;
        t->next=NULL;
        t->prev=NULL;
        start=t;
    }
    else
    {
        t=start;
        temp= (struct node *)malloc(sizeof(struct node));
        
        while(t != NULL)
        {
          printf("%d ->",t->data);
          temp=t;
          t=t->next;
          
        }
        t= (struct node *)malloc(sizeof(struct node));
         t->data=x;
         t->next=NULL;
         t->prev=temp;
         temp->next=t;

    }
    
}
void traverse()
{
    if(start==NULL)
    {
        printf("\n Linklist is empty:::  %c",2);
    }
    else{
        t=start;
        while(t!=NULL)
        {
            printf("%d ->",t->data);
            t=t->next;
        }
    }
}
void delete_from_beginning()
{
    int temp1=0;
    if(start==NULL)
    {
        printf("\n List is empty");
    }
    else if(start->next ==NULL)
    {
        temp1=start->data;
        free(start);
        start=NULL;
        printf("\n %d deleted from linklist  and list is now empty",temp1);

    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp=start->next;
        temp1=start->data;
        start=NULL;
        start=temp;
        start->prev=NULL; 
        printf("\n %d  deleted from linklist\n",temp1);
        traverse();
    }
    
}
void delete_from_end()
{

    int temp1=0;
    if(start==NULL)
    {
        printf("\n List is empty");
    }
    else if(start->next ==NULL)
    {
        temp1=start->data;
        free(start);
        start=NULL;
        printf("\n %d deleted from linklist  and list is now empty",temp1);

    }
    else
    {
        temp=(struct node *)malloc(sizeof(struct node));
        temp=start;
        while(temp !=NULL)
        {
            t=temp;
            temp=temp->next;
        }
        temp=t;
        t=temp->prev;
        t->next=NULL;
        temp1=temp->data;
        free(temp);
        temp=NULL;
        printf("\n %d  deleted from linklist\n",temp1);
        traverse();
    }
}
