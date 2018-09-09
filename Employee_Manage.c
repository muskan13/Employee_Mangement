#include<stdio.h>
#include<stdlib.h>
//Employee Management System using double linked list.
typedef struct node
{
	struct node *lt;
	int id;
	char name[30];
	char adrs[50];
	char city[20];
	char job[20];
	float salary;
	struct node *rt;
}node;
node *head=NULL;int pos=0;
node* get()
{
	node *ptr=(node*)malloc(sizeof(node));
	return ptr;
}
node* insert(node *ptr,int i)
{
	printf("Enter the employee data\n");
	printf("Enter the id:");
	scanf("%d",&ptr->id);
	fflush(stdin);
	printf("\nEnter the name:");
	gets(ptr->name);
	printf("\nEnter the address:");
	gets(ptr->adrs);
	printf("\nEnter the city:");
	gets(ptr->city);
	printf("\nEnter the job:");
	gets(ptr->job);
	printf("\nEnter the salary:");
	scanf("%f",&ptr->salary);
	fflush(stdin);
	printf("\n");
	if(i==0)
	    {
	        ptr->rt=NULL;
	        ptr->lt=NULL;
	    }
	return ptr;
}
void insert_beg()
{
	node *ptr=get();
	ptr=insert(ptr,0);
	if(head==NULL)
	   head=ptr;
	else
	{
	     ptr->rt=head;
	     head->lt=ptr;
	     head=ptr;
	}
	pos++;
}
void insert_end()
{
	node *ptr=get();
	ptr=insert(ptr,0);
	if(head==NULL)
	   head=ptr;
	else
	{
		node *temp=head;
		while(temp->rt!=NULL)
		    temp=temp->rt;
		temp->rt=ptr;
		ptr->lt=temp;
	}
	pos++;
}
void modify()
{
    int i;
    printf("Enter the id no. whose data you want to modify\n");
    scanf("%d",&i);
    int flag=0;
    node *ptr=head;
    while(ptr!=NULL)
    {
        if(ptr->id==i)
        {
            ptr=insert(ptr,1);
            flag=1;
            break;
        }
        ptr=ptr->rt;
    }
    if(flag==0)
    {
        printf("Employee details did not match\n");
    }
}
void insert_p()
{
	int p;
	node *ptr=get();
	node *temp=head,*r;
	printf("Enter the position to insert\n");
    scanf("%d",&p);
    int c=1;
    if(p>(pos+1) || p<1)
        printf("Not possible\n");
    else
    {
        while(c!=p)
	    {
		   temp=temp->rt;
           c++;
        }
	    if(p==1)
            insert_beg();
         else if(p==(pos+1))
            insert_end();
        else
        {
            ptr=insert(ptr,0);
		    r=temp->lt;
		    ptr->rt=temp;
		    ptr->lt=r;
		    temp->lt=ptr;
		    r->rt=ptr;
		    pos++;
        }
    }
}
void display()
{
    int i=1;
	node *ptr=head;
	if(head!=NULL)
    {
        printf("\tDisplay\n");
	while(ptr!=NULL)
	{
	    printf("\n\t%d.\n",i);
		printf("\tEmployee id:%d\n",ptr->id);
		printf("\tEmployee name:%s\n",ptr->name);
		printf("\tEmployee address:%s\n",ptr->adrs);
		printf("\tEmployee city:%s\n",ptr->city);
		printf("\tEmployee job:%s\n",ptr->job);
		printf("\tEmployee salary:%f\n",ptr->salary);
		ptr=ptr->rt;
		i++;
	}
	printf("\n");
    }
    else
        printf("No records\n");
}
void del_beg()
{
	if(head==NULL)
	    printf("UNDERFLOW of record\n");
	else if(head->rt==NULL)
	     {
	         printf("Data deleted with id no.:%d\n",head->id);
	         head=NULL;
	         pos--;
	     }
	else
	{
	    printf("Data deleted with id no.:%d\n",head->id);
	   pos--;
		node *temp=head;
		head=head->rt;
		free(temp);
		head->lt=NULL;
	}
}
void del_end()
{
	node *ptr;
	if(head==NULL)
	    printf("UNDERFLOW of records\n");
	else if(head->rt==NULL)
	    {
	        printf("Data deleted with id no.:%d\n",head->id);
	        pos--;
	        head=NULL;
	    }
	else
	{
		node *temp=head;
		while(temp->rt!=NULL)
		    {
		    	ptr=temp;
		    	temp=temp->rt;
			}
		ptr->rt=NULL;
		printf("Data deleted with id no.:%d\n",temp->id);
		pos--;
		free(temp);
	}
}
void del_p()
{
    node *ptr=head;
    node *temp1=ptr;
    node *temp2=ptr;
	int p;
	printf("Enter the position to delete\n");
    scanf("%d",&p);
    int c=1;
    if(p>pos || p<1)
         printf("Deletion is not possible\n");
    else
    {
     while(c!=p)
    {
        c++;
        temp1=ptr;
        ptr=ptr->rt;
        temp2=ptr->rt;
    }

    if(p==1)
        del_beg();
    else if(p==pos)
        del_end();
    else
    {
        temp1->rt=ptr->rt;
        temp2->lt=ptr->lt;
        printf("Data deleted with id no.:%d\n",ptr->id);
        free(ptr);
        pos--;
    }
    }
}
void del_id()
{
    int i,flag=0;
    printf("Enter the id no. whose details have to be deleted\n");
    scanf("%d",&i);
    node *ptr=head;
    node *temp1=head;
    node *temp2=head;
    if(pos==0)
        printf("Deletion is not possible\n");
    else if(head->id==i)
        {
            del_beg();
            flag=1;
        }
    else
    {
        while(ptr->rt!=NULL)
        {
            temp1=ptr;
            ptr=ptr->rt;
            temp2=ptr->rt;
            if(ptr->id==i)
            {
                if(temp2==NULL)
                    del_end();
                else
                {
                    temp1->rt=ptr->rt;
                   temp2->lt=ptr->lt;
                    printf("Data deleted with id no.:%d\n",ptr->id);
                    free(ptr);
                    pos--;
                }
                flag=1;
                 break;
            }
        }
    }
    if(flag==0)
        printf("Employee details not found\n");
}
int main()
{
	do
	{
	int ch;
	printf("Enter choice-\n1 to insert at beg,\n2. to insert at end,\n3. to insert at position,\n4. to modify details\n5. to display\n6. delete at beg\n7.delete at end\n8. delete at position\n9. to delete the details of particular employee\nAny other option to exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:insert_beg();break;
		case 2:insert_end();break;
		case 3:insert_p();break;
		case 4:modify();break;
	    case 5:display();break;
	    case 6:del_beg();break;
	    case 7:del_end();break;
	    case 8:del_p();break;
	    case 9:del_id();break;
	    default: printf("Wrong choice\n");exit(1);
	}
   }while(1);
}

