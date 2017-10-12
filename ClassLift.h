/* --- lift.h --------------------------------------------------------------------------------------------- **
 *  
 * -------------------------------------------------------------------------------------------------------- */
#ifndef _LIFT_H_
  #define _LIFT_H_

#include <ctime>

/* -------------------------------------------------------------------------------------------------------- **
 *  Определения
 * -------------------------------------------------------------------------------------------------------- */
#define MinFloor		-99		// Минимальное значение этажа
#define MaxFloor		99		// Максимальное значение этажа
#define LiftSpeed		1		// Скорость движения лифта, этажей/секунду
#define OpenDoorTime	5		// Время стоянки с открытыми дверями

/* -------------------------------------------------------------------------------------------------------- **
 *  Типы данных
 * -------------------------------------------------------------------------------------------------------- */
typedef enum
{ LiftUn = 0,	// Не определено
  LiftUp,		// Вверх
  LiftDown		// Вниз
} TLiftDir;		// Направление движения лифта

typedef enum
{ LiftStop = 0,	// Лифт остановлен, двери закрыты
  LiftOpen,		// Лифт остановлен, двери открыты
  LiftMove,		// Лифт двигается
} TLiftState;	// Текущее состояние лифта

typedef enum
{ FlOnly = 0,	// Проверка только попадания в диапазон существующих этажей
  FlCall,		// Проверка допустимости вызова этажа
  FlMove		// Проверка возможности перемещения к данному этажу
} TTypeCheck;	// Проверка корректности этажа

class TLift
{ 
public:
  TLift(int Min, int Max);
  ~TLift();
  ShowInfo();
  ShowStatus();
  void Action();
  bool AddFloorCall(int Floor);
  bool AddCabinCall(int Floor);
  
private:
  bool RemoveFloorCall(int Floor);
  bool RemoveCabinCall(int Floor);
  bool AddToList(int Floor, int *Queue, int *Cnt);
  bool RemoveFromList(int Floor, int *Queue, int *Cnt);
  int FindInList(int Floor, int *Queue, int Cnt);
  bool CheckFloor(int Floor, TTypeCheck type);
  bool CheckCalls(int Floor);
  ResetOpenDoorTimer();
  bool CheckDoorTimeout();
  TLiftDir SelectDirection(int Floor, TLiftDir CurDir);
  TLiftDir CheckDirection(int Floor, TLiftDir CurDir, int *List, int Cnt);

  int HiFloor;			// Верхний этаж
  int LowFloor;			// Нижний этаж
  int CurrFloor;		// Текущий этаж
  int TotalFloor;		// Общее кол-во этажей
  
  int *ListFloorCall;	// Список вызовов с этажей
  int CntFloorCall;		// Количество вызовов с этажей
  
  int *ListCabinCall;	// Список вызовов из кабины лифта
  int CntCabinCall;		// Количество вызовов из кабыны лифта
  
  int LiftState;		// Текущее состояние лифта 
  TLiftDir LiftDir;		// Направление движения лифта
  clock_t OpenDoorTimer;	// Время простоя с открытыми дверями
};

/* -------------------------------------------------------------------------------------------------------- **
 *  Глобальные данные
 * -------------------------------------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------------------------------------- **
 *  Прототипы функций
 * -------------------------------------------------------------------------------------------------------- */

#endif // _LIFT_H_
/* --------------------------------------------( end of file )--------------------------------------------- */

