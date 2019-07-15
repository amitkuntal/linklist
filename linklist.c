#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct  node *temp = NULL;
struct  node *t = NULL;
int count=0;

void delete_from_begin();
void delete_from_end();

int main()
{
    int input,data;
    for(;;)
    {
        printf("\nPress 1 for inseting element at begining\n");
        printf("Press 2 for inseting element at end\n");
        printf("Press 3 for Traversing linklist\n");
        printf("Press 4 for delete an element from begining\n");
        printf("Press 5 for delete and element form end\n");
        scanf("%d",&input);
        switch(input)
        {
            case 1:
            printf("\nPlease enter the element for inserting it in begining:-");
            scanf("%d",&data);
            t=(struct node*)malloc(sizeof(struct node));
            count++;
            if(start==NULL)
            {
                start=t;
                start->data=data;
                start->next=NULL;
            }
            else
            {
                t->data=data;
                t->next=start;
                start=t;
            }
            break;
            case 2:
            printf("\nPlease enter the element for inserting it in end:-");
            scanf("%d",&data);
            t= (struct node*)malloc(sizeof(struct node));
            count++;
            if(start==NULL)
            {
                start=t;
                start->data=data;
                start->next=NULL;
            }
            else
            {
                temp=start;
                while(temp->next !=NULL)
                {
                    temp=temp->next;
                }
                temp->next=t;
                t->data=data;
                t->next=NULL;
            }
            break;
            case 3:
            printf("\nHere is the link list:-");
            if(start == NULL)
            {
                printf("\nLink list is empty\n");
            }
            else
            {
                temp= start;
                while(temp->next !=NULL)
                {
                    printf("%d -> ",temp->data);
                    temp=temp->next;
                }
                printf("%d",temp->data);
            }
            break;
            case 4:
            printf("\nDeleting element from begining ");
            if(start==NULL)
            {
                printf("\nList is empty   :(");
            }
            else
            {
                t=start;
                start=t->next;
                int n=t->data;
                free(t);
                printf("\n%d deleted from begining",n);
                count--;
            }
            
            break;
            case 5:
            printf("\nDeleting element form end");
            if(start == NULL)
            {
                printf("\nList is empty");

            }
            else if(start->next== NULL)
            {
                int n=start->data;
                free(start);
                start=NULL;
                printf("%d deleted",n);
            }
            else
            {
                temp=start;
                while (temp->next != NULL)
                {
                    t=temp;
                    temp=temp->next;
                }
                t->next=NULL;
                int n=temp->data;
                free(temp);
                temp=NULL;
                printf("%d deleted",n);
                
            }
            
            
            break;
            default:
            printf("\nYou enter a wrong choice :(");
            break;
        }
    }
    return 0;
}
