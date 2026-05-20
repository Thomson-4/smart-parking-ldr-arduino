/*
 * Smart Parking System in Malls using LDR
 *
 * Detects vehicle presence using Light Dependent Resistors (LDRs).
 * When a car parks over an LDR, it blocks the light — resistance rises,
 * analog value drops. Arduino detects this and lights the Red LED (occupied).
 * Green LED lights when the slot is free.
 *
 * 4 parking slots, each with: LDR (analog) + Red LED + Green LED
 */

// ── Pin Configuration ────────────────────────────────────────────────────────

const int LDR_PINS[4]   = {A0, A1, A2, A3};  // LDR sensors (one per slot)
const int RED_PINS[4]   = {2, 4, 6, 8};       // Red LEDs   (occupied)
const int GREEN_PINS[4] = {3, 5, 7, 9};       // Green LEDs (available)

// ── Threshold ────────────────────────────────────────────────────────────────
//
// LDR in open light  → high analog value (~700–900)
// LDR blocked by car → low analog value  (~50–300)
//
// Calibrate this value based on your lighting conditions.
// If a slot is always shown as occupied, raise the threshold.
// If it never detects cars, lower it.

const int THRESHOLD = 400;

// ── Setup ────────────────────────────────────────────────────────────────────

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(RED_PINS[i],   OUTPUT);
    pinMode(GREEN_PINS[i], OUTPUT);
  }

  Serial.println("=== SMART PARKING SYSTEM ===");
  Serial.println("Monitoring 4 parking slots...");
  Serial.println("-------------------------------");
}

// ── Main Loop ────────────────────────────────────────────────────────────────

void loop() {
  int available = 0;

  for (int i = 0; i < 4; i++) {
    int ldrValue = analogRead(LDR_PINS[i]);
    bool occupied = (ldrValue < THRESHOLD);

    if (occupied) {
      digitalWrite(RED_PINS[i],   HIGH);
      digitalWrite(GREEN_PINS[i], LOW);
    } else {
      digitalWrite(RED_PINS[i],   LOW);
      digitalWrite(GREEN_PINS[i], HIGH);
      available++;
    }

    Serial.print("Slot ");
    Serial.print(i + 1);
    Serial.print(": LDR = ");
    Serial.print(ldrValue);
    Serial.print("  →  ");
    Serial.println(occupied ? "OCCUPIED  [RED]" : "AVAILABLE [GREEN]");
  }

  Serial.println("-------------------------------");
  Serial.print("Available: ");
  Serial.print(available);
  Serial.print(" / 4    Occupied: ");
  Serial.println(4 - available);
  Serial.println("===============================");
  Serial.println();

  delay(1000);
}
