#include<Servo.h>
Servo servo;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     int trig = 8;
int echo =9 ;
int IN1 =2 ;
int IN2 =3 ;
int IN3 = 4;
int IN4 = 5;
int duration;
int distance;
int pos = 90;
int stopdistance = 30;
int maxdistance = 500;
//int distance [2] = {0,0};


void setup() {
  // put your setup code here, to run once:
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  servo.attach(6);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(90);
  delay(500);
  int distance = Distance();
 // if (distance >= stopdistance){
   
    //Serial.printLn(distance);
    while (distance>= stopdistance){
      //distance = Distance();
      //delay(200)
      forward();
      delay(500);
      if (distance < stopdistance){
        stopped();
        delay(500);
         if(distance[0]){
          Backward();
         }
         else if (distance[0]>=distance[1]){
            left();
          }
           else (distance[0]<=distance[1]){
            right();
          }
          
        } 
      
      }
      else {stopped();
      }
     
//}
  

}
int Distance(){
    digitalWrite(trig.HIGH);
    delay(10);
    digitalWrite(trig,LOW);
    delay(2);
    duration = pulseIn(echo,HIGH);
    distance = (duration*0.034)/2;
    Serial.println(distance);
  }

  int checkdir(){
      int turndir = 1;
      servo.write(180);
      delay(500);
      distance[0]= Distance();
      servo.write(0);
      delay(500);
      distance[1] = Distance();
      servo.write(0);  
    }

   void forward(){
       digitalWrite(IN1,HIGH);
       digitalWrite(IN3,HIGH);
       
    }
    void Backward(){
       digitalWrite(IN2,HIGH);
       digitalWrite(IN4,HIGH);
      }
      void stopped(){
       digitalWrite(IN1,LOW);
       digitalWrite(IN3,LOW);
       digitalWrite(IN2,LOW);
       digitalWrite(IN4,LOW); 
          
        }
        void left(){
              digitalWrite(IN3,HIGH);
            
          }
          void right(){
              digitalWrite(IN1,HIGH);
            
          }
          
