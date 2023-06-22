#include <iostream>
#include <math.h>
#include <ctime>
#include <stdlib.h>
#include <stdint.h> //uint64_t . __int64
#include <fstream>
using namespace std;

void ArraysLSD()
{
    ifstream input("C:/Users/Stalker/Desktop/BobTest.txt");

    if(input){cout<<""<<endl;}
    else{cout<<"ERROR:(BobTest.txt) DO NOT OPEN"<<endl;}


    int *D, *S, *L, *U, *v1, *v2,y=0;//y=0
    int i, n, m, j, k;
    input>>n>>m;
    v1=new int[m]; v2=new int[m];
    for (i=0;i<m;i++)
    input>>v1[i]>>v2[i];

//    for(i=0)

    D=new int[m+m];
    S=new int[n];
    L=new int[n];
    U=new int[n];

    for (j=0; j<n; j++) L[j]=0;//make list length to 0 
    for (i=0; i<m; i++)   //counting list lenths
    {
        L[v1[i]]++;//v1[i]-1
        L[v2[i]]++;//v2[i]-1
    }
    S[0]=0; //counting beginner indexes for lists in arra D 
    for (j=1;j<n;j++) S[j]=S[j-1]+L[j-1];
    for (j=0;j<n;j++) U[j]=S[j];
                        //copy or beginner indexes 
    for (i=0;i<m;i++)   //distribution of adjacent vertices
                        //by lists of array D 
    {
          k = v1[i]; D[U[k]] = v2[i]; U[k]++;//v1[i]-1
          k = v2[i]; D[U[k]] = v1[i]; U[k]++;//v2[i]-1
    }

    cout<<"Arrays L , S , D:"<<endl;

    /*print L*/ cout<<"L: ";
    for (i=0;i<n;i++) {cout << L[i] << " ";}
    cout<<endl;

    /*print S*/ cout<<"S: ";
    for (i=0;i<n;i++) {cout << S[i] << " ";}//S[i]+1
    cout<<endl;

    /*Вprint D*/ cout<<"D: ";
    for (i=0;i<m+m;i++){cout << D[i] << " ";}

    //Input in 3rd text file
    ofstream out;   // stream to write
    out.open("C:/Users/Stalker/Desktop/LSD.txt");

    /*L*/
    for (i=0;i<n;i++) {out << L[i] << " ";}
    /*S*/out<<" \r";
    for (i=0;i<n;i++) {out << S[i] << " ";}//S[i]+1
    /*D*/out<<" \r";
    for (i=0;i<m+m;i++){out << D[i] << " ";}

    //cout << endl;
    out.close();    // Close the file for writing
    input.close(); // Close the stream for reading

     ofstream outLSD;
     outLSD.open("C:/Users/Stalker/Desktop/Total.txt");

    if(outLSD){cout<<""<<endl;}
    else{cout<<"ERROR:(Total.txt) DO NOT OPEN"<<endl;}

    for(int i=0;i<n; i++)
    {
        for(int j=0; j< L[i]; j++)
        {
            outLSD<<i<<" "<<D[S[i] + j];
        }
        outLSD<<" \r";
    }
}


void IncidenceMatrices() //Defining a graph as an adjacency matrix (incidence matrix)
{
    ifstream input("C:/Users/Stalker/Desktop/BobTest.txt");

    if(input){cout<<"File Open:"<<endl;}
    else{cout<<"ERROR:(BobTest.txt) DO NOT OPEN"<<endl;}

    int **M, i, j, n, m, k;

    input>>n;
    input>>m;
    M=new int*[n];

    for (i=0;i<n;i++)
    {M[i]=new int[n];
    for (j=0;j<n;j++) M[i][j]=0;
    }

    for (k=0;k<m;k++)
    {input>>i;input>>j;
   //  i--; j--;
    M[i][j]=1; M[j][i]=1;
    }

    /*Output adjacency matrix to terminal*/cout<<endl;
    cout<<"Incidence Matrices:"<<endl;
    for (i=0;i<n;i++)
    {for (j=0;j<n;j++)
        printf("%d ", M[i][j]);
        printf("\n");
    }

    //Input in 2nd text file
    ofstream out;   // stream to write
    out.open("C:/Users/Stalker/Desktop/IncidenceMatrices.txt");
    for (i=0;i<n;i++)
    {for (j=0;j<n;j++)
     {
        out<<M[i][j]<<" ";
     }
     out<<" \r";
    }

    out.close();    // Close the file for writing
    input.close(); // Close the stream for reading

  //  ArraysLSD(n);
}

