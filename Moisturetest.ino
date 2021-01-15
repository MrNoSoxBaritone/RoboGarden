#include <LiquidCrystal.h>

void getReadings(int readings[]);

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
const int AirValue = 611;   //you need to replace this value with Value_1
const int WaterValue = 272;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;
void setup() {
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  lcd.begin(16, 2);
}
void loop() {
  int moistureReadings[]={0,0,0,0};
  
  getReadings(moistureReadings);

  lcd.setCursor(0, 0);
  lcd.print("Soil Moisture");
  Serial.print("A0: ");
    Serial.println(moistureReadings[0]);

  for(int i=0;i<4;i++){
    lcd.setCursor(i*4, 1);
    soilMoistureValue = moistureReadings[i];  
    soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
   if(soilmoisturepercent >= 100)
    {
      lcd.print("100%");
    }
    else if(soilmoisturepercent <=0)
    {
      lcd.print("0%");
    }
    else if(soilmoisturepercent >0 && soilmoisturepercent < 100)
    {
      lcd.print(soilmoisturepercent);
      lcd.print("%");
    }  
  }
    delay(250);
    lcd.clear();
}

void getReadings(int readingsArray[])
{
  //Serial.print("A0: ");
  readingsArray[0] = analogRead(A0);
  //Serial.println(readingsArray[0]);
  //Serial.print("A1: ");
  readingsArray[1] = analogRead(A1);
  //Serial.println(readingsArray[1]);
  //Serial.print("A2: ");
  readingsArray[2] = analogRead(A2);
  //Serial.println(readingsArray[2]);
  //Serial.print("A3: ");
  readingsArray[3] = analogRead(A3);
  //Serial.println(readingsArray[3]);
}