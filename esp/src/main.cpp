#include <WiFi.h>

const char* ssid     = "agaga ";
const char* password = "tak ya i pokazal ";

WiFiServer server(80);

void setup()
{
    Serial.begin(115200);

    delay(100);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
    }

    server.begin();
}

void loop(){
    WiFiClient client = server.available();

    if (client) {
        String currentLine = "";
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();
                if (c == '\n') {
                    if (currentLine.length() == 0) {
                        client.println("HTTP/1.1 200 OK");
                        client.println("Content-type:text/html");
                        client.println();
                        client.print("EPS32 HELLLOOssO");
                        client.println();
                        break;
                    } else {
                        currentLine = "";
                    }
                } else if (c != '\r') {
                    currentLine += c;
                }
            }
        }
        client.stop();
    }
}
