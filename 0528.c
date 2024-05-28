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
	printf("\n1: 리스트 처음에 숫자 추가\n");
	printf("2: 리스트 끝에 숫자 추가\n");
	printf("3: 리스트 처음 노드 삭제\n");
	printf("4: 리스트 마지막 노드 삭제\n");
	printf("5: 리스트 출력\n");
	printf("6: 프로그램 종료\n");
}

int main() {
	ListNode* tail = NULL;
	int choice;
	element data;

	while (1) {
		menu();
		printf("메뉴를 선택하세요: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf("숫자를 입력하세요: ");
			scanf("%d", &data);
			tail = insert_first(tail, data);
			break;

		case 2:
			printf("숫자를 입력하세요: ");
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
			printf("프로그램을 종료합니다.\n");
			exit(0);

		default:
			printf("잘못된 입력입니다. 다시 선택하세요.\n");
			break;
		}
	}
	return 0;
}