#include <stdio.h>

typedef struct TreeNode {
	int data; //������ 
	tree_node* P_link; //�θ����ּ� 
	tree_node* L_link; //�����ڽĳ���ּ� 
	tree_node* R_link; //�������ڽĳ���ּ� 
}TreeNode;

TreeNode create(int data){
	TreeNode *tmp;
	tmp = (TreeNode) malloc(sizeof(TreeNode));
	tmp->data = data;
	tmp->L_link = NULL;
	tmp->R_link = NULL; 
	return tmp;
}
 
void insertTree(TreeNode *node, int data){
	if(node->L_link == NULL || node->R_link){
		
	}
} 

void deleteTree(TreeNode *node, int data){
	if(node->data == data){
		if(node->L_link == NULL && node->R_link == NULL) 
	}
}

void search(TreeNode *node, int data){
	
}

void preorder(TreeNode *node){
	printf("���� ��ȸ : ");
	printf("%c ", node->data);
	preorder(node->L_link);
	preorder(node->R_link);
}

void inorder(TreeNode *node){
	printf("���� ��ȸ : ");
	inorder(node->L_link);
	printf("%c ", node->data);
	inorder(node->R_link);
}

void postorder(TreeNode *node){
	printf("���� ��ȸ : ");
	postorder(node->L_link);
	postorder(node->R_link);
	printf("%c ", node->data);
}



int main(){
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
  		    	preorder()
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
	return 0;
}
