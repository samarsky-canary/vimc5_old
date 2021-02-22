#pragma once
#include <cstdint>

// ��������� �������� ��� - 7 ���, s - ������ ������ ��������
using address = uint16_t;
#pragma pack(push, 1)
struct command2b
{
	uint8_t cop : 7;
	uint8_t   s : 1;
	uint8_t	 r1 : 4;
	uint8_t	 r2 : 4;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct command4b
{
	uint8_t cop : 7;
	uint8_t   s : 1;
	uint8_t	 r1 : 4;	
	uint8_t	 r2 : 4;
	address off;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PSW
{
	address ip;			// ��������� �� ������� �������
	uint8_t of : 1;		// ���� ������������
	uint8_t zf : 1;		// ���� ����
	uint8_t nf : 1;		// ���� �������������� ���������
	uint8_t rez;		// �� ������������
};
#pragma pack(pop)

union b2_instruction	// 2�������� ������
{
	uint16_t su;		// ���� �������� �����������
	int16_t ss;			// ���� �������� ��������
	command2b c2b;		// ���� �������� �������
};

union b4_instruction	// 4�������� ������
{
	uint32_t lu;		// ������� �����������
	int32_t ls;			// ������� ��������
	float f;			// �������
	command4b c4b;		// ���� ������� �������
};

union datas				// ������ ��
{
	uint8_t ByteMem[4];
	uint16_t WordMem[2];
	uint32_t DwordMem;
	b2_instruction b2instr;
	b4_instruction b4instr;
};


union Word				// ��� ������ �����
{
	command2b cmd2;
	command4b cmd4;
	datas	dt;
};

union POH
{
	uint16_t su[8];		// short signed
	int16_t  ss[8];		// short unsigned
	uint32_t iu[4];		// long signed
	int32_t  is[4];		// long unsigned
	float    f [4];		// float
};