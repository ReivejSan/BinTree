
#include "header.h"

int main()
{
    BinTree T;
    int X;

    createTree(&T);
    InserNode(&T,6);
    InserNode(&T,2);
    InserNode(&T,5);
    InserNode(&T,2);
    InserNode(&T,8);
    InserNode(&T,7);
    InserNode(&T,7);
    InserNode(&T,4);
    InserNode(&T,4);
    InserNode(&T,4);
    InserNode(&T,5);
    InserNode(&T,5);
    InserNode(&T,5);

    printf("Pre Order Ganjil : ");
    PrintPreOrderGanjil(T);
    printf("\n\n");

    printf("Post Order Anak Kanan : ");
    PrintPostOrderKanan(T);
    printf("\n\n");

    printf("Pre Order : ");
    PrintPreOrder(T);
    puts("");

    printf("Tinggi Sub Pohon Kiri : ");
    printf("%d", LevelLeft(T));
    printf("\n\n");

    printf("Insert Kiri Sama : \n");
    InsertNodeKiri(&T, &X);
    printf("Post Order : ");
    PrintPostOrder(T);
    printf("\n\n");

    printf("Delete Terkanan : ");
    DelTerkanan(&T);
    puts("");
    printf("Post Order : ");
    PrintPostOrder(T);
    printf("\n\n");

    getchar();
    return 0;
}
