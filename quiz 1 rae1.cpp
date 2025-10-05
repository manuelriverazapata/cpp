/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

int main()
{
    
   //parte 1============================================================================================== 
    //1.1
   int a = 10;
    int b = -3;

    
    float x = 3.14f;
    float y = -0.5f;

    
    char c = 'Z';

    cout << "Enteros: a = " << a << ", b = " << b << endl;
    cout << "Flotantes: x = " << x << ", y = " << y << endl;
    cout << "Caracter: c = " << c << endl;

    return 0;

   //1.2==================================
   
   //int: almacena números enteros (sin parte decimal)
   //float: almacena números reales con punto decimal
   //char: almacena un solo carácter (letra, dígito, símbolo).
   
   //===== recomendaciones =======
   
   //int: Uso recomendable para contadores, índices, edades, cantidades discretas.
   //float:Útil cuando necesitas fracciones y no requieres gran precisión.
   //char:puede usarse para representar pequeños códigos.
   
   
   //parte 2==================================================================================================================
   
   int a, b;
    cout << "Ingresa dos enteros separados por espacio: ";
    cin >> a >> b;

    cout << "Suma: " << (a + b) << endl;
    cout << "Resta: " << (a - b) << endl;
    cout << "Multiplicacion: " << (a * b) << endl;
    if (b != 0) {
        cout << "Division (entera): " << (a / b) << endl;
        cout << "Modulo: " << (a % b) << endl;
    } else {
        cout << "No se puede dividir ni calcular modulo por 0." << endl;
    }

    return 0;
    
    //2.2 =============================
    
  //  == es el operador de igualdad: devuelve true si las dos expresiones son iguales.

  //  != es el operador de desigualdad: devuelve true si las dos expresiones son distintas.
  
  
   //ejemplo:
  
   int x = 5;
   int y = 3;
   if (x == y) {
    // no entra
 }
   if (x != y) {
    // entra porque 5 != 3
}
  
  
  // 2.3 =========================
  
  // && (AND): true si ambas condiciones son true.
  // || (OR): true si al menos una es true.
  // ! (NOT): invierte la condición.
  
  
  //ejemplo

   int edad = 20;
   bool permiso = true;

   if (edad >= 18 && permiso) {
    cout << "Puede entrar." << endl;
}

   if (edad < 18 || permiso == false) {
    cout << "Restriccion aplicada." << endl;
}

   bool mayor = (edad >= 18);
   if (!mayor) {
    cout << "No es mayor de edad." << endl;
}
  
 //parte 3 ====================================================================
 
 int edad;
    cout << "Ingresa tu edad: ";
    cin >> edad;

    if (edad >= 18) {
        cout << "Eres mayor de edad." << endl;
    } else {
        cout << "Eres menor de edad." << endl;
    }

    return 0;
    
  //3.2 =======================
  
  // else if permite evaluar varias condiciones en secuencia. Se usa cuando hay más de dos casos mutuamente excluyentes.
  
 // ejemplo
 
    int nota = 78;
   if (nota >= 90) {
    cout << "A" << endl;
    
 } else if (nota >= 80) {
    cout << "B" << endl;
 } else if (nota >= 70) {
     
    cout << "C" << endl;
 } else if (nota >= 60) {
    cout << "D" << endl;
    
 } else {
    cout << "F" << endl;
}

  
  //parte 4 ====================================================
  
   int main() {
    for (int i = 1; i <= 10; ++i) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
  
  //4.2 ================
  
  int main() {
    int i = 10;
    while (i >= 1) {
        cout << i << " ";
        --i;
    }
    cout << endl;
    return 0;
}

//4.3 ================

  int main() {
    int i = 1;
    do {
        if (i % 2 == 0) {
            cout << i << " ";
        }
        ++i;
    } while (i <= 20);
    cout << endl;
    return 0;
}


  
  
  
  
  
  
  
  
  
  
  
  
   
}