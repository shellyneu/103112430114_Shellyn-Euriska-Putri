#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
#include <string>
using namespace std;

const int MAX = 6;

struct Mahasiswa{
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
    float NilaiAkhir;
};

struct StackMahasiswa{
    Mahasiswa data[MAX];
    int top;
};

void createStackMahasiswa(StackMahasiswa &StackMHS);
bool isEmpty(StackMahasiswa StackMHS);
bool isFull(StackMahasiswa StackMHS);

void push(StackMahasiswa &StackMHS);
void pop(StackMahasiswa &StackMHS);

void update(StackMahasiswa &StackMHS, int posisi);
void view(StackMahasiswa StackMHS);
void searchNilaiAkhir(StackMahasiswa StackMHS, float NilaiAkhirMin, float NilaiAkhirMax);

// Bagian B
void maxNilaiAkhir(StackMahasiswa s);

#endif