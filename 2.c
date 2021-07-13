#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char pt[500],key[500],ct[500];
int m[5][5],p[500],q[500],temp[50],a,c[500],b[500],i,j,k,flag,alph[26],bet[26],r1,r2,c1,c2,cho,choice;
void main(){
printf("Enter the Plaintext: \n");
gets(pt);
printf("Enter the Key: \n");
gets(key);
/*for(i=0;pt[i]!='\0';i++)
q[i]=pt[i];*/
for(i=0,j=0;pt[i]!='\0';i++){
if(97 <= pt[i] && pt[i] <= 122){
q[j]=pt[i];
j++;
}
}
for(int i=0;key[i]!='\0';i++)
p[i]=key[i];
printf("Enter 1 for i and 2 for j\n");
scanf("%d",&cho);
switch(cho){
case 1 : choice=106;
	 break;
case 2 : choice=105;
	 break;
}
matr();
encr();
/*printf("Enter the Ciphertext: \n");
gets();
gets(ct);
for(i=0;ct[i]!='\0';i++)
c[i]=ct[i];*/
decr();
}
void matr(){
i=0,j=0;
while(p[i]!='\0'){
for(k=0;temp[k]!='\0';k++){
if(p[i] == temp[k]){
flag=1;
}
}
if(flag == 0){
temp[j]=p[i];
j++,i++;
}
if(flag == 1){
flag=0;
i++;
}
}
int len=0;
for(k=0;temp[k]!='\0';k++)
len++;
for(k=0;k<26;k++)
alph[k]=k+97;
i=0,j=0;
while(alph[i]!='\0'){
if(alph[i] == choice)
i++;
else{
for(k=0;temp[k]!='\0';k++){
if(alph[i] == temp[k]){
flag=1;
}
}
if(flag == 0){
bet[j]=alph[i];
j++,i++;
}
if(flag == 1){
flag=0;
i++;
}
}
}
for(k=0;temp[k]!='\0';k++)
m[k/5][k%5]=temp[k];
for(k=0;bet[k]!='\0';k++)
m[(len+k)/5][(len+k)%5]=bet[k];
printf("The playfair matrix: \n");
for(i=0;i<5;i++){
for(j=0;j<5;j++){
printf("%c\t",m[i][j]-32);
}
printf("\n");
}
}
void encr(){
int len1=0;
for(j=0;q[j]!='\0';j++)
len1++;
for(i=0;q[i]!='\0';i+=2){
if(q[i] == q[i+1]){
for(j=len1+1;j>i;j--)
q[j+1]=q[j];
q[i+1]=120;
len1++;
}
if(q[i+1] == '\0'){
q[i+2]='\0';
q[i+1]=120;
}
}
printf("Corrected Plaintext: \n");
for(i=0;q[i]!='\0';i++)
printf("%c",q[i]);
printf("\n");
for(k=0;q[k]!='\0';k+=2){
//if(q[k+1]!='\0'){
r1=rowchec(q[k]);
r2=rowchec(q[k+1]);
c1=colchec(q[k]);
c2=colchec(q[k+1]);
if(r1 == r2){
if(c1 >= 4)
c1=c1-5;
c[k]=m[r1][c1+1];
if(c2 >= 4)
c2=c2-5;
c[k+1]=m[r2][c2+1];
}
else if(c1 == c2){
if(r1 >= 4)
r1=r1-5;
c[k]=m[r1+1][c1];
if(r2 >= 4)
r2=c2-5;
c[k+1]=m[r2+1][c2];
}
else{
c[k]=m[r1][c2];
c[k+1]=m[r2][c1];
}
//}
/*else{
c[k]=q[k];
printf("ran else\n");
}*/
}
printf("Ciphertext: \n");
for(i=0;c[i]!='\0';i++){
printf("%c",c[i]-32);
}
printf("\n");
}
int rowchec(int ke){
for(i=0;i<5;i++)
for(j=0;j<5;j++)
if(m[i][j] == ke)
return i;
}
int colchec(int ke){
for(i=0;i<5;i++)
for(j=0;j<5;j++)
if(m[i][j] == ke)
return j;
}
void decr(){
for(k=0;c[k]!='\0';k+=2){
r1=rowchec(c[k]);
r2=rowchec(c[k+1]);
c1=colchec(c[k]);
c2=colchec(c[k+1]);
if(r1 == r2){
if(c1 <= 0)
c1=c1+5;
b[k]=m[r1][c1-1];
if(c2 <= 0)
c2=c2+5;
b[k+1]=m[r2][c2-1];
}
else if(c1 == c2){
if(r1 <= 0)
r1=r1+5;
b[k]=m[r1-1][c1];
if(r2 <= 0)
r2=c2+5;
b[k+1]=m[r2-1][c2];
}
else{
b[k]=m[r1][c2];
b[k+1]=m[r2][c1];
}
}
printf("Plaintext: \n");
for(i=0;b[i]!='\0';i++)
printf("%c",b[i]);
printf("\n");
}

