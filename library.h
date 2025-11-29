#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <string>
using namespace std;

// ========== Book (Double Linked List) ==========
struct Book {
    string code;
    string title;
    int year;
};

struct BookNode {
    Book data;
    BookNode* prev;
    BookNode* next;
};

// List Buku
class BookList {
public:
    BookNode* head;
    BookNode* tail;
    BookList();
    ~BookList();
    bool isEmpty();
    void insertLast(Book b);
    BookNode* search(string code);
    void remove(string code);
    void display();
};

// ========== Member (Single Linked List) ==========
struct Member {
    string id;
    string name;
};

struct MemberNode {
    Member data;
    MemberNode* next;
};

// List Anggota
class MemberList {
public:
    MemberNode* head;
    MemberList();
    ~MemberList();
    bool isEmpty();
    void insertFirst(Member m);
    MemberNode* search(string id);
    void remove(string id);
    void display();
};

// ========== Stack Buku Sementara ==========
struct StackNode {
    string code;
    StackNode* next;
};

class StackList {
public:
    StackNode* top;
    StackList();
    bool isEmpty();
    void push(string code);
    string pop();
    void display();
};

// ========== Queue Peminjaman ==========
struct QueueNode {
    string code;
    QueueNode* next;
};

class QueueList {
public:
    QueueNode* front;
    QueueNode* rear;
    QueueList();
    bool isEmpty();
    void enqueue(string code);
    string dequeue();
    void display();
};

#endif