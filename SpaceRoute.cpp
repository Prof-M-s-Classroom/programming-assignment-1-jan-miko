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
    Node<T>* head;
    Node<T>* tail;

public:
    SpaceRoute();  // Constructor
    ~SpaceRoute(); // Destructor

    void addWaypointAtBeginning(T& data) {
        Node<T>* newNode = new Node<T>(data);
        if (head == nullptr) { //add 1st node when link list is empty
            newNode -> data = data;
            newNode -> next = nullptr;
            newNode -> prev = nullptr;
            head = newNode;
            tail = newNode;
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
    void addWaypointAtIndex(int index, T& data){}
    void removeWaypointAtBeginning(){}
    void removeWaypointAtEnd(){}
    void removeWaypointAtIndex(int index){}
    void traverseForward(){}
    void traverseBackward(){}
    Node<T>* getWaypoint(int index){}
    void setWaypoint(int index, T& data){}
    void print(){

            Node<T>* current = head;
            while (current) {
                current->print();
                current = current->next;
            }
            cout << endl;
        }

};

