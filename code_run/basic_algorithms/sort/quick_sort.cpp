#include <iostream>

void merge (std::vector<int>& v, const std::vector<int>& left, int pivot, const std::vector<int>& right) {
    size_t index = 0;

    for (size_t i = 0; i < left.size(); ++i)
        v[index++] = left[i];

    v[index++] = pivot;

    for (size_t j = 0; j < right.size(); ++j)
        v[index++] = right[j];
}

void quick_sort(std::vector<int>& v) {

    if (v.size() <= 1) return;

    int pivot = v.back();

    std::vector<int> left, right;

    for (size_t i=0; i+1<v.size(); i++) {
        if (v[i] <= pivot)
            left.push_back(v[i]);
        else
            right.push_back(v[i]);
    }
    
    quick_sort (left);
    quick_sort (right);

    merge (v, left, pivot, right);
}
