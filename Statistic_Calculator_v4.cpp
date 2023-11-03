#include <iostream>
#include <iomanip>
using namespace std;
class stats
{
	int si=0;						// to keep count of nodes
	int mv;							// for finding middle location of observation
	float middle_value=0;           // for storing middle value of that observation
	int res=0;						// holding the GCD ( Greatest Common Factor ) that is 'i'			
	float n1=0;						// holding the 2nd element of the first class interval
	float n2=0;						// holding the 1st element of the second class interval
	float af=0;						// to store adjustment factor value
	float sigma=0;					// to store sigma (f)
	float sigmadx=0;				// to store sigma (dx)
	float sigmafdx=0;				// to store sigma (fdx,fd')
	int i;							// for loop
	int men=0;						// looping for observation data input by user
	int men2=0;						// looping for frequency data input by user
	
	float ind_direct;				// individual direct method
	float ind_shortcut;	            // individual shortcut method
	float discrete_direct;			// descrete direct method
	float discrete_shortcut;		// descrete shortcut method
	float conti_direct;				// continous direct
	float conti_shortcut;			// continous shorcut
	float conti_sdm;				// continou step deviation method
	
    struct nodes                    							// making link list to handle all the data
    {
        float element;											// will be used to store single data
        float mat1;												// will be used to store 1st element of the class interval
        float mat2;												// will be used to store 2nd element of the class interval
        struct nodes *next;
    };
    typedef struct nodes N1;        							// rewriting definition using typedef
    N1 *head,*head2,*head3, *head4, *head5, *head6, *head7;		// heads to keep the first location of the node
	N1 *temp,*temp2, *temp3, *temp4, *temp5, *temp6, *temp7;    // temps to create node  
    N1 *x,*fre, *dx,*fx,*fdx,*fd_, *ci, *d_,*in_ex;    			// respective node pointers to iterate through required data 
	
	void reset()        // for resetting all the variables to their initial stage so they don't affect the next request
    {
        si=0;
		sigma=0;
		sigmadx=0;
		sigmafdx=0;
		men=0;
		men2=0;
		mv=0;
        middle_value=0;
		n1=0;
		n2=0;
		af=0;
		res=0;
        ind_direct=0;
		ind_shortcut=0;
		discrete_direct=0;
		discrete_shortcut=0;
		conti_direct=0;
		conti_shortcut=0;
		conti_sdm=0;
    }

	int gcd(int a, int b)							// logic used to find GCD and which is used by findGCDOfLinkedList();
	{
    	while(b)
		{
        	int temp=b;
        	b=a%b;
        	a=temp;
    	}
    	return a;
	}

	int findGCDOfLinkedList(N1* head9)				// sending (dx) linked list to the function to find GCD
	{
    	if (head9==nullptr)
		{
        	return 0;
    	}
		int result= head9->element;
    	N1* current=head9->next;
		while (current!=nullptr)
		{
        	result=gcd(result, current->element);
			current=current->next;
    	}
    	return result;
	}

