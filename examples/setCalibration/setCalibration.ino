// ПРИМЕР КАЛИБРОВКИ МОДУЛЯ:                      // * Строки со звёздочкой являются необязательными.
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку   для работы с аппаратной шиной I2C.
#include <iarduino_I2C_pH.h>                      //   Подключаем библиотеку   для работы с pH-метром I2C-flash.
iarduino_I2C_pH sensor(0x09);                     //   Объявляем объект sensor для работы с функциями и методами библиотеки iarduino_I2C_pH, указывая адрес модуля на шине I2C.
                                                  //   Если объявить объект без указания адреса (iarduino_I2C_pH sensor;), то адрес будет найден автоматически.
void setup(){                                     //
     delay(500);                                  // * Ждём завершение переходных процессов связанных с подачей питания.
     Serial.begin(9600);                          //   Инициируем работу с шиной UART для передачи данных в монитор последовательного порта на скорости 9600 бит/сек.
     sensor.begin();                              //   Инициируем работу с pH-метром I2C-flash.
     Serial.print("ОПУСТИТЕ ДАТЧИК В 1 ЖИДКОСТЬ");//
     Serial.print(" (4.00 pH). \r\n");            //
     delay(300000);                               //   Ждём 5 минут.
     sensor.setCalibration(1, 4.00 );             //   Выполняем 1 стадию калибровки указав известную концентрацию 1 жидкости (в примере 4.0 pH ).
     delay(10000);                                //   Ждём 10 секунд.
     Serial.print("СПОЛОСНИТЕ ДАТЧИК.\r\n");      //
     delay(30000);                                //   Ждём 30 секунд.
     Serial.print("ОПУСТИТЕ ДАТЧИК В 2 ЖИДКОСТЬ");//
     Serial.print(" (9.18 ppm). \r\n");           //
     delay(300000);                               //   Ждём 5 минут.
     sensor.setCalibration(2, 9.18 );             //   Выполняем 2 стадию калибровки указав известную концентрацию 2 жидкости (в примере 9.18 pH ).
     delay(10000);                                //   Ждём 10 секунд.
     Serial.print("КАЛИБРОВКА ВЫПОЛНЕНА!\r\n");   //
}                                                 //
                                                  //
void loop(){}                                     //