#pragma once

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    Node* root = nullptr;

    // Level-order insertion
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!root) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = newNode;
                return;
            }
            else {
                q.push(temp->left);
            }

            if (!temp->right) {
                temp->right = newNode;
                return;
            }
            else {
                q.push(temp->right);
            }
        }
    }

    // Print tree in level-order
    void printLevelOrder() {
        if (!root) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->val << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }

    bool isSymmetric()
    {
        if (root == nullptr) return false;
        Node* tempL = root->left;
        Node* tempR = root->right;
        if (tempL != tempR) false;



        while (tempL != nullptr && tempR != nullptr)
        {
            if ((tempL->left == nullptr) != (tempR->right == nullptr)) return false;
            if (tempL->left != nullptr && tempR->right != nullptr)
            {
                if (tempL->left->val != tempR->right->val) return false;
                tempL = tempL->left;
                tempR = tempR->right;
            }
            if ((tempL->right == nullptr) != (tempR->left == nullptr)) return false;
            if (tempL->right != nullptr && tempR->left != nullptr)
            {
                if (tempL->right->val != tempR->left->val) return false;
                tempL = tempL->right;
                tempR = tempR->left;
            }

        }
        return true;
    }
};

    

