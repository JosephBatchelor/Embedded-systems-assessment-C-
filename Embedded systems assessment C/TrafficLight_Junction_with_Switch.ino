//Traffic light set1 these are the ports we will be using for the LEDS in set traffic set 1.
  int green1 = 13 ; // port 13.
  int amber1 = 12 ; //port 12.
  int red1 = 11; //port 11.
//Traffic light set2 port numbers.
  int green2 = 10 ; // port 10.
  int amber2 = 9 ; //port 9.
  int red2 = 8 ; //port 8.
//Pedestrain lights
  int ped1 = 7; // port 7
  int ped2 = 6; // port 6
/*As always we have to set up the ports we are using on the arduino. This tells the arduino which
 *ports we are using to comunicate and the type of action we are doing, so in this case output.  */
void setup(){ 
  pinMode(green1, OUTPUT); 
  pinMode(amber1, OUTPUT);
  pinMode(red1, OUTPUT);
  pinMode(green2, OUTPUT); 
  pinMode(amber2, OUTPUT);
  pinMode(red2, OUTPUT);
  pinMode(ped1, OUTPUT);
  pinMode(ped2, OUTPUT);
}
/*This functon loop will act as a forever working loop, this means that the code nested in the body 
 *will be executed until a condition is met where in this case their isnt. Within the loop function
 *their is a for loop which will help with alternating between the two functions which are 
 *TrafficLightSet1 & TrafficLightSet2. All together this will create the junction. */
void loop(){
 int i;
for(i = 1; i <=2; i++){ //Simple for loop statement designed to loop between each function.
if(i == 1){
  digitalWrite(red2, HIGH);//while TrafficLightSet1 is on this sets TrafficLightSet2 red and ped light on.
    delay(1500);
  digitalWrite(ped2, HIGH);
  TrafficLightSet1(green1 , amber1 , red1,ped1);//This calls function TrafficLightSet1 to do the sequence.
}else{ //Once the condition is not met it will switch to TrafficLightSet2 to do the same the 1.
  digitalWrite(red1, HIGH);//while TrafficLightSet2 is on this sets TrafficLightSet1 red and ped light on.
  delay(1500);
  digitalWrite(ped1, HIGH);
  TrafficLightSet2(green2 , amber2 , red2,ped2);
   }
  }
 }
/*TrafficLightSet1 i a function that holds four integer values. each value is set to its own port value.
 *This case Green1,amber1 and red1 are all set to port value 13,12 and 11. This function a combination
 *of a for loop statement and a switch statement. the for loops starts at the values i which is set to 1.  
 *The switch uses the value of i to pick the right case. So starting with i=1 the switch will run the case
 *1 which will start the first phase of the traffic light sequence. Each case is designed to represent what
 *each phase would do.*/
int TrafficLightSet1 (int green1, int amber1, int red1, int ped1){//Uses the port values stated at the top.
int i ;
for(i = 1; i <=4; i++){//simple for loops that does four loops, one for each case.
switch(i){//Switch with i set as its parameter.
case 1:
//PHASE ONE - Red light is the only light on for 8 seconds.
      digitalWrite(green1, LOW); //digitalWrite function is used to tell the arduino to do somthing 
      digitalWrite(amber1, LOW); // which is in this case is change the LED's to high or to low.
      digitalWrite(ped1, LOW);
      digitalWrite(red1, HIGH);
      delay(2000);
break;//Code is ran until break is read , this will stop case one and go back to the loop for the next.
case 2:
//PHASE TWO - Red and amber are both on for 3 seconds.
      digitalWrite(amber1, HIGH);
      delay(3000);
break;
case 3:
//PHASE THREE - Red and amber turn off and then green turns on for 3 seconds. and blinks when about to change.
      digitalWrite(green1, HIGH);
      digitalWrite(amber1, LOW);
      digitalWrite(red1, LOW);
      delay(8000);
      digitalWrite(green1, LOW);
break; 
case 4:
//PHASE FOUR - Green light turns off and amber is turned on for 3 seconds.
      digitalWrite(amber1, HIGH);
      delay(3000);
      digitalWrite(amber1, LOW);
      digitalWrite(red1, HIGH);
break;
      }
   }
}   
//Same function as TrafficLightSet1 except it uses different varibles that have different port values.      
int TrafficLightSet2 (int green2, int amber2, int red2, int ped2){ 
int i;
for(i = 1; i <=4; i++){
 switch(i){
 case 1:
//PHASE ONE - Red light is the only light on for 8 seconds.
      digitalWrite(green2, LOW); //digitalWrite function is used to tell the arduino to do somthing 
      digitalWrite(amber2, LOW); // which is in this case is change the LED's to high or to low.
      digitalWrite(ped2, LOW);
      digitalWrite(red2, HIGH);
      delay(2000);
break;
case 2:
//PHASE TWO - Red and amber are both on for 3 seconds.
      digitalWrite(amber2, HIGH);
      delay(3000);
break;
case 3:
//PHASE THREE - Red and amber turn off and then green turns on for 3 seconds. and blinks when about to change.
      digitalWrite(green2, HIGH);
      digitalWrite(amber2, LOW);
      digitalWrite(red2, LOW);
      delay(8000);
      digitalWrite(green2, LOW);
break; 
case 4:
//PHASE FOUR - Green light turns off and amber is turned on for 3 seconds.
      digitalWrite(amber2, HIGH);
      delay(3000);                                       
      digitalWrite(amber2, LOW);
      digitalWrite(red2, HIGH);
 break;
      }
   }
}
