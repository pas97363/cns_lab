#include<stdio.h>
#include<stdlib.h>
int *j;
int p[10],k[10],k1[8],k2[8],p10[10],p8[8],ip[8],ep[8],ipi[8],p4[4],i,l,m,temp,q[4],s[4],si[4];
int p10t[10]={3,5,2,7,4,10,1,9,8,6},p8t[8]={6,3,7,4,8,5,10,9},ipt[8]={2,6,3,1,4,8,5,7};
int ept[8]={4,1,2,3,2,3,4,1},p4t[4]={2,4,3,1},ipit[8]={4,1,3,5,7,2,8,6};
int s0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
int s1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
int * exor(int a[],int b[]){
static int r[8];
for(i=0;i<8;i++){
if(a[i] == b[i])
r[i]=0;
else
r[i]=1;
}
return r;
}
void main(){
printf("Enter the Plaintext: \n");
for(i=0;i<8;i++)
scanf("%d",&p[i]);
printf("Enter the Key: \n");
for(i=0;i<10;i++)
scanf("%d",&k[i]);
k1gen();
k2gen();
printf("Key 1: \n");
for(i=0;i<8;i++)
printf("%d",k1[i]);
printf("\nKey 2: \n");
for(i=0;i<8;i++)
printf("%d",k2[i]);
printf("\n");
e1();
e2();
}
void k1gen(){
for(i=0;i<10;i++){
temp=(p10t[i]-1);
p10[i]=k[temp];
//printf("%d %d\n",p10[i],temp);
}
ls_1();
for(i=0;i<8;i++){
temp=(p8t[i]-1);
k1[i]=p10[temp];
}
}
void k2gen(){
ls_1();
ls_1();
for(i=0;i<8;i++)
k2[i]=p10[(p8t[i]-1)];
}
void ls_1(){
temp=p10[0];
for(i=0;i<4;i++)
p10[i]=p10[i+1];
p10[4]=temp;
temp=p10[5];
for(i=5;i<9;i++)
p10[i]=p10[i+1];
p10[9]=temp;
}
void e1(){
for(i=0;i<8;i++){
ip[i]=p[(ipt[i]-1)];
if(i>3)
s[i-4]=ip[i];
if(i<4)
q[i]=ip[i];
}
for(i=0;i<8;i++)
ep[i]=s[(ept[i]-1)];
/*for(i=0;i<8;i++)
printf("%d\t",ep[i]);
printf("\n");*/
j=exor(ep,k1);
/*for(i=0;i<8;i++)
printf("%d\t",*(j+i));
printf("\n");*/
for(i=0;i<4;i=i+2){
si[i]=(s0[(2*(*(j+0+(2*i))))+(*(j+3+(2*i)))][(2*(*(j+1+(2*i))))+(*(j+2+(2*i)))])/2;
if(i == 2)
si[i]=(s1[(2*(*(j+0+(2*i))))+(*(j+3+(2*i)))][(2*(*(j+1+(2*i))))+(*(j+2+(2*i)))])/2;
//printf("%d\t%d\t%d\n",(2*(*(j+0+(2*i))))+(*(j+3+(2*i))),(2*(*(j+1+(2*i))))+(*(j+2+(2*i))),s0[(2*(*(j+0+(2*i))))+(*(j+3+(2*i)))][(2*(*(j+1+(2*i))))+(*(j+2+(2*i)))]);
}
for(i=1;i<4;i=i+2){
si[i]=(s0[(2*(*(j+0+(2*(i-1)))))+(*(j+3+(2*(i-1))))][(2*(*(j+1+(2*(i-1)))))+(*(j+2+(2*(i-1))))])%2;
if(i == 3)
si[i]=(s1[(2*(*(j+0+(2*(i-1)))))+(*(j+3+(2*(i-1))))][(2*(*(j+1+(2*(i-1)))))+(*(j+2+(2*(i-1))))])%2;
}
/*for(i=0;i<4;i++)
printf("%d\t",si[i]);
printf("\n");*/
for(i=0;i<4;i++)
p4[i]=si[(p4t[i]-1)];
/*for(i=0;i<4;i++)
printf("%d",p4[i]);
printf("\n");*/
j=exor(p4,q);
for(i=0;i<8;i++){
if(i<4)
ip[i]=s[i];
if(i>3)
ip[i]=*(j+i-4);
}
printf("Swapped Plaintext after 1 round: \n");
for(i=0;i<8;i++)
printf("%d",ip[i]);
printf("\n");
}
void e2(){
for(i=0;i<8;i++){
//ip[i]=p[(ipt[i]-1)];
if(i>3)
s[i-4]=ip[i];
if(i<4)
q[i]=ip[i];
}
for(i=0;i<8;i++)
ep[i]=s[(ept[i]-1)];
/*for(i=0;i<8;i++)
printf("%d\t",ep[i]);
printf("\n");*/
j=exor(ep,k2);
/*for(i=0;i<8;i++)
printf("%d\t",*(j+i));
printf("\n");*/
for(i=0;i<4;i=i+2){
si[i]=(s0[(2*(*(j+0+(2*i))))+(*(j+3+(2*i)))][(2*(*(j+1+(2*i))))+(*(j+2+(2*i)))])/2;
if(i == 2)
si[i]=(s1[(2*(*(j+0+(2*i))))+(*(j+3+(2*i)))][(2*(*(j+1+(2*i))))+(*(j+2+(2*i)))])/2;
//printf("%d\t%d\t%d\n",(2*(*(j+0+(2*i))))+(*(j+3+(2*i))),(2*(*(j+1+(2*i))))+(*(j+2+(2*i))),s0[(2*(*(j+0+(2*i))))+(*(j+3+(2*i)))][(2*(*(j+1+(2*i))))+(*(j+2+(2*i)))]);
}
for(i=1;i<4;i=i+2){
si[i]=(s0[(2*(*(j+0+(2*(i-1)))))+(*(j+3+(2*(i-1))))][(2*(*(j+1+(2*(i-1)))))+(*(j+2+(2*(i-1))))])%2;
if(i == 3)
si[i]=(s1[(2*(*(j+0+(2*(i-1)))))+(*(j+3+(2*(i-1))))][(2*(*(j+1+(2*(i-1)))))+(*(j+2+(2*(i-1))))])%2;
}
/*for(i=0;i<4;i++)
printf("%d\t",si[i]);
printf("\n");*/
for(i=0;i<4;i++)
p4[i]=si[(p4t[i]-1)];
/*for(i=0;i<4;i++)
printf("%d",p4[i]);
printf("\n");*/
j=exor(p4,q);
for(i=0;i<8;i++){
if(i>3)
ip[i]=s[i-4];
if(i<4)
ip[i]=*(j+i);
}
printf("Plaintext after 2 round: \n");
for(i=0;i<8;i++)
printf("%d",ip[i]);
printf("\n");
for(i=0;i<8;i++)
ipi[i]=ip[(ipit[i]-1)];
printf("Ciphertext: \n");
for(i=0;i<8;i++)
printf("%d",ipi[i]);
printf("\n");
}
