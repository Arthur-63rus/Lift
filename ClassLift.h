/* --- lift.h --------------------------------------------------------------------------------------------- **
 *  
 * -------------------------------------------------------------------------------------------------------- */
#ifndef _LIFT_H_
  #define _LIFT_H_

#include <ctime>

/* -------------------------------------------------------------------------------------------------------- **
 *  �����������
 * -------------------------------------------------------------------------------------------------------- */
#define MinFloor		-99		// ����������� �������� �����
#define MaxFloor		99		// ������������ �������� �����
#define LiftSpeed		1		// �������� �������� �����, ������/�������
#define OpenDoorTime	5		// ����� ������� � ��������� �������

/* -------------------------------------------------------------------------------------------------------- **
 *  ���� ������
 * -------------------------------------------------------------------------------------------------------- */
typedef enum
{ LiftUn = 0,	// �� ����������
  LiftUp,		// �����
  LiftDown		// ����
} TLiftDir;		// ����������� �������� �����

typedef enum
{ LiftStop = 0,	// ���� ����������, ����� �������
  LiftOpen,		// ���� ����������, ����� �������
  LiftMove,		// ���� ���������
} TLiftState;	// ������� ��������� �����

typedef enum
{ FlOnly = 0,	// �������� ������ ��������� � �������� ������������ ������
  FlCall,		// �������� ������������ ������ �����
  FlMove		// �������� ����������� ����������� � ������� �����
} TTypeCheck;	// �������� ������������ �����

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

  int HiFloor;			// ������� ����
  int LowFloor;			// ������ ����
  int CurrFloor;		// ������� ����
  int TotalFloor;		// ����� ���-�� ������
  
  int *ListFloorCall;	// ������ ������� � ������
  int CntFloorCall;		// ���������� ������� � ������
  
  int *ListCabinCall;	// ������ ������� �� ������ �����
  int CntCabinCall;		// ���������� ������� �� ������ �����
  
  int LiftState;		// ������� ��������� ����� 
  TLiftDir LiftDir;		// ����������� �������� �����
  clock_t OpenDoorTimer;	// ����� ������� � ��������� �������
};

/* -------------------------------------------------------------------------------------------------------- **
 *  ���������� ������
 * -------------------------------------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------------------------------------- **
 *  ��������� �������
 * -------------------------------------------------------------------------------------------------------- */

#endif // _LIFT_H_
/* --------------------------------------------( end of file )--------------------------------------------- */

