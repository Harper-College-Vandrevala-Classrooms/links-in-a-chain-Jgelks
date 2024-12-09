#include <iostream>
#include <string>

using namespace std;

class ChainLink {
private:
    string color;

public:
    ChainLink(string color) : color(color) {}

    string get_color() const {
        return color;
    }
};

class Node {
public:
    ChainLink* data;
    Node* next;

    Node(ChainLink* data) : data(data), next(nullptr) {}

    Node(ChainLink* data, Node* next_node) : data(data), next(next_node) {}

    ChainLink* get_data() {
        return data;
    }
    
    Node* get_next() {
        return next;
    }

    void set_next(Node* next_node) {
        next = next_node;
    }
};

class LinkedList {
private:
    Node* head;

public:

    LinkedList() : head(nullptr) {}

    
    void append(ChainLink* new_link) {
        Node* new_node = new Node(new_link);

        if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->get_next() != nullptr) {
                temp = temp->get_next();
            }
            temp->set_next(new_node);
        }
    }

    ChainLink* get_at_index(int index) {
        Node* temp = head;
        int current_index = 0;

        while (temp != nullptr) {
            if (current_index == index) {
                return temp->get_data();
            }
            temp = temp->get_next();
            current_index++;
        }
        
        return nullptr;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->get_data()->get_color() << " -> ";
            temp = temp->get_next();
        }
        cout << "nullptr" << endl;
    }
};











int main() {

    ChainLink link_one("red");
    ChainLink link_two("blue");
    ChainLink link_three("green");

    LinkedList list;

    list.append(&link_one);
    list.append(&link_two);
    list.append(&link_three);

    cout << "Displaying the linked list:" << endl;
    list.display();

    ChainLink* retrieved_link = list.get_at_index(1);
    if (retrieved_link != nullptr) {
        cout << "Link at index 1: " << retrieved_link->get_color() << endl;
    } else {
        cout << "Index out of bounds!" << endl;
    }

    retrieved_link = list.get_at_index(2);
    if (retrieved_link != nullptr) {
        cout << "Link at index 2: " << retrieved_link->get_color() << endl;
    } else {
        cout << "Index out of bounds!" << endl;
    }

    retrieved_link = list.get_at_index(5);
    if (retrieved_link != nullptr) {
        cout << "Link at index 5: " << retrieved_link->get_color() << endl;
    } else {
        cout << "Index out of bounds!" << endl;
    }

    return 0;
} 