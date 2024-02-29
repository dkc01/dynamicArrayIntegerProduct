#include <iostream>
using namespace std;

int product(int a[], int startingIndex, int endingIndex)
{
    if (startingIndex > endingIndex)
    {
        return 1;
    }
    else 
    {
        return a[startingIndex] * product(a, (startingIndex + 1), endingIndex);
    }
}

int main()
{
    int initialSize = 5;
    int size;
    int* data = new int[initialSize]; // Allocate memory for initialSize elements
    int count = 0;
    int input;

    cout << "Please enter how many integers you want to enter: ";
    cin >> size;

    do
    {
        cout << "Please input number: ";
        cin >> input;
        
        data[count] = input;
        count++;

        // Check if count exceeds the initial size, and reallocate memory if needed
        if (count == initialSize)
        {
            int* temp = new int[initialSize * 2]; // Allocate memory for double the current size
            for (int i = 0; i < initialSize; i++)
            {
                temp[i] = data[i];
            }
            delete[] data; // Deallocate old memory
            data = temp;   // Update pointer to point to new memory
            initialSize *= 2; // Update initialSize
        }
    } while (count < size);
   
    int result = product(data, 0, size - 1);
    cout << "Product of the entered numbers: " << result << endl;

    delete[] data; // Deallocate memory

    return 0;
}
