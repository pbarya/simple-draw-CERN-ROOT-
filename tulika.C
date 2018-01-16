{
// this is a code to draw columns 
// Author: Prabhakar Tiwari 
// Date: 16 Jan 2018
char tit[100],file[1000],line[1000],str[100];
int skip,nlines,nx,ny;
cout<<"You are welcome. I am Ms. Tulika. I love drawing \n";
cout<<"Please Enter the file name you want to draw \n"; 
ifstream inf;
while(!inf.is_open()){
cin>>file;
inf.open(file);
if(!inf.is_open()) {cout<<"Sorry! I do not find file "<<file<<endl; 
cout<<"Please check your file name and enter a valid file"<<endl;
} 
else cout<<"I got the file "<<file<<" ... let's explore "<<endl;
}
nlines=0;
cout<<"Scanning file ..."<<endl;
while(inf.good()){
inf.getline(line,1000);
nlines++;}
inf.close();
long l,m;
inf.open(file,ios_base::binary); 
     l=inf.tellg();
     inf.seekg(0,ios::end);
     m=inf.tellg();
     inf.close();
cout<<" The file "<<file<<" has "<<nlines<<" lines And the file is "<<(m-l)*1.0E-3<<" kB"<<endl;
inf.open(file);
bool f_skip=0;
while(!f_skip){
cout<<"Please enter the  lines you want to skip (header lines!), you may press 0! \n";
cin>>skip;
if(skip>=nlines)cout<<"Warning!!! There are only "<<nlines<<" lines in file."<<endl; 
else f_skip=1;
}

cout<<"skipping "<<skip<<" lines .."<<endl;
string strr;
for(int i=0;i<skip;i++){
inf.getline(line,1000);
cout<<line<<endl;
}
streampos oldpos = inf.tellg(); //file position 
getline(inf,strr);
istringstream ss(strr);
cout<<str<<endl;
double var;
int ncolumns=0;
while(ss>>var)ncolumns++;
inf.seekg (oldpos); //restore position
bool column=0;
bool histogram=0;
while(!column){
cout<<" please enter the x and y columns you want me to draw"<<endl;
cout<<" (if want to draw histogram just eneter one column and h)"<<endl;
cin>>nx>>str;
ny=atoi(str);
char hist[]= "h";
char hist2[]= "H";
if(strcmp(str,hist) == 0 || strcmp(str,hist2)==0 ){ny=nx;histogram=1;}
if(ny==0){cout<<" no valid drawing opetion. the program will exit now"<<endl; exit(0);}
if(ny<=ncolumns && nx<=ncolumns)column=1;
else cout<<"Warning!!! Only "<<ncolumns<<" column(s) in file. Please Enter valid columns"<<endl;
}

int ndat=nlines-skip;
int ncol;
double xmax,xmin,sum;
xmax=-1.0E-100; xmin=1.0E100;
sum=0;
ncol=ny; 
if(ncol<nx) ncol=nx;
double* x= new double [ndat];
double* y= new double [ndat];
double* xx= new  double[ncol];
for(int i=0;i<<ndat;i++) x[i]=y[i]=0.0;
for(int i=0;i<<ncol;i++) xx[i]=0.0;
int n=0;
while(inf.good()){
for(int i=0;i<ncol;i++)inf>>xx[i];
inf.getline(line,1000);
x[n]=xx[nx-1];
y[n]=xx[ny-1];
if(x[n]>xmax)xmax=x[n];
if(x[n]<xmin)xmin=x[n];
sum+=x[n];
//cout<<x[n]<<"  "<<y[n]<<endl;
//getchar();
n++;
}
if(n<2){ cout<<"Somthing wrong with data file. Please check your data file and call me again. Just type tulika and I will be there for you!!!"<<endl;}
else if(!histogram){
cout<<"Okay I am going to draw column "<<nx<<" as x  and column "<<ny<<" as y"<<endl;
cout<<" There are "<<n<<" data point. Tulika is generating plot. You can explore the plot!!!"<<endl;
TCanvas *c1= new TCanvas ();
TGraph *gr= new TGraph(n,x,y);
gr->Draw("Ap");
gr->SetTitle("Hi! I am Tulika.");
gr->SetMarkerColor(kBlue);
sprintf(tit,"column %i",nx);
gr->GetXaxis()->SetTitle(tit);
gr->GetXaxis()->CenterTitle();
sprintf(tit,"column %i",ny);
gr->GetYaxis()->SetTitle(tit);
gr->GetYaxis()->CenterTitle();
gr->SetMarkerStyle(7);
c1->Update();
 }
else{
int nbin;
cout<<"The column has the max value as "<<xmax<<" and the min is "<<xmin<<endl; 
cout<<" There are "<<n<<" data point. And the average of the data array is "<<sum<<endl;
cout<<" Tulika is generating histogram, please enter the number of bins you want.\n";
cout<<"Note that the bin  size will be (Array_max-Array_min)/n_bins. You can explore the histogram!!!"<<endl;
cout<<"nbins=";
cin>>nbin;
TH1F *h1= new TH1F("","Hi! I am Tulika",nbin,xmax,xmin);
for(int i=0;i<n;i++)h1->Fill(x[i]);
sprintf(tit,"column %i",nx);
h1->GetXaxis()->SetTitle(tit);
h1->GetXaxis()->CenterTitle();
h1->Draw();
}
return 0;
}