int main()
{
    setlocale(LC_ALL, "Russian");

//    IncidenceMatrices();

  ifstream input("C:/Users/Stalker/Desktop/BobTest.txt");

    if(input){cout<<"File Open:"<<endl;}
    else{cout<<"ERROR:(BobTest.txt) DO NOT OPEN"<<endl;}

    int **M, i, j, n, m, k;

    input>>n;
    input>>m;
    M=new int*[n];

    for (i=0;i<n;i++)
    {M[i]=new int[n];
    for (j=0;j<n;j++) M[i][j]=0;
    }

    for (k=0;k<m;k++)
    {input>>i;input>>j;
   //  i--; j--;
    M[i][j]=1; M[j][i]=1;
    }

    /*Output adjacency matrix to terminal*/cout<<endl;
    cout<<"Incidence Matrices:"<<endl;
    for (i=0;i<n;i++)
    {for (j=0;j<n;j++)
        printf("%d ", M[i][j]);
        printf("\n");
    }

    //Input in 2nd text file
    ofstream out;   // stream to write
    out.open("C:/Users/Stalker/Desktop/IncidenceMatrices.txt");
    for (i=0;i<n;i++)
    {for (j=0;j<n;j++)
     {
        out<<M[i][j]<<" ";
     }
     out<<" \r";
    }

    out.close();    // Close the file for writing
    input.close(); // Close the stream for reading

//    ArraysLSD();//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////

    ifstream inputBOB("C:/Users/Stalker/Desktop/BobTest.txt");

    if(inputBOB){cout<<""<<endl;}
    else{cout<<"ERROR:(BobTest.txt) DO NOT OPEN"<<endl;}

    for(int i= 1;i<n;i++){ /////////////////////
        for(int j=0;j<n;j++){
            M[i][j] = 0;
        }
    }

    int *D, *S, *L, *U, *v1, *v2,y=0;//y=0
   // int  k; //i, n , m, j ,k
    inputBOB>>n>>m;
    v1=new int[m]; v2=new int[m];
    for (i=0;i<m;i++)
    inputBOB>>v1[i]>>v2[i];

//    for(i=0)

    D=new int[m+m];
    S=new int[n];
    L=new int[n];
    U=new int[n];

    for (j=0; j<n; j++) L[j]=0;//resetting list lengths
    for (i=0; i<m; i++)   //calculating the lengths of lists
    {
        L[v1[i]]++;//v1[i]-1
        L[v2[i]]++;//v2[i]-1
    }
    S[0]=0; //calculating start indices on lists in array D
    for (j=1;j<n;j++) S[j]=S[j-1]+L[j-1];
    for (j=0;j<n;j++) U[j]=S[j];
                        //duplication of start indexes
    for (i=0;i<m;i++)   //distribution of adjacent vertices
                        //by lists of array D
    {
          k = v1[i]; D[U[k]] = v2[i]; U[k]++;//v1[i]-1
          k = v2[i]; D[U[k]] = v1[i]; U[k]++;//v2[i]-1
    }

    cout<<"Arrays L , S , D:"<<endl;

    /*print L*/ cout << "L: ";
    for (i=0;i<n;i++) {cout << L[i] << " ";}
    cout<<endl;

    /*print S*/ cout<<"S: ";
    for (i=0;i<n;i++) {cout << S[i] << " ";}//S[i]+1
    cout<<endl;

    /*print D*/ cout<<"D: ";
    for (i=0;i<m+m;i++){cout << D[i] << " ";}

    //Input in 3d text file
    ofstream out3;   // stream to write
    out3.open("C:/Users/Stalker/Desktop/LSD.txt");

    /*L*/
    for (i=0;i<n;i++) {out3 << L[i] << " ";}
    /*S*/out3<<" \r";
    for (i=0;i<n;i++) {out3 << S[i] << " ";}//S[i]+1
    /*D*/out3<<" \r";
    for (i=0;i<m+m;i++){out3 << D[i] << " ";}

    //cout << endl;
    out3.close();    // Close the file for writing
    inputBOB.close(); // Close the stream for reading

     ofstream outLSD;
     outLSD.open("C:/Users/Stalker/Desktop/Total.txt");

    if(outLSD){cout<<""<<endl;}
    else{cout<<"ERROR:(Total.txt) DO NOT OPEN"<<endl;}

    for(int i=0;i<n; i++)
    {
        for(int j=0; j< L[i]; j++)
        {
            outLSD<<i<<" "<<D[S[i] + j];
            outLSD<<" \r";
        }
        outLSD<<" \r";
    }


    cout << "\nEnd Program!" << endl;
    return 0;
}
