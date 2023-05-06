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

void buscar_archivo_mas_pequeno(std::string ruta_carpeta) {
    std::filesystem::path ruta(ruta_carpeta);
    if (std::filesystem::exists(ruta) && std::filesystem::is_directory(ruta)) {
        std::filesystem::path archivo_mas_pequeno;
        int tamano_mas_pequeno = INT_MAX;
        for (const auto& archivo : std::filesystem::directory_iterator(ruta)) {
            if (std::filesystem::is_regular_file(archivo)) {
                int tamano_actual = std::filesystem::file_size(archivo);
                if (tamano_actual < tamano_mas_pequeno) {
                    archivo_mas_pequeno = archivo.path();
                    tamano_mas_pequeno = tamano_actual;
                }
            }
        }
        if (!archivo_mas_pequeno.empty()) {
            std::cout << "El archivo mas pequeno en la carpeta " << ruta_carpeta << " es: " << archivo_mas_pequeno << std::endl;
        } else {
            std::cout << "No se encontraron archivos en la carpeta " << ruta_carpeta << std::endl;
        }
    } else {
        std::cout << "La ruta proporcionada no es valida o no es una carpeta" << std::endl;
    }
}
int main() {
     crear_archivos();
     agregar_texto();
    buscar_archivo_mas_pequeno("C:\\Users\\enamo\\OneDrive\\Documentos\\par");
    buscar_archivo_mas_pequeno("C:\\Users\\enamo\\OneDrive\\Escritorio\\impar");
    return 0;
}

