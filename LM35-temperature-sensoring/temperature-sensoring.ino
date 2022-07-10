#include<Wire.h>
#include<LiquidCrystal_I2C.h>


int redPin = 15; 
int greenPin = 14;//GPIO 13 corresponds to pin D7. You can check the pinout.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup(){
  Serial.begin(9600);
  lcd.begin();
lcd.backlight();

pinMode(redPin, OUTPUT);
pinMode(greenPin, OUTPUT);


}

void loop(){
    int rawData = analogRead(A0);
    float vcc = 5.0;
    float voltage = rawData * (vcc / 1024.0);
    float temperature = voltage * 100;
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");
    
    delay(500);
   lcd.clear();
   lcd.print("Temperature: ");
   lcd.setCursor(0,1);   
   lcd.print(temperature);
   lcd.print(" *C");


    if(temperature > 47 && temperature < 48){ 

        digitalWrite(greenPin,LOW);
digitalWrite(redPin,HIGH);

      
      }
      else{

                digitalWrite(greenPin,HIGH);
digitalWrite(redPin,LOW);

        
        }

        
   delay(500);
}
