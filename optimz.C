#include "TH1F.h"
#include "TH2F.h"
#include <vector>
#include "TLorentzVector.h"
void optimz(){
  gStyle->SetOptStat(0);
  //TFile *f1 = TFile::Open("/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2016/Signal/FH_NLO_2016_hadded/GluGluToHHTo2G4Q_node_cHHH1_2016.root");
  //TFile *f1 = TFile::Open("/eos/user/l/lipe/ntuple/2017/Signal/FH_NLO_2017_Hadded_March/GluGluToHHTo2G4Q_node_cHHH5_2017.root");
  //TFile *f1 = TFile::Open("/eos/user/l/lipe/ntuple/2017/Signal/FHZZ_NLO_2017_Hadded_March/GluGluToHHTo2G2ZTo2G4Q_node_cHHH0_2017.root");
  //TFile *f1 = TFile::Open("/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2018/Signal/FH_NLO_2018_hadded/GluGluToHHTo2G4Q_node_cHHH1_2018.root");
  TFile *f1 = TFile::Open("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Signal/GluGluToHHTo2G4Q_node_cHHH1_2017.root");
  
  TFile *f2 = TFile::Open("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Data/allData.root");
  //TFile *f2 = TFile::Open("/eos/user/l/lipe/ntuple/2017/Data/Data_2017_Hadded_Combined/Data_2017.root");
  //TFile *f2 = TFile::Open("/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2018/Data_Trees/Data_2018.root");

  TFile *f3 = TFile::Open("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/GluGluHToGG_M125_TuneCP5_13TeV.root");
  //TFile *f3 = TFile::Open("/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2016/Single_H_hadded/GluGluHToGG_M125.root");
  //TFile *f3 = TFile::Open("/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2018/Single_H_2018_hadded/GluGluHToGG_M125.root");

  TFile *f4 = TFile::Open("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/ttHJetToGG_M125_13TeV.root");
  //TFile *f4 = TFile::Open("/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2016/Single_H_hadded/ttHJetToGG_M125.root");
  //TFile *f4 = TFile::Open("/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2018/Single_H_2018_hadded/ttHJetToGG_M125.root");

  TFile *f5 = TFile::Open("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/VBFHToGG_M125_13TeV.root");
  //TFile *f5 = TFile::Open("/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2016/Single_H_hadded/VBFHToGG_M125.root");
  //TFile *f5 = TFile::Open("/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2018/Single_H_2018_hadded/VBFHToGG_M125.root");

  TFile *f6 = TFile::Open("/eos/user/r/rasharma/post_doc_ihep/double-higgs/ntuples/January_2021_Production/DNN_MoreVar/Backgrounds/VHToGG_M125_13TeV.root");
  //TFile *f6 = TFile::Open("/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2016/Single_H_hadded/VHToGG_M125.root");
  //TFile *f6 = TFile::Open("/eos/user/a/atishelm/ntuples/HHWWgg_flashgg/January_2021_Production/2018/Single_H_2018_hadded/VHToGG_M125.root");
  
 
  TTree *t1 = (TTree*)f1->Get("tagsDumper/trees/GluGluToHHTo2G4Q_node_cHHH1_13TeV_HHWWggTag_1");
  TTree *t2 = (TTree*)f2->Get("tagsDumper/trees/Data_13TeV_HHWWggTag_1");
  TTree *t3 = (TTree*)f3->Get("tagsDumper/trees/ggh_125_13TeV_HHWWggTag_1");
  TTree *t4 = (TTree*)f4->Get("tagsDumper/trees/tth_125_13TeV_HHWWggTag_1");
  TTree *t5 = (TTree*)f5->Get("tagsDumper/trees/vbf_125_13TeV_HHWWggTag_1");
  TTree *t6 = (TTree*)f6->Get("tagsDumper/trees/wzh_125_13TeV_HHWWggTag_1");
  
  //create histograms
  
  TH1F *preselection = new TH1F("preselection","preselection;number",30,0,30);
  TH1F *AK8njet = new TH1F("AK8njet","AK8njet;number",30,0,30);
  TH1F *HGGpt_NLO = new TH1F("dipho_pT_NLO","dipho_pT_NLO;p_{T}(Hgg)",1000,0,1000);
  TH1F *HGGpt_Data = new TH1F("dipho_pT","dipho_pT;p_{T}(Hgg)",1000,0,1000);
  TH1F *HGGpt_ggh = new TH1F("HGGpt_ggh","HGGpt_ggh;pT",100,0,1000);
  TH1F *HGGpt_tth = new TH1F("HGGpt_ggh","HGGpt_tth;pT",100,0,1000);
  TH1F *HGGpt_vbf = new TH1F("HGGpt_ggh","HGGpt_vbf;pT",100,0,1000);
  TH1F *HGGpt_wzh = new TH1F("HGGpt_ggh","HGGpt_wzh;pT",100,0,1000);
  TH1F *HGGpt_singleH = new TH1F("HGGpt_singleH","HGGpt_singleH;p_{T}(Hgg)",1000,0,1000);
  TH1F *b_dis_1_NLO = new TH1F("b_dis_1_NLO","b_dis_1_NLO;b_dis",100,-1,3);
  TH1F *b_dis_1_Data = new TH1F("b_dis_1_Data","b_dis_1_Data;b_dis",100,-1,3);
  TH1F *b_dis_1_singleH = new TH1F("b_dis_1_singleH","b_dis_1_singleH;b_dis",100,-1,3);
  TH1F *b_dis_2_NLO = new TH1F("b_dis_2_NLO","b_dis_2_NLO;b_dis",100,-1,3);
  TH1F *b_dis_2_Data = new TH1F("b_dis_2_Data","b_dis_2_Data;b_dis",100,-1,3);
  TH1F *b_dis_2_singleH = new TH1F("b_dis_2_singleH","b_dis_2_singleH;b_dis",100,-1,3);
  TH1F *mH_105To160_NLO = new TH1F("mH_105To160_NLO","mH_105To160_NLO;label",50,-5,5);
  TH1F *mH_105To160_Data = new TH1F("mH_105To160_Data","mH_105To160_Data;label",50,-5,5);
  TH1F *mH_105To160_singleH = new TH1F("mH_105To160_singleH","mH_105To160_singleH;label",50,-5,5);
  TH1F *mW1_65To105_NLO = new TH1F("mH_105To160_NLO","mH_105To160_NLO;label",50,-5,5);
  TH1F *mW1_65To105_Data = new TH1F("mH_105To160_Data","mH_105To160_Data;label",50,-5,5);
  TH1F *mW1_65To105_singleH = new TH1F("mH_105To160_singleH","mH_105To160_singleH;label",50,-5,5);
  TH1F *Leading_Photon_MVA_NLO = new TH1F("Leading_Photon_MVA_NLO","Leading_Photon_MVA_NLO;MVA",50,-1,3);
  TH1F *Leading_Photon_MVA_Data = new TH1F("Leading_Photon_MVA_Data","Leading_Photon_MVA_Data;MVA",50,-1,3);
  TH1F *Leading_Photon_MVA_singleH = new TH1F("Leading_Photon_MVA_singleH","Leading_Photon_MVA_singleH;MVA",50,-1,3);
  TH1F *Subleading_Photon_MVA_NLO = new TH1F("Subleading_Photon_MVA_NLO","Subleading_Photon_MVA_NLO;MVA",50,-1,3);
  TH1F *Subleading_Photon_MVA_Data = new TH1F("Subleading_Photon_MVA_Data","Subleading_Photon_MVA_Data;MVA",50,-1,3);
  TH1F *Subleading_Photon_MVA_singleH = new TH1F("Subleading_Photon_MVA_singleH","Subleading_Photon_MVA_singleH;MVA",50,-1,3);
  TH1F *goodJets_0_pt_NLO = new TH1F("goodJets_0_pt_NLO","goodJets_0_pt_NLO;pT",100,0,1000);
  TH1F *goodJets_0_pt_Data = new TH1F("goodJets_0_pt_Data","goodJets_0_pt_Data;pT",100,0,1000);
  TH1F *goodJets_0_pt_singleH = new TH1F("goodJets_0_pt_singleH","goodJets_0_pt_singleH;pT",100,0,1000);
  TH1F *goodJets_1_pt_NLO = new TH1F("goodJets_1_pt_NLO","goodJets_1_pt_NLO;pT",100,0,1000);
  TH1F *goodJets_1_pt_Data = new TH1F("goodJets_1_pt_Data","goodJets_1_pt_Data;pT",100,0,1000);
  TH1F *goodJets_1_pt_singleH = new TH1F("goodJets_1_pt_singleH","goodJets_1_pt_singleH;pT",100,0,1000);
  TH1F *DeltaPhi_HH_NLO = new TH1F("DeltaPhi_HH","#Delta #phi(HH);#Delta #phi(HH)",30,-1,4);
  TH1F *DeltaPhi_HH_Data = new TH1F("DeltaPhi_HH_Data","DeltaPhi_HH_Data;Phi",30,-1,4);
  TH1F *DeltaPhi_HH_singleH = new TH1F("DeltaPhi_HH_singleH","DeltaPhi_HH_singleH;Phi",30,-1,4);
  TH1F *DeltaR_HH_NLO = new TH1F("DeltaR_HH_NLO","DeltaR_HH_NLO;dR",1000,0,10);
  TH1F *DeltaR_HH_Data = new TH1F("DeltaR_HH_Data","DeltaR_HH_Data;dR",1000,0,10);
  TH1F *DeltaR_HH_singleH = new TH1F("DeltaR_HH_singleH","DeltaR_HH_singleH;dR",1000,0,10);
  TH1F *dipho_MVA_NLO = new TH1F("dipho_MVA_NLO","dipho_MVA_NLO;dipho_MVA",50,-1,2);
  TH1F *dipho_MVA_Data = new TH1F("dipho_MVA_Data","dipho_MVA_Data;dipho_MVA",50,-1,2);
  TH1F *dipho_MVA_singleH = new TH1F("dipho_MVA_singleH","dipho_MVA_singleH;dipho_MVA",50,-1,2);
  TH1F *ZeroVtx_z_NLO = new TH1F("ZeroVtx_z_NLO","ZeroVtx_z_NLO;ZeroVtx_z",100,-15,15);
  TH1F *ZeroVtx_z_Data = new TH1F("ZeroVtx_z_Data","ZeroVtx_z_Data;ZeroVtx_z",100,-15,15);
  TH1F *ZeroVtx_z_singleH = new TH1F("ZeroVtx_z_singleH","ZeroVtx_z_singleH;ZeroVtx_z",100,-15,15);
  TH1F *GenVtx_z_NLO = new TH1F("GenVtx_z_NLO","GenVtx_z_NLO;GenVtx_z",100,-15,15);
  TH1F *dZ_NLO = new TH1F("dZ_NLO","dZ_NLO;dZ",100,-0.01,0.01);
  TH1F *dZ_Data = new TH1F("dZ_Data","dZ_Data;dZ",100,-1,1);
  TH1F *dZ_singleH = new TH1F("dZ_singleH","dZ_singleH;dZ",100,-0.01,0.01);
  TH1F *HHCandidate_pt_NLO = new TH1F("HHCandidate_pt_NLO","HHCandidate_pt_NLO;pT",100,0,800);
  TH1F *HHCandidate_pt_Data = new TH1F("HHCandidate_pt_Data","HHCandidate_pt_Data;pT",100,0,800);
  TH1F *HHCandidate_pt_singleH = new TH1F("HHCandidate_pt_singleH","HHCandidate_pt_singleH;pT",100,0,800);
  TH1F *HHCandidate_M_NLO = new TH1F("HHCandidate_M_NLO","HHCandidate_M_NLO;M",100,0,2000);
  TH1F *HHCandidate_M_Data = new TH1F("HHCandidate_M_Data","HHCandidate_M_Data;M",100,0,2000);
  TH1F *HHCandidate_M_singleH = new TH1F("HHCandidate_M_singleH","HHCandidate_M_singleH;M",100,0,2000);
  TH1F *ET_rest_NLO = new TH1F("ET_rest_NLO","ET_rest_NLO;ET",1000,0,800);
  TH1F *ET_rest_Data = new TH1F("ET_rest_Data","ET_rest_Data;ET",1000,0,800);
  TH1F *ET_rest_singleH = new TH1F("ET_rest_singleH","ET_rest_singleH;ET",1000,0,800);
  TH1F *costhetastar_NLO = new TH1F("costhetastar_NLO","costhetastar_NLO;cos",1000,0,1);
  TH1F *costhetastar_Data = new TH1F("costhetastar_Data","costhetastar_Data;cos",1000,0,1);
  TH1F *costhetastar_singleH = new TH1F("costhetastar_singleH","costhetastar_singleH;cos",1000,0,1);
  TH1F *costheta1_NLO = new TH1F("costheta1_NLO","costheta1_NLO;cos",80,-1.1,1.1);
  TH1F *costheta1_Data = new TH1F("costheta1_Data","costheta1_Data;cos",80,-1.1,1.1);
  TH1F *costheta1_singleH = new TH1F("costheta1_singleH","costheta1_singleH;cos",80,-1.1,1.1);
  TH1F *costheta2_NLO = new TH1F("costheta2_NLO","costheta2_NLO;cos",80,-1.1,1.1);
  TH1F *costheta2_Data = new TH1F("costheta2_Data","costheta2_Data;cos",80,-1.1,1.1);
  TH1F *costheta2_singleH = new TH1F("costheta2_singleH","costheta2_singleH;cos",80,-1.1,1.1);
  TH1F *Phi_NLO = new TH1F("Phi_NLO","Phi_NLO;Phi",80,-3.5,3.5);
  TH1F *Phi_Data = new TH1F("Phi_Data","Phi_Data;Phi",80,-3.5,3.5);
  TH1F *Phi_singleH = new TH1F("Phi_singleH","Phi_singleH;Phi",80,-3.5,3.5);
  TH1F *Phi1_NLO = new TH1F("Phi1_NLO","Phi1_NLO;Phi",80,-3.5,3.5);
  TH1F *Phi1_Data = new TH1F("Phi1_Data","Phi1_Data;Phi",80,-3.5,3.5);
  TH1F *Phi1_singleH = new TH1F("Phi1_singleH","Phi1_singleH;Phi",80,-3.5,3.5);
  TH1F *HWWCandidate_M_NLO = new TH1F("HWWCandidate_M_NLO","HWWCandidate_M_NLO;M",100,0,1000);
  TH1F *HWWCandidate_M_Data = new TH1F("HWWCandidate_M_Data","HWWCandidate_M_Data;M",100,0,1000);
  TH1F *HWWCandidate_M_singleH = new TH1F("HWWCandidate_M_singleH","HWWCandidate_M_singleH;M",100,0,1000);
  TH1F *W1Candidate_M_NLO = new TH1F("W1Candidate_M_NLO","W1Candidate_M_NLO;M",100,0,300);
  TH1F *W1Candidate_M_Data = new TH1F("W1Candidate_M_Data","W1Candidate_M_Data;M",100,0,300);
  TH1F *W1Candidate_M_singleH = new TH1F("W1Candidate_M_singleH","W1Candidate_M_singleH;M",100,0,300);
  TH1F *gen_dipho_pt_NLO = new TH1F("gen_dipho_pt_NLO","gen_dipho_pt_NLO;pt",100,0,1000);
  TH1F *gen_dipho_pt_Data = new TH1F("gen_dipho_pt_Data","gen_dipho_pt_Data;pt",100,0,1000);
  TH1F *gen_dipho_pt_singleH = new TH1F("gen_dipho_pt_singleH","gen_dipho_pt_singleH;pt",100,0,1000);
  

  TH1F *S_B = new TH1F("S_B","S/sqrt(B);p_{T}(Hgg)",700,0,700);
  TH1F *S_B_1 = new TH1F("S_B_1","S/B_1;pT",100,0,600);
  

  TH2F *AK4GEN_AllResolved_onShellW_vs_gen_onShellW_Pt = new TH2F("AK4GEN_AllResolved_onShellW_vs_gen_onShellW_Pt","AK4GEN_AllResolved_onShellW_vs_gen_onShellW_Pt",110,0,1100,110,0,1100);

  
  

  
  float dipho_MVA;
  float passPhotonSels;
  float goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
  float goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
  float goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
  float goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
  float goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
  float goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
  float goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
  float goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
  float goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
  float goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb;
  float goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
  float goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
  float goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
  float goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
  float goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
  float goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
  float goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
  float goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
  float goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
  float goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb;
  float goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
  float goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
  float goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
  float goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
  float goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
  float goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
  float goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
  float goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
  float goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
  float goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb;
  float dipho_pt;
  float weight;
  float CMS_hgg_mass;

  float mH_105To160;
  float mW1_65To105;
  float Leading_Photon_MVA;
  float Subleading_Photon_MVA;
  float Leading_Photon_E;
  float Leading_Photon_pt;
  float Leading_Photon_eta;
  float Leading_Photon_phi;
  float Subleading_Photon_E;
  float Subleading_Photon_pt;
  float Subleading_Photon_eta;
  float Subleading_Photon_phi;
  float goodJets_0_pt;
  float goodJets_0_eta;
  float goodJets_0_phi;
  float goodJets_1_pt;
  float goodJets_1_eta;
  float goodJets_1_phi;
  float goodJets_2_pt;
  float goodJets_3_pt;
  float goodJets_4_pt;
  float goodJets_5_pt;
  float goodJets_6_pt;
  float goodJets_7_pt;
  float goodJets_8_pt;
  float goodJets_9_pt;
  
  float HWWCandidate_pt;
  float HWWCandidate_eta;
  float HWWCandidate_phi;
  float HWWCandidate_M;
  float HHCandidate_pt;
  float HHCandidate_eta;
  float HHCandidate_phi;
  float HHCandidate_M;
  float DeltaEta_HH;
  float DeltaPhi_HH;
  float DeltaR_HH;
  float ZeroVtx_z;
  float GenVtx_z;
  float dZ;
  float costheta1;
  float costheta2;
  float costhetastar;
  float Phi;
  float Phi1;

  float W1Candidate_M;
  float W2Candidate_M;
  
  float Leading_GEN_Photon_pt;
  float Subleading_GEN_Photon_pt;
  float Leading_GEN_Photon_eta;
  float Subleading_GEN_Photon_eta;
  float Leading_GEN_Photon_phi;
  float Subleading_GEN_Photon_phi;
  float Leading_GEN_Photon_E;
  float Subleading_GEN_Photon_E;
  
  
  t1->SetBranchAddress("a_costheta1",&costheta1);
  t1->SetBranchAddress("a_costheta2",&costheta2);
  t1->SetBranchAddress("a_costhetastar",&costhetastar);
  t1->SetBranchAddress("a_Phi",&Phi);
  t1->SetBranchAddress("a_Phi1",&Phi1);
  t1->SetBranchAddress("Leading_GEN_Photon_pt",&Leading_GEN_Photon_pt);
  t1->SetBranchAddress("Subleading_GEN_Photon_pt",&Subleading_GEN_Photon_pt);
  t1->SetBranchAddress("Leading_GEN_Photon_eta",&Leading_GEN_Photon_eta);
  t1->SetBranchAddress("Subleading_GEN_Photon_eta",&Subleading_GEN_Photon_eta);
  t1->SetBranchAddress("Leading_GEN_Photon_phi",&Leading_GEN_Photon_phi);
  t1->SetBranchAddress("Subleading_GEN_Photon_phi",&Subleading_GEN_Photon_phi);
  t1->SetBranchAddress("Leading_GEN_Photon_E",&Leading_GEN_Photon_E);
  t1->SetBranchAddress("Subleading_GEN_Photon_E",&Subleading_GEN_Photon_E);
  t1->SetBranchAddress("passPhotonSels",&passPhotonSels);
  t1->SetBranchAddress("dipho_MVA", &dipho_MVA);
  t1->SetBranchAddress("W1Candidate_M",&W1Candidate_M);
  t1->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  
  t1->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t1->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t1->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t1->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t1->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t1->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t1->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  
  t1->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t1->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t1->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t1->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t1->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t1->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t1->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  
  t1->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t1->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t1->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t1->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t1->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t1->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t1->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);

  t1->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t1->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t1->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t1->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t1->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t1->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t1->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t1->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t1->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t1->SetBranchAddress("dipho_pt", &dipho_pt);
  t1->SetBranchAddress("weight", &weight);
  t1->SetBranchAddress("CMS_hgg_mass", &CMS_hgg_mass);
  t1->SetBranchAddress("mH_105To160",&mH_105To160);
  t1->SetBranchAddress("mW1_65To105",&mW1_65To105);
  t1->SetBranchAddress("Leading_Photon_MVA",&Leading_Photon_MVA);
  t1->SetBranchAddress("Subleading_Photon_MVA",&Subleading_Photon_MVA);
  t1->SetBranchAddress("Leading_Photon_E",&Leading_Photon_E);
  t1->SetBranchAddress("Leading_Photon_pt",&Leading_Photon_pt);
  t1->SetBranchAddress("Leading_Photon_eta",&Leading_Photon_eta);
  t1->SetBranchAddress("Leading_Photon_phi",&Leading_Photon_phi);
  t1->SetBranchAddress("Subleading_Photon_E",&Subleading_Photon_E);
  t1->SetBranchAddress("Subleading_Photon_pt",&Subleading_Photon_pt);
  t1->SetBranchAddress("Subleading_Photon_eta",&Subleading_Photon_eta);
  t1->SetBranchAddress("Subleading_Photon_phi",&Subleading_Photon_phi);
  t1->SetBranchAddress("goodJets_0_pt",&goodJets_0_pt);
  t1->SetBranchAddress("goodJets_0_eta",&goodJets_0_eta);
  t1->SetBranchAddress("goodJets_0_phi",&goodJets_0_phi);
  t1->SetBranchAddress("goodJets_1_pt",&goodJets_1_pt);
  t1->SetBranchAddress("goodJets_1_eta",&goodJets_1_eta);
  t1->SetBranchAddress("goodJets_1_phi",&goodJets_1_phi);
  t1->SetBranchAddress("goodJets_2_pt",&goodJets_2_pt);
  t1->SetBranchAddress("goodJets_3_pt",&goodJets_3_pt);
  t1->SetBranchAddress("goodJets_4_pt",&goodJets_4_pt);
  t1->SetBranchAddress("goodJets_5_pt",&goodJets_5_pt);
  t1->SetBranchAddress("goodJets_6_pt",&goodJets_6_pt);
  t1->SetBranchAddress("goodJets_7_pt",&goodJets_7_pt);
  t1->SetBranchAddress("goodJets_8_pt",&goodJets_8_pt);
  t1->SetBranchAddress("goodJets_9_pt",&goodJets_9_pt);
  
  t1->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  t1->SetBranchAddress("HWWCandidate_pt",&HWWCandidate_pt);
  t1->SetBranchAddress("HWWCandidate_eta",&HWWCandidate_eta);
  t1->SetBranchAddress("HWWCandidate_phi",&HWWCandidate_phi);
  t1->SetBranchAddress("HHCandidate_pt",&HHCandidate_pt);
  t1->SetBranchAddress("HHCandidate_eta",&HHCandidate_eta);
  t1->SetBranchAddress("HHCandidate_phi",&HHCandidate_phi);
  t1->SetBranchAddress("HHCandidate_M",&HHCandidate_M);
  t1->SetBranchAddress("DeltaEta_HH",&DeltaEta_HH);
  t1->SetBranchAddress("DeltaPhi_HH",&DeltaPhi_HH);
  t1->SetBranchAddress("DeltaR_HH",&DeltaR_HH);
  t1->SetBranchAddress("ZeroVtx_z",&ZeroVtx_z);
  t1->SetBranchAddress("GenVtx_z",&GenVtx_z);
  t1->SetBranchAddress("dZ",&dZ);
  

  t2->SetBranchAddress("a_costheta1",&costheta1);
  t2->SetBranchAddress("a_costheta2",&costheta2);
  t2->SetBranchAddress("a_costhetastar",&costhetastar);
  t2->SetBranchAddress("a_Phi",&Phi);
  t2->SetBranchAddress("a_Phi1",&Phi1);
  t2->SetBranchAddress("W1Candidate_M",&W1Candidate_M);
  t2->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  
  t2->SetBranchAddress("dipho_MVA", &dipho_MVA);
  t2->SetBranchAddress("passPhotonSels",&passPhotonSels);
  t2->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t2->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t2->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t2->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t2->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t2->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t2->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t2->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t2->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t2->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t2->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t2->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t2->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t2->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t2->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t2->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t2->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t2->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t2->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t2->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t2->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);

  t2->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t2->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t2->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t2->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t2->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t2->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t2->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t2->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t2->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t2->SetBranchAddress("dipho_pt", &dipho_pt);
  t2->SetBranchAddress("weight", &weight);
  t2->SetBranchAddress("CMS_hgg_mass", &CMS_hgg_mass);
  t2->SetBranchAddress("mH_105To160",&mH_105To160);
  t2->SetBranchAddress("mW1_65To105",&mW1_65To105);
  t2->SetBranchAddress("Leading_Photon_MVA",&Leading_Photon_MVA);
  t2->SetBranchAddress("Subleading_Photon_MVA",&Subleading_Photon_MVA);
  t2->SetBranchAddress("Leading_Photon_E",&Leading_Photon_E);
  t2->SetBranchAddress("Leading_Photon_pt",&Leading_Photon_pt);
  t2->SetBranchAddress("Leading_Photon_eta",&Leading_Photon_eta);
  t2->SetBranchAddress("Leading_Photon_phi",&Leading_Photon_phi);
  t2->SetBranchAddress("Subleading_Photon_E",&Subleading_Photon_E);
  t2->SetBranchAddress("Subleading_Photon_pt",&Subleading_Photon_pt);
  t2->SetBranchAddress("Subleading_Photon_eta",&Subleading_Photon_eta);
  t2->SetBranchAddress("Subleading_Photon_phi",&Subleading_Photon_phi);
  t2->SetBranchAddress("goodJets_0_pt",&goodJets_0_pt);
  t2->SetBranchAddress("goodJets_0_eta",&goodJets_0_eta);
  t2->SetBranchAddress("goodJets_0_phi",&goodJets_0_phi);
  t2->SetBranchAddress("goodJets_1_pt",&goodJets_1_pt);
  t2->SetBranchAddress("goodJets_1_eta",&goodJets_1_eta);
  t2->SetBranchAddress("goodJets_1_phi",&goodJets_1_phi);
  t2->SetBranchAddress("goodJets_2_pt",&goodJets_2_pt);
  t2->SetBranchAddress("goodJets_3_pt",&goodJets_3_pt);
  t2->SetBranchAddress("goodJets_4_pt",&goodJets_4_pt);
  t2->SetBranchAddress("goodJets_5_pt",&goodJets_5_pt);
  t2->SetBranchAddress("goodJets_6_pt",&goodJets_6_pt);
  t2->SetBranchAddress("goodJets_7_pt",&goodJets_7_pt);
  t2->SetBranchAddress("goodJets_8_pt",&goodJets_8_pt);
  t2->SetBranchAddress("goodJets_9_pt",&goodJets_9_pt);
  t2->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  t2->SetBranchAddress("HWWCandidate_pt",&HWWCandidate_pt);
  t2->SetBranchAddress("HWWCandidate_eta",&HWWCandidate_eta);
  t2->SetBranchAddress("HWWCandidate_phi",&HWWCandidate_phi);
  t2->SetBranchAddress("HHCandidate_pt",&HHCandidate_pt);
  t2->SetBranchAddress("HHCandidate_eta",&HHCandidate_eta);
  t2->SetBranchAddress("HHCandidate_phi",&HHCandidate_phi);
  t2->SetBranchAddress("HHCandidate_M",&HHCandidate_M);
  t2->SetBranchAddress("DeltaEta_HH",&DeltaEta_HH);
  t2->SetBranchAddress("DeltaPhi_HH",&DeltaPhi_HH);
  t2->SetBranchAddress("DeltaR_HH",&DeltaR_HH);
  t2->SetBranchAddress("ZeroVtx_z",&ZeroVtx_z);
  t2->SetBranchAddress("dZ",&dZ);

  t3->SetBranchAddress("a_costheta1",&costheta1);
  t3->SetBranchAddress("a_costheta2",&costheta2);
  t3->SetBranchAddress("a_costhetastar",&costhetastar);
  t3->SetBranchAddress("a_Phi",&Phi);
  t3->SetBranchAddress("a_Phi1",&Phi1);
  t3->SetBranchAddress("W1Candidate_M",&W1Candidate_M);
  t3->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  
  t3->SetBranchAddress("Leading_GEN_Photon_pt",&Leading_GEN_Photon_pt);
  t3->SetBranchAddress("Subleading_GEN_Photon_pt",&Subleading_GEN_Photon_pt);
  t3->SetBranchAddress("Leading_GEN_Photon_eta",&Leading_GEN_Photon_eta);
  t3->SetBranchAddress("Subleading_GEN_Photon_eta",&Subleading_GEN_Photon_eta);
  t3->SetBranchAddress("Leading_GEN_Photon_phi",&Leading_GEN_Photon_phi);
  t3->SetBranchAddress("Subleading_GEN_Photon_phi",&Subleading_GEN_Photon_phi);
  t3->SetBranchAddress("Leading_GEN_Photon_E",&Leading_GEN_Photon_E);
  t3->SetBranchAddress("Subleading_GEN_Photon_E",&Subleading_GEN_Photon_E);
  
  t3->SetBranchAddress("dipho_MVA", &dipho_MVA);
  t3->SetBranchAddress("passPhotonSels",&passPhotonSels);
  t3->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t3->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t3->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t3->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t3->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t3->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t3->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t3->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t3->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t3->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t3->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t3->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t3->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t3->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t3->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t3->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t3->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t3->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t3->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t3->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t3->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);

  t3->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t3->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t3->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t3->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t3->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t3->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t3->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t3->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t3->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t3->SetBranchAddress("dipho_pt", &dipho_pt);
  t3->SetBranchAddress("weight", &weight);
  t3->SetBranchAddress("CMS_hgg_mass", &CMS_hgg_mass);
  t3->SetBranchAddress("mH_105To160",&mH_105To160);
  t3->SetBranchAddress("mW1_65To105",&mW1_65To105);
  t3->SetBranchAddress("Leading_Photon_MVA",&Leading_Photon_MVA);
  t3->SetBranchAddress("Subleading_Photon_MVA",&Subleading_Photon_MVA);
  t3->SetBranchAddress("Leading_Photon_E",&Leading_Photon_E);
  t3->SetBranchAddress("Leading_Photon_pt",&Leading_Photon_pt);
  t3->SetBranchAddress("Leading_Photon_eta",&Leading_Photon_eta);
  t3->SetBranchAddress("Leading_Photon_phi",&Leading_Photon_phi);
  t3->SetBranchAddress("Subleading_Photon_E",&Subleading_Photon_E);
  t3->SetBranchAddress("Subleading_Photon_pt",&Subleading_Photon_pt);
  t3->SetBranchAddress("Subleading_Photon_eta",&Subleading_Photon_eta);
  t3->SetBranchAddress("Subleading_Photon_phi",&Subleading_Photon_phi);
  t3->SetBranchAddress("goodJets_0_pt",&goodJets_0_pt);
  t3->SetBranchAddress("goodJets_0_eta",&goodJets_0_eta);
  t3->SetBranchAddress("goodJets_0_phi",&goodJets_0_phi);
  t3->SetBranchAddress("goodJets_1_pt",&goodJets_1_pt);
  t3->SetBranchAddress("goodJets_1_eta",&goodJets_1_eta);
  t3->SetBranchAddress("goodJets_1_phi",&goodJets_1_phi);
  t3->SetBranchAddress("goodJets_2_pt",&goodJets_2_pt);
  t3->SetBranchAddress("goodJets_3_pt",&goodJets_3_pt);
  t3->SetBranchAddress("goodJets_4_pt",&goodJets_4_pt);
  t3->SetBranchAddress("goodJets_5_pt",&goodJets_5_pt);
  t3->SetBranchAddress("goodJets_6_pt",&goodJets_6_pt);
  t3->SetBranchAddress("goodJets_7_pt",&goodJets_7_pt);
  t3->SetBranchAddress("goodJets_8_pt",&goodJets_8_pt);
  t3->SetBranchAddress("goodJets_9_pt",&goodJets_9_pt);
  t3->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  t3->SetBranchAddress("HWWCandidate_pt",&HWWCandidate_pt);
  t3->SetBranchAddress("HWWCandidate_eta",&HWWCandidate_eta);
  t3->SetBranchAddress("HWWCandidate_phi",&HWWCandidate_phi);
  t3->SetBranchAddress("HHCandidate_pt",&HHCandidate_pt);
  t3->SetBranchAddress("HHCandidate_eta",&HHCandidate_eta);
  t3->SetBranchAddress("HHCandidate_phi",&HHCandidate_phi);
  t3->SetBranchAddress("HHCandidate_M",&HHCandidate_M);
  t3->SetBranchAddress("DeltaEta_HH",&DeltaEta_HH);
  t3->SetBranchAddress("DeltaPhi_HH",&DeltaPhi_HH);
  t3->SetBranchAddress("DeltaR_HH",&DeltaR_HH);
  t3->SetBranchAddress("ZeroVtx_z",&ZeroVtx_z);
  t3->SetBranchAddress("dZ",&dZ);

  t4->SetBranchAddress("a_costheta1",&costheta1);
  t4->SetBranchAddress("a_costheta2",&costheta2);
  t4->SetBranchAddress("a_costhetastar",&costhetastar);
  t4->SetBranchAddress("a_Phi",&Phi);
  t4->SetBranchAddress("a_Phi1",&Phi1);
  t4->SetBranchAddress("W1Candidate_M",&W1Candidate_M);
  t4->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  
  t4->SetBranchAddress("Leading_GEN_Photon_pt",&Leading_GEN_Photon_pt);
  t4->SetBranchAddress("Subleading_GEN_Photon_pt",&Subleading_GEN_Photon_pt);
  t4->SetBranchAddress("Leading_GEN_Photon_eta",&Leading_GEN_Photon_eta);
  t4->SetBranchAddress("Subleading_GEN_Photon_eta",&Subleading_GEN_Photon_eta);
  t4->SetBranchAddress("Leading_GEN_Photon_phi",&Leading_GEN_Photon_phi);
  t4->SetBranchAddress("Subleading_GEN_Photon_phi",&Subleading_GEN_Photon_phi);
  t4->SetBranchAddress("Leading_GEN_Photon_E",&Leading_GEN_Photon_E);
  t4->SetBranchAddress("Subleading_GEN_Photon_E",&Subleading_GEN_Photon_E);
  
  t4->SetBranchAddress("dipho_MVA", &dipho_MVA);
  t4->SetBranchAddress("passPhotonSels",&passPhotonSels);
  t4->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t4->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t4->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t4->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t4->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t4->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t4->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t4->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t4->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t4->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t4->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t4->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t4->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t4->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t4->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t4->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t4->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t4->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t4->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t4->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t4->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  
  t4->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t4->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t4->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t4->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t4->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t4->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t4->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t4->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t4->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t4->SetBranchAddress("dipho_pt", &dipho_pt);
  t4->SetBranchAddress("weight", &weight);
  t4->SetBranchAddress("CMS_hgg_mass", &CMS_hgg_mass);
  t4->SetBranchAddress("mH_105To160",&mH_105To160);
  t4->SetBranchAddress("mW1_65To105",&mW1_65To105);
  t4->SetBranchAddress("Leading_Photon_MVA",&Leading_Photon_MVA);
  t4->SetBranchAddress("Subleading_Photon_MVA",&Subleading_Photon_MVA);
  t4->SetBranchAddress("Leading_Photon_E",&Leading_Photon_E);
  t4->SetBranchAddress("Leading_Photon_pt",&Leading_Photon_pt);
  t4->SetBranchAddress("Leading_Photon_eta",&Leading_Photon_eta);
  t4->SetBranchAddress("Leading_Photon_phi",&Leading_Photon_phi);
  t4->SetBranchAddress("Subleading_Photon_E",&Subleading_Photon_E);
  t4->SetBranchAddress("Subleading_Photon_pt",&Subleading_Photon_pt);
  t4->SetBranchAddress("Subleading_Photon_eta",&Subleading_Photon_eta);
  t4->SetBranchAddress("Subleading_Photon_phi",&Subleading_Photon_phi);
  t4->SetBranchAddress("goodJets_0_pt",&goodJets_0_pt);
  t4->SetBranchAddress("goodJets_0_eta",&goodJets_0_eta);
  t4->SetBranchAddress("goodJets_0_phi",&goodJets_0_phi);
  t4->SetBranchAddress("goodJets_1_pt",&goodJets_1_pt);
  t4->SetBranchAddress("goodJets_1_eta",&goodJets_1_eta);
  t4->SetBranchAddress("goodJets_1_phi",&goodJets_1_phi);
  t4->SetBranchAddress("goodJets_2_pt",&goodJets_2_pt);
  t4->SetBranchAddress("goodJets_3_pt",&goodJets_3_pt);
  t4->SetBranchAddress("goodJets_4_pt",&goodJets_4_pt);
  t4->SetBranchAddress("goodJets_5_pt",&goodJets_5_pt);
  t4->SetBranchAddress("goodJets_6_pt",&goodJets_6_pt);
  t4->SetBranchAddress("goodJets_7_pt",&goodJets_7_pt);
  t4->SetBranchAddress("goodJets_8_pt",&goodJets_8_pt);
  t4->SetBranchAddress("goodJets_9_pt",&goodJets_9_pt);
  t4->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  t4->SetBranchAddress("HWWCandidate_pt",&HWWCandidate_pt);
  t4->SetBranchAddress("HWWCandidate_eta",&HWWCandidate_eta);
  t4->SetBranchAddress("HWWCandidate_phi",&HWWCandidate_phi);
  t4->SetBranchAddress("HHCandidate_pt",&HHCandidate_pt);
  t4->SetBranchAddress("HHCandidate_eta",&HHCandidate_eta);
  t4->SetBranchAddress("HHCandidate_phi",&HHCandidate_phi);
  t4->SetBranchAddress("HHCandidate_M",&HHCandidate_M);
  t4->SetBranchAddress("DeltaEta_HH",&DeltaEta_HH);
  t4->SetBranchAddress("DeltaPhi_HH",&DeltaPhi_HH);
  t4->SetBranchAddress("DeltaR_HH",&DeltaR_HH);
  t4->SetBranchAddress("ZeroVtx_z",&ZeroVtx_z);
  t4->SetBranchAddress("dZ",&dZ);

  t5->SetBranchAddress("a_costheta1",&costheta1);
  t5->SetBranchAddress("a_costheta2",&costheta2);
  t5->SetBranchAddress("a_costhetastar",&costhetastar);
  t5->SetBranchAddress("a_Phi",&Phi);
  t5->SetBranchAddress("a_Phi1",&Phi1);
  t5->SetBranchAddress("W1Candidate_M",&W1Candidate_M);
  t5->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  
  t5->SetBranchAddress("Leading_GEN_Photon_pt",&Leading_GEN_Photon_pt);
  t5->SetBranchAddress("Subleading_GEN_Photon_pt",&Subleading_GEN_Photon_pt);
  t5->SetBranchAddress("Leading_GEN_Photon_eta",&Leading_GEN_Photon_eta);
  t5->SetBranchAddress("Subleading_GEN_Photon_eta",&Subleading_GEN_Photon_eta);
  t5->SetBranchAddress("Leading_GEN_Photon_phi",&Leading_GEN_Photon_phi);
  t5->SetBranchAddress("Subleading_GEN_Photon_phi",&Subleading_GEN_Photon_phi);
  t5->SetBranchAddress("Leading_GEN_Photon_E",&Leading_GEN_Photon_E);
  t5->SetBranchAddress("Subleading_GEN_Photon_E",&Subleading_GEN_Photon_E);
  
  t5->SetBranchAddress("dipho_MVA", &dipho_MVA);
  t5->SetBranchAddress("passPhotonSels",&passPhotonSels);
  t5->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t5->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t5->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t5->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t5->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t5->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t5->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t5->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t5->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t5->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t5->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t5->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t5->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t5->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t5->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t5->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t5->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t5->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t5->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t5->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t5->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);

  t5->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t5->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t5->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t5->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t5->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t5->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t5->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t5->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t5->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t5->SetBranchAddress("dipho_pt", &dipho_pt);
  t5->SetBranchAddress("weight", &weight);
  t5->SetBranchAddress("CMS_hgg_mass", &CMS_hgg_mass);
  t5->SetBranchAddress("mH_105To160",&mH_105To160);
  t5->SetBranchAddress("mW1_65To105",&mW1_65To105);
  t5->SetBranchAddress("Leading_Photon_MVA",&Leading_Photon_MVA);
  t5->SetBranchAddress("Subleading_Photon_MVA",&Subleading_Photon_MVA);
  t5->SetBranchAddress("Leading_Photon_E",&Leading_Photon_E);
  t5->SetBranchAddress("Leading_Photon_pt",&Leading_Photon_pt);
  t5->SetBranchAddress("Leading_Photon_eta",&Leading_Photon_eta);
  t5->SetBranchAddress("Leading_Photon_phi",&Leading_Photon_phi);
  t5->SetBranchAddress("Subleading_Photon_E",&Subleading_Photon_E);
  t5->SetBranchAddress("Subleading_Photon_pt",&Subleading_Photon_pt);
  t5->SetBranchAddress("Subleading_Photon_eta",&Subleading_Photon_eta);
  t5->SetBranchAddress("Subleading_Photon_phi",&Subleading_Photon_phi);
  t5->SetBranchAddress("goodJets_0_pt",&goodJets_0_pt);
  t5->SetBranchAddress("goodJets_0_eta",&goodJets_0_eta);
  t5->SetBranchAddress("goodJets_0_phi",&goodJets_0_phi);
  t5->SetBranchAddress("goodJets_1_pt",&goodJets_1_pt);
  t5->SetBranchAddress("goodJets_1_eta",&goodJets_1_eta);
  t5->SetBranchAddress("goodJets_1_phi",&goodJets_1_phi);
  t5->SetBranchAddress("goodJets_2_pt",&goodJets_2_pt);
  t5->SetBranchAddress("goodJets_3_pt",&goodJets_3_pt);
  t5->SetBranchAddress("goodJets_4_pt",&goodJets_4_pt);
  t5->SetBranchAddress("goodJets_5_pt",&goodJets_5_pt);
  t5->SetBranchAddress("goodJets_6_pt",&goodJets_6_pt);
  t5->SetBranchAddress("goodJets_7_pt",&goodJets_7_pt);
  t5->SetBranchAddress("goodJets_8_pt",&goodJets_8_pt);
  t5->SetBranchAddress("goodJets_9_pt",&goodJets_9_pt);
  t5->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  t5->SetBranchAddress("HWWCandidate_pt",&HWWCandidate_pt);
  t5->SetBranchAddress("HWWCandidate_eta",&HWWCandidate_eta);
  t5->SetBranchAddress("HWWCandidate_phi",&HWWCandidate_phi);
  t5->SetBranchAddress("HHCandidate_pt",&HHCandidate_pt);
  t5->SetBranchAddress("HHCandidate_eta",&HHCandidate_eta);
  t5->SetBranchAddress("HHCandidate_phi",&HHCandidate_phi);
  t5->SetBranchAddress("HHCandidate_M",&HHCandidate_M);
  t5->SetBranchAddress("DeltaEta_HH",&DeltaEta_HH);
  t5->SetBranchAddress("DeltaPhi_HH",&DeltaPhi_HH);
  t5->SetBranchAddress("DeltaR_HH",&DeltaR_HH);
  t5->SetBranchAddress("ZeroVtx_z",&ZeroVtx_z);
  t5->SetBranchAddress("dZ",&dZ);

  t6->SetBranchAddress("a_costheta1",&costheta1);
  t6->SetBranchAddress("a_costheta2",&costheta2);
  t6->SetBranchAddress("a_costhetastar",&costhetastar);
  t6->SetBranchAddress("a_Phi",&Phi);
  t6->SetBranchAddress("a_Phi1",&Phi1);
  t6->SetBranchAddress("Leading_GEN_Photon_pt",&Leading_GEN_Photon_pt);
  t6->SetBranchAddress("Subleading_GEN_Photon_pt",&Subleading_GEN_Photon_pt);
  t6->SetBranchAddress("Leading_GEN_Photon_eta",&Leading_GEN_Photon_eta);
  t6->SetBranchAddress("Subleading_GEN_Photon_eta",&Subleading_GEN_Photon_eta);
  t6->SetBranchAddress("Leading_GEN_Photon_phi",&Leading_GEN_Photon_phi);
  t6->SetBranchAddress("Subleading_GEN_Photon_phi",&Subleading_GEN_Photon_phi);
  t6->SetBranchAddress("Leading_GEN_Photon_E",&Leading_GEN_Photon_E);
  t6->SetBranchAddress("Subleading_GEN_Photon_E",&Subleading_GEN_Photon_E);
  t6->SetBranchAddress("W1Candidate_M",&W1Candidate_M);
  t6->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  
  t6->SetBranchAddress("dipho_MVA", &dipho_MVA);
  t6->SetBranchAddress("passPhotonSels",&passPhotonSels);
  t6->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t6->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t6->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t6->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t6->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t6->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t6->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t6->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t6->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t6->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t6->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t6->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t6->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t6->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t6->SetBranchAddress("goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t6->SetBranchAddress("goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t6->SetBranchAddress("goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t6->SetBranchAddress("goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t6->SetBranchAddress("goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t6->SetBranchAddress("goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t6->SetBranchAddress("goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);

  t6->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t6->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t6->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb);
  t6->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t6->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t6->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb);
  t6->SetBranchAddress("goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t6->SetBranchAddress("goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t6->SetBranchAddress("goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb", &goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb);
  t6->SetBranchAddress("dipho_pt", &dipho_pt);
  t6->SetBranchAddress("weight", &weight);
  t6->SetBranchAddress("CMS_hgg_mass", &CMS_hgg_mass);
  t6->SetBranchAddress("mH_105To160",&mH_105To160);
  t6->SetBranchAddress("mW1_65To105",&mW1_65To105);
  t6->SetBranchAddress("Leading_Photon_MVA",&Leading_Photon_MVA);
  t6->SetBranchAddress("Subleading_Photon_MVA",&Subleading_Photon_MVA);
  t6->SetBranchAddress("Leading_Photon_E",&Leading_Photon_E);
  t6->SetBranchAddress("Leading_Photon_pt",&Leading_Photon_pt);
  t6->SetBranchAddress("Leading_Photon_eta",&Leading_Photon_eta);
  t6->SetBranchAddress("Leading_Photon_phi",&Leading_Photon_phi);
  t6->SetBranchAddress("Subleading_Photon_E",&Subleading_Photon_E);
  t6->SetBranchAddress("Subleading_Photon_pt",&Subleading_Photon_pt);
  t6->SetBranchAddress("Subleading_Photon_eta",&Subleading_Photon_eta);
  t6->SetBranchAddress("Subleading_Photon_phi",&Subleading_Photon_phi);
  t6->SetBranchAddress("goodJets_0_pt",&goodJets_0_pt);
  t6->SetBranchAddress("goodJets_0_eta",&goodJets_0_eta);
  t6->SetBranchAddress("goodJets_0_phi",&goodJets_0_phi);
  t6->SetBranchAddress("goodJets_1_pt",&goodJets_1_pt);
  t6->SetBranchAddress("goodJets_1_eta",&goodJets_1_eta);
  t6->SetBranchAddress("goodJets_1_phi",&goodJets_1_phi);
  t6->SetBranchAddress("goodJets_2_pt",&goodJets_2_pt);
  t6->SetBranchAddress("goodJets_3_pt",&goodJets_3_pt);
  t6->SetBranchAddress("goodJets_4_pt",&goodJets_4_pt);
  t6->SetBranchAddress("goodJets_5_pt",&goodJets_5_pt);
  t6->SetBranchAddress("goodJets_6_pt",&goodJets_6_pt);
  t6->SetBranchAddress("goodJets_7_pt",&goodJets_7_pt);
  t6->SetBranchAddress("goodJets_8_pt",&goodJets_8_pt);
  t6->SetBranchAddress("goodJets_9_pt",&goodJets_9_pt);
  t6->SetBranchAddress("HWWCandidate_M",&HWWCandidate_M);
  t6->SetBranchAddress("HWWCandidate_pt",&HWWCandidate_pt);
  t6->SetBranchAddress("HWWCandidate_eta",&HWWCandidate_eta);
  t6->SetBranchAddress("HWWCandidate_phi",&HWWCandidate_phi);
  t6->SetBranchAddress("HHCandidate_pt",&HHCandidate_pt);
  t6->SetBranchAddress("HHCandidate_eta",&HHCandidate_eta);
  t6->SetBranchAddress("HHCandidate_phi",&HHCandidate_phi);
  t6->SetBranchAddress("HHCandidate_M",&HHCandidate_M);
  t6->SetBranchAddress("DeltaEta_HH",&DeltaEta_HH);
  t6->SetBranchAddress("DeltaPhi_HH",&DeltaPhi_HH);
  t6->SetBranchAddress("DeltaR_HH",&DeltaR_HH);
  t6->SetBranchAddress("ZeroVtx_z",&ZeroVtx_z);
  t6->SetBranchAddress("dZ",&dZ);
  
  
  vector<double> countnumber1(20,0);
  vector<double> countnumber2(20,0);
  vector<double> countnumber3(20,0);
  vector<double> countnumber4(20,0);
  vector<double> countnumber5(20,0);
  vector<double> countnumber6(20,0);
 
  
  int entries1=t1->GetEntries();
  int entries2=t2->GetEntries();
  int entries3=t3->GetEntries();
  int entries4=t4->GetEntries();
  int entries5=t5->GetEntries();
  int entries6=t6->GetEntries();
  std::cout <<"entries:"<<entries1<<std::endl;
  std::cout <<"entries:"<<entries2<<std::endl;
  std::cout <<"entries:"<<entries3<<std::endl;
  std::cout <<"entries:"<<entries4<<std::endl;
  std::cout <<"entries:"<<entries5<<std::endl;
  std::cout <<"entries:"<<entries6<<std::endl;
  float pi=3.1415926;
  for (int i=0; i<entries1; ++i){
    t1->GetEntry(i);
    TLorentzVector gen_leading_photon;
    TLorentzVector gen_Subleading_photon;
    gen_leading_photon.SetPtEtaPhiE(Leading_GEN_Photon_pt,Leading_GEN_Photon_eta,Leading_GEN_Photon_phi,Leading_GEN_Photon_E);
    gen_Subleading_photon.SetPtEtaPhiE(Subleading_GEN_Photon_pt,Subleading_GEN_Photon_eta,Subleading_GEN_Photon_phi,Subleading_GEN_Photon_E);
    float gen_dipho_pt=(gen_leading_photon+gen_Subleading_photon).Pt();
    gen_dipho_pt_NLO->Fill(gen_dipho_pt,weight);

    countnumber1[0]=countnumber1[0]+weight;
    if (DeltaPhi_HH>pi) {DeltaPhi_HH = 2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<-pi) {DeltaPhi_HH = -2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<0) {DeltaPhi_HH=-DeltaPhi_HH;}
    DeltaR_HH=sqrt(DeltaEta_HH*DeltaEta_HH+DeltaPhi_HH*DeltaPhi_HH);
    dipho_MVA_NLO->Fill(dipho_MVA,weight);
    ZeroVtx_z_NLO->Fill(ZeroVtx_z,weight);
    GenVtx_z_NLO->Fill(GenVtx_z,weight);
    dZ_NLO->Fill(dZ);
    
    HHCandidate_pt_NLO->Fill(HHCandidate_pt,weight);
    HHCandidate_M_NLO->Fill(HHCandidate_M,weight);
    float ET_tot=goodJets_0_pt+goodJets_1_pt+goodJets_2_pt+goodJets_3_pt;
    if (goodJets_4_pt>=0){ET_tot=ET_tot+goodJets_4_pt;}
    if (goodJets_5_pt>=0){ET_tot=ET_tot+goodJets_5_pt;}
    if (goodJets_6_pt>=0){ET_tot=ET_tot+goodJets_6_pt;}
    if (goodJets_7_pt>=0){ET_tot=ET_tot+goodJets_7_pt;}
    if (goodJets_8_pt>=0){ET_tot=ET_tot+goodJets_8_pt;}
    if (goodJets_9_pt>=0){ET_tot=ET_tot+goodJets_9_pt;}
    
    if (passPhotonSels > 0.5){
    //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5){
      //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5 && DeltaR_HH>1.5){
      countnumber1[1]=countnumber1[1]+weight;
      b_dis_1_NLO->Fill(goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      b_dis_2_NLO->Fill(goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      
      DeltaR_HH_NLO->Fill(DeltaR_HH,weight);
      HWWCandidate_M_NLO->Fill(HWWCandidate_M,weight);
      W1Candidate_M_NLO->Fill(W1Candidate_M,weight);
      
      if (goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221){ 
	//if (goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<2 && goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<2 && goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<2 && goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<2 && goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<2){
	if (goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb>=0.7221) continue;
	if (goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb>=0.7221) continue;
	if (goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb>=0.7221) continue;
	if (goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb>=0.7221) continue;
	if (goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb>=0.7221) continue;
	  
	countnumber1[2]=countnumber1[2]+weight;
	DeltaPhi_HH_NLO->Fill(DeltaPhi_HH,weight);
	
	ET_rest_NLO->Fill(ET_tot-sqrt(HWWCandidate_pt*HWWCandidate_pt+HWWCandidate_M*HWWCandidate_M),weight);
	//costhetastar_NLO->Fill(costhetastar,weight);
	//costheta1_NLO->Fill(costheta1,weight);
	//costheta2_NLO->Fill(costheta2,weight);
	//Phi_NLO->Fill(Phi,weight);
	//Phi1_NLO->Fill(Phi1,weight);
	
	if (DeltaPhi_HH>2.5){
	  
	  countnumber1[3]=countnumber1[3]+weight;
	  HGGpt_NLO->Fill(dipho_pt,weight);
	  mH_105To160_NLO->Fill(mH_105To160,weight);
	  mW1_65To105_NLO->Fill(mW1_65To105,weight);
	  Leading_Photon_MVA_NLO->Fill(Leading_Photon_MVA,weight);
	  Subleading_Photon_MVA_NLO->Fill(Subleading_Photon_MVA,weight);
	  goodJets_0_pt_NLO->Fill(goodJets_0_pt,weight);
	  goodJets_1_pt_NLO->Fill(goodJets_1_pt,weight);
	  if (dipho_pt>150) {
	    countnumber1[4]=countnumber1[4]+weight;
	    costhetastar_NLO->Fill(abs(costhetastar),weight);
	    costheta1_NLO->Fill(costheta1,weight);
	    costheta2_NLO->Fill(costheta2,weight);
	    Phi_NLO->Fill(Phi,weight);
	    Phi1_NLO->Fill(Phi1,weight);
	  }
	}
      }
      
    }
    
    
  }
 
  std::cout <<"TotalNLO:"<<countnumber1[0]<<"->"<<countnumber1[0]/countnumber1[0]<<std::endl;
  std::cout <<"passPhotonSels:"<<countnumber1[1]<<"->"<<countnumber1[1]/countnumber1[0]<<std::endl;
  std::cout <<"bveto:"<<countnumber1[2]<<"->"<<countnumber1[2]/countnumber1[0]<<std::endl;
  std::cout <<"DeltaPhi_HH:"<<countnumber1[3]<<"->"<<countnumber1[3]/countnumber1[0]<<std::endl;
  std::cout <<"dipho_pt:"<<countnumber1[4]<<"->"<<countnumber1[4]/countnumber1[0]<<std::endl;
  
 
  
  

  

  for (int i=0; i<entries2; ++i){
    t2->GetEntry(i);
    if (CMS_hgg_mass>115 && CMS_hgg_mass<135){continue;}
    countnumber2[0]=countnumber2[0]+1;
    
    if (DeltaPhi_HH>pi) {DeltaPhi_HH = 2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<-pi) {DeltaPhi_HH = -2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<0) {DeltaPhi_HH=-DeltaPhi_HH;}
    DeltaR_HH=sqrt(DeltaEta_HH*DeltaEta_HH+DeltaPhi_HH*DeltaPhi_HH);
    dipho_MVA_Data->Fill(dipho_MVA,weight);
    ZeroVtx_z_Data->Fill(ZeroVtx_z,weight);
    
    HHCandidate_pt_Data->Fill(HHCandidate_pt,weight);
    HHCandidate_M_Data->Fill(HHCandidate_M,weight);
    float ET_tot=goodJets_0_pt+goodJets_1_pt+goodJets_2_pt+goodJets_3_pt;
    if (goodJets_4_pt>=0) {ET_tot=ET_tot+goodJets_4_pt;}
    if (goodJets_5_pt>=0){ET_tot=ET_tot+goodJets_5_pt;}
    if (goodJets_6_pt>=0){ET_tot=ET_tot+goodJets_6_pt;}
    if (goodJets_7_pt>=0){ET_tot=ET_tot+goodJets_7_pt;}
    if (goodJets_8_pt>=0){ET_tot=ET_tot+goodJets_8_pt;}
    if (goodJets_9_pt>=0){ET_tot=ET_tot+goodJets_9_pt;}
    
    if (passPhotonSels > 0.5) {
      //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5){
      //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5 && DeltaR_HH>1.5) {
      countnumber2[1]=countnumber2[1]+weight;
      b_dis_1_Data->Fill(goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      b_dis_2_Data->Fill(goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      
      DeltaR_HH_Data->Fill(DeltaR_HH,weight);
      HWWCandidate_M_Data->Fill(HWWCandidate_M,weight);
      W1Candidate_M_Data->Fill(W1Candidate_M,weight);
      
      if (goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 ){
	countnumber2[2]=countnumber2[2]+weight;
	DeltaPhi_HH_Data->Fill(DeltaPhi_HH,weight);
	
	ET_rest_Data->Fill(ET_tot-sqrt(HWWCandidate_pt*HWWCandidate_pt+HWWCandidate_M*HWWCandidate_M),weight);

	/*costhetastar_Data->Fill(costhetastar,weight);
	costheta1_Data->Fill(costheta1,weight);
	costheta2_Data->Fill(costheta2,weight);
	Phi_Data->Fill(Phi,weight);
	Phi1_Data->Fill(Phi1,weight);*/

	if (DeltaPhi_HH>2.5){
	  
	  countnumber2[3]=countnumber2[3]+weight;
	  HGGpt_Data->Fill(dipho_pt,weight);
	  mH_105To160_Data->Fill(mH_105To160,weight);
	  mW1_65To105_Data->Fill(mW1_65To105,weight);
	  Leading_Photon_MVA_Data->Fill(Leading_Photon_MVA,weight);
	  Subleading_Photon_MVA_Data->Fill(Subleading_Photon_MVA,weight);
	  goodJets_0_pt_Data->Fill(goodJets_0_pt,weight);
	  goodJets_1_pt_Data->Fill(goodJets_1_pt,weight);
	  if (dipho_pt>150) {
	    countnumber2[4]=countnumber2[4]+weight;
	    costhetastar_Data->Fill(abs(costhetastar),weight);
	    costheta1_Data->Fill(costheta1,weight);
	    costheta2_Data->Fill(costheta2,weight);
	    Phi_Data->Fill(Phi,weight);
	    Phi1_Data->Fill(Phi1,weight);
	  }
	}
      }
    }
  
   
  }


  std::cout <<"TotalData:"<<countnumber2[0]<<"->"<<countnumber2[0]/countnumber2[0]<<std::endl;
  std::cout <<"passPhotonSels:"<<countnumber2[1]<<"->"<<countnumber2[1]/countnumber2[0]<<std::endl;
  std::cout <<"bveto:"<<countnumber2[2]<<"->"<<countnumber2[2]/countnumber2[0]<<std::endl;
  std::cout <<"DeltaPhi_HH:"<<countnumber2[3]<<"->"<<countnumber2[3]/countnumber2[0]<<std::endl;
  std::cout <<"dipho_pT:"<<countnumber2[4]<<"->"<<countnumber2[4]/countnumber2[0]<<std::endl;

    for (int i=0; i<entries3; ++i){
    t3->GetEntry(i);
    countnumber3[0]=countnumber3[0]+weight;
    TLorentzVector gen_leading_photon;
    TLorentzVector gen_Subleading_photon;
    gen_leading_photon.SetPtEtaPhiE(Leading_GEN_Photon_pt,Leading_GEN_Photon_eta,Leading_GEN_Photon_phi,Leading_GEN_Photon_E);
    gen_Subleading_photon.SetPtEtaPhiE(Subleading_GEN_Photon_pt,Subleading_GEN_Photon_eta,Subleading_GEN_Photon_phi,Subleading_GEN_Photon_E);
    float gen_dipho_pt=(gen_leading_photon+gen_Subleading_photon).Pt();
    gen_dipho_pt_singleH->Fill(gen_dipho_pt,weight);

    if (DeltaPhi_HH>pi) {DeltaPhi_HH = 2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<-pi) {DeltaPhi_HH = -2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<0) {DeltaPhi_HH=-DeltaPhi_HH;}
    DeltaR_HH=sqrt(DeltaEta_HH*DeltaEta_HH+DeltaPhi_HH*DeltaPhi_HH);
    dipho_MVA_singleH->Fill(dipho_MVA,weight);
    ZeroVtx_z_singleH->Fill(ZeroVtx_z,weight);
    
    HHCandidate_pt_singleH->Fill(HHCandidate_pt,weight);
    HHCandidate_M_singleH->Fill(HHCandidate_M,weight);
    float ET_tot=goodJets_0_pt+goodJets_1_pt+goodJets_2_pt+goodJets_3_pt;
    if (goodJets_4_pt>=0) {ET_tot=ET_tot+goodJets_4_pt;}
    if (goodJets_5_pt>=0){ET_tot=ET_tot+goodJets_5_pt;}
    if (goodJets_6_pt>=0){ET_tot=ET_tot+goodJets_6_pt;}
    if (goodJets_7_pt>=0){ET_tot=ET_tot+goodJets_7_pt;}
    if (goodJets_8_pt>=0){ET_tot=ET_tot+goodJets_8_pt;}
    if (goodJets_9_pt>=0){ET_tot=ET_tot+goodJets_9_pt;}
    
    if (passPhotonSels > 0.5){
    //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5){
      //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5 && DeltaR_HH>1.5){
      countnumber3[1]=countnumber3[1]+weight;
      b_dis_1_singleH->Fill(goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      b_dis_2_singleH->Fill(goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      
      DeltaR_HH_singleH->Fill(DeltaR_HH,weight);
      HWWCandidate_M_singleH->Fill(HWWCandidate_M,weight);
      W1Candidate_M_singleH->Fill(W1Candidate_M,weight);
      
      if (goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221){ 
	countnumber3[2]=countnumber3[2]+weight;
	
	DeltaPhi_HH_singleH->Fill(DeltaPhi_HH,weight);
	ET_rest_singleH->Fill(ET_tot-sqrt(HWWCandidate_pt*HWWCandidate_pt+HWWCandidate_M*HWWCandidate_M),weight);
	if (DeltaPhi_HH>2.5){
	  
	  countnumber3[3]=countnumber3[3]+weight;
	  HGGpt_ggh->Fill(dipho_pt,weight);
	  HGGpt_singleH->Fill(dipho_pt,weight);
	  mH_105To160_singleH->Fill(mH_105To160,weight);
	  mW1_65To105_singleH->Fill(mW1_65To105,weight);
	  Leading_Photon_MVA_singleH->Fill(Leading_Photon_MVA,weight);
	  Subleading_Photon_MVA_singleH->Fill(Subleading_Photon_MVA,weight);
	  goodJets_0_pt_singleH->Fill(goodJets_0_pt,weight);
	  goodJets_1_pt_singleH->Fill(goodJets_1_pt,weight);
	  if (dipho_pt>150) {
	    countnumber3[4]=countnumber3[4]+weight;
	    costhetastar_singleH->Fill(abs(costhetastar),weight);
	    costheta1_singleH->Fill(costheta1,weight);
	    costheta2_singleH->Fill(costheta2,weight);
	    Phi_singleH->Fill(Phi,weight);
	    Phi1_singleH->Fill(Phi1,weight);
	  }
	}
      }
      
    }
    

    
  }
 
  std::cout <<"Totalggh:"<<countnumber3[0]<<"->"<<countnumber3[0]/countnumber3[0]<<std::endl;
  std::cout <<"passPhotonSels:"<<countnumber3[1]<<"->"<<countnumber3[1]/countnumber3[0]<<std::endl;
  std::cout <<"bveto:"<<countnumber3[2]<<"->"<<countnumber3[2]/countnumber3[0]<<std::endl;
  std::cout <<"DeltaPhi_HH:"<<countnumber3[3]<<"->"<<countnumber3[3]/countnumber3[0]<<std::endl;
  std::cout <<"dipho_pt:"<<countnumber3[4]<<"->"<<countnumber3[4]/countnumber3[0]<<std::endl;
  
  for (int i=0; i<entries4; ++i){
    t4->GetEntry(i);
    countnumber4[0]=countnumber4[0]+weight;
    TLorentzVector gen_leading_photon;
    TLorentzVector gen_Subleading_photon;
    gen_leading_photon.SetPtEtaPhiE(Leading_GEN_Photon_pt,Leading_GEN_Photon_eta,Leading_GEN_Photon_phi,Leading_GEN_Photon_E);
    gen_Subleading_photon.SetPtEtaPhiE(Subleading_GEN_Photon_pt,Subleading_GEN_Photon_eta,Subleading_GEN_Photon_phi,Subleading_GEN_Photon_E);
    float gen_dipho_pt=(gen_leading_photon+gen_Subleading_photon).Pt();
    gen_dipho_pt_singleH->Fill(gen_dipho_pt,weight);

    if (DeltaPhi_HH>pi) {DeltaPhi_HH = 2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<-pi) {DeltaPhi_HH = -2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<0) {DeltaPhi_HH=-DeltaPhi_HH;}
    DeltaR_HH=sqrt(DeltaEta_HH*DeltaEta_HH+DeltaPhi_HH*DeltaPhi_HH);
    dipho_MVA_singleH->Fill(dipho_MVA,weight);
    ZeroVtx_z_singleH->Fill(ZeroVtx_z,weight);
    dZ_singleH->Fill(dZ);
    //DeltaPhi_HH_singleH->Fill(DeltaPhi_HH,weight);
    HHCandidate_pt_singleH->Fill(HHCandidate_pt,weight);
    HHCandidate_M_singleH->Fill(HHCandidate_M,weight);
    float ET_tot=goodJets_0_pt+goodJets_1_pt+goodJets_2_pt+goodJets_3_pt;
    if (goodJets_4_pt>=0) {ET_tot=ET_tot+goodJets_4_pt;}
    if (goodJets_5_pt>=0){ET_tot=ET_tot+goodJets_5_pt;}
    if (goodJets_6_pt>=0){ET_tot=ET_tot+goodJets_6_pt;}
    if (goodJets_7_pt>=0){ET_tot=ET_tot+goodJets_7_pt;}
    if (goodJets_8_pt>=0){ET_tot=ET_tot+goodJets_8_pt;}
    if (goodJets_9_pt>=0){ET_tot=ET_tot+goodJets_9_pt;}
    
    if (passPhotonSels > 0.5){
      //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5){
      //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5 && DeltaR_HH>1.5){
      countnumber4[1]=countnumber4[1]+weight;
      b_dis_1_singleH->Fill(goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      b_dis_2_singleH->Fill(goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      
      DeltaR_HH_singleH->Fill(DeltaR_HH,weight);
      HWWCandidate_M_singleH->Fill(HWWCandidate_M,weight);
      W1Candidate_M_singleH->Fill(W1Candidate_M,weight);
      
      if (goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221){ 
	countnumber4[2]=countnumber4[2]+weight;
	
	DeltaPhi_HH_singleH->Fill(DeltaPhi_HH,weight);
	ET_rest_singleH->Fill(ET_tot-sqrt(HWWCandidate_pt*HWWCandidate_pt+HWWCandidate_M*HWWCandidate_M),weight);
	if (DeltaPhi_HH>2.5){
	  //ET_rest_singleH->Fill(ET_tot-sqrt(HWWCandidate_pt*HWWCandidate_pt+HWWCandidate_M*HWWCandidate_M),weight);
	  countnumber4[3]=countnumber4[3]+weight;
	  HGGpt_tth->Fill(dipho_pt,weight);
	  HGGpt_singleH->Fill(dipho_pt,weight);
	  mH_105To160_singleH->Fill(mH_105To160,weight);
	  mW1_65To105_singleH->Fill(mW1_65To105,weight);
	  Leading_Photon_MVA_singleH->Fill(Leading_Photon_MVA,weight);
	  Subleading_Photon_MVA_singleH->Fill(Subleading_Photon_MVA,weight);
	  goodJets_0_pt_singleH->Fill(goodJets_0_pt,weight);
	  goodJets_1_pt_singleH->Fill(goodJets_1_pt,weight);
	  if (dipho_pt>150) {
	    countnumber4[4]=countnumber4[4]+weight;
	    costhetastar_singleH->Fill(abs(costhetastar),weight);
	    costheta1_singleH->Fill(costheta1,weight);
	    costheta2_singleH->Fill(costheta2,weight);
	    Phi_singleH->Fill(Phi,weight);
	    Phi1_singleH->Fill(Phi1,weight);
	  }
	}
      }
      
    }
    
    
  }
 
  std::cout <<"Totaltth:"<<countnumber4[0]<<"->"<<countnumber4[0]/countnumber4[0]<<std::endl;
  std::cout <<"passPhotonSels:"<<countnumber4[1]<<"->"<<countnumber4[1]/countnumber4[0]<<std::endl;
  std::cout <<"bveto:"<<countnumber4[2]<<"->"<<countnumber4[2]/countnumber4[0]<<std::endl;
  std::cout <<"DeltaPhi_HH:"<<countnumber4[3]<<"->"<<countnumber4[3]/countnumber4[0]<<std::endl;
  std::cout <<"dipho_pt:"<<countnumber4[4]<<"->"<<countnumber4[4]/countnumber4[0]<<std::endl;

    for (int i=0; i<entries5; ++i){
    t5->GetEntry(i);
    countnumber5[0]=countnumber5[0]+weight;
    TLorentzVector gen_leading_photon;
    TLorentzVector gen_Subleading_photon;
    gen_leading_photon.SetPtEtaPhiE(Leading_GEN_Photon_pt,Leading_GEN_Photon_eta,Leading_GEN_Photon_phi,Leading_GEN_Photon_E);
    gen_Subleading_photon.SetPtEtaPhiE(Subleading_GEN_Photon_pt,Subleading_GEN_Photon_eta,Subleading_GEN_Photon_phi,Subleading_GEN_Photon_E);
    float gen_dipho_pt=(gen_leading_photon+gen_Subleading_photon).Pt();
    gen_dipho_pt_singleH->Fill(gen_dipho_pt,weight);

    if (DeltaPhi_HH>pi) {DeltaPhi_HH = 2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<-pi) {DeltaPhi_HH = -2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<0) {DeltaPhi_HH=-DeltaPhi_HH;}
    DeltaR_HH=sqrt(DeltaEta_HH*DeltaEta_HH+DeltaPhi_HH*DeltaPhi_HH);
    dipho_MVA_singleH->Fill(dipho_MVA,weight);
    ZeroVtx_z_singleH->Fill(ZeroVtx_z,weight);
    //DeltaPhi_HH_singleH->Fill(DeltaPhi_HH,weight);
    HHCandidate_pt_singleH->Fill(HHCandidate_pt,weight);
    HHCandidate_M_singleH->Fill(HHCandidate_M,weight);
    
    float ET_tot=goodJets_0_pt+goodJets_1_pt+goodJets_2_pt+goodJets_3_pt;
    if (goodJets_4_pt>=0) {ET_tot=ET_tot+goodJets_4_pt;}
    if (goodJets_5_pt>=0){ET_tot=ET_tot+goodJets_5_pt;}
    if (goodJets_6_pt>=0){ET_tot=ET_tot+goodJets_6_pt;}
    if (goodJets_7_pt>=0){ET_tot=ET_tot+goodJets_7_pt;}
    if (goodJets_8_pt>=0){ET_tot=ET_tot+goodJets_8_pt;}
    if (goodJets_9_pt>=0){ET_tot=ET_tot+goodJets_9_pt;}
    
    if (passPhotonSels > 0.5){
      //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5){
      //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5 && DeltaR_HH>1.5){
      countnumber5[1]=countnumber5[1]+weight;
      b_dis_1_singleH->Fill(goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      b_dis_2_singleH->Fill(goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      
      DeltaR_HH_singleH->Fill(DeltaR_HH,weight);
      HWWCandidate_M_singleH->Fill(HWWCandidate_M,weight);
      W1Candidate_M_singleH->Fill(W1Candidate_M,weight);
      
      if (goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221){ 
	countnumber5[2]=countnumber5[2]+weight;
	
	DeltaPhi_HH_singleH->Fill(DeltaPhi_HH,weight);
	ET_rest_singleH->Fill(ET_tot-sqrt(HWWCandidate_pt*HWWCandidate_pt+HWWCandidate_M*HWWCandidate_M),weight);
	if (DeltaPhi_HH>2.5){
	  //ET_rest_singleH->Fill(ET_tot-sqrt(HWWCandidate_pt*HWWCandidate_pt+HWWCandidate_M*HWWCandidate_M),weight);
	  countnumber5[3]=countnumber5[3]+weight;
	  HGGpt_vbf->Fill(dipho_pt,weight);
	  HGGpt_singleH->Fill(dipho_pt,weight);
	  mH_105To160_singleH->Fill(mH_105To160,weight);
	  mW1_65To105_singleH->Fill(mW1_65To105,weight);
	  Leading_Photon_MVA_singleH->Fill(Leading_Photon_MVA,weight);
	  Subleading_Photon_MVA_singleH->Fill(Subleading_Photon_MVA,weight);
	  goodJets_0_pt_singleH->Fill(goodJets_0_pt,weight);
	  goodJets_1_pt_singleH->Fill(goodJets_1_pt,weight);
	  if (dipho_pt>150) {
	    countnumber5[4]=countnumber5[4]+weight;
	    costhetastar_singleH->Fill(abs(costhetastar),weight);
	    costheta1_singleH->Fill(costheta1,weight);
	    costheta2_singleH->Fill(costheta2,weight);
	    Phi_singleH->Fill(Phi,weight);
	    Phi1_singleH->Fill(Phi1,weight);
	  }
	}
      }
      
    }

    
  }
 
  std::cout <<"Totalvbf:"<<countnumber5[0]<<"->"<<countnumber5[0]/countnumber5[0]<<std::endl;
  std::cout <<"passPhotonSels:"<<countnumber5[1]<<"->"<<countnumber5[1]/countnumber5[0]<<std::endl;
  std::cout <<"bveto:"<<countnumber5[2]<<"->"<<countnumber5[2]/countnumber5[0]<<std::endl;
  std::cout <<"DeltaPhi_HH:"<<countnumber5[3]<<"->"<<countnumber5[3]/countnumber5[0]<<std::endl;
  std::cout <<"dipho_pt:"<<countnumber5[4]<<"->"<<countnumber5[4]/countnumber5[0]<<std::endl;

    for (int i=0; i<entries6; ++i){
    t6->GetEntry(i);
    countnumber6[0]=countnumber6[0]+weight;
    TLorentzVector gen_leading_photon;
    TLorentzVector gen_Subleading_photon;
    gen_leading_photon.SetPtEtaPhiE(Leading_GEN_Photon_pt,Leading_GEN_Photon_eta,Leading_GEN_Photon_phi,Leading_GEN_Photon_E);
    gen_Subleading_photon.SetPtEtaPhiE(Subleading_GEN_Photon_pt,Subleading_GEN_Photon_eta,Subleading_GEN_Photon_phi,Subleading_GEN_Photon_E);
    float gen_dipho_pt=(gen_leading_photon+gen_Subleading_photon).Pt();
    gen_dipho_pt_singleH->Fill(gen_dipho_pt,weight);

    if (DeltaPhi_HH>pi) {DeltaPhi_HH = 2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<-pi) {DeltaPhi_HH = -2*pi-DeltaPhi_HH;}
    if (DeltaPhi_HH<0) {DeltaPhi_HH=-DeltaPhi_HH;}
    DeltaR_HH=sqrt(DeltaEta_HH*DeltaEta_HH+DeltaPhi_HH*DeltaPhi_HH);
    dipho_MVA_singleH->Fill(dipho_MVA,weight);
    ZeroVtx_z_singleH->Fill(ZeroVtx_z,weight);
    //DeltaPhi_HH_singleH->Fill(DeltaPhi_HH,weight);
    HHCandidate_pt_singleH->Fill(HHCandidate_pt,weight);
    HHCandidate_M_singleH->Fill(HHCandidate_M,weight);
    float ET_tot=goodJets_0_pt+goodJets_1_pt+goodJets_2_pt+goodJets_3_pt;
    if (goodJets_4_pt>=0) {ET_tot=ET_tot+goodJets_4_pt;}
    if (goodJets_5_pt>=0){ET_tot=ET_tot+goodJets_5_pt;}
    if (goodJets_6_pt>=0){ET_tot=ET_tot+goodJets_6_pt;}
    if (goodJets_7_pt>=0){ET_tot=ET_tot+goodJets_7_pt;}
    if (goodJets_8_pt>=0){ET_tot=ET_tot+goodJets_8_pt;}
    if (goodJets_9_pt>=0){ET_tot=ET_tot+goodJets_9_pt;}
    
    if (passPhotonSels > 0.5){
      //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5){
      //if (passPhotonSels > 0.5 && DeltaPhi_HH>1.5 && DeltaR_HH>1.5){
      countnumber6[1]=countnumber6[1]+weight;
      b_dis_1_singleH->Fill(goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      b_dis_2_singleH->Fill(goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb,weight);
      
      DeltaR_HH_singleH->Fill(DeltaR_HH,weight);
      HWWCandidate_M_singleH->Fill(HWWCandidate_M,weight);
      W1Candidate_M_singleH->Fill(W1Candidate_M,weight);
      
      if (goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_0_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_1_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_2_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_3_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_4_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_5_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_6_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_7_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_8_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221 && goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_probbb+goodJets_9_bDiscriminator_mini_pfDeepFlavourJetTags_problepb<0.7221){ 
	countnumber6[2]=countnumber6[2]+weight;
	
	DeltaPhi_HH_singleH->Fill(DeltaPhi_HH,weight);
	ET_rest_singleH->Fill(ET_tot-sqrt(HWWCandidate_pt*HWWCandidate_pt+HWWCandidate_M*HWWCandidate_M),weight);
	if (DeltaPhi_HH>2.5){
	  //ET_rest_singleH->Fill(ET_tot-sqrt(HWWCandidate_pt*HWWCandidate_pt+HWWCandidate_M*HWWCandidate_M),weight);
	  countnumber6[3]=countnumber6[3]+weight;
	  HGGpt_wzh->Fill(dipho_pt,weight);
	  HGGpt_singleH->Fill(dipho_pt,weight);
	  mH_105To160_singleH->Fill(mH_105To160,weight);
	  mW1_65To105_singleH->Fill(mW1_65To105,weight);
	  Leading_Photon_MVA_singleH->Fill(Leading_Photon_MVA,weight);
	  Subleading_Photon_MVA_singleH->Fill(Subleading_Photon_MVA,weight);
	  goodJets_0_pt_singleH->Fill(goodJets_0_pt,weight);
	  goodJets_1_pt_singleH->Fill(goodJets_1_pt,weight);
	  if (dipho_pt>150) {
	    countnumber6[4]=countnumber6[4]+weight;
	    costhetastar_singleH->Fill(abs(costhetastar),weight);
	    costheta1_singleH->Fill(costheta1,weight);
	    costheta2_singleH->Fill(costheta2,weight);
	    Phi_singleH->Fill(Phi,weight);
	    Phi1_singleH->Fill(Phi1,weight);
	  }
	}
      }
      
    }
    

    
  }
 
  std::cout <<"Totalwzh:"<<countnumber6[0]<<"->"<<countnumber6[0]/countnumber6[0]<<std::endl;
  std::cout <<"passPhotonSels:"<<countnumber6[1]<<"->"<<countnumber6[1]/countnumber6[0]<<std::endl;
  std::cout <<"bveto:"<<countnumber6[2]<<"->"<<countnumber6[2]/countnumber6[0]<<std::endl;
  std::cout <<"DeltaPhi_HH:"<<countnumber6[3]<<"->"<<countnumber6[3]/countnumber6[0]<<std::endl;
  std::cout <<"dipho_pt:"<<countnumber6[4]<<"->"<<countnumber6[4]/countnumber6[0]<<std::endl;
  

  double num_NLO;
  double num_Data;
  double num_singleH;
  double num_ggh;
  double num_tth;
  double num_vbf;
  double num_wzh;
  
  double tot_NLO=ET_rest_NLO->Integral();
  double tot_Data=ET_rest_Data->Integral();
  double tot_singleH=ET_rest_singleH->Integral();
  //double tot_ggh=ET_rest_ggh->Integral();
  //double tot_tth=ET_rest_tth->Integral();
  //double tot_vbf=ET_rest_vbf->Integral();
  //double tot_wzh=ET_rest_wzh->Integral();
  double nocut_singleH=countnumber3[0]+countnumber4[0]+countnumber5[0]+countnumber6[0];
  double passpho_singleH=countnumber3[1]+countnumber4[1]+countnumber5[1]+countnumber6[1];
  double bveto_singleH=countnumber3[2]+countnumber4[2]+countnumber5[2]+countnumber6[2];
  double diphopt_singleH=countnumber3[3]+countnumber4[3]+countnumber5[3]+countnumber6[3];
  double ET_singleH=countnumber3[4]+countnumber4[4]+countnumber5[4]+countnumber6[4];
  std::cout <<"TotalsingleH:"<<nocut_singleH<<"->"<<nocut_singleH/nocut_singleH<<std::endl;
  std::cout <<"passPhotonSel:"<<passpho_singleH<<"->"<<passpho_singleH/nocut_singleH<<std::endl;
  std::cout <<"bveto:"<<bveto_singleH<<"->"<<bveto_singleH/nocut_singleH<<std::endl;
  std::cout <<"DeltaPhi_HH:"<<diphopt_singleH<<"->"<<diphopt_singleH/nocut_singleH<<std::endl;
  std::cout <<"dipho_pt:"<<ET_singleH<<"->"<<ET_singleH/nocut_singleH<<std::endl;
  
  //std::cout <<"singleH_dPHI:"<<(diphopt_singleH/bveto_singleH)<<std::endl;
  //std::cout <<"signifwithoutdPhi:"<<((countnumber1[2])/sqrt(countnumber2[2]+bveto_singleH))<<std::endl;
  std::cout <<"signif:"<<((countnumber1[3])/sqrt(countnumber2[3]+countnumber1[3]+countnumber3[3]+countnumber4[3]+countnumber5[3]+countnumber6[3]))<<std::endl;
  //std::cout <<"fraction_NLO:"<<tot_NLO/countnumber1[2]<<"fraction_Data:"<<tot_Data/countnumber2[2]<<"fraction_SingleH:"<<(tot_ggh+tot_tth+tot_vbf+tot_wzh)/(bveto_singleH)<<std::endl;
  
  for (int i=0; i<700; ++i){
    //num_NLO=DeltaPhi_HH_NLO->Integral(i,1000);
    //num_Data=DeltaPhi_HH_Data->Integral(i,1000);
    //num_singleH=DeltaPhi_HH_singleH->Integral(i,1000);
    
    num_NLO=HGGpt_NLO->Integral(i,1000);
    num_Data=HGGpt_Data->Integral(i,1000);
    num_singleH=HGGpt_singleH->Integral(i,1000);

    //num_NLO=costhetastar_NLO->Integral(0,i);
    //num_Data=costhetastar_Data->Integral(0,i);
    //num_singleH=costhetastar_singleH->Integral(0,i);

    //num_ggh=ET_rest_ggh->Integral(0,i);
    //num_tth=ET_rest_tth->Integral(0,i);
    //num_vbf=ET_rest_vbf->Integral(0,i);
    //num_wzh=ET_rest_wzh->Integral(0,i);
    if (num_Data+num_NLO+num_singleH != 0.0){
      //S_B->SetBinContent(i,(num_NLO/tot_NLO)/(num_Data/tot_Data));
      S_B->SetBinContent(i,(num_NLO)/sqrt(num_Data+num_NLO+num_singleH));
    }
  }
  

  TCanvas *c0 = new TCanvas();
  S_B->Draw();
 
  c0->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/S_B.pdf");
  
  TCanvas *c1 = new TCanvas();
  HGGpt_NLO->SetLineColor(1);
  HGGpt_Data->SetLineColor(3);
  HGGpt_singleH->SetLineColor(2);
  HGGpt_Data->DrawNormalized();
  HGGpt_NLO->DrawNormalized("same");
  HGGpt_singleH->DrawNormalized("same");
  
  auto legend1 = new TLegend(0.6,0.7,0.9,0.9);
   legend1->AddEntry(HGGpt_NLO,"Signal");
   legend1->AddEntry(HGGpt_Data,"Bkg");
   legend1->AddEntry(HGGpt_singleH,"SingleHiggs");
   legend1->Draw();

  c1->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/HGGpt_2016.pdf");
  /*
  TCanvas *c2 = new TCanvas();
  gen_dipho_pt_NLO->SetLineColor(3);
  gen_dipho_pt_singleH->SetLineColor(2);

  gen_dipho_pt_NLO->DrawNormalized();
  gen_dipho_pt_singleH->DrawNormalized("same");
 
  c2->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/gen_dipho_pt_2016_withoutmasswindow.png");

  TCanvas *c3 = new TCanvas();
  HWWCandidate_M_NLO->SetLineColor(3);
  HWWCandidate_M_Data->SetLineColor(1);
  HWWCandidate_M_singleH->SetLineColor(2);
  HWWCandidate_M_NLO->DrawNormalized();
  HWWCandidate_M_Data->DrawNormalized("same");
  HWWCandidate_M_singleH->DrawNormalized("same");
 
  c3->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/HWWCandidate_M_2016_withoutmasswindow.png");

  TCanvas *c4 = new TCanvas();
  W1Candidate_M_NLO->SetLineColor(3);
  W1Candidate_M_Data->SetLineColor(1);
  W1Candidate_M_singleH->SetLineColor(2);
  W1Candidate_M_NLO->DrawNormalized();
  W1Candidate_M_Data->DrawNormalized("same");
  W1Candidate_M_singleH->DrawNormalized("same");
 
  c4->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/W1Candidate_M_2016_withoutmasswindow.png");*/

  
 
  
  TCanvas *c10 = new TCanvas();
  DeltaPhi_HH_NLO->SetLineColor(1);
  DeltaPhi_HH_Data->SetLineColor(3);
  DeltaPhi_HH_singleH->SetLineColor(2);
  DeltaPhi_HH_NLO->DrawNormalized();
  DeltaPhi_HH_Data->DrawNormalized("same");
  DeltaPhi_HH_singleH->DrawNormalized("same");
 
  auto legend2 = new TLegend(0.1,0.7,0.45,0.9);
   legend2->AddEntry(DeltaPhi_HH_NLO,"Signal");
   legend2->AddEntry(DeltaPhi_HH_Data,"Bkg");
   legend2->AddEntry(DeltaPhi_HH_singleH,"SingleHiggs");
   legend2->Draw();

  c10->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/DeltaPhi_HH.pdf");
  /* 
  TCanvas *c11 = new TCanvas();
  costhetastar_NLO->SetLineColor(1);
  costhetastar_Data->SetLineColor(3);
  costhetastar_singleH->SetLineColor(2);
  costhetastar_NLO->DrawNormalized();
  costhetastar_Data->DrawNormalized("same");
  costhetastar_singleH->DrawNormalized("same");
 
  c11->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/costhetastar_2016_withoutmasswindow.png");

  

  TCanvas *c14 = new TCanvas();
  HHCandidate_pt_NLO->SetLineColor(1);
  HHCandidate_pt_Data->SetLineColor(3);
  HHCandidate_pt_singleH->SetLineColor(2);
  HHCandidate_pt_NLO->DrawNormalized();
  HHCandidate_pt_Data->DrawNormalized("same");
  HHCandidate_pt_singleH->DrawNormalized("same");
  
  
 
  c14->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/HHCandidate_pt_2016_withoutmasswindow.png");

  TCanvas *c15 = new TCanvas();
  costheta1_NLO->SetLineColor(1);
  costheta1_Data->SetLineColor(3);
  costheta1_singleH->SetLineColor(2);
  costheta1_NLO->DrawNormalized();
  costheta1_Data->DrawNormalized("same");
  costheta1_singleH->DrawNormalized("same");

 
  c15->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/costheta1_2016_withoutmasswindow.png");
  
  TCanvas *c16 = new TCanvas();
  costheta2_NLO->SetLineColor(1);
  costheta2_Data->SetLineColor(3);
  costheta2_singleH->SetLineColor(2);
  costheta2_NLO->DrawNormalized();
  costheta2_Data->DrawNormalized("same");
  costheta2_singleH->DrawNormalized("same");

 
  c16->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/costheta2_2016_withoutmasswindow.png");

  TCanvas *c17 = new TCanvas();
  Phi_NLO->SetLineColor(1);
  Phi_Data->SetLineColor(3);
  Phi_singleH->SetLineColor(2);
  Phi_NLO->DrawNormalized();
  Phi_Data->DrawNormalized("same");
  Phi_singleH->DrawNormalized("same");

 
  c17->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/Phi_2016_withoutmasswindow.png");

  TCanvas *c18 = new TCanvas();
  Phi1_NLO->SetLineColor(1);
  Phi1_Data->SetLineColor(3);
  Phi1_singleH->SetLineColor(2);
  Phi1_NLO->DrawNormalized();
  Phi1_Data->DrawNormalized("same");
  Phi1_singleH->DrawNormalized("same");

 
  c18->SaveAs("/afs/cern.ch/user/l/lipe/private/HHtoWWgg/CMSSW_10_2_22/src/GEN-SIM-analyzer/GenAnalyzer/Plotting-Macro/optimz/Phi1_2016_withoutmasswindow.png");*/
}

