#include <Arduino.h>
#include <rak3272_lib_p2p.h>



#define FREQ 915000000
#define SF 7
#define BW 0
#define CR 0
#define PREAMB_LEN 20
#define TX_PW 14

// put function declarations here:
String message_LoRa = "", message_pc = "";
RAK3272 node1(FREQ, SF, BW, CR, PREAMB_LEN, TX_PW);

void setup() {
  // put your setup code here, to run once:
  pinMode(16,INPUT);
  pinMode(17,OUTPUT);
  Serial.begin(9600);
  Serial2.begin(115200);
  Serial.println("estoy listo");
  //node1.inicialize();
  //node1.check();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(Serial2.available()){
    message_LoRa = Serial2.readStringUntil('\n');
    Serial.println("recibo: " + message_LoRa);
    message_LoRa="";
  }

  
  while(Serial.available()){
    message_pc = Serial.readStringUntil('\n');
    Serial2.print(message_pc);
    Serial.println("estoy enviando: " + message_pc);
    message_pc="";
  }

}
