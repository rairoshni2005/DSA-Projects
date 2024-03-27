#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class array_operations {
private:
    int arr[MAX_SIZE];
    int size;

public:
    array_operations() {
        size = 0;
    }
    array_operations(int initial_array[], int initial_size) {
        if (initial_size <= MAX_SIZE) {
            for (int i = 0; i < initial_size; ++i) {
                arr[i] = initial_array[i];
            }
            size = initial_size;
        } else {
            cerr << "Initial array size exceeds maximum size." << endl;
        }
    }
    void display_array() {
        if (size == 0) {
            cout << "Array is empty." << endl;
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void insert_at_end(int element) {
        if (size < MAX_SIZE) {
            arr[size++] = element;
            cout << "Element inserted at the end successfully." << endl;
        } else {
            cout << "Array is full. Cannot insert element." << endl;
        }
    }
    void insert_at_beginning(int element) {
        if (size < MAX_SIZE) {
            for (int i = size; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = element;
            size++;
            cout << "Element inserted at the beginning successfully." << endl;
        } else {
            cout << "Array is full. Cannot insert element." << endl;
        }
    }
    void insert_before_element(int element, int target) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            if (size < MAX_SIZE) {
                for (int i = size; i > index; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[index] = element;
                size++;
                cout << "Element inserted before " << target << " successfully." << endl;
            } else {
                cout << "Array is full. Cannot insert element." << endl;
            }
        } else {
            cout << "Element not found in the array." << endl;
        }
    }
    void insert_after_element(int element, int target) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            if (size < MAX_SIZE) {
                for (int i = size; i > index + 1; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[index + 1] = element;
                size++;
                cout << "Element inserted after " << target << " successfully." << endl;
            } else {
                cout << "Array is full. Cannot insert element." << endl;
            }
        } else {
            cout << "Element not found in the array." << endl;
        }
    }
    void delete_at_end() {
        if (size > 0) {
            size--;
            cout << "Element deleted from the end successfully." << endl;
        } else {
            cout << "Array is empty. Cannot delete element." << endl;
        }
    }
    void delete_at_beginning() {
        if (size > 0) {
            for (int i = 0; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            cout << "Element deleted from the beginning successfully." << endl;
        } else {
            cout << "Array is empty. Cannot delete element." << endl;
        }
    }
    void delete_before_element(int target) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                index = i;
                break;
            }
        }
        if (index != -1 && index > 0) {
            for (int i = index - 1; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            cout << "Element deleted before " << target << " successfully." << endl;
        } else {
            cout << "Element not found in the array or no element before it." << endl;
        }
    }
    void delete_after_element(int target) {
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                index = i;
                break;
            }
        }
        if (index != -1 && index < size - 1) {
            for (int i = index + 1; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            cout << "Element deleted after " << target << " successfully." << endl;
        } else {
            cout << "Element not found in the array or no element after it." << endl;
        }
    }
    void search_element(int element) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (arr[i] == element) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "Element " << element << " found in the array." << endl;
        } else {
            cout << "Element " << element << " not found in the array." << endl;
        }
    }
    void count_elements() {
        cout << "Number of elements in the array: " << size << endl;
    }
};

int main() {
    int initial_array[] = {1, 2, 3, 4, 5};
    int initial_size = sizeof(initial_array) / sizeof(initial_array[0]);

    array_operations array(initial_array, initial_size);
    int choice, element, target;
    do {
        cout << "\n---Menu Driven Program---" << endl;
        cout << "1) Display Array" << endl;
        cout << "2) Insert at End" << endl;
        cout << "3) Insert at Beginning" << endl;
        cout << "4) Insert Before an Element" << endl;
        cout << "5) Insert After an Element" << endl;
        cout << "6) Delete at End" << endl;
        cout << "7) Delete at Beginning" << endl;
        cout << "8) Delete Before an Element" << endl;
        cout << "9) Delete After an Element" << endl;
        cout << "10) Search an Element" << endl;
        cout << "11) Count Number of Elements" << endl;
        cout << "What do you want to perform :- ";
        cin >> choice;

        switch (choice) {
            case 1:
                array.display_array();
                break;
            case 2:
                cout << "Enter element to insert at end: ";
                cin >> element;
                array.insert_at_end(element);
                array.display_array();
                break;
            case 3:
                cout << "Enter element to insert at beginning: ";
                cin >> element;
                array.insert_at_beginning(element);
                array.display_array();
                break;
            case 4:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter element before which to insert: ";
                cin >> target;
                array.insert_before_element(element, target);
                array.display_array();
                break;
            case 5:
                cout << "Enter element to insert: ";
                cin >> element;
                cout << "Enter element after which to insert: ";
                cin >> target;
                array.insert_after_element(element, target);
                array.display_array();
                break;
            case 6:
                array.delete_at_end();
                array.display_array();
                break;
            case 7:
                array.delete_at_beginning();
                array.display_array();
                break;
            case 8:
                cout << "Enter element before which to delete: ";
                cin >> target;
                array.delete_before_element(target);
                array.display_array();
                break;
            case 9:
                cout << "Enter element after which to delete: ";
                cin >> target;
                array.delete_after_element(target);
                array.display_array();
                break;
            case 10:
                cout << "Enter element to search: ";
                cin >> element;
                array.search_element(element);
                array.display_array();
                break;
            case 11:
                array.count_elements();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (true); 
    return 0;
}   