#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define M50_SENSOR_PIN 15
#define M100_SENSOR_PIN 2
#define M200_SENSOR_PIN 4
#define M500_SENSOR_PIN 16
#define M1000_SENSOR_PIN 17

LiquidCrystal_I2C lcd(0x27, 16, 2);
int amount = 0;
int p_amount = -1;


void setup() {
  Serial.begin(115200);
  pinMode(M50_SENSOR_PIN, INPUT);
  pinMode(M100_SENSOR_PIN, INPUT);
  pinMode(M200_SENSOR_PIN, INPUT);
  pinMode(M500_SENSOR_PIN, INPUT);
  pinMode(M1000_SENSOR_PIN, INPUT);
  lcd.init(); // initializing the LCD
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Total monedas:");
}

void loop() {
  Serial.println("moneda mil");
  Serial.println(digitalRead(M1000_SENSOR_PIN));
  Serial.println("moneda quinientos");
  Serial.println(digitalRead(M500_SENSOR_PIN));
  Serial.println("moneda doscientos");
  Serial.println(digitalRead(M200_SENSOR_PIN));
  Serial.println("moneda cien");
  Serial.println(digitalRead(M100_SENSOR_PIN));
  Serial.println("moneda cincuenta");
  Serial.println(digitalRead(M50_SENSOR_PIN));

  if(digitalRead(M1000_SENSOR_PIN) == 0){
    amount = amount + 1000;
  }

  if(digitalRead(M500_SENSOR_PIN) == 0){
    amount = amount + 500;
  }

  if(digitalRead(M200_SENSOR_PIN) == 0){
    amount = amount + 200;
  }

  if(digitalRead(M100_SENSOR_PIN) == 0){
    amount = amount + 100;
  }

  if(digitalRead(M50_SENSOR_PIN) == 0){
    amount = amount + 50;
  }


  if (amount != p_amount){
    printTotal();
    p_amount = amount;
  }

  for (int a = 0; a < 10; a++) {
    for (int i = 0; i < 5; i++) {
      delay(1);
    }
  }
}

void printTotal() {
  lcd.setCursor(0, 1);
  lcd.print(amount);
  lcd.print(" pesos ");
}
