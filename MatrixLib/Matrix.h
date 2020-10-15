#ifndef _MATRIX_
#define _MATRIX_
#include "MyVector.h"

const int MAX_MATRIX_SIZE = 10000;

template <class ValType>
class TMatrix : public TVector<TVector<ValType>>
{
public:
  TMatrix(int s = 10);
  TMatrix(const TMatrix &mt);                   // копирование
  TMatrix(const TVector<TVector<ValType>> &mt); // преобразование типа
  bool operator==(const TMatrix &mt) const;     // сравнение
  bool operator!=(const TMatrix &mt) const;     // сравнение
  TMatrix &operator=(const TMatrix &mt);        // присваивание
  TMatrix operator+(const TMatrix &mt);         // сложение
  TMatrix operator-(const TMatrix &mt);         // вычитание

  // ввод / вывод
  friend istream &operator>>(istream &in, TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      in >> mt.pVector[i];
    return in;
  }
  friend ostream &operator<<(ostream &out, const TMatrix &mt)
  {
    for (int i = 0; i < mt.Size; i++)
      out << mt.pVector[i] << endl;
    return out;
  }
  template <class ValType>
  TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType>>(s)
  {
    if ((s < 0) || (s > MAX_MATRIX_SIZE))
      throw -1;
    for (int i = 0; i < s; ++i)
    {
      TVector<ValType> v(s - i, i);
      pVector[i] = v;
    }
  }

  template <class ValType> // конструктор копирования
  TMatrix<ValType>::TMatrix(const TMatrix<ValType> &mt) : TVector<TVector<ValType>>(mt)
  {}

  template <class ValType> // конструктор преобразования типа
  TMatrix<ValType>::TMatrix(const TVector<TVector<ValType>> &mt) : TVector<TVector<ValType>>(mt)
  {}

  template <class ValType> // сравнение
  bool TMatrix<ValType>::operator==(const TMatrix<ValType> &mt) const
  {
    if (this->Size != mt.Size)
      return false;
    for (int i = 0; i < this->Size; i++)
      if (this->pVector[i] != mt.pVector[i])
        return false;
    return true;
  }

  template <class ValType> // сравнение
  bool TMatrix<ValType>::operator!=(const TMatrix<ValType> &mt) const
  {
    if (*this == mt)
      return false;
    return true;
  }

  template <class ValType> // присваивание
  TMatrix<ValType> &TMatrix<ValType>::operator=(const TMatrix<ValType> &mt)
  {
    if (this != &mt)
    {
      if (this->Size != mt.Size)
      {
        delete[] this->pVector;
        this->Size = mt.Size;
        this->pVector = new TVector<ValType>[mt.Size];
      }
      for (int i = 0; i < this->Size; i++)
        this->pVector[i] = mt.pVector[i];
    }
    return *this;
  }

  template <class ValType> // сложение
  TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType> &mt)
  {
    return TVector<TVector<ValType>>::operator+(mt);
  }

  template <class ValType> // вычитание
  TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType> &mt)
  {
    return TVector<TVector<ValType>>::operator-(mt);
  }
};
#endif