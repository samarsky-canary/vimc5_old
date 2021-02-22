#pragma once
#include <cstdint>
#include "Typos.h"
#include "Memory.h"

class Processor
{
	POH _poh;
	PSW _psw;
	address PC;		// ������� ������ �������
	address RI;		// ������� ������ ������� ����������
	Memory _mem;	// RAM ������
};