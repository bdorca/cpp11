#include <functional>

#ifndef SORTER_H
#define CORTER_H

/**
 * @brief swap a and b
 * @param a
 * @param b
 */
template<typename T>
void mySwap(T& a, T& b){
	T temp=a;
	a=b;
	b=temp;
}
/**
 * @class BaseSorter
 * @author Dorka
 * @file basesorter.hpp
 * @brief Base class for sorters
 */
template<typename T>
class BaseSorter{
public:
	/**
	 * @brief overload of operator()
	 * @param a sortable array
	 * @param s size of the array
	 * @param f function used for comparing
	 */		
	virtual void operator()(T* a, size_t s, std::function<bool(T,T)> f)=0;
	virtual ~BaseSorter(){}
};
/**
 * @class BubbleSorter
 * @author Dorka
 * @file basesorter.hpp
 * @brief simple bubble sort
 */
template<typename T>
class BubbleSorter: public BaseSorter<T>{
public:
	void operator ()(T* a, size_t s, std::function<bool(T,T)> f){
		for(int i=s-1;i>0;i--){
			for(int j=0;j<i;j++){
				if(!f(a[j],a[j+1])){
					mySwap<T>(a[j],a[j+1]);
				}
			}
		}
	}
};
/**
 * @class Bubble2Sorter
 * @author Dorka
 * @file basesorter.hpp
 * @brief another bubble sort implementation
 */
template<typename T>
class Bubble2Sorter:public BaseSorter<T>{
public:
	void operator ()(T* a, size_t s, std::function<bool(T,T)> f){
		for(int i=0;i<s-1;i++){
			for(int j=i;j<s;j++){
				if(!f(a[i],a[j])){
					mySwap<T>(a[i],a[j]);
				}
			}
		}
	}	
};
/**
 * @class SelectionSorter
 * @author Dorka
 * @file basesorter.hpp
 * @brief selection sort
 */
template<typename T>
class SelectionSorter:public BaseSorter<T>{
public:
	void operator ()(T* a, size_t s, std::function<bool(T,T)> f){
		int i, j, index;

		for (i = 0; i < s-1; ++i) {
			index = i;                
			for (j = i+1; j < s; ++j)
				if (f(a[j], a[index]))
					index = j;
			if (index != i) {         
				mySwap<T>(a[index],a[i]);
			}
		}
	}

};


/**
 * @class GnomeSorter
 * @author Dorka
 * @file basesorter.hpp
 * @brief gnome sort
 */
template<typename T>
class GnomeSorter:public BaseSorter<T>{
public:
	void operator ()(T* a, size_t s, std::function<bool(T,T)> f){
		int i = 0;
		while (i < s) {
			if (i == 0 || f(a[i-1], a[i])) { 
				i++;                
			} else {
				mySwap<T>(a[i],a[i-1]);
				i--;                
			}
		}
	}

};
/**
 * @class QuickSorter
 * @author Dorka
 * @file basesorter.hpp
 * @brief quick sort
 */
template<typename T>
class QuickSorter: public BaseSorter<T>{

	//http://www.algolist.net/Algorithms/Sorting/Quicksort
	void quickSort(T arr[], int left, int right, std::function<bool(T,T)> f) {
      int i = left, j = right;
      T tmp;
      T pivot = arr[(left + right) / 2];
       /* partition */
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
      if (left < j)
            quickSort(arr, left, j,f);
      if (i < right)
            quickSort(arr, i, right,f);
	}

public:
	void operator ()(T* a, size_t s, std::function<bool(T,T)> f){
		quickSort(a,0,s-1, f);
	}
};
/**
 * @class MergeSorter
 * @author Dorka
 * @file basesorter.hpp
 * @brief merge sort
 */

template<typename T>
class MergeSorter: public BaseSorter<T>{
	//http://stackoverflow.com/questions/12030683/implementing-merge-sort-in-c
	void mergesort(T *a, T*b, int start, int end, std::function<bool(T,T)> f) {
		int halfpoint;
		if (start < end) {
			halfpoint = (start + end) / 2;
			mergesort(a, b, start, halfpoint,f);
			mergesort(a, b, halfpoint + 1, end,f);
			merge(a, b, start, halfpoint, end,f);
		}
	}

	void merge(T *a, T *b, int start, int halfpoint, int end, std::function<bool(T,T)> f) {
		int h, i, j, k;
		h = start;
		i = start;
		j = halfpoint + 1;

		while ((h <= halfpoint) && (j <= end)) {
			if (f(a[h], a[j])) {
				b[i] = a[h];
				h++;
			} else {
				b[i] = a[j];
				j++;
			}
			i++;
		}
		if (h > halfpoint) {
			for (k = j; k <= end; k++) {
				b[i] = a[k];
				i++;
			}
		} else {
			for (k = h; k <= halfpoint; k++) {
				b[i] = a[k];
				i++;
			}
		}

		for (k = start; k <= end; k++) {
			a[k] = b[k];
		}
	}
	
public:
	void operator ()(T* a, size_t s, std::function<bool(T,T)> f){
		T b[s];
		mergesort(a,b,0,s-1, f);
	}
};


#endif