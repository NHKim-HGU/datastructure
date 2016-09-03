#include <stdio.h>
#include <stdlib.h>


#define Data char //������ ����� 
#define MAX 10 //�迭�� ũ�⸦ ����
#define START 1 // �ε����� �����Ѵ�  

 
char arrayQueue[MAX]; //�迭���� ���������� ���� 
int rear = 0; //ť�� ��  
int front = 0; //ť�� ��  
//���� ť�� ��ȯ�ؾ��ϹǷ� ��� �迭�� �� ä���� ����Ѵ�. 

//push : ������ �Է� 
//�����Ͱ� ������,  rear ���� 
void push(Data data){
	if(rear%MAX == (front%MAX)-1){ // ���������� front-1 = rear 
		printf("Queue is already full!!\n"); 
			
	} else{ // �������� ������,  
		arrayQueue[rear%MAX] = data; // ���� �������� ����Ű�� rear�� ��ġ�� ������ �Է� 
		rear++; // rear ���� 
		printf("push %c\n", data);
	}
	printPoint();
} 

//pop : ������ ��� front ���� 
void pop(){
	if(front%MAX == rear%MAX) {
		printf("Stack is empty!!\n");
		return; // ��������� ���� 
	}	
	
	//�����͸� ����ϰ� front ���� 
	printf("pop : %c\n", arrayQueue[front++]); 
	arrayQueue[front-1] = '.'; // �� �ʱ�ȭ 
	printPoint();
}


//search : ������ �˻�(������ ���°�� �ִ��� �˻�) 
void search(Data data){
	int i, j = 0;
	
	for(i = front;i<=rear;i++){
		if(arrayQueue[i] == data) {
			printf("%c is in %d\n", arrayQueue[i], i);	
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
	for(i=front;i<=rear;i++){
		printf("%c  ", arrayQueue[i%MAX]);
	}
	printf("\n");
	printPoint();
} 

//count : ������ ���� ���
void count(){
	printf("the number of Queue is %d\n", rear-front+1);
} 


void printPoint(){
	printf("front = %d\n", front%MAX);
	printf("rear = %d\n", rear%MAX);
}

void main() {
	char input1, input2; //�Է� 
	int i;
	for(i=0; i<MAX;i++) arrayQueue[i] = 0; // ���ù迭 �ʱ�ȭ 
	
	printf("***********Command***********\n");
  	printf("+<c> : push <c>, P : pop, S : show all queue\n");
   	printf("?<c> : search <c>, C : count queue, Q: Quit\n");
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
