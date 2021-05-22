#include "/home/tracy/projects/LAB4/rectBlocks.h"
#include "/home/tracy/projects/LAB4/sqrBaseRectBlocks.h"
#include "/home/tracy/projects/LAB4/sphericalBlocks.h"
#include "/home/tracy/projects/LAB4/cylindricalBlocks.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <math.h>


using namespace std;

bool sortbydiameter(sphericalBlocks &a, sphericalBlocks &b){
	return (a.diameter < b.diameter);
};

bool sortbyarea(cylindricalBlocks &a, cylindricalBlocks &b){
	return (a.getCylindricalArea() < b.getCylindricalArea());
};

int main()
{
    string w,h,l;
    vector <int> width;
    vector <int> height;
    vector <int> length;
    vector <rectBlocks> rectArray(20);
    vector <sqrBaseRectBlocks> sqrArray(20);
    vector <sphericalBlocks> sphereArray(20);
    vector <cylindricalBlocks> cylArray(20);

    string file="dataBlocks.dat";
    int i=0;

    ifstream thisfile(file);
    if(thisfile.is_open()){
        while(!thisfile.eof()){
            getline(thisfile,w,' ');
            width.push_back(stof(w));
            getline(thisfile,h,' ');
            height.push_back(stof(h));
            getline(thisfile,l,'\n');
            length.push_back(stof(l));

            i+=1;
        }
        thisfile.close();

    }
    else{
        cout<<"Unable to open file"<<endl;
    }

    for(int j=0;j<=20;j++){
            int a=width[j];
            int b=height[j];
            int c=length[j];
            rectBlocks A(a,b,c);
            rectArray.push_back(A);
    }

    for(int j=0;j<=20;j++){
            if(width[j]==height[j]){
				sqrBaseRectBlocks B(width[j],length[j]);
				sqrArray.push_back(B);
			}

    }

    int sqrsize = sqrArray.size();

    for(int j=0;sqrsize;j++){
		sqrBaseRectBlocks C = sqrArray.at(j);
		if(C.width != C.length){
			cylindricalBlocks D(C.width,C.length);
			cylArray.push_back(D);
		}
	}


	for(int j=0;sqrsize;j++){
		sqrBaseRectBlocks C = sqrArray.at(j);
		if(C.width == C.length){
			sphericalBlocks E(C.width);
			sphereArray.push_back(E);
		}
	}

	sort(sphereArray.begin(),sphereArray.end(),sortbydiameter);

	int spheresize = sphereArray.size();
	for(int a=0; spheresize;a++){
		cout<<"The diameter is "<<sphereArray[a].diameter<<" the spherical surface is "<<sphereArray[a].getArea()<<" and the volume is "<<sphereArray[a].getVol()<<endl;
	}

	sort(cylArray.begin(),cylArray.end(),sortbyarea);
	int cylsize = cylArray.size();
	for(int a=0; cylsize;a++){
		cout<<"The surface area is "<< cylArray[a].getCylindricalArea() <<" the diameter of the circular base is "<< cylArray[a].diameter <<" the length is "<< cylArray[a].length <<" and the area is "<< cylArray[a].getArea() <<endl;
	}

    return 0;
}
