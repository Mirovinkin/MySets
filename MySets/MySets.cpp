// MySets.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <locale.h>
#include <string.h>
#include <typeinfo>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
//#include <cstdlib>
#include <ctype.h>
#include <fstream>
#include <vector>

using namespace std;

class Set
{
private:
    double* _sets;
    int _size = sizeof(_sets) / sizeof(double);
    int _index = sizeof(_sets) / sizeof(double) - 1;

public:
    Set(double* Set)
    {
        _sets = Set;
    }

    double* GetSet()
    {
        return _sets;
    }

    int GetSize()
    {
        return _size;
    }

    void SetSets(double* NewSet)
    {
        _sets = NewSet;
    }

    void AddElem(const double& Item)
    {
        bool isCopy = false;
        if (_index == -1)_index++;
        for (int i = 0; i < _size; i++)
        {
            if (_sets[i] == Item)
            {
                isCopy = true;
            }
        }
        if (isCopy = true) throw exception("There is such value in the Set");
        
        _sets[_index] = Item;
        _index++;

    }

    double* operator +(Set SetN)
    {
        for (int j = 0; j < SetN.GetSize(); j++)
        {
            if (_index == -1)_index++;
            _sets[_index] = SetN.GetSet()[j];
            _index++;
        }
        return _sets;
    }

    double* operator -(double Elem)
    {
        int NewIndex = 0;
        if (_index == -1)_index++;
        for (int i = 0; i < _size; i++)
        {
            if (_sets[i] == Elem)
            {
                NewIndex = i;
            }
        }

        for (int i = 0; i < _size; i++)
        {
            if (i == NewIndex) continue;
            
            _sets[_index] = _sets[i];
            _index++;
            
        }

        return _sets;
    }

    double* operator -=(Set SetN)
    {
        if (_index == -1)_index++;
        for (int i = 0; i < SetN.GetSize(); i++)
        {
            bool isCopy = false;
            for (int j = 0; j < _size; j++)
            {
                if (_sets[j] == SetN.GetSet()[i])
                {
                    isCopy = true;
                }
                if (isCopy == true)
                {
                    isCopy = false;
                    continue;
                }
                _sets[_index] = _sets[j];
            }
        }
        return _sets;
    }

    double* operator *(Set SetN)
    {
        if (_index == -1)_index++;
        for (int i = 0; i < SetN.GetSize(); i++)
        {
            bool isCopy = false;
            for (int j = 0; j < _size; j++)
            {
                if (_sets[j] != SetN.GetSet()[i])
                {
                    isCopy = true;
                }
                if (isCopy == true)
                {
                    isCopy = false;
                    continue;
                }
                _sets[_index] = _sets[j];
            }
        }
        return _sets;
    }

    double* operator =(Set SetN)
    {
        for (int i = 0; i < SetN.GetSize(); i++)
        {
            _sets[i] = SetN.GetSet()[i];
        }
    }
    ~Set() {};
};
int main()
{
    std::cout << "Hello World!\n";
}
