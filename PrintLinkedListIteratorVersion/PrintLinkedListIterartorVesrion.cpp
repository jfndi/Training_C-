#ifndef _MSC_VER
#include <bits/stdc++.h>
#else
#include <iostream>
#include <iterator>
#include <vector>
#endif

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedListIterator;

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }

    friend class SinglyLinkedListIterator;
    typedef SinglyLinkedListIterator iterator;

    iterator begin();
    iterator end();
};

class SinglyLinkedListIterator
{
public:
    typedef std::ptrdiff_t difference_type;
    typedef std::forward_iterator_tag iterator_category;
    typedef SinglyLinkedListNode value_type;
    typedef SinglyLinkedListNode* pointer;
    typedef SinglyLinkedListNode& reference;

    reference operator*() const;
    pointer operator->() const { return &(operator*()); }
    SinglyLinkedListIterator& operator++();
    SinglyLinkedListIterator operator++(int);
    bool operator==(const SinglyLinkedListIterator& other) const;
    bool operator!=(const SinglyLinkedListIterator& other) const { return !operator==(other); }

    SinglyLinkedListIterator(SinglyLinkedListNode* node = nullptr) : node_(node) {}
private:
    SinglyLinkedListNode* node_;
};

SinglyLinkedListIterator::reference SinglyLinkedListIterator::operator*() const
{
    return *node_;
}

SinglyLinkedListIterator& SinglyLinkedListIterator::operator++()
{
    node_ = node_->next;
    return *this;
}

SinglyLinkedListIterator SinglyLinkedListIterator::operator++(int)
{
    auto tmp = *this;
    node_ = node_->next;
    return tmp;
}

bool SinglyLinkedListIterator::operator==(const SinglyLinkedListIterator& other) const
{
    return this->node_ == other.node_;
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the printLinkedList function below.

/*
 * As I promised I have implemented the same functionality
 * as in PrintLinkedList but I use a forward iterator
 * in this case.
 */
void printLinkedList2(SinglyLinkedList& llist)
{
    for (auto& e : llist)
        cout << e.data << endl;
}

int main()
{
    SinglyLinkedList llist{};

    int llist_count;
    cin >> llist_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        llist.insert_node(llist_item);
    }

    printLinkedList2(llist);

    return 0;
}

SinglyLinkedList::iterator SinglyLinkedList::begin()
{
    return iterator(this->head);
}

SinglyLinkedList::iterator SinglyLinkedList::end()
{
    return iterator(nullptr);
}
