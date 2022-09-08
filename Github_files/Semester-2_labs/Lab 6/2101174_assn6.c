#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int key;
    int HD;
    struct tree *left, *right;
};
int maximumhd = 0;
int counter = 0;

int searching(int in[], int instart, int inend, int key)
{
    int i;
    for (i = instart; i <= inend; i++)
    {
        if (in[i] == key)
        {
            return i;
        }
    }
}

int HD(struct tree *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int lHD = HD(root->left);
    int rHD = HD(root->right);

    if (lHD > rHD)
    {
        return lHD + 1;
    }
    else
    {
        return rHD + 1;
    }
}

void HD_diff(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }

    root->HD = HD(root->left) - HD(root->right);

    if (maximumhd < abs(root->HD))
    {
        maximumhd = abs(root->HD);
    }

    HD_diff(root->left);
    HD_diff(root->right);
}

struct tree *newnode(int key)
{

    struct tree *root = (struct tree *)malloc(sizeof(struct tree));
    root->key = key;
    root->left = NULL;
    root->right = NULL;
    return root;
}

struct tree *buildsecondarytreetree(int in[], int pre[], int instart, int inend)
{

    static int preindex = 0;
    if (instart > inend)
    {
        return 0;
    }
    struct tree *node = newnode(pre[preindex++]);

    if (instart == inend)
        return node;

    int inindex = searching(in, instart, inend, node->key);

    node->left = buildsecondarytreetree(in, pre, instart, inindex - 1);
    node->right = buildsecondarytreetree(in, pre, inindex + 1, inend);

    return node;
    
}

void Printpre(struct tree *root)
{

    if (root == NULL)
    {
        return;
    }

    printf("key = %d HDdiff = %d \n", root->key, root->HD);
    Printpre(root->left);
    Printpre(root->right);
}

void PrintIn(struct tree *root)
{
    if (root == NULL)
    {
        return;
    }

    PrintIn(root->left);
    printf("key = %d HDdiff = %d \n", root->key, root->HD);
    PrintIn(root->right);
}

void Printpost(struct tree *root)
{

    if (root == NULL)
    {
        return;
    }
    Printpost(root->left);
    Printpost(root->right);
    printf("key = %d HDdiff = %d \n", root->key, root->HD);
}

void Findkey(struct tree *root, int key, int *flag)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (root->key == key)
        {
            *flag = 1;
            return;
        }
    }
    Findkey(root->left, key, flag);
    Findkey(root->right, key, flag);
}

void insertNode(struct tree *root, int key1, int key2)
{
    if (root == NULL)
    {
        return;
    }

    if (root->key == key2 && root->left == NULL)
    {
        root->left = newnode(key1);
    }

    else if (root->key == key2 && root->right == NULL)
    {
        root->right = newnode(key1);
    }

    else if (root->key == key2)
    {
        if (root->HD > 0)
        {
            insertNode(root->right, key1, key2);
        }

        else
        {
            insertNode(root->left, key1, key2);
        }
    }
    else
    {
        insertNode(root->left, key1, key2);
        insertNode(root->right, key1, key2);
    }
}

void insertChild(struct tree *root, int key1, int key2)
{

    if (root == NULL)
    {
        return;
    }

    int Findkeykey1 = 0;
    int Findkeykey2 = 0;

    Findkey(root, key1, &Findkeykey1);
    Findkey(root, key2, &Findkeykey2);

    if (Findkeykey2 == 0)
    {
        printf("Not Found\n");
        return;
    }
    if (Findkeykey1 == 1)
    {
        printf("Already There!\n");
        return;
    }

    insertNode(root, key1, key2);
    HD_diff(root);
}

struct tree *lastsecondnode(struct tree *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if ((root->left != NULL && root->left->key == key) || (root->right != NULL && root->right->key == key))
    {
        return root;
    }

    else
    {
            struct tree *f = lastsecondnode(root->left, key);
            if (f)
                return f;

            return lastsecondnode(root->right, key);
    }
}

struct tree *leafnode(struct tree *root)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }
    else
    {
        struct tree *f = leafnode(root->left);
        if (f)
            return f;
        else
            return leafnode(root->right);
    }
}

void delete (struct tree *root, struct tree *mainroot, int key)
{
    if (root == NULL)
    {
        return;
    }

    if ((root)->key == key)
    {
        struct tree *first, *second, *third;
        first = root;
        second = leafnode(root);
        third = lastsecondnode(mainroot,second->key);
        first->key = second->key;
        if(third)
            if (third->left && third->left->key == second->key)
            {
                third->left = NULL;
            }
            else if(third->right)
            {
                third->right = NULL;
            }
    }
    
    delete (root->left, mainroot, key);
    delete (root->right, mainroot, key);
}

void deletenode(struct tree *root, int key)
{
    int Findkeykey = 0;
    Findkey(root, key, &Findkeykey);

    if (root == NULL)
    {
        return;
    }

    if (Findkeykey == 0)
    {
        printf("Not Found\n");
        return;
    }

    delete (root, root, key);
    HD_diff(root);
}

