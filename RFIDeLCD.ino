#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>

static const uint8_t NSS = 10; RST = 9; RS = 6; E = 7; D4 = 5; D5 = 4; D6 = 3; D7 = 2;

MFRC522 mfrc522(NSS, RST);
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);

void setup() 
{
  Serial.begin(9600);   // Inicia a serial
  SPI.begin();      	// Inicia SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522
  lcd.begin(16, 2);
}
 
void loop() 
{
  Serial.println("Aproxime o seu cartao do leitor...");
  lcd.clear();
  lcd.print(" Aproxime o seu");  
  lcd.setCursor(0, 1);
  lcd.print("cartao do leitor");  
  
  if (!mfrc522.PICC_IsNewCardPresent()){return;}
  if (!mfrc522.PICC_ReadCardSerial()){return;}
  
  lcd.clear();
  lcd.print(" TAG: ");  
  lcd.setCursor(0, 1);
  
  //Mostra UID no serial monitor
  Serial.print("UID da tag :");
  for (uint8_t i = 0; i < mfrc522.uid.size; i++) {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
	 lcd.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();
} 