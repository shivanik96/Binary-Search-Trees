#include<iostream>

using namespace std;

struct node
{
    int value;
    node* left;
    node* right;
};

struct queue_node
{
    node* tree_node;
    queue_node* next;
};

class my_queue
{
    queue_node* head;
public:
    my_queue()
    {
        head=NULL;
    }
    queue_node* create_node(node* tn)
    {
        queue_node* qn = new queue_node();
        qn->tree_node=tn;
        qn->next=NULL;
        return qn;
    }
    void insert_into_queue(node* tn)
    {
        queue_node* qn = create_node(tn);
        queue_node* tmp=head;
        if (tmp==NULL)
        {
            head=qn;
            head->next=NULL;
            return;
        }
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
        }
        tmp->next=qn;
        qn->next=NULL;
    }
    queue_node* delete_from_queue()
    {
        queue_node* tmp=head;
        if (tmp==NULL)
        {
            cout<<"\nUnderflow!\n";
            return NULL;
        }
        head=head->next;
        return tmp;
    }
    bool is_vacant()
    {
        if (head==NULL)
            return true;
        return false;
    }
};

class BS_Tree
{
    node* root;
public:
    BS_Tree()
    {
        root=NULL;
    }
    node* create_node(int val)
    {
        node* new_node = new node();
        new_node->left=NULL;
        new_node->right=NULL;
        new_node->value=val;
        return new_node;
    }
    void insert_into_tree(node* new_node)
    {
        node* tmp=root;
        if (tmp==NULL)
        {
            root=new_node;
            root->left=NULL;
            root->right=NULL;
            return;
        }
        int val=new_node->value;
        node* prev=root;
        while(tmp!=NULL)
        {
            if (tmp==root)
                ;
            else
            {
                prev=tmp;
            }
            if (tmp->value>val)
            {
                tmp=tmp->left;
            }
            else
            {
                tmp=tmp->right;
            }
        }
        if (prev->value<val)
        {
            prev->right=new_node;
        }
        else
        {
            prev->left=new_node;
        }
        return;
    }
    void inorder(node* nd)
    {
        if (nd!=NULL)
        {
            inorder(nd->left);
            cout<<nd->value<<" ";
            inorder(nd->right);
        }
    }
    void preorder(node* nd)
    {
        if (nd!=NULL)
        {
            cout<<nd->value<<" ";
            preorder(nd->left);
            preorder(nd->right);
        }
    }
    void postorder(node* nd)
    {
        if (nd!=NULL)
        {
            postorder(nd->left);
            postorder(nd->right);
            cout<<nd->value<<" ";
        }
    }
    void levelorder()
    {
        node* tmp=root;
        int sum=0;
        if (tmp==NULL)
            return;
        my_queue q;
        queue_node* qn;
        q.insert_into_queue(tmp);
        while(!q.is_vacant());
        {
            qn=q.delete_from_queue();
            tmp=qn->tree_node;
            if (tmp->left!=NULL)
                q.insert_into_queue(tmp->left);
            if (tmp->right!=NULL)
                q.insert_into_queue(tmp->right);
            cout<<tmp->value<<" ";
        }
    }
    node* return_root()
    {
        return root;
    }
    int no_of_nodes(node* nd,int ctr) {
        if (nd != NULL) {
            ctr++;
            no_of_nodes(nd->left,ctr);
            no_of_nodes(nd->left,ctr);
        }
        return ctr;
    }
};