struct tree *buildsecondarytree(struct tree *root, int key1, int key2)
{

    static int i = 0;
    static struct tree *tree, *x, *temp;
    if (root == NULL)
    {
        return root;
    }

    int Findkeykey1 = 0;
    int Findkeykey2 = 0;

    Findkey(root, key1, &Findkeykey1);
    Findkey(root, key2, &Findkeykey2);

    if (Findkeykey1 == 1)
    {
        printf("Already There!\n");
        return 0;
    }

    if (Findkeykey2 == 0)
    {
        if (i == 0)
        {
            tree = newnode(key2);
            HD_diff(tree);
            i = i + 2;
            counter = counter + 2;
            temp = tree;
            x = tree;
            temp->left = newnode(key1);
            HD_diff(tree);
        }

        else if (i == 2)
        {
            temp = temp->left;
            temp->left = newnode(key1);
            HD_diff(tree);
            i++;
            counter++;
        }

        else if (i == 3)
        {
            temp->right = newnode(key1);
            HD_diff(tree);
            i++;
            counter++;
        }
        else if (i == 4)
        {
            temp = x;
            temp->right = newnode(key1);
            HD_diff(tree);
            i++;
            counter++;
        }
        else if (i == 5)
        {
            temp = temp->right;
            temp->left = newnode(key1);
            HD_diff(tree);
            i++;
            counter++;
        }

        else if (i == 6)
        {
            temp->right = newnode(key1);
            HD_diff(tree);
            i++;
            counter++;
        }
    }

    return tree;
}

void reinsert(struct tree *root, struct tree *mainroot, struct tree *tree, int key1, int key2)
{
    if (root == NULL)
    {
        return;
    }

    struct tree *temp, *second;
    if (abs(root->HD) == maximumhd)
    {

        temp = root;
        second = leafnode(root);

        if (counter == 7)
        {
            second->left = buildsecondarytree(mainroot, key1, key2);
        }
    }

    reinsert(root->left, mainroot, tree, key1, key2);
    reinsert(root->right, mainroot, tree, key1, key2);
}

int main()
{

    int length;
    printf("Enter total no of nodes\n");
    scanf("%d", &length);

    printf("Enter key of PrintIn\n");
    int in[length], pre[length];
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &in[i]);
    }
    printf("Enter key of Printpre\n");
    for (size_t i = 0; i < length; i++)
    {
        scanf("%d", &pre[i]);
    }

    struct tree *tree, *tree2;
    tree = buildsecondarytreetree(in, pre, 0, length - 1);
    HD_diff(tree);

    while (1)
    {
        int choice;
        printf("0 - Exit | 1 - Insertchild() | 2 - DeleteChild() | 3 - Re-InsertChild() | 4 - Print()\n");
        printf("Enter choice\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            int key1, key2;
            printf("Enter key1\n");
            scanf("%d", &key1);
            printf("Enter key2\n");
            scanf("%d", &key2);
            insertChild(tree, key1, key2);
            HD_diff(tree);
        }
        else if (choice == 2)
        {
            int key;
            printf("Enter key\n");
            scanf("%d", &key);
            deletenode(tree, key);
        }
        else if (choice == 3)
        {
            int key1, key2;
            printf("Enter key1\n");
            scanf("%d", &key1);
            printf("Enter key2\n");
            scanf("%d", &key2);
            tree2 = buildsecondarytree(tree, key1, key2);
            reinsert(tree, tree, tree2, key1, key2);
            HD_diff(tree);
        }
        else if (choice == 4)
        {
            printf("1 - Maintree() | 2 - Secondary-tree()\n");
            int choice1;
            printf("Enter Choice\n");
            scanf("%d", &choice1);
            if (choice1 == 1)
            {
                printf("1 - PrintIn | 2 - Printpre | 3 - Printpost\n");
                int choice2;
                printf("Enter Choice\n");
                scanf("%d", &choice2);

                if (choice2 == 1)
                {
                    printf("The PrintIn is : \n");
                    PrintIn(tree);
                    printf("\n");
                }
                else if (choice2 == 2)
                {
                    printf("The Printpre is : \n");
                    Printpre(tree);
                    printf("\n");
                }
                else if (choice2 == 3)
                {
                    printf("The Printpost is : \n");
                    Printpost(tree);
                    printf("\n");
                }
            }
            else if (choice1 == 2)
            {
                printf("1 - PrintIn | 2 - Printpre | 3 - Printpost\n");
                int choice3;
                printf("Enter Choice\n");
                scanf("%d", &choice3);
                if (choice3 == 1)
                {
                    printf("The PrintIn is : \n");
                    PrintIn(tree2);
                    printf("\n");
                }
                else if (choice3 == 2)
                {
                    printf("The Printpre is : \n");
                    Printpre(tree2);
                    printf("\n");
                }
                else if (choice3 == 3)
                {
                    printf("The Printpost is : \n");
                    Printpost(tree2);
                    printf("\n");
                }
            }
            else
            {
                printf("Invalid Choice\n");
            }
        }

        else if (choice == 0)
        {
            break;
        }
    }
    return 0;
}
