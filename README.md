[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/j-DzvjBA)
Jan Miko Bautista
CS-210 03/02/25
Programming Assignment 1: Space Mission Tracker using a Doubly Linked List

Hello, my name is Jan Miko and this is my first time writing a README section/file.

Overview
This program utilizes a doubly linked list to simulate a space mission for a space craft called Voyager-210.
The Voyage-210 can go forwards and backwards visiting various stopping points called celestial waypoints.
This code allows for the adding, removing, and traversing these celestial waypoints in an efficient way.

Key Features
- Insertion and Deletion: methods to add or remove celestial waypoints in three different ways.
  - this includes at the beginning, end, and at an index
- Traversing the Route: methods to display the route in two directions
  - both forward and backward
- Dynamic Memory Management: implements managing dynamic memory for adding and removing nodes

Methods
Here I will list what each Method does.

Insertion Methods:
- addWaypointAtBeginning: add a new waypoint as a node at the beginning of the link list
    - I put an if statement to consider when the link list is empty
- addWaypointAtEnd: add a new waypoint as a node at the end of the link list
    - Similar to the the insert at beginning, I wrote an if statement for the edge case of an empty link list.
    - I used an else statement for when the link is not empty when adding to the end of the link list
- addWaypointAtIndex: 

Deletion Methods:
- 

-

-

Traversal Methods:
-

-

Getter and Setter Methods:
-

-

Print Method:
- 

Time Complexity
Here I will state the Big 0 Complexity for each method and my reasonings.

- addWaypointAtBeginning:O(1) This is because the lines of code are just assignment and comparison operators which run
in constant time
- addWaypointAtEnd: O(1) This is also constant time as it runs just primitive operations
- addWaypointAtIndex: O(n) To insert at a certain index we would have to traverse the list so it's n time

removeWaypointAtBeginning: O(1)
removeWaypointAtEnd: O(1)
removeWaypointAtIndex: O(n)

traverseForward: O(n)
traverseBackward: O(n)

getWaypoint: O(n)
setWaypoint: O(n)

print: O(n)













