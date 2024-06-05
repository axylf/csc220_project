#include <cstdlib>
#include <string>

class Node {
private:
  int data;
  Node* prev, *next; //prev for previous

public:
  //constructors
  Node() {} //empty constructor for the funny

  Node(int data) { //lonely node
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }

  Node(int data, Node* prev, Node* next) { //we can define the previous and next on the fly
    this->data = data;
    this->prev = prev;
    this->next = next;
  }

  //getter methods
  int getData() {
    return data;
  }

  Node* getPrev() {
    return prev;
  }

  Node* getNext() {
    return next;
  }

  //setter methods
  void setData(int data) {
    this->data = data;
  }
  
  void setPrev(Node* prev) {
    this->prev = prev;
  }
  
  void setNext(Node* next) {
    this->next = next;
  }
};

class DoublyLinkedList {

private:
  Node* head, *tail;

public:
  //constructors
  DoublyLinkedList() { //for empty list
    head = NULL;
    tail = head;
  }
  DoublyLinkedList(int data) { //for one element list
    head = new Node(data);
    tail = head;
  }

  //methods
  void addToTail(int d) {
    if (head) {
      tail = new Node(d, tail, NULL); //the tail always points to null 
      (tail->getPrev())->setNext(tail); //we set the node before tail to have a next node of the new tail
    } else {  //case of empty linked list
      head = new Node(d);
      tail = head;
    }
  }

  void printElements() {
    Node* cursor;
    for (cursor = this->head; cursor; cursor = cursor->getNext()) {
      //we start at the head, the program runs while cursor != NULL, and we keep moving node by node forwards
      printf("%d\t", cursor->getData());
    }
    printf("\n");
  }

  void printReverse() {
    Node* cursor;
    for (cursor = tail; cursor; cursor = cursor->getPrev()) {
      //we start at the tail, the program runs while cursor != NULL, and we keep moving node by node backwards
      printf("%d\t", cursor->getData());
    }
    printf("\n");
  }

  //alternate recursive methods
  void printElementsRecursive(Node* head) { //these node parameter things are needed, it could be streamlined by making these into helper functions
    printf("%d\t", head->getData());
    if (head->getNext())
      printElementsRecursive(head->getNext());
  }

  void printReverseRecursive(Node* tail) {
    printf("%d\t", tail->getData());
    if (tail->getPrev())
      printReverseRecursive(tail->getPrev());
  }

  //getter methods
  Node* getHead() {
    return this->head;
  }
  Node* getTail() {
    return this->tail;
  }
};

int main() {
  bool program_running = true;
  int input;
  int add; //element we must add
  DoublyLinkedList list;
  srand(time(NULL)); //pseudo random stuff, we set the seed
  for (int i = 0; i < 15; i++) { //add 15 random elements to list
    list.addToTail(rand() % 100);
  }
  
  while (program_running) {
    printf("Welcome to the Doubly Linked List Test Program! Enter a number to begin! \n1 - Add new element\n2 - Print List Elements\n3 - Print List Elements in reverse order\n4 - Quit\n");
    if (scanf("%d", &input)) {
      switch (input) {
        case 1:
          printf("Add an integer: ");
          if (scanf("%d", &add))
            list.addToTail(add);
          else
            printf("Not an integer, try again.\n");
        break;
        case 2:
          list.printElements();
        break;
        case 3:
          list.printReverse();
        break;
        case 4:
          program_running = false;
        break;
        default: //failsafe to prevent crashing or undefined behavior
          list.printElements();
        break;
      }
    } else {
      printf("Error: Bad input.");
      program_running = false;
    }
  }
}