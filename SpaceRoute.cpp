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
    int length;

public:
    SpaceRoute() {// Constructor //O(1)
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    ~SpaceRoute() {// Destructor //O(n)
        Node<T> *temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    void addWaypointAtBeginning(T& data) { //O(1)
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr) { //add 1st node when link list is empty
            head = newNode;
            tail = newNode; //1st node is also head

        } else { // add 2nd node at Beginning
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;   //either way the length gets updated
    }

    void addWaypointAtEnd(T& data) { //O(1)
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr) { // add 1st node when link list is empty
            head = newNode;
            tail = newNode;

        } else { // add 2nd node at End
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    void addWaypointAtIndex(int index, T& data) { //O(n)
        Node<T> *newNode = new Node<T>(data);
        if (index == 0) { //same code as addWaypointAtBeginning
            Node<T> *newNode = new Node<T>(data);
            if (head == nullptr) { //add 1st node when link list is empty
                head = newNode;
                tail = newNode; //1st node is also head

            } else { // add 2nd node at Beginning
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        else {
            Node<T> *temp = head;
            for (int i = 0; i < index - 1; i++) { //traverse until just before desired index
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;   //insert newNode after temp
            newNode->prev = temp;
            newNode->next->prev = newNode; //make sure can traverse in reverse
        }
        length++;
    }
    void removeWaypointAtBeginning() { //O(1)
        // if only one node in link list
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        // if more than one node in link list
        else if (head != nullptr) {
            head = head->next;
            delete head->prev;
            head->prev = nullptr;
        }
        length--;
    }
    void removeWaypointAtEnd() { //O(1)
        // if only one node in link list
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }// if more than one node in link list
        else if (head != nullptr) {
            tail = tail -> prev;
            delete tail -> next;
            tail -> next = nullptr;
        }
        length--;
    }
    void removeWaypointAtIndex(int index) { //O(n)
        if (index == 0) {
            // if only one node in link list
            if (head->next == nullptr) { //similar code to removeWaypointAtBeginning
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            // if more than one node in link list
            else if (head != nullptr) {
                head = head->next;
                delete head->prev;
                head->prev = nullptr;
            }
        }
        else {
            Node<T> *temp = head;
            for (int i = 0; i < index; i++) {//traverse to desired index
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
        length--;
    }

    void traverseForward() { //prints list forward from head //O(n)
        Node<T>* traverser = head;
        while (traverser != nullptr) {
            cout <<traverser->data<<endl;
            traverser = traverser -> next;
        }
    }
    void traverseBackward() { //prints list backward from tail //O(n)
        Node<T>* traverser = tail;
        while (traverser != nullptr) {
            cout <<traverser->data<<endl;
            traverser = traverser -> prev;
        }

    }
    Node<T>* getWaypoint(int index) { //from Canvas template //O(n)
        if (index < 0 || index >= length) //check if index is within proper range
            return nullptr;
        Node<T> *temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp;
    }

    void setWaypoint(int index, T& data) { //O(n)
        Node<T> *temp = getWaypoint(index);
        if (temp) { //if possible add new data
            temp->data = data;
        }
    }

    void print(){ //prints exactly like traverseForward so it's redundant //O(n)
            Node<T>* temp = head;
            while (temp != nullptr) {
                temp->print();
                temp = temp->next;
            }
            cout << endl;
        }

};

