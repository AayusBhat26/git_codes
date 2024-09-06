#include <iostream>
// anananananananyayayayayayayayayay
using namespace std;

const int SENTINEL_VALUE = -1;

void printArray(int* arr, int size) {
    cout << "\n";
    if (size <= 0) {
        cout << "Array is empty.\n";
        return;
    }
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}

bool isArrayEmpty(int size) {
    return size <= 0;
}

bool isSortedAscending(int* arr, int size){
    if(isArrayEmpty(size)){
        cout<<"Array is empty";
        return false;
    }
    else{
    for(int i = 0; i < size - 1; i++){
        if(*(arr+i) > *(arr + i + 1)){
            return false;
        }
    }
    return true;
    }
}
bool isSortedDescending(int* arr, int size){
     if(isArrayEmpty(size)){
        cout<<"Array is empty";
        return false;
    }
    else{
    for(int i =0; i < size -1 ; i++){
        if(*(arr+i) < *(arr+i + 1)){
            return false;
        }
    }
    }
    return true;
}

void insertionSort(int arr[], int size) {
    for(int i =1; i < size; i++ ){
        int mainElement = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > mainElement){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = mainElement;
    }
}

void addAtStart(int* arr, int &size, int element) {
    for (int i = size; i > 0; i--) {
        *(arr + i) = *(arr + i - 1);
    }
    *arr = element;
    size++;
    printArray(arr, size);
}

void addAtEnd(int* arr, int &size, int element) {
    *(arr + size) = element;
    size++;
    printArray(arr, size);
}

void addAtPosition(int* arr, int &size, int element, int position) {
    if (position < 0 || position > size) {
        cout << "Invalid Position!\n";
        return;
    }
    for (int i = size; i > position; i--) {
        *(arr + i) = *(arr + i - 1);
    }
    *(arr + position) = element;
    size++;
    printArray(arr, size);
}

void deleteFromStart(int* arr, int &size) {
    if (isArrayEmpty(size)) {
        cout << "Array is empty, first add an element.\n";
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        *(arr + i) = *(arr + i + 1);
    }
    size--;
    printArray(arr, size);
}

void deleteFromPosition(int* arr, int &size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid Position.\n";
        return;
    }
    for (int i = position; i < size - 1; i++) {
        *(arr + i) = *(arr + i + 1);
    }
    size--;
    printArray(arr, size);
}

void deleteFromEnd(int* arr, int &size) {
    if (isArrayEmpty(size)) {
        cout << "\nArray is empty.\n";
        return;
    }
    size--;
    printArray(arr, size);
}

void deleteFromRange(int* arr, int &size, int start, int end) {
    if (start < 0 || end >= size || start > end) {
        cout << "Invalid Range.\n";
        return;
    }
    for (int i = end + 1; i < size; i++) {
        *(arr + start + i - (end - start + 1)) = *(arr + i);
    }
    size -= (end - start + 1);
    printArray(arr, size);
}

void addMultipleAtEnd(int* arr, int &size) {
    int noelements;
    cout << "\nProvide number of elements you want to add: ";  
    cin >> noelements;
    cout << "\nProvide the elements: ";
    int* tempArr = new int[noelements];
    for (int i = 0; i < noelements; i++) {
        cin >> *(tempArr + i);
    }
    for (int i = 0; i < noelements; i++) {
        *(arr + size) = *(tempArr + i);
        size++;
    }
    delete[] tempArr;
    printArray(arr, size);
}

void addMultipleAtStart(int* arr, int &size) {
    int noelements;
    cout << "\nProvide number of elements you want to add: ";  
    cin >> noelements;
    cout << "\nProvide the elements: ";
    int* tempArr = new int[noelements];
    for (int i = 0; i < noelements; i++) {
        cin >> *(tempArr + i);
    }
    for (int i = size + noelements - 1; i >= noelements; i--) {
        *(arr + i) = *(arr + i - noelements);
    }
    for (int i = 0; i < noelements; i++) {
        *(arr + i) = *(tempArr + i);
    }
    size += noelements;
    delete[] tempArr;
    printArray(arr, size);
}

