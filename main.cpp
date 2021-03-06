#include <iostream>
#include <fstream>

int main(int argc, const char * argv[])
{
    float x = 0;
    int size = 0; 
    float average = 0;
    float sum = 0;
 
    std::ifstream file;
    file.open(argv[1]);

    // Get the sum of the input, and the amount of numbers.
    if(file.is_open()){
        while(file >> x){
            sum += x;
            size += 1;
        }
    }else{
        std::cout << "The file couldn't be opened." << std::endl;
        getchar();
        exit(EXIT_FAILURE);
    }

    // Returns to the beggining of the input file.
    file.clear();
    file.seekg(0, std::ios::beg); 

    float *array = new float[size];

    for(int i = 0; i < size; i++){
        file >> array[i];
    }

    file.close();

    std::cout.setf(std::ios::fixed,std::ios::floatfield);
    std::cout.precision(3);

    std::cout << "Input:" << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << array[i] << " ";
    }

    average = (sum/size);

    std::cout << "\nOutput:" << std::endl;
    for(int i = 0; i < size; i++){
        if(array[i] > average){
            std::cout << array[i] << " ";
        }
    }

    delete[] array;

    getchar();
    return 0;
}