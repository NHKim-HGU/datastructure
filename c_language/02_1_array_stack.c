#include <stdio.h>
#include <stdlib.h>

#define Data char //������ ����� 
#define MAX 100 //�迭�� ũ�⸦ ����
#define START 1 // �ε����� �����Ѵ�  

char arrayStack[MAX]; //�迭���� ���������� ���� 
int rear = 0; //�ʱ� ������ �������� 0�̶�� �ʱ�ȭ
//�˾ƺ��� ������ arrayStack[0] �ε����� ����ΰ� [1]�ε������� ä�� ���̴�. 

//push : ������ �Է� 
void push(Data data){
	if(rear == MAX-1){ //MAX�� 100�ε� �迭�� ���� [99] �ε����̹Ƿ� 
		printf("stack is already full!!\n");
		return;
	}
	//-1���� �����ϹǷ� ++ ������ �����ϰ� �����͸� �ִ´�. 
	arrayStack[++rear] = data; // ���� �������� ����Ű�� rear�� ��ġ�� ������ �Է� 
	printf("push %c\n", data);
	printf("rear = %d\n", rear);
} 

//pop : ������ ��� 
void pop(){
	if(rear == 0){
		printf("stack is empty!!\n");
		return;
	}
	printf("pop stack : %c\n", arrayStack[rear--]); //������ ����ϰ� ���� ������ ���
	printf("rear = %d\n", rear);
}

//search : ������ �˻�(������ ���°�� �ִ��� �˻�) 
void search(Data data){
	int i, j = 0;
	
	for(i = START;i<=rear;i++){
		if(arrayStack[i] == data) {
			printf("%c is in %d\n", arrayStack[i], i);	
			j = 1;
		}
	}
	if(j != 1) { //�� ���Ҵµ� ��ã�� ��� 
		printf("%c doesn't exist\n", data);
	} 
}

//show : ���ÿ� ���ִ� �����͸� ������� ���
void show(){
	int i;
	for(i=START;i<=rear;i++){
		printf("%c  ", arrayStack[i]);
	}
	printf("\n");
} 

//count : ������ ���� ���
void count(){
	printf("the number of stack is %d\n", rear);
} 

void main() {
	char input1, input2; //�Է� 
	int i;
	for(i=0; i<MAX;i++) arrayStack[i] = 0; // ���ù迭 �ʱ�ȭ 
	
	printf("***********Command***********\n");
  	printf("+<c> : push <c>, P : pop, S : show all stack\n");
   	printf("?<c> : search <c>, C : count stack, Q: Quit\n");
   	printf("*****************************\n");
	
	while (1) {
      printf("\nCommand> ");
      input1 = getchar();
      input1 = toupper(input1);
  		 switch (input1) {
     		case '+':
      		   	input2 = getchar();
     		    push(input2);
    		    break;
    		    
 		    case 'P':
 		      	pop();
  		       	break;
  		       	
 		    case '?':
  		        input2 = getchar();
  		        search(input2);
  		       break;
  		     	
  		    case 'S':
  		    	show();
			  	break;  
				  	
			case 'C':
  		    	count();
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
