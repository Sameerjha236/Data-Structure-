#include <bits/stdc++.h>
using namespace std;
#define ll long long int

class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        data = 0;
        left = right = nullptr;
    }
    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

class Tree
{
    node *root;

public:
    Tree()
    {
        root = nullptr;
    }
    node *Root()
    {
        return root;
    }
    void *updateRoot(node *add)
    {
        root = add;
    }
    node *insertnode(node *, int);
    node *deletnode(node *, int);
    void preorder(node *);
    void inorder(node *);
    void postorder(node *);
    friend node *find_min(node *);
};

node *Tree::insertnode(node *root, int key)
{
    node *n = new node(key);
    if (root == nullptr)
    {
        root = n;
        return root;
    }
    else if (key >= root->data)
        root->right = insertnode(root->right, key);
    else
        root->left = insertnode(root->left, key);
    return root;
}

node *find_min(node *root)
{
    if (root->left == nullptr)
        return root;
    return find_min(root->left);
}

node *Tree::deletnode(node *root, int key)
{
    if (root == nullptr)
        return nullptr;
    else if (root->data > key)
        root->left = deletnode(root->left, key);
    else if (root->data < key)
        root->right = deletnode(root->right, key);
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr)
        {
            node *tem = root->right;
            delete root;
            root = tem;
        }
        else if (root->right == nullptr)
        {
            node *tem = root->left;
            delete root;
            root = tem;
        }
        else
        {
            node *temp = find_min(root->right);
            root->data = temp->data;
            root->right = deletnode(root->right, temp->data);
        }
    }
    return root;
}

void Tree::preorder(node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void Tree::inorder(node *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void Tree::postorder(node *root)
{
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    int a[7] = {6, 1, 2, 4, 223, 43, 0};
    Tree t1;
    for (auto i : a)
    {
        t1.updateRoot(t1.insertnode(t1.Root(), i));
    }
    cout << "Preorder \n";
    t1.preorder(t1.Root());
    cout << endl;
    cout << "Inorder \n";
    t1.inorder(t1.Root());
    cout << endl;
    cout << "Postorder \n";
    t1.postorder(t1.Root());
    cout << endl;
    t1.updateRoot(t1.deletnode(t1.Root(), 43));
    cout << "Preorder \n";
    t1.preorder(t1.Root());
    cout << endl;
    cout << "Inorder \n";
    t1.inorder(t1.Root());
    cout << endl;
    cout << "Postorder \n";
    t1.postorder(t1.Root());
    cout << endl;
    return 0;
}