void addMultipleAtPosition(int* arr, int &size) {
    int noelements;
    int position; 
    cout << "\nProvide the position to add to: "; 
    cin >> position;
    if (position < 0 || position > size) {
        cout << "\nInvalid Position\n";
        return;
    }
    cout << "\nProvide number of elements you want to add: ";  
    cin >> noelements;
    cout << "\nProvide the elements: ";
    int* tempArr = new int[noelements];
    for (int i = 0; i < noelements; i++) {
        cin >> *(tempArr + i);
    }
    for (int i = size + noelements - 1; i >= position + noelements; i--) {
        *(arr + i) = *(arr + i - noelements);
    }
    for (int i = 0; i < noelements; i++) {
        *(arr + position + i) = *(tempArr + i);
    }
    size += noelements;
    delete[] tempArr;
    printArray(arr, size);
}

void deleteMultipleFromStart(int* arr, int &size) {
    int noelements; 
    cout << "Provide the number of elements to delete: ";
    cin >> noelements;
    if (noelements > size) {
        cout << "\nNumber of elements to delete is greater than the size of array\n";
        return;
    }
    for (int i = 0; i < size - noelements; i++) {
        *(arr + i) = *(arr + i + noelements);
    }
    size -= noelements;
    printArray(arr, size);
}

void deleteMultipleFromEnd(int* arr, int &size) {
    int noelements; 
    cout << "Provide the number of elements to delete: ";
    cin >> noelements;
    if (noelements > size) {
        cout << "\nNumber of elements to delete is greater than the size of array\n";
        return;
    }
    for (int i = size - noelements; i < size; i++) {
        *(arr + i) = SENTINEL_VALUE;
    }
    size -= noelements;
    printArray(arr, size);
}

void deleteMultipleFromPosition(int* arr, int &size) {
    int position;
    int noelement; // Number of elements to delete from position
    cout << "\nProvide number of elements to delete: "; 
    cin >> noelement;
    cout << "\nProvide the position: "; 
    cin >> position;
    if (position < 0 || position >= size) {
        cout << "Invalid Position";
        return;
    }
    if (position + noelement > size) {
        cout << "\nOut of bounds\n";
        return;
    }
    for (int i = position; i < size - noelement; i++) {
        *(arr + i) = *(arr + i + noelement);
    }
    for (int i = size - noelement; i < size; i++) {
        *(arr + i) = SENTINEL_VALUE;
    }
    size -= noelement;
    printArray(arr, size);
}

void searchElement(int* arr, int size, int element) {
    if(isArrayEmpty(size)){
        cout<<"\n\n Add elements first\n";
        return ;
    }
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (*(arr + i) == element) {
            cout << "\nElement " << element << " found at index " << i << ".\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\nElement " << element << " not found.\n";
    }
}

void updateElement(int* arr, int size, int position, int newElement) {
    if (position < 0 || position >= size) {
        cout << "Invalid Position.\n";
        return;
    }
    *(arr + position) = newElement;
    cout << "Element at position " << position << " updated to " << newElement << ".\n";
    printArray(arr, size);
}

void binarySearchWithoutRecursion(int* arr, int low, int high, int keyElement, int size) {
    if(isArrayEmpty(size)){
        cout<<"\n\nArray is empty, add new elements\n";
        return;
    }
    if(!isSortedAscending(arr, size)){
        cout<<"\nArray is not sorted, please sort first\n.";
        return;
    }
    if(!isSortedDescending(arr, size)){
        cout<<"\nArray is not sorted, please sort first\n.";
        return;
    }
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (*(arr + mid) == keyElement) {
            cout << "\nKey element found at index: " << mid << endl;
            return;
        }
        if (*(arr + mid) < keyElement) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "\nElement was not present in the array\n";
}

