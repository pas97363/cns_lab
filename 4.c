#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int p[50],c[50],t[50],ke[50],i,j,temp,len,len0;
char pt[50],key[50];
void main(){
printf("Enter the plaintext:\n");
gets(pt);
for(i=0,j=0;pt[i]!='\0';i++)
if(97 <= pt[i] && pt[i] <= 122){
p[j]=pt[i]%97;
j++;
}
len=0;
for(i=0;pt[i]!='\0';i++){
len++;
if(pt[i] == 32)
len=len-1;
}
printf("Enter the key:\n");
gets(key);
len0=0;
for(i=0;key[i]!='\0';i++)
len0++;
for(i=0;i<len;i++)
ke[i]=key[i%len0]%97;
encr();
decr();
}
void encr(){
for(i=0;i<len;i++)
c[i]=((p[i]+ke[i])%26)+65;
printf("Ciphertext: \n");
for(i=0;i<len;i++)
printf("%c",c[i]);
printf("\n");
}
void decr(){
for(i=0;i<len;i++){
temp=c[i]-65-ke[i];
if(temp<0)
t[i]=temp+123;
else
t[i]=temp+97;
}
printf("Plaintext: \n");
for(i=0;i<len;i++)
printf("%c",t[i]);
printf("\n");
}
