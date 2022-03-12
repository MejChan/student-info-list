/*
 * (1)����ָ��ѧ���������������ѧ����Ϣ;
 * (2)�����ʾѧ����������ѧ���������Ϣ;
 * (3)�����������в��ң����ش�ѧ����ѧ�źͳɼ�;
 * (4)����ָ����λ�ÿɷ�����Ӧ��ѧ����Ϣ��ѧ�ţ��������ɼ�);
 * (5)����һ��ѧ����Ϣ�����뵽����ָ����λ��;
 * (6)ɾ��ָ��λ�õ�ѧ����¼;
 * (7)ͳ�Ʊ���ѧ��������
 */

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#pragma warning(disable : 4996 6031 6054)

//ѧ������
int student_count = 0;

typedef struct list {
	int student_number;
	char* student_name;
	int student_score;
	list* next;
};

list* head = nullptr;

//��������¼�����ݣ���һ���ڵ�����,lenΪ����
void create_list(int len) {
	head = new list;
	list* temp = head;
	for (int i = 0; i < len; ++i) {
		temp->next = new list;
		temp = temp->next;

		int number;
		char* name=new char[13];
		int score;
		printf("���� %d ��ѧ����\n", i + 1);
		printf("ѧ�ţ�");
		scanf("%d", &number);
		printf("������");
		scanf("%s", name);
		printf("�ɼ���");
		scanf("%d", &score);
		
		temp->student_number = number;
		temp->student_name = name;
		temp->student_score = score;
		temp->next = nullptr;
	}
}

//����һ���½ڵ㵽����indexΪҪ�����λ�ã���Χ1��n+1��ԭ�ڵ�һ������ƶ�
//λ��Ϊ1��nʱ��һ�������Ϊn+1ʱ�ǵڶ������
void list_insert(int index) {
	int number;
	char* name = new char[13];
	int score;
	
	printf("ѧ�ţ�");
	scanf("%d", &number);
	printf("������");
	scanf("%s", name);
	printf("�ɼ���");
	scanf("%d", &score);

	if (index == student_count + 1) {
		//���2��ֱ����������ӽڵ�
		list* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		list* ready = new list;
		ready->student_number = number;
		ready->student_name = name;
		ready->student_score = score;
		ready->next = nullptr;
		
		temp->next = ready;
	}
	else {
		//���1��ԭ�ڵ��������
		list* before = head;
		for (int i = 0; i < index - 1; ++i) {
			before = before->next;
		}

		list* ready = new list;
		ready->student_number = number;
		ready->student_name = name;
		ready->student_score = score;
		ready->next = before->next;

		before->next = ready;
	}

	++student_count;
}

//ɾ��һ���ڵ㣬indexΪҪɾ���Ľڵ��λ��
void list_delete(int index) {
	list* before = head;
	for (int i = 0; i < index - 1; ++i) {
		before = before->next;
	}

	list* del = before->next;

	before->next = before->next->next;
	
	delete del;

	--student_count;
}

//(1)����ָ��ѧ���������������ѧ����Ϣ
void order1() {
	printf("����ѧ��������");
	int count = 0;
	scanf("%d", &count);

	if (!count) {
		printf("ѧ����������Ϊ0");
		return;
	}
	
	student_count = count;
	printf("ѧ��������%d\n", count);
	
	create_list(count);
	printf("���̡���Ϣ¼�����\n");
}

//(2)�����ʾѧ����������ѧ���������Ϣ
void order2() {
	list* temp = head->next;
	int i = 1;

	while (temp) {
		printf("��ѧ��%d�� ѧ�ţ�%d  ������%s  �ɼ���%d\n",
			i,
			temp->student_number,
			temp->student_name,
			temp->student_score
		);
		
		temp = temp->next;
		++i;
	}

	printf("���̡�����ѧ����Ϣ����ʾ\n");
}

