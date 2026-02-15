#include <iostream>
using namespace std;
int a[4][4]={}, i, j, x, y, nrd, nrm, nralg1, nralg2 = 1;
bool ok = 0;
int main(){
    while(nrm < 11){
        for(i=1;i<=3;i++)
            for(j=1;j<=3;j++){
                cout << a[i][j] << "   ";
                nrd++;
                if(nrd == 3){
                    cout << endl << endl;
                    nrd = 0;
            }
        }
        if(nralg1  <  nralg2){
        /// primul player (1)
            cout << "Primul jucator sa aleaga o linie si o coloana: ";
            cin >> x >> y;
            if(x >= 1 && x <= 3 && y >= 1 && y <= 3 && a[x][y] == 0)
                a[x][y] = 1;
            else{
                cout << "Alege un spatiu liber";
                cin >> x >> y;
                a[x][y] = 1;
            }
            nralg1++;
        }
        else{
            /// al doilea jucator (2)
            cout << "Al doilea jucator sa aleaga o linie si o coloana: ";
            cin >> x >> y;
            if(x >= 1 && x <= 3 && y >= 1 && y <= 3 && a[x][y] == 0)
                a[x][y] = 2;
            else{
                cout << "Alege un spatiu liber";
                cin >> x >> y;
                a[x][y] = 2;
            }
            nralg2++;
        }
        /// verificarea tablei
            for(i=1;i<=3;i++)
                for(j=1;j<=3;j++){
                    ///verificarea liniilor
                    if(a[i][1] != 0 && a[i][1] == a[i][2] && a[i][2] == a[i][3]){
                        ok = 1;
                        break;
                    }
                    if(a[1][j] != 0 && a[1][j] == a[2][j] && a[2][j] == a[3][j]){
                        ok = 1;
                        break;
                    }
                }
            if(ok == 1){
                cout << "Jocul s a terminat";
                return 0;
            }
            /// verificarea diagonalelor
                if(a[1][1] != 0 &&  a[1][1] == a[2][2] && a[2][2] == a[3][3] || 
                    a[1][3] != 0 && a[1][3] == a[2][2] && a[2][2] == a[3][1]){
                    ok = 1;
                    break;
                }
            if(ok == 1){
                cout << "Jocul s a terminat";
                return 0;
            }
        nrm++;
    }
    cout << "Nu mai sunt locuri libere. Jocul s a terminat";
    return 0;
}