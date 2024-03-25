 /*3-Bit Calculator Project
Made by : Pongsapat Boonpong
Purpose : To study about binary addition and subtraction
Version : v1.0
Finish date : V1.0 (25-3-2024)
*/

int Base10Sum1;
int Base10Sum2;
int Base10Result;

/*
//Input digital pins
Input1 = 2;
Input2 = 3;
Input3 = 4;
Input4 = 5;
Input5 = 6;
Input6 = 7;

//Output digital pins
Output1 = 8;
Output2 = 9;
Output3 = 10;
Output4 = 11;
*/

//Modes
int CheckMode = A0;

void setup() {
  Serial.begin(115200);
  pinMode(CheckMode, INPUT); 
}

void loop() {
  Serial.println(analogRead(A0));
  for (int i = 8; i <= 11; i++){
    digitalWrite(i, LOW);
  }
  //Get input from the calculator
  for (int i = 0; i <= 2; i++){
    if (digitalRead(i+2) == 1){
      Base10Sum1 += round(pow(2,i));
      //Serial.println(pow(2,i));
    }
    if (digitalRead(i+5) == 1){
      Base10Sum2 += round(pow(2,i));
    }
  }

  //Show results on serial monitor
  char buffer[40];
   sprintf(buffer,"Set 1 : %i", Base10Sum1);
   Serial.println(buffer);
   sprintf(buffer,"Set 2 : %i", Base10Sum2);
   Serial.println(buffer);

  //Calculation
  if (analogRead(CheckMode) >= 1){
   //Calculation summmation 
   Serial.println("Mode : Summation");
   Base10Result = Base10Sum1 + Base10Sum2;
   char buffer[40];
   sprintf(buffer,"Summation result : %i", Base10Result);
   Serial.println(buffer);
   for (int i = 0; i <= 3; i++){
          if (Base10Result <= 0){
            break;
          }
          digitalWrite(i+8, Base10Result%2);
          Base10Result /= 2;
       }
  }
  else{
    //Calculate subtraction  
    Serial.println("Mode : Subtraction");
    Base10Result = Base10Sum1 - Base10Sum2;
    if (Base10Result < 0){
      Serial.println("Subtraction invalid");
      Base10Sum1 = 0;
      Base10Sum2 = 0;
      Base10Result = 0;
      delay(2000);  
      return;
    }
    else{
      char buffer[40];
      sprintf(buffer,"Subtraction result : %i", Base10Result);
      Serial.println(buffer);
       for (int i = 0; i <= 3; i++){
          if (Base10Result <= 0){
            break;
          }
          digitalWrite(i+8, Base10Result%2);
          Base10Result /= 2;
       }
    }
  }
  Base10Sum1 = 0;
  Base10Sum2 = 0;
  Base10Result = 0;
  delay(2000);  
}