//(3)�����������в��ң����ش�ѧ����ѧ�źͳɼ�
void order3() {
	char name[13];
	printf("����������");
	scanf("%s", name);

	list* temp = head->next;

	while (temp) {
		if (!strcmp(name, temp->student_name)) {
			printf("ѧ�ţ�%d  �ɼ���%d\n",
				temp->student_number,
				temp->student_score
			);

			printf("���̡����ҵ�����\n");
			return;
		}
		temp = temp->next;
	}

	printf("������δ�ҵ�����\n");
}

//(4)����ָ����λ�ÿɷ�����Ӧ��ѧ����Ϣ��ѧ�ţ��������ɼ�)
void order4() {
	int index = 0;
	printf("�鿴λ�ã�");
	scanf("%d", &index);

	if (index > student_count || index < 1) {
		printf("������λ�� %d ������\n", index);
		return;
	}

	list* temp = head;
	for (int i = 0; i < index; ++i) {
		temp = temp->next;
	}
	printf("ѧ�ţ�%d  ������%s  �ɼ���%d\n",
		temp->student_number,
		temp->student_name,
		temp->student_score
	);
	
	printf("���̡�λ��%d����Ϣ����ʾ\n", index);
}

//(5)����һ��ѧ����Ϣ�����뵽����ָ����λ��
//����λ��ԭ�еĽڵ�����ƣ�����list_insert���и���ע�ͣ�
void order5() {
	int index = 0;
	printf("����λ�ã�");
	scanf("%d", &index);

	if (index > student_count + 1 || index < 1) {
		printf("������λ�� %d ������\n", index);
		return;
	}

	list_insert(index);

	printf("���̡��µ���Ϣ����ɹ�\n");
}

//(6)ɾ��ָ��λ�õ�ѧ����¼
void order6() {
	int index = 0;
	printf("ɾ��λ�ã�");
	scanf("%d", &index);

	if (index > student_count || index < 1) {
		printf("������λ�� %d ������\n", index);
		return;
	}

	list_delete(index);

	printf("���̡�λ��%d��ɾ��\n", index);
}

//(7)ͳ�Ʊ���ѧ������
void order7() {
	printf("ѧ��������%d\n", student_count);
	printf("���̡�ͳ��ѧ�������ɹ�\n");
}



int main(void) {
	while (1) {
		int input = 0;
		printf("	(1)����ָ��ѧ���������������ѧ����Ϣ;\n" \
			   "	(2)�����ʾѧ����������ѧ���������Ϣ;\n" \
			   "	(3)�����������в��ң����ش�ѧ����ѧ�źͳɼ�;\n" \
			   "	(4)����ָ����λ�ÿɷ�����Ӧ��ѧ����Ϣ��ѧ�ţ��������ɼ�);\n" \
			   "	(5)����һ��ѧ����Ϣ�����뵽����ָ����λ��;\n" \
			   "	(6)ɾ��ָ��λ�õ�ѧ����¼;\n" \
			   "	(7)ͳ�Ʊ���ѧ��������\n");

		printf("��ѡ��\n");
		scanf("%d", &input);

		if (input != 1 && head == nullptr) {
			printf("������û�п��õı�����ʹ��(1)����һ���±�\n");
			getch();
			continue;
		}

		if (input == 1 && head != nullptr) {
			printf("����������һ�����������´���\n");
			getch();
			continue;
		}

		switch (input) {
			default: {
				printf("������Ч\n");
				getch();
				break;
			}
			case 1: {
				order1();
				getch();
				break;
			}
			case 2: {
				order2();
				getch();
				break;
			}
			case 3: {
				order3();
				getch();
				break;
			}
			case 4: {
				order4();
				getch();
				break;
			}
			case 5: {
				order5();
				getch();
				break;
			}
			case 6: {
				order6();
				getch();
				break;
			}
			case 7: {
				order7();
				getch();
				break;
			}
			
		}


	}
}


