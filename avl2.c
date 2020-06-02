#include<stdlib.h>
#include<stdio.h>
 typedef struct node{
int data;
struct node*left,*right;

};
struct node*ll(struct node*);
struct node*rr(struct node*);
 struct node* create(struct node*temp,int i)
{
if(temp==NULL)
{
     struct node* newnode;
newnode=(struct node*)malloc(sizeof(struct node));
newnode->data=i;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}
else
{
    if((temp->data)>i)
    {

    temp->left=create(temp->left,i);
            if(bfactor(temp)==2)
						temp=ll(temp);


    }
    else{
    temp->right=create(temp->right,i);

}

}
return temp;
}
int height(struct node *temp,int i)
{ int j,k;
    if(temp==NULL)
        return 0;
    else
    { i++;
        j=height(temp->left,0);
        k=height(temp->right,0);
        if(j>k)
            return i+j;
        else
            return i+k;
    }}
    int main()
{ struct node *root=NULL;

int num[6]={1,2,3,4,5,6};
int n=0;
    while(n!=6)
    {
  int i=num[n];

    root=create(root,i);
    n++;

    }
    preorder(root);
    // constructing bst tree with 1 2 3 4 5 6
      printf(" height of tree is %d\n",height(root,-1));
}


int bfactor(struct node*temp)
{ printf("bfactor");
    int i=(hight(temp->left,0))-(hight(temp->right,0));
    printf("%d",i);
    return i;

}
struct node*ll(struct node* temp)
{ printf("lol");
   struct  node* curr;
    curr=temp->right;
    temp->right=curr->left;
    curr->left=temp;
    return curr;
}

struct node*rr(struct node* temp)
{
    struct node* curr;
    curr=temp->left;
    temp->left=curr->right;
    curr->right=temp;
    return curr;
}
int hight( struct node*temp,int i)
{  int j,k;
    if(temp==NULL)
        return 0;
    else
    { i++;
        j=hight(temp->left,0);
        k=hight(temp->right,0);
        if(j>k)
            return i+j;
        else
            return i+k;
    }}

void preorder(struct node *T)
{
	if(T!=NULL)
	{
		printf("%d",T->data);
		preorder(T->left);
		preorder(T->right);
	}
}