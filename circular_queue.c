/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define N 10
int queue[N];
int front = -1;
int rear = -1;
int checker = 0; //pomocna varijabla da vidimo jel zadnje koristen push ili pop
int isFull(){
    if(rear == N-1 && front == 0 && checker == 1) //znaci ako je krajnji na kraju a prednji na pocetku i push je zadnje koristen stog je pun
    return 1;
    else if(front == rear+1 && checker == 1) //tj ako je pocetak ispred kraja
    return 1;
    else return 0;
}
int isEmpty(){
    if(front == -1 && rear == -1) return 1; //ovo ako nismo uopce upotrijebili push 
    else 
  if(rear == N-1 && front == 0 && checker == 0) //isto ko i za full samo sto je zadnje koristen pop
    return 1;
    else if(front == rear+1 && checker == 0) return 1; //..
    else return 0;
}
void clear(){ //ovo da ocistimo red
    front = -1;
    rear = -1;
}
void push(int data){
    
    if(front == -1 && rear == -1 ){ //postavljanje na prvi element indekse i inicijalizacija prvog elementa
        front = 0;
        rear = 0;
        checker = 1;
        queue[rear] = data;
    }
    else if(!isFull()){ //ako nije pun puni se dalje i indeks se pomjera
        checker = 1;
     if(rear == N-1)
    rear = 0;
    else rear++;
        queue[rear]=data;
    }
    else{ //ako jest pun ..
       printf("Queue is full. Cannot push any more numbers. ");
    }
}
int pop(){
   int data;
   
    if(!isEmpty()){ //ako nije prazan vraca se varijabla i ona se uklanja tj indeks se smanjuje
        checker=0;
   data = queue[front];
    if(front == N-1)
    front = 0;
        else front++;
        
        return data;
    }
    else printf("Queue is empty. Cannot pop any more numbers. "); //ako jest prazan..
   
  
}
int main()
{  
  int i;  
  for(i = 0; i < 10; i++) //isprobavanje pusha
 push(i);
for(i = 0; i < 10; i++) //isprobavanje popa
printf("%d ", pop());

    return 0;
}
