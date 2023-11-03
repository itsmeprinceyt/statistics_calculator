#include <iostream>
using namespace std;
class stats
{
	int si=0;						// indexing of array
	int si2=0;						// indexing of array2
	int si3=0; 						// indexing of array3
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
					for(i=0;i<1;i++)
					{
						cout<<"Enter element number "<<si+1<<" : ";
						cin>>array[si];
						si++;					
					}
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
			cout<<"\n\nx\n";
			for(k=0;k<si;k++) // showing entered frequency
			{
				cout<<array[k]<<endl;
			}
			cout<<"\n\nSum Of f: "<<sigma<<endl;
			dm=sigma/si;
			cout<<"\nMean: "<<dm;
			cout<<endl;	
			si=0;
			si2=0;
			si3=0;
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
					for(i=0;i<1;i++)
					{
						cout<<"Enter element number "<<si+1<<" : ";
						cin>>array[si]; 
						si++;
					}
				}
				if(men==1)
				{
					men=1;
				}
			}
			mv=si/2; // getting middle value
			for(i=0;i<si;i++) // calculating dx and storing in new array
			{
				array2[si2]= (array[i] - array[mv]);
				si2++;
			}
			for(j=0;j<si2;j++)
			{
					sigmadx=sigmadx+array2[j];	// calculating sigma (dx)
			}
			cout<<"\n\nf			dx\n";
			for(k=0;k<si;k++) // showing entered frequency & dx
			{
				cout<<array[k]<<"\t\t\t"<<array2[k]<<endl;
			}
			cout<<"\n\nSum Of dx: "<<sigmadx<<endl<<"Key: "<<array[mv]<<endl;
			shortcut_formula_calc=array[mv]+(sigmadx/si2);
			cout<<"\nMean: "<<shortcut_formula_calc;
			si=0;
			si2=0;
			si3=0;
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
					for(i=0;i<1;i++)
					{
						cout<<"Enter element number "<<si+1<<" : ";
						cin>>array[si]; // store to array 
						si++;
					}
				}
				if(men==1)
				{
					men=1;
				}
			}
			cout<<endl<<endl;
		while(men2==0) // another loop which will run until men2==1
			{
				cout<<"To Insert an frequency(f) element press 0, To Stop Inserting press 1:"; // getting frequency
				cin>>men2;
				if(men2==0)
				{
					for(i=0;i<1;i++)
					{
						cout<<"Enter element number "<<si2+1<<" : ";
						cin>>array2[si2]; // storing to array2
						si2++;
					}
				}
				if(men2==1)
				{
					men2=1;
				}
			}
		for(i=0;i<si;i++)
		{
			array3[i]=array[i]*array2[i]; //finding fx
		}
		for(j=0;j<si2;j++)
			{
					sigmafdx=sigmafdx+array3[j]; // adding (fx)
					sigma=sigma+array2[j];	// adding (f)
			}
		cout<<"\n\nx			f			dx\n"; // showing data
			for(k=0;k<si;k++)
			{
				cout<<array[k]<<"\t\t\t"<<array2[k]<<"\t\t\t"<<array3[k]<<endl;
			}
			cout<<"\n\nSum Of f: "<<sigma<<endl;
			cout<<"Sum Of fdx: "<<sigmafdx<<endl;
			descrete_direct=sigmafdx/sigma;
			cout<<"\nMean: "<<descrete_direct;
			cout<<endl;
			si=0;
			si2=0;
			si3=0;
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
					for(i=0;i<1;i++)
					{
						cout<<"Enter element number "<<si+1<<" : ";
						cin>>array[si];
						si++;
					}
				}
				if(men==1)
				{
					men=1;
				}
			}
			cout<<endl<<endl;
		while(men2==0)
			{
				cout<<"To Insert an frequency(f) element press 0, To Stop Inserting press 1:"; // getting frequency
				cin>>men2;
				if(men2==0)
				{
					for(i=0;i<1;i++)
					{
						cout<<"Enter element number "<<si2+1<<" : ";
						cin>>array2[si2];
						si2++;
					}
				}
				if(men2==1)
				{
					men2=1;
				}
			}
		mv=si/2; // getting middle value
		for(i=0;i<si;i++) // calculating dx
			{
				array3[si3]= (array[i] - array[mv]);
				si3++;
			}
		for(i=0;i<si;i++) // finding fdx
		{
			array4[i]=array2[i]*array3[i]; 
		}
		for(j=0;j<si2;j++) // calculating submission
			{
					sigma=sigma+array2[j]; // adding (f)
					sigmafdx=sigmafdx+array4[j]; // adding (fdx)
			}
			cout<<"\n\nx			f			dx			fdx\n"; // showing entered data
			for(k=0;k<si;k++)
			{
				cout<<array[k]<<"\t\t\t"<<array2[k]<<"\t\t\t"<<array3[k]<<"\t\t\t"<<array4[k]<<endl;
			}
			cout<<"\n\nSum Of f: "<<sigma<<endl;
			cout<<"Sum Of fdx: "<<sigmafdx<<endl<<"Key: "<<array[mv]<<endl;
			descrete_shortcut=array[mv]+(sigmafdx/sigma);
			cout<<"\nMean: "<<descrete_shortcut;
			cout<<endl;
			si=0;
			si2=0;
			si3=0;
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
					for(i=0;i<1;i++)
					{
						cout<<"Entering "<<si+1<<" Class Interval (I II) :";
						cin>>array5[si][0]>>array5[si][1];
						si++;
					}
				}
				if(men==1)
				{
					men=1;
				}
			}
			cout<<endl<<endl;
		while(men2==0)
			{
				cout<<"To Insert an frequency(f) element press 0, To Stop Inserting press 1:"; // getting frequency
				cin>>men2;
				if(men2==0)
				{
					for(i=0;i<1;i++)
					{
						cout<<"Enter element number "<<si2+1<<" : ";
						cin>>array2[si2];
						si2++;
					}
				}
				if(men2==1)
				{
					men2=1;
				}
			}
			for(i=0;i<=si;i++)
			{
				array[i]=(array5[i][0]+array5[i][1])/2;		// getting observation (x)
			}
			for(i=0;i<si;i++)
			{
				array3[i]=array[i]*array2[i]; 				//finding fx
			}
			for(j=0;j<si2;j++) // calculating submission
			{
					sigma=sigma+array2[j]; // adding (f)
					sigmadx=sigmadx+array3[j]; // ignore the variable name, it is calculating fx sum
			}
			cout<<"\n\nEntered (CI)\n"; 											// showing entered data
			for(k=0;k<si;k++)														// |
			{																		// |
				cout<<array5[k][0]<<" - "<<array5[k][1]<<endl;						// |
			}																		// |
			cout<<"\n\nx			f			fx\n";								// |
			for(i=0;i<si;i++)														// |	
			{																		// |
				cout<<array[i]<<"\t\t\t"<<array2[i]<<"\t\t\t"<<array3[i]<<endl;		// |
			}																		// showing entered data
			cout<<"\n\nSum Of f: "<<sigma<<endl;								
			cout<<"Sum Of fx: "<<sigmadx<<endl;
			conti_direct=(sigmadx/sigma);
			cout<<"\nMean: "<<conti_direct;
			si=0;
			si2=0;
			si3=0;
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
					for(i=0;i<1;i++)
					{
						cout<<"Entering "<<si+1<<" Class Interval (I II) :";
						cin>>array5[si][0]>>array5[si][1];
						si++;
					}
				}
				if(men==1)
				{
					men=1;
				}
			}
			cout<<endl<<endl;
		while(men2==0)
			{
				cout<<"To Insert an frequency(f) element press 0, To Stop Inserting press 1:"; // getting frequency
				cin>>men2;
				if(men2==0)
				{
					for(i=0;i<1;i++)
					{
						cout<<"Enter element number "<<si2+1<<" : ";
						cin>>array2[si2];
						si2++;
					}
				}
				if(men2==1)
				{
					men2=1;
				}
			}
			for(i=0;i<=si;i++)
			{
				array[i]=(array5[i][0]+array5[i][1])/2;		// getting observation (x)
			}
			mv=si/2; // getting middle value
			for(i=0;i<si;i++) // calculating dx
			{
				array3[si3]= (array[i] - array[mv]);
				si3++;
			}
			for(i=0;i<si;i++) // finding fdx
			{
				array4[i]=array2[i]*array3[i]; 
			}
			for(j=0;j<si2;j++) // calculating submission
			{
					sigma=sigma+array2[j]; // adding (f)
					sigmafdx=sigmafdx+array4[j]; // sum of fdx
			}
			cout<<"\n\nEntered (CI)\n"; 															// showing entered data
			for(k=0;k<si;k++)																		// |
			{																						// |
				cout<<array5[k][0]<<" - "<<array5[k][1]<<endl;										// |
			}																						// |
			cout<<"\n\nx			f			dx			fdx\n";									// |
			for(i=0;i<si;i++)																		// |	
			{																						// |
				cout<<array[i]<<"\t\t\t"<<array2[i]<<"\t\t\t"<<array3[i]<<"\t\t\t"<<array4[i]<<endl;// |
			}																						// showing entered data
			cout<<"\n\nSum Of f: "<<sigma<<endl;								
			cout<<"Sum Of fx: "<<sigmafdx<<endl;
			cout<<"Key: "<<array[mv]<<endl;
			conti_shortcut=array[mv]+(sigmafdx/sigma);
			cout<<"\nMean: "<<conti_shortcut;
			si=0;
			si2=0;
			si3=0;
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
					for(i=0;i<1;i++)
					{
						cout<<"Entering "<<si+1<<" Class Interval (I II) :";
						cin>>array5[si][0]>>array5[si][1];
						si++;
					}
				}
				if(men==1)
				{
					men=1;
				}
			}
			cout<<endl<<endl;
		while(men2==0)
			{
				cout<<"To Insert an frequency(f) element press 0, To Stop Inserting press 1:"; // getting frequency
				cin>>men2;
				if(men2==0)
				{
					for(i=0;i<1;i++)
					{
						cout<<"Enter element number "<<si2+1<<" : ";
						cin>>array2[si2];
						si2++;
					}
				}
				if(men2==1)
				{
					men2=1;
				}
			}
			for(i=0;i<=si;i++)
			{
				array[i]=(array5[i][0]+array5[i][1])/2;		// getting observation (x)
			}
			mv=si/2; // getting middle value
			for(i=0;i<si;i++) // calculating dx
			{
				array3[si3]= (array[i] - array[mv]);
				si3++;
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
			for(j=0;j<si2;j++) // calculating submission
			{
					sigma=sigma+array2[j]; // adding (f)
					sigmafdx=sigmafdx+array6[j]; // ignore the variable name , it IS actually storing the sum of fd'
			}
			cout<<"\n\nEntered (CI)\n"; 																				  // showing entered data
			for(k=0;k<si;k++)																							  // |
			{																											  // |
				cout<<array5[k][0]<<" - "<<array5[k][1]<<endl;															  // |
			}																											  // |
			cout<<"\n\nx			f			dx			d'			fd'\n";											  // |
			for(i=0;i<si;i++)																							  // |	
			{																											  // |
				cout<<array[i]<<"\t\t\t"<<array2[i]<<"\t\t\t"<<array3[i]<<"\t\t\t"<<array4[i]<<"\t\t\t"<<array6[i]<<endl; // |
			}																										      // showing entered data
			cout<<"\n\nSum Of f: "<<sigma<<endl;								
			cout<<"Sum Of fd': "<<sigmafdx<<endl;
			cout<<"Key: "<<array[mv]<<endl;
			cout<<"i= "<<f_gcd<<endl;
			conti_sdm=array[mv]+(sigmafdx/sigma)*f_gcd;
			cout<<"\nMean: "<<conti_sdm;
			si=0;
			si2=0;
			si3=0;
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
};
int main()
{
	stats ob1;
	int men=0;
	while(men==0)
	{
		int choice=0;
		int mchoice=0;
		cout<<"[STATISTIC CALCULATOR]\n\n";
		cout<<"[Notes:]\n-> This Program does not support the functionality to find out missing data!\n";
		cout<<"-> Please refrain from entering any inexclusive data in Continous Mean Calculation!\n\n";
		cout<<"Select From The Following:\n\n";
		cout<<"1. Individual Data\n2. Descrete Data\n3. Continuos Data\n\nTo Exit Press 4\n\nEnter Your Input: ";
		cin>>choice;
		if(choice==4)
		{
			men=1;
			break;
		}
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
			default:
				cout<<"\n\nInvalid Input!";
				break;
		}
		cout<<"\n\n***************************************\n\n\n";
	}
}


/*

version 2:
Interval show together
Without loop entering data
Reset through function


*/