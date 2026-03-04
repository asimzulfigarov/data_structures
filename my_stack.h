#pragma once

#include <iostream>

using namespace std;


class Node {
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
};


class Stack {
private:
    Node* top;
    int height;

public:
    Stack(int value) {
        Node* newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    ~Stack() {
        Node* temp = top;
        while (top) {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    void printStack() {
        Node* temp = top;
        while (temp) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getTop() {
        if (top == nullptr) {
            cout << "Top: nullptr" << endl;
        }
        else {
            cout << "Top: " << top->value << endl;
        }
    }

    void getHeight() {
        cout << "Height: " << height << endl;
    }

    void push(int value)
    {
        Node* newNode = new Node(value);
        if (top == nullptr)
        {
            top = newNode;
            height++;
        }
        newNode->next = top;
        top = newNode;
        height;
    }

    int pop()
    {
        if (top == nullptr) return INT_MIN;
        int r = top->value;
        Node* temp = top;
        temp = top->next;
        delete top;
        top = temp;
        height--;
        return r;
    }
};