#include "SimpleGeometry.hh"
#include "SimpleParticleSource.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4RunManager.hh"
#include "G4ProductionCuts.hh"
#include "G4UImanager.hh"
#include "FTFP_BERT.hh"

int main(int argc, char** argv)
{    
  // Construct the default run manager

  G4RunManager * runManager = new G4RunManager;

  // Set mandatory initialization classes

  // Detector construction
  runManager->SetUserInitialization(new SimpleGeometry());

  // Physics list
  runManager->SetUserInitialization(new FTFP_BERT);
    
  // Primary generator action
  runManager->SetUserAction(new SimpleParticleSource());

  // Initialize G4 kernel
  runManager->Initialize();

  G4UIExecutive* ui = new G4UIExecutive(argc, argv);

  G4UImanager::GetUIpointer()->ApplyCommand("/tracking/verbose 2");

  G4VisManager* visManager = new G4VisExecutive;
  visManager->Initialize();

  // interactive mode
  G4UImanager::GetUIpointer()->ApplyCommand("/control/execute init_vis.mac");
  ui->SessionStart();

  delete ui;
  delete visManager;
  delete runManager;
  return 0;
}
