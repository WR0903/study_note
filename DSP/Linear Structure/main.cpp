#include <stdlib.h>
#include "linklist.h"
//#include "LinkListClass.h"
#include <stdio.h>

int main()
{
    Node *test_list;
    test_list=creatList();
    for (int i=0;i<10;i++)
    {
        insert(test_list,i+1,i);
    }
    printf("\r\nCreat a list with 0~10 \r\n");
    printList(test_list);
    insert(test_list,5,12);
    printf("\r\nInsert 12 at position 5 \r\n");
    printList(test_list);
    remove(test_list,8);
    printf("\r\nRemove data 8 \r\n");
    printList(test_list);
    makeEmpty(test_list);
    //system("pause");
    return 0;
}
