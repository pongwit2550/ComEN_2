#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//constance
#define SIZE 50

char s[SIZE]; 
int top=-1;

//push stack
void push(char oper){
	if(top == SIZE - 1){
		printf("Stack Overflow\n");
		return;
	}
	s[++top] = oper;
}
//pop temp out stack 
char pop(){
	if(top == -1){
		printf("Stack Underflow\n");
		return -1;
	}
	return s[top--];
}
//Check if the character is an operator
int isOperator(char ch){
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
void getStackString(char *buffer){
	int i;
	for(i=0;i<=top;i++){
		buffer[i] = s[i];
	}
	buffer[i] = '\0';
}

void printRow(char infix, char *postfix){
	char stackstr[SIZE];
	int i;
	getStackString(stackstr);

	if(infix != '\0'){
		 printf("%-8c%-8s%-8s\n", infix, stackstr, postfix);
	}else{
		printf("%-8s%-8s%-8s\n", "", stackstr, postfix);
	}
	
}

int priority(char oper){
	switch(oper){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default:
			return -1;
	}
}
void display(char ch,char postfix[50]){
	printf("%c", ch);
}

void infixToPostfix(char infix[50]){
	int i=0,j=0;
	char ch;
	char postfix[50];

	while((ch = infix[i++]) != '\0'){
		if(isalnum(ch)){
			postfix[j++] = ch;
			postfix[j] = '\0';
			printRow(ch, postfix);
		}
		else if(ch == '('){
			push(ch);
			postfix[j] = '\0';
			printRow(ch, postfix);
		}
		else if(ch == ')'){
			while(top != -1 && s[top] != '('){
				postfix[j++] = pop();
				postfix[j] = '\0';
			}
			if(top != -1 && s[top] != '('){
				printf("Invalid Expression\n");
				return;
			}
			else{
				pop();
				printRow(ch, postfix);
			}
		}
		else if(isOperator(ch)){
			while(top != -1 && priority(s[top]) >= priority(ch)){
				postfix[j++] = pop();
				postfix[j] = '\0';
				
			}
			push(ch);
			printRow(ch, postfix);
		}
		else{
			printf("Invalid Character: %c\n", ch);
			return;
		}
	}
	while(top != -1){
		postfix[j++] = pop();
		postfix[j] = '\0';
		printRow('\0', postfix);
	}
	
}
int main(){        
	//Infix to Postfix Conversion
	//char postfix[50];	
	char infix[50];
	//input infix expression	
	printf("Enter an infix expression: ");
	scanf("%s", infix);
	printf("\nOutput:\n");
	infixToPostfix(infix);
	//printf("Postfix expression: %s\n", postfix);
	return 0;
}