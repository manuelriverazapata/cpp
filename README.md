//1. Struct con constructores y valores por defecto:

#include <iostream>
#include <string>

struct Producto {
    string nombre;
    double precio;
    int stock;

    Producto(string n = "", double p = 0.0, int s = 0)
        : nombre(n), precio(p), stock(s) {}
};

int main() {
    Producto p1("Pan");
    Producto p2("Leche", 3500.5);
    Producto p3("Huevos", 12000.0, 5);

    cout << "Producto: " << p1.nombre << " | Precio: " << p1.precio << " | Stock: " << p1.stock << endl;
    cout << "Producto: " << p2.nombre << " | Precio: " << p2.precio << " | Stock: " << p2.stock << endl;
    cout << "Producto: " << p3.nombre << " | Precio: " << p3.precio << " | Stock: " << p3.stock << endl;

    return 0;
}


//2. Métodos const y validación: 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Producto {
    string nombre;
    double precio;
    int stock;

    Producto(string n = "", double p = 0.0, int s = 0)
        : nombre(n), precio(p), stock(s) {}

    bool disponible() const {
        return stock > 0;
    }

    bool esValido() const {
        return precio >= 0 && !nombre.empty();
    }
};

int main() {
    vector<Producto> productos = {
        {"Pan", 1500, 3},
        {"Leche", 3500, 0},
        {"Huevos", 12000, 5},
        {"", 2000, 2},
        {"Arroz", -1500, 4}
    };

    productos.erase(remove_if(productos.begin(), productos.end(),
        [](const Producto& p){ return !p.esValido(); }), productos.end());

    cout << "Productos válidos y disponibles:\n";
    for (const auto& p : productos)
        if (p.disponible())
            cout << "Nombre: " << p.nombre << " | Precio: " << p.precio << " | Stock: " << p.stock << endl;

    return 0;
}

//3. Operadores == y < para ordenar y buscar: 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Producto {
    string nombre;
    double precio;
    int stock;

    Producto(string n = "", double p = 0.0, int s = 0)
        : nombre(n), precio(p), stock(s) {}

    bool operator==(const Producto& otro) const {
        string a = nombre, b = otro.nombre;
        transform(a.begin(), a.end(), a.begin(), ::tolower);
        transform(b.begin(), b.end(), b.begin(), ::tolower);
        return a == b;
    }

    bool operator<(const Producto& otro) const {
        if (precio == otro.precio)
            return nombre < otro.nombre;
        return precio < otro.precio;
    }
};

int main() {
    vector<Producto> productos = {
        {"Pan", 1500, 3},
        {"Leche", 3500, 0},
        {"Huevos", 12000, 5},
        {"Arroz", 2500, 4},
        {"Leche", 3500, 10}
    };

    sort(productos.begin(), productos.end());

    cout << "Productos ordenados:\n";
    for (const auto& p : productos)
        cout << "Nombre: " << p.nombr


//4. Crea una estructura para representar un polinomio

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Termino {
    double coeficiente;
    int exponente;

    Termino(double c = 0.0, int e = 0) : coeficiente(c), exponente(e) {}
};

struct Polinomio {
    vector<Termino> terminos;

    void agregarTermino(double coef, int exp) {
        terminos.push_back(Termino(coef, exp));
    }

    double evaluar(double x) const {
        double resultado = 0.0;
        for (const auto& t : terminos)
            resultado += t.coeficiente * pow(x, t.exponente);
        return resultado;
    }

    void mostrar() const {
        for (size_t i = 0; i < terminos.size(); ++i) {
            cout << terminos[i].coeficiente << "x^" << terminos[i].exponente;
            if (i != terminos.size() - 1) cout << " + ";
        }
        cout << endl;
    }
};

int main() {
    Polinomio p;
    p.agregarTermino(3, 2);
    p.agregarTermino(2, 1);
    p.agregarTermino(1, 0);

    cout << "Polinomio: ";
    p.mostrar();

    cout << "Evaluado en x=2: " << p.evaluar(2) << endl;

    return 0;
}


//5. Implementa un sistema de inventario más complejo 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Producto {
    string nombre;
    double precio;
    int stock;

    Producto(string n = "", double p = 0.0, int s = 0)
        : nombre(n), precio(p), stock(s) {}
};

struct Inventario {
    vector<Producto> productos;

    void agregar(const Producto& p) {
        productos.push_back(p);
    }

