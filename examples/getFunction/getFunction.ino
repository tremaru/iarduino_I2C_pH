// ПРИМЕР ПОЛУЧЕНИЯ И ВЫЧИСЛЕНИЯ ДАННЫХ:          // * Строки со звёздочкой являются необязательными.
                                                  //
#include <Wire.h>                                 // * Подключаем библиотеку   для работы с аппаратной шиной I2C.
#include <iarduino_I2C_pH.h>                      //   Подключаем библиотеку   для работы с pH-метром I2C-flash.
iarduino_I2C_pH sensor(0x09);                     //   Объявляем объект sensor для работы с функциями и методами библиотеки iarduino_I2C_pH, указывая адрес модуля на шине I2C.
                                                  //   Если объявить объект без указания адреса (iarduino_I2C_pH sensor;), то адрес будет найден автоматически.
void setup(){                                     //
     delay(500);                                  // * Ждём завершение переходных процессов связанных с подачей питания.
     Serial.begin(9600);                          //   Инициируем работу с шиной UART для передачи данных в монитор последовательного порта на скорости 9600 бит/сек.
     sensor.begin();                              //   Инициируем работу с pH-метром I2C-flash.
}                                                 //
                                                  //
void loop(){                                      //
     Serial.print("Кислотность = pHn+"      );    //
     Serial.print("( Vn -Vout)/( Vstep *Ky)");    //
     Serial.print("\r\n            = "      );    //
     Serial.print(sensor.getPHn()        , 1);    //
     Serial.print("+("                      );    //
     Serial.print(sensor.getVn()         , 2);    //
     Serial.print("-"                       );    //
     Serial.print(sensor.getVout()       , 2);    //
     Serial.print(")/("                     );    //
     Serial.print(sensor.getVstp()/1000  , 5);    //
     Serial.print("* "                      );    //
     Serial.print(sensor.getKy()         , 0);    //
     Serial.print(") = "                    );    //
     Serial.print(sensor.getPH()         , 1);    //
     Serial.print(" pH.\r\n"                );    //
     delay(1000);                                 //
}                                                 //