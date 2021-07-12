#include<stdio.h>
#include<stdlib.h>
int p,q,n,fn,i,x,y;
long key=1,X=1,Y=1,c;
int cprime(int a){
for(i=2;i<=a/2;i++)
if(a%i==0)
return 0;
return 1;
}
long fun(int e,long pt){
for(i=0,c=1;i<e;i++){
c*=pt;
c=c%p;
}
return c;
}
void main(){
printf("Enter p and alpha value: \n");
scanf("%d%d",&p,&q);
if(cprime(p) && q<p){
printf("Enter A's private key value: \n");
scanf("%d",&x);
if(x<p){
X=fun(x,q);
printf("A's public key: %ld\n",X);
printf("Enter B's private key value: \n");
scanf("%d",&y);
if(y<p){
Y=fun(y,q);
printf("B's public key: %ld\n",Y);
key=fun(x,Y);
printf("Shared key: %ld\n",key);
}
}
}
else{
printf("Run the application again!!!\n");
}
}
