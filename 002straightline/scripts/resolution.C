#include "lhcbStyle.h"
double x(double omega, double phi, double d0)
{
    //return (1/omega - d0) * sin(phi);
    return (0/omega - d0) * sin(phi);
}
double y(double omega, double phi, double d0)
{
    return -(0/omega - d0) * cos(phi);
}
void resolution()
{
    lhcbStyle();
    TFile *f = new TFile("tuple.root", "read");
    TTree * tree = (TTree*)f->Get("tracksTree");
    TCut cut = "has_marlinTrack && has_siTrack && has_cluptraTrack";
    TCut range1 = "abs( x(marlinTrack_omega, marlinTrack_phi, marlinTrack_d0) - x(siTrack_omega, siTrack_phi, siTrack_d0)) < 0.02";
    TCut range2 = "abs( y(marlinTrack_omega, marlinTrack_phi, marlinTrack_d0) - y(siTrack_omega, siTrack_phi, siTrack_d0)) < 0.02";
    TCut range3 = "abs(marlinTrack_z0 - siTrack_z0) < 0.02";
    TCanvas *c1 = new TCanvas("x", "");
    tree->Draw("x(marlinTrack_omega, marlinTrack_phi, marlinTrack_d0) - x(siTrack_omega, siTrack_phi, siTrack_d0) >> h1", cut && range1);
    TCanvas *c2 = new TCanvas("y", "");
    tree->Draw("y(marlinTrack_omega, marlinTrack_phi, marlinTrack_d0) - y(siTrack_omega, siTrack_phi, siTrack_d0) >> h2", cut && range2);
    TCanvas *c3 = new TCanvas("z", "");
    tree->Draw("marlinTrack_z0 - siTrack_z0 >> h3", cut && range3);
    TH1D* h1 = (TH1D*)gDirectory->Get("h1");
    h1->GetXaxis()->SetTitle("x / mm");
    TH1D* h2 = (TH1D*)gDirectory->Get("h2");
    h2->GetXaxis()->SetTitle("y / mm");
    TH1D* h3 = (TH1D*)gDirectory->Get("h3");
    h3->GetXaxis()->SetTitle("z / mm");
    c1->SaveAs("x.png");
    c2->SaveAs("y.png");
    c3->SaveAs("z.png");
}
