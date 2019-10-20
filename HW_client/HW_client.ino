#include <ESP8266WiFi.h>
#include <WebSocketsClient.h>

WebSocketsClient wsc;

const char *ssid = "CSE Dept";
const char *pass = "CSE@zu2020";

#define SERVER  "192.168.22.49"
#define PORT    9000
#define URL     "/"

#define led1	3
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
	  char* s = (string) data;
	  if (s == "on1"){
		  digitalWrite(led1,HIGH);
		  //led on
	  }
	  else if (s == "off1"){
		  //led off 
		  digitalWrite(led1,LOW);
	  }
	  
	  if (s == "on2"){
		  digitalWrite(led2,HIGH);
		  //led on
	  }
	  else if (s == "off2"){
		  //led off 
		  digitalWrite(led2,LOW);
	  }
	  
	  
	  	  if (s == "on3"){
		  digitalWrite(led3,HIGH);
		  //led on
	  }
	  else if (s == "off3"){
		  //led off 
		  digitalWrite(led3,LOW);
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

