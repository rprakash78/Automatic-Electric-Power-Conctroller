#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

#define in 14
#define out 19
#define relay 2
//#define CONTRAST_PIN 3
//#define CONTRAST_VALUE

int count=0;

void IN()
{
    count++;
    lcd.clear();
    lcd.print("Person In Room:");
    Serial.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    Serial.println(count);
    delay(2000);
}

void OUT()
{
  if(count<=0){
    count=0;
  }
  else{
    count--;
  }
    lcd.clear();
    lcd.print("Person In Room:");
    Serial.print("Person In Room:");
    lcd.setCursor(0,1);
    lcd.print(count);
    Serial.println(count);
    delay(2000);
}

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  digitalWrite(relay,200);
  lcd.print("Visitor Counter");
  Serial.print("Visitor Counter");
  delay(2000);
  pinMode(in, INPUT);
  pinMode(out, INPUT);
  pinMode(relay, OUTPUT);
  lcd.clear();
  lcd.print("Person In Room:");
  Serial.print("Person In Room:");
  lcd.setCursor(0,1);
  lcd.print(count);
  Serial.println(count);
}

void loop()
{  
  
  if(digitalRead(in) && !digitalRead(out))
  {
  IN();
  }
  if(digitalRead(out) && !digitalRead(in))
  {
  OUT();
  }
  if(count<=0)
  {
    lcd.clear();
    digitalWrite(relay, LOW);
    lcd.clear();
    lcd.print("Nobody In Room");
    Serial.print("Nobody In Room");
    lcd.setCursor(0,1);
    lcd.print("Light Is Off");
    Serial.println("Light Is Off");
    delay(200);
  }
  else
    digitalWrite(relay, HIGH);
  
}
