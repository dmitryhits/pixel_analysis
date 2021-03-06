//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Sep 30 16:42:06 2015 by ROOT version 5.34/22
// from TTree tree/a simple Tree with simple variables
// found on file: test150800343_withTracks.root
//////////////////////////////////////////////////////////

#ifndef analysis_h
#define analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class analysis {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           event_number;
   Float_t         time;
   Int_t           pulser;
   Float_t         pulser_int;
   Int_t           trig_time;
   Int_t           nwfs;
   vector<string>  *sensor_name;
   vector<string>  *type_name;
   vector<float>   *ped;
   vector<float>   *sig;
   vector<float>   *sig_time;
   vector<int>     *plane;
   vector<int>     *col;
   vector<int>     *row;
   vector<int>     *adc;
   vector<int>     *charge;
   UChar_t         hit_plane_bits;
   Float_t         diam1_track_x;
   Float_t         diam1_track_y;
   Float_t         diam2_track_x;
   Float_t         diam2_track_y;
   Float_t         dist_to_dia1;
   Float_t         dist_to_dia2;
   Float_t         chi2;
   Float_t         chi2_x;
   Float_t         chi2_y;
   Float_t         slope_x;
   Float_t         slope_y;
   UChar_t         n_tracks;
   UChar_t         n_clusters;
   vector<float>   *charge_all_ROC0;
   vector<float>   *charge_all_ROC1;
   vector<float>   *charge_all_ROC2;
   vector<float>   *charge_all_ROC3;
   vector<float>   *charge_all_ROC4;
   vector<float>   *charge_all_ROC5;
   vector<float>   *charge_all_ROC6;

   // List of branches
   TBranch        *b_event_number;   //!
   TBranch        *b_time;   //!
   TBranch        *b_pulser;   //!
   TBranch        *b_pulser_int;   //!
   TBranch        *b_trig_time;   //!
   TBranch        *b_n_waveforms;   //!
   TBranch        *b_sensor_name;   //!
   TBranch        *b_type_name;   //!
   TBranch        *b_ped;   //!
   TBranch        *b_sig;   //!
   TBranch        *b_sig_time;   //!
   TBranch        *b_plane;   //!
   TBranch        *b_col;   //!
   TBranch        *b_row;   //!
   TBranch        *b_adc;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_hit_plane_bits;   //!
   TBranch        *b_diam1_track_x;   //!
   TBranch        *b_diam1_track_y;   //!
   TBranch        *b_diam2_track_x;   //!
   TBranch        *b_diam2_track_y;   //!
   TBranch        *b_dist_to_dia1;   //!
   TBranch        *b_dist_to_dia2;   //!
   TBranch        *b_chi2;   //!
   TBranch        *b_chi2_x;   //!
   TBranch        *b_chi2_y;   //!
   TBranch        *b_slope_x;   //!
   TBranch        *b_slope_y;   //!
   TBranch        *b_n_tracks;   //!
   TBranch        *b_n_clusters;   //!
   TBranch        *b_charge_all_ROC0;   //!
   TBranch        *b_charge_all_ROC1;   //!
   TBranch        *b_charge_all_ROC2;   //!
   TBranch        *b_charge_all_ROC3;   //!
   TBranch        *b_charge_all_ROC4;   //!
   TBranch        *b_charge_all_ROC5;   //!
   TBranch        *b_charge_all_ROC6;   //!

   analysis(TTree *tree=0);
   virtual ~analysis();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef analysis_cxx
analysis::analysis(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("test150800328_withTracks.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("test150800328_withTracks.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

analysis::~analysis()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t analysis::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t analysis::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void analysis::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   sensor_name = 0;
   type_name = 0;
   ped = 0;
   sig = 0;
   sig_time = 0;
   plane = 0;
   col = 0;
   row = 0;
   adc = 0;
   charge = 0;
   charge_all_ROC0 = 0;
   charge_all_ROC1 = 0;
   charge_all_ROC2 = 0;
   charge_all_ROC3 = 0;
   charge_all_ROC4 = 0;
   charge_all_ROC5 = 0;
   charge_all_ROC6 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("event_number", &event_number, &b_event_number);
   fChain->SetBranchAddress("time", &time, &b_time);
   fChain->SetBranchAddress("pulser", &pulser, &b_pulser);
   fChain->SetBranchAddress("pulser_int", &pulser_int, &b_pulser_int);
   fChain->SetBranchAddress("trig_time", &trig_time, &b_trig_time);
   fChain->SetBranchAddress("nwfs", &nwfs, &b_n_waveforms);
   fChain->SetBranchAddress("sensor_name", &sensor_name, &b_sensor_name);
   fChain->SetBranchAddress("type_name", &type_name, &b_type_name);
   fChain->SetBranchAddress("ped", &ped, &b_ped);
   fChain->SetBranchAddress("sig", &sig, &b_sig);
   fChain->SetBranchAddress("sig_time", &sig_time, &b_sig_time);
   fChain->SetBranchAddress("plane", &plane, &b_plane);
   fChain->SetBranchAddress("col", &col, &b_col);
   fChain->SetBranchAddress("row", &row, &b_row);
   fChain->SetBranchAddress("adc", &adc, &b_adc);
   fChain->SetBranchAddress("charge", &charge, &b_charge);
   fChain->SetBranchAddress("hit_plane_bits", &hit_plane_bits, &b_hit_plane_bits);
   fChain->SetBranchAddress("diam1_track_x", &diam1_track_x, &b_diam1_track_x);
   fChain->SetBranchAddress("diam1_track_y", &diam1_track_y, &b_diam1_track_y);
   fChain->SetBranchAddress("diam2_track_x", &diam2_track_x, &b_diam2_track_x);
   fChain->SetBranchAddress("diam2_track_y", &diam2_track_y, &b_diam2_track_y);
   fChain->SetBranchAddress("dist_to_dia1", &dist_to_dia1, &b_dist_to_dia1);
   fChain->SetBranchAddress("dist_to_dia2", &dist_to_dia2, &b_dist_to_dia2);
   fChain->SetBranchAddress("chi2", &chi2, &b_chi2);
   fChain->SetBranchAddress("chi2_x", &chi2_x, &b_chi2_x);
   fChain->SetBranchAddress("chi2_y", &chi2_y, &b_chi2_y);
   fChain->SetBranchAddress("slope_x", &slope_x, &b_slope_x);
   fChain->SetBranchAddress("slope_y", &slope_y, &b_slope_y);
   fChain->SetBranchAddress("n_tracks", &n_tracks, &b_n_tracks);
   fChain->SetBranchAddress("n_clusters", &n_clusters, &b_n_clusters);
   fChain->SetBranchAddress("charge_all_ROC0", &charge_all_ROC0, &b_charge_all_ROC0);
   fChain->SetBranchAddress("charge_all_ROC1", &charge_all_ROC1, &b_charge_all_ROC1);
   fChain->SetBranchAddress("charge_all_ROC2", &charge_all_ROC2, &b_charge_all_ROC2);
   fChain->SetBranchAddress("charge_all_ROC3", &charge_all_ROC3, &b_charge_all_ROC3);
   fChain->SetBranchAddress("charge_all_ROC4", &charge_all_ROC4, &b_charge_all_ROC4);
   fChain->SetBranchAddress("charge_all_ROC5", &charge_all_ROC5, &b_charge_all_ROC5);
   fChain->SetBranchAddress("charge_all_ROC6", &charge_all_ROC6, &b_charge_all_ROC6);
   Notify();
}

Bool_t analysis::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void analysis::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t analysis::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef analysis_cxx
