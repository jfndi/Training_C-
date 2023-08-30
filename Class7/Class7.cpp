#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
    int key;
    Node(Node* p, Node* n, int k, int val) :prev(p), next(n), key(k), value(val) {};
    Node(int k, int val) :prev(NULL), next(NULL), key(k), value(val) {};
};

class Cache {

protected:
    map<int, Node*> mp; //map the key to the node in the linked list
    int cp;  //capacity
    Node* tail; // double linked list tail pointer
    Node* head; // double linked list head pointer
    virtual void set(int, int) = 0; //set function
    virtual int get(int) = 0; //get function

};



class LRUCache : public Cache
{
private:
    void update_cache_order(Node* entry)
    {
        if (entry->prev == head)
        {
            return;
        }

        for (auto node = head->next; node != tail; node = node->next)
        {
            if (node == entry)
            {
                entry->next->prev = entry->prev;
                entry->prev->next = entry->next;

                entry->prev = head;
                entry->next = head->next;

                head->next->prev = entry;
                head->next = entry;

                break;
            }
        }
    }

    Node* get_node_from_map(int key)
    {
        Node* ret;

        try
        {
            ret = mp.at(key);
        }
        catch (out_of_range& /*e*/)
        {
            return nullptr;
        }

        assert(ret->key == key);

        return ret;
    }

    void remove_last_entry()
    {
        Node* last = tail->prev;
        mp.erase(last->key);

        
        tail->prev = last->prev;
        last->prev->next = tail;

        last->prev = last->next = nullptr;
        delete last;
    }

    void insert_new_node(Node* entry)
    {
        entry->prev = head;
        entry->next = head->next;

        head->next->prev = entry;
        head->next = entry;

        mp.insert({ entry->key, entry });
    }

public:

#define INVALID_VALUES 0xFFFFFFFF

    LRUCache() = delete;
    LRUCache(int capacity) : Cache()
    {
        mp = move(map<int, Node*>{});
        cp = capacity;
        /*
         * Use dummy nodes as Node anchors. 
         */
        head = new Node(INVALID_VALUES, INVALID_VALUES);
        tail = new Node(INVALID_VALUES, INVALID_VALUES);

        tail->next = nullptr;
        tail->prev = head;
        head->prev = nullptr;
        head->next = tail;
    }

    virtual ~LRUCache()
    {
        Node* entry;

        for (entry = head->next; entry != tail;)
        {
            Node* tmp = entry->next;
            delete entry;
            entry = tmp;
        }
        /*
         * Don't forget the dummy nodes. 
         */
        delete head;
        delete tail;
    }

    virtual void set(int key, int value)
    {
        Node* entry;

        if (mp.size() == cp)
            remove_last_entry();

        if ((entry = get_node_from_map(key)) != nullptr) 
        {
            entry->value = value;
            update_cache_order(entry);
        }
        else
        {
            entry = new Node(key, value);
            insert_new_node(entry);
        } 
    }

    virtual int get(int key)
    {
        size_t len = mp.size();
        if (len)
        {
            Node* found = get_node_from_map(key);

            if (found == nullptr)
                return -1;
            
            if (len > 1)
                update_cache_order(found);

            return found->value;
        }

        return -1;
    }
};

int main() {
    int n, capacity, i;
    cout << "Enter  number of loops and capacity: ";
    cin >> n >> capacity;
    LRUCache l(capacity);
   
    for (i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        }
        else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
        else
            break;
    }
    return 0;
}