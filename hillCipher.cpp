
//*********************************************

// This is the hill climb implementation

// This program takes  2 X 2 matrix key , converts the plain_text into upper case

//*********************************************

#include<iostream>
#include<string.h>

using namespace std;

int main(){
	
	int key[2][2]={0},inverse[2][2]={0},i=0,j=0;
	int x=0,y=0,Ex=0,Ey=0,charCount=0;
	char cipher[50],plain_text[50];
	cout<<"Enter Key:\n";
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			cin>>key[i][j];
			
		}
	}
	
	cout<<"\nEnter Plain Text:";
	cin>>plain_text;
	for(i=0;i<strlen(plain_text);i++){
		if(int(plain_text[i])>=97 && int(plain_text[i])<=122){
			plain_text[i]=char(int(plain_text[i])-32);
		}
	}
	cout<<"\nEntered Plain Text : "<<plain_text;
	
	
	inverse[1][1]=key[0][0];
	inverse[0][0]=key[1][1];
	inverse[0][1]=-key[0][1]+26;
	inverse[1][0]=-key[1][0]+26;

	cout<<"\n\nCalulated Inverse Matrix:\n\n";
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			cout<<"\t"<<inverse[i][j];			
		}
		cout<<"\n";
	}
	
	
	cout<<"\n";
	charCount=(strlen(plain_text));
	if((charCount%2)!=0){
		plain_text[charCount]='x';
		charCount+=1;
	}
	
	cout<<"\nEncrypted Message: \t";
	
	for(i=0;i<charCount;i=i+2){
		x=int(plain_text[i])%65;
		y=int(plain_text[i+1])%65;
		Ex=(x*key[0][0]+y*key[1][0])%26;
		Ey=(x*key[0][1]+y*key[1][1])%26;
		Ex=Ex+65;
		Ey=Ey+65;
		cout<<char(Ex)<<char(Ey);
		cipher[i]=char(Ex);
		cipher[i+1]=char(Ey);
	}
	
	
	cout<<"\n\nDecryption Text :\t";
	
	for(i=0;i<charCount;i=i+2){
		x=int(cipher[i])%65;
		y=int(cipher[i+1])%65;
		Ex=(x*inverse[0][0]+y*inverse[1][0])%26;
		Ey=(x*inverse[0][1]+y*inverse[1][1])%26;
		Ex=Ex+65;
		Ey=Ey+65;
		cout<<char(Ex)<<char(Ey);
	}
	
	//"A" = 65
	
}