	void freeLinkedList(N1* &head10)
	{
    	N1* current = head10;
    	N1* next;
    	while (current != nullptr)
		{
        	next = current->next;
        	free(current);  // Free the current node
        	current = next;
    	}
    	head10 = nullptr;  // Set the head to nullptr to indicate the list is freed
	}
	public:
		void indD()
	{
		cout<<"\n***************************************";
		cout<<"\n\nIndividual Direct Method\n\n";
        head=0;
		while(men==0) //will loop until men==1
		{
			cout<<"To Insert an element press 0, To Stop Inserting press 1:"; // getting observation (x)
			cin>>men;
			if(men==0)
			{
                temp=(N1*)malloc(sizeof(N1));
                temp->next=0;
				cout<<"Enter element number "<<si+1<<" : ";
				cin>>temp->element;
                if(head==0)
                {
                    head=x=temp;
                }
                else
                {
                    x->next=temp;
                    x=temp;
                }
				si++;	
			}
			if(men==1)
			{	
				men=1;
			}
		}
        x=head;
		for(i=0;i<si;i++)
		{
			sigma=sigma+(x->element); // calculating sigma (x)
            x=x->next;
		}
        x=head;
		cout<<"\n\nS.R"<<setw(6)<<"X"<<endl;
		for(i=0;i<si;i++) // showing entered X
		{
		    cout<<i+1<<"\t"<<x->element<<endl;
            x=x->next;
		}
		cout<<"\n\nSum Of X: "<<sigma<<endl;
        cout<<"N: "<<si<<endl;
		ind_direct=sigma/si;
		cout<<"\nMean: "<<ind_direct;
        cout<<"\n\nFormula\n(Sum Of X/N) ";
		cout<<endl;
		freeLinkedList(x);
		reset();
	}
	void indS()
	{
		cout<<"\n***************************************";
		cout<<"\n\nIndividual Shortcut Method\n\n";
        head=0;
		while(men==0) // looping until men==1
		{
			cout<<"To Insert an element press 0, To Stop Inserting press 1:"; // getting observation
			cin>>men;
			if(men==0)
			{
                temp=(N1*)malloc(sizeof(N1));
                temp->next=0;
				cout<<"Enter element number "<<si+1<<" : ";
				cin>>temp->element;
                if(head==0)
                {
                    head=x=temp;
                } 
                else
                {
                    x->next=temp;
                    x=temp;
                }
				si++;
			}
			if(men==1)
			{
				men=1;
			}
		}
		x=head;
        mv=si/2; // getting middle location
        while(mv>0) // going to that location
        {
            x=x->next;
            mv--;
        }
        middle_value=x->element;
        x=head;
        head2=0;
		for(i=0;i<si;i++) // calculating dx and storing in new array
		{
			temp2=(N1*)malloc(sizeof(N1));
            temp2->next=0;
            temp2->element=(x->element)-middle_value;
            if(head2==0)
            {
                head2=dx=temp2;
            }
            else
            {
                dx->next=temp2;
                dx=temp2;
            }
            x=x->next;
		}
        dx=head2;
		for(i=0;i<si;i++)
		{
			sigmadx=sigmadx+(dx->element);	// calculating sigma (dx)
            dx=dx->next;
		}
		cout<<"\n\nS.R"<<setw(6)<<"X"<<setw(9)<<"DX"<<endl;
        x=head;
        dx=head2;
		for(i=0;i<si;i++) // showing entered x & dx
		{
			cout<<i+1<<"\t"<<x->element<<"\t"<<dx->element<<endl;
            x=x->next;
            dx=dx->next;
		}
		cout<<"\n\nSum Of dx: "<<sigmadx<<endl<<"Key: "<<middle_value<<endl<<"N: "<<si<<endl;
		ind_shortcut=middle_value+(sigmadx/si);
		cout<<"\nMean: "<<ind_shortcut;
        cout<<"\n\nFormula\nA+(Sum Of DX/N) ";
		freeLinkedList(x);
		freeLinkedList(dx);
		reset();
	}
	void descrete_D()
	{
		cout<<"\n***************************************";
		cout<<"\n\nDescrete Direct Method\n\n";
        head=0;
		while(men==0) // looping until men==1
		{
			cout<<"To Insert an observation(x) element press 0, To Stop Inserting press 1:"; // getting observation
			cin>>men;
			if(men==0)
			{
                temp=(N1*)malloc(sizeof(N1));
                temp->next=0;
		    	cout<<"Enter element number "<<si+1<<" : ";
				cin>>temp->element;// store to array 
    			if(head==0)
                {
                    head=x=temp;
                }
                else
                {
                    x->next=temp;
                    x=temp;
                }
                si++;
			}
			if(men==1)
			{
				men=1;
			}
		}
		cout<<endl<<endl;
        head2=0;
		i=0;
		cout<<"To Insert frequency(f) elements:\n"; // getting frequency
		while(true)
        {
            temp2=(N1*)malloc(sizeof(N1));
            temp2->next=0;
            cout<<"Enter element number "<<i+1<<" :";
            cin>>temp2->element;
            if(head2==0)
            {
                head2=fre=temp2;
            }
            else
            {
                fre->next=temp2;
                fre=temp2;
            }
            i++;
            if(i==si)
            {
                break;
            }
        }
        x=head;
        fre=head2;
        head3=0;
		for(i=0;i<si;i++)      //finding fx
		{   
			temp3=(N1*)malloc(sizeof(N1)); 
            temp3->next=0;
            temp3->element=(x->element)*(fre->element);
            if(head3==0)
            {
                head3=fx=temp3;
            }
            else
            {
                fx->next=temp3;
                fx=temp3;
            }
            x=x->next;
            fre=fre->next;
		}
        fre=head2;
        fx=head3;
        for(i=0;i<si;i++)
		{
			sigmafdx=sigmafdx+(fx->element); // adding (fx)
			sigma=sigma+(fre->element);	// adding (f)
            fx=fx->next;
            fre=fre->next;
        }
        x=head;
        fre=head2;
        fx=head3;
        cout<<"\n\nX"<<setw(8)<<"F"<<setw(9)<<"FX"<<endl; // showing data
		for(i=0;i<si;i++)
		{
			cout<<x->element<<"\t"<<fre->element<<"\t"<<fx->element<<endl;
            x=x->next;
            fre=fre->next;
            fx=fx->next;
        }
		cout<<"\n\nSum Of f: "<<sigma<<endl;
		cout<<"Sum Of fx: "<<sigmafdx<<endl;
		discrete_direct=sigmafdx/sigma;
		cout<<"\nMean: "<<discrete_direct;
        cout<<"\n\nFormula\n(Sum Of FX/Sum of F)";
		cout<<endl;
		freeLinkedList(x);
		freeLinkedList(fre);
		freeLinkedList(fx);
		reset();
	}
	void descrete_S()
	{
		cout<<"\n***************************************";
		cout<<"\n\nDescrete Shortcut Method\n\n";
        head=0;
		while(men==0) // looping until men==1
		{
			cout<<"To Insert an observation(x) element press 0, To Stop Inserting press 1:"; // getting observations
			cin>>men;
			if(men==0)
			{
		    	temp=(N1*)malloc(sizeof(N1));
                temp->next=0;
				cout<<"Enter element number "<<si+1<<" : ";
				cin>>temp->element;		// store to array 
    			if(head==0)
                {
                    head=x=temp;
                }
                else
                {
                    x->next=temp;
                    x=temp;
                }
                si++;
			}
			if(men==1)
			{
				men=1;
			}
		}
		cout<<endl<<endl;
        head2=0;
		i=0;
		cout<<"To Insert frequency(f) elements:\n"; // getting frequency
		while(true)
        {
            temp2=(N1*)malloc(sizeof(N1));
            temp2->next=0;
            cout<<"Enter element number "<<i+1<<" :";
            cin>>temp2->element;
            if(head2==0)
            {
                head2=fre=temp2;
            }
            else
            {
                fre->next=temp2;
                fre=temp2;
            }
            i++;
            if(i==si)
            {
                break;
            }
        }
		x=head;
		mv=si/2; // getting middle location
        while(mv>0) // going to that location
        {
            x=x->next;
            mv--;
        }
        middle_value=x->element;
        x=head;
        head3=0;  
		for(i=0;i<si;i++) // calculating dx
		{
			temp3=(N1*)malloc(sizeof(N1));
            temp3->next=0;
            temp3->element=(x->element)-middle_value;
            if(head3==0)
            {
                head3=dx=temp3;
            }
            else
            {
                dx->next=temp3;
                dx=temp3;
            }
            x=x->next;
		}
        fre=head2;
        dx=head3;
		head4=0;
        for(i=0;i<si;i++) // finding fdx
		{
            temp4=(N1*)malloc(sizeof(N1));
            temp4->next=0;
            temp4->element=(fre->element)*(dx->element);
            if(head4==0)
            {
                head4=fdx=temp4;
            }
            else
            {
                fdx->next=temp4;
                fdx=temp4;
            }
            fre=fre->next;
            dx=dx->next;
		}
        fre=head2;
        fdx=head4;
		for(i=0;i<si;i++) // calculating submission
		{
			sigma=sigma+(fre->element); // adding (f)
			sigmafdx=sigmafdx+(fdx->element); // adding (fdx)
            fre=fre->next;
            fdx=fdx->next;
		}
		x=head;
        fre=head2;
        dx=head3;
        fdx=head4;
        cout<<"\n\nX"<<setw(8)<<"F"<<setw(9)<<"DX"<<setw(9)<<"FDX"<<endl; // showing entered data
		for(i=0;i<si;i++)
		{
		    cout<<x->element<<"\t"<<fre->element<<"\t"<<dx->element<<"\t"<<fdx->element<<endl;
            x=x->next;
            fre=fre->next;
            dx=dx->next;
            fdx=fdx->next;
		}
		cout<<"\n\nSum Of f: "<<sigma<<endl;
		cout<<"Sum Of fdx: "<<sigmafdx<<endl<<"Key: "<<middle_value<<endl;
		discrete_shortcut=middle_value+(sigmafdx/sigma);
		cout<<"\nMean: "<<discrete_shortcut;
        cout<<"\n\nFormula\nA+(Sum Of FDX/Sum of F)";
		cout<<endl;
		freeLinkedList(x);
		freeLinkedList(fre);
		freeLinkedList(dx);
		freeLinkedList(fdx);
		reset();
	}
	void conti_D()
	{
		cout<<"\n***************************************";
		cout<<"\n\nContinous Direct Method\n\n";
		head=0;
		while(men==0) // looping until men==1
		{
			cout<<"To Insert an Class Interval(I II) element press 0, To Stop Inserting press 1:"; // getting class interval
			cin>>men;
			if(men==0)
			{
				temp=(N1*)malloc(sizeof(N1));
				temp->next=0;
				cout<<"Entering "<<si+1<<" Class Interval (I II) :";
				cin>>temp->mat1>>temp->mat2;
				if(head==0)
				{
					head=ci=temp;
				}
				else
				{
					ci->next=temp;
					ci=temp;
				}
				si++;
			}
			if(men==1)
			{
				men=1;
			}
		}
		cout<<endl<<endl;
		head2=0;
		i=0;
		cout<<"To Insert an frequency(f) elements:\n"; // getting frequency
		while(true)
		{
			temp2=(N1*)malloc(sizeof(N1));
			temp2->next=0;
			cout<<"Enter element number "<<i+1<<" : ";
			cin>>temp2->element;
            if(head2==0)
			{
				head2=fre=temp2;
			}
			else
			{
				fre->next=temp2;
				fre=temp2;
			}
			i++;
			if(i==si)
			{
				break;
			}
		}
		ci=head;
		head3=0;
		for(i=0;i<si;i++) // getting observation (x)
		{
			temp3=(N1*)malloc(sizeof(N1));
			temp3->next=0;
			temp3->element=((ci->mat1)+(ci->mat2))/2;
			if(head3==0)
			{
				head3=x=temp3;
			}
			else
			{
				x->next=temp3;
				x=temp3;
			}
			ci=ci->next;
		}
		fre=head2;
		x=head3;
		head4=0;
		for(i=0;i<si;i++)	//finding fx
		{
			temp4=(N1*)malloc(sizeof(N1));
			temp4->next=0;
			temp4->element=(fre->element)*(x->element);
			if(head4==0)
			{
				head4=fx=temp4;
			}
			else
			{
				fx->next=temp4;
				fx=temp4;
			}
			fre=fre->next;
			x=x->next;
		}
		fre=head2;
		fx=head4;
		for(i=0;i<si;i++) // calculating submission
		{
			sigma=sigma+(fre->element); // adding (f)
			sigmadx=sigmadx+(fx->element); // adding (fx)
			fre=fre->next;
			fx=fx->next;
		}
		ci=head;
		n1=ci->mat2;
		ci=ci->next;
		n2=ci->mat1;
		if(n2!=n1)
		{
			af=(n2-n1)/2;
			head5=0;
			ci=head;
			for(i=0;i<si;i++)		// adjusting class interval
			{
				temp5=(N1*)malloc(sizeof(N1));
				temp5->next;
				temp5->mat1=(ci->mat1)-af;
				temp5->mat2=(ci->mat2)+af;
				if(head5==0)
				{
					head5=in_ex=temp5;
				}
				else
				{
					in_ex->next=temp5;
					in_ex=temp5;
				}
				ci=ci->next;
			}				
			in_ex=head5;
			fre=head2;
			x=head3;
			fx=head4;
			cout<<"\n\nC.I"<<setw(10)<<"X"<<setw(8)<<"F"<<setw(8)<<"FX"<<endl;		// showing entered data - inexclusive
			for(i=0;i<si;i++)																						
			{																										
				cout<<in_ex->mat1<<" - "<<in_ex->mat2<<setw(7)<<x->element<<setw(8)<<fre->element<<setw(8)<<fx->element<<endl;
				in_ex=in_ex->next;
				x=x->next;
				fre=fre->next;
				fx=fx->next;
			}
		}
		else
		{
			ci=head;
			fre=head2;
			x=head3;
			fx=head4;
			cout<<"\n\nC.I"<<setw(10)<<"X"<<setw(8)<<"F"<<setw(8)<<"FX"<<endl;		// showing entered data
			for(i=0;i<si;i++)																						
			{																										
				cout<<ci->mat1<<" - "<<ci->mat2<<setw(7)<<x->element<<setw(8)<<fre->element<<setw(8)<<fx->element<<endl;
				ci=ci->next;
				x=x->next;
				fre=fre->next;
				fx=fx->next; 
			}
		}	
		cout<<"\n\nSum Of f: "<<sigma<<endl;								
		cout<<"Sum Of fx: "<<sigmadx<<endl;
		conti_direct=(sigmadx/sigma);
		cout<<"\nMean: "<<conti_direct;
        cout<<"\n\nFormula\n(Sum of FX/Sum of F)";
		freeLinkedList(ci);
		freeLinkedList(in_ex);
		freeLinkedList(x);
		freeLinkedList(fre);
		freeLinkedList(fx);
		reset();
	}
	void conti_S()
	{
		cout<<"\n***************************************";
		cout<<"\n\nContinous Shortcut Method\n\n";
		head=0;
		while(men==0) // looping until men==1
		{
			cout<<"To Insert an Class Interval(I II) element press 0, To Stop Inserting press 1:"; // getting class interval
			cin>>men;
			if(men==0)
			{
				temp=(N1*)malloc(sizeof(N1));
				temp->next=0;
				cout<<"Entering "<<si+1<<" Class Interval (I II) :";
				cin>>temp->mat1>>temp->mat2;
				if(head==0)
				{
					head=ci=temp;
				}
				else
				{
					ci->next=temp;
					ci=temp;
				}
				si++;
			}
			if(men==1)
			{
				men=1;
			}
		}
		cout<<endl<<endl;
		head2=0;
		i=0;
		cout<<"To Insert an frequency(f) elements:\n"; // getting frequency
		while(true)
		{
			temp2=(N1*)malloc(sizeof(N1));
			temp2->next=0;
			cout<<"Enter element number "<<i+1<<" : ";
			cin>>temp2->element;
            if(head2==0)
			{
				head2=fre=temp2;
			}
			else
			{
				fre->next=temp2;
				fre=temp2;
			}
			i++;
			if(i==si)
			{
				break;
			}
		}
		ci=head;
		head3=0;
		for(i=0;i<si;i++) // getting observation (x)
		{
			temp3=(N1*)malloc(sizeof(N1));
			temp3->next=0;
			temp3->element=((ci->mat1)+(ci->mat2))/2;
			if(head3==0)
			{
				head3=x=temp3;
			}
			else
			{
				x->next=temp3;
				x=temp3;
			}
			ci=ci->next;
		}
		x=head3;
		mv=si/2; // getting middle location
		while(mv>0) // going to that location
        {
            x=x->next;
            mv--;
        }
		middle_value=x->element;
		x=head3;
        head4=0;  
		for(i=0;i<si;i++) // calculating dx
		{
			temp4=(N1*)malloc(sizeof(N1));
            temp4->next=0;
            temp4->element=(x->element)-middle_value;
            if(head4==0)
            {
                head4=dx=temp4;
            }
            else
            {
                dx->next=temp4;
                dx=temp4;
            }
            x=x->next;
		}
		fre=head2;
        dx=head4;
		head5=0;
        for(i=0;i<si;i++) // finding fdx
		{
            temp5=(N1*)malloc(sizeof(N1));
            temp5->next=0;
            temp5->element=(fre->element)*(dx->element);
            if(head5==0)
            {
                head5=fdx=temp5;
            }
            else
            {
                fdx->next=temp5;
                fdx=temp5;
            }
            fre=fre->next;
            dx=dx->next;
		}
		fre=head2;
        fdx=head5;
		for(i=0;i<si;i++) // calculating submission
		{
			sigma=sigma+(fre->element); // adding (f)
			sigmafdx=sigmafdx+(fdx->element); // adding (fdx)
            fre=fre->next;
            fdx=fdx->next;
		}
		ci=head;
		n1=ci->mat2;
		ci=ci->next;
		n2=ci->mat1;
		if(n2!=n1)
		{
			af=(n2-n1)/2;
			head6=0;
			ci=head;
			for(i=0;i<si;i++)		// adjusting class interval
			{
				temp6=(N1*)malloc(sizeof(N1));
				temp6->next;
				temp6->mat1=(ci->mat1)-af;
				temp6->mat2=(ci->mat2)+af;
				if(head6==0)
				{
					head6=in_ex=temp6;
				}
				else
				{
					in_ex->next=temp6;
					in_ex=temp6;
				}
				ci=ci->next;
			}
			in_ex=head6;
			fre=head2;
			x=head3;
			dx=head4;
			fdx=head5;
			cout<<"\n\nC.I"<<setw(10)<<"X"<<setw(8)<<"F"<<setw(9)<<"DX"<<setw(8)<<"FDX"<<endl;		// showing entered data - inexclusive
			for(i=0;i<si;i++)																						
			{																										
				cout<<in_ex->mat1<<" - "<<in_ex->mat2<<setw(7)<<x->element<<setw(8)<<fre->element<<setw(8)<<dx->element<<setw(8)<<fdx->element<<endl; 
				in_ex=in_ex->next;
				x=x->next;
				fre=fre->next;
				dx=dx->next;
				fdx=fdx->next;
			}
		}
		else
		{
			ci=head;
			fre=head2;
			x=head3;
			dx=head4;
			fdx=head5;
			cout<<"\n\nC.I"<<setw(10)<<"X"<<setw(8)<<"F"<<setw(9)<<"DX"<<setw(8)<<"FDX"<<endl;		// showing entered data
			for(i=0;i<si;i++)																						
			{																										
				cout<<ci->mat1<<" - "<<ci->mat2<<setw(7)<<x->element<<setw(8)<<fre->element<<setw(8)<<dx->element<<setw(8)<<fdx->element<<endl; 
				ci=ci->next;
				x=x->next;
				fre=fre->next;
				dx=dx->next;
				fdx=fdx->next;
			}
		}
		cout<<"\n\nSum Of f: "<<sigma<<endl;								
		cout<<"Sum Of fdx: "<<sigmafdx<<endl;
		cout<<"Key: "<<middle_value<<endl;
		conti_shortcut=middle_value+(sigmafdx/sigma);
		cout<<"\nMean: "<<conti_shortcut;
        cout<<"\n\nFormula\nA+(Sum of FDX/Sum of F)";
		freeLinkedList(ci);
		freeLinkedList(in_ex);
		freeLinkedList(x);
		freeLinkedList(fre);
		freeLinkedList(dx);
		freeLinkedList(fdx);
		reset();
	}
	void conti_SDM()
	{
		cout<<"\n***************************************";
		cout<<"\n\nContinous Step Deviation Method Method\n\n";
		head=0;
		while(men==0) // looping until men==1
		{
			cout<<"To Insert an Class Interval(I II) element press 0, To Stop Inserting press 1:"; // getting class interval
			cin>>men;
			if(men==0)
			{
				temp=(N1*)malloc(sizeof(N1));
				temp->next=0;
				cout<<"Entering "<<si+1<<" Class Interval (I II) :";
				cin>>temp->mat1>>temp->mat2;
				if(head==0)
				{
					head=ci=temp;
				}
				else
				{
					ci->next=temp;
					ci=temp;
				}
				si++;
			}
			if(men==1)
			{
				men=1;
			}
		}
		cout<<endl<<endl;
		head2=0;
		i=0;
		cout<<"To Insert an frequency(f) elements:\n"; // getting frequency
		while(true)
		{
			temp2=(N1*)malloc(sizeof(N1));
			temp2->next=0;
			cout<<"Enter element number "<<i+1<<" : ";
			cin>>temp2->element;
            if(head2==0)
			{
				head2=fre=temp2;
			}
			else
			{
				fre->next=temp2;
				fre=temp2;
			}
			i++;
			if(i==si)
			{
				break;
			}
		}
		ci=head;
		head3=0;
		for(i=0;i<si;i++) // getting observation (x)
		{
			temp3=(N1*)malloc(sizeof(N1));
			temp3->next=0;
			temp3->element=((ci->mat1)+(ci->mat2))/2;
			if(head3==0)
			{
				head3=x=temp3;
			}
			else
			{
				x->next=temp3;
				x=temp3;
			}
			ci=ci->next;
		}
		x=head3;
		mv=si/2; // getting middle location
		while(mv>0) // going to that location
        {
            x=x->next;
            mv--;
        }
		middle_value=x->element;
		x=head3;
        head4=0;  
		for(i=0;i<si;i++) // calculating dx
		{
			temp4=(N1*)malloc(sizeof(N1));
            temp4->next=0;
            temp4->element=(x->element)-middle_value;
            if(head4==0)
            {
                head4=dx=temp4;
            }
            else
            {
                dx->next=temp4;
                dx=temp4;
            }
            x=x->next;
		}
		dx=head4;
		res=findGCDOfLinkedList(dx);
		head5=0;
		dx=head4;
		for(i=0;i<si;i++)
		{
			temp5=(N1*)malloc(sizeof(N1));
			temp5->next=0;
			temp5->element=(dx->element)/res;
			if(head5==0)
			{
				head5=d_=temp5;
			}
			else
			{
				d_->next=temp5;
				d_=temp5;
			}
			dx=dx->next;
		}
		fre=head2;
		d_=head5;
		head6=0;
		for(i=0;i<si;i++) // calculating fd'
		{
			temp6=(N1*)malloc(sizeof(N1));
			temp6->next=0;
			temp6->element=(fre->element)*(d_->element);
			if(head6==0)
			{
				head6=fd_=temp6;
			}
			else
			{
				fd_->next=temp6;
				fd_=temp6;
			}
			fre=fre->next;
			d_=d_->next;
		}
		fre=head2;
		fd_=head6;
		for(i=0;i<si;i++)	//calculating submission
		{
			sigma=sigma+(fre->element);	//adding (f)
			sigmafdx=sigmafdx+(fd_->element);	//ignore the name, it is actually storing the sum of fd'
			fre=fre->next;
			fd_=fd_->next;
		}
		ci=head;
		n1=ci->mat2;
		ci=ci->next;
		n2=ci->mat1;
		if(n2!=n1)
		{
			af=(n2-n1)/2;
			head7=0;
			ci=head;
			for(i=0;i<si;i++)
			{
				temp7=(N1*)malloc(sizeof(N1));
				temp7->next=0;
				temp7->mat1=(ci->mat1)-af;
				temp7->mat2=(ci->mat2)+af;
				if(head7==0)
				{
					head7=in_ex=temp7;
				}
				else
				{
					in_ex->next=temp7;
					in_ex=temp7;
				}
				ci=ci->next;
			}
			in_ex=head7;
			fre=head2;
			x=head3;
			dx=head4;
			d_=head5;
			fd_=head6;
           	cout<<"\n\nC.I"<<setw(10)<<"X"<<setw(8)<<"F"<<setw(8)<<"DX"<<setw(8)<<"D'"<<setw(8)<<"FD'"<<endl;		// showing entered data
			for(i=0;i<si;i++)																						
			{																										
				cout<<in_ex->mat1<<" - "<<in_ex->mat2<<setw(7)<<x->element<<setw(8)<<fre->element<<setw(8)<<dx->element<<setw(8)<<d_->element<<setw(8)<<fd_->element<<endl; 
				in_ex=in_ex->next;
				fre=fre->next;
				x=x->next;
				dx=dx->next;
				d_=d_->next;
				fd_=fd_->next;
			}	
		}
		else
		{
			ci=head;
			fre=head2;
			x=head3;
			dx=head4;
			d_=head5;
			fd_=head6;
           	cout<<"\n\nC.I"<<setw(10)<<"X"<<setw(8)<<"F"<<setw(8)<<"DX"<<setw(8)<<"D'"<<setw(8)<<"FD'"<<endl;		// showing entered data
			for(i=0;i<si;i++)																						
			{																										
				cout<<ci->mat1<<" - "<<ci->mat2<<setw(7)<<x->element<<setw(8)<<fre->element<<setw(8)<<dx->element<<setw(8)<<d_->element<<setw(8)<<fd_->element<<endl; 
				ci=ci->next;
				fre=fre->next;
				x=x->next;
				dx=dx->next;
				d_=d_->next;
				fd_=fd_->next;
			}
		}
		cout<<"\n\nSum Of f: "<<sigma<<endl;								
		cout<<"Sum Of fd': "<<sigmafdx<<endl;
		cout<<"Key: "<<middle_value<<endl;
		cout<<"i= "<<res<<endl;
		conti_sdm=middle_value+(sigmafdx/sigma)*res;
		cout<<"\nMean: "<<conti_sdm;
        cout<<"\n\nFormula\nA+(Sum of FD'/Sum of F)*i\n[Whereas 'i' is the Common Highest Factor in 'dx']";
		freeLinkedList(ci);
		freeLinkedList(in_ex);
		freeLinkedList(x);
		freeLinkedList(fre);
		freeLinkedList(dx);
		freeLinkedList(d_);
		freeLinkedList(fd_);
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
		cout<<"[STATISTIC CALCULATOR V4]\n\n";
		cout<<"[Notes:]\n-> This Program does not support the functionality to find out missing data!\n";
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
                cout<<"\n\nChange Logs";
				
				cout<<"\n1.1\n";
				cout<<"\n-> Made changes to how variables data are reverted back to their original initialised value. (Result: Lines of Code Reduced)";
                cout<<"\n-> You won't be asked to enter second data each time! (Result: User Comfort)";
                cout<<"\n-> The Data is being entered without using 'For Loop'. (Result: Lines of Code Reduced)";
                cout<<"\n-> Class Interval is now displayed along side with the other data. (Result: Neat & Clean Look)";
                cout<<"\n-> Fixed some issues regarding displaying.\n-> Fixed some formula naming errors.";
                
				cout<<"\n\n1.2\n";
				cout<<"\n-> Now user can enter inexclusive class interval. (Result: User Comfort)";

                cout<<"\n\n1.3\n";
                cout<<"\n-> The Program now uses Linked List instead of Array. (Result: No Memory Wastage)";
                cout<<"\n-> Source code has been optimised and indented properly. (Result: Ease for future Development)";
                break;
            default:
                cout<<"\n\nENTER VALID OPTION!";
                break;
		}
		cout<<"\n\n***************************************\n\n";
	}
	cout<<"Thank You";
}
