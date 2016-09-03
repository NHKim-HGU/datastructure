#include <stdio.h>
#include <stdlib.h>

//������ ��� ����  
#define Data char

//����ü 
typedef struct Node{
	Data data; //Data �� char �������� 
	struct Node *L_link;
	struct Node *R_link;
}Node;

//�� ������ ��� �˻�
Node* finalNode(Node *s){
	while(s->R_link != NULL){
		s = s->R_link;
	}
	return s;
}

//�ǳ��� ��� ���� 
Node* createNode(Node *s/*�ǳ� ���*/, Data e/*������*/){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data = e;
	p->L_link = s;
	p->R_link = NULL;
	s->R_link = p;
	printf("push %c\n", e);
	return p;
}

//push : ������ �Է� 
void push(Node *s, Data e){
	Node *p = finalNode(s); // �Ǹ����� ��� �˻� 
	p = createNode(p, e); //������ 
}

//pop : ������ ����, ���� �տ� �ִ� ����� 
void pop(Node *s){
	if(s->R_link == NULL) { // ������� ��� 
		printf("queue is empty!!\n");
		return;
	}
	Node *p = s->R_link; //���� ó�� ���
	
	printf("pop : %c\n",p->data); //������ ���
	
	if(p->R_link != NULL) p->R_link->L_link = p->L_link; //���� ���� ��� �տ� �ִ� ����� ���� �ּҸ� �ʱ���� �ٲ��� 
	s->R_link = p->R_link; //���� ���� ����ּҸ� �Է�
	//�ּҸ� �ٲ��ְ� ��� �����ϸ� �ȴ�. 
	if(p->R_link == NULL) printf("Now, queue is empty!\n");
	free(p); // ��� ���� 
} 

//search : ������ �˻�
void search(Node *s, Data e){
	Node *p = s;
	
	if(s->R_link == NULL) {
		isListEmpty(s);
		return;
	}
	
	int cnt = 0; // ���° ������� ���� 
	int find = 0; // �˻� ���� ���� | 0 : ���� | 1: ���� |  
	isListEmpty(s);
	while(p != NULL){ //���� ���������� Ž�� 
		if(p->data == e){
			find = 1;
			printf("%c is in node%d\n", p->data, cnt);  //���⿡ ����! 
			break; //�ݺ��� �ı� 
		}
		p = p->R_link;
		cnt++; // ���� ���� 
	}
	if(find != 1) printf("there is no %c\n", e);
}

//��尹�� ���ϱ�
void count(Node *s){
	Node *p = s;
	int cnt = 0; // ���° ������� ī��Ʈ  
	isListEmpty(s);
	
	while(p->R_link != NULL){ //���� ���������� Ž�� 
		cnt++; // ���� ���� 
		p = p->R_link;
	}
	
	printf("the number of node is %d\n", cnt);  //��� ���� ��� 
} 

//���� ��� ��� 
void show(Node *s){
	int cnt=0;
	if(s->R_link == NULL) {
		isListEmpty(s);
		return;
	}
	while(s != NULL){
		if(cnt != 0) Print(s); //ù��° ���� �Ⱦ���. 
		s = s->R_link;
		cnt++;
	} 
	printf("\n");
}

//���� ���� ��� 
void reverse(Node *s){
	if(s->R_link == NULL) {
		isListEmpty(s);
		return;
	}
	s = finalNode(s);
	int cnt=0;
	while(s->L_link != NULL){
		Print(s);
		s = s->L_link;
		cnt++;
	}
	printf("\n");
}  

//Print : ���� ���� ���(�迭�� �����ϰ� ��µǵ���)
void Print(Node *s){
	printf("%c ", s->data);
} 

//����� �ʵ带 ����ϴ� �޼ҵ� 
void printNode(Node *s){
	printf("data : %c | L-link : %p | R-link : %p |\n", 
	s->data, s->L_link, s->R_link);
}

//��尡 ��������� ����ٰ� �˸��� �޼ҵ� 
void isListEmpty(Node *s){
	if(s->R_link == NULL) printf("queue is empty!!\n");
}


void main() {
	char input1, input2; //�Է� 
	Node *s; //�⺻ ������ 
	s = (Node*)malloc(sizeof(Node)); // ��� �ʱ�ȭ
	s->data = '.'; // �ʱ�ȭ ������ 
	s->L_link = NULL;
	s->R_link = NULL;
	
	printf("***********Command***********\n");
  	printf("+<c> : add <c>, P : pop, S : show all queue, R : show reverse queue\n");
   	printf("?<c> : search <c>, C : count node, Q: Quit\n");
   	printf("*****************************\n");
	
	while (1) {
      printf("\nCommand> ");
      input1 = getchar();
      input1 = toupper(input1);
  		 switch (input1) {
     		case '+':
      		   	input2 = getchar();
     		    push(s, input2);
    		    break;
    		    
 		    case 'P':
 		      	pop(s);
  		       	break;
  		       	
 		    case '?':
  		        input2 = getchar();
  		        search(s, input2);
  		       break;
  		       
  		    case 'C':
  		     	count(s);
  		     	break;
  		     	
  		    case 'S':
  		    	show(s);
			  	break;  
				  	
			case 'R':
  		    	reverse(s);
			  	break;  
				  		     	
  		    case 'Q':
  		        printf("\n");
  		        exit(1);
  		        break;
  		     default: break;
    		  }
   		   while(input1 != EOF && input1 !='\n'){
    		     input1 = getchar();
  		 }
	}
	
}
