#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
using namespace std;

// ===== Double Linked List (BOOKS) =====
struct Book {
    string code, title;
    int year;
};

struct BookNode {
    Book data;
    BookNode *prev, *next;
};

class BookList {
public:
    BookNode *head, *tail;
    BookList();
    bool isEmpty();
    void addBook(Book data);
    void displayBooks();
    BookNode* searchBook(string code);
    void deleteBook(string code);
};

// ===== Single Linked List (MEMBERS) =====
struct Member {
    string id;
    string name;
};

struct MemberNode {
    Member data;
    MemberNode *next;
};

class MemberList {
public:
    MemberNode *head;
    MemberList();
    bool isEmpty();
    void registerMember(Member data);
    MemberNode* searchMember(string id);
    void displayMembers();
};

// ===== Stack (BOOK SELECTION) =====
struct StackNode {
    string bookCode;
    StackNode *next;
};

class StackList {
public:
    StackNode *top;
    StackList();
    bool isEmpty();
    void push(string code);
    string pop();
    void displayStack();
};

// ===== Queue (BORROW REQUEST) =====
struct QueueNode {
    string memberID, bookCode;
    QueueNode *next;
};

class QueueList {
public:
    QueueNode *front, *rear;
    QueueList();
    bool isEmpty();
    void enqueue(string memberID, string bookCode);
    string dequeue(string &outMember);
    void displayQueue();
    void displayQueueByMember(string memberID);
};

#endif