/*3-Bit Calculator Project
Made by : Pongsapat Boonpong
Purpose : To study about binary addition and subtraction
Version : v1.0
Finish date : TBD
*/

byte Base10Sum1;
byte Base10Sum2;
byte Base10Result;

/*
//Input pins
int Input1 = 2;
int Input2 = 3;
int Input3 = 4;
int Input4 = 5;
int Input5 = 6;
int Input6 = 7;

//Output pins
int Output1 = 8;
int Output2 = 9;
int Output3 = 10;
int Output4 = 11;
*/

//Modes
int SummaryMode = 12;
int SubtractMode = 13;
bool Mode; //if true = sum mode, if false = subtract mode

void setup() {
  /*
  pinMode(input1, INPUT);
  pinMode(input2, INPUT);
  pinMode(input3, INPUT);
  pinMode(input4, INPUT);
  pinMode(input5, INPUT);
  pinMode(input6, INPUT);
  
  pinMode(Output1, OUTPUT);
  pinMode(Output2, OUTPUT); 
  pinMode(Output3, OUTPUT); 
  pinMode(Output4, OUTPUT); 
  */

  pinMode(SummaryMode, INPUT); 
  pinMode(SubtractMode, INPUT); 

}

void loop() {

  //Get input from the calculator
  for (int i = 0; i <= 2; i++){
    Base10Sum1 += digitalRead(i+2)^i;
    Base10Sum2 += digitalRead(i+5)^i;
  }

  //Show results on serial monitor
  char buffer[40];
   sprintf(buffer,"Set 1 : %i", Base10Sum1);
   Serial.print(buffer);
   sprintf(buffer,"Set 2 : %i", Base10Sum2);
   Serial.print(buffer);

  //Select mode
  if (digitalRead(SummaryMode == 1)){
    Serial.println("Mode : Summation");
    Mode = true;
  }
  else if (digitalRead(SubtractMode == 1)){
    Serial.println("Mode : Subtraction");
    Mode = false;
  }

  //Calculation
  if (Mode == true){
   //Calculation summmation 
   Base10Result = Base10Sum1 + Base10Sum2;
   char buffer[40];
   sprintf(buffer,"Summation result : %i", Base10Result);
   Serial.print(buffer);
   for (int i = 0; i <= 3; i++){
          if (Base10Result <= 0){
            break;
          }
          digitalWrite(i, Base10Result%2);
          Base10Result /= 2;
       }
  }
  else{
    //Calculate subtraction  
    Base10Result = Base10Sum1 - Base10Sum2;
    Serial.print("Subtraction result : " + Base10Result);
    if (Base10Result < 0){
      delay(2000);  
      return;
    }
    else{
       for (int i = 0; i <= 3; i++){
          if (Base10Result <= 0){
            break;
          }
          digitalWrite(i+8, Base10Result%2);
          Base10Result /= 2;
       }
    }
  }
  
  delay(2000);  
}
