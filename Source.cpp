#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<int> sumOfAllBranches;

struct Node
{
    int i;
    Node* pLeft;
    Node* pRight;

    Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};

void InsertToTree(Node*& pRoot, Node* pNew)
{
    if (!pRoot)
    {
        pRoot = pNew;
        return;
    }

    if (pNew->i <= pRoot->i)
        InsertToTree(pRoot->pLeft, pNew);
    else
        InsertToTree(pRoot->pRight, pNew);
}

void printAndAddBranchSumArray(int branch[], int len)
{
    int i;
    int sum = 0;
    for (i = 0; i < len; i++)
    {
        cout << branch[i] << " ";
        sum = sum + branch[i];
    }

    sumOfAllBranches.push_back(sum);
    cout << endl;
}
void PrintTree(Node* pRoot, int Level)
{
    if (!pRoot)
        return;

    PrintTree(pRoot->pRight, Level + 1);

    for (int i = 0; i < Level; i++)
        cout << "  ";
    cout << pRoot->i << endl;

    PrintTree(pRoot->pLeft, Level + 1);
}

void Insert(Node*& pRoot, Node* pNewNode)
{
    if (!pRoot)
        pRoot = pNewNode;
    else
    {
        if (pNewNode->i < pRoot->i)
            Insert(pRoot->pLeft, pNewNode);
        else
            Insert(pRoot->pRight, pNewNode);
    }
}

void printPathsRecur(Node* node, int path[], int pathLen);

void printPaths(Node* node)
{
    int path[1000];
    printPathsRecur(node, path, 0);
}

// Recursively find  all branches
void printPathsRecur(Node* node, int path[], int pathLen)
{
    if (node == NULL)
        return;

    path[pathLen] = node->i;
    pathLen++;

    if (node->pLeft == NULL && node->pRight == NULL)
    {
        printAndAddBranchSumArray(path, pathLen);
    }
    else
    { 
        printPathsRecur(node->pRight, path, pathLen);
    }
}


int main()
{
    int i;
    Node* pRoot = nullptr;
    while (true)
    {
        cin >> i;
        if (i == 99) {
            PrintTree(pRoot, 1);
            printPaths(pRoot);
            double max = *max_element(sumOfAllBranches.begin(), sumOfAllBranches.end());
            cout << "Max path sum: " << max << endl;

            break;
        }

        Node* p = new Node(i);
        InsertToTree(pRoot, p);

    }



    return 0;
}
