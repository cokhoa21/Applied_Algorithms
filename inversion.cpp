#include<bits/stdc++.h>

#define f1(i ,a) for(int i = 1; i <= a; i++)
#define f0(i, a) for(int i = 0; i < a; i++)
#define MAX 100005
#define MODULE 1000000007
using namespace std;

int n, a[MAX], temp[MAX];

void input() {
    cin >> n;
    f1(i, n) {
        cin >> a[i];
        temp[i] = 0;
    }
}

int merge(int left, int mid, int right) {
    int inv_count = 0;
    int i, j, k;
    i = left; 
    j = mid;
    k = left;

    while((i <= mid - 1) && (j <= right)) {
        if(a[i] <= a[j]) {
            temp[k++] = a[i++];
        }else {
            temp[k++] = a[j++];
            inv_count += mid - i;
        }
    }
    while(i <= mid-1) {
        temp[k++] = a[i++];
    }

    while(j <= right) {
        temp[k++] = a[j++];
    }

    for (int i = left; i <= right; i++)
    {
        a[i] = temp[i];
    }
    
    return inv_count%=MODULE;

}

int mergeSort(int left, int right) {
    int res = 0; int mid = 0;
    if(left < right) {
        mid = (left + right) / 2;
        res += mergeSort(left, mid);
        res += mergeSort(mid+1, right);
        res += merge(left, mid+1, right);
    }else{ 
        return 0;
    }
    return res%=MODULE;
}

int main() {
    input();
    cout << mergeSort(1, n);
    return 0;
}