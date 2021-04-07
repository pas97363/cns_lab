#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char pt[50];
int p[50],key[10][10],c[50],i,j,k,temp,len,s;
void main(){
printf("Enter the Plaintext: \n");
gets(pt);
for(i=0;pt[i]!='\0';i++)
p[i]=pt[i]%97;
printf("Enter the size of the key matrix: \n");
scanf("%d",&s);
printf("Enter the key matrix: \n");
for(i=0;i<s;i++)
for(j=0;j<s;j++)
scanf("%d",&key[i][j]);
len=0;
for(i=0;pt[i]!='\0';i++)
len++;
encr();
//decr();
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
