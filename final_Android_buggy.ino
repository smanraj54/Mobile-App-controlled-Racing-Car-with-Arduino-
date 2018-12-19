int x=255/2 ;
int slow=255/3 ;
int high=255 ;
int mid =255/2 ;
int d=0 ;
int s=0 ;
boolean turn=true;
void setup() {
Serial.begin(9600);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
}

void loop() 
{
  int y=0;
  for(int t=0;t<3;t++){
     if(Serial.available()>0){
    s=Serial.read();
    Serial.println(s);
    s=s-48;
    y=(pow(10,(2-t)))*s+y;    }
    else{t--;}
    }
    y=y+1;
  if(y==102){d=1;}
  else if(y==101){d=0;}
  else if(y==103){d=2;}
  else if(y==104){d=3;}
  else if(y==105){d=4;}
  else if(y==106){d=0;}
  else if(y==107){x=mid;}
  else if(y==108){x=slow;}
  else if(y==109){x=high;}
  else if(y==110){if(x<=245){x=x+10;}}
  else if(y==111){if(x>=10){x=x-10;}}
  else if(y==112){turn=true;}
  else if(y==113){turn=false;}
  
  if(d==0){STOP();}
  else if(d==1){Aforw(x);}
  else if(d==2){Aback(x);}
  else if(d==3){if(turn){Aleft(x);}else{SAleft(x);}}
  else if(d==4){if(turn){Aright(x);}else{SAright(x);}}  
}



void Aforw(int x)
{
  analogWrite(5,x);
  analogWrite(6,0);
  analogWrite(9,x);
  analogWrite(10,0);
  }void Aback(int x)
{
  analogWrite(5,0);
  analogWrite(6,x);
  analogWrite(9,0);
  analogWrite(10,x);
  }void Aright(int x)
{
  analogWrite(5,x);
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(10,x);
  }void Aleft(int x)
{
  analogWrite(5,0);
  analogWrite(6,x);
  analogWrite(9,x);
  analogWrite(10,0);
  }void SAright(int x)
{
  analogWrite(5,x);
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(10,0);
  }void SAleft(int x)
{
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,x);
  analogWrite(10,0);
  }void STOP()
{
  analogWrite(5,0);
  analogWrite(6,0);
  analogWrite(9,0);
  analogWrite(10,0);
  }

