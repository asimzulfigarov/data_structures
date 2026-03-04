#pragma once

#include <iostream>
#include <unordered_map>

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


class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;

public:
    LinkedList(int value) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~LinkedList() {
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

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* pre = head;
            while (temp->next) {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value) {
        Node* newNode = new Node(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;
        Node* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        }
        else {
            head = head->next;
        }
        delete temp;
        length--;
    }

    Node* get(int index) {
        if (index < 0 || index >= length) return nullptr;
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, int value) {
        Node* temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value) {
        if (index < 0 || index > length) return false;
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }
        Node* newNode = new Node(value);
        Node* temp = get(index - 1);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
        return true;
    }

    void deleteNode(int index) {
        if (index < 0 || index >= length) return;
        if (index == 0) return deleteFirst();
        if (index == length - 1) return deleteLast();

        Node* prev = get(index - 1);
        Node* temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }

    ////////////Exercises

    void reverse() {
        Node* temp = head;
        head = tail;
        tail = temp;
        Node* after = temp->next;
        Node* before = nullptr;
        for (int i = 0; i < length; ++i) {
            after = temp->next;
            temp->next = before;
            before = temp;
            temp = after;
        }
    }

    Node* findMiddleNode()
    {
        Node* middle = nullptr;
        if (head == nullptr) return middle;
        if (head == tail) return middle = head;

        Node* temp = head;
        int i{ 1 };
        middle = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
            i++;
            if (i % 2 == 0)
            {
                middle = middle->next;
            }

        }
        return middle;
    }

    bool hasLoop()
    {
        if (head == nullptr) return false;
        if (head == tail) return false;

        Node* slowTemp = head;
        Node* fastTemp = head;

        while (fastTemp->next != nullptr)
        {
            slowTemp = slowTemp->next;
            fastTemp = fastTemp->next->next;
            if (fastTemp == slowTemp)
            {
                return true;
            }
        }
        return false;

    }

    Node* findKthFromEnd(int k)
    { 
        Node* temp = head;
        Node* lateTemp = head;
        int i = 0;

        while (temp->next != nullptr)
        {
            temp = temp->next;
            i++;
            if (i >= k) lateTemp = lateTemp->next;
        }
        return lateTemp;
    }

    Node* removeNthFromEnd(int k)
    {

        if (head == nullptr) return nullptr;
        if (head->next == nullptr)
        {
            delete head;
            return nullptr;
        }

        Node* temp = head;
        Node* lateTemp = head;
        Node* prelateTemp = head;
        int i = 0;

        while (temp->next != nullptr)
        {
            temp = temp->next;
            i++;
            if (i >= k) lateTemp = lateTemp->next;
            if (i > k) prelateTemp = prelateTemp->next;
        }
        if (lateTemp == head)
        {
            head = head->next;
            delete lateTemp;
            return head;
        }
        prelateTemp->next = lateTemp->next;
        delete lateTemp;
        return head;
    }

    void partitionList(int x)
    {
        if (head == nullptr) return;
        if (head->next == nullptr) return;
        Node* temp = head;
        Node* smallHead = nullptr;
        Node* smallTail = nullptr;
        Node* bigHead = nullptr;
        Node* bigTail = nullptr;
        int s{ 0 };
        int b{ 0 };

        while (temp != nullptr)
        {
            if (temp->value < x && s == 0)
            {
                smallHead = temp;
                smallTail = temp;
                s++;
            }
                
            if (temp->value >= x && b == 0)
            {
                bigHead = temp;
                bigTail = temp;
                b++;
            }
            temp = temp->next;
            if (smallHead != nullptr && bigHead != nullptr) 
                break;
        }
        temp = head;

        while (temp != nullptr)
        {
            if (temp->value < x && temp != smallHead)
            {
                smallTail->next = temp;
                smallTail = temp;
            }
            
            if (temp->value >= x && temp != bigHead)
            {
                bigTail->next = temp;
                bigTail = temp;
            }  
            temp = temp->next;
        }
        if (smallTail != nullptr && bigTail != nullptr)
        {
            head = smallHead;
            smallTail->next = bigHead;
            bigTail->next = nullptr;
        }
    }

    void removeDuplicates()
    {
       
        
    }

    Node* removeElements(int val) {
        
    }
};