    void eliminar(const string& nombre) {
        productos.erase(remove_if(productos.begin(), productos.end(),
            [&](const Producto& p){ return p.nombre == nombre; }), productos.end());
    }

    void actualizarStock(const string& nombre, int nuevoStock) {
        for (auto& p : productos)
            if (p.nombre == nombre)
                p.stock = nuevoStock;
    }

    void mostrar() const {
        for (const auto& p : productos)
            cout << "Nombre: " << p.nombre << " | Precio: " << p.precio << " | Stock: " << p.stock << endl;
    }

    double valorTotal() const {
        double total = 0;
        for (const auto& p : productos)
            total += p.precio * p.stock;
        return total;
    }
};

int main() {
    Inventario inv;
    inv.agregar({"Pan", 1500, 10});
    inv.agregar({"Leche", 3500, 5});
    inv.agregar({"Huevos", 12000, 2});

    cout << "Inventario inicial:\n";
    inv.mostrar();

    inv.actualizarStock("Leche", 8);
    inv.eliminar("Huevos");

    cout << "\nInventario actualizado:\n";
    inv.mostrar();

    cout << "\nValor total del inventario: " << inv.valorTotal() << endl;

    return 0;
}


//6. Desarrolla una estructura para representar una fracción 

#include <iostream>
using namespace std;

struct Fraccion {
    int numerador;
    int denominador;

    Fraccion(int n = 0, int d = 1) : numerador(n), denominador(d) {}

    void simplificar() {
        int a = abs(numerador), b = abs(denominador);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        numerador /= a;
        denominador /= a;
        if (denominador < 0) {
            numerador = -numerador;
            denominador = -denominador;
        }
    }

    Fraccion sumar(const Fraccion& f) const {
        Fraccion r(numerador * f.denominador + f.numerador * denominador, denominador * f.denominador);
        r.simplificar();
        return r;
    }

    Fraccion restar(const Fraccion& f) const {
        Fraccion r(numerador * f.denominador - f.numerador * denominador, denominador * f.denominador);
        r.simplificar();
        return r;
    }

    Fraccion multiplicar(const Fraccion& f) const {
        Fraccion r(numerador * f.numerador, denominador * f.denominador);
        r.simplificar();
        return r;
    }

    Fraccion dividir(const Fraccion& f) const {
        Fraccion r(numerador * f.denominador, denominador * f.numerador);
        r.simplificar();
        return r;
    }

    void mostrar() const {
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {
    Fraccion f1(2, 3), f2(4, 5);
    cout << "Suma: "; f1.sumar(f2).mostrar();
    cout << "Resta: "; f1.restar(f2).mostrar();
    cout << "Multiplicacion: "; f1.multiplicar(f2).mostrar();
    cout << "Division: "; f1.dividir(f2).mostrar();
    return 0;
}


//7. Crea un sistema de gestión de contactos 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Contacto {
    string nombre;
    string telefono;
    string correo;

    Contacto(string n = "", string t = "", string c = "")
        : nombre(n), telefono(t), correo(c) {}
};

struct Agenda {
    vector<Contacto> contactos;

    void agregar(const Contacto& c) {
        contactos.push_back(c);
    }

    void eliminar(const string& nombre) {
        contactos.erase(remove_if(contactos.begin(), contactos.end(),
            [&](const Contacto& c){ return c.nombre == nombre; }), contactos.end());
    }

    void buscar(const string& nombre) const {
        auto it = find_if(contactos.begin(), contactos.end(),
            [&](const Contacto& c){ return c.nombre == nombre; });
        if (it != contactos.end())
            cout << "Nombre: " << it->nombre << " | Tel: " << it->telefono << " | Correo: " << it->correo << endl;
        else
            cout << "Contacto no encontrado.\n";
    }

    void mostrar() const {
        for (const auto& c : contactos)
            cout << "Nombre: " << c.nombre << " | Tel: " << c.telefono << " | Correo: " << c.correo << endl;
    }
};

int main() {
    Agenda agenda;
    agenda.agregar({"Sara", "3115554444", "sara@gmail.com"});
    agenda.agregar({"Juan", "3129998888", "juan@hotmail.com"});
    agenda.agregar({"Camilo", "3101112222", "camilo@outlook.com"});

    cout << "Contactos actuales:\n";
    agenda.mostrar();

    cout << "\nBuscando a Juan:\n";
    agenda.buscar("Juan");

    agenda.eliminar("Sara");

    cout << "\nContactos después de eliminar:\n";
    agenda.mostrar();

    return 0;
}
