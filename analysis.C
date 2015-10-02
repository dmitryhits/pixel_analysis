#define analysis_cxx
#include "analysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TProfile.h>

using namespace std;

void analysis::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L analysis.C
//      Root > analysis t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;
   TH1F* h_signal = new TH1F("h_signal","signal",150,-1000,+30000);
   TH1F* h_signal_high = new TH1F("h_signal_high","signal high signal region",150,-1000,+30000);
   TH1F* h_signal_low = new TH1F("h_signal_low","signal low signal region",150,-1000,+30000);
   TH2F* h_ave_signal_2D = new TH2F("h_signal_2D","signal vs xy",100,-0.25,0.2,100,-0.2,0.3);
   TH2F* h_ave_signal_2D_norm = new TH2F("h_signal_2D_norm","number of events vs xy",100,-0.25,0.2,100,-0.2,0.3);
   TProfile* h_ave_high_signal_vs_time = new TProfile("h_ave_high_signal_vs_time","signal in high signal region vs time",200,0,4e6,0,3e4);
   TProfile* h_ave_low_signal_vs_time = new TProfile("h_ave_low_signal_vs_time","signal in low signal region vs time",200,0,4e6,0,3e4);
   TProfile* h_ave_signal_vs_time = new TProfile("h_ave_signal_vs_time","signal vs time",200,0,4e6,0,3e4);

   Long64_t nentries = fChain->GetEntriesFast();
   float start_time = 0;
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      if(jentry==0) { 
	start_time = time;
	cout << start_time <<endl;
      }
      if(n_tracks==1) {
	h_signal->Fill(charge_all_ROC4->front());
	h_ave_signal_vs_time->Fill(time-start_time,charge_all_ROC4->front(),1);
	h_ave_signal_2D->Fill(diam1_track_x,diam1_track_y,charge_all_ROC4->front());
	h_ave_signal_2D_norm->Fill(diam1_track_x,diam1_track_y);
	///cut on a high signal
	if(diam1_track_x>-0.1 && diam1_track_x<0.0 && diam1_track_y>0.05 && diam1_track_y<0.15) {
	  h_signal_high->Fill(charge_all_ROC4->front());
	  h_ave_high_signal_vs_time->Fill(time-start_time,charge_all_ROC4->front(),1);
	}
	///cut on a low signal
	if(diam1_track_x>.05 && diam1_track_x<0.17 && diam1_track_y>-0.1 && diam1_track_y<0.05) {
	  h_signal_low->Fill(charge_all_ROC4->front());
	  h_ave_low_signal_vs_time->Fill(time-start_time,charge_all_ROC4->front(),1);
	}
      }
      // if (Cut(ientry) < 0) continue;
   }
   TCanvas* c1 = new TCanvas("c1");
   c1->Divide(2,3);
   c1->cd(1);
   h_signal->Draw();
   c1->cd(2);
   h_ave_signal_2D->Divide(h_ave_signal_2D_norm);
   h_ave_signal_2D->SetStats(kFALSE);
   h_ave_signal_2D->Draw("colz");
   h_ave_signal_2D->GetZaxis()->SetRangeUser(0,15000);
   c1->cd(3);
   h_ave_signal_2D_norm->SetStats(kFALSE);
   h_ave_signal_2D_norm->Draw("colz");
   c1->cd(4);
   h_signal_low->Draw();
   //h_signal_high->GetYaxis()->SetRangeUser(0,2000);
   h_signal_low->SetLineColor(kRed);
   h_signal_high->Draw("sames");
   c1->cd(5);
   h_ave_high_signal_vs_time->Draw();
   h_ave_high_signal_vs_time->GetYaxis()->SetRangeUser(0,15000);
   h_ave_low_signal_vs_time->SetLineColor(kRed);
   h_ave_low_signal_vs_time->Draw("same");
   c1->cd(6);
   h_ave_signal_vs_time->Draw();
   h_ave_signal_vs_time->GetYaxis()->SetRangeUser(0,15000);
}
