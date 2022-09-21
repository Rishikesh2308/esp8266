#include <ESP8266WiFi.h>

const char* ssid = "San";
const char* password = "sanjay23";
const char* host = "maker.ifttt.com";

void setup() {
   Serial.begin(115200);
   Serial.println("Email from Node Mcu");
   delay(100);
   Serial.print("Connecting to ");
   Serial.println(ssid);
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
   }
   Serial.println("");
   Serial.println("IP address: ");
   Serial.println(WiFi.localIP()); 
}
void loop() { 
        WiFiClient client;
        const int httpPort = 80; 
         if (!client.connect(host, httpPort)) { 
               Serial.println("connection failed"); 
         return;}
        if(Serial.available()){
         char a=Serial.read();
         if (a=='o'){
                 String url = "/trigger/note/json/with/key/d2vWzmxm0t_Qx3QW8G_nkB";
                 Serial.print("Requesting URL: ");
                 Serial.println(url);
                 client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                                   "Host: " + host + "\r\n" +  
                                          "Connection: close\r\n\r\n");   
                                   } 
         else{
           Serial.println("Correct character not pressed.Try again");
         }
         }
         delay(1000);
}
