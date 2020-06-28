#include<SoftwareSerial.h>

SoftwareSerial bt(0,1); // assigning 0 as RX ans 1 as TX 

#define motor_left 10  //PWM for left motor
#define motor_right 11 //PWM for right motor
#define motor_right_dir 13  //Direction control for right motor
#define motor_left_dir 12  //Direction control for left motor

void setup() {
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
 
 while(!Serial){;} // waiting for serial communication to setup
 bt.begin(9600); // beginning the bluetooth connection
}
void loop() {
 bt.listen(); // listening to the bluetooth
 while(bt.available()) // till we are receiving the input continue in the loop
 {
     char ch = bt.read();  // reading one character at a time
     if(ch=='f'){          // action to be performed if input is 'f'
       digitalWrite(motor_left_dir,HIGH);
       digitalWrite(motor_right_dir,HIGH);
       analogWrite(motor_left,150);
       analogWrite(motor_right,150);
     }
     else if(ch == 'b'){       // action to be performed if input is 'b'
       digitalWrite(motor_left_dir,LOW);
       digitalWrite(motor_right_dir,LOW);
       analogWrite(motor_left,150);
       analogWrite(motor_right,150);
     }
     else if(ch == 'l'){       // action to be performed if input is 'l'
       digitalWrite(motor_left_dir,HIGH);
       digitalWrite(motor_right_dir,HIGH);
       analogWrite(motor_left,0);
       analogWrite(motor_right,120);
     }
     else if(ch == 'r'){     // action to be performed if input is 'r'
       digitalWrite(motor_left_dir,HIGH);
       digitalWrite(motor_right_dir,HIGH);
       analogWrite(motor_left,120);
       analogWrite(motor_right,0); 
     }
     else if(ch =='s'){  // action to be performed if input is 's'
       digitalWrite(motor_left_dir,HIGH);
       digitalWrite(motor_right_dir,HIGH);
       analogWrite(motor_left,0);
       analogWrite(motor_right,0); 
     }
 }
}
