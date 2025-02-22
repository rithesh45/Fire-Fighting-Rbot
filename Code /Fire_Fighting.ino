#define enA 10//Enable1 L298 Pin enA 
#define in1 9 //Motor1  L298 Pin in1 
#define in2 8 //Motor1  L298 Pin in2 
#define in3 7 //Motor2  L298 Pin in3 
#define in4 6 //Motor2  L298 Pin in4 
#define enB 5 //Enable2 L298 Pin enB 
#define ir_R A0    
#define ir_F A1  
#define ir_L A2  
#define servo A4
#define pump 11 
int Speed = 160;
int pumpSpeed = 255;
int s1, s2, s3; 
void setup(){ // put your setup code here, to run once
Serial.begin(9600); // start serial communication at 9600bps
pinMode(ir_R, INPUT);// declare fire sensor pin as input
pinMode(ir_F, INPUT);// declare fire sensor pin as input
pinMode(ir_L, INPUT);// declare fire sensor pin as input
pinMode(enA, OUTPUT); // declare as output for L298 Pin enA 
pinMode(in1, OUTPUT); // declare as output for L298 Pin in1 
pinMode(in2, OUTPUT); // declare as output for L298 Pin in2 
pinMode(in3, OUTPUT); // declare as output for L298 Pin in3   
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4 
pinMode(enB, OUTPUT); // declare as output for L298 Pin enB 
pinMode(servo, OUTPUT);
pinMode(pump, OUTPUT); 
for (int angle = 90; angle <= 140; angle += 5)  {
   servoPulse(servo, angle);  }
for (int angle = 140; angle >= 40; angle -= 5)  {
   servoPulse(servo, angle);  }
for (int angle = 40; angle <= 95; angle += 5)  {
   servoPulse(servo, angle);  }
analogWrite(enA, Speed); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed 
analogWrite(enB, Speed); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed 
   
delay(500);
}
void loop(){  
s1 = analogRead(ir_R);
s2 = analogRead(ir_F);
s3 = analogRead(ir_L);

Serial.print(s1);
Serial.print("\t");
Serial.print(s2);
Serial.print("\t");
Serial.println(s3);
delay(50);
if(s1<100){
turnRight();
delay(500);
analogrite(pump, pumpSpeed);
for(int angle = 90; angle >= 40; angle -= 3){
servoPulse(servo, angle);  
}
for(int angle = 40; angle <= 90; angle += 3){
servoPulse(servo, angle);  
delay(4000);
analogwrite(pump,o);
}
}
else if(s2<100){
forword();
delay(1000);
analogWrite(pump, pumpSpeed);
for(int angle = 90; angle <= 140; angle += 3){
servoPulse(servo, angle);  
}
for(int angle = 140; angle >= 40; angle -= 3){
servoPulse(servo, angle);    
}
for(int angle = 40; angle <= 90; angle += 3){
servoPulse(servo, angle);
delay(4000);
analogwrite(pump,o);  
 }  
}
else if(s3<100){
turnLeft();
delay(500);
analogWrite(pump, pumpSpeed);
for(int angle = 90; angle <= 140; angle += 3){
servoPulse(servo, angle);  
}
for(int angle = 140; angle >= 90; angle -= 3){
servoPulse(servo, angle);  
delay(4000);
analogwrite(pump,0);
} 
}
else if(s1>=250 && s1<=700){
digitalWrite(pump, 0);
backword();
delay(100); 
turnRight();
delay(200); 
}
else if(s2>=250 && s2<=800){
digitalWrite(pump, 0);
forword(); 
}
else if(s3>=250 && s3<=700){
digitalWrite(pump, 0);
backword();
delay(100); 
turnLeft();
delay(200); 
}else{
digitalWrite(pump, 0);
Stop();
}
delay(10);
}
void servoPulse (int pin, int angle){
int pwm = (angle*11) + 500;      
 digitalWrite(pin, HIGH);
 delayMicroseconds(pwm);
 digitalWrite(pin, LOW);
 delay(50);                   
}
void forword(){ //forword
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}
void backword(){ //backword
digitalWrite(in1, HIGH); //Right Motor forword Pin
digitalWrite(in2, LOW); //Right Motor backword Pin
digitalWrite(in3, LOW); //Left Motor backword Pin
digitalWrite(in4, HIGH); //Left Motor forword Pin
}
void turnRight(){ //turnRight
digitalWrite(in1, HIGH); //Right Motor forword Pin
digitalWrite(in2, LOW); //Right Motor backword Pin
digitalWrite(in3, HIGH); //Left Motor backword Pin
digitalWrite(in4, LOW); //Left Motor forword Pin
}
void turnLeft(){ //turnLeft
digitalWrite(in1, LOW); //Right Motor forword Pin
digitalWrite(in2, HIGH); //Right Motor backword Pin
digitalWrite(in3, LOW); //Left Motor backword Pin
digitalWrite(in4, HIGH); //Left Motor forword Pin
}
void Stop(){ //stop
digitalWrite(in1, LOW); //Right Motor forword Pin
digitalWrite(in2, LOW); //Right Motor backword Pin
digitalWrite(in3, LOW); //Left Motor backword Pin
digitalWrite(in4, LOW); //Left Motor forword Pin

