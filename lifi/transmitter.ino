#define LED_PIN 7
#define PERIOD 14
const char *string = "Kedar Suman";
int string_length;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  int string_length = strlen(string);
  Serial.println();
}

void loop() {
   for(int i = 0; i < 46; i++)
   {

    send_byte(string[i]);
   }
   delay(100);
}

void send_byte(char my_byte){
  Serial.print(my_byte);
  digitalWrite(LED_PIN, LOW);
  delay(PERIOD);

  uint8_t bin;
  Serial.print("  ");
  for(int i = 0; i < 8; i++){
    int led_state = bitRead(my_byte, i);
    Serial.print(led_state);
    digitalWrite(LED_PIN, led_state != 0);
    delay(PERIOD);
  }
  Serial.println();
  digitalWrite(LED_PIN, HIGH);
  delay(PERIOD);
}