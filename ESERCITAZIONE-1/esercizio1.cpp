#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
// devo conoscere come è strutturato il file per poter procedere con le operazioni
int main(int argc, const char *argv[]) 
{	//argc= valori effettivi numeri, argv[]=riga quanti valori ha 
	cout<< "Numero parametri: "<<argc<<"\n";
	ifstream ifs(argv[1]);
	if (ifs.is_open()){
		for (int i=1; i<=3;i++){ //quando devo fare più iterazioni e so il numero conviene sempre usare il for
			string citta;
			double temp1;
			double temp2;
			double temp3;
			double temp4; 
			ifs>>citta>>temp1>>temp2>>temp3>>temp4;
			
			double temptot = (temp1+temp2+temp3+temp4)/4;
			cout<<"Temperature at "<<citta<<" is "<<temptot<<"\n";
		}
	}
	else {
        cout << "Errore: Impossibile aprire il file '" << argv[1];
    }
	return 0;
}
