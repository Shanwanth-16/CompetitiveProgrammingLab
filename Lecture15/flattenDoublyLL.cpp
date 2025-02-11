#include <iostream>
using namespace std;
struct node{
    int val;
    node* left=NULL;
    node* right=NULL;
    node* down =NULL;
};
node* input(int level)
{
    int a;
    node* start=NULL;
    node* downPointer;
    node* temp;
    while(true)
    {
        cout<<"Enter the val or -1 to terminate at level "<<level<<endl;
        cin>>a;
        if(a==-1)
        {
            break;
        }
        else
        {
            node* newNode=new node();
            newNode->val=a;
            if(start==NULL)
            {
                start=newNode;
            }
            else
            {
                temp->right=newNode;
                newNode->left=temp;
            }
            temp=newNode;
            cout<<"Enter 1 if there is down pointer else 0"<<endl;
            int c;
            cin>>c;
            if(c==1){
                downPointer=input(level+1);
                newNode->down=downPointer;
            } 
        }
    }
    return start;
}
node* recurse(node* start)
{
    if(start==NULL)
    {
        return NULL;
    }
    node* curr=start;
    while(curr->down==NULL)
    {
        curr=curr->right;
        if(curr==NULL)
        {
            break;
        }
    }
    if(curr!=NULL)
    {
        node* mid=recurse(curr->down);
        node* next=curr->right;
        curr->down=NULL;
        curr->right=mid;
        mid->left=curr;
        node* temp=mid;
        while(temp->right!=NULL)
        {
            temp=temp->right;
        }
        temp->right=next;
        if(next!=NULL)
        {
            next->left=temp;
        }
    }
    return start;
}
int main()
{
    node* start=NULL;
    start=input(1);
    node* temp1=start;
    while(temp1!=NULL)
    {
        cout<<temp1->val<<" ";
        temp1=temp1->right;
    }
    cout<<"before recurse"<<endl;

    node* newStart=recurse(start);
    node* temp=newStart;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->right;
    }
    
    return 0;
}