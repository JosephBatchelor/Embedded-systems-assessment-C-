#include <stdlib.h>
#include <stdio.h>
//Global varibles
/*
This area is where I’m declaring and initializing my global varibles 
to be used throughout my code. A global varible is one that can be called
and used within different function within this code.
The two global varibles ive creates is an array which has been set to hold 15 
elements and size which is the size of the array which is 15. The reason ive created
a varible for the size is that it will help me with setting up loops through out my code.
*/
int array[15]; 
int size = 15;
/*
Function set up is used to initiate communication between the Arduino board and the computer.
As you can see ive told the arduino board that we will be using serial ports 2 to 9.
This will establish a connection.
*/
void setup() {
Serial.begin(9600);//This line of code will allow me to enter keyboard input within the serial monitor.
//the value 9600 is the rate at which data will be transfered at.
pinMode(9,OUTPUT);//This means that serial port 9 will preform an output task, which is to turn on a light.
pinMode(8,OUTPUT);
pinMode(7,OUTPUT);
pinMode(6,OUTPUT);
pinMode(5,OUTPUT);
pinMode(4,OUTPUT);
pinMode(3,OUTPUT);
pinMode(2,OUTPUT);
}
/*
Function loop is a feature of C that will constantly run this function forever, repeating the
code within the function. In this case function loop will be used to call all my other functions and constantly run them.
This will allow for the array to change its sequence meaning a new array of elements will be sorted every time.
*/
void loop() {
char byte; // This is a delcalred character varible which will be used to store the value of the key input.
byte = Serial.available(); //byte has beeen set to a serial method called availbe which acts as a scanner within the 
//serial montior it will store the value of the key input and convert it into a value to be used.
if(byte >0){// this is a simple if statmenet where if the key input when converted is greater than 0,
           //will start the execution of code.
RandomArray();//Sorts 15 random numbers within the array and Displays them.
FindingSmallestValues();//Finds all posssible information relating to the smallest number.
delay(5000); //tells the execution of code to sleep for 5 seconds before proceeding.
digitalWrite(2,LOW);//turns off the LED
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
FindingLargestValues();//Finds all posssible information relating to the largest number.
delay(5000);
digitalWrite(2,LOW);
digitalWrite(3,LOW);
digitalWrite(4,LOW);
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
digitalWrite(9,LOW);
SortingAlgorithm();//Sorts the array created in acessending order using bubble sort mehtod.
SortedArrayDisplay();//Displays the sorted array.
byte = 0; // This is just setting the value of byte back to 0. 
delay(10000);/*Once the entire execution of code has finished it will sleep for 10 seconds
before starting on the new sequence.*/
  }
}


/*
This first function is designed to store 15 random integers within the array. 
*/
int RandomArray(){
Serial.print("\n Unsorted");//Displays a line of text saying "Unsorted" on a new line.
int i;
for(i = 0; i < size ; i++){
array[i] = rand()%255;//Using the method rand() which is a feature of C this will generate a random number.
// i divided the rand() number by the max amount which 255 and then used "%" to get its reaminder which will be less than the max.
}
//I created another loop which will be used to display the unsorted array using a pointer.
//Using a pointer to display the contents
int *Pointer = array; // This finds the value witihin the array , which is simular to saying "*pointer = array[0]" 
int j;
  for(j = 0; j < size; j++){
    Serial.print(" ");//spaces everything neatly.
    Serial.print(*(Pointer+j)); //Displays the value of array[j].
}return 0;
  }
  
