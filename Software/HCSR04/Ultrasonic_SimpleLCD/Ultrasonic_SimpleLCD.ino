// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
#include <LiquidCrystal.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 800 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
LiquidCrystal lcd(8, 7, 6, 5, 4, 3); // Initialize the library with the numbers of the interface pins

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  lcd.begin(16, 2); // Set up the LCD's number of columns and rows
}

void loop() {
  delay(500);                      // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance and print result (0 = outside set distance range, no ping echo)
  Serial.println("cm");
  lcd.setCursor(0, 0);
  lcd.print("Ping: ");
  lcd.print(uS / US_ROUNDTRIP_CM);
  lcd.print("cm   ");
}