/* --- string.h ------------------------------------------------------------------------------------------- **
 *  
 * -------------------------------------------------------------------------------------------------------- */
#ifndef _STRING_H_
  #define _STRING_H_

  #define StrInitialData        "*********** Исходные  данные ***********\n"
  #define StrEntLowFl           "Введите нижний этаж"
  #define StrEntHighFl          "Введите верхний этаж"

  #define StrLiftParam          "\n******** Хараткеристики лифта ********\n"
  #define StrTotalFl            "Число обслуживаемых этажей: %d\n"
  #define StrRangeFl            "Диапазон обслуживаемых этажей: %d...%d\n"

  #define StrStartCond          "\n********* Начальные  условия *********\n"
  #define StrCurrFl             "Лифт находится на %dм этаже\n"
  #define StrLiftEmp            "Пассажиров нет\n"

  #define StrCmd1               "\n******** Команды упроавления *********\n"
  #define StrCmd2               "Fxx - вызов лифта на xx-этаже\n"
  #define StrCmd3               "Cyy - нажатие кнопки yy-этажа в лифте\n"
  #define StrCmd4               "X   - выход из программы\n"

  #define StrStart              "\n*********** Начало работы ************\n"

  #define StrErrCmd             "<<Неверная команда\n"
  #define StrErrFloor           "<<Данный этаж лифтом не обслуживается\n"
  #define StrOnSameFloor        "<<Лифт уже на данном этаже\n"
  #define StrFlAlreadyAdd       "<<Данный этаж уже есть в очереди\n"
  #define StrFloorCall          "<<Вызов лифта на %d-м этаже (Floor %d)\n"
  #define StrCabinCall          "<<Человек в лифте нажал кнопку %d-го этажа (Cabin %d)\n"
  #define StrEnterCabinCall     "<<Человек зашел в лифт и нажал кнопку %d-го этажа (Cabin %d)\n"

  #define StrCabinOnFloor       "Cabin on floor %d. "
  #define StrGoingUp            "Going up. "
  #define StrGoingDown          "Going down. "
  #define StrPressAnyKey        "<Press any key to enter new command>\n"
  #define StrStopped            "Stopped. "
  #define StrDoorsOpened        "Doors opened "
  #define StrDoorsClosed        "Doors closed\n"
  #define StrFloorStopOpened    "Cabin on floor %d. Stopped. Doors opened\n"

#endif // _STRING_H_
/* --------------------------------------------( end of file )--------------------------------------------- */

