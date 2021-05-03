#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char pt[50];
int p[50],c0[50][50],c1[50][7],t0[50][50],t1[50],i,j,k,key[7],cho,len,mid,ro,re,temp[500],temp0[500],depth,ro0,re0;
void main(){
printf("Enter the Plaintext: \n");
gets(pt);
for(i=0,j=0;pt[i]!='\0';i++)
if(97 <= pt[i] && pt[i] <= 122){
p[j]=pt[i];
j++;
}
len=0,mid=0,cho=9;
for(i=0;pt[i]!='\0';i++){
len++;
if(pt[i] == 32)
len-=1;
}
//printf("%d\n",len);
if(len%2)
mid=len/2+1;
else
mid=len/2;
while(cho){
printf("Enter 1 for RailFence \n");
printf("Enter 2 for Row Transposition \n");
scanf("%d",&cho);
switch(cho){
case 1: printf("Enter the depth: \n");
	scanf("%d",&depth);
	ro0=len/depth+1;
	//printf("%d\n",ro0);
	rencr();
	rdecr();
	break;
case 2: printf("Enter the key: \n");
	for(i=0;i<7;i++)
	scanf("%d",&key[i]);
	tencr();
	break;
}
printf("Enter 9 for Repeat else 0 to End \n");
scanf("%d",&cho);
}
//printf("%d\n",mid);
//decr();
}
void rencr(){
/*for(i=0,k=0;k<mid;i=i+2,k++){
c0[k]=p[i]-32;
//printf("c0[%d]=%d %c \n",k,p[i]-32,p[i]);
}
for(j=1,k=mid;k<len;j=j+2,k++){
c0[k]=p[j]-32;
//printf("c0[%d]=%d %c \n",k,p[j]-32,p[j]);
}*/
for(i=0;i<ro0;i++)
for(j=0;j<depth;j++){
c0[i][j]=p[j+(i*depth)]-32;
//printf("%d %c\n",c0[i][j],c0[i][j]);
if(65 <= c0[i][j]){
temp[(j*ro0)+i]=c0[i][j];
//printf("%d %c %d\n",temp[(j*ro0)+i],temp[(j*ro0)+i],(j*ro0)+i);
}
}
printf("Ciphertext: \n");
for(i=0;i<len;i++){
printf("%c",temp[i]);
}
printf("\n");
}
void rdecr(){
/*for(i=0,k=0;k<mid;i=i+2,k++){
t0[i]=c0[k]+32;
//printf("t0[%d]=%d %c \n",i,c0[k]+32,c0[k]);
}
for(j=1,k=mid;k<len;j=j+2,k++){
t0[j]=c0[k]+32;
//printf("t0[%d]=%d %c \n",j,c0[k]+32,c0[k]);
}*/
for(i=0;i<ro0;i++)
for(j=0;j<depth;j++){
t0[i][j]=temp[(j*ro0)+i]+32;
//printf("%d %c\n",c0[i][j],c0[i][j]);
if(97 <= t0[i][j]){
temp0[j+(i*depth)]=t0[i][j];
//printf("%d %c %d\n",temp0[j+(i*depth)],temp0[j+(i*depth)],j+(i*depth));
}
}
printf("Plaintext: \n");
for(i=0;i<len;i++)
printf("%c",temp0[i]);
printf("\n");
}













void tencr(){
ro=len/7+1;
re=len%7;
for(j=0;j<ro;j++)
for(i=0;i<7;i++)
c1[j][i]=p[i+(j*7)]-32;
for(i=6,j=90;i>re-1;i--,j--)
c1[ro-1][i]=j;
/*for(j=0;j<ro;j++){
for(i=0;i<7;i++){
printf("%c\t",c1[j][i]);
}
printf("\n");
}*/
for(i=0;i<7;i++)
for(j=0;j<ro;j++){
temp[j+((key[i]-1)*5)]=c1[j][i];
}
/*for(k=0;k<len;k++)
printf("%c",temp[k]);
printf("\n");*/
for(j=0;j<ro;j++)
for(i=0;i<7;i++)
c1[j][i]=temp[i+(j*7)];
for(i=0;i<7;i++)
for(j=0;j<ro;j++){
temp[j+((key[i]-1)*5)]=c1[j][i];
}
for(j=0;j<ro;j++)
for(i=0;i<7;i++)
c1[j][i]=temp[i+(j*7)];
printf("Ciphertext: \n");
for(k=0;k<7*ro;k++)
printf("%c",temp[k]);
printf("\n");
for(j=0;j<ro;j++){
for(i=0;i<7;i++){
printf("%c\t",c1[j][i]);
}
printf("\n");
}
}
/*void tdecr(){
for(j=0;j<ro;j++)
for(i=0;i<7;i++)
}
*/
