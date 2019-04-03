#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    sort(a, a+n); // ordenando o vetor
    
    // l é o indice mais a esquerda que estamos olhando no momento, r é o indice mais a direita
    int l, r;
    l = 0;
    r = n-1;
    
    int x;
    cin >> x; // x sera o elemento que vamos procurar
    
    // O(log(n))
    // enquanto ainda temos pelo menos um elemento pra comparar
    while(l <= r){
        int mid = (l+r)/2; // pegando o indice do meio
        if(a[mid] == x){
            cout << "achei";
            return 0;
        } else if(a[mid] > x){ // se o valor do meio eh maior que o valor que queremos, entao precisamos olhar mais pra esquerda
            r = mid-1; // descartamos todos os elementos de mid até r
        } else if(a[mid] < x){ // se o valor do meio eh menor do que o valor que queremos, entao precisamos procurar mais pra direita
            l = mid+1; // descartamos todos os elementos de 0 até mid
        }
    }
    
    cout << "nao achei";
    
    return 0;
}
