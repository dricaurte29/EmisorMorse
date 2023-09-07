
int buzzerPin = 8;

// Arreglo de palabras
String palabras[] = {"coco","rey","gato","ieee","flor","oro","sol","luz","mar","rama"};
String palabra;
// Alfabeto y números en código Morse
String morseAlphabet[] = {
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--..", // Z
  "-----", // 0
  ".----", // 1
  "..---", // 2
  "...--", // 3
  "....-", // 4
  ".....", // 5
  "-....", // 6
  "--...", // 7
  "---..", // 8
  "----."  // 9
};

void setup() {
  
  pinMode(buzzerPin, OUTPUT);
  pinMode(13,OUTPUT);
  randomSeed(analogRead(0)); 
  int randomIndex = random(0, sizeof(palabras) / sizeof(palabras[0]));
  palabra = palabras[randomIndex];
  Serial.begin(9600);
}

void loop() {
  


  
  palabra.toUpperCase();

  
  Serial.print("Palabra: ");
  Serial.println(palabra);

  
  emitMorseWord(palabra);

  
  delay(2000);
}

void emitMorseWord(String word) {
  for (int i = 0; i < word.length(); i++) {
    char c = word.charAt(i);

    if (c == ' ') {
      // Espacio entre palabras
      delay(2000);
    } else {
      
      int index = -1;
      if (c >= 'A' && c <= 'Z') {
        
        index = c - 'A';
      } else if (c >= '0' && c <= '9') {
        
        index = c - '0' + 26;
      }

      if (index >= 0 && index < sizeof(morseAlphabet) / sizeof(morseAlphabet[0])) {
        String morseCode = morseAlphabet[index];
        emitMorseCode(morseCode);
      }
    }
  }
}

void emitMorseCode(String code) {
  for (int i = 0; i < code.length(); i++) {
    char c = code.charAt(i);
    if (c == '.') {
      // Emitir un corto pitido
      tone(buzzerPin, 1000);
      digitalWrite(13,HIGH);
      delay(170);
      digitalWrite(13,LOW);
      noTone(buzzerPin);
      delay(200);
    } else if (c == '-') {
      // Emitir un pitido largo
      tone(buzzerPin, 1000);
      digitalWrite(13,HIGH);
      delay(800);
      digitalWrite(13,LOW);
      noTone(buzzerPin);
      delay(200);
    }
  }
  // Espacio entre caracteres
  delay(1500);
}
