// Construct an expression tree from the given prefix expression eg. +--a*bc/def and
// traverse it using postordertraversal(non recursive) and then delete the entire tree. 

#include<bits/stdc++.h>

using namespace std;

typedef struct node
{
    char data;
    struct node *left, *right;
} node;



char* add(node** p, char* a)
{
    if (*a == '\0')
        return 0;

    while (1)
    {
        char* q = NULL;
        if (*p == NULL)
        {

            node* nn = new node;
            nn->data = *a;
            nn->left = NULL;
            nn->right = NULL;
            *p = nn;
        }
        else
        {

            if (*a >= 'a' && *a <= 'z')
            {
                return a;
            }
            q = add(&(*p)->left, a + 1);
            q = add(&(*p)->right, q + 1);
            return q;
        }
    }
}


vector<char> postOrderIterative(node* root)
{
    vector<char> postOrderList;
    if (root == NULL)
        return postOrderList;
    stack<node*> S;
    S.push(root);
    node* prev = NULL;
    while (!S.empty())
    {
        auto current = S.top();

        if (prev == NULL || prev->left == current
                || prev->right == current)
        {
            if (current->left)
                S.push(current->left);
            else if (current->right)
                S.push(current->right);
            else
            {
                S.pop();
                postOrderList.push_back(current->data);
            }
        }

        else if (current->left == prev)
        {
            if (current->right)
                S.push(current->right);
            else
            {
                S.pop();
                postOrderList.push_back(current->data);
            }
        }
        else if (current->right == prev)
        {
            S.pop();
            postOrderList.push_back(current->data);
        }
        prev = current;
    }
    return postOrderList;
}


// Driver code
int main()
{
    node* s = NULL;
    char a[] = "+ab";
    add(&s, a);
    printf("Post order traversal of binary tree is :\n");
    vector<char> postOrderList = postOrderIterative(s);
    for (auto it : postOrderList)
        cout << it << " ";
    return 0;
}
