void plot(){


  
  int start=1;
  int end = 2;
  char str[100];
  TH1F *hs[end],*hb[end];
  double min=10,max=100000;
  for(int i=start; i<end; i++){
    sprintf(str,"hs%d",i);
    hs[i] = new TH1F(str,"",750,min,max);
    sprintf(str,"hb%d",i);
    hb[i] = new TH1F(str,"Top detector in tower 1",750,min,max);
  }


  TFile fs("bdt_organise.root");
  TTree *ts = (TTree*)fs.Get("train_signal");
  TTree *tb = (TTree*)fs.Get("train_background");

  double x[end];
  for(int i=start; i<end; i++){
    sprintf(str,"Edep%d",i);
    ts->SetBranchAddress(str,&x[i]);
    tb->SetBranchAddress(str,&x[i]);
  }

  int nent = ts->GetEntries();

  for(int e=0; e<nent; e++){
    ts->GetEntry(e);
    for(int i=start; i<end; i++) {
        hs[i]->Fill(x[i]*1000);

    }
  }

  nent = tb->GetEntries();
  for(int e=0; e<nent; e++){
    tb->GetEntry(e);
    for(int i=start; i<end; i++) {
        hb[i]->Fill(x[i]*1000);

    }
  }


  TCanvas *c;
  for(int i=start; i<end; i++){
    sprintf(str,"c%d",i);
    c = new TCanvas(str,"",25,25,1000,800);
    c->SetLogy();
    c->SetLogx();
    c->SetLeftMargin(0.2);
    c->SetRightMargin(0.1);
    c->SetTopMargin(0.1);
    c->SetBottomMargin(0.17);

     //hs[i]->SetMinimum(0);
    hb[i]->SetMaximum(6000);
    sprintf(str,"Edep%d (KeV)",i);
    hb[i]->GetXaxis()->SetTitle(str);
    hb[i]->GetYaxis()->SetTitle("Counts");
    Int_t ci;      // for color index setting
    TColor *color; // for color definition with alpha
    ci = TColor::GetColor("#ff0000");
    hb[i]->SetFillColor(ci);
    hb[i]->SetLineColor(1);
    hb[i]->SetFillStyle(3008);
    hb[i]->Draw("HIST");
    ci = TColor::GetColor("#0000ff");
    hs[i]->SetFillColor(ci);
    hs[i]->SetLineColor(1);
    hs[i]->SetFillStyle(3010);
    hs[i]->Draw("same");
    TLegend *legend = new TLegend(0.78,0.775,0.98,0.94);
    legend->SetHeader("Legend","C");
    sprintf(str,"hs%d",i); 				// option "C" allows to center the header
    legend->AddEntry(str,"Signal","f");
    sprintf(str,"hb%d",i);
    legend->AddEntry(str,"Background","f");
    legend->Draw();

    sprintf(str,"plots/fig_x%d.eps ",i);
    c->SaveAs(str);
  }}
