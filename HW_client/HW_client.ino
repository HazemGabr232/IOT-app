#include <ESP8266WiFi.h>
#include <WebSocketsClient.h>

WebSocketsClient wsc;

const char *ssid = "your ssid";
const char *pass = "your pass";

#define SERVER  "damp-brook-16044.herokuapp.com"
#define PORT    80
#define URL     "/"

#define led1	16
#define led2	4
#define led3	5

void websocketEvent(WStype_t type, uint8_t *data, size_t length){
  switch(type){
    case(WStype_CONNECTED):
      Serial.printf("connected to server\n");
      wsc.sendTXT("hardware");
      break;

    case(WStype_TEXT):
      Serial.printf("data: %s\n",data);
	  String s =  (char*)data;
	  if (s == "on1"){
		  digitalWrite(led1,HIGH);
      Serial.println("led1 high");
		  //led on
	  }
	  else if (s == "off1"){
		  //led off 
		  digitalWrite(led1,LOW);
     Serial.println("led1 low");
	  }
	  
	  if (s == "on2"){
		  digitalWrite(led2,HIGH);
      Serial.println("led2 high");
		  //led on
	  }
	  else if (s == "off2"){
		  //led off 
		  digitalWrite(led2,LOW);
     Serial.println("led2 low");
	  }
	  
	  
	  	  if (s == "on3"){
		  digitalWrite(led3,HIGH);
      Serial.println("led3 high");
		  //led on
	  }
	  else if (s == "off3"){
		  //led off 
		  digitalWrite(led3,LOW);
     Serial.println("led3 low");
	  }
	  
	  
      break;
  }
}

void setup(){
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
  Serial.begin(115200);

  WiFi.begin(ssid, pass);

  while(WiFi.status() != WL_CONNECTED){
    Serial.println(".");
    delay(500);
  }

  Serial.println(WiFi.SSID());
  Serial.println(WiFi.localIP());

  wsc.begin(SERVER, PORT, URL);
  wsc.onEvent(websocketEvent);
  wsc.setReconnectInterval(1000);
}

void loop(){
  wsc.loop();
}

