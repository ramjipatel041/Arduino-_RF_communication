#include <VirtualWire.h>

const int button = 3;
int button_state = LOW;
char *controller;

void setup() 
{
// put your setup code here, to run once:
pinMode(button , INPUT);
vw_set_ptt_inverted(true);
vw_set_tx_pin(12);
vw_setup(4000);
delay(100);
}

void loop() 
{
// put your main code here, to run repeatedly:
button_state = digitalRead(button);
if(button_state == HIGH)
 {
  controller = "1";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx();
 }
else
 {
  controller = "0";
  vw_send((uint8_t *)controller, strlen(controller));
  vw_wait_tx();
 }
}
 
