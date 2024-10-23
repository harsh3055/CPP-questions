// program to find the roots of the equation (quadratic)
// enter the input a,b,c as per ax^2 + bx + c 
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
	
#ifndef ONLINE_JUDGE
freopen("../inputf.in","r",stdin); //file input.txt is opened in reading mode i.e "r"
freopen("../outputf.out","w",stdout);  //file output.txt is opened in writing mode i.e "w"
#endif

	float a,b,c,A,B;
	float x,y,z;

	cin>>a>>b>>c;
	   A = b*b;
	   B = 4*a*c;

// condition for the real roots
	if(A > B){
	z = A-B;
	x = -b/(2*a);
    y = pow(z, 1/2)/(2*a);

		cout<<"the real roots are: "<<x+y <<" and "<<x-y;
	}

// condition for the equal roots
	else if(A==B){
		x = -b/(2*a);

    	cout<<" the two equal roots are: "<<x;
    }

// condition for the imaginary roots
	else if(A<B){
		z = B-A;
		x = (-b)/(2*a);
	    y = pow(z, 1/2)/(2*a);
	    
		cout<<"the imaginary roots are: "<<x<<"+_"<<y<<"i";
}

}