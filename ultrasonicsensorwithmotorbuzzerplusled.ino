                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
int echo = 12;
int duration;
int distance;
int relay = 5;
int trig = 11;
int Buzzer = 6;
int LED = 4;



void setup() {
  // put your setup code here, to run once:
  pinMode(trig,OUTPUT);
  pinMode(relay,OUTPUT);
  pinMode(Buzzer,OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(echo,INPUT);
 
  
   
   Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,HIGH);
  delay(2);
  digitalWrite(trig,LOW);
  duration = pulseIn(echo,HIGH);
  distance = (duration * 0.034)/2;
  Serial.println("Distance =");
  Serial.println(distance);
  delay(50);
  if (distance<=20){
    digitalWrite(relay,LOW);
    digitalWrite(Buzzer,HIGH);
     delay(500);
    digitalWrite(LED,HIGH);
    delay(500);
    
      
    }
  else{
     digitalWrite(relay,HIGH);
     digitalWrite(Buzzer,LOW);
     digitalWrite(LED,LOW);
     
    }
 //return distance;

}
