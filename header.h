#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Nil NULL

typedef int infotype;
typedef struct Node *address;
typedef struct Node{
    infotype Info;
    address Left;
    address Right;
}Node;

typedef address BinTree;

#define Info(P) (P)->Info
#define Left(P) (P)->Left
#define Right(P) (P)->Right

void createTree(BinTree *T);
bool IsUnerLeft(BinTree T);
bool IsUnerRight(BinTree T);
bool IsOneElmt(BinTree T);
bool Search(BinTree T, infotype X);
bool IsTreeEmpty(BinTree T);
address Alokasi(infotype X);
void Dealokasi(BinTree *T);
void InserNode(BinTree *T,infotype X);
void PrintPreOrder(BinTree T);
void PrintInOrder(BinTree T);
void PrintPostOrder(BinTree T);
void PrintPreOrderGanjil(BinTree T);
void PrintPostOrderKanan(BinTree T);
int LevelLeft(BinTree P);
int LevelTanpaX(BinTree P);
void InserNodeKiri(BinTree *T, infotype X);
void DelTerkanan(BinTree *T);

#endif // HEADER_H_INCLUDED
