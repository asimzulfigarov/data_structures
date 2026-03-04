#pragma once

#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <stack>

//Linked List LeetCode definition

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};


// 160. Intersection of Two Linked Lists


int findLength(ListNode* head) {
    ListNode* temp = head;
    int length{ 0 };
    while (temp) {
        length++;
        temp = temp->next;
    }
    return length;
}




ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int lenA = findLength(headA);
    int lenB = findLength(headB);
    ListNode* tempA = headA;
    ListNode* tempB = headB;
    if (lenA <= lenB) {
        for (size_t i = 0; i < lenB - lenA; i++)
        {
            tempB = tempB->next; 
        }
    }
    else {
        for (size_t i = 0; i < lenA - lenB; i++)
        {
            tempA = tempA->next;
        }
    }

    while (tempA && tempB) {
        if (tempA == tempB)
            return tempA;
        tempA = tempA->next;
        tempB = tempB->next;
    }
    return nullptr;
}






//21. Merge Two Sorted Lists


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
 
    while (list1 && list2) {
        if (list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        }
            
        else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }
    if (list1)
        temp->next = list1;
    else
        temp->next = list2;

    ListNode* head = dummy->next;
    delete dummy;

    return head;
}


//141. Linked List Cycle

bool hasCycle(ListNode* head) {

    ListNode* slowTemp = head;
    ListNode* fastTemp = head;

    while (fastTemp != nullptr && fastTemp->next != nullptr)
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

// 206. Reverse Linked List

ListNode* reverseList(ListNode* head) {
    ListNode* before = nullptr;
    ListNode* temp = head;
    ListNode* after = nullptr;


    while (temp)
    {
        after = temp->next;
        temp->next = before;
        before = temp;
        temp = after;
    }
    return before;
}

// 234. Palindrome Linked List


//Stack Solution

bool isPalindrome(ListNode* head) {
    std::stack<int> stack;
    ListNode* curr = head;

    // Push all values to the stack
    while (curr) {
        stack.push(curr->val);
        curr = curr->next;
    }

    // Compare while traversing again
    curr = head;
    while (curr) {
        if (curr->val != stack.top()) return false;  // <-- your fix here
        stack.pop();
        curr = curr->next;
    }

    return true;
}


////////////////////////////

// Reverse Soltuion    and   O(1) space solution


ListNode* reverse(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


bool isPalindromeLessSpace(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode* rev = reverse(slow);
    while (rev != nullptr) {
        if (head->val != rev->val) {
            return false;
        }
        head = head->next;
        rev = rev->next;
    }
    return true;
}


// 142. Linked List Cycle II


ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) break;
    }

    if (!fast || !fast->next) return nullptr;

    fast = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

// 876. Middle of the Linked List

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


// 19. Remove Nth Node From End of List


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0); // create dummy node
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast n+1 steps ahead so slow points to node before target
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both until fast hits end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove target node
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    head = dummy->next;
    delete dummy; // clean up dummy
    return head;
}




//2. Add Two Numbers


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* newNode = new ListNode(0);
    ListNode* newHead = newNode;
    int remainder{ 0 };

    while (l1 && l2) {

        if (((l1->val + l2->val) + remainder) < 10) {
            newNode->val = (l1->val + l2->val) + remainder;
            remainder = 0;
        }
        else
        {
            newNode->val = ((l1->val + l2->val) + remainder) % 10;
            remainder = 1;
        }
        l1 = l1->next;
        l2 = l2->next;
        if (l1 && l2) {
            newNode->next = new ListNode(0);
            newNode = newNode->next;
        }
    }

    while (l1 || l2) {
        newNode->next = new ListNode(0);
        newNode = newNode->next;
        if (l1) {
            if (l1->val + remainder >= 10) {
                newNode->val = (l1->val + remainder) % 10;
                remainder = 1;
            }
            else {
                newNode->val = l1->val + remainder;
                remainder = 0;
            }
            l1 = l1->next;
        }
        else {
            if (l2->val + remainder >= 10) {
                newNode->val = (l2->val + remainder) % 10;
                remainder = 1;
            }
            else {
                newNode->val = l2->val + remainder;
                remainder = 0;
            }
            l2 = l2->next;
        }
    }

    if (remainder == 1) {
        newNode->next = new ListNode(0);
        newNode = newNode->next;
        newNode->val = 1;
    }

    return newHead;
}



