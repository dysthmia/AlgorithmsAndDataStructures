#include<iostream>

void merge (std::vector<int>& v, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> l(n1), r(n2);

    for (int i=0; i<n1; i++) l[i] = v[left+i];
    for (int j=0; j<n2; j++) r[j] = v[mid+j+1];

    int i = 0, j = 0, k = left;
    while (i<n1 && j<n2){
        if (l[i] <= r[j]) v[k++] = l[i++];
        else v[k++] = r[j++];
    }

    while (i<n1) v[k++] = l[i++];
    while (j<n2) v[k++] = r[j++];
}

void merge_sort (std::vector<int>& v, int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left)/2;

    merge_sort (v, left, mid);
    merge_sort (v, mid+1, right);

    merge (v, left, mid, right);
}