# Построение модели установки (материалы, геометрия).

## Описание материалов

1. ```G4Isotope``` - описывает свойства атома (атомное число, количество нуклонов, молярную массу).

    Создание изотопов:
    ```cpp
    G4Isotope* U235 = new G4Isotope(name="U235", iz=92, n=235, a=235.01*g/mole);
    G4Isotope* U238 = new G4Isotope(name="U238", iz=92, n=238, a=238.03*g/mole);
    ```

2. ```G4Element``` - описывает свойства элемента (эффективное атомное число, эффективную молярную массу, число изотопов).

    Создание простого элемента:
    ```cpp
    G4Element* elH = new G4Element(name="Hydrogen", symbol="H", z=1., 1.01*g/mole);
    G4Element* elO = new G4Element(name="Oxygen", symbol="O", z=8., 16.00*g/mole);
    G4Element* elN = new G4Element(name="Nitrogen",symbol="N" , z= 7., 14.01*g/mole);
    ```

    Создание элемента из изотопов:
    ```cpp
    G4Element* elU = new G4Element(name="enriched Uranium", symbol="U", ncomponents=2);
    elU->AddIsotope(U5, abundance= 90.*perCent);
    elU->AddIsotope(U8, abundance= 10.*perCent);
    ```

3. ```G4Material``` - описывает макроскопические свойства вещества (плотность, состояние, температуру, давление, радиационную длину, длину свободного пробега).

    Cоздание простого материала:
    ```cpp
    G4Material* Al = new G4Material(name="Aluminum", z=13., 26.98*g/mole,  2.700*g/cm3);
    ```

    Создание материала по химической формуле:
    ```cpp
    G4Material* H2O = new G4Material(name="Water", 1.000*g/cm3, ncomponents=2);
    H2O->AddElement(elH, natoms=2);
    H2O->AddElement(elO, natoms=1);

    G4Material* CO2 = new G4Material(name="Carbonic gas", 27.*mg/cm3, ncomponents=2, kStateGas, 325.*kelvin, 50.*atmosphere);
    CO2->AddElement(elC, natoms=1);
    CO2->AddElement(elO, natoms=2);
    ```

    Создание материала через массовые доли компонент:
    ```cpp
    G4Material* Air = new G4Material(name="Air", 1.290*mg/cm3, ncomponents=2);
    Air->AddElement(elN, fractionmass=0.7);
    Air->AddElement(elO, fractionmass=0.3);

    G4Material* Steam = new G4Material(name="Water steam", 0.3*mg/cm3, ncomponents=1, kStateGas, 500.*kelvin, 2.*atmosphere);
    steam->AddMaterial(H2O, fractionmass=1.);
    ```

    Создание смеси нескольких материалов
    ```cpp
    G4Material* Aerog = new G4Material(name="Aerogel", 0.200*g/cm3, ncomponents=3);
    Aerog->AddMaterial(SiO2, fractionmass=62.5*perCent);
    Aerog->AddMaterial(H2O, fractionmass=37.4*perCent);
    Aerog->AddElement(elC, fractionmass= 0.1*perCent);
    ```

    Создание разреженного газа (вакуума):
    ```cpp
    G4Material* Galactic = new G4Material(name="Galactic", z=1., a=1.01*g/mole, universe_mean_density, kStateGas, 0.1*kelvin, 1.e-19*pascal);

    G4Material* Beam = new G4Material(name="Beam", 1.e-5*g/cm3, ncomponents=1, kStateGas, STP_Temperature, 2.e-2*bar);
    beam->AddMaterial(Air, fractionmass=1.)
    ```

    Импорт материалов из библиотеки материалов Geant4
    ```cpp
    #include "G4NistManager.hh"

    G4NistManager* man = G4NistManager::Instance();

    //elements
    G4Element* elAl = man->FindOrBuildElement("Al");

    //materials
    G4Material* Al = man->FindOrBuildMaterial("G4_Al");
    G4Material* Cu = man->FindOrBuildMaterial("G4_Cu");
    G4Material* H2O = man->FindOrBuildMaterial("G4_WATER");
    G4Material* Sci = man->FindOrBuildMaterial("G4_PLASTIC_SC_VINYLTOLUENE");
    G4Material* Vacuum = man-> FindOrBuildMaterial("G4_Galactic");
    ```

## Описание геометрии

Описание геометрии включает три этапа:

1. ```G4VSolid``` - описание формы

2. ```G4LogicalVolume``` - описание логического объема (строится на основе формы; кроме геометрических параметров, содержит описание материала, заполняющего объем, информацию о э/м поле, свойства визуализации
объема и описание детектирующей способности)

3. ```G4VPhysicalVolume``` - описание физического объема (строится на основе логического объема; описывает положение объема в пространстве, позволяет одновременно описать серию одинаковых объемов или параметризовать свойства объема в зависимости от номера копии)