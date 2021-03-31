#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char pt[50];
int p[50],key[2][2],c[50],i,j,k,temp,len;
void main(){
printf("Enter the Plaintext: \n");
gets(pt);
for(i=0;pt[i]!='\0';i++)
p[i]=(pt[i]-97);
printf("Enter the key matrix: \n");
for(i=0;i<2;i++)
for(j=0;j<2;j++)
scanf("%d",&key[i][j]);
len=0;
for(i=0;pt[i]!='\0';i++)
len++;
len=len/2;
encr();
//decr();
}
void encr(){
k=0;
while(p[k]!='\0'){
for(i=0;i<len && (i+k)<len*2;i++){
for(j=0;j<2;j++){
c[i+k]=(((p[k]*key[0][i%2])+(p[k+1]*key[1][i%2]))%26)+65;
//c[i+k+1]=(((p[k]*key[0][i%2+1])+(p[k+1]*key[1][i%2+1]))%26)+65;
//printf("c[%d]=%d %d %d\n",(i+k),c[i+k]-65,i,k);
//printf("c[%d]=%d\n",(i+k+1),c[i+k+1]-65);

}
}
k+=2;
}
printf("Ciphertext: \n");
for(i=0;c[i]!='\0';i++)
printf("%c",c[i]);
printf("\n");
}
