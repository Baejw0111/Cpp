#include "../Tree.h"

template <typename T>
tree::AVL<T>::AVL() : root(NULL) {}

template <typename T>
int tree::AVL<T>::MaxHeight(node_ptr nod)
{
    if (nod->left)
    {
        if (nod->right)
        {
            if (nod->left->height > nod->right->height)
            {
                return nod->left->height;
            }
            else
            {
                return nod->right->height;
            }
        }
        else
        {
            return nod->left->height;
        }
    }
    else
    {
        if (nod->right)
        {
            return nod->right->height;
        }
        else
        {
            return 0;
        }
    }
}

template <typename T>
typename tree::AVL<T>::node_ptr tree::AVL<T>::RightRotate(node_ptr nodeA)
{
    node_ptr nodeB = nodeA->left;
    node_ptr nodeBchild = nodeB->right;

    nodeB->right = nodeA;
    nodeA->left = nodeBchild;

    nodeA->height = 1 + MaxHeight(nodeA);
    nodeB->height = 1 + MaxHeight(nodeB);

    return nodeB;
}

template <typename T>
typename tree::AVL<T>::node_ptr tree::AVL<T>::LeftRotate(node_ptr nodeA)
{
    node_ptr nodeB = nodeA->right;
    node_ptr nodeBchild = nodeB->left;

    nodeB->left = nodeA;
    nodeA->right = nodeBchild;

    nodeA->height = 1 + MaxHeight(nodeA);
    nodeB->height = 1 + MaxHeight(nodeB);

    return nodeB;
}

template <typename T>
int tree::AVL<T>::GetBF(node_ptr nod)
{
    int hl, hr;
    if (nod->left == NULL)
    {
        hl = 0;
    }
    else
    {
        hl = nod->left->height;
    }

    if (nod->right == NULL)
    {
        hr = 0;
    }
    else
    {
        hr = nod->right->height;
    }

    int bf = hl - hr;

    return bf;
}

template <typename T>
typename tree::AVL<T>::node_ptr tree::AVL<T>::Rebalance(node_ptr nod)
{
    if (!nod)
    {
        return nod;
    }

    int bf = GetBF(nod);
    if (bf > 1)
    {
        if (nod->left->left)
        { // LL case
            return RightRotate(nod);
        }
        else
        { // LR case
            nod->left = LeftRotate(nod->left);
            return RightRotate(nod);
        }
    }
    else if (bf < -1)
    {
        if (nod->right->right)
        { // RR case
            return LeftRotate(nod);
        }
        else
        { // RL case
            nod->right = RightRotate(nod->right);
            return LeftRotate(nod);
        }
    }

    return nod;
}

template <typename T>
typename tree::AVL<T>::node_ptr tree::AVL<T>::Insert(node_ptr nod, T n)
{
    if (nod == NULL)
    {
        node_ptr tmp = new node;
        tmp->data = n;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->height = 1;

        return tmp;
    }

    if (n < nod->data)
    {
        nod->left = Insert(nod->left, n);
    }
    else
    {
        nod->right = Insert(nod->right, n);
    }

    nod->height = 1 + MaxHeight(nod);
    nod = Rebalance(nod);
    nod->height = 1 + MaxHeight(nod);

    return nod;
}

template <typename T>
void tree::AVL<T>::PreOrder(node_ptr nod)
{
    lst::Stack<node_ptr> stack;

    stack.Push(nod);

    while (1)
    {
        if (stack.isEmpty())
        {
            break;
        }

        nod = stack.Pop();

        std::cout << nod->data << " ";

        if (nod->right)
        {
            stack.Push(nod->right);
        }
        if (nod->left)
        {
            stack.Push(nod->left);
        }
    }
    std::cout << std::endl;
}

template <typename T>
void tree::AVL<T>::InOrder(node_ptr nod)
{
    lst::Stack<node_ptr> stack;

    while (1)
    {
        while (nod)
        {
            stack.Push(nod);
            nod = nod->left;
        }

        if (stack.isEmpty())
        {
            break;
        }

        nod = stack.Pop();

        std::cout << nod->data << " ";
        nod = nod->right;
    }
    std::cout << std::endl;
}

template <typename T>
void tree::AVL<T>::PostOrder(node_ptr nod)
{
    lst::Stack<node_ptr> stack;

    while (1)
    {
        while (nod)
        {
            stack.Push(nod);
            stack.Push(nod);
            nod = nod->left;
        }

        if (stack.isEmpty())
        {
            break;
        }

        nod = stack.Pop();

        if (nod == stack.Top())
        {
            nod = nod->right;
        }
        else
        {
            std::cout << nod->data << " ";
            nod = NULL;
        }
    }
    std::cout << std::endl;
}

template <typename T>
void tree::AVL<T>::LevelOrder(node_ptr nod)
{
    lst::Queue<node_ptr> queue;

    queue.Enqueue(nod);

    while (1)
    {
        if (queue.isEmpty())
        {
            break;
        }

        nod = queue.Dequeue();

        std::cout << nod->data << " ";

        if (nod->left)
        {
            queue.Enqueue(nod->left);
        }
        if (nod->right)
        {
            queue.Enqueue(nod->right);
        }
    }
    std::cout << std::endl;
}

template <typename T>
void tree::AVL<T>::Search(node_ptr nod, T n)
{
    lst::Queue<char> answer;

    answer.Enqueue('H');

    while (1)
    {
        if (nod->data > n)
        {
            answer.Enqueue('L');
            nod = nod->left;
        }
        else if (nod->data < n)
        {
            answer.Enqueue('R');
            nod = nod->right;
        }
        else
        {
            break;
        }

        if (!nod)
        {
            std::cout << -1 << std::endl;
            return;
        }
    }

    while (!answer.isEmpty())
    {
        std::cout << answer.Dequeue();
    }
    std::cout << std::endl;
}

template <typename T>
typename tree::AVL<T>::node_ptr tree::AVL<T>::ReturnMax(node_ptr nod)
{
    while (nod->right)
    {
        nod = nod->right;
    }

    return nod;
}

template <typename T>
typename tree::AVL<T>::node_ptr tree::AVL<T>::ReturnMin(node_ptr nod)
{
    while (nod->left)
    {
        nod = nod->left;
    }

    return nod;
}

template <typename T>
typename tree::AVL<T>::node_ptr tree::AVL<T>::Delete(node_ptr nod, T n)
{
    node_ptr tmp;

    if (!nod)
    {
        return nod;
    }
    else if (nod->data > n)
    {
        nod->left = Delete(nod->left, n);
    }
    else if (nod->data < n)
    {
        nod->right = Delete(nod->right, n);
    }
    else
    {
        if (nod->left && nod->right)
        { // if node have 2 child
            tmp = ReturnMin(nod->right);
            nod->data = tmp->data;
            nod->right = Delete(nod->right, tmp->data);
        }
        else
        { // if node have 1 or no child
            tmp = nod;
            if (nod->left)
            {
                nod = nod->left;
            }
            else
            {
                nod = nod->right;
            }
            delete tmp;
        }
    }

    if (nod)
    {
        nod->height = 1 + MaxHeight(nod);
    }
    nod = Rebalance(nod);
    if (nod)
    {
        nod->height = 1 + MaxHeight(nod);
    }

    return nod;
}

template <typename T>
void tree::AVL<T>::FreeNode(node_ptr nod)
{
    if (nod != NULL)
    {
        FreeNode(nod->left);
        FreeNode(nod->right);
        delete nod;
    }
}

template <typename T>
tree::AVL<T>::~AVL()
{
    FreeNode(root);
}