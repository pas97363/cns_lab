#include<stdio.h>
#include<stdlib.h>
int p,q,e,n,d,fn,i,j,temp,temp0,split;
long c=1,pt=1,ct=1,m=1;
int cprime(int a){
for(i=2;i<=a/2;i++)
if(a%i==0)
return 0;
return 1;
}
int gcd(int a,int b){
int temp1;
while(b!=0){
temp1=b;
b=a%b;
a=temp1;
}
return a;
}
void gener(){
for(i=1;i<fn;i++)
for(j=-fn;j<0;j++)
if(((fn*i)+(e*j))==1){
d=j+fn;
}
printf("Calculated d value: %d\n",d);
}
long fun(int e,long pt){
for(i=0,c=1;i<e;i++){
c*=pt;
c=c%n;
}
return c;
}
int gene(){
n=p*q;
fn=((p-1)*(q-1));
for(i=fn-1;i>1;i--)
if(gcd(i,fn)==1){
e=i;
printf("Calculated e value: %d\n",e);
break;
}
}
void main(){
printf("Enter p and q values: \n");
scanf("%d%d",&p,&q);
if(cprime(p) && cprime(q)){
printf("Enter plaintext value: \n");
scanf("%ld",&m);
gene();
gener();
ct=fun(e,m);
printf("Ciphertext: %ld\n",ct);
pt=fun(d,ct);
printf("Plaintext: %ld\n",pt);
}
else{
printf("Run the application again!!!\n");
}
}
