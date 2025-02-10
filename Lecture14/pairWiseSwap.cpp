#include <iostream>
using namespace std;
struct node{
    int val;
    node* next;
};
int main()
{
    int size;
    cout<<"Enter the number of elements"<<endl;
    cin>>size;
    node* start;
    node* temp;
    for(int i=0;i<size;i++)
    {
        cout<<"Enter val";
        node* newNode = new node();
        cin>>newNode->val;
        if(i==0)
        {
            start=newNode;
            temp=newNode;
        }
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    node* curr=start;
    node* prev=NULL;
    node* adj=NULL;
    node* nextPair=NULL;
   while(curr!=NULL)
   {
        adj=curr->next;
        if(adj==NULL)
        {
            prev->next=adj;
            //55adj->next=NULL;
            break;
        }
        nextPair=adj->next;
        adj->next=curr;
        curr->next=NULL;
        if(prev==NULL)
        {
            start=adj;
        }
        else{
            prev->next=adj;
        }
        prev=curr;
        curr=nextPair;
   }
   node* temp1=start;
   while(temp1!=NULL){
        cout<<temp1->val<<" ";
        temp1=temp1->next;
   }
    return 0;
}