// TextBook solution 

ListNode* addTwoNumbersNew(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0);
    ListNode* res = dummy;
    int total = 0, carry = 0;

    while (l1 || l2 || carry) {
        total = carry;

        if (l1) {
            total += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            total += l2->val;
            l2 = l2->next;
        }

        int num = total % 10;
        carry = total / 10;
        dummy->next = new ListNode(num);
        dummy = dummy->next;
    }

    ListNode* result = res->next;
    delete res;
    return result;
}


/*




// Middle Node

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


//Has Cycle   -    Linked List Cycle

bool hasCycle(ListNode* head) {
    if (head == nullptr) return false;
    if (head->next == nullptr) return false;

    ListNode* slowTemp = head;
    ListNode* fastTemp = head;

    while (fastTemp != nullptr && fastTemp->next != nullptr)
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

// Remove Kth node from end of Linked list


ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0); // create dummy node
    dummy->next = head;

    ListNode* fast = dummy;
    ListNode* slow = dummy;

    // Move fast n+1 steps ahead so slow points to node before target
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both until fast hits end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove target node
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    head = dummy->next;
    delete dummy; // clean up dummy  ------- Handles Edge case where head  === kth element
    return head;
}


/// Remove Duplicates from Sorted List

ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;
    ListNode* fast = head->next;
    ListNode* slow = head;

    while (fast != nullptr) {
        if (slow->val == fast->val) {
            slow->next = fast->next;
            ListNode* toDelete = fast;
            fast = fast->next;
            delete toDelete;
        }
        else {
            slow = fast;
            fast = fast->next;
        }


    }
    return head;


    // Remove Duplicates From an Unsorted Linked List solution

    Node* removeDuplicates(Node * head) {
        unordered_set<int> hashSet;
        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {

            // Check if the element is already in the hash table
            if (hashSet.find(curr->data) != hashSet.end()) {

                // Element is present, remove it
                prev->next = curr->next;

                // Delete the curr node
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            else {

                // Element is not present, add it to hash table
                hashSet.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }


    // Function to remove duplicates using nested loops


    Node* removeDuplicates(Node* head) {
        Node* curr1 = head;

        // Traverse each node in the list
        while (curr1 != nullptr) {
            Node* curr2 = curr1;

            // Traverse the remaining nodes to find and 
            // remove duplicates
            while (curr2->next != nullptr) {

                // Check if the next node has the same 
                // data as the current node
                if (curr2->next->data == curr1->data) {

                    // Duplicate found, remove it
                    Node* duplicate = curr2->next;
                    curr2->next = curr2->next->next;

                    // Free the memory of the duplicate node
                    delete duplicate;
                }
                else {

                    // If the next node has different data from 
                    // the current node, move to the next node
                    curr2 = curr2->next;
                }
            }

            // Move to the next node in the list
            curr1 = curr1->next;
        }
        return head;
    }


    ///// Binary to Decimal


    int getDecimalValue(ListNode* head) {
        int result{ 0 };
        ListNode* temp = head;
        while (temp != nullptr) {
            result = (result * 2) + temp->val;
            temp = temp->next;
        }
        return result;
    }


    //Partition List


    ListNode* partition(ListNode* head, int x) {
        ListNode* leftDummy = new ListNode(0);   // Dummy head for nodes < x
        ListNode* rightDummy = new ListNode(0);  // Dummy head for nodes >= x

        ListNode* left = leftDummy;
        ListNode* right = rightDummy;

        while (head) {
            if (head->val < x) {
                left->next = head;
                left = left->next;
            }
            else {
                right->next = head;
                right = right->next;
            }
            head = head->next;
        }

        right->next = nullptr;          // Terminate right list
        left->next = rightDummy->next;  // Connect left and right lists

        ListNode* newHead = leftDummy->next;
        delete leftDummy;
        delete rightDummy;
        return newHead;
    }
};


*/