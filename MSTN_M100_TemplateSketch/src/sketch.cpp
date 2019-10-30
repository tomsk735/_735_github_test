#include "mstn_usb.h"
#include "stdio.h"
#include "Arduino_w.h"

void setup()
{
    while(USB_GetStatus() != PERMITTED);
}

void loop()
{
    printf ("Hello!\n");
    delay(1000);
}