void train(){
	ROOT::EnableImplicitMT();
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
	dataloader->AddVariable("count");


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
	factory->BookMethod(dataloader,TMVA::Types::kBDT,"BDT","!H:!V:NTrees=1000:MinNodeSize=0.1%:MaxDepth=3:BoostType=AdaBoost:AdaBoostBeta=0.5:SeparationType=GiniIndex:nCuts=100");
	
	//factory->BookMethod(dataloader,TMVA::Types::kPDERS,"PDERS","!H:!V:KernelEstimator=Gauss:NEventsMin=100:NEventsMax=200:MaxVIterations=150:VolumeRangeMode=Adaptive");
	//factory->BookMethod(dataloader,TMVA::Types::kKNN,"KNN","ScaleFrac=0.85:!H:!V");
	
	 //DNN
	//factory->BookMethod(dataloader,TMVA::Types::kDNN,"DNN","Architecture=GPU:Layout=RELU|150,RELU|100,RELU|50,SOFTSIGN:TrainingStrategy=LearningRate=1e-1,Momentum=0.3,Repetitions=3,ConvergenceSteps=20,BatchSize=30,TestRepetitions=10|LearningRate=1e-4,Momentum=0,Repetitions=3,ConvergenceSteps=50,BatchSize=30,TestRepetitions=10,Multithreading=True");

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
