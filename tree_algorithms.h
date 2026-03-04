#pragma once

#include <iostream>
#include <queue>


using namespace std;


class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};


class BinarySearchTree {
public:
    Node* root;

public:
    BinarySearchTree() { root = nullptr; }

    void destroy(Node* currentNode) {
        if (currentNode->left) destroy(currentNode->left);
        if (currentNode->right) destroy(currentNode->right);
        delete currentNode;
    }

    ~BinarySearchTree() { destroy(root); }

    bool rContains(Node* currentNode, int value) {
        if (currentNode == nullptr) return false;

        if (currentNode->value == value) return true;

        if (value < currentNode->value) {
            return rContains(currentNode->left, value);
        }
        else {
            return rContains(currentNode->right, value);
        }
    }

    bool rContains(int value) {
        return rContains(root, value);
    }

    Node* rInsert(Node* currentNode, int value) {
        if (currentNode == nullptr) return new Node(value);
        if (value < currentNode->value) {
            currentNode->left = rInsert(currentNode->left, value);
        }
        else if (value > currentNode->value) {
            currentNode->right = rInsert(currentNode->right, value);
        }
        return currentNode;
    }

    void rInsert(int value) {
        if (root == nullptr) root = new Node(value);
        rInsert(root, value);
    }

    Node* deleteNode(Node* currentNode, int value) {
        if (currentNode == nullptr) return nullptr;
        if (value < currentNode->value) {
            currentNode->left = deleteNode(currentNode->left, value);
        }
        else if (value > currentNode->value) {
            currentNode->right = deleteNode(currentNode->right, value);
        }
        else {
            if (currentNode->left == nullptr && currentNode->right == nullptr) {
                delete(currentNode);
                return nullptr;
            }
            else if (currentNode->left == nullptr) {
                Node* temp = currentNode->right;
                delete currentNode;
                return temp;
            }
            else if (currentNode->right == nullptr) {
                Node* temp = currentNode->left;
                delete currentNode;
                return temp;
            }
            else {
                int subTreeMin = minValue(currentNode->right);
                currentNode->value = subTreeMin;
                currentNode->right = deleteNode(currentNode->right, subTreeMin);
            }
        }
        return currentNode;
    }

    void deleteNode(int value) {

        root = deleteNode(root, value);
    }

    int minValue(Node* currentNode) {
        while (currentNode->left != nullptr) {
            currentNode = currentNode->left;
        }
        return currentNode->value;
    }

    void BFS() {
        queue<Node*> myQueue;
        myQueue.push(root);
        
        while (myQueue.size() > 0) {
            Node* currentNode = myQueue.front();
            myQueue.pop();
            cout << currentNode->value << " ";
            if (currentNode->left) {
                myQueue.push(currentNode->left);
            }
            if (currentNode->right) {
                myQueue.push(currentNode->right);
            }
        }
    }


    void DFSPreOrder(Node* currentNode) {
        cout << currentNode->value << " ";
        if (currentNode->left != nullptr) {
            DFSPreOrder(currentNode->left);
        }
        if (currentNode->right != nullptr) {
            DFSPreOrder(currentNode->right);
        }
    }

    void DFSPreOrder() { DFSPreOrder(root); }


    void DFSPostOrder(Node* currentNode) {
        if (currentNode->left != nullptr) {
            DFSPostOrder(currentNode->left);
        }
        if (currentNode->right != nullptr) {
            DFSPostOrder(currentNode->right);
        }
        cout << currentNode->value << " ";
    }

    void DFSPostOrder() { DFSPostOrder(root); }


    void DFSInOrder(Node* currentNode) {
        if (currentNode->left != nullptr) {
            DFSInOrder(currentNode->left);
        }
        cout << currentNode->value << " ";
        if (currentNode->right != nullptr) {
            DFSInOrder(currentNode->right);
        }
    }

    void DFSInOrder() { DFSInOrder(root); }

    ///////////////leet code

    vector<int> inorderTraversal(Node* root) {
        static vector<int> tree;
        if (root == nullptr) return tree;
        if (root->left) {
             inorderTraversal(root->left);
        }
        tree.push_back(root->value);
        if (root->right) {
            inorderTraversal(root->right);
        }
        return tree;
    
    }


    ////////////////
    

    ////////////////
};
