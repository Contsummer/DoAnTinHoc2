#pragma once
#include<iostream>
#include <fstream>
#include <cstdlib> 
const int listNumSize = 10;
using namespace std;
struct Node {
    bool dau;
    short int so;
    Node* next;
};
typedef Node* Bang;
Node* taoNode(int a);
void themNode(Node*& list, int a);
void inList(Node* list);
Node* init(Node*& a);
Node* daoChuoi(Node* head);
Node* Add(Node* a, Node* b);
Node* coppyNode(Node* list);
Node* Subtraction(Node* a, Node* b);
Node* max(Node* a, Node* b);
Node* times(Node* a, Node* b);
void  Nhap(Node*& a);
Node* Division(Node* a, Node* b); 
void xoaDau(Node*& a);
void menu(Bang a[]);
void subMenuTinhToan(Node* a, Node* b, Bang c[], int& e);
void subMenuTaoSo(Bang c[], int& b);
//void subMenuFile(string fileName, Bang c[], int b);
//void ghiFile(Node* list, const string& fileName);