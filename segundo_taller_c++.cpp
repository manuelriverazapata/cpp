#include <iostream>
#include <algorithm>
using namespace std;
//11111111111111111111111111111111111111111111111111111111111111111111111111111111111111
int main() {
    int n;
    cout << "Ingrese el tamaño del array: ";
    cin >> n;

    int arr[n];
    cout << "Ingrese los elementos: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n); // ordenar

    double mediana;
    if (n % 2 == 0) {
        mediana = (arr[n/2 - 1] + arr[n/2]) / 2.0;
    } else {
        mediana = arr[n/2];
    }

    cout << "La mediana es: " << mediana << endl;
    return 0;
}
//22222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222
int main() {
    int n, x;
    cout << "Ingrese el tamaño del array: ";
    cin >> n;

    int arr[n];
    cout << "Ingrese los elementos en orden: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Ingrese el valor a buscar: ";
    cin >> x;

    int inicio = 0, fin = n - 1, medio;
    bool encontrado = false;

    while (inicio <= fin) {
        medio = (inicio + fin) / 2;
        if (arr[medio] == x) {
            encontrado = true;
            break;
        } else if (arr[medio] < x) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }

    if (encontrado)
        cout << "Elemento encontrado en la posición " << medio << endl;
    else
        cout << "Elemento no encontrado" << endl;

    return 0;
}
//3333333333333333333333333333333333333333333333333333333333333333333333333333333333333333
int main() {
    int filas, columnas;
    cout << "Ingrese filas y columnas: ";
    cin >> filas >> columnas;

    int matriz[filas][columnas];
    cout << "Ingrese los elementos:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << "Matriz transpuesta:\n";
    for (int j = 0; j < columnas; j++) {
        for (int i = 0; i < filas; i++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
//444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444444
int main() {
    const int MAX = 5;
    string productos[MAX];
    int stock[MAX];

    for (int i = 0; i < MAX; i++) {
        cout << "Ingrese el nombre del producto " << i+1 << ": ";
        cin >> productos[i];
        cout << "Ingrese el stock: ";
        cin >> stock[i];
    }

    cout << "\n=== Inventario ===\n";
    for (int i = 0; i < MAX; i++) {
        cout << productos[i] << " - " << stock[i] << " unidades\n";
    }

    return 0;
}

//555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555555
int main() {
    int n;
    cout << "Ingrese el tamaño del array: ";
    cin >> n;

    int arr[n];
    cout << "Ingrese los elementos: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }

    cout << "Array ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

//6666666666666666666666666666666666666666666666666666666666666666666666666666666666666
int main() {
    int n;
    cout << "Ingrese el tamaño del array: ";
    cin >> n;

    int arr[n];
    cout << "Ingrese los elementos: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Elementos duplicados: ";
    bool hayDuplicados = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                cout << arr[i] << " ";
                hayDuplicados = true;
                break;
            }
        }
    }
    if (!hayDuplicados) {
        cout << "Ninguno";
    }
    cout << endl;

    return 0;
}
//7777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777777
int main() {
    char tablero[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int fila, col;
    char jugador = 'X';

    for (int turnos = 0; turnos < 9; turnos++) {
        cout << "Turno del jugador " << jugador << endl;
        cout << "Ingrese fila y columna (0-2): ";
        cin >> fila >> col;

        if (tablero[fila][col] == ' ') {
            tablero[fila][col] = jugador;
        } else {
            cout << "Casilla ocupada, intenta de nuevo.\n";
            turnos--;
            continue;
        }

        // Mostrar tablero
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }

        // Cambiar jugador
        jugador = (jugador == 'X') ? 'O' : 'X';
    }

    return 0;
}