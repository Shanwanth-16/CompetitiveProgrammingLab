#include <iostream>
using namespace std;
struct node{
    int val;
    node* next;
};
node* create()
{
    int n=0;
    node* start=NULL;
    node* temp;
    while(true)
    {
        cout<<"Enter the val or -1 to terminate"<<endl;
        cin>>n;
        if(n==-1)
        {
            break;
        }
        else
        {
            node* newNode=new node();
            newNode->val=n;
            if(start==NULL)
            {
                start=newNode;
            }
            else
            {
                temp->next=newNode;
            }
            temp=newNode;
        }
    }
    return start;
}
int main()
{
    node* start=create();
    node* temp=start;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    return 0;
}