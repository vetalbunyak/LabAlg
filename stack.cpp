#include <iostream>

class Stack
{
private:
    int *arr;
    unsigned int size;
public:
	Stack();
	~Stack(); 
	void MAKENULL();
	void PUSH(int);
    void POP();
    int TOP();
    void PRINT();
 	bool EMPTY();
};
Stack::Stack() {
    size = 0;   
    arr = nullptr;
}

 
Stack::~Stack() {
    delete[] arr;
}
 
void Stack::MAKENULL() 
{
    if (size == 0)
    {
        std::cout << "Stack is empty!" << std::endl;
    }
    else
    {
        while(!EMPTY()) {
            POP();
        }
    }
    std::cout << "SIze: "  << size << std::endl;
 }

void Stack::PUSH(int value)
{  
    if (size == 0)
    {
        arr = new int[size + 1];
        arr[0] = value;
        size++;
    }
    else
    {
        int *temp_arr = new int[size + 1];
        temp_arr[0] = value;
        for (unsigned int i = 1; i <= size; i++)
        {
            temp_arr[i] = arr[i - 1];
        }
        arr = new int[size + 1];
        for (unsigned int i = 0; i < size + 1; i++)
        {
            arr[i] = temp_arr[i];
        }
        delete[] temp_arr;
        size++;
    }
}
int Stack::TOP()
{
    return arr[0];   
}
void Stack::POP()
{
    if (size == 0)
    {
        std::cout << "Stack is empty." << std::endl;
    }
    else
    {
        int *temp_arr = new int[size - 1];
        for (unsigned int i = 0; i < size - 1; i++)
        {
            temp_arr[i] = arr[i + 1];
        }
        arr = new int[size - 1];
        for (unsigned int i = 0; i < size - 1; i++)
        {
            arr[i] = temp_arr[i];
        }
        delete[] temp_arr;
        size--;
    }
}
bool Stack::EMPTY() 
{ 
    return size == 0;
}

void Stack::PRINT()
{ 
    if (size == 0)
    {
        std::cout << "Stack is empty!" << std::endl;    
    }
    else
    {
        for (unsigned int i = 0; i < size; i++)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
   
}


int main () 
{
    bool check = true;
    unsigned int choice;
    Stack st;
	do
	{
			std::cout << "\t\t\t\tMenu: " << std::endl;
			std::cout <<"Options of stack: " << std::endl;
			std::cout << "\t1.PUSH;" << std::endl;
			std::cout << "\t2.POP;" << std::endl;
			std::cout << "\t3.TOP;" << std::endl;
			std::cout <<" \t4.MAKENULL;" << std::endl;
			std::cout <<" \t5.EMPTY;" << std::endl;
			std::cout <<" \t6.PRINT;" << std::endl;
			std::cout << "\t0.Exit;" << std::endl;

	do
        {
            std::cout << "Your choice: ";
            std::cin >> choice;
            if (choice >= 0 && choice <= 15)
            {
                break;
            }
            else{
                std::cout << "Problem."<< std::endl;
            }
            
        } while (true);
        switch(choice){
        	case 1:
        	{
        		system("clear");
        		int number;
        		std::cout << "Enter number: ";
        		std::cin >> number;
        		st.PUSH(number);
        		break;
        	}
        	case 2:
        	{
        		system("clear");
        		st.POP();
        		break;
        	}
        	case 3: 
        	{
        		system("clear");
        		std::cout << st.TOP() << std::endl;
        		break;
        	}
        	case 4:
        	{
        		system("clear");
        		st.MAKENULL();
        		break;
        	}
        	case 5:
        	{
        		system("clear");
        		std::cout <<"Stack is empty(1)/is full(0) " <<  st.EMPTY() << std::endl;
        		break;
        	}
        	case 6:
        	{
        		system("clear");
        		st.PRINT();
        		break;
        	}
        	case 0:
        	{
        		check = false;
        		break;
        	}
        }
    } while (check);
	return 0;
}
