
/**********************************************************************
 * 
 *      ****
 *     * 
 *    *        ****   **** ***   *   * 
 *    *       *    * *     *  *  *   *
 *    *       *    *  ***  ****   ***
 *     *      *    *     * *   *   *
 *      ****   ****  ****  ****    * 
 *      
 ***********************************************************************      
 *
 *    **        ********* ********        *****        *****       *****
 *    **        ********* *********      *     *      *     *     *     * 
 *    **        **        **      **    *  ***  *    *  ***  *   *  ***  *
 *    **        ****      **      **     *  *  *      *  *  *     *  *  *   
 *    **        ****      **      **      * * *        * * *       * * *
 *    **        **        **      **       ***          ***         ***
 *    ********* ********* *********        ***          ***         ***
 *    ********* ********* ********         ***          ***         ***
 *    
 *************************************************************************/

/**************************************************************************
 * 
 * Simple LED blinking project that blink with 3 LED (red, yellow, green) 
 * on a button push. 
 * 
 * Author: Cosby
 * 
 ***************************************************************************/

// Pin used by switch/contact
int contactPin = 7; 

// LED pins
int redPin = 3; 
int yellowPin = 4; 
int greenPin = 5;

// for serial print timing
unsigned long startMillis;
unsigned long currentMillis;

void setup() {
  // put your setup code here, to run once:

  // Start the serial so I can print to the serial monitor
  Serial.begin(9600);

  // initialize contact pin
  pinMode(contactPin, INPUT);

  // initialize LED pins
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // assign current time to startMillis
  startMillis = millis();

}

void loop() {
  // put your main code here, to run repeatedly:

  // only print every second
  currentMillis = millis();
  
  if(startMillis + 1000 <= currentMillis){ //check if second has passed 
    
    Serial.println(digitalRead(contactPin)); //write state of contact pin to serial monitor
    startMillis = currentMillis; //update startmillis
    
  } // END IF

  // check if contact is activated (pushed)
  if(digitalRead(contactPin) == HIGH){

    Serial.println(1); // write contact state to serial monitor
    
    ledBlink(); // call blink rutine
  
  } // END IF
 
} //END LOOP 


// LED blink rutine method
void ledBlink(){

  // blink red LED
  digitalWrite(redPin, HIGH);
  delay(200);
  digitalWrite(redPin, LOW);
  delay(200);
  digitalWrite(redPin, HIGH);
  delay(200);
  digitalWrite(redPin, LOW);
  delay(200);
  digitalWrite(redPin, HIGH);
  delay(200);
  digitalWrite(redPin, LOW);
  delay(200);
  digitalWrite(redPin, HIGH);
  delay(200);
  digitalWrite(redPin, LOW);
  delay(200);
  digitalWrite(redPin, HIGH);
  delay(200);

  // blink yellow LED
  digitalWrite(yellowPin, HIGH);
  delay(200);
  digitalWrite(yellowPin, LOW);
  delay(200);
  digitalWrite(yellowPin, HIGH);
  delay(200);
  digitalWrite(yellowPin, LOW);
  delay(200);
  digitalWrite(yellowPin, HIGH);
  delay(200);
  digitalWrite(yellowPin, LOW);
  delay(200);
  digitalWrite(yellowPin, HIGH);
  delay(200);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);
  delay(200);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(redPin, HIGH);
  delay(200);

  // blink green LED
  digitalWrite(greenPin, HIGH);
  delay(200);
  digitalWrite(greenPin, LOW);
  delay(200);
  digitalWrite(greenPin, HIGH);
  delay(200);
  digitalWrite(greenPin, LOW);
  delay(200);
  digitalWrite(greenPin, HIGH);
  delay(200);
  digitalWrite(greenPin, LOW);
  delay(200);
  digitalWrite(greenPin, HIGH);
  delay(200);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);
  delay(200);
  digitalWrite(greenPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(redPin, HIGH);
  delay(1000);

  // disco blinking 
  for(int i = 0; i < 5; i++){
    discoLED();  
  }

  // turn off all LED's
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, LOW);

}

// disco LED rutine
void discoLED(){

  // delay between disco blinks
  int delayTime = 75;

  // red to green
  digitalWrite(redPin, HIGH);
  delay(delayTime);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(delayTime);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(delayTime);

  // green to red
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(delayTime);
  digitalWrite(yellowPin, LOW);
 
}




//END
