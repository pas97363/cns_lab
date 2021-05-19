#include<stdio.h>
#include<stdlib.h>
int p,q,e,n,pt=1,ct=1,m=1,d,fn,i,j,temp,temp0;
void main(){
printf("Enter p and q values: \n");
scanf("%d%d",&p,&q);
printf("Enter e and plaintext value: \n");
scanf("%d%d",&e,&m);
gener();
ct=fun(e,m);
printf("Ciphertext: %d\n",ct);
pt=fun(d,ct);
printf("Plaintext: %d\n",pt);
}
void gener(){
n=p*q;
fn=((p-1)*(q-1));
for(i=1;i<fn;i++)
for(j=-fn;j<0;j++)
if(((fn*i)+(e*j))==1){
d=j+fn;
}
}
int fun(int e,int pt){
temp=e/7;
temp0=e%7;
int cit[temp];
for(j=0;j<temp;j++){
for(i=7,ct=1;i>0;i--){
ct*=pt;}
cit[j]=ct%n;
}
for(i=0,ct=1;i<temp0;i++)
ct*=pt;
ct=ct%n;
for(i=0;i<temp;i++)
ct*=cit[i];
ct=ct%n;
return ct;
}
