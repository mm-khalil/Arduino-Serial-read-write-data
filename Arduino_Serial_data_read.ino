int outputpin = 13; //LED
//int analogPin = A0; // Analog
int inputValue = 0;
String inputString = "";
boolean stringComplete = false;

void setup() 
{ 
   pinMode(outputpin, OUTPUT);
   digitalWrite(outputpin, LOW);
   Serial.begin(9600);
   inputString.reserve(200);

  while(Serial.available()<=0)
  {  sendStatus();
     delay(300);   }
}
void loop() 
{  if(stringComplete)
//   {  if(inputString.startsWith("status"))
//      {  sendStatus();
//         //Serial.println("status");   
//      }
         
    {  if(inputString.startsWith("set"))
      {   Serial.print(inputString);
          //if(inputString.indexOf("on" > -1))
          if(inputString.startsWith("seton"))
          {   digitalWrite(outputpin, HIGH);
              Serial.println("led turned ON");        }
          //else if (inputString.indexOf("off" > -1 ))
          else if(inputString.startsWith("setoff"))
          {   digitalWrite(outputpin, LOW);
              Serial.println("led turned OFF");       }
          else 
          {   Serial.println(inputString);
              Serial.println("invalid set command");  }
      }


       
    else
    {   Serial.println(inputString);
        Serial.println("invalid command");   }
      
   }
   
   
  // Reset string
  stringComplete = false;
  inputString="";
  
  delay(10);
  
  if(Serial.available()>0) 
  {  serialEvent();  }
  

}
void sendStatus()
{ char buffer[50];
 // inputValue = analogRead(analogPin);
 
  //sprintf(buffer,"Analog input is %d",inputValue);
  inputValue+=10;
  
  //Serial.println(buffer);
  //Serial.println("sendStatus = ");
}

void serialEvent() 
{ while (Serial.available()) 
  { // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') 
    {  stringComplete = true;  }

//    //Debug
//    Serial.println("serialevent");
//    Serial.println(inputString);
  }
}
