# Установка GEANT4 и запуск проекта

## Установка GEANT4

Для операционной системы Ubuntu 22.04:

1. Скачать и распаковать исходный пакет GEANT4 в каталоге с именем /path/to
    cd /path/to/
    wget https://gitlab.cern.ch/geant4/geant4/-/archive/v11.1.3/geant4-v11.1.3.tar.gz
    tar xzvf geant4-v11.1.3.tar.gz
2. Установить необходимые средства разработки
    sudo apt-get install cmake cmake-curses-gui g++
3. Создать каталог, в котором можно будет настроить и запустить сборку, а также хранить продукты сборки:
    cd geant4-v11.1.3
    mkdir geant4-v11.1.3-build
    cd geant4-v11.1.3-build
    cmake -D"GEANT4_INSTALL_DATA=ON" -D"GEANT4_USE_OPENGL_X11=ON" -D"GEANT4_USE_QT=ON" -D"CMAKE_INSTALL_PREFIX=/path/to/geant4-v11.1.3" ../
4. Запустить сборку GEANT4
    make
5. Установить Geant4
    make install