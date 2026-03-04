#pragma once


#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node* prev;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};


class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    DoublyLinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList() {
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead() {
        if (head == nullptr) {
            cout << "Head: nullptr" << endl;
        }
        else {
            cout << "Head: " << head->value << endl;
        }
    }

    void getTail() {
        if (tail == nullptr) {
            cout << "Tail: nullptr" << endl;
        }
        else {
            cout << "Tail: " << tail->value << endl;
        }
    }

    void getLength() {
        cout << "Length: " << length << endl;
    }

    void append(const int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            length++;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        length++;
    }

    void deleteLast()
    {
        Node* temp = nullptr;
        if (head == nullptr) return;
        if (head == tail)
        {
            temp = head;
            delete temp;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }

        temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        length--;
    }

    void prepend(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            length++;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        length++;
    }

    void deleteFirst()
    {
        Node* temp = head;
        if (head == nullptr) return;
        if (head == tail)
        {
            delete temp;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }
        head = head->next;
        delete temp;
        head->prev = nullptr;
        length--;
    }

    Node* get(int index)
    {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        if (index < length / 2)
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        else
        {
            temp = tail;
            for (int i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value)
    {
        if (index < 0 || index >= length) return false;
        Node* temp = get(index);
        temp->value = value;
        return true;
    }

    bool insert(int index, int value)
    {
        if (head == nullptr) return false;
        if (index == 0)
        {
            prepend(value);
            return true;
        }
        if (index == length)
        {
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* temp = get(index);
        if (temp)
        {
            Node* preTemp = temp->prev;
            preTemp->next = newNode;
            newNode->prev = preTemp;
            newNode->next = temp;
            temp->prev = newNode;
            length++;
            return true;
        }
        return false;
    }

    bool deleteNode(int index)
    {
        if (head == nullptr) return false;
        if (index == 0)
        {
            deleteFirst();
            return true;
        }
        if (index == length - 1)
        {
            deleteLast();
            return true;
        }
        Node* temp = get(index);
        if (temp)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
            length--;
            return true;
        }
        return false;
    }

    void swapFirstLast()
    {
        if (head == nullptr) return;
        if (head->next == nullptr) return;
        int temp = head->value;
        head->value = tail->value;
        tail->value = temp;
    }

    void reverse()
    {
        if (head == nullptr) return;
        if (head->next == nullptr) return;
        Node* preTemp = nullptr;
        Node* temp = head;
        Node* afterTemp = head->next;
        while (temp)
        {
            temp->next = preTemp;
            temp->prev = afterTemp;
            preTemp = temp;
            temp = afterTemp;
            if (afterTemp != nullptr)
                afterTemp = afterTemp->next;
        }
        Node* tempHead = head;
        head = tail;
        tail = tempHead;
        tail->next = nullptr;
        head->prev = nullptr;
    }

    bool isPalindrome()
    {
        Node* left = head;
        Node* right = tail;
        int j = length - 1;

        for (int i = 0; i < length / 2;)
        {
            if (left->value != right->value) return false;
            i++;
            j--;
            left = get(i);
            right = get(j);
        }
        return true;
    }

    bool isPalindrome1()
    {
        if (head == nullptr) return false;
        if (head->next == nullptr) return true;
        Node* temp = head;
        std::stack<int> stack;

        while (temp != nullptr)
        {
            stack.push(temp->value);
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr)
        {
            if (temp->value != stack.top()) return false;
            temp = temp->next;
            stack.pop();
        }
        return true;
    }
};