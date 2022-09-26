#include <VirtualWire.h>
#define led 5

void setup() {
// put your setup code here, to run once:
pinMode(led, OUTPUT);
vw_set_rx_pin(12);
vw_setup(4000);
vw_rx_start();
}

void loop() {
// put your main code here, to run repeatedly:
uint8_t buf[VW_MAX_MESSAGE_LEN];
uint8_t buflen = VW_MAX_MESSAGE_LEN;
if(vw_get_message(buf, &buflen))
 {
  if(buf[0] == '1')
   {
    digitalWrite(led, HIGH);
   }
  else
   {
    digitalWrite(led, LOW);
   }
 }
}
