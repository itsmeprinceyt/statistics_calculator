#include <iostream>
#include <iomanip>
using namespace std;
class stats
{
	int si=0;						// indexing of array
	int f_gcd=0;					// for storing highest common factor;
	float sigma=0;					// to store sigma (f)
	float sigmadx=0;				// to store sigma (dx)
	float sigmafdx=0;				// to store sigma (fdx)
	float dm;						// individual direct method
	float shortcut_formula_calc;	// individual shortcut method
	float descrete_direct;			// descrete direct method
	float descrete_shortcut;		// descrete shortcut method
	float conti_direct;				// continous direct
	float conti_shortcut;			// continous shorcut
	float conti_sdm;				// continou step deviation method
	int i,j,k;						// for loops
	int men=0;						// looping for observation data input by user
	int men2=0;						// looping for frequency data input by user
	float array[25];				// for frequency
	float array2[25];				// for dx
	float array3[25];				// for fdx
	float array4[25];  				// for fdx 2nd
	float array5[25][2];			// for storing C.I
	float array6[25];				// for storing d'
	int mv;							// to store middle value

	int gcd(int a,int b) // for finding ( i ) in continous step deviation method
	{
   		int temp;
   		while(b>0)
		{
      		temp=b;
      		b=a%b;
      		a=temp;
   		}
   			return a;
	}
	void reset()        // for resetting all the variables to their initial stage so they don't affect the next request
    {
        si=0;
		sigma=0;
		sigmadx=0;
		sigmafdx=0;
		f_gcd=0;
		men=0;
		men2=0;
		mv=0;
		dm=0;
		shortcut_formula_calc=0;
		descrete_direct=0;
		descrete_shortcut=0;
		conti_direct=0;
		conti_shortcut=0;
		conti_sdm;
    }
	public:
		void indD()
	{
		cout<<"\n***************************************";
		cout<<"\n\nIndividual Direct Method\n\n";
		while(men==0) //will loop until men==1
			{
				cout<<"To Insert an element press 0, To Stop Inserting press 1:"; // getting observation
				cin>>men;
				if(men==0)
				{
					cout<<"Enter element number "<<si+1<<" : ";
					cin>>array[si];
					si++;	
				}
				if(men==1)
				{	
					men=1;
				}
			}
			for(j=0;j<si;j++)
			{
				sigma=sigma+array[j]; // calculating sigma (f)
			}
			cout<<"\n\nS.R"<<setw(6)<<"X"<<endl;
			for(k=0;k<si;k++) // showing entered frequency
			{
				cout<<k+1<<"\t"<<array[k]<<endl;
			}
			cout<<"\n\nSum Of X: "<<sigma<<endl;
            cout<<"N: "<<si<<endl;
			dm=sigma/si;
			cout<<"\nMean: "<<dm;
            cout<<"\n\nFormula\n(Sum Of X/N) ";
			cout<<endl;	
			reset();
	}
	void indS()
	{
		cout<<"\n***************************************";
		cout<<"\n\nIndividual Shortcut Method\n\n";
		while(men==0) // looping until men==1
			{
				cout<<"To Insert an element press 0, To Stop Inserting press 1:"; // getting observation
				cin>>men;
				if(men==0)
				{
					cout<<"Enter element number "<<si+1<<" : ";
					cin>>array[si]; 
					si++;
				}
				if(men==1)
				{
					men=1;
				}
			}
			mv=si/2; // getting middle value
			for(i=0;i<si;i++) // calculating dx and storing in new array
			{
				array2[i]= (array[i] - array[mv]);
			}
			for(j=0;j<si;j++)
			{
					sigmadx=sigmadx+array2[j];	// calculating sigma (dx)
			}
			cout<<"\n\nS.R"<<setw(6)<<"X"<<setw(9)<<"DX"<<endl;
			for(k=0;k<si;k++) // showing entered x & dx
			{
				cout<<k+1<<"\t"<<array[k]<<"\t"<<array2[k]<<endl;
			}
			cout<<"\n\nSum Of dx: "<<sigmadx<<endl<<"Key: "<<array[mv]<<endl<<"N: "<<si<<endl;
			shortcut_formula_calc=array[mv]+(sigmadx/si);
			cout<<"\nMean: "<<shortcut_formula_calc;
            cout<<"\n\nFormula\nA+(Sum Of DX/N) ";
			reset();
	}
	void descrete_D()
	{
		cout<<"\n***************************************";
		cout<<"\n\nDescrete Direct Method\n\n";
		while(men==0) // looping until men==1
			{
				cout<<"To Insert an observation(x) element press 0, To Stop Inserting press 1:"; // getting observation
				cin>>men;
				if(men==0)
				{
					cout<<"Enter element number "<<si+1<<" : ";
					cin>>array[si]; // store to array 
    				si++;
				}
				if(men==1)
				{
					men=1;
				}
			}
			cout<<endl<<endl;
		while(men2==0) // another loop which will run until men2==1
			{
				cout<<"To Insert frequency(f) elements:\n"; // getting frequency
				for(i=0;i<si;i++)
                {
                    cout<<"Enter element number "<<i+1<<" : ";
					cin>>array2[i];
                }
				men2=1;
			}
		for(i=0;i<si;i++)
		{
			array3[i]=array[i]*array2[i]; //finding fx
		}
		for(j=0;j<si;j++)
			{
					sigmafdx=sigmafdx+array3[j]; // adding (fx)
					sigma=sigma+array2[j];	// adding (f)
			}
		cout<<"\n\nX"<<setw(8)<<"F"<<setw(9)<<"FX"<<endl; // showing data
			for(k=0;k<si;k++)
			{
				cout<<array[k]<<"\t"<<array2[k]<<"\t"<<array3[k]<<endl;
			}
			cout<<"\n\nSum Of f: "<<sigma<<endl;
			cout<<"Sum Of fx: "<<sigmafdx<<endl;
			descrete_direct=sigmafdx/sigma;
			cout<<"\nMean: "<<descrete_direct;
            cout<<"\n\nFormula\n(Sum Of FX/Sum of F)";
			cout<<endl;
			reset();
	}
	void descrete_S()
	{
		cout<<"\n***************************************";
		cout<<"\n\nDescrete Shortcut Method\n\n";
		while(men==0) // looping until men==1
			{
				cout<<"To Insert an observation(x) element press 0, To Stop Inserting press 1:"; // getting observations
				cin>>men;
				if(men==0)
				{
					cout<<"Enter element number "<<si+1<<" : ";
					cin>>array[si];
					si++;
				}
				if(men==1)
				{
					men=1;
				}
			}
			cout<<endl<<endl;
		while(men2==0)
			{
				cout<<"To Insert frequency(f) elements:\n"; // getting frequency
				for(i=0;i<si;i++)
                {
                    cout<<"Enter element number "<<i+1<<" : ";
					cin>>array2[i];
                }
				men2=1;
			}
		mv=si/2; // getting middle value
		for(i=0;i<si;i++) // calculating dx
			{
				array3[i]= (array[i] - array[mv]);
			}
		for(i=0;i<si;i++) // finding fdx
		{
			array4[i]=array2[i]*array3[i]; 
		}
		for(j=0;j<si;j++) // calculating submission
			{
					sigma=sigma+array2[j]; // adding (f)
					sigmafdx=sigmafdx+array4[j]; // adding (fdx)
			}
			cout<<"\n\nX"<<setw(8)<<"F"<<setw(9)<<"DX"<<setw(9)<<"FDX"<<endl; // showing entered data
			for(k=0;k<si;k++)
			{
				cout<<array[k]<<"\t"<<array2[k]<<"\t"<<array3[k]<<"\t"<<array4[k]<<endl;
			}
			cout<<"\n\nSum Of f: "<<sigma<<endl;
			cout<<"Sum Of fdx: "<<sigmafdx<<endl<<"Key: "<<array[mv]<<endl;
			descrete_shortcut=array[mv]+(sigmafdx/sigma);
			cout<<"\nMean: "<<descrete_shortcut;
            cout<<"\n\nFormula\nA+(Sum Of FDX/Sum of F)";
			cout<<endl;
			reset();
	}
	void conti_D()
	{
		cout<<"\n***************************************";
		cout<<"\n\nContinous Direct Method\n\n";
		while(men==0) // looping until men==1
			{
				cout<<"To Insert an Class Interval(I II) element press 0, To Stop Inserting press 1:"; // getting class interval
				cin>>men;
				if(men==0)
				{
					cout<<"Entering "<<si+1<<" Class Interval (I II) :";
					cin>>array5[si][0]>>array5[si][1];
					si++;
				}
				if(men==1)
				{
					men=1;
				}
			}
			cout<<endl<<endl;
		while(men2==0)
			{
				cout<<"To Insert an frequency(f) elements:\n"; // getting frequency
				for(i=0;i<si;i++)
                {
                    cout<<"Enter element number "<<i+1<<" : ";
					cin>>array2[i];
                }
				men2=1;
			}
			for(i=0;i<=si;i++)
			{
				array[i]=(array5[i][0]+array5[i][1])/2;		// getting observation (x)
			}
			for(i=0;i<si;i++)
			{
				array3[i]=array[i]*array2[i]; 				//finding fx
			}
			for(j=0;j<si;j++) // calculating submission
			{
					sigma=sigma+array2[j]; // adding (f)
					sigmadx=sigmadx+array3[j]; // ignore the variable name, it is calculating fx sum
			}
			cout<<"\n\nC.I"<<setw(10)<<"X"<<setw(8)<<"F"<<setw(8)<<"FX"<<endl;		// showing entered data
			for(i=0;i<si;i++)																						
			{																										
				cout<<array5[i][0]<<" - "<<array5[i][1]<<setw(7)<<array[i]<<setw(8)<<array2[i]<<setw(8)<<array3[i]<<endl; 
			}	
			cout<<"\n\nSum Of f: "<<sigma<<endl;								
			cout<<"Sum Of fx: "<<sigmadx<<endl;
			conti_direct=(sigmadx/sigma);
			cout<<"\nMean: "<<conti_direct;
            cout<<"\n\nFormula\n(Sum of FX/Sum of F)";
			reset();
	}
	void conti_S()
	{
		cout<<"\n***************************************";
		cout<<"\n\nContinous Shortcut Method\n\n";
		while(men==0) // looping until men==1
			{
				cout<<"To Insert an Class Interval(I II) element press 0, To Stop Inserting press 1:"; // getting class interval
				cin>>men;
				if(men==0)
				{
					cout<<"Entering "<<si+1<<" Class Interval (I II) :";
					cin>>array5[si][0]>>array5[si][1];
					si++;
				}
				if(men==1)
				{
					men=1;
				}
			}
			cout<<endl<<endl;
		while(men2==0)
			{
				cout<<"To Insert an frequency(f) elements:\n"; // getting frequency
				for(i=0;i<si;i++)
                {
                    cout<<"Enter element number "<<i+1<<" : ";
					cin>>array2[i];
                }
				men2=1;
			}
			for(i=0;i<=si;i++)
			{
				array[i]=(array5[i][0]+array5[i][1])/2;		// getting observation (x)
			}
			mv=si/2; // getting middle value
			for(i=0;i<si;i++) // calculating dx
			{
				array3[i]= (array[i] - array[mv]);
			}
			for(i=0;i<si;i++) // finding fdx
			{
				array4[i]=array2[i]*array3[i]; 
			}
			for(j=0;j<si;j++) // calculating submission
			{
					sigma=sigma+array2[j]; // adding (f)
					sigmafdx=sigmafdx+array4[j]; // sum of fdx
			}
            cout<<"\n\nC.I"<<setw(10)<<"X"<<setw(8)<<"F"<<setw(9)<<"DX"<<setw(8)<<"FDX"<<endl;		// showing entered data
			for(i=0;i<si;i++)																						
			{																										
				cout<<array5[i][0]<<" - "<<array5[i][1]<<setw(7)<<array[i]<<setw(8)<<array2[i]<<setw(8)<<array3[i]<<setw(8)<<array4[i]<<endl; 
			}	
			cout<<"\n\nSum Of f: "<<sigma<<endl;								
			cout<<"Sum Of fdx: "<<sigmafdx<<endl;
			cout<<"Key: "<<array[mv]<<endl;
			conti_shortcut=array[mv]+(sigmafdx/sigma);
			cout<<"\nMean: "<<conti_shortcut;
            cout<<"\n\nFormula\nA+(Sum of FDX/Sum of F)";
			reset();
	}
	void conti_SDM()
	{
		cout<<"\n***************************************";
		cout<<"\n\nContinous Step Deviation Method Method\n\n";
		while(men==0) // looping until men==1
			{
				cout<<"To Insert an Class Interval(I II) element press 0, To Stop Inserting press 1:"; // getting class interval
				cin>>men;
				if(men==0)
				{
					cout<<"Entering "<<si+1<<" Class Interval (I II) :";
					cin>>array5[si][0]>>array5[si][1];
					si++;
				}
				if(men==1)
				{
					men=1;
				}
			}
			cout<<endl<<endl;
		while(men2==0)
			{
				cout<<"To Insert an frequency(f) elements:\n"; // getting frequency
				for(i=0;i<si;i++)
                {
                    cout<<"Enter element number "<<i+1<<" : ";
					cin>>array2[i];
                }
				men2=1;
			}
			for(i=0;i<=si;i++)
			{
				array[i]=(array5[i][0]+array5[i][1])/2;		// getting observation (x)
			}
			mv=si/2; // getting middle value
			for(i=0;i<si;i++) // calculating dx
			{
				array3[i]= (array[i] - array[mv]);
			}
			f_gcd=array3[0]; 			//finding i
			for(i=1;i<si;i++)
			{
				f_gcd=gcd(f_gcd,array3[i]);		// finding and storing highest divisble = basically finding D'
			}
			for(i=0;i<si;i++) // finding d'
			{
				array4[i]=array3[i]/f_gcd; 
			}
			for(i=0;i<si;i++) // calculating fd'
			{
				array6[i]=array2[i]*array4[i];
			}
			for(j=0;j<si;j++) // calculating submission
			{
					sigma=sigma+array2[j]; // adding (f)
					sigmafdx=sigmafdx+array6[j]; // ignore the variable name , it IS actually storing the sum of fd'
			}
            cout<<"\n\nC.I"<<setw(10)<<"X"<<setw(8)<<"F"<<setw(8)<<"DX"<<setw(8)<<"D'"<<setw(8)<<"FD'"<<endl;		// showing entered data
			for(i=0;i<si;i++)																						
			{																										
				cout<<array5[i][0]<<" - "<<array5[i][1]<<setw(7)<<array[i]<<setw(8)<<array2[i]<<setw(8)<<array3[i]<<setw(8)<<array4[i]<<setw(8)<<array6[i]<<endl; 
			}					
			cout<<"\n\nSum Of f: "<<sigma<<endl;								
			cout<<"Sum Of fd': "<<sigmafdx<<endl;
			cout<<"Key: "<<array[mv]<<endl;
			cout<<"i= "<<f_gcd<<endl;
			conti_sdm=array[mv]+(sigmafdx/sigma)*f_gcd;
			cout<<"\nMean: "<<conti_sdm;
            cout<<"\n\nFormula\nA+(Sum of FD'/Sum of F)*i\n[Whereas 'i' is the Common Highest Factor in 'dx']";
			reset();
	}
};
int main()
{
	stats ob1;
	int men=0;
	while(men==0)
	{
		int choice=0;
		int mchoice=0;
		cout<<"[STATISTIC CALCULATOR V2]\n\n";
		cout<<"[Notes:]\n-> This Program does not support the functionality to find out missing data!\n";
		cout<<"-> Please refrain from entering any inexclusive data in Continous Mean Calculation!\n\n";
        cout<<"Select From The Following:\n\n";
		cout<<"1. Individual Data\n2. Descrete Data\n3. Continuos Data\n\n4. To Exit\n5. Check Change Logs\n\nEnter Your Input: ";
		cin>>choice;
		cout<<"\n***************************************";
		switch(choice)
		{
			case 1:
				cout<<"\n\nYou Have Selected Individual Data, select method:\n1. Direct Method\n2. Shortcut Method\n\nEnter your choice: ";
				cin>>mchoice;
				if(mchoice==1)
				{
					ob1.indD();
				}
				else if(mchoice==2)
				{
					ob1.indS();
				}
				else
				{
					cout<<"Invalid Input!";
				}
				break;
			case 2:
				cout<<"\n\nYou Have Selected Descrete Data, select method:\n1. Direct Method\n2. Shortcut Method\n\nEnter your choice: ";
				cin>>mchoice;
				if(mchoice==1)
				{
					ob1.descrete_D();
				}
				else if(mchoice==2)
				{
					ob1.descrete_S();
				}
				else
				{
					cout<<"Invalid Input!";
				}
				break;
			case 3:
				cout<<"\n\nYou Have Selected Continuos Data, select method:\n1. Direct Method\n2. Shortcut Method\n3. Step Deviation Method\n\nEnter your choice: ";
				cin>>mchoice;
				if(mchoice==1)
				{
						ob1.conti_D();
				}
				else if(mchoice==2)
				{
						ob1.conti_S();
				}
				else if(mchoice==3)
				{
						ob1.conti_SDM();
				}
				else
				{
					cout<<"Invalid Input!";
				}
				break;
            case 4:
                men=1;
                break;
            case 5:
                cout<<"\n\nChange Logs\n-> Made changes to how variables data are reverted back to their original initialised value. (Result: Lines of Code Reduced)";
                cout<<"\n-> You won't be asked to enter second data each time! (Result: User Comfort)";
                cout<<"\n-> The Data is being entered without using 'For Loop'. (Result: Lines of Code Reduced)";
                cout<<"\n-> Class Interval is now displayed along side with the other data. (Result: Neat & Clean Look)";
                cout<<"\n-> Fixed some issues regarding displaying.\n-> Fixed some formula naming errors.";
                break;
            default:
                cout<<"\n\nENTER VALID OPTION!";
                break;
		}
		cout<<"\n\n***************************************\n\n";
	}
	cout<<"Thank You";
}