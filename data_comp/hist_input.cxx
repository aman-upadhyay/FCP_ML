#include <iostream>
#include <fstream>


void hist_input(){
	Double_t en,count;
	ifstream fdata;
	TH1F *h1,*h2,*h3;
	/*fdata.open("U_gamma.dat");
	h1 = new TH1F("u_gamma","U_gamma",221,0,2.21);
	fdata>>en>>count;
	for(Int_t bin=1; bin<=2221; bin++){
	fdata>>en>>count;
	h1->SetBinContent(bin,count);		// Use to fill histogram
	}
fdata.close();
h1->SaveAs("U_gamma.root");
    h1->GetXaxis()->SetTitle("Energy (MeV)");
    h1->GetYaxis()->SetTitle("Counts");
TLegend *legend = new TLegend(0.78,0.775,0.98,0.94);
legend->SetHeader("Legend","C"); 				// option "C" allows to center the header
legend->AddEntry("h1","U_gamma","f");
legend->Draw();
//h1->SaveAs("U_gamma.eps");
h1->Draw("HIST");
	fdata.open("SnoLab_neutron_albedo.dat");
	h2 = new TH1F("SnoLab_neutron_albedo","SnoLab_neutron",997,0,10);
	fdata>>en>>count;
	for(Int_t bin=1; bin<=997; bin++){
	fdata>>en>>count;
	h2->SetBinContent(bin,count);		// Use to fill histogram
	}
fdata.close();
h2->SaveAs("SnoLab_neutron_albedo.root");
h2->GetXaxis()->SetTitle("Energy (MeV)");
h2->GetYaxis()->SetTitle("Counts");
//h2->SaveAs("SnoLab_neutron_albedo.eps");
h2->Draw("HIST");*/
	fdata.open("SnoLab_Th-gamma_albedo.dat");
	h3 = new TH1F("SnoLab_Th-gamma_albedo","SnoLab_Th-gamma",262,0,2.62);
	fdata>>en>>count;
	for(Int_t bin=1; bin<=262; bin++){
	fdata>>en>>count;
	h3->SetBinContent(bin,count);		// Use to fill histogram
	}
fdata.close();
h3->SaveAs("SnoLab_Th-gamma_albedo.root");
h3->GetXaxis()->SetTitle("Energy (MeV)");
h3->GetYaxis()->SetTitle("Counts");
//h3->SaveAs("SnoLab_Th-gamma_albedo.eps");
h3->Draw("HIST");
	
}
