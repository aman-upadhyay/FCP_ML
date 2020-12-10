#include <iostream> 
using namespace std; 
void app(const char *fname="dataset/weights/lips_bdt_DNN.weights.xml"){   //load this function in root

	double h;    //variable for soring response value, should be double
	float x[16];   // array to store value from application file
	int count_s = 0;
	int count_b = 0;
	double dummy[16];
	int pid;
	
	
	TMVA::Reader *reader = new TMVA::Reader("!Color:!Silent");  

  	TFile fs("CDMSlite_LIP.root");
	TTree *ts = (TTree*)fs.Get("tr1");
	
	
	
	ts->SetBranchAddress("PID",&pid);     
  	ts->SetBranchAddress("Edep1",&dummy[1]);
	reader->AddVariable("Edep1",&x[1]);
	ts->SetBranchAddress("Edep2",&dummy[2]);
	reader->AddVariable("Edep2",&x[2]);
	ts->SetBranchAddress("Edep3",&dummy[3]);
	reader->AddVariable("Edep3",&x[3]);
	ts->SetBranchAddress("Edep4",&dummy[4]);
	reader->AddVariable("Edep4",&x[4]);
	ts->SetBranchAddress("Edep5",&dummy[5]);
	reader->AddVariable("Edep5",&x[5]);
	ts->SetBranchAddress("Edep6",&dummy[6]);
	reader->AddVariable("Edep6",&x[6]);
	ts->SetBranchAddress("Edep7",&dummy[7]);
	reader->AddVariable("Edep7",&x[7]);
	ts->SetBranchAddress("Edep8",&dummy[8]);
	reader->AddVariable("Edep8",&x[8]);
	ts->SetBranchAddress("Edep9",&dummy[9]);
	reader->AddVariable("Edep9",&x[9]);
	ts->SetBranchAddress("Edep10",&dummy[10]);
	reader->AddVariable("Edep10",&x[10]);
	ts->SetBranchAddress("Edep11",&dummy[11]);
	reader->AddVariable("Edep11",&x[11]);
	ts->SetBranchAddress("Edep12",&dummy[12]);
	reader->AddVariable("Edep12",&x[12]);
	ts->SetBranchAddress("Edep13",&dummy[13]);
	reader->AddVariable("Edep13",&x[13]);
	ts->SetBranchAddress("Edep14",&dummy[14]);
	reader->AddVariable("Edep14",&x[14]);
	ts->SetBranchAddress("Edep15",&dummy[15]);
	reader->AddVariable("Edep15",&x[15]);
  	

	
	reader->BookMVA("DNN",fname);
	
	int nent = ts->GetEntries();
 	for(int e=0; e<nent; e++){
		ts->GetEntry(e);
		if(pid==22){
			if(dummy[1]>=0.001){x[1]=dummy[1];}
			else{x[1]=0;}
			if(dummy[2]>=0.001){x[2]=dummy[2];}
			else{x[2]=0;}
			if(dummy[3]>=0.001){x[3]=dummy[3];}
			else{x[3]=0;}
			if(dummy[4]>=0.001){x[4]=dummy[4];}
			else{x[4]=0;}
			if(dummy[5]>=0.001){x[5]=dummy[5];}
			else{x[5]=0;}
			if(dummy[6]>=0.001){x[6]=dummy[6];}
			else{x[6]=0;}
			if(dummy[7]>=0.001){x[7]=dummy[7];}
			else{x[7]=0;}
			if(dummy[8]>=0.001){x[8]=dummy[8];}
			else{x[8]=0;}
			if(dummy[9]>=0.001){x[9]=dummy[9];}
			else{x[9]=0;}
			if(dummy[10]>=0.001){x[10]=dummy[10];}
			else{x[10]=0;}
			if(dummy[11]>=0.001){x[11]=dummy[11];}
			else{x[11]=0;}
			if(dummy[12]>=0.001){x[12]=dummy[12];}
			else{x[12]=0;}
			if(dummy[13]>=0.001){x[13]=dummy[13];}
			else{x[13]=0;}
			if(dummy[14]>=0.0001){x[14]=dummy[14];}
			else{x[14]=0;}
			if(dummy[15]>=0.001){x[15]=dummy[15];}
			else{x[15]=0;}
			h=reader->EvaluateMVA("DNN");
			if(h>=0.19){
			count_s++;}
			else{
			count_b++;
			}
		}
			
	}
	cout<<count_s;
	cout<<"\n";
	cout<<count_b;
	cout<<"\n";

}
