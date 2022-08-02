# EstrD-2022s1-TP-Final

## Pasos para correr el proyecto

1. Clonar el repositorio.
2. Instalar g++.
3. Ejecutar las siguientes lineas de código:
```sh
g++ -o result main.cpp Img.cpp Matrix.cpp Color.cpp
```
```sh
./result 2    > output.svg #(en este caso, la imagen 2 es un árbol sin comprimir)
./result 2 -c > output.svg #(en este caso, la imagen 2 es un árbol comprimido)
```

4. Abrir el .svg (output.svg) con algún previsualizador de esta extensión de archivos.