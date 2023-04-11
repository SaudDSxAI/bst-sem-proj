#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
Node *create_node(Node *root, int data)
{
    root = new Node;
    root->data = data;
    root->left = root->right = NULL;

    return root;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
        return create_node(root, data);

    else if (root->data >= data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

void traver(Node *root)
{
    if (root == NULL)
        return;
    traver(root->left);
    cout << root->data << endl;
    traver(root->right);
}

void traver2(Node *root)
{

    if (root == NULL)
        return;

    cout << root->data << endl;
    traver2(root->left);
    traver2(root->right);
}

void traver3(Node *root)
{
    if (root == NULL)
        return;

    traver3(root->left);
    traver3(root->right);
    cout << root->data << endl;
}

Node *find_min(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;
}

Node *delete_element(Node *root, int data)
{
    if (root->data > data)
        root->left = delete_element(root->left, data);
    else if (root->data < data)
        root->right = delete_element(root->right, data);
    else if (root->data == data)
    {
        if (root->left == NULL && root->right == NULL)
        {
            Node *temp = new Node;
            temp = root;
            root = NULL;
            delete temp;
        }

        else if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        else if (root->left != NULL && root->right != NULL)
        {
            Node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = delete_element(root->right, root->data);
        }
    }

    return root;
}
int main()
{
    Node *root = NULL;
    int data;
    
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter data ";
        cin >> data;
        root = insert(root, data);
    }

    traver(root);
    cout << "Enter which Node " << endl
         << endl;
    cin >> data;
    root = delete_element(root, data);
    traver(root);

    return 0;
}
