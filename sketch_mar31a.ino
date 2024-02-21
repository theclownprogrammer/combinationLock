#include <Keypad.h> // подключаем библиотеку для управление клавиатурой
#include <Servo.h>

const byte ROWS = 4; //число строк у нашей клавиатуры
const byte COLS = 4; //число столбцов у нашей клавиатуры
char hexaKeys[ROWS][COLS] = {// здесь мы располагаем названия наших клавиш, как на клавиатуре,для удобства пользования
{'1','4','7','*'},
{'2','5','8','0'},
{'3','6','9','#'},
{'A','E','L','D'}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; //к каким выводам подключаем управление строками
byte colPins[COLS] = {9, 8, 7, 6}; //к каким выводам подключаем управление столбцами

//передаем все эти данные библиотеке:
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

const int speakerPin = 10;

const int GPin = 12;
const int RPin = 13;

// Пин, к которому подключено сервопривод
const int servoPin = 11;
Servo lockServo;

// Пароль для открытия замка
const String password = "050404";
const String DEAL = "DEAL";

String enteredPassword = "";


void setup(){
  // Настройка сервопривода
  lockServo.attach(servoPin);
  Serial.begin(9600);//запускаем отладочный вывод в монитор порта
  // Установка пина динамика в режим OUTPUT
  pinMode(speakerPin, OUTPUT);
}

void loop(){
char customKey = customKeypad.getKey();//записывем нажатый символ

if (customKey){//если что-то нажато
   if (customKey == '#') { // Если нажата клавиша "#"
      // Проверка введенного пароля
      if (checkPassword()) {
        enteredPassword = "";
        digitalWrite(GPin, HIGH);
        tone(speakerPin, 1700);  
  delay(1500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin);
  unlock(); // Открытие замка
  delay(2000); // Задержка на 2 секунды
  lock();
  digitalWrite(GPin, LOW);
  return;
      } else {

        
        if (checkDEAL()) {
        enteredPassword = "";
        melody();
  return;
      } else {
        enteredPassword = "";
        // Неправильный пароль
        Serial.println("Неправильный пароль");
        digitalWrite(RPin, HIGH);
        tone(speakerPin, 500);  
  delay(1500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin);
  digitalWrite(RPin, LOW);
  return;
      
        enteredPassword = "";
        // Неправильный пароль
        Serial.println("Неправильный пароль");
        digitalWrite(RPin, HIGH);
        tone(speakerPin, 500);  
  delay(1500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin);
  digitalWrite(RPin, LOW);
  return;
      }
      }
    }
  enteredPassword = enteredPassword + customKey;
  Serial.println(customKey);
  Serial.println(enteredPassword);
  if(customKey == '1')
  {
    tone(speakerPin, 1000);  
  delay(500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin);
  }
  if(customKey == '2')
  {
    tone(speakerPin, 950); 
  delay(500);             
  
  // Отключение звукового сигнала
  noTone(speakerPin); 
  }
  if(customKey == '3')
  {
    tone(speakerPin, 900);  
  delay(500);             
  
  // Отключение звукового сигнала
  noTone(speakerPin);
  }
  if(customKey == '4')
  {
    tone(speakerPin, 850);  
  delay(500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin);
  }
  if(customKey == '5')
  {
    tone(speakerPin, 800);  
  delay(500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin); 
  }
  if(customKey == '6')
  {
    tone(speakerPin, 750);  
  delay(500);             
  
  // Отключение звукового сигнала
  noTone(speakerPin); 
  }
  if(customKey == '7')
  {
    tone(speakerPin, 700);  
  delay(500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin);
  }
  if(customKey == '8')
  {
    tone(speakerPin, 650);  
  delay(500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin); 
  }
  if(customKey == '9')
  {
    tone(speakerPin, 600); 
  delay(500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin); 
  }
  if(customKey == '*')
  {
    tone(speakerPin, 550);  
  delay(500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin); 
  }
  if(customKey == '0')
  {
    tone(speakerPin, 500);  
  delay(500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin); 
  }
  if(customKey == '#')
  {
    tone(speakerPin, 450); 
  delay(500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin); 
  }
  if(customKey == 'D')
  {
    tone(speakerPin, 400);  
  delay(500);              
  
  // Отключение звукового сигнала
  noTone(speakerPin);
  }
  if(customKey == 'L')
  {
    tone(speakerPin, 350);  
  delay(500);             
  
  // Отключение звукового сигнала
  noTone(speakerPin);
  }
  if(customKey == 'E')
  {
    tone(speakerPin, 300);  
  delay(500);             
  
  // Отключение звукового сигнала
  noTone(speakerPin); 
  }
  if(customKey == 'A')
  {
    tone(speakerPin, 250);  
  delay(500);             
  
  // Отключение звукового сигнала
  noTone(speakerPin);
  }
}

}



bool checkPassword() {
  // Сравнение введенного пароля с заданным паролем
  if (enteredPassword == password) {
    return true; // Пароль верный
  } else {
    return false; // Пароль неверный
  }
}

bool checkDEAL() {
  // Сравнение введенного пароля с заданным паролем
  if (enteredPassword == DEAL) {
    return true; // Пароль верный
  } else {
    return false; // Пароль неверный
  }
}

void melody(){
  lockServo.write(0);
  delay(100);
  lockServo.write(90);
  delay(100);
  lockServo.write(0);
  delay(100);
  lockServo.write(90);
  delay(100);
  lockServo.write(0);
  delay(100);
  lockServo.write(0);
  delay(100);
  lockServo.write(90);
  delay(100);
  lockServo.write(0);
  delay(100);
  lockServo.write(90);
  delay(100);
  lockServo.write(0);
  delay(100);
  lockServo.write(180);
  delay(100);
  lockServo.write(0);
  delay(100);
  lockServo.write(180);
  delay(100);
  lockServo.write(0);
  delay(100);
  lockServo.write(180);
  delay(100);
  lockServo.write(0);
  delay(100);
  lockServo.write(180);
  delay(100);
  lockServo.write(0);
  delay(100);
  lockServo.write(270);
  delay(100);
  lockServo.write(0);
  delay(100);
  lockServo.write(270);
  delay(100);
  lockServo.write(270);
  delay(100);
  lockServo.write(0);
  delay(100);
  lockServo.write(270);
  delay(100);
  //1 такт
  tone(speakerPin, 554);   //ДО ДИЕЗ
  delay(600);
  tone(speakerPin, 831);   //СОЛЬ ДИЕЗ
  delay(300);
  noTone(speakerPin);
  delay(300);
  tone(speakerPin, 831);
  delay(600);
  noTone(speakerPin);
  delay(600);
  //2 такт
  tone(speakerPin, 831);
  delay(150);
  tone(speakerPin, 988);   //СИ
  delay(150);
  tone(speakerPin, 784);   //СОЛЬ
  delay(150);
  tone(speakerPin, 659);   //МИ
  delay(150);
  tone(speakerPin, 554);
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 659);
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 988);
  delay(600);
  noTone(speakerPin);
  delay(600);
  // 3 такт
  tone(speakerPin, 554);   //ДО ДИЕЗ
  delay(600);
  tone(speakerPin, 831);   //СОЛЬ ДИЕЗ
  delay(300);
  noTone(speakerPin);
  delay(300);
  tone(speakerPin, 831);
  delay(600);
  noTone(speakerPin);
  delay(600);
  //4 такт
  tone(speakerPin, 784);   //СОЛЬ
  delay(300);
  tone(speakerPin, 831);   //СОЛЬ ДИЕЗ
  delay(300);
  tone(speakerPin, 784);   //СОЛЬ
  delay(150);
  tone(speakerPin, 659);   //МИ
  delay(150);
  tone(speakerPin, 554);   //ДО ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 659);   //МИ
  delay(300);
  noTone(speakerPin);
  noTone(speakerPin);
  tone(speakerPin, 740);   //ФА ДИЕЗ
  delay(600);
  noTone(speakerPin);
  delay(600);
  //5 такт
  tone(speakerPin, 554);   //ДО ДИЕЗ
  delay(600);
  tone(speakerPin, 831);   //СОЛЬ ДИЕЗ
  delay(300);
  noTone(speakerPin);
  delay(300);
  tone(speakerPin, 831);
  delay(600);
  noTone(speakerPin);
  delay(600);
  //6 такт
  tone(speakerPin, 831);
  delay(150);
  tone(speakerPin, 988);   //СИ
  delay(150);
  tone(speakerPin, 784);   //СОЛЬ
  delay(150);
  tone(speakerPin, 659);   //МИ
  delay(150);
  tone(speakerPin, 554);
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 659);
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 988);
  delay(600);
  noTone(speakerPin);
  delay(600);
  //7 такт
  tone(speakerPin, 554);   //ДО ДИЕЗ
  delay(600);
  tone(speakerPin, 831);   //СОЛЬ ДИЕЗ
  delay(300);
  noTone(speakerPin);
  delay(300);
  tone(speakerPin, 831);
  delay(600);
  noTone(speakerPin);
  delay(600);
  //8 такт
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 880);   //ЛЯ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 880);   //ЛЯ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 880);   //ЛЯ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 880);   //ЛЯ
  delay(300);
  noTone(speakerPin);
  //9 такт
  tone(speakerPin, 554);   //ДО ДИЕЗ
  delay(600);
  tone(speakerPin, 831);   //СОЛЬ ДИЕЗ
  delay(300);
  noTone(speakerPin);
  delay(300);
  tone(speakerPin, 831);
  delay(600);
  noTone(speakerPin);
  delay(600);
  //10 takt
  tone(speakerPin, 831);
  delay(150);
  tone(speakerPin, 988);   //СИ
  delay(150);
  tone(speakerPin, 784);   //СОЛЬ
  delay(150);
  tone(speakerPin, 659);   //МИ
  delay(150);
  tone(speakerPin, 554);
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 659);
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 988);
  delay(600);
  noTone(speakerPin);
  delay(600);
  //11 takt
  tone(speakerPin, 554);   //ДО ДИЕЗ
  delay(600);
  tone(speakerPin, 831);   //СОЛЬ ДИЕЗ
  delay(300);
  noTone(speakerPin);
  delay(300);
  tone(speakerPin, 831);
  delay(600);
  noTone(speakerPin);
  delay(600);
  //12 takt
  tone(speakerPin, 784);   //СОЛЬ
  delay(300);
  tone(speakerPin, 831);   //СОЛЬ ДИЕЗ
  delay(300);
  tone(speakerPin, 784);   //СОЛЬ
  delay(150);
  tone(speakerPin, 659);   //МИ
  delay(150);
  tone(speakerPin, 554);   //ДО ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 659);   //МИ
  delay(300);
  noTone(speakerPin);
  noTone(speakerPin);
  tone(speakerPin, 740);   //ФА ДИЕЗ
  delay(600);
  noTone(speakerPin);
  delay(600);
  //13 такт
  tone(speakerPin, 554);   //ДО ДИЕЗ
  delay(600);
  tone(speakerPin, 831);   //СОЛЬ ДИЕЗ
  delay(300);
  noTone(speakerPin);
  delay(300);
  tone(speakerPin, 831);
  delay(600);
  noTone(speakerPin);
  delay(600);
  //14 takt
  tone(speakerPin, 831);
  delay(150);
  tone(speakerPin, 988);   //СИ
  delay(150);
  tone(speakerPin, 784);   //СОЛЬ
  delay(150);
  tone(speakerPin, 659);   //МИ
  delay(150);
  tone(speakerPin, 554);
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 659);
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 988);
  delay(600);
  noTone(speakerPin);
  delay(600);
  //15 takt
  tone(speakerPin, 554);   //ДО ДИЕЗ
  delay(600);
  tone(speakerPin, 831);   //СОЛЬ ДИЕЗ
  delay(300);
  noTone(speakerPin);
  delay(300);
  tone(speakerPin, 831);
  delay(600);
  noTone(speakerPin);
  delay(600);
  //16 takt
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(100);
  tone(speakerPin, 659);
  delay(100);
  tone(speakerPin, 932);    //ЛЯ ДИЕЗ
  delay(100);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(100);
  tone(speakerPin, 659);
  delay(100);
  tone(speakerPin, 932);    //ЛЯ ДИЕЗ
  delay(100);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(100);
  tone(speakerPin, 659);
  delay(100);
  tone(speakerPin, 932);    //ЛЯ ДИЕЗ
  delay(100);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(100);
  tone(speakerPin, 659);
  delay(100);
  tone(speakerPin, 932);    //ЛЯ ДИЕЗ
  delay(100);
  noTone(speakerPin);
  tone(speakerPin, 880);   //ЛЯ
  delay(100);
  tone(speakerPin, 740);   //ФА ДИЕЗ
  delay(100);
  tone(speakerPin, 523);   //ДО
  delay(100);
  noTone(speakerPin);
  tone(speakerPin, 880);   //ЛЯ
  delay(100);
  tone(speakerPin, 740);   //ФА ДИЕЗ
  delay(100);
  tone(speakerPin, 523);   //ДО
  delay(100);
  noTone(speakerPin);
  tone(speakerPin, 880);   //ЛЯ
  delay(100);
  tone(speakerPin, 740);   //ФА ДИЕЗ
  delay(100);
  tone(speakerPin, 523);   //ДО
  delay(100);
  noTone(speakerPin);
  tone(speakerPin, 880);   //ЛЯ
  delay(100);
  tone(speakerPin, 740);   //ФА ДИЕЗ
  delay(100);
  tone(speakerPin, 523);   //ДО
  delay(100);
  noTone(speakerPin);
  //17 takt i vsya stroka
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  tone(speakerPin, 1319);   //МИ6
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1319);   //МИ6
  delay(600);
  tone(speakerPin, 1480);   //ФА6 ДИЕЗ
  delay(600);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1568);   //СОЛЬ6
  delay(600);
  tone(speakerPin, 1319);   //МИ6
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1319);   //МИ6
  delay(600);
  tone(speakerPin, 1480);   //ФА6 ДИЕЗ
  delay(600);
  //21 takt i vsya stroka
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  tone(speakerPin, 1319);   //МИ6
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1319);   //МИ6
  delay(300);
  tone(speakerPin, 1480);   //ФА6 ДИЕЗ
  delay(600);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 988);   //СИ
  delay(600);
  tone(speakerPin, 1040);   //СИ ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1040);   //СИ ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  //25 takt i vsya stroka
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  tone(speakerPin, 1319);   //МИ6
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1319);   //МИ6
  delay(600);
  tone(speakerPin, 1480);   //ФА6 ДИЕЗ
  delay(600);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1568);   //СОЛЬ6
  delay(600);
  tone(speakerPin, 1319);   //МИ6
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1319);   //МИ6
  delay(600);
  tone(speakerPin, 1480);   //ФА6 ДИЕЗ
  delay(600);
  //29 takt i vsya stroka
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  tone(speakerPin, 1319);   //МИ6
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1319);   //МИ6
  delay(300);
  tone(speakerPin, 1480);   //ФА6 ДИЕЗ
  delay(600);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 988);   //СИ
  delay(600);
  tone(speakerPin, 1040);   //СИ ДИЕЗ
  delay(300);
  noTone(speakerPin);
  tone(speakerPin, 1040);   //СИ ДИЕЗ
  delay(600);
  noTone(speakerPin);
  tone(speakerPin, 1109);   //ДО6 ДИЕЗ
  delay(600);
  noTone(speakerPin);
  }


// Функция для открытия замка
void unlock() {
  lockServo.write(0); // Поворот сервопривода для открытия замка
}

void lock(){
  lockServo.write(90); // Поворот сервопривода для закрытия замка
}
