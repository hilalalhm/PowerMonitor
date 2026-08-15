# ⚡ ESP32 Power Monitor

**ESP32 Power Monitor** is an IoT-based electrical power monitoring system using an ESP32 and PZEM sensor. The system measures voltage, current, power, and energy consumption, displays the data on an OLED screen, and provides a web interface for real-time monitoring.

## ✨ Features

* ⚡ Real-time voltage monitoring
* 🔌 Current measurement
* 💡 Power consumption monitoring
* 📊 Energy consumption monitoring
* 🖥️ OLED display
* 🌐 Built-in web monitoring interface
* 📡 ESP32 Wi-Fi Access Point
* 🔄 Automatic sensor updates every 2 seconds

## 🛠️ Components

* ESP32
* PZEM Power Sensor
* OLED Display
* Electrical Load
* Power Supply
* Jumper Wires

## 📊 Monitored Parameters

| Parameter | Unit | Description                     |
| --------- | ---- | ------------------------------- |
| Voltage   | V    | Electrical voltage              |
| Current   | A    | Electrical current              |
| Power     | W    | Instantaneous power consumption |
| Energy    | kWh  | Accumulated energy consumption  |

## ⚙️ How It Works

The ESP32 reads electrical data from the PZEM sensor every **2 seconds**. The measured values are processed and displayed on the OLED screen.

At the same time, the ESP32 creates a Wi-Fi Access Point and runs a web server. Users connected to the ESP32 can access the web interface to view the latest power monitoring data.

```text
       PZEM Sensor
            │
            ▼
          ESP32
        ┌───┴───┐
        ▼       ▼
      OLED    Web Server
                │
                ▼
          Wi-Fi Access Point
                │
                ▼
          📱 / 💻 Browser
```

## 🌐 Web Interface

The ESP32 creates its own Wi-Fi Access Point:

```text
SSID      : Power Monitor
Password  : power123
```

After connecting to the Wi-Fi network, open the ESP32's IP address in a web browser.

The `/data` endpoint provides the latest sensor readings in JSON format:

```json
{
  "v": 220.5,
  "i": 1.25,
  "p": 275.6,
  "e": 0.125
}
```

## 📁 Project Structure

```text
ESP32-Power-Monitor/
├── index.h
├── pzem_sensor.h
├── display_oled.h
├── main.ino
└── README.md
```

### File Description

* `main.ino` — Main ESP32 program and web server
* `pzem_sensor.h` — PZEM sensor handling
* `display_oled.h` — OLED display functions
* `index.h` — Web interface HTML

## 🚀 Getting Started

1. Connect the PZEM sensor and OLED display to the ESP32.
2. Open the project in Arduino IDE or PlatformIO.
3. Install the required ESP32 libraries.
4. Upload the program to the ESP32.
5. Connect your phone or computer to the **Power Monitor** Wi-Fi network.
6. Open the IP address shown in the Serial Monitor.
7. Monitor voltage, current, power, and energy consumption in real time.

## 🔮 Future Improvements

* 📈 Real-time power charts
* 💾 Data logging
* 📱 Mobile-friendly dashboard
* ☁️ Cloud-based monitoring
* 🔔 Overload notifications
* 📊 Historical energy consumption
* 🔐 Web authentication

## ⚠️ Safety Warning

This project involves electrical power measurement. **Working with mains electricity can be dangerous.** Make sure the PZEM sensor and electrical connections are installed correctly and safely. Disconnect power before modifying wiring and use appropriate electrical protection.

## 📄 License

This project is open-source and intended for educational and personal use.

---

Made with ⚡ by **Hilal Al Hamdi**
