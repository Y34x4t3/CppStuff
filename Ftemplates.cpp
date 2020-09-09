/*
 * Ftemplates.cpp
 * 
 * Copyright 2020 Y34x4t3 <y34x4t3@y34x4t3-Lenovo-ideapad-330S-14IKB>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
using namespace std;
template<class T>
void imprimirTam( T a )
{
	cout<<sizeof(a)<<endl;
}
template <class A>
A* asignarMemoria ( int tam )
{
	return new A[tam];
}
template <typename T>
void llenarA (T* vec, int tam)
{
	for ( int i = 0; i < tam; i++)
	{
		vec[i] = 35 + i;
	}
}
template <class T>
void imprimirA (T* vec, int tam)
{
	for ( int i = 0; i < tam; i++)
	{
		cout<<vec[i]<<"\t";
	}
}
int main()
{
    int t = 9;
    double a = 9;
    imprimirTam <int> (t);
    imprimirTam <double> (a);	
    char *v = asignarMemoria <char> (t);
    llenarA <char> (v, t);
    imprimirA <char> (v, t);
	return 0;
}

