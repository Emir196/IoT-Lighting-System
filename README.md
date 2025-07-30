# 💡 ESP32 Smart Light Controller

A WiFi-enabled lighting control system built with ESP32 microcontroller. Control your lights remotely through a modern web interface with real-time status monitoring.

## 🌟 Features

- **WiFi Connectivity**: Connect ESP32 to your WiFi network for remote access
- **Web Interface**: Modern, responsive web-based control panel
- **Relay Control**: Turn lights on/off with a single click
- **Real-time Status**: Live status updates without page refresh
- **JSON API**: RESTful API support for integration
- **Turkish Interface**: Fully localized Turkish user experience
- **Mobile Friendly**: Responsive design works on all devices

## 🛠️ Hardware Requirements

- ESP32 development board
- Relay module (5V/3.3V compatible)
- Jumper wires
- WiFi network
- Power supply
- Light fixture to control

## 📚 Software Requirements

### Arduino IDE Libraries
```cpp
#include <WiFi.h>
#include <WebServer.h>
#include <ArduinoJson.h>
```

## 🔧 Installation

### 1. Setup Arduino IDE
- Install ESP32 board support in Arduino IDE
- Install required libraries (ArduinoJson)

### 2. Hardware Connections
```
ESP32 Pin 25 → Relay IN
ESP32 VCC    → Relay VCC
ESP32 GND    → Relay GND
```

### 3. Configuration
Edit the WiFi credentials in the code:
```cpp
const char* ssid = "Your_WiFi_Name";
const char* password = "Your_WiFi_Password";
```

### 4. Upload Code
- Connect ESP32 to computer
- Select correct board and port
- Upload the code

## 🚀 Usage

1. Power on the ESP32
2. Wait for WiFi connection (monitor serial output)
3. Note the IP address from serial monitor
4. Open web browser and navigate to the IP address
5. Use the "Aç/Kapat" (On/Off) button to control lights

## 🌐 API Endpoints

| Method | Endpoint | Description |
|--------|----------|-------------|
| `GET` | `/` | Main page (Web interface) |
| `GET` | `/toggle-relay` | Toggle relay state |

### API Response Format
```json
{
  "success": true,
  "state": true
}
```

## 📱 Web Interface

The web interface features:
- Clean, minimalist design
- Large, easy-to-use toggle button
- Real-time status display
- Error handling with user feedback
- Mobile-responsive layout

## 🔌 Circuit Diagram

```
ESP32          Relay Module
GPIO 25   →    IN
3.3V      →    VCC
GND       →    GND

Relay Module   Load (Light)
COM       →    AC Line
NO        →    Light Fixture
```

## ⚡ Technical Specifications

- **Microcontroller**: ESP32
- **Programming Language**: C++ (Arduino Framework)
- **Web Server**: ESP32 WebServer Library
- **Communication**: HTTP/JSON
- **Control Pin**: GPIO 25
- **Operating Voltage**: 3.3V/5V
- **WiFi Standard**: 802.11 b/g/n

## 🛡️ Safety Notes

⚠️ **Important Safety Information**
- Always disconnect power when making connections
- Use appropriate relay ratings for your load
- Follow local electrical codes
- Consider using GFCI protection
- Test the system before permanent installation

## 🔧 Troubleshooting

### WiFi Connection Issues
- Verify SSID and password
- Check signal strength
- Ensure 2.4GHz network (ESP32 doesn't support 5GHz)

### Relay Not Working
- Check wiring connections
- Verify relay module compatibility
- Test with multimeter

### Web Interface Not Loading
- Confirm IP address from serial monitor
- Check firewall settings
- Try different browser

## 📈 Future Enhancements

- [ ] Scheduling functionality
- [ ] Multiple relay support
- [ ] MQTT integration
- [ ] Mobile app
- [ ] Voice control integration
- [ ] Energy monitoring
- [ ] OTA updates

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

## 📞 Support

If you encounter any issues or have questions, please open an issue on GitHub.

---

⭐ If you found this project helpful, please give it a star!

**Made with ❤️ for the IoT community**
