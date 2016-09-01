#include <stdio.h>
#include <stdlib.h>

//������ ��� ���� 
#define Data char

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

//����� �ʵ带 ����ϴ� �޼ҵ� 
void printNode(Node *s){
	printf("data : %c | L-link : %p | R-link : %p |\n", 
	s->data, s->L_link, s->R_link);
}

//��尡 ��������� ����ٰ� �˸��� �޼ҵ� 
void isListEmpty(Node *s){
	if(s->R_link == NULL) printf("list is empty!!\n");
}


//��� �߰� 
void addNode(Node *s, Data e){
	Node *p;
	s = finalNode(s); // �Ǹ����� ��� �˻� 
	
	p =(Node*)malloc(sizeof(Node)); // ��� ũ�⸸ŭ �����Ҵ�
	p-> data  = e ; //������ ������ �Է�
	p->L_link = s; //���� �ּҿ��� ���������(���ݳ��)�� �ּ� �Է� 
	p->R_link = NULL; // ������ ǥ�� ,  �����ʿ� null�Է� 
	s->R_link = p;// ������ ��尡 ����Ų�ٰ� ǥ�� 
	
	printf("new Node created!\n"); //��������� ǥ�� 
}

 //��� ����  �����Ͱ� ��ġ�ϴ� ��� ���� 
void deleteNode(Node *s, Data e){
	Node *p = s;
	isListEmpty(s);
	while(p != NULL){ //���� ���������� Ž�� 
		if(p->data == e){
			if(p->R_link == NULL){ //������ ����� ��� 
				p->L_link->R_link = NULL; // �������� �������� 
			} else { //�������� �ƴѰ�� 
				p->R_link->L_link = p->L_link; //������ ��尡 ����Ű�� ������ ������ ����� L_link�� ����
				p->L_link->R_link = p->R_link; //������ ��尡 ����Ű�� �������� ���� ����� R_link�� ���� 
			} 
			printf("%c is deleted\n", p->data); //����ǥ�� 
			free(p); // p��� ���� 
			isListEmpty(s); //���� ��尡 ���ٸ� ����ٰ� ǥ�� 
			break; //�ݺ��� �ı� 
		}
		p = p->R_link;
	}
	
} 

//��� �˻� 
void searchNode(Node *s, Data e){
	Node *p = s;
	int cnt = 0, find=0; // ���° ������� ���� 
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
void countNode(Node *s){
	Node *p = s;
	int cnt = 0; // ���° ������� ī��Ʈ  
	isListEmpty(s);
	
	while(p->R_link != NULL){ //���� ���������� Ž�� 
		cnt++; // ���� ���� 
		p = p->R_link;
	}
	
	printf("the number of node is %d", cnt);  //��� ���� ��� 
} 

//��� ��带 ������� ����ϴ� �޼ҵ�   
void showNode(Node *s){
	int cnt=0;
	while(s != NULL){
		if(cnt != 0) printNode(s);
		s = s->R_link;
		cnt++;
	}  
}

//��� ������ ���ݴ�� ����ϴ� �޼ҵ�  
void reverseNode(Node *s){
	s = finalNode(s);
	int cnt=0;
	while(s->L_link != NULL){
		printNode(s);
		s = s->L_link;
		cnt++;
	}
} 


void main() {
	char input1, input2; //�Է� 
	Node *s;
	s = (Node*)malloc(sizeof(Node)); // ��� �ʱ�ȭ
	s->data = '.'; // �ʱ�ȭ ������ 
	s->L_link = NULL;
	s->R_link = NULL;
	
	printf("***********Command***********\n");
  	printf("+<c> : add <c>, -<c> : delete <c>,\n");
   	printf("?<c> : search <c>, C : count node, Q: Quit\n");
   	printf("*****************************\n");
	
	while (1) {
      printf("\nCommand> ");
      input1 = getchar();
      input1 = toupper(input1);
  		 switch (input1) {
     		case '+':
      		   	input2 = getchar();
     		    addNode(s, input2);
    		    break;
    		    
 		    case '-':
 		     	input2 = getchar();
 		      	deleteNode(s, input2);
  		       	break;
  		       	
 		    case '?':
  		        input2 = getchar();
  		        searchNode(s, input2);
  		       break;
  		       
  		    case 'C':
  		     	countNode(s);
  		     	break;
  		     	
  		    case 'S':
  		    	showNode(s);
			  	break;  
				  	
			case 'R':
  		    	reverseNode(s);
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
