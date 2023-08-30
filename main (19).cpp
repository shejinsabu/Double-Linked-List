#include <iostream>
using namespace std;

struct node {
  int data;
  node *next;
  node *prev;
  node(int _data, node* _next, node* _prev) {
    data = _data;
    next = _next;
    prev = _prev;
  }
};

class linkedlist {
  private:
    node *head;

  public:
    linkedlist() {
      head = nullptr;
    }

    ~linkedlist() {
      node* cu = head;
      while (cu != nullptr) {
        node* temp = cu;
        cu = cu->next;
        delete temp;
      }
    }

    void addAtHead(int value) {
      node* temp = new node(value, head, nullptr);
      if(head != nullptr)
        head->prev = temp;
      head = temp;
    }

    void addAtTail(int value) {
      node* temp = new node(value, nullptr, nullptr);
      if(head == nullptr)
        head = temp; 
      else {
        node* cu = head;
        while(cu->next != nullptr)
          cu = cu->next;
        cu->next = temp;
        temp->prev = cu;
      }
    }

    void removeAtHead() {
      if(head == nullptr)
        return;
      else {
        node* temp = head;
        head = head->next;
        if(head != nullptr)
          head->prev = nullptr;
        delete temp;
      }
    }

    void removeAtTail() {
      if(head == nullptr)
        return;
      else if(head->next == nullptr) {
        node* temp = head;
        head = nullptr;
        delete temp;
      }
      else {
        node* cu = head;
        while(cu->next->next != nullptr)
          cu = cu->next;
        node* temp = cu->next;
        cu->next = nullptr;
        delete temp;
      }
    }



    void print() {
      node* cu = head;
      cout << "forward" << endl;
      while(cu->next != nullptr) {
        cout << cu->data << ' ';
        cu = cu->next;
      }
      cout << cu->data << endl << endl;
      cout << "backward" << endl;
      while(cu->prev != nullptr) {
        cout << cu->data << ' ';
        cu = cu->prev;
      }
      cout << cu->data << endl;
    }
};

int main() {
  return 0;
}