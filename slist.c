#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node *head=NULL;
void add_begin();
void add_after();
void add_last();
int length();
void display();
void delete_first();
void delete_node();
void main()
{
   int choice;
   while(1)
   {
   printf("\n\n1.Add at begin\n2.Add at last\n3.Add at after\n4.Delete frst node\n5.Delete specified node\n6.Display elements\n7.length\n8.exit\n");
   printf("\nEnter your choice\n");
   scanf("%d",&choice);
   switch(choice)
   {
   case 1:
       add_begin();
       break;
   case 2:add_last();
       break;
    case 3:
        add_after();
        break;
    case 4:delete_first();
        break;
    case 5:
        delete_node();
        break;
    case 6:display();
        break;
    case 7:
        printf("The length of the list is %d\n",length());
        break;
    case 8:exit(0);
    default:
        printf("Invalid choice\n");

   }
   }
}
void add_begin()
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter element to insert\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
       head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    printf("element inserted successfully\n");
}
void add_last()
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter element to insert\n");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        struct node*p;
        p=head;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
}
int length()
{
    int count=0;
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    while(temp!=NULL)
    {
      count++;
      temp=temp->next;
    }
    return count;
}
void add_after()
{
    int len,loc,i=1;
    struct node*temp,*p;
    printf("Enter the location\n");
    scanf("%d",&loc);
    len=length();
    if(loc>len)
    {
        printf("Invalid location\nThere are only %d nodes in the list\n",len);
    }
    else
    {
        p=head;
        while(i<loc)
        {
          p=p->next;
          i++;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        printf("Enter element to insert\n");
        scanf("%d",&temp->data);
        temp->next=p->next;
        p->next=temp;
        printf("%d Inserted successfully\n",temp->data);
    }
}
void display()
{
    struct node*p=head;
    if(head==NULL)
    {
        printf("There are no elements in the list\n");
    }
    else
    {
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
    }
}
void delete_first()
{
    struct node*p=head;
    head=head->next;
    printf("Node deleted\n");
    free(p);
}
void delete_node()
{
    struct node*temp;
    int loc;
    printf("Enter location\n");
    scanf("%d",&loc);
    if(loc>length())
    {
     printf("NO such Location\n");
    }
    else if(loc==1)
    {
       temp=head;
       head=head->next;
    printf("Node deleted\n");
    free(temp);
    }
    else
    {
        struct node*p=head,*q;
        int i=1;
        while(i<loc-1);
        {
            p=p->next;
            i++;
        }
        q=p->next;
        p->next=q->next;
        q->next=NULL;
        free(q);
    }
}
