    #include <WiFi.h>
    #include <WebServer.h>
    #include <ArduinoJson.h>

    #define RELAY_PIN 25  // Röle pin tanımı
    
    const char* ssid = "emir";      // WiFi ağ adınız
    const char* password = "internet";  // WiFi şifreniz

    bool relayState = false;  // Röle durumu için değişken
    // Set web server port number to 80
    WebServer server(80);

    // HTML content
    const char* html_content = R"rawliteral(
    <!DOCTYPE html>
    <html lang="tr">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Aydınlatma Kontrol Paneli</title>
        <style>
            body {
                font-family: Arial, sans-serif;
                display: flex;
                justify-content: center;
                align-items: center;
                min-height: 100vh;
                margin: 0;
                background-color: #f0f0f0;
            }
            .container {
                background-color: white;
                padding: 20px;
                border-radius: 8px;
                box-shadow: 0 2px 4px rgba(0,0,0,0.1);
                text-align: center;
            }
            .button {
                background-color: #4CAF50;
                border: none;
                color: white;
                padding: 15px 32px;
                text-align: center;
                text-decoration: none;
                display: inline-block;
                font-size: 16px;
                margin: 4px 2px;
                cursor: pointer;
                border-radius: 4px;
            }
            .status {
                margin: 20px 0;
                font-size: 24px;
            }
        </style>
    </head>
    <body>
        <div class="container">
            <h1>Aydınlatma Kontrol</h1>
            <div class="status">Durum: <span id="relay-status">Kapalı</span></div>
            <button class="button" onclick="toggleRelay()">Aç/Kapat</button>
        </div>
        <script>
            function toggleRelay() {
                fetch('/toggle-relay')
                    .then(response => response.json())
                    .then(data => {
                        if(data.success) {
                            document.getElementById('relay-status').textContent = 
                                data.state ? 'Açık' : 'Kapalı';
                        }
                    })
                    .catch(error => {
                        console.error('Bağlantı hatası:', error);
                        alert('Bağlantı hatası oluştu!');
                    });
            }
        </script>
    </body>
    </html>
    )rawliteral";


        
    void controlRelay(bool state) {
        relayState = state;
        digitalWrite(RELAY_PIN, state ? HIGH : LOW);
        Serial.println(state ? "Işıklar açıldı" : "Işıklar kapandı");
    }

    void setup() {
        Serial.begin(115200);
        pinMode(RELAY_PIN, OUTPUT);

    //digitalWrite(DHT11_LED_PIN,HIGH);
    //digitalWrite(DS18B20_LED_PIN,HIGH);
    // WiFi bağlantısı
    WiFi.begin(ssid, password);
    Serial.print("WiFi bağlanıyor");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi bağlandı");
    Serial.println("IP adresi: ");
    Serial.println(WiFi.localIP());



    // Web sunucusu rotaları
    server.on("/", HTTP_GET, []() {
        server.send(200, "text/html; charset=utf-8", html_content);
    });

    // Röle durumunu değiştirme endpoint'i
    server.on("/toggle-relay", HTTP_GET, []() {
        StaticJsonDocument<200> doc;
        
        // Röle durumunu tersine çevir
        relayState = !relayState;
        controlRelay(relayState);
        
        doc["success"] = true;
        doc["state"] = relayState;
        
        String response;
        serializeJson(doc, response);
        server.send(200, "application/json", response);
    });

    server.begin();
    Serial.println("HTTP sunucusu başlatıldı");
    }

    void loop() {
    server.handleClient();
    
    delay(200);
    }