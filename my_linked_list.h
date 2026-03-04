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


class LinkedList {
private:
    Node* head;
    Node* tail;
    int length;
    LinkedList* linkedList;

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

    void pop_back()
    {
        auto temp = head;
        if (head != tail)
        {
            while (temp->next)
            {
                if (temp->next->next == nullptr)
                {
                    delete temp->next;
                    temp->next = nullptr;
                    tail = temp;
                    length--;
                    return;
                }
                temp = temp->next;
            }
        }
        else
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            length = 0;
        }
        if (head == nullptr)
        {
            return;
        }
    }

    void prepend(int value)
    {
        Node* newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void pop_front()
    {
        if (head == nullptr)
            return;

        if (head != tail)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        length--;
    }

    Node* get(int index)
    {
        if (index >= 0 && index < length)
        {
            Node* temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            return temp;
        }
        else
        {
            std::cout << "Invalid index!" << std::endl;
            return nullptr;
        }

    }

    bool set(int index, int value)
    {
        if (index >= 0 && index < length)
        {
            Node* temp = head;
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
            temp->value = value;
            return true;
        }
        else
        {
            return false;
        }
    }

    bool insert(int index, int value)
    {
        if (index >= 0 && index <= length)
        {
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
            Node* pre = head;
            for (int i = 0; i < index - 1; i++)
            {
                pre = pre->next;
            }
            newNode->next = pre->next;
            pre->next = newNode;
            length++;
            return true;
        }
        else { return false; }
    }

    bool deleteNode(int index)
    {
        if (index >= 0 && index < length)
        {
            if (index == 0)
            {
                pop_front();
                return true;
            }

            if (index == length - 1)
            {
                pop_back();
                return true;
            }
            Node* pre = head;
            for (int i = 0; i < index - 1; i++)
            {
                pre = pre->next;
            }
            Node* temp = pre->next;
            pre->next = pre->next->next;
            delete temp;
            length--;
            return true;
        }
        else
        {
            return false;
        }
    }

    void reverse()
    {
        if (head == nullptr) return;
        int golfPost = length;
        Node* temp = head;
        Node* headCopy = head;
        Node* tempLast = tail;
        while (golfPost > 1)
        {
            temp = head;
            for (int i = 0; i < golfPost - 2; i++)
            {
                temp = temp->next;
            }
            tempLast->next = temp;
            tempLast = temp;
            golfPost--;
        }
        head = tail;
        tail = headCopy;
        tail->next = nullptr;
    }

    void reverseAlt()
    {
        if (head == nullptr) return;
        int golfPost = length;
        Node* temp = head;
        Node* headCopy = head;
        Node* tempLast = tail;
        int count = 3;

        for (int i = 0; i <= golfPost - 2; i++)
        {
            temp = temp->next;
            if (i >= golfPost - count)
            {
                if (golfPost - 2 == 0)
                    temp = head;
                tempLast->next = temp;
                tempLast = temp;
                golfPost--;
                temp = head;
                i = -1;
            }

        }

        head = tail;
        tail = headCopy;
        tail->next = nullptr;
    }

    void reverseOn()
    {
        Node* before = nullptr;
        Node* temp = head;
        Node* after = head->next;
        head = tail;
        tail = temp;
        for (int i = 0; i < length; i++)
        {
            temp->next = before;
            before = temp;
            temp = after;
            if (after != nullptr)
                after = after->next;

        }
        tail->next = nullptr;
        std::cout << "done!" << std::endl;
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
        Node* fastTemp = head ;

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

    Node* reverseList() {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;
        Node* before = nullptr;
        Node* temp = head;
        Node* after = head->next;
        Node* headTemp = head;

        while (temp)
        {
            temp->next = before;
            before = temp;
            temp = after;
            if (temp != nullptr)
                head = temp;
            if (after != nullptr)
                after = after->next;

        }
        headTemp->next = nullptr;
        return head;
    }
};