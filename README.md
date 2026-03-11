# ☀️ Solar Tracker

An Arduino-based dual-axis solar tracker that automatically orients a solar panel toward the brightest light source using LDR sensors and servo motors.

## 📌 How It Works

Four LDR (Light Dependent Resistor) sensors are placed at the top, bottom, left, and right of the panel. The Arduino continuously reads light intensity from each sensor and adjusts two servo motors (vertical and horizontal) to point the panel toward the strongest light source.

- If the **top** LDR reads more light than the **bottom**, the panel tilts upward — and vice versa.
- If the **left** LDR reads more light than the **right**, the panel pans left — and vice versa.
- A **tolerance value** prevents jittering from minor light fluctuations.

## 🔧 Components

| Component        | Quantity |
|------------------|----------|
| Arduino (Uno/Nano) | 1      |
| Servo Motor      | 2        |
| LDR Sensor       | 4        |
| Resistors (10kΩ) | 4        |
| Solar Panel (optional display) | 1 |
| Jumper Wires     | —        |
| Breadboard       | 1        |

## 📐 Wiring

| Sensor / Component | Arduino Pin |
|--------------------|-------------|
| Top LDR            | A0          |
| Right LDR          | A1          |
| Bottom LDR         | A2          |
| Left LDR           | A3          |
| Vertical Servo     | Pin 10      |
| Horizontal Servo   | Pin 9       |

## 🚀 Getting Started

1. Clone this repository:
   ```bash
   git clone https://github.com/YOUR_USERNAME/Solar_Tracker.git
   ```
2. Open `Solar_Tracker.ino` in the [Arduino IDE](https://www.arduino.cc/en/software).
3. Connect your components according to the wiring table above.
4. Upload the sketch to your Arduino board.
5. Open the Serial Monitor at **9600 baud** to view live LDR readings.

## ⚙️ Configuration

You can tune these values in the code:

```cpp
int tolerance = 30;   // Increase to reduce sensitivity / jitter
int vertPos   = 90;   // Starting vertical angle
int horzPos   = 90;   // Starting horizontal angle
```

## 📊 Serial Output

The sketch prints live sensor values to the Serial Monitor:

```
T:512 B:480 L:390 R:620
T:515 B:478 L:385 R:625
```

`T` = Top, `B` = Bottom, `L` = Left, `R` = Right

## 📄 License

MIT License — feel free to use and modify for your own projects.
