void converter(int A,int B,int C,int f){
  int d;
  if(f>=0){
    d=f%8;}
  else{
       while(f<0){
         f=f+8;}
     d=f%8;}
  
if(d==0){
digitalWrite(A, 0);
digitalWrite(B, 0);
digitalWrite(C, 0);
}
if(d==1){
digitalWrite(A, 1);
digitalWrite(B, 0);
digitalWrite(C, 0);
}
if(d==2){
digitalWrite(A, 0);
digitalWrite(B, 1);
digitalWrite(C, 0);
}
if(d==3){
digitalWrite(A, 1);
digitalWrite(B, 1);
digitalWrite(C, 0);
}
if(d==4){
digitalWrite(A, 0);
digitalWrite(B, 0);
digitalWrite(C, 1);
}
if(d==5){
digitalWrite(A, 1);
digitalWrite(B, 0);
digitalWrite(C, 1);
}
if(d==6){
digitalWrite(A, 0);
digitalWrite(B, 1);
digitalWrite(C, 1);
}
if(d==7){
digitalWrite(A, 1);
digitalWrite(B, 1);
digitalWrite(C, 1);
}
else{}

}
int c=0,x=4,y=4,d=1,l=3,j=1;
int body[5][2];
int h[2][2];
int f,g;
//-------- Void Setup -------------
void setup(){ 
int a;
for(a=0;a<8;a++){
 pinMode(a,INPUT);
}
for(a=8;a<14;a++){
 pinMode(a,OUTPUT);
}
attachInterrupt(0, button1 , FALLING);
attachInterrupt(1, button2 , FALLING);

converter(8,9,10,4);
converter(11,12,13,4);
body[0][0]=x;
body[0][1]=y;
body[1][0]=x-1;
body[1][1]=y;
body[2][0]=x-2;
body[2][1]=y;
}
//-------- Void Loop -------------
void loop(){
 if(c==1){
   d=1;
   x--;
 }
 if(c==2){
     d=2;
       x++;       
 }
 if(c==3){
   d=3;
   y--;
 }
 if(c==4){
   d=4;
  y++;   
 }
 //MEMORY 
 h[0][0]=body[1][0];
 h[0][1]=body[1][1];
 body[1][0]=body[0][0];
 body[1][1]=body[0][1];
 h[1][0]=body[2][0];
 h[1][1]=body[2][1];
 body[2][0]=h[0][0];
 body[2][1]=h[0][1];
 if(l%2==1){
   int i; 
        for(i=3;i<l;i=i+2){
          h[0][0]=body[i][0];
          h[0][1]=body[i][1];
          body[i][0]=h[1][0];
          body[i][1]=h[1][1];
          h[1][0]=body[i+1][0];
          h[1][1]=body[i+1][1];
          body[i+1][0]=h[0][0];
          body[i+1][1]=h[0][1];
        }
 }
 else{
   int i; 
        for(i=3;i<l-1;i=i+2){
          h[0][0]=body[i][0];
          h[0][1]=body[i][1];
          body[i][0]=h[1][0];
          body[i][1]=h[1][1];
          h[1][0]=body[i+1][0];
          h[1][1]=body[i+1][1];
          body[i+1][0]=h[0][0];
          body[i+1][1]=h[0][1];
        }
        h[0][0]=body[l-1][0];
          h[0][1]=body[l-1][1];
          body[l-1][0]=h[1][0];
          body[l-1][1]=h[1][1];
 }
  body[0][0]=x;
  body[0][1]=y;
  if(j==1){
    body[0][0]=x;
body[0][1]=y;
body[1][0]=x-1;
body[1][1]=y;
body[2][0]=x-2;
body[2][1]=y;
j++;}
  //DISPLAY
  for(f=0;f<30;f++){
    for(g=l;g<=l;g++){
  converter(8,9,10,body[g-1][1]);
  converter(11,12,13,body[g-1][0]);
  delay(1/l);
    }
  }
}
//----Interrupt Functions-------
void button1(){
  if(d==1||d==2){
    l++;
    c=3;}
   else if(d==3||d==4){
     l++;
    c=2;}
}
void button2(){
if(d==1||d==2){
    c=4;
    }
   else if(d==3||d==4){
    c=1;}
}
