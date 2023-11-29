#include "SimpleGeometry.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"

using namespace CLHEP;

SimpleGeometry::SimpleGeometry()
: G4VUserDetectorConstruction()
{ }

SimpleGeometry::~SimpleGeometry()
{ }

G4VPhysicalVolume* SimpleGeometry::Construct()
{  
  G4bool checkOverlaps = true;

  G4NistManager* nist = G4NistManager::Instance();
  G4Material* Lead = nist->FindOrBuildMaterial("G4_Pb");
  G4Material* Vacuum = nist->FindOrBuildMaterial("G4_Galactic");
 
  // World
  G4Box* world = new G4Box("World", 50*cm, 50*cm, 50*cm);
  G4LogicalVolume* worldlv =                         
    new G4LogicalVolume(world, Vacuum, "World");  
  
  G4VPhysicalVolume* physWorld = 
    new G4PVPlacement(0, G4ThreeVector(),
                      worldlv, "World",
                      0, false, 0, checkOverlaps);

  // Lead plate
  G4Box* plate = new G4Box("LeadPlate", 10*cm, 10*cm, 5*cm);
  G4LogicalVolume* platelv =                         
    new G4LogicalVolume(plate, Lead, "LeadPlate");  

  new G4PVPlacement(0, G4ThreeVector(0.,0.,0.),
                      platelv, "LeadPlate",
                      worldlv, false, 0, checkOverlaps);

  return physWorld;
}
