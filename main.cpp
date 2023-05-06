#include <iostream>
#include <filesystem>
#include <windows.h>
#include <fstream>

void crear_archivos() {
    int num_archivos;
    std::cout << "Cuantos archivos deseas crear ";
    std::cin >> num_archivos;
    std::string ruta;
    if (num_archivos % 2 == 0) {  // Si la cantidad de archivos es par
        ruta = "C:\\Users\\enamo\\OneDrive\\Documentos\\par";
    } else {  // Si la cantidad de archivos es impar
        ruta = "C:\\Users\\enamo\\OneDrive\\Escritorio\\impar";
    }
    std::filesystem::create_directories(ruta);
    for (int i = 1; i <= num_archivos; i++) {
        std::string nombre_archivo = "documento" + std::to_string(i) + ".txt";
        std::filesystem::path ruta_archivo = std::filesystem::path(ruta).append(nombre_archivo);
        std::ofstream archivo(ruta_archivo);
        archivo.close();
    }
}
void agregar_texto() {
    int num_archivos;
    std::cout << "Cuantos archivos deseas agregar texto: ";
    std::cin >> num_archivos;
    std::string ruta;
    if (num_archivos % 2 == 0) {  // Si la cantidad de archivos es par
        ruta = "C:\\Users\\enamo\\OneDrive\\Documentos\\par";
    } else {  // Si la cantidad de archivos es impar
        ruta = "C:\\Users\\enamo\\OneDrive\\Escritorio\\impar";
    }
    for (int i = 1; i <= num_archivos; i++) {
        std::string nombre_archivo = "documento" + std::to_string(i) + ".txt";
        std::filesystem::path ruta_archivo = std::filesystem::path(ruta).append(nombre_archivo);
        std::ofstream archivo(ruta_archivo, std::ios::app);
        for (int j = 1; j <= i; j++) {
            archivo << "Linea " << j << std::endl;
        }
        archivo.close();
    }
}

int main() {
     crear_archivos();
     agregar_texto();
    return 0;
}
