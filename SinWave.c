const double Pi = 3.1415926535;

void linspace(double a, double b, int n, double *x)
{
	double h = (b - a)/ n;
	
	for (int i=0; i < n; i++)
	{
		x[i] = a + h* i;
	}
}

void Plot(int n, double *x, double *y)
{
	TGraph *gr = new TGraph(n, x, y);
	
	gr->SetLineWidth(2);
	gr->SetLineColor(kRed);
	
	gr->SetTitle("Sine wave");
	gr->GetXaxis()->SetTitle("x");
	gr->GetYaxis()->SetTitle("y");
	
	TCanvas *c1 = new TCanvas();
	gr->Draw("AL");
}

void SinWave()
{
	double a = 0, b = 4* Pi, h = 0.01;
	const int n = (b - a)/h;
	
	double x[n], y[n];
	
	linspace(a, b, n, x);
	for (int i=0; i < n; i++)
	{ 
		y[i] = sin(x[i]) + sin(3* x[i]); 
	}
	
	Plot(n, x, y);
}

