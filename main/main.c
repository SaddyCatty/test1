#include <stdio.h>
#include "LinkedList.h"

int main() {
    // 初始化链表
    Node* head;
    initializeLinkedList(&head);

    // 在链表头部插入节点
    insertAtHead(&head, 1);
    insertAtHead(&head, 2);
    insertAtHead(&head, 3);

    // 在链表尾部插入节点
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);

    // 在指定位置插入节点
    insertAtPosition(&head, 6, 2);
    insertAtPosition(&head, 7, 4);

    // 打印链表元素
    printf("Linked List: ");
    printLinkedList(head);

    // 删除头节点
    deleteAtHead(&head);

    // 删除尾节点
    deleteAtTail(&head);

    // 删除指定位置的节点
    deleteAtPosition(&head, 2);

    // 打印链表元素和长度
    printf("Linked List: ");
    printLinkedList(head);
    printf("Length: %d\n", getLength(head));

    return 0;
}
