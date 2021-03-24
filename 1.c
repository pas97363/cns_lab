#include <stdio.h>
#include <string.h>
int key;
char pt[10],ct[10],temp[10];
int main(){
printf("Enter the text:\n");
gets(pt);
printf("Enter the key:\n");
scanf("%d",&key);
encr();
decr();
}
void encr(){
for(int i=0;pt[i]!='\0';i++){
temp[i]=pt[i];
if(pt[i]<='z' && pt[i]>='a'){
temp[i]=temp[i]+key;
if(temp[i]>'z')
temp[i]=temp[i]-26;
}
ct[i]=temp[i]-32;
}
printf("Cipher text: %s\n",ct);
}
void decr(){
for(int i=0;ct[i]!='\0';i++){
temp[i]=ct[i];
if(ct[i]<='Z' && ct[i]>='A'){
temp[i]=temp[i]-key;
if(temp[i]<'A')
temp[i]=temp[i]+26;
}
temp[i]=temp[i]+32;
}
printf("Plain text: %s\n",temp);
}