/*
This function is designed to find the smallest value within the array. 
It also is tasked with finding additional information such as the position 
within the array and what the number is, as well as the its binary format.
*/
int FindingSmallestValues(){
int max = 255;//This is the max value we were set.
int minposition; //declaring a new varible for the position.
int i; //This loop is designed to look for the smallest value within the array.
for(i = 0; i <size ; i++){
  if(array[i] < max){//This if statment comapres the max value to the array indexed value.
    max = array[i]; //sets max to the smallest number witthin the array. 
  }
 }
int Smallest = max;// setting smallest to be the value of max.
/*A new loop is used to find the position of the smallest number.
This is done by loop through the array comparing each number to the smallest value and counting its positons.*/
int Minp;
for(Minp =0; Minp < size; Minp++){
    if( array[Minp] == Smallest){
        minposition = Minp; //Initialising minposition to be equalled to the array counter.
    }
}
//This next section is used to display the information reagarding the smallest value within the serial monitor.
Serial.print("\n\n Smallest value: ");
Serial.print(Smallest);
Serial.print("\n Small value Position: ");
Serial.print(minposition+1);//Incrementing the minpositon by one so that it starts at one and is inline with the arduino port numbers. 
Serial.print("\n Smallest value in binary: ");
int n,c,k;//Delcalring three varibles.
n = Smallest;//setting n to the smallest value.
for (c =7; c >= 0; c--){//This for loop will allow me to print and display in the LED's the binary value for the smallest number.
int value =1;//This will be used withn the switch statment to turn the correct lights on. 
k = n >> c;//The operator ">>" means binary shift right it means to shift the value in set right by "1" bit.
// K will be equaled the the shift.
if (k & 1){//this is an if statement that says if k is equalled one then do the following and print "1" else do nothing and print "0".
Serial.print("1");//when ever K is equalled to one then it will print the value "1".
value *= c; /*To get he correct switch statement with the right LED we must make value albe to determine which lights needs to be on.
 i managed to do this by timeings the varible value with the value c which the loop index. once the statement has been executed the varible 
 value will be set to zero and then back to one to light up the next LED.*/
switch(value){//Value will be used to trigger the the correct LED's
case 0:
digitalWrite(2,HIGH); // Each case will have their own LED's that will be turned on when the condition is correct.
value = 0;
break;
case 1:
digitalWrite(3,HIGH);
value = 0;
break;
case 2:
digitalWrite(4,HIGH);
value = 0;
break;
case 3:
digitalWrite(5,HIGH);
value = 0;
break;
case 4:
digitalWrite(6,HIGH);
value = 0;
break;
case 5:
digitalWrite(7,HIGH);
value = 0;
break;
case 6:
digitalWrite(8,HIGH);
value = 0;
break;
case 7:
digitalWrite(9,HIGH);
value = 0;
break;
};
}else{
Serial.print("0");//This will print if K does not equal "1".
    }
  }
  return 0;
  }

  
/*
This function is the same as FindingSmallestValues(), 
the only diffrence is that some of the varible are set different or have different values. 
The layout and the struture is still the same.
*/
int FindingLargestValues(){
int min = 0;//Min is the smallest value we can use.
int maxposition = 7;
  
int i;
for(i = 0; i <size ; i++){
  if(array[i] > min){
    min = array[i];
  }
 }
 
int  Largest = min;

int Maxp;
for(Maxp =0; Maxp < size; Maxp++){
    if( array[Maxp] == Largest){
        maxposition = Maxp;
    }
}
//Printed all the information needed for the largest value.
Serial.print("\n");
Serial.print("\n Largest value: ");
Serial.print(Largest);
Serial.print("\n Large value Position ");
Serial.print(maxposition+1);
Serial.print("\n Largest value in binary: ");

//Converting the Largest number into 8-bit binary
int n,c,k;
n = Largest;
for (c = 7; c >= 0; c--){
int value =1;
k = n >> c;
if (k & 1){
Serial.print("1");
value *= c;
switch(value){
case 0:
digitalWrite(2,HIGH);
value = 0;
break;
case 1:
digitalWrite(3,HIGH);
value = 0;
break;
case 2:
digitalWrite(4,HIGH);
value = 0;
break;
case 3:
digitalWrite(5,HIGH);
value = 0;
break;
case 4:
digitalWrite(6,HIGH);
value = 0;
break;
case 5:
digitalWrite(7,HIGH);
value = 0;
break;
case 6:
digitalWrite(8,HIGH);
value = 0;
break;
case 7:
digitalWrite(9,HIGH);
value = 0;
break;
};
}else{
Serial.print("0");
  }
}
return 0;
}
                                     

/* 
This function is designed to sort the array in ascending order. 
This method is based around the bubble sort algorithm. 
*/  
int SortingAlgorithm(){
int CurrnetNode; //This is used within the loops and is set as the current index value within the array.
int NextNode;//This varible is "+1" to the current node which is the next element.  
/*This sorting algorithm uses two loops and an if statement. 
The first loop searches the array once, where as the second loop will search the array 15 times.
In total loop two will preform 225 loops by the time loop one finishes. 
the whole purpose of the second loop is to check which value is bigger. 
Its able to do this by using the if statmenet to compare the current node and the
next node. if the the current node is geater, then it will swap the the two around.*/ 
int x;
for(x = 0; x < size-1 ; x++){
  int y;
  for(y = 0; y <size-1 ; y++){
   if(array[y] > array[y+1]){// If the current array value is greater than the next array then swap.
       CurrnetNode = array[y];// This sets the array index value to current node , where current node is used as a temp.
       array[y] = array[y+1]; // Now we are setting the current node to the value of the next node.
       array[y+1] = CurrnetNode;// Then we use the temp varible "CurrentNode"which held our previous current node 
       //and use that to store it where next node was.
      }
    }
  }
}

/*
This function is to print and display the final arrangement of the the array which should be sorted in ascending order.
This was done by using pointers. This is the smae method used to display the unsorted array using the pointer.
*/
int SortedArrayDisplay(){
  //displaying the final outcome
Serial.print("\n \n sorted: ");
int *Pointer = array;
int i;
  for(i = 0; i < size; i++){
    Serial.print(" ");
    Serial.print(*(Pointer+i));
}
 }
  
