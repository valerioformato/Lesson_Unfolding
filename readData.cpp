void readData() {

  auto inFile = TFile::Open("data.root");

  TTree *tEvents;
  inFile->GetObject("Data", tEvents);

  double mass;
  tEvents->SetBranchAddress("Mass", &mass);

  TTree *tSimulation;
  inFile->GetObject("Simulation", tSimulation);

  double rmass, tmass;
  tSimulation->SetBranchAddress("RecoMass", &rmass);
  tSimulation->SetBranchAddress("TrueMass", &tmass);

  for (Long64_t iEv = 0; iEv < tEvents->GetEntries(); iEv++) {
    tEvents->GetEntry(iEv);

    // have fun...
  }

  for (Long64_t iEv = 0; iEv < tSimulation->GetEntries(); iEv++) {
    tSimulation->GetEntry(iEv);

    // have even more fun...
  }
}
