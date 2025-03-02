#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node {
public:
    T& data;
    Node* next;
    Node* prev;

    Node(T& d) : data(d), next(nullptr), prev(nullptr) {}
    void print() { cout << data << " "; }
};

class CelestialNode {
private:
    string name;
    double distance_from_earth;
    string mission_log;

public:
    CelestialNode(const string& n, double d, const string& log);
    const string& getName() const;
    double getDistance() const;
    const string& getMissionLog() const;
    void print() const { cout << name << " (" << distance_from_earth << " AU) - " << mission_log << endl; }
};

template <typename T>
class SpaceRoute {
private:
    T& data;
    Node<T>* head;
    Node<T>* tail;
    Node<T>* next;
    Node<T>* prev;
    int length;

public:
    SpaceRoute(T& *data) {// Constructor
        Node<T> *newNode = new Node<T>(&data);
        head = newNode;
        tail = newNode;
        length = 1;
    }
    ~SpaceRoute() {// Destructor
        Node<T> *temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    void addWaypointAtBeginning(T& data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr) { //add 1st node when link list is empty
            newNode -> data = data;
            newNode -> next = nullptr;
            newNode -> prev = nullptr;
            length = 1
        } else { // add 2nd node at Beginning
            newNode -> data = data;
            newNode -> next = nullptr;
            newNode -> prev = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addWaypointAtEnd(T& data) {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr) { // add 1st node when link list is empty
            newNode -> data = data;
            newNode -> next = nullptr;
            newNode -> prev = nullptr;
            head = newNode;
            tail = newNode;
        } else { // add 2nd node at End
            newNode -> data = data;
            newNode -> next = nullptr;
            newNode -> prev = tail;
            tail -> next = newNode;
            tail = newNode;
        }
    }
    void addWaypointAtIndex(int index, T& data) {

    }
    void removeWaypointAtBeginning() {
        // if only one node in link list
        if (head -> next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
        }
        // if more than one node in link list
        else if (head != nullptr) {
            head = head -> next;
            delete head -> prev;
            head -> prev = nullptr;
            length--;
        }
    }
    void removeWaypointAtEnd() {
        // if only one node in link list
        if (head-> next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
        }// if more than one node in link list
        else if (head != nullptr) {
            tail = tail -> prev;
            delete tail -> next;
            tail -> next = nullptr;
            length--;
        }
    }
    void removeWaypointAtIndex(int index){}

    void traverseForward(Node<T>*head) { //prints list forward from head
        Node<T>* traverser = head;
        while (traverser != nullptr) {
            cout <<traverser->data<<endl;
            traverser = traverser -> next;
        }
    }
    void traverseBackward(Node<T>*tail) { //prints list backward from tail
        Node<T>* traverser = tail;
        while (traverser != nullptr) {
            cout <<traverser->data<<endl;
            traverser = traverser -> prev;
        }

    }
    Node<T>* getWaypoint(int index){}
    void setWaypoint(int index, T& data){}
    void print(){ //prints exactly like traverseForward so redundant
            Node<T>* temp = head;
            while (temp != nullptr) {
                temp -> print();
                temp = temp -> next;
            }
            cout << endl;
        }

};

