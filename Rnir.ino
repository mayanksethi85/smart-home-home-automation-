int ir1=8;
int ir2=7;
int led=3;
int count=0;

void setup() {
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:
}
void loop() {

 if(digitalRead(ir1)==HIGH)
  {  
     while(digitalRead(ir2)==LOW)
    {
      if(digitalRead(ir2)==HIGH)
      {
        //count=count+1;
      break;
      }
   }
   count=count+1;
    //Serial.print("total no. of people inside  =");
    //Serial.print(count);
    //Serial.println();
    Serial.println("ir 1 se ir 2");
      digitalWrite(led,HIGH);
  }
 else if(digitalRead(ir2)==HIGH)
  {    
     while(digitalRead(ir1)==LOW)
    {
      if(digitalRead(ir1)==HIGH)
      {
        count=count-1;
      break;
      }
   }
     //  Serial.print("total no. of people inside  =");
    //Serial.print(count);
    //Serial.println();
      
      digitalWrite(led,LOW);
  }

  // put your main code here, to run repeatedly:

}
