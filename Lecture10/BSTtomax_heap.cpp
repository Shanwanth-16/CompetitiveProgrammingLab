#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

struct node
{
    int val;
    node* left;
    node* right;
    node* parent;
    node(int v)
    {
        val = v;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

node* insertBst(node* root, int num, node* parent = NULL)
{
    if (root == NULL)
    {
        return new node(num);
    }
    else if (num >= root->val)
    {
        root->right = insertBst(root->right, num, root);
    }
    else
    {
        root->left = insertBst(root->left, num, root);
    }
    return root;
}

void bstTraverse(node* root, vector<int>& ans)
{
    if (root == NULL)
    {
        return;
    }
    bstTraverse(root->left, ans);
    ans.push_back(root->val);
    bstTraverse(root->right, ans);
}

void postOrder(node* root, vector<int>& ans, int& index)
{
    if (root == NULL)
    {
        return;
    }
    
    postOrder(root->left, ans, index);
    postOrder(root->right, ans, index);
    root->val = ans[index++];
}

int main()
{
    int size;
    cin >> size;
    node* root = NULL;
    cout << "Enter the elements in the binary search tree:" << endl;
    int a;
    for (int i = 0; i < size; i++)
    {
        cin >> a;
        root = insertBst(root, a);
    }

    vector<int> ans;
    bstTraverse(root, ans);

    reverse(ans.begin(), ans.end());

    int index = 0;
    postOrder(root, ans, index);
    cout << "Tree values after converting to max-heap:" << endl;
    bstTraverse(root, ans); 
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
