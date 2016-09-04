#include <Arduino.h>
#include "OtaUpdate.h"

void setup()
{

Serial.begin(115200);
delay(5000);
Serial.println("GOOO!!!");


OtaUpdate ota("http://crm.wedoit.io/temp/firmware1.bin", 1);

OTAUpdateResult ret = ota.RunUpdate();

switch(ret) {
  case OTA_UPDATE_FAILED:
          Serial.println("[update] Update failed.");
          break;
  case OTA_RELEASE_NUMBER_UNAVAILABLE:
          Serial.println("[update] remote release unvailable");
          break;
  case OTA_UPDATE_UNNECESSARY:
          Serial.println("[update] firmware already installed");
          break;
  case OTA_UPDATE_OK:
          Serial.println("[update] Update ok.");
          int newRelease = ota.GetReleaseNumber();
          Serial.println("New release was saved. reboot");
          Serial.println(newRelease);
          ota.Reboot();

          break;
}


Serial.println(ret);

}

void loop()
{


}
