#include <stdio.h>
#include "LinkedList.h"

int main() {
    // ��ʼ������
    Node* head;
    initializeLinkedList(&head);

    // ������ͷ������ڵ�
    insertAtHead(&head, 1);
    insertAtHead(&head, 2);
    insertAtHead(&head, 3);

    // ������β������ڵ�
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);

    // ��ָ��λ�ò���ڵ�
    insertAtPosition(&head, 6, 2);
    insertAtPosition(&head, 7, 4);

    // ��ӡ����Ԫ��
    printf("Linked List: ");
    printLinkedList(head);

    // ɾ��ͷ�ڵ�
    deleteAtHead(&head);

    // ɾ��β�ڵ�
    deleteAtTail(&head);

    // ɾ��ָ��λ�õĽڵ�
    deleteAtPosition(&head, 2);

    // ��ӡ����Ԫ�غͳ���
    printf("Linked List: ");
    printLinkedList(head);
    printf("Length: %d\n", getLength(head));

    return 0;
}
