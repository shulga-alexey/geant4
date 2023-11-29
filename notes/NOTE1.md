# Установка GEANT4 и запуск проекта

Инструкция по установке GEANT4 версии 11.1.3 на операционной системе Ubuntu 22.04.

Первый запуск проекта на GEANT4.

## Установка GEANT4

1. Скачать и распаковать исходный пакет GEANT4 в каталоге с именем ```/path/to```
    ```cd /path/to/```
    ```wget https://gitlab.cern.ch/geant4/geant4/-/archive/v11.1.3/geant4-v11.1.3.tar.gz```
    ```tar xzvf geant4-v11.1.3.tar.gz```
2. Установить необходимые средства разработки
    ```sudo apt-get install cmake cmake-curses-gui g++```
3. Создать каталог, в котором можно будет настроить и запустить сборку, а также хранить продукты сборки:
    ```cd geant4-v11.1.3 && mkdir geant4-v11.1.3-build && cd geant4-v11.1.3-build```
    ```cmake -D"GEANT4_INSTALL_DATA=ON" -D"GEANT4_USE_OPENGL_X11=ON" -D"GEANT4_USE_QT=ON" -D"CMAKE_INSTALL_PREFIX=/path/to/geant4-v11.1.3" ../```
4. Запустить сборку GEANT4 на двух ядрах процессора
    ```make -j2```
5. Установить Geant4
    ```make install```
6. Установить переменные окружения (в каждом новом сеансе)
    ```source ~/geant4.10.07.p01/bin/geant4.sh```

## Запуск проекта

1. Перейти в директорию проекта ```/path/to_project```
    ```cd /path/to_project/```
2. Cоздать каталог для сборки проекта и перейти в него
    ```mkdir build && cd build/```
3. Создать makefile с инструкцией по сборке проекта
    ```cmake ..```
4. Запустить сборку проекта
    ```make```
5. Запустить проект
    ```./name_project.exe```
