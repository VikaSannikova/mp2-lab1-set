// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// tbitfield.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (19.04.2015)
//
// Битовое поле
 
//куку




#include "tbitfield.h"

TBitField::TBitField(int len)
{

}

TBitField::TBitField(const TBitField &bf) // конструктор копирования (инициализатор???)
{
	BitLen = bf.BitLen;  //внутренней переменной присваиваем значение битового поля максимальнойдлины
	MemLen = bf.MemLen;  //кол-во элементов для предоставления битового поля
	pMem = new TELEM[MemLen];  //выделение памяти под битовое поле
	for (int i = 0; i < MemLen; i++)
		pMem[i] = bf.pMem[i]; //копируем элементы из вводимого числа в память для битового поля
}

TBitField::~TBitField()
{
	delete[] pMem;
}

int TBitField::GetMemIndex(const int n) const // индекс памяти дляинта в котором есть n
{
	return n/(sizeof(TELEM) * 8); //получаем индекс инта, к котором хранится наше число. для 35--1. 8 это число бит в бите и умножаем на 2
}

TELEM TBitField::GetMemMask(const int n) const // битовая маска для бита n
{
	return 1 << (n % (sizeof(TELEM) * 8));	//сдвигаем 1 на остаток от деления на 32. для 35-3 
}

// доступ к битам битового поля

int TBitField::GetLength(void) const // получить длину (к-во битов)
{
	return BitLen;
}

void TBitField::SetBit(const int n) // установить сдвиг бит
{
	if (n >= 0 && n < BitLen)
	{
		pMem[GetMemIndex(n)] |= GetMemMask(n); //элементу массива pMem с индексом инта в котором хранится наше число присваиваем старое значение и объединяем с маской
	}
}

void TBitField::ClrBit(const int n) // очистить бит
{
	if (n >= 0 && n < BitLen)
	{
		pMem[GetMemIndex(n)] &= ~GetMemMask(n); //элементу массива pMem с индексом инта в котором хранится наше число присваиваем старое значение и пересекаем с инверсией маски нашего элемента
	}
}

int TBitField::GetBit(const int n) const // получить значение бита
{
	if (n >= 0 && n < BitLen)
	{
		pMem[GetMemIndex(n)] & GetMemMask(n); //на элемент из массива интов накладываем маску элемента. на его позиции стоит 1. битовое и получаем элемент

	}
}

// битовые операции

TBitField& TBitField::operator=(const TBitField &bf) //перегрузка присваивания
{

}

int TBitField::operator==(const TBitField &bf) const // перегрузка сравнение
{
  return 0;
}

int TBitField::operator!=(const TBitField &bf) const // прегрузка сравнение
{
  return 0;
}

TBitField TBitField::operator|(const TBitField &bf) // перегрузка операция "или"
{
}

TBitField TBitField::operator&(const TBitField &bf) // перегрузка операция "и"
{
}

TBitField TBitField::operator~(void) // перегрузка отрицание
{
}

// ввод/вывод

istream &operator>>(istream &istr, TBitField &bf) // ввод
{
}

ostream &operator<<(ostream &ostr, const TBitField &bf) // вывод
{
}
