#include <iostream>
#include <bitset>

using namespace std;

// ----- XOR con una máscara de 8 bits -----
uint8_t xor_mask(uint8_t value, uint8_t mask) {
    return value ^ mask;
}

// ----- Rotaciones a la derecha -----
uint8_t rotate_right(uint8_t value, int bits) {
    return (value >> bits) | (value << (8 - bits));
}

// ----- Rotaciones a la izquierda -----
uint8_t rotate_left(uint8_t value, int bits) {
    return (value << bits) | (value >> (8 - bits));
}

// ----- Desplazamientos a la derecha -----
uint8_t shift_right(uint8_t value, int bits) {
    return value >> bits; // rellena con ceros a la izquierda
}

// ----- Desplazamientos a la izquierda -----
uint8_t shift_left(uint8_t value, int bits) {
    return value << bits; // rellena con ceros a la derecha
}

// ----- Mostrar resultado -----
void mostrar_resultados(uint8_t value, uint8_t mask) {
    cout << "Valor original:       " << bitset<8>(value) << endl;
    cout << "XOR con máscara:      " << bitset<8>(xor_mask(value, mask)) << endl;

    for (int i = 1; i <= 7; ++i) {
        cout << "Rotar der " << i << ":           " << bitset<8>(rotate_right(value, i)) << endl;
        cout << "Rotar izq " << i << ":           " << bitset<8>(rotate_left(value, i)) << endl;
        cout << "Shift der " << i << ":           " << bitset<8>(shift_right(value, i)) << "  (pierde info)" << endl;
        cout << "Shift izq " << i << ":           " << bitset<8>(shift_left(value, i)) << "  (pierde info)" << endl;
    }
}
