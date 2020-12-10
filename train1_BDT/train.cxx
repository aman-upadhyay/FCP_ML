void train(){
	TMVA::Tools::Instance();

	TFile *fo = new TFile("tmp.root","recreate");
	TMVA::Factory *factory = new TMVA::Factory("lips_bdt", fo,"!V:!Silent:Color:DrawProgressBar:Transformations=I;D;P;G,D");
	TMVA::DataLoader *dataloader = new TMVA::DataLoader("dataset");
  

	dataloader->AddVariable("Edep1");
	dataloader->AddVariable("Edep2");
	dataloader->AddVariable("Edep3");
	dataloader->AddVariable("Edep4");
	dataloader->AddVariable("Edep5");
	dataloader->AddVariable("Edep6");
	dataloader->AddVariable("Edep7");
	dataloader->AddVariable("Edep8");
	dataloader->AddVariable("Edep9");
	dataloader->AddVariable("Edep10");
	dataloader->AddVariable("Edep11");
	dataloader->AddVariable("Edep12");
	dataloader->AddVariable("Edep13");
	dataloader->AddVariable("Edep14");
	dataloader->AddVariable("Edep15");


	TFile Tr("bdt_organise.root");
	TTree *ts = (TTree*)Tr.Get("train_signal");
	TTree *tb = (TTree*)Tr.Get("train_background");
	TTree *qs = (TTree*)Tr.Get("test_signal");
	TTree *qb = (TTree*)Tr.Get("test_background");

	// the 1's are event weights (setting both to 1 ignores that)
	dataloader->AddSignalTree(ts,1,TMVA::Types::kTraining);
	dataloader->AddBackgroundTree(tb,1,TMVA::Types::kTraining);
	dataloader->AddSignalTree(qs,1,TMVA::Types::kTesting);
	dataloader->AddBackgroundTree(qb,1,TMVA::Types::kTesting);

  
	// AdaBoost BDT
	factory->BookMethod(dataloader,TMVA::Types::kBDT,"BDT","!H:!V:NTrees=1000:MinNodeSize=2.5%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=20");

	//train
	factory->TrainAllMethods();
	factory->TestAllMethods();
	factory->EvaluateAllMethods();

	//clean-up
	fo->Close();
	delete factory;
	delete dataloader;

	TMVA::TMVAGui("tmp.root");
}
