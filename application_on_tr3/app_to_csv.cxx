#include <iostream> 
#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair
using namespace std; 


void write_csv(std::string filename, std::vector<std::pair<std::string, std::vector<int>>> dataset){
    // Make a CSV file with one or more columns of integer values
    // Each column of data is represented by the pair <column name, column data>
    //   as std::pair<std::string, std::vector<int>>
    // The dataset is represented as a vector of these columns
    // Note that all columns should be the same size
    
    // Create an output filestream object
    std::ofstream myFile(filename);
    
    // Send column names to the stream
    for(int j = 0; j < dataset.size(); ++j)
    {
        myFile << dataset.at(j).first;
        if(j != dataset.size() - 1) myFile << ","; // No comma at end of line
    }
    myFile << "\n";
    
    // Send data to the stream
    for(int i = 0; i < dataset.at(0).second.size(); ++i)
    {
        for(int j = 0; j < dataset.size(); ++j)
        {
            myFile << dataset.at(j).second.at(i);
            if(j != dataset.size() - 1) myFile << ","; // No comma at end of line
        }
        myFile << "\n";
    }
    
    // Close the file
    myFile.close();
}


void app_to_csv(const char *fname="dataset/weights/lips_bdt_KNN.weights.xml"){   //load this function in root

	double h;    //variable for soring response value, should be double
	float x[16];   // array to store value from application file
	double dummy[16];
	int pid;
	std::vector<int> vec1;   //  label i.e if fcp then charge of the fcp or else gamma or muon
	std::vector<int> vec2;   //   result from prediction
	std::vector<int> vec3;   //   true label
	
	TMVA::Reader *reader = new TMVA::Reader("!Color:!Silent");  


	reader->AddVariable("Edep1",&x[1]);
	reader->AddVariable("Edep2",&x[2]);
	reader->AddVariable("Edep3",&x[3]);
	reader->AddVariable("Edep4",&x[4]);
	reader->AddVariable("Edep5",&x[5]);
	reader->AddVariable("Edep6",&x[6]);
	reader->AddVariable("Edep7",&x[7]);
	reader->AddVariable("Edep8",&x[8]);
	reader->AddVariable("Edep9",&x[9]);
	reader->AddVariable("Edep10",&x[10]);
	reader->AddVariable("Edep11",&x[11]);
	reader->AddVariable("Edep12",&x[12]);
	reader->AddVariable("Edep13",&x[13]);
	reader->AddVariable("Edep14",&x[14]);
	reader->AddVariable("Edep15",&x[15]);
	
	reader->BookMVA("KNN",fname);
	
	
	
  	TFile fs("CDMSlite_LIP.root");
	TTree *ts = (TTree*)fs.Get("tr1");
	
	
	
	ts->SetBranchAddress("PID",&pid);     
  	ts->SetBranchAddress("Edep1",&dummy[1]);
	ts->SetBranchAddress("Edep2",&dummy[2]);
	ts->SetBranchAddress("Edep3",&dummy[3]);
	ts->SetBranchAddress("Edep4",&dummy[4]);
	ts->SetBranchAddress("Edep5",&dummy[5]);
	ts->SetBranchAddress("Edep6",&dummy[6]);
	ts->SetBranchAddress("Edep7",&dummy[7]);
	ts->SetBranchAddress("Edep8",&dummy[8]);
	ts->SetBranchAddress("Edep9",&dummy[9]);
	ts->SetBranchAddress("Edep10",&dummy[10]);
	ts->SetBranchAddress("Edep11",&dummy[11]);
	ts->SetBranchAddress("Edep12",&dummy[12]);
	ts->SetBranchAddress("Edep13",&dummy[13]);
	ts->SetBranchAddress("Edep14",&dummy[14]);
	ts->SetBranchAddress("Edep15",&dummy[15]);
	
  	

	
	
	
	int nent = ts->GetEntries();
 	for(int e=0; e<nent; e++){
		ts->GetEntry(e);
		if(pid==22||pid==-13){
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
			h=reader->EvaluateMVA("KNN");
			if(h>=0.81){
			vec1.push_back(pid);
			vec2.push_back(1);
			vec3.push_back(0);}
			else{
			vec1.push_back(pid);
			vec2.push_back(0);
			vec3.push_back(0);
			}
		}
	}
	
	TFile fs2("CDMSlite_LIP_2.root");
	TTree *ts2 = (TTree*)fs2.Get("tr1");
	
	ts2->SetBranchAddress("PID",&pid);     
  	ts2->SetBranchAddress("Edep1",&dummy[1]);
	
	ts2->SetBranchAddress("Edep2",&dummy[2]);
	ts2->SetBranchAddress("Edep3",&dummy[3]);
	ts2->SetBranchAddress("Edep4",&dummy[4]);
	ts2->SetBranchAddress("Edep5",&dummy[5]);
	ts2->SetBranchAddress("Edep6",&dummy[6]);
	ts2->SetBranchAddress("Edep7",&dummy[7]);
	ts2->SetBranchAddress("Edep8",&dummy[8]);
	ts2->SetBranchAddress("Edep9",&dummy[9]);
	ts2->SetBranchAddress("Edep10",&dummy[10]);
	ts2->SetBranchAddress("Edep11",&dummy[11]);
	ts2->SetBranchAddress("Edep12",&dummy[12]);
	ts2->SetBranchAddress("Edep13",&dummy[13]);
	ts2->SetBranchAddress("Edep14",&dummy[14]);
	ts2->SetBranchAddress("Edep15",&dummy[15]);
	
	int nent2 = ts2->GetEntries();
 	for(int e=0; e<nent2; e++){
		ts2->GetEntry(e);
		if(pid==-90){
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
			h=reader->EvaluateMVA("KNN");
			if(h>=0.81){
			vec1.push_back(2);
			vec2.push_back(1);
			vec3.push_back(1);}
			else{
			vec1.push_back(2);
			vec2.push_back(0);
			vec3.push_back(1);
			}
		}
	}
	
	TFile fs5("CDMSlite_LIP_5.root");
	TTree *ts5 = (TTree*)fs5.Get("tr1");
	
	ts5->SetBranchAddress("PID",&pid);     
  	ts5->SetBranchAddress("Edep1",&dummy[1]);
	ts5->SetBranchAddress("Edep2",&dummy[2]);
	ts5->SetBranchAddress("Edep3",&dummy[3]);
	ts5->SetBranchAddress("Edep4",&dummy[4]);
	ts5->SetBranchAddress("Edep5",&dummy[5]);
	ts5->SetBranchAddress("Edep6",&dummy[6]);
	ts5->SetBranchAddress("Edep7",&dummy[7]);
	ts5->SetBranchAddress("Edep8",&dummy[8]);
	ts5->SetBranchAddress("Edep9",&dummy[9]);
	ts5->SetBranchAddress("Edep10",&dummy[10]);
	ts5->SetBranchAddress("Edep11",&dummy[11]);
	ts5->SetBranchAddress("Edep12",&dummy[12]);
	ts5->SetBranchAddress("Edep13",&dummy[13]);
	ts5->SetBranchAddress("Edep14",&dummy[14]);
	ts5->SetBranchAddress("Edep15",&dummy[15]);
	
	int nent5 = ts5->GetEntries();
 	for(int e=0; e<nent5; e++){
		ts5->GetEntry(e);
		if(pid==-90){
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
			h=reader->EvaluateMVA("KNN");
			if(h>=0.81){
			vec1.push_back(5);
			vec2.push_back(1);
			vec3.push_back(1);}
			else{
			vec1.push_back(5);
			vec2.push_back(0);
			vec3.push_back(1);
			}
		}
	}
	
	
	TFile fs10("CDMSlite_LIP_10.root");
	TTree *ts10 = (TTree*)fs10.Get("tr1");
	
	ts10->SetBranchAddress("PID",&pid);     
  	ts10->SetBranchAddress("Edep1",&dummy[1]);
	ts10->SetBranchAddress("Edep2",&dummy[2]);
	ts10->SetBranchAddress("Edep3",&dummy[3]);
	ts10->SetBranchAddress("Edep4",&dummy[4]);
	ts10->SetBranchAddress("Edep5",&dummy[5]);
	ts10->SetBranchAddress("Edep6",&dummy[6]);
	ts10->SetBranchAddress("Edep7",&dummy[7]);
	ts10->SetBranchAddress("Edep8",&dummy[8]);
	ts10->SetBranchAddress("Edep9",&dummy[9]);
	ts10->SetBranchAddress("Edep10",&dummy[10]);
	ts10->SetBranchAddress("Edep11",&dummy[11]);
	ts10->SetBranchAddress("Edep12",&dummy[12]);
	ts10->SetBranchAddress("Edep13",&dummy[13]);
	ts10->SetBranchAddress("Edep14",&dummy[14]);
	ts10->SetBranchAddress("Edep15",&dummy[15]);
	
	
	int nent10 = ts10->GetEntries();
 	for(int e=0; e<nent10; e++){
		ts10->GetEntry(e);
		if(pid==-90){
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
			h=reader->EvaluateMVA("KNN");
			if(h>=0.81){
			vec1.push_back(10);
			vec2.push_back(1);
			vec3.push_back(1);}
			else{
			vec1.push_back(10);
			vec2.push_back(0);
			vec3.push_back(1);
			}
		}
	}
	
	
	TFile fs100("CDMSlite_LIP_100.root");
	TTree *ts100 = (TTree*)fs100.Get("tr1");
	
	ts100->SetBranchAddress("PID",&pid);     
  	ts100->SetBranchAddress("Edep1",&dummy[1]);
	ts100->SetBranchAddress("Edep2",&dummy[2]);
	ts100->SetBranchAddress("Edep3",&dummy[3]);
	ts100->SetBranchAddress("Edep4",&dummy[4]);
	ts100->SetBranchAddress("Edep5",&dummy[5]);
	ts100->SetBranchAddress("Edep6",&dummy[6]);
	ts100->SetBranchAddress("Edep7",&dummy[7]);
	ts100->SetBranchAddress("Edep8",&dummy[8]);
	ts100->SetBranchAddress("Edep9",&dummy[9]);
	ts100->SetBranchAddress("Edep10",&dummy[10]);
	ts100->SetBranchAddress("Edep11",&dummy[11]);
	ts100->SetBranchAddress("Edep12",&dummy[12]);
	ts100->SetBranchAddress("Edep13",&dummy[13]);
	ts100->SetBranchAddress("Edep14",&dummy[14]);
	ts100->SetBranchAddress("Edep15",&dummy[15]);
	
	
	int nent100 = ts100->GetEntries();
 	for(int e=0; e<nent100; e++){
		ts100->GetEntry(e);
		if(pid==-90){
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
			h=reader->EvaluateMVA("KNN");
			if(h>=0.81){
			vec1.push_back(100);
			vec2.push_back(1);
			vec3.push_back(1);}
			else{
			vec1.push_back(100);
			vec2.push_back(0);
			vec3.push_back(1);
			}
		}
	}
	

	TFile fs1000("CDMSlite_LIP_1000.root");
	TTree *ts1000 = (TTree*)fs1000.Get("tr1");
	
	ts1000->SetBranchAddress("PID",&pid);     
  	ts1000->SetBranchAddress("Edep1",&dummy[1]);
	ts1000->SetBranchAddress("Edep2",&dummy[2]);
	ts1000->SetBranchAddress("Edep3",&dummy[3]);
	ts1000->SetBranchAddress("Edep4",&dummy[4]);
	ts1000->SetBranchAddress("Edep5",&dummy[5]);
	ts1000->SetBranchAddress("Edep6",&dummy[6]);
	ts1000->SetBranchAddress("Edep7",&dummy[7]);
	ts1000->SetBranchAddress("Edep8",&dummy[8]);
	ts1000->SetBranchAddress("Edep9",&dummy[9]);
	ts1000->SetBranchAddress("Edep10",&dummy[10]);
	ts1000->SetBranchAddress("Edep11",&dummy[11]);
	ts1000->SetBranchAddress("Edep12",&dummy[12]);
	ts1000->SetBranchAddress("Edep13",&dummy[13]);
	ts1000->SetBranchAddress("Edep14",&dummy[14]);
	ts1000->SetBranchAddress("Edep15",&dummy[15]);
	
	
	int nent1000 = ts1000->GetEntries();
 	for(int e=0; e<nent1000; e++){
		ts1000->GetEntry(e);
		if(pid==-90){
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
			h=reader->EvaluateMVA("KNN");
			if(h>=0.81){
			vec1.push_back(1000);
			vec2.push_back(1);
			vec3.push_back(1);}
			else{
			vec1.push_back(1000);
			vec2.push_back(0);
			vec3.push_back(1);
			}
		}
	}
	
	
	std::vector<std::pair<std::string, std::vector<int>>> vals = {{"Label", vec1}, {"Prediction", vec2}, {"True_label", vec3}};
	// Write the vector to CSV
	write_csv("predicted_dataset.csv", vals);
}
