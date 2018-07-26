  #include <Servo.h>
  int ir1 = 7;
  int buz = 8;
  int led1 = 6;
  int speaker = 11;
  int flag1 = 0;

 
Servo myservo;
int pos = 0; 
int state=0;
int flag=0;

void setup() {
  pinMode(ir1,INPUT);
  pinMode(buz,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(speaker, OUTPUT);

  myservo.attach(9);

  Serial.begin(9600);
}

void loop() {
 delayMicroseconds(1000);

  if(digitalRead(ir1) == HIGH)
  {
    while((digitalRead(ir1) == HIGH) && (flag <=3))
    {
      flag1++;
      delay(1000);
      
      if(flag1 == 3)
      break;
    }
    if(flag1 == 3)
    {
      digitalWrite(speaker, HIGH);
      delay(2000);
      digitalWrite(speaker, LOW);
      delay(1000);

      digitalWrite(led1, HIGH);
 
      digitalWrite(buz,HIGH);
      delay(1100);
      digitalWrite(buz, LOW);
      delay(1100);
      digitalWrite(buz,HIGH);
      delay(1100);
      digitalWrite(buz, LOW);
      digitalWrite(led1, LOW);
      //.............................................................

      //............................................
      flag1 = 0;
    }
    }
    else
    {
      flag1 = 0;
    }

    if(Serial.available()>0)
      {
  {
    delay(400);
    state=Serial.read();
    flag=0;
  }
      if(state=='0')
      {
             myservo.write(0);              
            
            
            if(flag==0)
            {
              Serial.println("off");
              flag=1;
            }
      }
      else if(state=='1')
      {          
            myservo.write(90);              

            if(flag==0)
            {
              Serial.println("on");flag=1;
            }
        }
  }
}
