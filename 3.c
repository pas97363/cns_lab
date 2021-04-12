#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char pt[50];
int p[50],key[10][10],c[50],t[50],i,j,k,temp,len,s,inv[26],det;
void main(){
printf("Enter the Plaintext: \n");
gets(pt);
for(i=0,j=0;pt[i]!='\0';i++){
if(97 <= pt[i] && pt[i] <= 122){
p[j]=pt[i]%97;
j++;
}
}
len=0;
for(i=0;pt[i]!='\0';i++){
len++;
if(pt[i] == 32)
len=len-1;
}
printf("Enter the size of the key matrix: \n");
scanf("%d",&s);
printf("Enter the key matrix: \n");
for(i=0;i<s;i++)
for(j=0;j<s;j++)
scanf("%d",&key[i][j]);
encr();
decr();
}
void encr(){
k=0;
while(k<len){
for(j=0;j<s;j++){
for(i=k;i<(k+s);i++){
//c[k+j]=(((p[k]*key[k%2][j])+(p[k+1]*key[(k+1)%2][j])));
c[k+j]+=(p[i]*key[i%s][j]);
//printf("%d=%d*%d  \n",p[i]*key[i%s][j],p[i],key[i%s][j]);
//printf("c[%d]=%d %d \n",(k+j),c[k+j],k);
}
c[k+j]=(c[k+j]%26)+65;
}
k+=s;
}
printf("Ciphertext: \n");
for(i=0;c[i]!='\0';i++)
printf("%c",c[i]);
printf("\n");
}
void decr(){
det=0;
for(i=0;i<len;i++)
c[i]=c[i]%65;
int a[s][s],m[s][s];
for(k=1;k<26;k++)
for(i=1;i<26;i++)
for(j=-25;j<26;j++){
if(((26*i)+(k*j)) == 1)
inv[k]=j+26;
//printf("%d %d %d\n",k,i,j+26);
}
for(i=0;i<s;i++){
for(j=0;j<s;j++){
m[j][i]=(key[(i+1)%s][(j+1)%s]*key[(i+2)%s][(j+2)%s])-(key[(i+1)%s][(j+2)%s]*key[(i+2)%s][(j+1)%s]);
}
}
for(i=0;i<s;i++)
det+=m[i][0]*key[0][i];
det=det%26;
if(det<0)
det+=26;
det=inv[det];
printf("Det inverse: %d\n",det);
for(i=0;i<s;i++)
for(j=0;j<s;j++){
m[i][j]=(det*m[i][j])%26;
if(m[i][j]<0)
m[i][j]+=26;
}
printf("Inverse key matrix:\n");
for(i=0;i<s;i++){
for(j=0;j<s;j++)
printf("%d\t",m[i][j]);
printf("\n");
}
k=0;
while(k<len){
for(j=0;j<s;j++){
for(i=k;i<(k+s);i++){
//c[k+j]=(((p[k]*key[k%2][j])+(p[k+1]*key[(k+1)%2][j])));
t[k+j]+=(c[i]*m[i%s][j]);
//printf("%d=%d*%d  \n",p[i]*key[i%s][j],p[i],key[i%s][j]);
//printf("c[%d]=%d %d \n",(k+j),c[k+j],k);
}
t[k+j]=(t[k+j]%26)+97;
}
k+=s;
}
printf("Plaintext: \n");
for(i=0;t[i]!='\0';i++)
printf("%c",t[i]);
printf("\n");
}