void binarySearchWithRecursion(int* arr, int low, int high, int keyElement, int size) {
    if(isArrayEmpty(size)){
        cout<<"\n\nArray is empty, add new elements\n";
        return;
    }
    if(!isSortedAscending(arr, size)){
        cout<<"\nArray is not sorted, please sort first\n.";
        return;
    }
    if(!isSortedDescending(arr, size)){
        cout<<"\nArray is not sorted, please sort first\n.";
        return;
    }
    if (low <= high) {
        int mid = low + (high - low) / 2;
        if (*(arr + mid) == keyElement) {
            cout<<"\nElement Found at index: "<<mid<<endl;
            return;
        }
        if (*(arr + mid) < keyElement) {
            return binarySearchWithRecursion(arr, mid + 1, high, keyElement, size);
        }
        return binarySearchWithRecursion(arr, low, mid - 1, keyElement, size);
    }
    cout<<"\nElement Not found\n";
    return;
}


int main() {
    int arr[10];
    int size = 0;
    int choice, element, position, start, end, flag_sort;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add at Start\n";
        cout << "2. Add at End\n";
        cout << "3. Add at Position\n";
        cout << "4. Delete from Start\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Delete from Range\n";
        cout << "8. Search Element\n";
        cout << "9. Update Element\n";
        cout << "10. Add Multiple at Start\n";
        cout << "11. Add Multiple at End\n";
        cout << "12. Add Multiple at Position\n";
        cout << "13. Delete Multiple from Start\n";
        cout << "14. Delete Multiple from End\n";
        cout << "15. Delete Multiple from Position\n";
        cout << "16. Binary Search Without Recursion\n";
        cout << "17. Binary Search With Recursion\n";
        cout << "18. Check whether Array is sorted (ascending) or not\n";
        cout << "19. Check whether Array is sorted (descending)or not\n";
        cout << "20. Insertion Sort\n";
        cout << "21. Print the array\n";
        cout << "22. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nEnter element to add at start: ";
                cin >> element;
                addAtStart(arr, size, element);
                break;
            case 2:
                cout << "\nEnter element to add at end: ";
                cin >> element;
                addAtEnd(arr, size, element);
                break;
            case 3:
                cout << "\nEnter element to add: ";
                cin >> element;
                cout << "Enter position: ";
                cin >> position;
                addAtPosition(arr, size, element, position);
                break;
            case 4:
                deleteFromStart(arr, size);
                break;
            case 5:
                deleteFromEnd(arr, size);
                break;
            case 6:
                cout << "\nEnter position: ";
                cin >> position;
                deleteFromPosition(arr, size, position);
                break;
            case 7:
                cout << "\nEnter start position: ";
                cin >> start;
                cout << "Enter end position: ";
                cin >> end;
                deleteFromRange(arr, size, start, end);
                break;
            case 8:
                cout << "\nEnter element to search: ";
                cin >> element;
                searchElement(arr, size, element);
                break;
            case 9:
                cout << "\nEnter position to update: ";
                cin >> position;
                cout << "Enter new element: ";
                cin >> element;
                updateElement(arr, size, position, element);
                break;
            case 10:
                addMultipleAtStart(arr, size);
                break;
            case 11:
                addMultipleAtEnd(arr, size);
                break;
            case 12:
                addMultipleAtPosition(arr, size);
                break;
            case 13:
                deleteMultipleFromStart(arr, size);
                break;
            case 14:
                deleteMultipleFromEnd(arr, size);
                break;
            case 15:
                deleteMultipleFromPosition(arr, size);
                break;
            case 16:
                cout << "\nEnter element to search using binary search without recursion: ";
                cin >> element;
                binarySearchWithoutRecursion(arr, 0, size - 1, element, size);
                break;
            case 17:
                cout << "\nEnter element to search using binary search with recursion: ";
                cin >> element;
                binarySearchWithRecursion(arr, 0, size - 1, element, size);
           
            case 18:
                if(isSortedAscending(arr, size)){
                    cout<<"\nArray is sorted in ascending order.\n";
                }
                else{
                    
                    cout<<"\nArray not sorted\n";
                }
                break;

            case 19: 
                  if(isSortedDescending(arr, size)){
                    cout<<"\nArray is sorted in descending order.\n";
                }
                else{
                    cout<<"\nArray not sorted\n";
                }
                break;
             
            case 20:
                cout << "\nInsertion Sort\n";
                insertionSort(arr, size);
                break;

            case 21:
                printArray(arr, size);
                break;
            case 22:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 22);

    return 0;
}
