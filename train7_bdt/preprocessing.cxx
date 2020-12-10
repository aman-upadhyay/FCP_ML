using namespace std; 

void preprocessing(){
	ROOT::EnableImplicitMT();
	char str[100];
	int PID,e,count;
	double Edep_go[16];
	double Edep_come[16];
	count=0;
	//output file
	TFile f("bdt_organise.root","recreate");
	TTree train_signal("train_signal",""),train_background("train_background",""),test_signal("test_signal",""),test_background("test_background","");
	for(int i=1; i<16; i++){
		sprintf(str,"Edep%d",i);
		train_signal.Branch(str,&Edep_go[i]);
		test_signal.Branch(str,&Edep_go[i]);
		train_background.Branch(str,&Edep_go[i]);
		test_background.Branch(str,&Edep_go[i]);
	}
	train_signal.Branch("count",&Edep_go[0]);
	test_signal.Branch("count",&Edep_go[0]);
	train_background.Branch("count",&Edep_go[0]);
	test_background.Branch("count",&Edep_go[0]);
	//input file
	TFile fs("CDMSlite_LIP.root");
	TTree *ts = (TTree*)fs.Get("tr1");
	
	ts->SetBranchAddress("PID",&PID);
	for(int i=1; i<16; i++){
		sprintf(str,"Edep%d",i);
		ts->SetBranchAddress(str,&Edep_come[i]);
	}
	
	int nent = ts->GetEntries();
	int x = nent*0.8;
 	for(int e=0; e<nent; e++)
	{
		ts->GetEntry(e);
		if(PID==-90){//signal
			if(Edep_come[1]>=0.001)
			{Edep_go[1]=Edep_come[1];
			count++;}
			else{Edep_go[1]=0;}
			if(Edep_come[2]>=0.001)
			{Edep_go[2]=Edep_come[2];
			count++;}
			else{Edep_go[2]=0;}
			if(Edep_come[3]>=0.001)
			{Edep_go[3]=Edep_come[3];
			count++;}
			else{Edep_go[3]=0;}
			if(Edep_come[4]>=0.001)
			{Edep_go[4]=Edep_come[4];
			count++;}
			else{Edep_go[4]=0;}
			if(Edep_come[5]>=0.001)
			{Edep_go[5]=Edep_come[5];
			count++;}
			else{Edep_go[5]=0;}
			if(Edep_come[6]>=0.001)
			{Edep_go[6]=Edep_come[6];
			count++;}
			else{Edep_go[6]=0;}
			if(Edep_come[7]>=0.001)
			{Edep_go[7]=Edep_come[7];
			count++;}
			else{Edep_go[7]=0;}
			if(Edep_come[8]>=0.001)
			{Edep_go[8]=Edep_come[8];
			count++;}
			else{Edep_go[8]=0;}
			if(Edep_come[9]>=0.001)
			{Edep_go[9]=Edep_come[9];
			count++;}
			else{Edep_go[9]=0;}
			if(Edep_come[10]>=0.001)
			{Edep_go[10]=Edep_come[10];
			count++;}
			else{Edep_go[10]=0;}
			if(Edep_come[11]>=0.001)
			{Edep_go[11]=Edep_come[11];
			count++;}
			else{Edep_go[11]=0;}
			if(Edep_come[12]>=0.001)
			{Edep_go[12]=Edep_come[12];
			count++;}
			else{Edep_go[12]=0;}
			if(Edep_come[13]>=0.001)
			{Edep_go[13]=Edep_come[13];
			count++;}
			else{Edep_go[13]=0;}
			if(Edep_come[14]>=0.0001)
			{Edep_go[14]=Edep_come[14];
			count++;}
			else{Edep_go[14]=0;}
			if(Edep_come[15]>=0.001)
			{Edep_go[15]=Edep_come[15];
			count++;}
			else{Edep_go[15]=0;}
			if(count==0){}
			else{
			Edep_go[0]=count;
			if(e<x){
			train_signal.Fill();
			count=0;}
			else{test_signal.Fill();
			count=0;}}
			
			}
		else{
			if(Edep_come[1]>=0.001)
			{Edep_go[1]=Edep_come[1];
			count++;}
			else{Edep_go[1]=0;}
			if(Edep_come[2]>=0.001)
			{Edep_go[2]=Edep_come[2];
			count++;}
			else{Edep_go[2]=0;}
			if(Edep_come[3]>=0.001)
			{Edep_go[3]=Edep_come[3];
			count++;}
			else{Edep_go[3]=0;}
			if(Edep_come[4]>=0.001)
			{Edep_go[4]=Edep_come[4];
			count++;}
			else{Edep_go[4]=0;}
			if(Edep_come[5]>=0.001)
			{Edep_go[5]=Edep_come[5];
			count++;}
			else{Edep_go[5]=0;}
			if(Edep_come[6]>=0.001)
			{Edep_go[6]=Edep_come[6];
			count++;}
			else{Edep_go[6]=0;}
			if(Edep_come[7]>=0.001)
			{Edep_go[7]=Edep_come[7];
			count++;}
			else{Edep_go[7]=0;}
			if(Edep_come[8]>=0.001)
			{Edep_go[8]=Edep_come[8];
			count++;}
			else{Edep_go[8]=0;}
			if(Edep_come[9]>=0.001)
			{Edep_go[9]=Edep_come[9];
			count++;}
			else{Edep_go[9]=0;}
			if(Edep_come[10]>=0.001)
			{Edep_go[10]=Edep_come[10];
			count++;}
			else{Edep_go[10]=0;}
			if(Edep_come[11]>=0.001)
			{Edep_go[11]=Edep_come[11];
			count++;}
			else{Edep_go[11]=0;}
			if(Edep_come[12]>=0.001)
			{Edep_go[12]=Edep_come[12];
			count++;}
			else{Edep_go[12]=0;}
			if(Edep_come[13]>=0.001)
			{Edep_go[13]=Edep_come[13];
			count++;}
			else{Edep_go[13]=0;}
			if(Edep_come[14]>=0.0001)
			{Edep_go[14]=Edep_come[14];
			count++;}
			else{Edep_go[14]=0;}
			if(Edep_come[15]>=0.001)
			{Edep_go[15]=Edep_come[15];
			count++;}
			else{Edep_go[15]=0;}
			if(count==0){}
			else{
			Edep_go[0]=count;
			if(e<x){
			train_background.Fill();
			count=0;}
			else{test_background.Fill();
			count=0;}}
		}
	}
	f.cd();
	train_signal.Write();
	test_signal.Write();
	train_background.Write();
	test_background.Write();
}
