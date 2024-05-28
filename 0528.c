#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct listNode {
	element data;
	struct listNode* link;
} ListNode;

ListNode* insert_first(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link;
		tail->link = node;
	}
	return tail;
}

void print_list(ListNode* tail) {
	ListNode* p;

	if (tail == NULL) return;
	p = tail->link;
	do {
		printf("[%2d] ", p->data);
		p = p->link;
	} while (p != tail->link);
}

ListNode* insert_last(ListNode* tail, element data) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode)); // <1>
	node->data = data; // <2>

	if (tail == NULL) {
		tail = node;
		node->link = node;
	}
	else {
		node->link = tail->link; //<3>
		tail->link = node; //<4>
		tail = node; //<5>
	}
	return tail; //<5>
}

ListNode* delete_first(ListNode* tail) {
	if (tail == NULL) return NULL;
	ListNode* head = tail->link;
	if (head == tail) {
		free(head);
		return NULL;
	}
	else {
		tail->link = head->link;
		free(head);
		return tail;
	}
}

ListNode* delete_last(ListNode* tail) {
	if (tail == NULL) return NULL;
	ListNode* prev = tail;
	ListNode* curr = tail->link;
	if (prev == curr) {
		free(tail);
		return NULL;
	}
	while (curr->link != tail->link) {
		prev = curr;
		curr = curr->link;
	}
	prev->link = tail->link;
	free(tail);
	return prev;
}

void menu() {
	printf("\n1: ����Ʈ ó���� ���� �߰�\n");
	printf("2: ����Ʈ ���� ���� �߰�\n");
	printf("3: ����Ʈ ó�� ��� ����\n");
	printf("4: ����Ʈ ������ ��� ����\n");
	printf("5: ����Ʈ ���\n");
	printf("6: ���α׷� ����\n");
}

int main() {
	ListNode* tail = NULL;
	int choice;
	element data;

	while (1) {
		menu();
		printf("�޴��� �����ϼ���: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("���ڸ� �Է��ϼ���: ");
			scanf("%d", &data);
			tail = insert_first(tail, data);
			break;

		case 2:
			printf("���ڸ� �Է��ϼ���: ");
			scanf("%d", &data);
			tail = insert_last(tail, data);
			break;

		case 3:
			tail = delete_first(tail);
			break;

		case 4:
			tail = delete_last(tail);
			break;

		case 5:
			print_list(tail);
			break;

		case 6:
			printf("���α׷��� �����մϴ�.\n");
			exit(0);

		default:
			printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
			break;
		}
	}
	return 0;
}