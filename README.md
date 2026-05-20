# Smart Parking System in Malls using LDR

An **Arduino-based IoT project** that detects real-time parking slot availability in malls using **Light Dependent Resistors (LDRs)**. Each slot shows a **Green LED** when available and a **Red LED** when occupied.

---

## How It Works

1. Each parking slot has an **LDR sensor** embedded in the ground
2. In an empty slot — ambient light hits the LDR → **low resistance** → high analog value
3. When a car parks — it **blocks the light** reaching the LDR → resistance rises → analog value drops
4. The Arduino reads this change and:
   - Analog value **below threshold** → slot **Occupied** → Red LED ON
   - Analog value **above threshold** → slot **Available** → Green LED ON
5. Real-time slot count is printed to the **Serial Monitor**

---

## Components Required

| Component | Quantity | Purpose |
|-----------|----------|---------|
| Arduino Uno | 1 | Microcontroller — reads sensors and controls LEDs |
| LDR (Photoresistor) | 4 | Detects vehicle presence via light blocking |
| 10kΩ Resistor | 4 | Pull-down resistors for LDR voltage divider |
| Red LED | 4 | Indicates occupied slot |
| Green LED | 4 | Indicates available slot |
| 220Ω Resistor | 8 | Current limiting for LEDs |
| Breadboard | 1 | Prototyping connections |
| Jumper Wires | Several | Component connections |
| USB Cable (Type-B) | 1 | Upload code and power Arduino |

---

## Pin Connections

### LDR Sensors (Analog Input)

Each LDR is wired as a **voltage divider** with a 10kΩ pull-down resistor:
- One leg of LDR → **5V**
- Other leg → Arduino Analog Pin AND → 10kΩ → **GND**

| Slot | LDR Pin |
|------|---------|
| Slot 1 | A0 |
| Slot 2 | A1 |
| Slot 3 | A2 |
| Slot 4 | A3 |

### LED Indicators (Digital Output)

| Slot | Red LED (Occupied) | Green LED (Available) |
|------|-------------------|----------------------|
| Slot 1 | Pin 2 | Pin 3 |
| Slot 2 | Pin 4 | Pin 5 |
| Slot 3 | Pin 6 | Pin 7 |
| Slot 4 | Pin 8 | Pin 9 |

Connect each LED with a **220Ω resistor** in series to GND.

---

## Circuit Logic

```
LDR (in daylight)     → High analog value (700–900)  → Available → Green LED
LDR (car on top)      → Low analog value  (50–300)   → Occupied  → Red LED
```

The threshold is set to `400` by default. Adjust it in the code based on your lighting conditions:

```cpp
const int THRESHOLD = 400;
```

- Too many false "occupied" readings → **raise** the threshold
- Car not being detected → **lower** the threshold

---

## Files

| File | Description |
|------|-------------|
| `Smart_Parking_LDR.ino` | Main Arduino sketch — reads LDRs, controls LEDs, prints to Serial Monitor |

---

## Steps to Run

### Step 1 — Wire the circuit
Connect LDRs (with 10kΩ pull-down to GND) to analog pins A0–A3.  
Connect Red LEDs (with 220Ω resistors) to pins 2, 4, 6, 8.  
Connect Green LEDs (with 220Ω resistors) to pins 3, 5, 7, 9.

### Step 2 — Upload the code
1. Open **Arduino IDE**
2. Open `Smart_Parking_LDR.ino`
3. Select **Tools → Board → Arduino Uno**
4. Select the correct **Port** under `Tools → Port`
5. Click **Upload** (→)

### Step 3 — Calibrate the threshold
1. Open **Serial Monitor** (`Tools → Serial Monitor`) — set baud rate to `9600`
2. Observe LDR values for empty slots (typically 700–900)
3. Cover an LDR with your hand (simulate a car) — observe the value drop (typically 50–300)
4. Set `THRESHOLD` in the code to a value between these two ranges (default: 400)

### Step 4 — Test
- Place an object over any LDR → Red LED turns ON
- Remove the object → Green LED turns ON
- Serial Monitor shows live slot status and count

---

## Serial Monitor Output

```
=== SMART PARKING SYSTEM ===
Monitoring 4 parking slots...
-------------------------------
Slot 1: LDR = 820  →  AVAILABLE [GREEN]
Slot 2: LDR = 134  →  OCCUPIED  [RED]
Slot 3: LDR = 795  →  AVAILABLE [GREEN]
Slot 4: LDR = 811  →  AVAILABLE [GREEN]
-------------------------------
Available: 3 / 4    Occupied: 1
===============================
```

---

## Academic Details

- **Institution:** REVA University, Bengaluru
- **Course:** IoT and Applications
- **Academic Year:** 2023–24
- **Semester:** 2nd

---

## Authors

**Shyam Sundar** (R23EF257)  
**Suhil Prasanth** (R23EF266)  
**Thomson Sunny** (R23EF284)  
**Sujal Patil** (R23EF267)

GitHub: [@Thomson-4](https://github.com/Thomson-4)
