#include <stdio.h>
#include <string.h>
int key;
char pt[100];
int p[100],c[100],tem[100];
int main(){
printf("Enter the text:\n");
gets(pt);
printf("Enter the key:\n");
scanf("%d",&key);
for(int i=0;pt[i]!='\0';i++)
p[i]=pt[i];
encr();
decr();
}
void encr(){
for(int i=0;p[i]!='\0';i++){
tem[i]=p[i];
if(p[i]<=122 && p[i]>=97){
tem[i]=tem[i]+key;
if(tem[i]>122)
tem[i]=tem[i]-26;
c[i]=tem[i]-32;
}
else 
c[i]=tem[i];
}
printf("Cipher text: \n");
for(int i=0;c[i]!='\0';i++)
printf("%c",c[i]);
}
void decr(){
for(int i=0;c[i]!='\0';i++){
tem[i]=c[i];
if(c[i]<=90 && c[i]>=65){
tem[i]=tem[i]-key;
if(tem[i]<65)
tem[i]=tem[i]+26;
tem[i]=tem[i]+32;
}
}
printf("\nPlain text: \n");
for(int i=0;tem[i]!='\0';i++)
printf("%c",tem[i]);
printf("\n");
}
