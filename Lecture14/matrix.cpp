#include <iostream>
using namespace std;
struct node{
    int val;
    node* next;
};
int main()
{
    node* start=NULL;
    vector<vector<int> > matrix(3,vector<int>(3));
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++)
        {
            cin>>matrix[i][j];
        }
    }
    node* temp;
    for(int i=0;i<matrix.size();i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<matrix[i].size();j++)
            {
                node* newNode=new node();
                newNode->val=matrix[i][j];
                if(start==NULL)
                {
                    start=newNode;
                    temp=newNode;
                }
                else{
                    temp->next=newNode;
                    temp=newNode;
                }
            }
        }
        else{
            for(int j=matrix[i].size()-1;j>=0;j--)
            {
                node* newNode=new node();
                newNode->val=matrix[i][j];
                if(start==NULL)
                {
                    start=newNode;
                    temp=newNode;
                }
                else{
                    temp->next=newNode;
                    temp=newNode;
                }
            }
        }
    }
    while(start!=NULL)
    {
        cout<<start->val<<" ";
        start=start->next;
    }
    return 0;
}