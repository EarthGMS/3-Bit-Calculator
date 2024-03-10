/*3-Bit Calculator Project
Made by : Pongsapat Boonpong

*/

byte Base10Sum1;
byte Base10Sum2;


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

//Modes
int SummaryMode = 12;
int SubtractMode = 13;

void setup() {
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

  pinMode(SummaryMode, INPUT); 
  pinMode(SubtractMode, INPUT); 

}

void loop() {
  

}
