#include "header.h"

void createTree(BinTree *T)
{
    *T = Nil;
}

bool IsUnerLeft(BinTree T)
{
    return(Right(T)==Nil && Left(T)!=Nil);
}

bool IsUnerRight(BinTree T)
{
    return(Right(T)!=Nil && Left(T)==Nil);
}

bool IsOneElmt(BinTree T)
{
    return(!(IsTreeEmpty(T)) && (Right(T)==Nil && Left(T)==Nil));
}

bool Search(BinTree T, infotype X)
{
    if(IsTreeEmpty(T))
    {
        return false;
    }
    else
    {
        if(Info(T)==X)
        {
            return true;
        }
        else
        {
            return (Search(Left(T),X));
        }
    }
}

bool IsTreeEmpty(BinTree T)
{
    return T == Nil;
}

address Alokasi(infotype X)
{
    address P;

    P=(address)malloc(sizeof(Node));
    if(P!=Nil)
    {
        Info(P) = X;
        Left(P) = Nil;
        Right(P) = Nil;
    }
    return P;
}

void Dealokasi(BinTree *P)
{
    free(*P);
}

void InserNode(BinTree *T, infotype X)
{
    if(IsTreeEmpty(*T))
    {
        *T = Alokasi(X);
    }
    else
    {
        if(X <= Info(*T))
        {
            InserNode(&Left(*T),X);
        }
        else
        {
            InserNode(&Right(*T),X);
        }
    }
}

void PrintPreOrder(BinTree T)
{
    if(IsTreeEmpty(T))
    {
        return;
    }
    else
    {
        printf("| %d ",Info(T));
        PrintPreOrder(Left(T));
        PrintPreOrder(Right(T));
    }
}

void PrintInOrder(BinTree T)
{
    if(IsTreeEmpty(T))
        {
        return;
    }
    else
    {
        PrintInOrder(Left(T));
        printf("| %d ",Info(T));
        PrintInOrder(Right(T));
    }
}

void PrintPostOrder(BinTree T)
{
    if(IsTreeEmpty(T))
    {
        return;
    }
    else
    {
        PrintPostOrder(Left(T));
        PrintPostOrder(Right(T));
        printf("| %d ",Info(T));
    }
}

void PrintPreOrderGanjil(BinTree T)
{
    if(IsTreeEmpty(T))
    {
        return;
    }
    else
    {
        if(Info(T)%2!=0)
        {
            printf("| %d ",Info(T));
        }
        PrintPreOrderGanjil(Left(T));
        PrintPreOrderGanjil(Right(T));
    }
}

void PrintPostOrderKanan(BinTree T)
{
    if(IsTreeEmpty(T))
    {
        return;
    }
    else
    {
        PrintPostOrderKanan(Left(T));
        PrintPostOrderKanan(Right(T));
        if(Right(T)!=Nil)
        {
            if(!IsOneElmt(T))
            {
                printf("| %d ",Info(T));
            }
        }
    }
}

int LevelLeft(BinTree P)
{
    return LevelTanpaX(Left(P));
}

int LevelTanpaX(BinTree P)
{
   if (IsOneElmt(P))
   {
       return 1;
   }
   else if(IsTreeEmpty(P))
    {
        return;
   }
   else{
       int lDepth = LevelTanpaX(Left(P));
       int rDepth = LevelTanpaX(Right(P));

       if(lDepth > rDepth)
       {
           return(lDepth+1);
       }
       else
       {
            return(rDepth+1);
       }
   }
}

void InsertNodeKiri(BinTree *T, infotype *X)
{
    if(IsTreeEmpty(*T))
    {
        *T = Alokasi(*X);
    }
    else if(IsOneElmt(*T))
    {
        *X = Info(*T);
        InsertNodeKiri(&Left(*T), X);
    }
    else
    {
        if(IsUnerLeft(*T))
        {
            InsertNodeKiri(&Left(*T), X);
        }
        else if(IsUnerRight(*T))
        {
            InsertNodeKiri(&Left(*T), X);
        }
        else
        {
            InsertNodeKiri(&Left(*T), X);
            InsertNodeKiri(&Right(*T), X);
        }
    }
}

void DelTerkanan(BinTree *T)
{
    if(IsOneElmt(*T) ||  IsUnerLeft(*T))
    {
        Dealokasi(&(*T));
        *T = Nil;
    }
    else
    {
        DelTerkanan(&(Right(*T)));
    }
}
