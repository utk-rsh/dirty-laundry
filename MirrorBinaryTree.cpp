//mirroring a binary tree

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct node
{
    string data;
    node* right;
    node* left;
};

void print(node* a)
{
    cout << a->data << "  ";
    if (a->left != NULL)
        print(a->left);
    if (a->right != NULL)
        print(a->right);
    return;
}

node* mirror_node(node* a)
{
  //  cout << "mirror node called for " << endl;
    cout << a->data << endl;
    node* b = new node;
    b->data = a->data;
    if (a->right != NULL)
        b->left = a->right;
    if (a->left != NULL)
        b->right = a->left;
    return b;
}

node* mirror_rec(node* a)
{
    node *b = mirror_node(a);
    bool d = b->left == NULL;
    bool e = b->right == NULL;
    if (d == 0)
    {b->left = mirror_rec(b->left);}
    if (e == 0)
    {b->right = mirror_rec(b->right);}
    return b;
}

int main()
{
    node *a = new node;
    node *b = new node;
    node *b1 = new node;
    node *b2 = new node;
    node *c = new node;
    node *d = new node;
    node *e = new node;
    node *e1 = new node;
    node *f = new node;
    node *g = new node;
    a->data = "a";
    b->data = "b";
    b1->data = "b1";
    b2->data = "b2";
    c->data = "c";
    d->data = "d";
    e->data = "e";
    e1->data = "e1";
    f->data = "f";
    g->data = "g";
    a->left = b;
    a->right = c;
    b->right = b1;
    b->left = b2;
    c->right = d;
    d->left = e;
    d->right = f;
    e->left = e1;
    e->right = g;
    print(a);
    cout << endl;
    node* flipped = mirror_rec(a);
    print(flipped);
    return 0;
}
