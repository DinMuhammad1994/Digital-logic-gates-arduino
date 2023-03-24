

// Define boolean inputs
boolean inA;
boolean inB;

// Define boolean outputs
boolean outXNOR;
boolean outXOR;
boolean outNOR;
boolean outOR;
boolean outNAND;
boolean outAND;

// Define the pushbuttons
int pbA = 4;
int pbB = 5;

// Define the logic output LEDs
int ledXNOR = 6;
int ledXOR = 7;
int ledNOR = 8;
int ledOR = 9;
int ledNAND = 10;
int ledAND = 11;

// Define the logic input LEDs 
int ledA = 12;
int ledB = 13;


void setup() {
  // initialize serial port at 9600 bps:
  Serial.begin(9600);

  // Define pushbuttons as inputs
  pinMode(pbA, INPUT);
  pinMode(pbB, INPUT);

  // Define LEDs as outputs
  pinMode(ledXNOR, OUTPUT);
  pinMode(ledXOR, OUTPUT);
  pinMode(ledNOR, OUTPUT);
  pinMode(ledOR, OUTPUT);
  pinMode(ledNAND, OUTPUT);
  pinMode(ledAND, OUTPUT);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);

}

void loop() {
  // Read the pushbuttons and assign values to input booleans
  inA = digitalRead(pbA);
  inB = digitalRead(pbB);

  // Display the pushbutton inputs on LEDs
  digitalWrite(ledA, inA);
  digitalWrite(ledB, inB);
  
  // Compute the logic outputs
  outXNOR = !(inA ^ inB);
  outXOR = inA ^ inB;
  outNOR = !(inA | inB);
  outOR = inA | inB;
  outNAND = !(inA & inB);
  outAND = inA & inB;

  // Display the results

  Serial.print("IN-- A:");
  Serial.print(inA);
  Serial.print(" B:");
  Serial.print(inB);
  Serial.print(" --- OUT-- AND:");
  Serial.print(outAND);
  Serial.print(" NAND:");
  Serial.print(outNAND);
  Serial.print(" OR:");
  Serial.print(outOR);
  Serial.print(" NOR:");
  Serial.print(outNOR);
  Serial.print(" XOR:");
  Serial.print(outXOR);
  Serial.print(" XNOR:");
  Serial.println(outXNOR); 

  digitalWrite(ledXNOR, outXNOR);
  digitalWrite(ledXOR, outXOR);
  digitalWrite(ledNOR, outNOR);
  digitalWrite(ledOR, outOR);
  digitalWrite(ledNAND, outNAND);
  digitalWrite(ledAND, outAND);

  // Short delay
  delay(50);
   
}
